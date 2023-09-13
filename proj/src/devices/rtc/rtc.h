#ifndef _LCOM_RTC_H_
#define _LCOM_RTC_H_

#include <minix/sysutil.h>
#include <lcom/lcf.h>

#define RTC_MASK            5
#define RTC_IRQ             8

#define REGISTER_INPUT      0x70
#define REGISTER_OUTPUT     0x71
#define REGISTER_UPDATING   10
#define REGISTER_COUNTING   11

#define SECONDS    0
#define MINUTES    2
#define HOURS      4   
#define DAY        7
#define MONTH      8
#define YEAR       9

#define BINARY              BIT(2)
#define UPDATING            BIT(7)

typedef struct {
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
} real_time_info;

/**
 * @brief Sets up the RTC by initializing the binary mode and updating the time information.
 */
void rtc_setup();

/**
 * @brief Sends a command to the RTC and retrieves the output value.
 * @param command The command to be sent to the RTC.
 * @param output Pointer to a variable where the output value will be stored.
 * @return Returns 0 upon success, non-zero otherwise.
 */
int rtc_output(uint8_t command, uint8_t *output);

/**
 * @brief Checks if the RTC is currently updating.
 * @return Returns 1 if the RTC is updating, 0 otherwise.
 */
int rtc_is_updating();

/**
 * @brief Checks if the RTC is in binary mode.
 * @return Returns 1 if the RTC is in binary mode, 0 otherwise.
 */
int rtc_is_binary();

/**
 * @brief Converts a Binary Coded Decimal (BCD) number to binary representation.
 * @param bcd_number The BCD number to be converted.
 * @return The converted binary number.
 */
uint8_t to_binary(uint8_t bcd_number);

/**
 * @brief Updates the time information by reading the current values from the RTC.
 * @return Returns 0 upon success, non-zero otherwise.
 */
int rtc_update_time();

/**
 * @brief Retrieves the current hour from the RTC.
 * @return The current hour.
 */
uint8_t rtc_get_hour();

#endif
