/****************** DESCRIPTION *****************/

/**
 * Filename: HW_UART.cpp
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose:  Hardware UART wrapper functions.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:
 */


/************ PREPROCESSOR DIRECTIVES ***********/

/*--- Includes ---*/

// Essential Arduino library.
#include <Arduino.h>

// Local modules.
#include "HW_UART.h"


/******************* FUNCTIONS ******************/

uint32_t HW_UART_read_line(char *buf, uint32_t str_max_len, uint32_t conn_timeout, uint32_t read_slowdown)
{
    // Connection timeout counter.
    uint64_t current_millis = millis();
    uint64_t previous_millis = current_millis;

    uint32_t i = 0, j = 0;
    bool lf = 0;
    while (Serial.available() && current_millis - previous_millis < conn_timeout && !lf) {
        char c = Serial.read();
        ++i;

        if (j < str_max_len) {
            buf[j] = c;
            ++j;
        }

        if (c == '\n') {
            lf = 1;
        }

        current_millis = millis();

        if (read_slowdown > 0) {
            delay(read_slowdown);  /* A pause to ensure that reading from a buffer
                                    * won't run ahead of writing to it.
                                    */
        }
    }

    return i;
}
