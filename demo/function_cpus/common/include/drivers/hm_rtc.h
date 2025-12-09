/**********************************************************************
* $Id$		hm_rtc.h			2021-09-29
*//**
* @file		hm_rtc.h
* @brief	Contains all functions support for RTC firmware library
*			on HM3C1788,HM4C123,HM3S9B96
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
/** @defgroup SYSTICK	RTC (System tick timer)
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_RTC_H_
#define __HM_RTC_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif


/* Private Macros ------------------------------------------------------------- */
/** @defgroup RTC_Private_Macros SysTick Private Macros
 * @{
 */
/**********************************************************************
* CONTROL register definitions
**********************************************************************/
/** CONTROL register mask */
#define RTC_CTLR_BITMASK			((0x00000003))

/** Increment Calendar Disable*/
#define RTC_CTLR_Stop_Cal			((1<<1))

/** Increment Time Disable*/
#define RTC_CTLR_Stop_Tim			((1<<0))

/**********************************************************************
* ALARM_ENABLE register definitions
**********************************************************************/
/** ALARM_ENABLE register mask */
#define RTC_ALARMEN_BITMASK			((0x0000003f))

/** MNTH enable */
#define RTC_ALARMEN_MNTH			((1<<5))

/** DATE reset */
#define RTC_ALARMEN_DATE			((1<<4)) 
 
/** HOUR reset */
#define RTC_ALARMEN_HOUR			((1<<3)) 

/** MIN reset */
#define RTC_ALARMEN_MIN			((1<<2)) 

/** SEC reset */
#define RTC_ALARMEN_SEC			((1<<1)) 

/** HOS reset */
#define RTC_ALARMEN_HOS			((1<<0)) 

/**********************************************************************
* TIME register definitions
**********************************************************************/
/** TIME register mask */
#define RTC_TIME_BITMASK					((0xFF7F7FFF))

/** HOS value */
#define RTC_TIME_HOS_POS							(0)
#define RTC_TIME_HOS_BITMASK				((0x000000FF))

/** SEC value */
#define RTC_TIME_SEC_POS							(8)
#define RTC_TIME_SEC_BITMASK				((0x00007F00))
 
/** MIN value */
#define RTC_TIME_MIN_POS							(16)
#define RTC_TIME_MIN_BITMASK				((0x007F0000))

/** HOUR value */
#define RTC_TIME_HOUR_POS							(24)
#define RTC_TIME_HOUR_BITMASK			((0x3F000000))

/** CH value */
#define RTC_TIME_CH								((1<<31))

/** PM value */
#define RTC_TIME_PM								((1<<30))

/**********************************************************************
* Calendar register definitions
**********************************************************************/
/** Calendar register mask */
#define RTC_CAL_BITMASK					((0xBFFF3FFF))

/** WEEKDAY value */
#define RTC_CAL_WEEKDAY_POS						(0)
#define RTC_CAL_WEEKDAY_BITMASK				((0x00000007))
/** Month value */
#define RTC_CAL_MONTH_POS							(3)
#define RTC_CAL_MONTH_BITMASK					((0x000000F8))
/** Date value */
#define RTC_CAL_DATE_POS							(8)
#define RTC_CAL_DATE_BITMASK					((0x00003F00))
/** Year value */
#define RTC_CAL_YEAR_POS							(16)
#define RTC_CAL_YEAR_BITMASK					((0x003F0000))
/** Century value */
#define RTC_CAL_CENTURY_POS						(24)
#define RTC_CAL_CENTURY_BITMASK				((0x3F000000))
/** CH value */
#define RTC_CAL_CH										((1<<31))

/**********************************************************************
* TIME alarm register definitions
**********************************************************************/
/** TIME register mask */
#define RTC_TIMEALARM_BITMASK					((0x7F7F7FFF))

/** HOS value */
#define RTC_TIMEALARM_HOS_POS							(0)
#define RTC_TIMEALARM_HOS_BITMASK				((0x000000FF))

/** SEC value */
#define RTC_TIMEALARM_SEC_POS							(8)
#define RTC_TIMEALARM_SEC_BITMASK				((0x00007F00))
 
