#include <lcom/lcf.h>
#include <stdint.h>
#include "keyboard.h"
#include "../i8042.h"
#include "../../utils/utils.h"

int kbd_hook_id = IRQ_KEYBOARD, num_bytes;
bool make_code, full_scancode;
uint8_t scan_bytes[2];

int (keyboard_subscribe_int)(uint8_t *bit_no) {
    if (bit_no == NULL) return 1;
    *bit_no = IRQ_KEYBOARD;
    return sys_irqsetpolicy(IRQ_KEYBOARD, IRQ_REENABLE | IRQ_EXCLUSIVE, &kbd_hook_id);
}

int (keyboard_unsubscribe_int)() {
    return sys_irqrmpolicy(&kbd_hook_id);
}

void (keyboard_int_handler)() {
    for (int i = 0; i < 3; i++) {
        uint8_t* status = (uint8_t*) malloc(sizeof(uint8_t));
        if (util_sys_inb(KBC_STATUS_REG, status) != 0) return;
        
        if (!(*status & OBF)) return;

        uint8_t* scancode = (uint8_t*) malloc(sizeof(uint8_t));

        if (util_sys_inb(KBC_OUT_CMD, scancode) != 0) return;
        if (util_sys_inb(KBC_STATUS_REG, status) != 0) return;

        if (*status & (PAR_ERR | TO_ERR)) return;

        num_bytes++;

        if (*scancode == SCAN_MSB) {
            full_scancode = false;
            scan_bytes[0] = SCAN_MSB;
            return;

        } else {
            full_scancode = true;
            if (num_bytes == 2) scan_bytes[1] = *scancode;
            else scan_bytes[0] = *scancode;

            if (*scancode & BIT(7)) make_code = false;
            else make_code = true;
            return;
        }

        tickdelay(micros_to_ticks(WAIT_KBC));
    }
}
