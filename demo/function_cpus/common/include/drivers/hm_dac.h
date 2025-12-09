/**********************************************************************
* $Id$		hm_dac.h			2021-09-29
*//**
* @file		hm_dac.h
* @brief	Contains all functions support for DAC firmware library on
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
/** @defgroup DAC DAC (Digital-to-Analog Converter)
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_DAC_H_
#define __HM_DAC_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"

#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif

/* Public Macros -------------------------------------------------------------- */
/** @defgroup DAC_Private_Macros DAC Private Macros
 * @{
 */

/** After the selected settling time after this field is written with a
new VALUE, the voltage on the AOUT pin (with respect to VSSA)
is VALUE/1024 � VREF */
#define DAC_VALUE(n) 		((uint32_t)((n&0x3FF)<<6))

/*********************************************************************//**
 * Macro defines for CTRL_REG
 **********************************************************************/
#define DAC_PDN 		    ((uint32_t)(1))
#define DAC_SYNC_EN 		((uint32_t)(1<<2))
#define DAC_AUTO 		    ((uint32_t)(1<<3))
#define DAC_CNT_DOWN_EN 	((uint32_t)(1<<4))
#define DAC_CNT_UP_EN 		((uint32_t)(1<<5))
#define DAC_DMA_EN 		    ((uint32_t)(1<<7))
#define DAC_WATERMARK_LEVEL(n) 		((uint32_t)((n&0x3)<<8))
#define DAC_FILT_EN 		((uint32_t)(1<<12))


/** If this bit = 0: The settling time of the DAC is 1 microsecond max,
 * and the maximum current is 700 microAmpere
 * If this bit = 1: The settling time of the DAC is 2.5 microsecond
 * and the maximum current is 350 microAmpere */
#define DAC_BIAS_EN			((uint32_t)(1<<16))

/** Value to reload interrupt DMA counter */
#define DAC_CCNT_VALUE(n)  ((uint32_t)(n&0xffff))

/** DCAR double buffering */
#define DAC_DBLBUF_ENA		((uint32_t)(1<<1))

/** DCAR Time out count enable */
#define DAC_CNT_ENA			((uint32_t)(1<<2))

/** DCAR DMA access */
#define DAC_DMA_ENA			((uint32_t)(1<<3))

/** DCAR DACCTRL mask bit */
#define DAC_DACCTRL_MASK	((uint32_t)(0x0F))

/** Macro to determine if it is valid DAC peripheral */
#define PARAM_DACx(n)		(((uint32_t *)n)==((uint32_t *)HM_DAC))

/** Macro to check DAC current optional parameter */
#define	PARAM_DAC_CURRENT_OPT(OPTION) ((OPTION == DAC_MAX_CURRENT_700uA)\
											||(OPTION == DAC_MAX_CURRENT_350uA))
/**
 * @}
 */
/* Public Types --------------------------------------------------------------- */
/** @defgroup DAC_Public_Types DAC Public Types
 * @{
 */

/**
 * @brief Current option in DAC configuration option */
typedef enum
{
	DAC_MAX_CURRENT_700uA = 0, 	/*!< The settling time of the DAC is 1 us max,
								and the maximum	current is 700 uA */
	DAC_MAX_CURRENT_350uA		/*!< The settling time of the DAC is 2.5 us
								and the maximum current is 350 uA */
} DAC_CURRENT_OPT;

/**
 * @brief Configuration for DAC converter control register */
typedef struct
{

	uint8_t DBLBUF_ENA; 	/**<
							- If 0: Disable DACR double buffering

							- If 1: when bit CNT_ENA, enable DACR double buffering feature
							*/
	uint8_t CNT_ENA;		/*!<
							- If 0: Time out counter is disable

							-1: Time out conter is enable
							*/
	uint8_t DMA_ENA;		/*!<
							- If 0: DMA access is disable

							- If 1: DMA burst request
							*/
	uint8_t RESERVED;

} DAC_CONVERTER_CFG_Type;

/**
 * @}
 */

/* Public Functions ----------------------------------------------------------- */
/** @defgroup DAC_Public_Functions DAC Public Functions
 * @{
 */

void 	DAC_Init(uint8_t DAC_Id);
void    DAC_UpdateValue (uint8_t DAC_Id, uint32_t dac_value);
void    DAC_SetBias (uint8_t DAC_Id,uint32_t bias);
void    DAC_ConfigDAConverterControl (uint8_t DAC_Id,DAC_CONVERTER_CFG_Type *DAC_ConverterConfigStruct);
void 	DAC_SetDMATimeOut(uint8_t DAC_Id,uint32_t time_out);
uint8_t DAC_IsIntRequested(uint8_t DAC_Id);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif


#endif /* __HM_DAC_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */

