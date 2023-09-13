#include "keyboard.h"

int counter, return_value;
uint8_t scancode;

int hook_id = 1;
int (keyboard_subscribe_interrupts)(uint8_t *bit_no){
    *bit_no = hook_id;
    return sys_irqsetpolicy(IRQ_KEYBOARD, IRQ_REENABLE | IRQ_EXCLUSIVE, &hook_id);
}

int (keyboard_unsubscribe_interrupts)(){
    return sys_irqrmpolicy(&hook_id);
}


int (read_KBC_output)(uint8_t port, uint8_t *output){
    int i = MAX_ATTEMPS;
    uint8_t status;

    while(i) {
        int r = util_sys_inb(KBC_STATUS_REG, &status);
        if (r != 0x55) continue;
        if (status & FULL_OUT_BUFFER) {
            if(util_sys_inb(port,output)!=0) return 1;
            return 0;
        }
        tickdelay(WAIT_KBC);
        i--;
    }
    return 1;
}

int kbd_error = 0;
uint8_t kbd_output = 0;
void (kbc_ih)(){
    int error = read_KBC_output(KBC_OUT_CMD, &kbd_output);
    kbd_error = 0;
    uint8_t status;
    util_sys_inb(KBC_STATUS_REG, &status);
    if(status & (TIMEOUT_ERROR | PARITY_ERROR)) kbd_error=1;
    if (error == -1) kbd_error = 1;
}


int (keyboard_restore)(){
    uint8_t kbc_command;

    if(sys_outb(KBC_IN_CMD, KBC_READ_CMD) != 0) return 1;
    if(util_sys_inb(KBC_OUT_CMD, &kbc_command) != 0) return 1;

    kbc_command |= BIT(0);

    if(sys_outb(KBC_IN_CMD, KBC_WRITE_CMD) != 0) return 1;
    if(sys_outb(KBC_OUT_CMD, kbc_command) != 0) return 1;

    return 0;
}
