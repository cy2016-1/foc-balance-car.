#ifndef _FLASH_STORE_H
#define _FLASH_STORE_H

#include <stdint.h>
#include "main.h"

#define FLASH_SAVE_ADDR  (0x8000000) 

void WriteFlash(uint32_t addr,uint32_t *Data,uint32_t L);
void Flash_Read(uint32_t address, uint32_t *data, uint16_t length);


#endif