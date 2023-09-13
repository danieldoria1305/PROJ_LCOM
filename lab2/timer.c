#include <lcom/lcf.h>
#include <lcom/timer.h>
#include <stdint.h>
#include "i8254.h"


int (timer_set_frequency)(uint8_t timer, uint32_t freq) {
    if (freq < 19 || freq > TIMER_FREQ) return 1;

    unsigned char st;
    if (timer_get_conf(timer,&st) != 0) return 1;

    st = st & 0x0F;

    uint8_t timer_sel = TIMER_SEL0;
    if (timer == 1) timer_sel = TIMER_SEL1;
    if (timer == 2) timer_sel = TIMER_SEL2;

    st = st | BIT(5) | BIT(4) | timer_sel;

    sys_outb(TIMER_CTRL,st);

    unsigned long count = TIMER_FREQ / freq;

    unsigned char lsb, msb;
    if (util_get_LSB(count,&lsb) !=0) return 1;
    if (util_get_MSB(count,&msb)!=0) return 1;

    sys_outb(TIMER_0 + timer, lsb);
    sys_outb(TIMER_0 + timer, msb);
    return 0;

}


int hook_id;

int (timer_subscribe_int)(uint8_t *bit_no) {
    *bit_no = hook_id;
    sys_irqsetpolicy(TIMER0_IRQ, IRQ_REENABLE, &hook_id);
    return 0;
}

int (timer_unsubscribe_int)() {
    return sys_irqrmpolicy(&hook_id);   
}


long timer_counter = 0;
void (timer_int_handler)() {
    timer_counter++;
}


int (timer_get_conf)(uint8_t timer, uint8_t *st) {
    uint8_t read_back_command = TIMER_RB_CMD | TIMER_RB_SEL(timer) | TIMER_RB_COUNT_;
    sys_outb(TIMER_CTRL, read_back_command);
    return util_sys_inb(TIMER_0 + timer, st);
}

int (timer_display_conf)(uint8_t timer, uint8_t st, enum timer_status_field field) {
    union timer_status_field_val conf;

    switch (field) {
        case tsf_all:
            conf.byte = st;
            break;
        case tsf_initial:
            if (st & TIMER_LSB_MSB) conf.in_mode = MSB_after_LSB;     
            else if (st & TIMER_LSB) conf.in_mode = LSB_only;     
            else if (st & TIMER_MSB) conf.in_mode = MSB_only;     
            else conf.in_mode = INVAL_val;      
          break;
        case tsf_mode:
            conf.count_mode = (st >> POS_M_MASK) & TIMER_M_MASK; 
        case tsf_base:
            conf.bcd = st & TIMER_BCD;
    }
    return timer_print_config(timer, field, conf);
}
