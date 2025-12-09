/**********************************************************************
* $Id$		hm3c1788_eeprom.h			2021-11-13
*//**
* @file		hm3c1788_eeprom.h
* @brief	Contains all functions support for EEPROM firmware library
*			on HM3C1788
* @version	0.01
* @date		13. Nov. 2021
* @author	PML MCU SW Application Team
* 
* Copyright(C) 2021, PML
* All rights reserved.
*
***********************************************************************
*
**********************************************************************/


/* Peripheral group ----------------------------------------------------------- */
/** @defgroup EEPROM
 * @ingroup HM3C1788CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM3C1788_EEPROM_H_
#define __HM3C1788_EEPROM_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"
#include "hm_iap.h"


#ifdef __cplusplus
extern "C"
{
#endif


/* Private Macros ------------------------------------------------------------- */
/** @defgroup EEPROM_Private_Macros EEPROM Private Macros
 * @{
 */
#define EEPROM_LOCATION					(0xF0000)
#define EEPROM_PAGE_SIZE				(64)
#define EEPROM_PAGE_NUM					(64)


/**
 * @}
 */


/* Public Types --------------------------------------------------------------- */
/** @defgroup EEPROM_Public_Types EEPROM Public Types
 * @{
 */

typedef enum
{
	MODE_8_BIT = 0,
	MODE_16_BIT,
	MODE_32_BIT
}EEPROM_Mode_Type;




/* Public Functions ----------------------------------------------------------- */
/** @defgroup EEPROM_Public_Functions EEPROM Public Functions
 * @{
 */
extern void EEPROM_Init(void);
extern void EEPROM_Write(uint16_t page_offset, uint16_t page_address, void* data, EEPROM_Mode_Type mode, uint32_t size);
extern void EEPROM_Read(uint16_t page_offset, uint16_t page_address, void* data, EEPROM_Mode_Type mode, uint32_t size);
extern void EEPROM_Erase(uint16_t page);


/**
 * @}
 */


#ifdef __cplusplus
}
#endif


#endif /* __HM3C1788_EEPROM_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
