#ifndef __HM_UART_H
#define __HM_UART_H
#include "hm_libcfg_default.h"
#include "hm_types.h"
/*define*/

/*define*/
#define UART_CTRL_MASK					(0x000001ff)
#define UART_MODE_MASK					(0x00003fff)
#define UART_IER_MASK					(0x00003fff)
#define UART_IDR_MASK					(0x000001ff)
#define UART_IMR_MASK					(0x000001ff)
#define UART_CISR_MASK					(0x000001ff)
#define UART_BRGR_MASK					(0x0000ffff)
#define UART_RTOR_MASK					(0x000000ff)
#define UART_RTR_MASK					(0x0000001f)
#define UART_MCR_MASK					(0x00000023)
#define UART_MSR_MASK					(0x000000ff)

#define UART_CSR_MASK					(0x0000ffff)
#define UART_CSR_TNFUL_MASK				(1<14)
#define UART_CSR_REMPTY_MASK			(0x00000002)
#define UART_CSR_TEMPTY_MASK			(0x00000008)
#define UART_CSR_TFUL_MASK				(1<<4)

#define UART_FIFO_MASK					(0xffffffff)
#define UART_BDIVR_MASK					(0x000000ff)
#define UART_FCDR_MASK					(0x0000001f)
#define UART_RPWR_MASK					(0x0000ffff)
#define UART_TPWR_MASK					(0x000000ff)
#define UART_TTR_MASK					(0x0000001f)
#define UART_RBSR_MASK					(0x000007ff)

#define UART_INT_RBRK_MASK				(1<<13)
#define UART_INT_TOVR_MASK				(1<<12)
#define UART_INT_TNFUL_MASK				(1<<11)
#define UART_INT_TTRIG_MASK				(1<<10)
#define UART_INT_DMSI_MASK				(1<<9)
#define UART_INT_TIMEOUT_MASK			(1<<8)
#define UART_INT_PARE_MASK				(1<<7)
#define UART_INT_FRAME_MASK				(1<<6)
#define UART_INT_ROVR_MASK				(1<<5)
#define UART_INT_TFUL_MASK				(1<<4)
#define UART_INT_TEMPTY_MASK			(1<<3)
#define UART_INT_RFUL_MASK				(1<<2)
#define UART_INT_REMPTY_MASK			(1<<1)
#define UART_INT_RTRIG_MASK				(1<<0)



#define UART_TRANSMIT_ENABLE			1
#define UART_TRANSMIT_DISABLE			0

#define UART_RECEIVE_ENABLE				1
#define UART_RECEIVE_DISABLE			0

#define UART_BAUD_4800					(4800)
#define UART_BAUD_9600					(9600)
#define UART_BAUD_14400					(14400)
#define UART_BAUD_28800					(28800)
#define UART_BAUD_19200					(19200)
#define UART_BAUD_38400					(38400)
#define UART_BAUD_57600					(57600)
#define UART_BAUD_115200				(115200)
#define UART_BAUD_128000				(128000)
#define UART_BAUD_230400				(230400)
#define UART_BAUD_256000				(256000)
#define UART_BAUD_460800				(460800)
#define UART_BAUD_5000000				(5000000)

#define UART_WORD_6BIT					(3)
#define UART_WORD_7BIT					(2)
#define UART_WORD_8BIT					(1)//or (0)

#define UART_STOP_1BIT					(0)
#define UART_STOP_1_5BIT				(1)
#define UART_STOP_2BIT					(2)
#define UART_STOP_RES_BIT				(3)

#define UART_PARITY_EVEN				(0)
#define UART_PARITY_ODD					(1)
#define UART_PARITY_SPACE				(2)
#define UART_PARITY_MARK				(3)
#define UART_PARITY_NONE				(4)//or(5)(6)(7)

#define UART_FIFO_LEGACY_MODE			(0)
#define UART_FIFO_1BYTE_MODE			(1)
#define UART_FIFO_2BYTE_MODE			(2)
#define UART_FIFO_4BYTE_MODE			(3)

