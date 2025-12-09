/**********************************************************************
* $Id$		hm_wwdt.h			2021-09-28
*//**
* @file		hm_wwdt.h
* @brief	Contains all functions support for Wachtdog Timer
*			firmware library on HM3C1788,HM4C123,HM3S9B96
* @version	0.01
* @date		28. Sept. 2021
* @author	PML MCU SW Application Team
* 
* Copyright(C) 2024, Purple Moutain Laboratories
* All rights reserved.
*
***********************************************************************
*
**********************************************************************/


/* Peripheral group ----------------------------------------------------------- */
/** @defgroup WDT	WDT (Windowed Watchdog Timer)
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_WDT_H_
#define __HM_WDT_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup WDT_Private_Macros WDT Private Macros
 * @{
 */

//*****************************************************************************
//
// The following are defines for the Watchdog Timer register offsets.
//
//*****************************************************************************
#define WDT_O_LOAD              0x00000000  // Watchdog Load
#define WDT_O_VALUE             0x00000004  // Watchdog Value
#define WDT_O_CTL               0x00000008  // Watchdog Control
#define WDT_O_ICR               0x0000000C  // Watchdog Interrupt Clear
#define WDT_O_RIS               0x00000010  // Watchdog Raw Interrupt Status
#define WDT_O_MIS               0x00000014  // Watchdog Masked Interrupt Status
#define WDT_O_TEST              0x00000418  // Watchdog Test
#define WDT_O_LOCK              0x00000C00  // Watchdog Lock

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_LOAD register.
//
//*****************************************************************************
#define WDT_LOAD_M              0xFFFFFFFF  // Watchdog Load Value
#define WDT_LOAD_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_VALUE register.
//
//*****************************************************************************
#define WDT_VALUE_M             0xFFFFFFFF  // Watchdog Value
#define WDT_VALUE_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_CTL register.
//
//*****************************************************************************
#define WDT_CTL_WRC             0x80000000  // Write Complete
#define WDT_CTL_INTTYPE         0x00000004  // Watchdog Interrupt Type
#define WDT_CTL_RESEN           0x00000002  // Watchdog Reset Enable
#define WDT_CTL_INTEN           0x00000001  // Watchdog Interrupt Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_ICR register.
//
//*****************************************************************************
#define WDT_ICR_M               0xFFFFFFFF  // Watchdog Interrupt Clear
#define WDT_ICR_S               0

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_RIS register.
//
//*****************************************************************************
#define WDT_RIS_WDTRIS          0x00000001  // Watchdog Raw Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_MIS register.
//
//*****************************************************************************
#define WDT_MIS_WDTMIS          0x00000001  // Watchdog Masked Interrupt Status

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_TEST register.
//
//*****************************************************************************
#define WDT_TEST_STALL          0x00000100  // Watchdog Stall Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the WDT_O_LOCK register.
//
//*****************************************************************************
#define WDT_LOCK_M              0xFFFFFFFF  // Watchdog Lock
#define WDT_LOCK_UNLOCKED       0x00000000  // Unlocked
#define WDT_LOCK_LOCKED         0x00000001  // Locked
#define WDT_LOCK_UNLOCK         0x1ACCE551  // Unlocks the watchdog timer

/**
 * @}
 */

/** @defgroup WDT_Public_Types WDT Public Types
 * @{
 */

/**
 * @brief The field to configurate the WatchDog Timer
 */

/**
 * @}
 */


/* Public Functions ----------------------------------------------------------- */
/** @defgroup WDT_Public_Functions WDT Public Functions
 * @{
 */
extern Bool WatchdogRunning(HM_WDT_TypeDef *WDTx);
extern void WatchdogEnable(HM_WDT_TypeDef *WDTx);
extern void WatchdogResetEnable(HM_WDT_TypeDef *WDTx);
extern void WatchdogResetDisable(HM_WDT_TypeDef *WDTx);
extern void WatchdogLock(HM_WDT_TypeDef *WDTx);
extern void WatchdogUnlock(HM_WDT_TypeDef *WDTx);
extern Bool WatchdogLockState(HM_WDT_TypeDef *WDTx);
extern void WatchdogReloadSet(HM_WDT_TypeDef *WDTx, uint32_t ui32LoadVal);
extern uint32_t WatchdogReloadGet(HM_WDT_TypeDef *WDTx);
extern uint32_t WatchdogValueGet(HM_WDT_TypeDef *WDTx);
extern void WatchdogIntEnable(HM_WDT_TypeDef *WDTx);
extern uint32_t WatchdogIntStatus(HM_WDT_TypeDef *WDTx, Bool bMasked);
extern void WatchdogIntClear(HM_WDT_TypeDef *WDTx);
extern void WatchdogIntTypeSet(HM_WDT_TypeDef *WDTx, uint32_t ui32Type);
extern void WatchdogStallEnable(HM_WDT_TypeDef *WDTx);
extern void WatchdogStallDisable(HM_WDT_TypeDef *WDTx);


/**
 * @}
 */


#ifdef __cplusplus
}
#endif

#endif /* __HM_WDT_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