/** MIN value */
#define RTC_TIMEALARM_MIN_POS							(16)
#define RTC_TIMEALARM_MIN_BITMASK				((0x007F0000))

/** HOUR value */
#define RTC_TIMEALARM_HOUR_POS							(24)
#define RTC_TIMEALARM_HOUR_BITMASK			((0x3F000000))

/** PM value */
#define RTC_TIMEALARM_PM								((1<<30))

/**********************************************************************
* Calendar alarm register definitions
**********************************************************************/
/** Calendar register mask */
#define RTC_CALALARM_BITMASK					((0x00003DF8))

/** Month value */
#define RTC_CALALARM_MONTH_POS							(3)
#define RTC_CALALARM_MONTH_BITMASK					((0x000000F8))
/** Date value */
#define RTC_CALALARM_DATE_POS							(8)
#define RTC_CALALARM_DATE_BITMASK					((0x00003F00))

/**********************************************************************
* Interrup register definitions
**********************************************************************/
#define RTC_INT_HOS												((1<<0))
#define RTC_INT_SEC												((1<<1))
#define RTC_INT_MIN												((1<<2))
#define RTC_INT_HOUR											((1<<3))
#define RTC_INT_DATE											((1<<4))
#define RTC_INT_MNTH											((1<<5))
#define RTC_INT_ALRM											((1<<6))


/** Maximum value of hundredths second */
#define RTC_HOS_MAX		99

/** Maximum value of second */
#define RTC_SECOND_MAX		59

/** Maximum value of minute*/
#define RTC_MINUTE_MAX		59

/** Maximum value of hour*/
#define RTC_HOUR_MAX		23

/** Minimum value of month*/
#define RTC_MONTH_MIN		1

/** Maximum value of month*/
#define RTC_MONTH_MAX		12

/** Maximum value of day of Date*/
#define RTC_DATE_MAX 	31

/** Minimum value of day of WeekDay*/
#define RTC_WEEKDAY_MIN 	1

/** Maximum value of day of WeekDay*/
#define RTC_WEEKDAY_MAX 	7

/** Maximum value of year*/
#define RTC_YEAR_MAX		29

/** Maximum value of Century*/
#define RTC_CENTURY_MAX		29
/** Minimum value of year*/
#define RTC_CENTURY_MIN		10


#define RTC_ER_INPUT_CHANNEL_NUM			(3)
 
/**********************************************************************
* Event Monitor/Recorder Control register
**********************************************************************/
#define RTC_ERCTRL_EV0_INTWAKE_ENABLE		(1<<0)
#define RTC_ERCTRL_EV0_GPCLEAR_ENABLE		(1<<1)
#define RTC_ERCTRL_EV0_POS_EDGE				(1<<2)
#define RTC_ERCTRL_EV0_NEG_EDGE				(0<<2)
#define RTC_ERCTRL_EV0_INPUT_ENABLE			(1<<3)

#define RTC_ERCTRL_EV1_INTWAKE_ENABLE		(1<<10)
#define RTC_ERCTRL_EV1_GPCLEAR_ENABLE		(1<<11)
#define RTC_ERCTRL_EV1_POS_EDGE				(1<<12)
#define RTC_ERCTRL_EV1_NEG_EDGE				(0<<12)
#define RTC_ERCTRL_EV1_INPUT_ENABLE			(1<<13)


#define RTC_ERCTRL_EV2_INTWAKE_ENABLE		(1<<20)
#define RTC_ERCTRL_EV2_GPCLEAR_ENABLE		(1<<21)
#define RTC_ERCTRL_EV2_POS_EDGE				(1<<22)
#define RTC_ERCTRL_EV2_NEG_EDGE				(0<<22)
#define RTC_ERCTRL_EV2_INPUT_ENABLE			(1<<23)

#define RTC_ERCTRL_MODE_MASK				(((uint32_t)3)<<30)
#define RTC_ERCTRL_MODE_CLK_DISABLE			(((uint32_t)0)<<30)
#define RTC_ERCTRL_MODE_16HZ				(((uint32_t)1)<<30)
#define RTC_ERCTRL_MODE_64HZ				(((uint32_t)2)<<30)
#define RTC_ERCTRL_MODE_1KHZ				(((uint32_t)3)<<30)

