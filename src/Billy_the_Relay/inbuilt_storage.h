/****************** DESCRIPTION *****************/

/**
 * Filename: inbuilt_storage.h
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Purpose: чтение и запись строк во встроенный накопитель устройства
 * с помощью библиотеки EEPROM.h.
 * ----------------------------------------------------------------------------|---------------------------------------|
 * Notes:
 * У микроконтроллеров AVR используется встроенная EEPROM.
 * У микроконтроллеров ESP32, ESP8266 и STM32 используется флеш-память
 * с эмуляцией EEPROM.
 */


/************ PREPROCESSOR DIRECTIVES ***********/

// Include guards.
#ifndef INBUILT_STORAGE_H
#define INBUILT_STORAGE_H

// Project configs.
#include "config_inbuilt_storage.h"


/************** FUNCTION PROTOTYPES *************/

// Инициализация хранилища. Требуется для ESP32, ESP8266 и STM32. Не требуется для AVR.
void inbuilt_storage_init(uint32_t emulated_EEPROM_size);

// Чтение строки.
void inbuilt_storage_read(char *buf, size_t buf_size, uint32_t str_max_len, uint32_t addr);

// Запись строки.
void inbuilt_storage_write(char *str, uint32_t str_len, uint32_t str_max_len, uint32_t addr);


#endif  // Include guards.