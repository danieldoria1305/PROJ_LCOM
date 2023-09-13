#include <lcom/lcf.h>
#include <lcom/lab3.h>
#include <stdbool.h>
#include <stdint.h>
#include "keyboard.h"
#include "i8042.h"

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


extern uint32_t cnt;
extern int counter, return_value;
extern uint8_t scancode;

int(kbd_test_scan)() {
  uint8_t bit_no;
  if (keyboard_subscribe_interrupts(&bit_no) != 0){
    printf("Error subscribing keyboard\n");
    return 1;
  }

  uint8_t packet[2];

  int ipc_status, r, i=0;
  message msg;

  while(scancode != BREAK_ESC) {
    if((r = driver_receive(ANY, &msg, &ipc_status)) != 0) {
      printf("driver_receive failed with: %d", r);
      continue;
    }

    if (is_ipc_notify(ipc_status)) {
      switch (_ENDPOINT_P(msg.m_source)) {
        case HARDWARE:
          if (msg.m_notify.interrupts & BIT(bit_no)) {
            kbc_ih();

            if (return_value == 0) {
              packet[i] = scancode;

              if (scancode == TWO_BYTES) {
                i++;
              }
              else {
                if (kbd_print_scancode(!(scancode & MAKE_CODE), i + 1, packet) != 0) return 1;
                i = 0;
              }
            }
          }
          break;
        default:
          break;
      }
    }
  }

  if (keyboard_unsubscribe_interrupts() != 0) {
    printf("Error unsubscribing keyboard\n");
    return 1;
  }

  if (kbd_print_no_sysinb(cnt) != 0) {
    printf("Failed kbd_print_no_sysinb\n");
    return 1;
  }
  return 0;
}

int(kbd_test_poll)() {

  uint8_t packet[2];
  int i = 0;

  while(scancode != BREAK_ESC) {
    kbc_ih();

    if (return_value == 0) {
      if(read_KBC_output(KBC_OUT_CMD, &scancode) != 0) continue;

      packet[i] = scancode;

      if (scancode == TWO_BYTES) {
        i++;
      }
      else {
        if (kbd_print_scancode(!(scancode & MAKE_CODE), i + 1, packet) != 0) return 1;
        i = 0;
      }
    }
  }

  if(keyboard_restore() != 0){
    printf("Error restoring keyboard\n");
    return 1;
  }

  if (kbd_print_no_sysinb(cnt) != 0) {
    printf("Failed kbd_print_no_sysinb\n");
    return 1;
  }

  return 0;
}

int(kbd_test_timed_scan)(uint8_t n) {
  uint8_t kb_bit_no, timer_bit_no;

  if (keyboard_subscribe_interrupts(&kb_bit_no) != 0) {
    printf("Error subscribing keyboard\n");
    return 1;
  }
  if (timer_subscribe_int(&timer_bit_no) != 0) {
    printf("Error subscribing timer\n");
    return 1;
  }

  counter = 0;
  uint8_t packet[2];
  int ipc_status, r, i = 0, max_counter = n * sys_hz();
  message msg;

  while((scancode != BREAK_ESC) && (counter < max_counter)) {
    if((r = driver_receive(ANY, &msg, &ipc_status)) != 0) {
      printf("driver_receive failed with: %d", r);
      continue;
    }

    if (is_ipc_notify(ipc_status)) {
      switch (_ENDPOINT_P(msg.m_source)) {
        case HARDWARE:
          if (msg.m_notify.interrupts & BIT(timer_bit_no)) {
            timer_int_handler();
          }
          if (msg.m_notify.interrupts & BIT(kb_bit_no)) {
            counter = 0;
            
            kbc_ih();

            if (return_value == 0) {
              packet[i] = scancode;

              if (scancode == TWO_BYTES) {
                i++;
              }
              else {
                if (kbd_print_scancode(!(scancode & MAKE_CODE), i + 1, packet) != 0) return 1;
                i = 0;
              }
            }
          }
          break;
        default:
          break;
      }
    }
  }

  if (keyboard_unsubscribe_interrupts() != 0) {
    printf("Error unsubscribing keyboard\n");
    return 1;
  }

  if (timer_unsubscribe_int() != 0) {
    printf("Error unsubscribing timer\n");
    return 1;
  }

  return 0;
}
