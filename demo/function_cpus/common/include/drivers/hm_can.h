/**********************************************************************
* $Id$		hm_can.h			2021-11-13
*//**
* @file		hm_can.h
* @brief	Contains all functions support for CAN firmware library
*			on HM3C1788,HM4C123,HM3S9B96
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
/** @defgroup CAN
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_CAN_H_
#define __HM_CAN_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif


/* Public Types --------------------------------------------------------------- */
/** @defgroup CAN_Public_Macros CAN Public Macros
 * @{
 */



/**
 * @}
 */


/* Private Macros ------------------------------------------------------------- */
/** @defgroup CAN_Private_Macros CAN Private Macros
 * @{
 */
/*********************************************************************//**
 * Macro defines for CAN Mode Register
 **********************************************************************/

/** CAN Reset mode */
#define CAN_CONTROL_RESET			((uint32_t)(1<<7))

/** CAN Loop Back Mode, External */
#define CAN_CONTROL_LBME			((uint32_t)(1<<6))

/** CAN Loop Back Mode, External */
#define CAN_CONTROL_LBMI			((uint32_t)(1<<5))

/** Transmission Secondary STATus bits   */
#define CAN_CONTROL_CFG_POS			(0)
#define CAN_CONTROL_CFG_MASK		((uint32_t)(0xFF<<CAN_CONTROL_CFG_POS))

/** Transmit Buffer Select */
#define CAN_CONTROL_TBSEL			((uint32_t)(1<<15))

/** Listen Only Mode  */
#define CAN_CONTROL_LOM				((uint32_t)(1<<14))

/** Transceiver Standby Mode  */
#define CAN_CONTROL_STBY			((uint32_t)(1<<13))

/** Transmit Primary Enable  */
#define CAN_CONTROL_TPE				((uint32_t)(1<<12))

/** Transmit Primary Abort   */
#define CAN_CONTROL_TPA				((uint32_t)(1<<11))

/** Transmit Secondary ONE frame   */
#define CAN_CONTROL_TSONE			((uint32_t)(1<<10))

/** Transmit Secondary ALL frames   */
#define CAN_CONTROL_TSALL			((uint32_t)(1<<9))

/** Transmit Secondary Abort   */
#define CAN_CONTROL_TSA				((uint32_t)(1<<8))

/** CAN FD ISO mode   */
#define CAN_CONTROL_FD_ISO			((uint32_t)(1<<23))

/** Transmit buffer Secondary NEXT   */
#define CAN_CONTROL_TSNEXT			((uint32_t)(1<<22))

/** Transmit buffer Secondary operation MODE    */
#define CAN_CONTROL_TSMODE			((uint32_t)(1<<21))

/** Transmit Buffer Mode   */
#define CAN_CONTROL_TTTBM			((uint32_t)(1<<20))

/** Transmission Secondary STATus bits   */
#define CAN_CONTROL_TSSTAT_EMPTY		(0)
#define CAN_CONTROL_TSSTAT_NEARHALF		(1)
#define CAN_CONTROL_TSSTAT_LESSHALF		(1)
#define CAN_CONTROL_TSSTAT_MOREHALF		(2)
#define CAN_CONTROL_TSSTAT_FULL			(3)

#define CAN_CONTROL_TSSTAT_POS			(16)
#define CAN_CONTROL_TSSTAT_MASK			((uint32_t)(0x03<<CAN_CONTROL_TSSTAT_POS))

/** Self-ACKnowledge  */
#define CAN_CONTROL_SACKSACK			((uint32_t)(1<<31))

/** Receive buffer Overflow Mode  */
#define CAN_CONTROL_ROM					((uint32_t)(1<<30))

/** Receive buffer OVerflow  */
#define CAN_CONTROL_ROV					((uint32_t)(1<<29))

/** Receive buffer RELease  */
#define CAN_CONTROL_RREL				((uint32_t)(1<<28))

/** Receive Buffer stores ALL data frames   */
#define CAN_CONTROL_RBALL				((uint32_t)(1<<27))

/** Receive buffer STATus    */
#define CAN_CONTROL_RSTAT_EMPTY		(0)
#define CAN_CONTROL_RSTAT_LESSAFULL	(1)
#define CAN_CONTROL_RSTAT_AFULL		(2)
#define CAN_CONTROL_RSTAT_FULL			(3)