#define UART_DEFAULT_MODE				(0)
#define UART_IRDA_MODE					(1)

#define UART_NORMAL_CHANNEL				(0)
#define UART_ECHO_CHANNEL				(1)
#define UART_LOCAL_LOOPBACK_CHANNEL		(2)
#define UART_REMOTE_LOOPBACK_CHANNEL	(3)

#define UART_SEL_APB_CLOCK				(0)
#define UART_SEL_USER_CLOCK				(1)

#define UART_CLOCK_PRESCALAR_DIS		(0)
#define UART_CLOCK_PRESCALAR_EN			(1)


/** UART Parity Disable */
#define UART_MODE_PARITY_BITMASK	((uint8_t)(7<<3))
/** UART Parity Disable */
#define UART_MODE_PARITY_DIS		((uint8_t)(4<<3))
/** UART Odd Parity Select */
#define UART_MODE_PARITY_ODD		((uint8_t)(1<<3))
/** UART Even Parity Select */
#define UART_MODE_PARITY_EVEN	((uint8_t)(0<<3))
/** UART force 1 stick parity */
#define UART_MODE_PARITY_F_1		((uint8_t)(3<<3))
/** UART force 0 stick parity */
#define UART_MODE_PARITY_F_0		((uint8_t)(2<<3))
/** UART line control bit mask */
#define UART_MODE_BITMASK		((uint8_t)(0x3FFF))


/*********************************************************************//**
 * Macro defines for Macro defines for UART RS485 Control register
 **********************************************************************/
/** RS-485/EIA-485 Normal Multi-drop Mode (NMM) is disabled */
#define UART_RS485CTRL_NMM_EN		((uint32_t)(1<<0))
/** The receiver is disabled */
#define UART_RS485CTRL_RX_DIS		((uint32_t)(1<<1))
/** Auto Address Detect (AAD) is enabled */
#define UART_RS485CTRL_AADEN		((uint32_t)(1<<2))
/** If direction control is enabled (bit DCTRL = 1), pin DTR is used for direction control */
#define UART_RS485CTRL_SEL_DTR		((uint32_t)(1<<3))
/** Enable Auto Direction Control */
#define UART_RS485CTRL_DCTRL_EN	((uint32_t)(1<<4))
/** This bit reverses the polarity of the direction control signal on the RTS (or DTR) pin. 
The direction control pin will be driven to logic "1" when the transmitter has data to be sent */
#define UART_RS485CTRL_OINV_1		((uint32_t)(1<<5))

/** RS485 control bit-mask value */
#define UART_RS485CTRL_BITMASK		((uint32_t)(0x3F))

/*********************************************************************//**
 * Macro defines for Macro defines for UART RS-485 Address Match register
 **********************************************************************/
#define UART_RS485ADRMATCH_BITMASK ((uint8_t)(0xFF)) 	/**< Bit mask value */

/*********************************************************************//**
 * Macro defines for Macro defines for UART1 RS-485 Delay value register
 **********************************************************************/
/* Macro defines for UART1 RS-485 Delay value register */
#define UART_RS485DLY_BITMASK		((uint8_t)(0xFF)) 	/** Bit mask value */



/*data struct*/
typedef struct {
	unsigned int Baudrate;
	unsigned char Word;
	unsigned char Stop;
	unsigned char Parity;
	unsigned char TransmitEnable;
	unsigned char ReceiveEnable;
	unsigned char FifoAccess;
	unsigned char IrdaMode;
	unsigned char ChannelMode;
	unsigned char ClockSelect;
	unsigned char ClockPrescalar8;
}UART_InitTypeDef;

/**
 * @brief UART Direction Control Pin type definition
 */
typedef enum {
	UART_RS485_DIRCTRL_RTS = 0,	/**< Pin RTS is used for direction control */
	UART_RS485_DIRCTRL_DTR			/**< Pin DTR is used for direction control */
} UART_RS485_DIRCTRL_PIN_Type;
	

