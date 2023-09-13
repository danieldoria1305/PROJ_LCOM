#include <lcom/lcf.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "i8042.h"
#include "i8254.h"
#include "KBC.c"
#include "mouse.h"
#include "timer.c"

extern struct packet mouse_packet;
extern uint8_t byte_index;
extern int counter_TIMER;

typedef enum {
  START,
  UP,
  VERTEX,
  DOWN,
  END
} SystemState;

SystemState state = START;
uint16_t x_len_total = 0;

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need/ it]
  lcf_trace_calls("/home/lcom/labs/lab4/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab4/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

int (mouse_test_packet)(uint32_t cnt) {
   
  int ipc_status;
  message msg;
  uint8_t mouse_mk; 
  
  if (mouse_subscribe_int(&mouse_mk) != 0) return 1;
  if (mouse_enable_data_reporting() != 0) return 1;

  while (cnt) { 

    if (driver_receive(ANY, &msg, &ipc_status) != 0){
      printf("Error");
      continue;
    }

    if (is_ipc_notify(ipc_status)){
      switch(_ENDPOINT_P(msg.m_source)){
        case HARDWARE: 
          if (msg.m_notify.interrupts & mouse_mk){ 
            mouse_ih();                               
            mouse_sync_bytes();                       
            if (byte_index == 3) {                    
              mouse_bytes_to_packet();                
              mouse_print_packet(&mouse_packet);      
              byte_index = 0;
              cnt--;
            }
          }
          break;
      }
    }
  }
  
  if (mouse_write(DISABLE_DATA_REPORT) != 0) return 1;
  if (mouse_unsubscribe_int() != 0) return 1;
 
  return 0;
}

/*
int (mouse_enable_data_reporting)() {
  for (int i = 0; i < 3; i++) {
    uint8_t status;

    if (util_sys_inb(KBC_STATUS_REG, &status) != 0) return 1;
    if (status & IBF) continue;

    if (sys_outb(KBC_IN_CMD, WRITE_BYTE_MOUSE) != 0) return 1;
    if (sys_outb(KBC_OUT_CMD, ENABLE_DATA_REPORT) != 0) return 1;

    uint8_t acknowledgement;
    if (util_sys_inb(KBC_OUT_CMD, &acknowledgement) != 0) return 1;
    if (acknowledgement == ACK) return 0;
    if (acknowledgement == ERROR) return 1;
  }
  return 1;
}
*/

int (mouse_test_remote)(uint16_t period, uint8_t cnt) {
    
  while (cnt) { 

    if (mouse_write(MOUSE_READ_DATA) != 0) return 1;  
    mouse_ih();                                  
    mouse_sync_bytes();                                     
    if (byte_index == 3) {                            
      mouse_bytes_to_packet();                      
      mouse_print_packet(&mouse_packet);             
      byte_index = 0;
      cnt--;
      tickdelay(micros_to_ticks(period * 1000));    
    }
  }

  if (mouse_write(ENABLE_STREAM_MODE) != 0) return 1;
  if (mouse_write(DISABLE_DATA_REPORT) != 0) return 1;

  uint8_t commByte = minix_get_dflt_kbc_cmd_byte();           
  
  if (write_KBC_command(KBC_IN_CMD, KBC_WRITE_CMD) != 0) return 1;  
  if (write_KBC_command(KBC_WRITE_CMD, commByte) != 0) return 1; 
  
  return 0;
}

int (mouse_test_async)(uint8_t idle_time) {

  int ipc_status;
  message msg;
  uint8_t seconds = 0, mouse_mk = 0, timer_mask = 0; 
  uint16_t timer_frequency = sys_hz();

  if (mouse_subscribe_int(&mouse_mk) != 0) return 1;
  if (timer_subscribe_int(&timer_mask) != 0) return 1;
  if (mouse_enable_data_reporting() != 0) return 1;

  while (seconds < idle_time) { 

    if (driver_receive(ANY, &msg, &ipc_status) != 0){
      printf("Error");
      continue;
    }

    if (is_ipc_notify(ipc_status)){
      switch(_ENDPOINT_P(msg.m_source)){
        case HARDWARE: 

          if (msg.m_notify.interrupts & timer_mask) { 
            timer_int_handler();
            if (counter_TIMER % timer_frequency == 0) seconds++;
          }

          if (msg.m_notify.interrupts & mouse_mk){  
            mouse_ih();                             
            mouse_sync_bytes();                       
            if (byte_index == 3) {                    
              mouse_bytes_to_packet();                
              mouse_print_packet(&mouse_packet);      
              byte_index = 0;
            }
            seconds = 0;
            counter_TIMER = 0;
          }
      }
    }
  }

  if (mouse_write(DISABLE_DATA_REPORT) != 0) return 1;

  if (timer_unsubscribe_int() != 0) return 1;
  if (mouse_unsubscribe_int() != 0) return 1;

  return 0;
}

void update_state_machine(uint8_t tolerance) {
  switch (state) {
    case START:
      if (mouse_packet.lb && !mouse_packet.rb && !mouse_packet.mb) {
        state = UP;
      }
      break;

    case UP:
      if (mouse_packet.lb && !mouse_packet.rb && !mouse_packet.mb) {
        if (mouse_packet.delta_x >= -tolerance && mouse_packet.delta_y >= -tolerance) {
          state = VERTEX;
        } else {
          state = START;
        }
      } else if (!mouse_packet.lb && !mouse_packet.rb && !mouse_packet.mb) {
        state = START;
      }
      break;

    case VERTEX:
      if (!mouse_packet.lb && !mouse_packet.rb && !mouse_packet.mb) {
        state = DOWN;
      } else if (mouse_packet.lb && !mouse_packet.rb && !mouse_packet.mb) {
        if (mouse_packet.delta_x >= -tolerance && mouse_packet.delta_y >= -tolerance) {
          state = VERTEX;
        } else {
          state = START;
        }
      } else if (mouse_packet.lb && !mouse_packet.rb && mouse_packet.mb) {
        state = END;
      }
      break;

    case DOWN:
      if (!mouse_packet.lb && !mouse_packet.rb && !mouse_packet.mb) {
        state = DOWN;
      } else if (!mouse_packet.lb && !mouse_packet.rb && mouse_packet.mb) {
        if (mouse_packet.delta_x >= -tolerance && mouse_packet.delta_y >= -tolerance) {
          state = VERTEX;
        } else {
          state = START;
        }
      } else if (mouse_packet.lb && !mouse_packet.rb && !mouse_packet.mb) {
        state = UP;
      }
      break;

    case END:
      break;
  }

  x_len_total = max(0, x_len_total + mouse_packet.delta_x);
}

int (mouse_test_gesture)(uint8_t x_len, uint8_t tolerance) {
  
  int ipc_status;
  message msg;
  uint8_t mouse_mk;

  if (mouse_subscribe_int(&mouse_mk) != 0) return 1;
  if (mouse_enable_data_reporting() != 0) return 1;

  while (state != END) {

    if (driver_receive(ANY, &msg, &ipc_status) != 0){
      printf("Error");
      continue;
    }

    if (is_ipc_notify(ipc_status)){
      switch(_ENDPOINT_P(msg.m_source)){
        case HARDWARE: 
          if (msg.m_notify.interrupts & mouse_mk){  
            mouse_ih();                              
            mouse_sync_bytes();                       
            if (byte_index == 3) {                    
              mouse_bytes_to_packet();                
              update_state_machine(tolerance);
              byte_index = 0;
            }
          }
      }
    }
  }
  
  if (mouse_write(DISABLE_DATA_REPORT) != 0) return 1;

  if (mouse_unsubscribe_int() != 0) return 1;

  return 0;
}