#define CAN_CONTROL_RSTAT_POS			(24)
#define CAN_CONTROL_RSTAT_MASK			((uint32_t)(0x03<<24))


/*********************************************************************//**
 * Macro defines for CAN Interrupt Register
 **********************************************************************/
/** Receive Interrupt Enable  */
#define CAN_INTERRUPT_RIE				((uint32_t)(1<<7))

/** RB Overrun Interrupt Enable  */
#define CAN_INTERRUPT_ROIE				((uint32_t)(1<<6))

/** RB Full Interrupt Enable  */
#define CAN_INTERRUPT_RFIE				((uint32_t)(1<<5))

/** RB Almost Full Interrupt Enable  */
#define CAN_INTERRUPT_RAFIE				((uint32_t)(1<<4))

/** Transmission Primary Interrupt Enable  */
#define CAN_INTERRUPT_TPIE				((uint32_t)(1<<3))

/**  Transmission Secondary Interrupt Enable  */
#define CAN_INTERRUPT_TSIE				((uint32_t)(1<<2))

/**  Error Interrupt Enable   */
#define CAN_INTERRUPT_EIE				((uint32_t)(1<<1))

/**   Transmit Secondary buffer Full Flag   */
#define CAN_INTERRUPT_TSFF				((uint32_t)(1<<0))

#define CAN_INTERRUPT_EN_MASKBIT		((uint32_t)(0xFF000000))

/**  Abort Interrupt Flag  */
#define CAN_INTERRUPT_AIF				((uint32_t)(1<<8))

#define CAN_INTERRUPT_FLAG_MASKBIT		((uint32_t)(0x00FF0000))


/*********************************************************************//**
 * Macro defines for CAN BitTimingS Register
 **********************************************************************/
/**  Bit TimingS Segment 1   */
#define CAN_BITTIMINGS_SEG1_POS			(0)
#define CAN_BITTIMINGS_SEG1_MASKBIT		((uint32_t)(0x000000FF))

/**  Bit TimingS Segment 2   */
#define CAN_BITTIMINGS_SEG2_POS			(8)
#define CAN_BITTIMINGS_SEG2_MASKBIT		((uint32_t)(0x0000FF00))

/**  Bit TimingS SJW   */
#define CAN_BITTIMINGS_SJW_POS			(16)
#define CAN_BITTIMINGS_SJW_MASKBIT		((uint32_t)(0x00FF0000))

/**  Bit TimingS Prescale   */
#define CAN_BITTIMINGS_PRESCALE_POS		(24)
#define CAN_BITTIMINGS_PRESCALE_MASKBIT	((uint32_t)(0xFF000000))

/*********************************************************************//**
 * Macro defines for CAN BitTimingF Register
 **********************************************************************/
/**  Bit TimingF Segment 1   */
#define CAN_BITTIMINGF_SEG1_POS			(0)
#define CAN_BITTIMINGF_SEG1_MASKBIT		((uint32_t)(0x000000FF))

/**  Bit TimingF Segment 2   */
#define CAN_BITTIMINGF_SEG2_POS			(8)
#define CAN_BITTIMINGF_SEG2_MASKBIT		((uint32_t)(0x0000FF00))

/**  Bit TimingF SJW   */
#define CAN_BITTIMINGF_SJW_POS			(16)
#define CAN_BITTIMINGF_SJW_MASKBIT		((uint32_t)(0x00FF0000))

/**  Bit TimingF Prescale   */
#define CAN_BITTIMINGF_PRESCALE_POS		(24)
#define CAN_BITTIMINGF_PRESCALE_MASKBIT	((uint32_t)(0xFF000000))




/**
 * @}
 */


/* Public Types --------------------------------------------------------------- */
/** @defgroup CAN_Public_Types CAN Public Types
 * @{
 */


/***********************************************************************
 * CAN device configuration commands (IOCTL commands and arguments)
 **********************************************************************/
/** CAN peripheral ID 0 */
#define CAN_0		0

/** CAN peripheral ID 1 */
#define CAN_1		1

/**
 * @brief CAN peripheral ID no
 */