/********************************************************************//**
* @brief UART-  RS485 Control configuration type
**********************************************************************/
typedef struct {
	FunctionalState NormalMultiDropMode_State; /*!< Normal MultiDrop mode State:
													- ENABLE: Enable this function.
													- DISABLE: Disable this function. */
	FunctionalState Rx_State;					/*!< Receiver State:
													- ENABLE: Enable Receiver.
													- DISABLE: Disable Receiver. */
	FunctionalState AutoAddrDetect_State;		/*!< Auto Address Detect mode state:
												- ENABLE: ENABLE this function.
												- DISABLE: Disable this function. */
	FunctionalState AutoDirCtrl_State;			/*!< Auto Direction Control State:
												- ENABLE: Enable this function.
												- DISABLE: Disable this function. */
	UART_RS485_DIRCTRL_PIN_Type DirCtrlPin;		/*!< If direction control is enabled, state:
												- UART1_RS485_DIRCTRL_RTS:
												pin RTS is used for direction control.
												- UART1_RS485_DIRCTRL_DTR:
												pin DTR is used for direction control. */
	 SetState DirCtrlPol_Level;					/*!< Polarity of the direction control signal on
												the RTS (or DTR) pin:
												- RESET: The direction control pin will be driven
												to logic "0" when the transmitter has data to be sent.
												- SET: The direction control pin will be driven
												to logic "1" when the transmitter has data to be sent. */
	uint8_t MatchAddrValue;					/*!< address match value for RS-485/EIA-485 mode, 8-bit long */
	uint8_t DelayValue;						/*!< delay time is in periods of the baud clock, 8-bit long */
} UART1_RS485_CTRLCFG_Type;


/*function api*/

void UART_Init(HM_UART_TypeDef *uartx ,UART_InitTypeDef *uart_init, const unsigned pll_type);
void UART_ConfigBaud(HM_UART_TypeDef *uartx,uint8_t bdiv,	uint8_t	cd);
void UART_PollPutChar(HM_UART_TypeDef *uartx,int c);
void UART_BlockPutChar(HM_UART_TypeDef *uartx,int c);
void UART_BlockPutChars(HM_UART_TypeDef *uartx,unsigned char *data,unsigned int size);

void UART_PollFifoPutChar(HM_UART_TypeDef *uartx,int c);
int UART_PollGetChar(HM_UART_TypeDef *uartx);
int UART_BlockGetChar(HM_UART_TypeDef *uartx);
void UART_WriteByte(HM_UART_TypeDef *uartx,unsigned char data);
void UART_Write(HM_UART_TypeDef *uartx,unsigned char *data,unsigned int size);
void UART_WriteBytes(HM_UART_TypeDef *uartx,unsigned char *data,unsigned int size);

//int
void UART_EnableInt(HM_UART_TypeDef *uartx, unsigned int pics);
void UART_DisenableInt(HM_UART_TypeDef *uartx, unsigned int pics);
unsigned char UART_GetIntState(HM_UART_TypeDef *uartx, unsigned int pic);
unsigned char UART_GetIntMask(HM_UART_TypeDef *uartx, unsigned int pic);
void UART_RfifoTrigger(HM_UART_TypeDef *uartx,int num);
void UART_TfifoTrigger(HM_UART_TypeDef *uartx,int num);
void UART_SetDmaMode(HM_UART_TypeDef *uartx,FunctionalState NewState);

/* UART RS485 functions ----------------------------------------------------------*/
void UART_RS485Config(HM_UART_TypeDef *uartx,UART1_RS485_CTRLCFG_Type *RS485ConfigStruct);
void UART_RS485ReceiverCmd(HM_UART_TypeDef *uartx, FunctionalState NewState);
void UART_RS485SendSlvAddr(HM_UART_TypeDef *uartx, uint8_t SlvAddr);
void UART_RS485SendData(HM_UART_TypeDef *uartx, uint8_t *pData, uint32_t size);


#endif

