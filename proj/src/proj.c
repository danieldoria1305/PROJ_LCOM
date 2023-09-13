#include <lcom/lcf.h>
#include <lcom/proj.h>

#include <stdio.h>
#include <stdint.h>

#include "devices/timer/timer.h"
#include "devices/kbc/keyboard/keyboard.h"
#include "devices/kbc/mouse/mouse.h"
#include "devices/kbc/i8042.h"
#include "devices/rtc/rtc.h"
#include "devices/graphics/graphics.h"

#include "controller/gameController/gameController.h"
#include "controller/timerController/timerController.h"
#include "controller/keyboardController/keyboardController.h"
#include "controller/mouseController/mouseController.h"

#include "view/pixmaps/pixmaps.h"
#include "view/wallsView/wallsView.h"
#include "view/pacmanView/pacmanView.h"
#include "view/ghostsView/ghostsView.h"
#include "view/timerView/timerView.h"
#include "view/mouseView/mouseView.h"
#include "view/menuView/menuView.h"

extern bool isMenu, isGame, isPause, end, start;
extern unsigned int score, gameDuration;

uint8_t* timer_bit_no, *keyboard_bit_no, *mouse_bit_no;

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

int (menuLoop)() {
    if (enable_data_reporting() != 0) return 1;

    mouse_bit_no = (uint8_t*) malloc(sizeof(uint8_t));
    if (mouse_subscribe_int(mouse_bit_no) != 0) return 1;

    drawMenu();
    rtc_setup();

    message msg;
    int ipc_status, r;
    int mouse_irq_set = BIT(*mouse_bit_no), rtc_irq_set = BIT(RTC_IRQ);

    while (isMenu) {
        if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0 ) { 
            printf("driver_receive failed with: %d", r);
            continue;
        }
        if (is_ipc_notify(ipc_status)) {
            switch (_ENDPOINT_P(msg.m_source)) {
                case HARDWARE:        
                    if (msg.m_notify.interrupts & rtc_irq_set) {
                          rtc_update_time();
                    }
                    if (msg.m_notify.interrupts & mouse_irq_set) {
                        mouseInterruptHandler();
                    }
                    break;
                default:
                    break;
            }
        }
    }

    eraseMenu();
    
    if (mouse_unsubscribe_int() != 0) return 1;
    if (disable_data_reporting() != 0) return 1;

    return 0;
}

int (gameLoop)() {
    timer_bit_no = (uint8_t*) malloc(sizeof(uint8_t));
    if (timer_subscribe_int(timer_bit_no) != 0) return 1;

    keyboard_bit_no = (uint8_t*) malloc(sizeof(uint8_t));
    if (keyboard_subscribe_int(keyboard_bit_no) != 0) return 1;

    if (!isPause) drawGameElements(); 

    start = false;

    message msg;
    int ipc_status, r;
    int timer_irq_set = BIT(*timer_bit_no), keyboard_irq_set = BIT(*keyboard_bit_no);

    while (isGame) {
        if ((r = driver_receive(ANY, &msg, &ipc_status)) != 0 ) { 
            printf("driver_receive failed with: %d", r);
            continue;
        }
        if (is_ipc_notify(ipc_status)) {
            switch (_ENDPOINT_P(msg.m_source)) {
                case HARDWARE:        
                    if (msg.m_notify.interrupts & timer_irq_set) {
                        timerInterruptHandler();
                        if (!isPause) {
                            draw_rectangle(TIMER_X, TIMER_Y, TIMER_WIDTH, TIMER_HEIGHT, 0);
                            drawTimer();
                            if(score == 3500){
                                drawYouWon();
                                sleep(5);
                                isGame = false;
                                end = true;
                            }
                        }
                    }
                    if (msg.m_notify.interrupts & keyboard_irq_set) {
                        keyboard_int_handler();
                        keyHandler();
                    }
                    break;
                default:
                    break;
            }
        }
    }

    if (timer_unsubscribe_int() != 0) return 1;
    if (keyboard_unsubscribe_int() != 0) return 1;

    return 0;
}

int (proj_main_loop)(int argc, char *argv[]) {
    uint16_t mode = 0x105;

    if (graphics_init(mode) != 0) {
        vg_exit();
        return 1;
    }

    initializeGame();

    timer_set_frequency(0, 80);

    if (menuLoop() != 0) {
        vg_exit();
        return 1;
    }

    if (gameLoop() != 0) {
        vg_exit();
        return 1;
    }

    if (!end) {
        drawYouLost();
        sleep(5);         
    }

    if (vg_exit() != 0) return 1;

    return 0;
}
