/**********************************************************************
* $Id$		hm_iap.h			2021-10-27
*//**
* @file		hm_iap.h
* @brief	Contains all functions support for IAP firmware library
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
/** @defgroup IAP	(In Application Programming)
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_IAP_H_
#define __HM_IAP_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif


/** @defgroup IAP_Public_Macros IAP Public Macros
 * @{
 */

/** IAP entry location */
#define IAP_LOCATION              (0x0013f801)

/**
 * @}
 */

/** @defgroup IAP_Public_Types IAP Public Types
 * @{
 */

/**
 * @brief IAP command code definitions
 */
typedef enum
{
    IAP_PREPARE = 50,       // Prepare sector(s) for write operation
    IAP_COPY_RAM2FLASH = 51,     // Copy RAM to Flash
    IAP_ERASE = 52,              // Erase sector(s)
    IAP_BLANK_CHECK = 53,        // Blank check sector(s)
    IAP_READ_PART_ID = 54,       // Read chip part ID
    IAP_READ_BOOT_VER = 55,      // Read chip boot code version
    IAP_COMPARE = 56,            // Compare memory areas
    IAP_REINVOKE_ISP = 57,       // Reinvoke ISP
    IAP_READ_SERIAL_NUMBER = 58, // Read serial number
    IAP_ERASE_PAGE = 59,              // Erase page(s)
    IAP_BLANK_CHECK_PAGE = 60,        // Blank check page(s)
	IAP_BUFFER_ACC = 61,		  // Buffer Accelerator

}  IAP_COMMAND_CODE;

/**
 * @brief IAP status code definitions
 */
typedef enum
{
    CMD_SUCCESS,	             // Command is executed successfully.
    INVALID_COMMAND,             // Invalid command.
    SRC_ADDR_ERROR,              // Source address is not on a word boundary.
    DST_ADDR_ERROR,              // Destination address is not on a correct boundary.
    SRC_ADDR_NOT_MAPPED,         // Source address is not mapped in the memory map.
    DST_ADDR_NOT_MAPPED,         // Destination address is not mapped in the memory map.
    COUNT_ERROR,	               // Byte count is not multiple of 4 or is not a permitted value.
    INVALID_SECTOR,	           // Sector number is invalid.
    SECTOR_NOT_BLANK,	           // Sector is not blank.
    SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION,	// Command to prepare sector for write operation was not executed.
    COMPARE_ERROR,               // Source and destination data is not same.
    BUSY,		                   // Flash programming hardware interface is busy.
} IAP_STATUS_CODE;

/**
 * @brief IAP write length definitions
 */
typedef enum {
  //IAP_WRITE_256  = 256,
  IAP_WRITE_512  = 512,
  IAP_WRITE_1024 = 1024,
  IAP_WRITE_4096 = 4096,
} IAP_WRITE_SIZE;

/**
 * @brief IAP command structure
 */
typedef struct {
    uint32_t cmd;   // Command
    uint32_t param[4];      // Parameters
    uint32_t status;        // status code
    uint32_t result[4];     // Result
} IAP_COMMAND_Type;

/**
 * @}
 */
 
/* Public Functions ----------------------------------------------------------- */
/** @defgroup IAP_Public_Functions IAP Public Functions
 * @{
 */

/**  Prepare sector(s) for write operation */
IAP_STATUS_CODE PrepareSector(uint32_t start_sec, uint32_t end_sec);
/**  Copy RAM to Flash */
IAP_STATUS_CODE CopyRAM2Flash(uint32_t dest, uint32_t source, IAP_WRITE_SIZE size);
/**  Prepare sector(s) for write operation */
IAP_STATUS_CODE EraseSector(uint32_t start_sec, uint32_t end_sec);
/**  Blank check sectors */
IAP_STATUS_CODE BlankCheckSector(uint32_t start_sec, uint32_t end_sec,
                                 uint32_t *first_nblank_loc, 
								 uint32_t *first_nblank_val);
/**  Read part identification number */
IAP_STATUS_CODE ReadPartID(uint32_t *partID);
/**  Read boot code version */
IAP_STATUS_CODE ReadBootCodeVer(uint8_t *major, uint8_t* minor);
/**  Read Device serial number */
IAP_STATUS_CODE ReadDeviceSerialNum(uint32_t *uid);
/**  Compare memory */
IAP_STATUS_CODE Compare(uint8_t *addr1, uint8_t *addr2, uint32_t size);
/**  Invoke ISP */
void InvokeISP(void);
/**  Buffer Accelerator */
void FlashBufferAccelerator(uint8_t index,uint8_t base);

/**
 * @}
 */




/**
 * @}
 */


#ifdef __cplusplus
}
#endif


#endif /* __HM_IAP_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
