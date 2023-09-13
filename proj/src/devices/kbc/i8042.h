#ifndef _LCOM_I8042_H_
#define _LCOM_I8042_H_

#define IRQ_KEYBOARD 1

#define BREAK_ESC  0x81
#define MAKE_CODE  BIT(7)
#define TWO_BYTES  0xE0
#define ENABLE_INT BIT(0)

#define TIMEOUT_ERROR   BIT(6)
#define PARITY_ERROR    BIT(7)
#define AUX             BIT(5)
#define FULL_OUT_BUFFER BIT(0)
#define FULL_IN_BUFFER  BIT(1)

#define KBC_STATUS_REG  0x64
#define KBC_IN_CMD      0x64
#define KBC_OUT_CMD     0x60
#define KBC_READ_CMD    0x20
#define KBC_WRITE_CMD   0x60

#define WAIT_KBC 20000
#define MAX_ATTEMPS 10


#define MOUSE_IRQ 12

#define WRITE_MOUSE_BYTE 0xD4

// mouse commands
#define ENABLE_DATA 0xF4
#define DISABLE_DATA 0xF5
#define ACK 0xFA
#define NACK 0xFE
#define ERROR 0xFC

// status flags
#define OBF BIT(0)
#define IBF BIT(1)
#define PAR_ERR BIT(7)
#define TO_ERR BIT(6)

// value of the most significant byte if the scanecode has 2 bytes
#define SCAN_MSB 0xE0

#define ARROW_UP_MCODE 0x48
#define ARROW_DOWN_MCODE 0x50
#define ARROW_RIGHT_MCODE 0x4D
#define ARROW_LEFT_MCODE 0x4B
#define SPACEBAR_MCODE 0x39
#define P_MCODE 0x19
#define Q_MCODE 0x10

// get value of packet's byte 1 bits
#define MOUSE_LB BIT(0)
#define MOUSE_RB BIT(1)
#define MOUSE_MB BIT(2)
#define MOUSE_X_SIGNAL BIT(4)
#define MOUSE_Y_SIGNAL BIT(5)
#define MOUSE_X_OVERFLOW BIT(6)
#define MOUSE_Y_OVERFLOW BIT(7)

#define INT_PER_SEC 60

#endif /* _LCOM_I8042_H_ */
