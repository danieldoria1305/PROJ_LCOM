#include <lcom/lcf.h>
#include <stdint.h>
#include "mouse.h"
#include "../i8042.h"
#include "../../utils/utils.h"

int mouse_hook_id = MOUSE_IRQ;
int packet_index;
uint8_t mouse_bytes[3];

int (mouse_subscribe_int)(uint8_t *bit_no) {
  if (bit_no == NULL) return 1;
  *bit_no = MOUSE_IRQ;
  return sys_irqsetpolicy(MOUSE_IRQ, IRQ_REENABLE | IRQ_EXCLUSIVE, &mouse_hook_id);
}

int (mouse_unsubscribe_int)() {
  return sys_irqrmpolicy(&mouse_hook_id);
}

int (enable_data_reporting)() {
  for (int i = 0; i < 3; i++) {
    uint8_t status;

    if (util_sys_inb(KBC_STATUS_REG, &status) != 0) return 1;
    if (status & IBF) continue;

    if (sys_outb(KBC_IN_CMD, WRITE_MOUSE_BYTE) != 0) return 1;
    if (sys_outb(KBC_OUT_CMD, ENABLE_DATA) != 0) return 1;

    uint8_t acknowledgement;
    if (util_sys_inb(KBC_OUT_CMD, &acknowledgement) != 0) return 1;
    if (acknowledgement == ACK) return 0;
    if (acknowledgement == ERROR) return 1;
  }
  return 1;
}

int (disable_data_reporting)() {
  for (int i = 0; i < 3; i++) {
    uint8_t status;

    if (util_sys_inb(KBC_STATUS_REG, &status) != 0) return 1;
    if (status & IBF) continue;

    if (sys_outb(KBC_IN_CMD, WRITE_MOUSE_BYTE) != 0) return 1;
    if (sys_outb(KBC_OUT_CMD, DISABLE_DATA) != 0) return 1;

    uint8_t acknowledgement;
    if (util_sys_inb(KBC_OUT_CMD, &acknowledgement) != 0) return 1;
    if (acknowledgement == ACK) return 0;
    if (acknowledgement == ERROR) return 1;
  }
  return 1;
}

void (mouse_int_handler)() {
  uint8_t* current_byte = (uint8_t*) malloc(sizeof(uint8_t));
  if (util_sys_inb(KBC_OUT_CMD, current_byte) != 0)
    return;

  uint8_t* status = (uint8_t*) malloc(sizeof(uint8_t));
  if (util_sys_inb(KBC_STATUS_REG, status) != 0) return;
  if (*status & (TO_ERR | PAR_ERR)) return;

  if ((packet_index == 0 && *current_byte & BIT(3)) || packet_index != 0) {
    mouse_bytes[packet_index] = *current_byte;
    packet_index++;
  }
}

void (parse_mouse_packet)(struct packet* pp) {
  pp->bytes[0] = mouse_bytes[0];
  pp->bytes[1] = mouse_bytes[1];
  pp->bytes[2] = mouse_bytes[2];

  pp->lb = mouse_bytes[0] & MOUSE_LB;
  pp->rb = (mouse_bytes[0] & MOUSE_RB) >> 1;
  pp->mb = (mouse_bytes[0] & MOUSE_MB) >> 2;

  pp->x_ov = (mouse_bytes[0] & MOUSE_X_OVERFLOW) >> 6;
  pp->y_ov = (mouse_bytes[0] & MOUSE_Y_OVERFLOW) >> 7;

  pp->delta_x = (mouse_bytes[0] & MOUSE_X_SIGNAL) ? (0xFF00 | mouse_bytes[1]) : mouse_bytes[1];
  pp->delta_y = (mouse_bytes[0] & MOUSE_Y_SIGNAL) ? (0xFF00 | mouse_bytes[2]) : mouse_bytes[2];

}