#define RTC_ER_INPUT_CHANNEL_NUM			(3)

/**********************************************************************
* Event Monitor/Recorder Status register
**********************************************************************/
#define RTC_ER_STATUS_EV0_BIT				(0)
#define RTC_ER_STATUS_EV1_BIT				(1)
#define RTC_ER_STATUS_EV2_BIT				(2)
#define RTC_ER_STATUS_GPCLEARED_BIT			(3)
#define RTC_ER_STATUS_WAKEUP_BIT			(31)

#define RTC_ER_EVENTS_ON_EV0_FLG            (1<<RTC_ER_STATUS_EV0_BIT)
#define RTC_ER_EVENTS_ON_EV1_FLG            (1<<RTC_ER_STATUS_EV1_BIT)
#define RTC_ER_EVENTS_ON_EV2_FLG            (1<<RTC_ER_STATUS_EV2_BIT)
#define RTC_ER_STATUS_GP_CLEARED_FLG        (1<<RTC_ER_STATUS_GPCLEARED_BIT)
#define RTC_ER_STATUS_WAKEUP_REQ_PENDING    (((uint32_t)1)<<RTC_ER_STATUS_WAKEUP_BIT)
/**********************************************************************
* Event Monitor/Recorder Counter register
**********************************************************************/
#define RTC_ER_EV0_COUNTER(n)				(n&0x07)
#define RTC_ER_EV1_COUNTER(n)				((n>>8)&0x07)
#define RTC_ER_EV2_COUNTER(n)				((n>>16)&0x07)

/**********************************************************************
* Event Monitor/Recorder TimeStamp register
**********************************************************************/
#define RTC_ER_TIMESTAMP_SEC(n)				(n&0x3F)
#define RTC_ER_TIMESTAMP_MIN(n)				((n>>6)&0x3F)
#define RTC_ER_TIMESTAMP_HOUR(n)			((n>>12)&0x1F)
#define RTC_ER_TIMESTAMP_DOY(n)				((n>>17)&0x1FF) 

/** @brief Time structure definitions for easy manipulate the data */
typedef struct 
{
	/** Hos Register */
	uint32_t HOS;	
	/** Seconds Register */
	uint32_t SEC;
	/** Minutes Register */
	uint32_t MIN;
	/** Hours Register */
	uint32_t HOUR;
	/** Date Register */
	uint32_t DATE;
	/** WEEKDAY Register */
	uint32_t WEEKDAY;
	/** Months Register */
	uint32_t MONTH;
	/** Years Register */
	uint32_t YEAR;
	/** CENTURY Register */
	uint32_t CENTURY;	
} RTC_TIME_Type;
 /** @brief RTC timedate type option */
typedef enum 
{
	/** Month */
	RTC_TIMEDATETYPE_CAL = 0,
	/** Year */
	RTC_TIMEDATETYPE_TIM = 1,
} RTC_TIMEDATETYPE_Num;
 /** @brief RTC time type option */
typedef enum 
{
	/** Second */
	RTC_TIMETYPE_SECOND = 0,
	/** Month */
	RTC_TIMETYPE_MINUTE = 1,
	/** Hour */
	RTC_TIMETYPE_HOUR = 2,
	/** DATE */
	RTC_TIMETYPE_DATE= 3,
	/** Month */
	RTC_TIMETYPE_MONTH = 6,
	/** HOS */
	RTC_TIMETYPE_HOS = 7,
	/** WEEKDAY */
	RTC_TIMETYPE_WEEKDAY = 8,	
	/** YEAR */
	RTC_TIMETYPE_YEAR = 9,	
	/** CENTURY */
	RTC_TIMETYPE_CENTURY= 10,		
} RTC_TIMETYPE_Num;

/** @brief Hour Mode Type */
typedef enum 
{
	/** 12 Hour Mode */
	RTC_HOURMODE_12 = 1,
	/** 24 Hour Mode */
	RTC_HOURMODE_24 = 0
} RTC_HOURMODE_Type;


