/**********************************************************************
* $Id$		hm_flash.h			2021-10-27
*//**
* @file		hm_flash.h
* @brief	Contains all functions support for FLASH firmware library
*			on HM3C1788,HM4C123,HM3S9B96
* @version	0.01
* @date		27. Oct. 2021
* @author	PML MCU SW Application Team
* 
* Copyright(C) 2021, PML 
* All rights reserved.
*
***********************************************************************
*
**********************************************************************/

/* Peripheral group ----------------------------------------------------------- */
/** @defgroup FLASH	
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_FLASH_H_
#define __HM_FLASH_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif


/* Private Macros ------------------------------------------------------------- */
/** @defgroup FLASH_Private_Macros flash Private Macros
 * @{
 */


/*********************************************************************//**
 * Macro defines for AcceleratorCtrl1 register
 **********************************************************************/

/** FLASH buffer0 bit pos */
#define FLASH_ACC_BUFF0BASE_POS				((uint32_t)(0))
/** FLASH buffer0 base */
#define FLASH_ACC_BUFF0BASE_MASK			((uint32_t)(0xf<<0))
/** FLASH buffer0 enable */
#define FLASH_ACC_BUFF0BASE_EN				((uint32_t)(1<<4))
/** FLASH buffer0 refill enable */
#define FLASH_ACC_BUFF0BASE_REFILL_EN		((uint32_t)(1<<5))
/** FLASH buffer0 refill enable */
#define FLASH_ACC_BUFF0BASE_DONE			((uint32_t)(1<<22))

/** FLASH buffer1 bit pos */
#define FLASH_ACC_BUFF1BASE_POS				((uint32_t)(8))
/** FLASH buffer1 base */
#define FLASH_ACC_BUFF1BASE_MASK			((uint32_t)(0xf<<8))
/** FLASH buffer1 enable */
#define FLASH_ACC_BUFF1BASE_EN				((uint32_t)(1<<12))
/** FLASH buffer1 refill enable */
#define FLASH_ACC_BUFF1BASE_REFILL_EN		((uint32_t)(1<<13))
/** FLASH buffer0 refill enable */
#define FLASH_ACC_BUFF1BASE_DONE			((uint32_t)(1<<23))

/** FLASH buffer2 bit pos */
#define FLASH_ACC_BUFF2BASE_POS				((uint32_t)(16))
/** FLASH buffer2 base */
#define FLASH_ACC_BUFF2BASE_MASK			((uint32_t)(0xf<<16))
/** FLASH buffer2 enable */
#define FLASH_ACC_BUFF2BASE_EN				((uint32_t)(1<<20))
/** FLASH buffer2 refill enable */
#define FLASH_ACC_BUFF2BASE_REFILL_EN		((uint32_t)(1<<21))
/** FLASH buffer2 refill enable */
#define FLASH_ACC_BUFF2BASE_DONE			((uint32_t)(1<<24))




/**
 * @}
 */


/* Public Functions ----------------------------------------------------------- */
/** @defgroup EXTI_Public_Functions EXTI Public Functions
 * @{
 */

void FLASH_PreProgram(uint32_t addr);
void FLASH_ClearPageLatchs(void);
void FLASH_EraseOnePage(void);
void FLASH_ErasePage(uint32_t page);
void FLASH_ClearPageLatchs(void);
void FLASH_WriteOnePageLatchs(uint32_t offset,uint32_t data);
void FLASH_WriteAllPageLatchs(uint32_t offset,uint32_t data);
void FLASH_WaitDone( void );
void FLASH_RomProgram(uint32_t addr);
uint32_t FLASH_ReadFlashWord(uint32_t addr);
void FLASH_Lock(void);
void FLASH_Unlock(void);
void FLASH_AcceleratorBuffer(uint8_t index, uint32_t addr);
void FLASH_EraseSector(uint32_t start_sec, uint32_t end_sec);
void FLASH_CopyRAM2Flash(uint32_t      dest, uint32_t source, uint32_t size);
Status FLASH_Compare(uint32_t addr1, uint32_t addr2, uint32_t size);
Status FLASH_BlankCheckPage(uint32_t start_page, uint32_t end_page,
                                 uint32_t *first_nblank_loc, 
								 uint32_t *first_nblank_val);

Status FLASH_BlankCheckSector(uint32_t start_sec, uint32_t end_sec,
                                 uint32_t *first_nblank_loc, 
								 uint32_t *first_nblank_val);
void FLASH_WritePage(uint32_t start_addr,uint32_t src_addr);
void FLASH_ProgramSuperROM(void);

/**
 * @}
 */


#ifdef __cplusplus
}
#endif


#endif /* __HM_FLASH_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
