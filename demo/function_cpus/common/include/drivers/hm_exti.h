/**********************************************************************
* $Id$		hm_exti.h			2021-09-29
*//**
* @file		hm_exti.h
* @brief	Contains all functions support for External Interrupt
*			firmware library on HM3C1778
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
/** @defgroup EXTI	EXTI (External Interrupt)
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_EXTI_H_
#define __HM_EXTI_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif


/* Private Macros ------------------------------------------------------------- */
/** @defgroup EXTI_Private_Macros EXTI Private Macros
 * @{
 */
/*********************************************************************//**
 * Macro defines for EXTI  control register
 **********************************************************************/
#define EXTI_EINT0_BIT_MARK 	0x01
#define EXTI_EINT1_BIT_MARK 	0x02
#define EXTI_EINT2_BIT_MARK 	0x04
#define EXTI_EINT3_BIT_MARK 	0x08

/**
 * @}
 */

/* Private Macros ------------------------------------------------------------- */
/** @defgroup EXTI_Public_Types EXTI Public Types
 * @{
 */

/**
 * @brief EXTI external interrupt line option
 */
typedef enum
{
	EXTI_EINT0, /*!<  External interrupt 0, P2.10 */
	EXTI_EINT1, /*!<  External interrupt 0, P2.11 */
	EXTI_EINT2, /*!<  External interrupt 0, P2.12 */
	EXTI_EINT3 	/*!<  External interrupt 0, P2.13 */
} EXTI_LINE_ENUM;

/**
 * @brief EXTI mode option
 */
typedef enum
{
	EXTI_MODE_LEVEL_SENSITIVE, 	/*!< Level sensitivity is selected */
	EXTI_MODE_EDGE_SENSITIVE  	/*!< Edge sensitivity is selected */
} EXTI_MODE_ENUM;

/**
 * @brief EXTI polarity option
 */
typedef enum
{
	EXTI_POLARITY_LOW_ACTIVE_OR_FALLING_EDGE,	/*!< Low active or falling edge sensitive
												depending on pin mode */
	EXTI_POLARITY_HIGH_ACTIVE_OR_RISING_EDGE	/*!< High active or rising edge sensitive
												depending on pin mode */
} EXTI_POLARITY_ENUM;

/**
 * @brief EXTI Initialize structure
 */
typedef struct
{
	/** Select external interrupt pin (EINT0, EINT1, EINT 2, EINT3) */
	EXTI_LINE_ENUM EXTI_Line;

	/** Choose between Level-sensitivity or Edge sensitivity */
	EXTI_MODE_ENUM EXTI_Mode;

	/** If EXTI mode is level-sensitive: this element use to select low or high active level
	if EXTI mode is polarity-sensitive: this element use to select falling or rising edge */
	EXTI_POLARITY_ENUM EXTI_polarity;

}EXTI_InitTypeDef;


/**
 * @}
 */


/* Public Functions ----------------------------------------------------------- */
/** @defgroup EXTI_Public_Functions EXTI Public Functions
 * @{
 */

void EXTI_Init(void);
void EXTI_DeInit(void);

void EXTI_Config(EXTI_InitTypeDef *EXTICfg);
void EXTI_SetMode(EXTI_LINE_ENUM EXTILine, EXTI_MODE_ENUM mode);
void EXTI_SetPolarity(EXTI_LINE_ENUM EXTILine, EXTI_POLARITY_ENUM polarity);
void EXTI_ClearEXTIFlag(EXTI_LINE_ENUM EXTILine);
void EXTI_Enable(FunctionalState state);


/**
 * @}
 */


#ifdef __cplusplus
}
#endif


#endif /* __HM_EXTI_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
