/**********************************************************************
* $Id$		hm_crc.h			2021-09-29
*//**
* @file		hm_crc.h
* @brief	Contains all functions support for CRC firmware library on
*			HM3C1788,HM4C123,HM3S9B96
* @version	0.01
* @date		29. Sept. 2021
* @author	PML MCU SW Application Team
* 
* Copyright(C) 2024, Purple Moutain Laboratories
* All rights reserved.
*
***********************************************************************
*
**********************************************************************/


/* Peripheral group ----------------------------------------------------------- */
/** @defgroup CRC	CRC (Cyclic Redundancy Check)
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_CRC_H_
#define __HM_CRC_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif

/* Private macros ------------------------------------------------------------- */
/** @defgroup CRC_Private_Macros CRC Private Macros
 * @{
 */

/* -------------------------- BIT DEFINITIONS ----------------------------------- */
/*********************************************************************//**
 * Macro defines for CRC mode register
 **********************************************************************/
#define CRC_BIT_RVS_WR			(1<<2)
#define CRC_CMPL_WR				(1<<3)
#define CRC_BIT_RVS_SUM			(1<<4)
#define CRC_CMPL_SUM			(1<<5)

#define CRC_STATUS_EMPTY			(1<<3)
#define CRC_STATUS_FULL				(1<<2)
#define CRC_STATUS_DONE				(1<<1)
#define CRC_STATUS_READY			(1<<0)
/**
 * @}
 */
/* Private types ------------------------------------------------------------- */
typedef enum
{
	CRC_POLY_CRCCCITT = 0,			/** CRC CCITT polynomial */
	CRC_POLY_CRC16,					/** CRC-16 polynomial */
	CRC_POLY_CRC32					/** CRC-32 polynomial */
}CRC_Type;

typedef enum
{
	CRC_WR_8BIT = 1,				/** 8-bit write: 1-cycle operation */
	CRC_WR_16BIT = 2,					/** 16-bit write: 2-cycle operation */
	CRC_WR_32BIT = 4,					/** 32-bit write: 4-cycle operation */
}CRC_WR_SIZE;

/* Public Functions ----------------------------------------------------------- */
/** @defgroup CRC_Public_Functions CRC Public Functions
 * @{
 */
void CRC_Init(CRC_Type CRCType, uint32_t blocksize);
void CRC_Reset(void);
void CRC_WaitDone(void);
void CRC_IntClear(void);
uint32_t CRC_CalcDataChecksum(uint32_t data, CRC_WR_SIZE SizeType);
uint32_t CRC_CalcBlockChecksum(void *blockdata, uint32_t blocksize, CRC_WR_SIZE SizeType);

/**
 * @}
 */


#ifdef __cplusplus
}
#endif


#endif /* __HM_CRC_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
