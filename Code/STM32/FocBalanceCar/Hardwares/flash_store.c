#include "flash_store.h"

void WriteFlash(uint32_t addr,uint32_t *Data,uint32_t L)
{
	uint32_t i=0;
	/* 1/4����FLASH*/
	HAL_FLASH_Unlock();
	/* 2/4����FLASH*/
	/*��ʼ��FLASH_EraseInitTypeDef*/
	/*������ʽҳ����FLASH_TYPEERASE_SECTORS�������FLASH_TYPEERASE_MASSERASE*/
	/*����ҳ��*/
	/*������ַ*/
	FLASH_EraseInitTypeDef FlashSet;
	FlashSet.TypeErase = FLASH_TYPEERASE_SECTORS;
	FlashSet.Sector = 0;
	FlashSet.NbSectors = 1;
	/*����PageError�����ò�������*/
	uint32_t PageError = 0;
	HAL_FLASHEx_Erase(&FlashSet, &PageError);
	/* 3/4��FLASH��д*/
	for(i=0;i<L;i++)
	{
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addr+4*i, Data[i]);
	}
	/* 4/4��סFLASH*/
	HAL_FLASH_Lock();
}

void Flash_Read(uint32_t address, uint32_t *data, uint16_t length)
{
	uint16_t i;
	for (i = 0; i < length; i++) {
		data[i] = *(__IO uint32_t *)(address + (i * 4)); // ����Ϊ��λ��ȡFlash
	}
}