typedef enum
{
	CAN_ID_0 = CAN_0,
	CAN_ID_1 = CAN_1
} en_CAN_unitId;

/**
 * @brief CAN ID format definition
 */
typedef enum 
{
	STD_ID_FORMAT = 0, 	/**< Use standard ID format (11 bit ID) */
	EXT_ID_FORMAT = 1	/**< Use extended ID format (29 bit ID) */
} CAN_ID_FORMAT_Type;

/**
 * @brief CAN Baudrate
 */
typedef enum
{
	CAN_BAUD_0_25M = 1,
	CAN_BAUD_0_5M,
	CAN_BAUD_1M,
	CAN_BAUD_2M,
	CAN_BAUD_4M,
	CAN_BAUD_5M
} CAN_BAUD_Type;

/**
 * @brief AF Entry type definition
 */
typedef enum 
{
	FULLCAN_ENTRY = 0,
	EXPLICIT_STANDARD_ENTRY,
} AF_ENTRY_Type;

/**
 * @brief Symbolic names for type of CAN message
 */
typedef enum 
{
	DATA_FRAME = 0, 	/**< Data frame */
	REMOTE_FRAME = 1	/**< Remote frame */
} CAN_FRAME_Type;

/**
 * @brief CAN Control status definition
 */
typedef enum 
{
	CANCTRL_GLOBAL_STS = 0, /**< CAN Global Status */
	CANCTRL_INT_CAP, 		/**< CAN Interrupt and Capture */
	CANCTRL_ERR_WRN, 		/**< CAN Error Warning Limit */
	CANCTRL_STS				/**< CAN Control Status */
} CAN_CTRL_STS_Type;

/**
 * @brief Central CAN status type definition
 */
typedef enum 
{
	CANCR_TX_STS = 0, 	/**< Central CAN Tx Status */
	CANCR_RX_STS, 		/**< Central CAN Rx Status */
	CANCR_MS			/**< Central CAN Miscellaneous Status */
} CAN_CR_STS_Type;

/**
 * @brief FullCAN Interrupt Capture type definition
 */
typedef enum
{
	FULLCAN_IC0,	/**< FullCAN Interrupt and Capture 0 */
	FULLCAN_IC1	/**< FullCAN Interrupt and Capture 1 */
}FullCAN_IC_Type;

/**
 * @brief CAN interrupt enable type definition
 */
typedef enum 
{
	CANINT_RIE = 0, 	/**< CAN Receiver Interrupt Enable */
	CANINT_TIE1, 		/**< CAN Transmit Interrupt Enable */
	CANINT_EIE, 		/**< CAN Error Warning Interrupt Enable */
	CANINT_DOIE, 		/**< CAN Data Overrun Interrupt Enable */
	CANINT_WUIE, 		/**< CAN Wake-Up Interrupt Enable */
	CANINT_EPIE, 		/**< CAN Error Passive Interrupt Enable */
	CANINT_ALIE, 		/**< CAN Arbitration Lost Interrupt Enable */
	CANINT_BEIE, 		/**< CAN Bus Error Inter rupt Enable */
	CANINT_IDIE, 		/**< CAN ID Ready Interrupt Enable */
	CANINT_TIE2, 		/**< CAN Transmit Interrupt Enable for Buffer2 */
	CANINT_TIE3, 		/**< CAN Transmit Interrupt Enable for Buffer3 */
	CANINT_FCE			/**< FullCAN Interrupt Enable */
} CAN_INT_EN_Type;

/**
 * @brief Acceptance Filter Mode type definition
 */
typedef enum 
{
	CAN_NORMAL = 0, 	/**< Normal Mode */
	CAN_ACC_OFF, 		/**< Acceptance Filter Off Mode */
	CAN_ACC_BP, 			/**< Acceptance Fileter Bypass Mode */
	CAN_EFCAN			/**< FullCAN Mode Enhancement */
} CAN_AFMODE_Type;

/**
 * @brief CAN Mode Type definition
 */