/** @brief Event Monitor/Recording Input Channel configuration */
typedef struct
{
 	Bool	EventOnPosEdge;	// Event occurs on positive edge on the channel
	Bool	IntWake;		// Create interrupt and wake-up request if there is an event
	Bool	GPClear;		// Clear GP registers of RTC if there is an event.
} RTC_ER_CHANNEL_Init_Type;

/** @brief Event Monitor/Recording configuration */
typedef struct
{
	RTC_ER_CHANNEL_Init_Type InputChannel[RTC_ER_INPUT_CHANNEL_NUM];
	uint32_t				 Clk;	// Sample clock on input channel. (Hz)
} RTC_ER_CONFIG_Type;

/** @brief Event Monitor/Recording TimeStamp Type */
typedef struct 
{
	/** Seconds Register */
	uint32_t SEC;
	/** Minutes Register */
	uint32_t MIN;
	/** Hours Register */
	uint32_t HOUR;
	/** Day of Year Register */
	uint32_t DOY;
} RTC_ER_TIMESTAMP_Type;



/**
 * @}
 */


/* Public Functions ----------------------------------------------------------- */
/** @defgroup RTC_Public_Functions Systick Public Functions
 * @{
 */
void RTC_Init (HM_RTC_TypeDef *RTCx);
void RTC_DeInit(HM_RTC_TypeDef *RTCx);
void RTC_HourModeConfig (HM_RTC_TypeDef *RTCx,uint32_t HourModeType );
void RTC_CntIncrConfig (HM_RTC_TypeDef *RTCx, uint32_t CntIncrType, \
								FunctionalState NewState);
void RTC_AlarmConfig (HM_RTC_TypeDef *RTCx, uint32_t AlarmTimeType, \
								FunctionalState NewState);
void RTC_SetTime (HM_RTC_TypeDef *RTCx, uint32_t Timetype, uint32_t TimeValue);
uint32_t RTC_GetTime(HM_RTC_TypeDef *RTCx, uint32_t Timetype);
void RTC_SetFullTime (HM_RTC_TypeDef *RTCx, RTC_TIME_Type *pFullTime);
void RTC_GetFullTime (HM_RTC_TypeDef *RTCx, RTC_TIME_Type *pFullTime);
void RTC_SetAlarmTime (HM_RTC_TypeDef *RTCx, uint32_t Timetype, uint32_t ALValue);
uint32_t RTC_GetAlarmTime (HM_RTC_TypeDef *RTCx, uint32_t Timetype);
void RTC_SetFullAlarmTime (HM_RTC_TypeDef *RTCx, RTC_TIME_Type *pFullTime);
void RTC_GetFullAlarmTime (HM_RTC_TypeDef *RTCx, RTC_TIME_Type *pFullTime);
IntStatus RTC_GetIntPending (HM_RTC_TypeDef *RTCx, uint32_t IntType);
void RTC_ClearIntPending (HM_RTC_TypeDef *RTCx, uint32_t IntType);
void RTC_SetInterrupMask (HM_RTC_TypeDef *RTCx, uint32_t IntType,FunctionalState NewState);

void 	RTC_ER_InitConfigStruct(RTC_ER_CONFIG_Type* pConfig);
Status 	RTC_ER_Init(RTC_ER_CONFIG_Type* pConfig);
Status 	RTC_ER_Cmd(uint8_t channel, FunctionalState state);
uint8_t RTC_ER_GetEventCount(uint8_t channel);
uint32_t RTC_ER_GetStatus(void);
Bool 	RTC_ER_WakupReqPending(void);
Bool 	RTC_ER_GPCleared(void);
Status 	RTC_ER_GetFirstTimeStamp(uint8_t channel, RTC_ER_TIMESTAMP_Type* pTimeStamp);
Status 	RTC_ER_GetLastTimeStamp(uint8_t channel, RTC_ER_TIMESTAMP_Type* pTimeStamp);
void	RTC_ER_ClearStatus(uint32_t status);

/**
 * @}
 */


#ifdef __cplusplus
}
#endif


#endif /* __HM_RTC_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
