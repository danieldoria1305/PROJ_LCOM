#include <lcom/lcf.h>
#include <lcom/lab3.h>

#include <stdbool.h>
#include <stdint.h>

#include "i8254.h"
#include "i8042.h"
#include "keyboard.h"
#include "KBC.c"
#include "timer.c"

extern uint32_t counter_KBC;
extern int timer_counter;
extern uint8_t scancode;

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab3/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab3/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}


int(kbd_test_scan)() {

    int ipc_status;
    uint8_t irqset;
    message msg;

    if(keyboard_subscribe_interrupts(&irqset) != 0){
        printf("Error subscribing timer\n");
        return 1;
    } 

    while(scancode != BREAK_ESC){

        if( driver_receive(ANY, &msg, &ipc_status) != 0 ){
            printf("Error");
            continue;
        }

        if(is_ipc_notify(ipc_status)) {
            switch(_ENDPOINT_P(msg.m_source)){
                 case HARDWARE:
                    if (msg.m_notify.interrupts & irqset) {
                        kbc_ih();
                        kbd_print_scancode(!(scancode & MAKE_CODE), scancode == TWO_BYTES ? 2 : 1, &scancode);
                    }
            }
        }
    }

  if (keyboard_unsubscribe_interrupts() != 0) return 1;
  if (kbd_print_no_sysinb(counter_KBC) != 0) return 1;

  return 0;
}

int(kbd_test_poll)() {
  
    while (scancode != BREAK_ESC) { 

        if (read_KBC_output(KBC_OUT_CMD, &scancode, 0) == 0) {
            kbd_print_scancode(!(scancode & MAKE_CODE), scancode == TWO_BYTES ? 2 : 1, &scancode);
        }   
    }

  return keyboard_restore();
}

int(kbd_test_timed_scan)(uint8_t n) {

    int ipc_status;
    uint8_t irq_set_TIMER, irq_set_KBC;
    message msg;

    int secs = 0; 

    if (timer_subscribe_int(&irq_set_TIMER) != 0) { 
        printf("Error subscribing timer\n");
        return 1;
    }
    if (keyboard_subscribe_interrupts(&irq_set_KBC) != 0) {
    printf("Error subscribing keyboard\n");
    return 1;
  }

    while (scancode != BREAK_ESC && secs < n){

        if( driver_receive(ANY, &msg, &ipc_status) != 0 ){
            printf("Error");
            continue;
        }

        if(is_ipc_notify(ipc_status)) {
            switch(_ENDPOINT_P(msg.m_source)){
                 case HARDWARE:
                    if (msg.m_notify.interrupts & irq_set_KBC) {
                        kbc_ih();
                        kbd_print_scancode(!(scancode & MAKE_CODE), scancode == TWO_BYTES ? 2 : 1, &scancode);
                        secs = 0;
                        timer_counter = 0;
                    }
                    if (msg.m_notify.interrupts & irq_set_TIMER) {
                        timer_int_handler();
                        if (timer_counter % 60 == 0) secs++;
                    }
            }
        }
    }

  if (timer_unsubscribe_int() != 0) return 1;
  if (keyboard_unsubscribe_interrupts() != 0) return 1;
  if (kbd_print_no_sysinb(counter_KBC) != 0) return 1;

  return 0;
}