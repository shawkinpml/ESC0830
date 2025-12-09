/**********************************************************************
* $Id$		hm_i2c.h
*//**
* @file		hm_i2c.h
* @author	HCW MCU SW Application Team
* 
* Copyright(C) 2021, HCW
* All rights reserved.
*
**********************************************************************/

/* Peripheral group ----------------------------------------------------------- */
/** @defgroup I2C	I2C (Inter-IC Control bus)
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_I2C_H_
#define __HM_I2C_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif


/* Private Macros ------------------------------------------------------------- */
/** @defgroup I2C_Private_Macros I2C Private Macros
 * @{
 */
/* --------------------- BIT DEFINITIONS -------------------------------------- */
/*******************************************************************//**
 * I2C Control register description
 *********************************************************************/
#define I2C_I2CONSET_SD(n)		(((n&0x1)<<6)) /*!< IC_SLAVE_DISABLE */
#define I2C_I2CONSET_RE(n)		(((n&0x1)<<5)) /*!< IC_RESTART_EN */
#define I2C_I2CONSET_10AM(n)	(((n&0x1)<<4)) /*!< IC_10BITADDR_MASTER */
#define I2C_I2CONSET_10AS(n)	(((n&0x1)<<3)) /*!< IC_10BITADDR_SLAVE */
#define I2C_I2CONSET_SM(n)		(((n&0x3)<<1)) /*!< IC_MAX_SPEED_MODE */
#define I2C_I2CONSET_MM(n)		(((n&0x1)<<0)) /*!< IC_MASTER_MODE */

/**
 * @}
 */

#define I2C_INTRSTAT_RXFULL		(1<<2)
#define I2C_INTRSTAT_RD_REQ		(1<<5)
#define I2C_INTRSTAT_TX_ABRT	(1<<6)
#define I2C_STAT_SLV_ACTIVITY	(1<<6)


/* Public Types --------------------------------------------------------------- */
/** @defgroup I2C_Public_Types I2C Public Types
 * @{
 */

typedef enum
{
	I2C_MASTER_MODE,
	I2C_SLAVE_MODE,
	I2C_GENERAL_MODE,
} en_I2C_Mode;


/**
 * @brief Master transfer setup data structure definitions
 */
typedef struct
{
  uint32_t	TargetSlaverAddr;				/**< Slave address in 7bit mode */
	uint32_t RxThresholdLevel;
	uint32_t TxThresholdLevel;
} I2C_M_InitTypeDef;



/**
 * @}
 */

/**
 * @brief Slave transfer setup data structure definitions
 */
typedef struct
{
  __IO uint8_t*         tx_data;

} I2C_S_InitTypeDef;


/**
 * @}
 */


/* Public Functions ----------------------------------------------------------- */
/** @defgroup I2C_Public_Functions I2C Public Functions
 * @{
 */

/* I2C Init/DeInit functions ---------- */
void I2C_Init(HM_I2C_TypeDef *I2Cx,I2C_M_InitTypeDef init);
void I2C_DeInit(HM_I2C_TypeDef *I2Cx);
void I2C_Cmd(HM_I2C_TypeDef *I2Cx, en_I2C_Mode Mode, FunctionalState NewState);
void I2C_IntCmd (HM_I2C_TypeDef *I2Cx,uint32_t Int, FunctionalState NewState);
/* I2C set clock (hz) */
void I2C_SetClock (HM_I2C_TypeDef *I2Cx, uint32_t target_clock);
/* Generate a start condition on I2C bus (in master mode only) */
uint32_t I2C_Start (HM_I2C_TypeDef *I2Cx);
/* Generate a stop condition on I2C bus (in master mode only) */
void I2C_Stop (HM_I2C_TypeDef *I2Cx);
/* I2C send byte subroutine */
uint32_t I2C_SendByte (HM_I2C_TypeDef *I2Cx, uint8_t databyte);
/* I2C get byte subroutine */
uint32_t I2C_GetByte (HM_I2C_TypeDef *I2Cx, uint8_t *retdat, FunctionalState ack);





/**
 * @}
 */


#ifdef __cplusplus
}
#endif

#endif /* __HM_I2C_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