typedef enum 
{
	CAN_OPERATING_MODE = 0, 	/**< Operating Mode */
	CAN_RESET_MODE, 			/**< Reset Mode */
	CAN_LISTENONLY_MODE, 		/**< Listen Only Mode */
	CAN_SELFTEST_MODE, 			/**< Seft Test Mode */
	CAN_TXPRIORITY_MODE, 		/**< Transmit Priority Mode */
	CAN_SLEEP_MODE, 			/**< Sleep Mode */
	CAN_RXPOLARITY_MODE, 		/**< Receive Polarity Mode */
	CAN_TEST_MODE				/**< Test Mode */
} CAN_MODE_Type;

/**
 * @brief Error values that functions can return
 */
typedef enum 
{
	CAN_OK = 1, 				/**< No error */
	CAN_OBJECTS_FULL_ERROR, 	/**< No more rx or tx objects available */
	CAN_FULL_OBJ_NOT_RCV, 		/**< Full CAN object not received */
	CAN_NO_RECEIVE_DATA, 		/**< No have receive data available */
	CAN_AF_ENTRY_ERROR, 		/**< Entry load in AFLUT is unvalid */
	CAN_CONFLICT_ID_ERROR, 		/**< Conflict ID occur */
	CAN_ENTRY_NOT_EXIT_ERROR	/**< Entry remove outo AFLUT is not exit */
} CAN_ERROR;


/**
 * @brief CAN message object structure
 */
typedef struct 
{
	uint32_t id:29; 			/**< 29 bit identifier, it depend on "format" value
								 - if format = STD_ID_FORMAT, id should be 11 bit identifier
								 - if format = EXT_ID_FORMAT, id should be 29 bit identifier
							 */
	uint32_t reserved:2;
	uint32_t esi_tts:1;	
	uint32_t len:4; 			/**< Length of data field in bytes */
	uint32_t ratemode:1;
	uint32_t frame:1;	
	uint32_t type:1; 		/**< Remote Frame transmission, should be:
								 - DATA_FRAME: the number of data bytes called out by the DLC
								 field are send from the CANxTDA and CANxTDB registers
								 - REMOTE_FRAME: Remote Frame is sent
							*/	
	uint32_t format:1; 		
	uint32_t status:8; 		/**< Status */
	uint32_t cycletime:16; 	/**< Cycletime */
	// uint8_t data[16]; 		/**< Data field  */
	uint32_t data[4]; 		/**< Data field  */
	uint32_t cia603[2]; 		/**< Data field  */
		
} CAN_MSG_Type;





/**
 * @}
 */


/* Public Functions ----------------------------------------------------------- */
/** @defgroup CAN_Public_Functions CAN Public Functions
 * @{
 */

/* Init/DeInit CAN peripheral -----------*/
void CAN_Init(uint8_t canId, uint32_t baudrate);
void CAN_DeInit(uint8_t canId);

/* CAN messages functions ---------------*/
Status CAN_SendMsg(uint8_t canId, CAN_MSG_Type *CAN_Msg);
Status CAN_ReceiveMsg(uint8_t canId, CAN_MSG_Type *CAN_Msg);

/* CAN configure functions ---------------*/
 void CAN_ModeConfig(uint8_t canId, CAN_MODE_Type mode,FunctionalState NewState);
void CAN_SetAFMode(CAN_AFMODE_Type AFmode);
void CAN_SetCommand(uint8_t canId, uint32_t CMRType);

/* Acceptance Filter Control functions ---------------------- */
CAN_ERROR CAN_AFConfig(uint8_t canId, uint16_t index,uint32_t ID);
CAN_ERROR CAN_RemoveAF(uint8_t canId,uint32_t ID);

/* CAN interrupt functions -----------------*/
void CAN_IRQCmd(uint8_t canId, CAN_INT_EN_Type arg, FunctionalState NewState);
uint32_t CAN_IntGetStatus(uint8_t canId);

/* CAN get status functions ----------------*/
IntStatus CAN_FullCANIntGetStatus (void);
uint32_t CAN_FullCANPendGetStatus (FullCAN_IC_Type type);
uint32_t CAN_GetCTRLStatus(uint8_t canId, CAN_CTRL_STS_Type arg);
uint32_t CAN_GetCRStatus(uint8_t canId, CAN_CR_STS_Type arg);

/**
 * @}
 */



#ifdef __cplusplus
}
#endif


#endif /* __HM_CAN_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
