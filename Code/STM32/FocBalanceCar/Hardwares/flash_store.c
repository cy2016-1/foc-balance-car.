#include "flash_store.h"

void WriteFlash(uint32_t addr,uint32_t *Data,uint32_t L)
{
	uint32_t i=0;
	/* 1/4解锁FLASH*/
	HAL_FLASH_Unlock();
	/* 2/4擦除FLASH*/
	/*初始化FLASH_EraseInitTypeDef*/
	/*擦除方式页擦除FLASH_TYPEERASE_SECTORS，块擦除FLASH_TYPEERASE_MASSERASE*/
	/*擦除页数*/
	/*擦除地址*/
	FLASH_EraseInitTypeDef FlashSet;
	FlashSet.TypeErase = FLASH_TYPEERASE_SECTORS;
	FlashSet.Sector = 0;
	FlashSet.NbSectors = 1;
	/*设置PageError，调用擦除函数*/
	uint32_t PageError = 0;
	HAL_FLASHEx_Erase(&FlashSet, &PageError);
	/* 3/4对FLASH烧写*/
	for(i=0;i<L;i++)
	{
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addr+4*i, Data[i]);
	}
	/* 4/4锁住FLASH*/
	HAL_FLASH_Lock();
}

void Flash_Read(uint32_t address, uint32_t *data, uint16_t length)
{
	uint16_t i;
	for (i = 0; i < length; i++) {
		data[i] = *(__IO uint32_t *)(address + (i * 4)); // 以字为单位读取Flash
	}
}