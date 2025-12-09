/**********************************************************************
* $Id$		hm_ssp.h			2021-09-29
*//**
* @file		hm_ssp.h
* @brief	Contains all functions support for SSP firmware library
*			on HM3C1788,HM4C123,HM3S9B96
* @version	0.01
* @date		29. Sept. 2021
* @author	PML MCU SW Application Team
* 
* Copyright(C) 2021, PML
* All rights reserved.
*
***********************************************************************
*
**********************************************************************/


/* Peripheral group ----------------------------------------------------------- */
/** @defgroup SSP
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_SSP_H_
#define __HM_SSP_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif

/* Public Macros -------------------------------------------------------------- */
/** @defgroup SSP_Public_Macros SSP Public Macros
 * @{
 */

/*********************************************************************//**
 * SSP configuration parameter defines
 **********************************************************************/
/** Clock phase control bit */
#define IS_MASTER_MODE(instance)	((instance->SSP_M.CTRLR0&SSP_CR0_SLAVE_EN)?DISABLE:ENABLE)

/** Clock phase control bit */
#define SSP_CPHA_FIRST			((uint32_t)(0))
#define SSP_CPHA_SECOND			SSP_CR0_CPHA_SECOND


/** Clock polarity control bit */
/* - If bit[6] in SSPnCR0 is 0: SSP controller maintains the bus clock low between frames.
 * That means the active clock is in HI state.
 * - If bit[6] in SSPnCR0 is 1 (SSP_CR0_CPOL_HI): SSP controller maintains the bus clock
 * high between frames. That means the active clock is in LO state.
 */
#define SSP_CPOL_HI				SSP_CR0_CPOL_HI
#define SSP_CPOL_LO				((uint32_t)(0))

/** SSP master mode enable */
#define SSP_SLAVE_MODE			SSP_CR0_SLAVE_EN
#define SSP_MASTER_MODE			((uint32_t)(0))
#define SSP_MSCTRL_M			((uint32_t)(1))
#define SSP_MSCTRL_S			((uint32_t)(0))

/** SSP data bit number defines */
#define SSP_DATABIT_4		SSP_CR0_DFS(4) 			/*!< Databit number = 4 */
#define SSP_DATABIT_5		SSP_CR0_DFS(5) 			/*!< Databit number = 5 */
#define SSP_DATABIT_6		SSP_CR0_DFS(6) 			/*!< Databit number = 6 */
#define SSP_DATABIT_7		SSP_CR0_DFS(7) 			/*!< Databit number = 7 */
#define SSP_DATABIT_8		SSP_CR0_DFS(8) 			/*!< Databit number = 8 */
#define SSP_DATABIT_9		SSP_CR0_DFS(9) 			/*!< Databit number = 9 */
#define SSP_DATABIT_10		SSP_CR0_DFS(10) 		/*!< Databit number = 10 */
#define SSP_DATABIT_11		SSP_CR0_DFS(11) 		/*!< Databit number = 11 */
#define SSP_DATABIT_12		SSP_CR0_DFS(12) 		/*!< Databit number = 12 */
#define SSP_DATABIT_13		SSP_CR0_DFS(13) 		/*!< Databit number = 13 */
#define SSP_DATABIT_14		SSP_CR0_DFS(14) 		/*!< Databit number = 14 */
#define SSP_DATABIT_15		SSP_CR0_DFS(15) 		/*!< Databit number = 15 */
#define SSP_DATABIT_16		SSP_CR0_DFS(16) 		/*!< Databit number = 16 */
/** SSP data bit number defines 32bit */
#define SSP_DATABIT32_4		SSP_CR0_DFS32(4) 			/*!< Databit number = 4 */
#define SSP_DATABIT32_5		SSP_CR0_DFS32(5) 			/*!< Databit number = 5 */
#define SSP_DATABIT32_6		SSP_CR0_DFS32(6) 			/*!< Databit number = 6 */
#define SSP_DATABIT32_7		SSP_CR0_DFS32(7) 			/*!< Databit number = 7 */
#define SSP_DATABIT32_8		SSP_CR0_DFS32(8) 			/*!< Databit number = 8 */
#define SSP_DATABIT32_9		SSP_CR0_DFS32(9) 			/*!< Databit number = 9 */
#define SSP_DATABIT32_10	SSP_CR0_DFS32(10) 		/*!< Databit number = 10 */
#define SSP_DATABIT32_11	SSP_CR0_DFS32(11) 		/*!< Databit number = 11 */
#define SSP_DATABIT32_12	SSP_CR0_DFS32(12) 		/*!< Databit number = 12 */
#define SSP_DATABIT32_13	SSP_CR0_DFS32(13) 		/*!< Databit number = 13 */
#define SSP_DATABIT32_14	SSP_CR0_DFS32(14) 		/*!< Databit number = 14 */
#define SSP_DATABIT32_15	SSP_CR0_DFS32(15) 		/*!< Databit number = 15 */
#define SSP_DATABIT32_16	SSP_CR0_DFS32(16) 		/*!< Databit number = 16 */
#define SSP_DATABIT32_32	SSP_CR0_DFS32(32) 		/*!< Databit number = 32 */

/** SSP Frame Format definition */
/** Motorola SPI mode */
#define SSP_FRAME_SPI		SSP_CR0_FRF_SPI
/** TI synchronous serial mode */
#define SSP_FRAME_TI		SSP_CR0_FRF_TI
/** National Micro-wire mode */
#define SSP_FRAME_MICROWIRE	SSP_CR0_FRF_MICROWIRE

/** SSP SPI Frame Format,Standard SPI Frame Format */
#define SSP_TRANSFER_MODE_STD			SSP_CR0_FRF_STD
/** SSP SPI Frame Format,Dual SPI Frame Format */
#define SSP_TRANSFER_MODE_DUAL   		SSP_CR0_FRF_DUAL
/** SSP SPI Frame Format,Quad SPI Frame Format */
#define SSP_TRANSFER_MODE_QUAD  		SSP_CR0_FRF_QUAD
/** SSP SPI Frame Format,Octal SPI Frame Format */
#define SSP_TRANSFER_MODE_OCTAL  		SSP_CR0_FRF_OCTAL



/*********************************************************************//**
 * SSP Status defines
 **********************************************************************/
/** SSP status TX FIFO Empty bit */
#define SSP_STAT_TXFIFO_EMPTY		SSP_SR_TFE
/** SSP status TX FIFO not full bit */
#define SSP_STAT_TXFIFO_NOTFULL		SSP_SR_TFNF
/** SSP status RX FIFO not empty bit */
#define SSP_STAT_RXFIFO_NOTEMPTY	SSP_SR_RFNE
/** SSP status RX FIFO full bit */
#define SSP_STAT_RXFIFO_FULL		SSP_SR_RFF
/** SSP status SSP Busy bit */
#define SSP_STAT_BUSY				SSP_SR_BSY

/*********************************************************************//**
 * SSP Interrupt Configuration defines
 **********************************************************************/
/** Receive FIFO Full */
#define SSP_INTCFG_MSTIM		SSP_IMR_MSTIM
/** Receive FIFO Full */
#define SSP_INTCFG_RXFIM		SSP_IMR_RXFIM
/** Receive FIFO Overflow  */
#define SSP_INTCFG_RXOIM		SSP_IMR_RXOIM
/** Receive FIFO Underflow */
#define SSP_INTCFG_RXUIM		SSP_IMR_RXUIM
/** Transmit FIFO Overflow  */
#define SSP_INTCFG_TXOIM		SSP_IMR_TXOIM
/** Transmit FIFO Empty  */
#define SSP_INTCFG_TXEIM		SSP_IMR_TXEIM


/*********************************************************************//**
 * SSP Configured Interrupt Status defines
 **********************************************************************/
/** Transmit FIFO Empty */
#define SSP_INTSTAT_TXEIS		SSP_ISR_TXEIS
/** Transmit FIFO Overflow */
#define SSP_INTSTAT_TXOIS		SSP_ISR_TXOIS
/** Receive FIFO Underflow */
#define SSP_INTSTAT_RXUIS		SSP_ISR_RXUIS
/** Receive FIFO Overflow */
#define SSP_INTSTAT_RXFIS		SSP_ISR_RXFIS
/** Multi-Master Contention */
#define SSP_INTSTAT_MSTIS		SSP_ISR_MSTIS


/*********************************************************************//**
 * SSP Raw Interrupt Status defines
 **********************************************************************/
/** Transmit FIFO Empty */
#define SSP_INTSTAT_RAW_TXEIR		SSP_RISR_TXEIR
/** Transmit FIFO Overflow */
#define SSP_INTSTAT_RAW_TXOIR		SSP_RISR_TXOIR
/** Receive FIFO Underflow */
#define SSP_INTSTAT_RAW_RXUIR		SSP_RISR_RXUIR
/** Receive FIFO Overflow */
#define SSP_INTSTAT_RAW_RXOIR		SSP_RISR_RXOIR
/** Receive FIFO Full */
#define SSP_INTSTAT_RAW_RXFIR		SSP_RISR_RXFIR
/** Multi-Master Contention */
#define SSP_INTSTAT_RAW_MSTIR		SSP_RISR_MSTIR


/*********************************************************************//**
 * SSP Interrupt Clear defines
 **********************************************************************/
/** Writing a 1 to this bit clears  interrupt */
#define SSP_INTCLR_ICR		SSP_ICR_CLR

/*********************************************************************//**
 * SSP DMA defines
 **********************************************************************/
/** SSP bit for enabling RX DMA */
#define SSP_DMA_RX		SSP_DMA_RXDMA_EN
/** SSP bit for enabling TX DMA */
#define SSP_DMA_TX		SSP_DMA_TXDMA_EN

/* SSP Status Implementation definitions */
#define SSP_STAT_DONE		(1UL<<8)		/**< Done */
#define SSP_STAT_ERROR		(1UL<<9)		/**< Error */

/**
 * @}
 */


/* Private Macros ------------------------------------------------------------- */
/** @defgroup SSP_Private_Macros SSP Private Macros
 * @{
 */

/* --------------------- BIT DEFINITIONS -------------------------------------- */
/*********************************************************************//**
 * Macro defines for CR0 register
 **********************************************************************/
/** SSP data size select, must be 4 bits to 16 bits */
#define SSP_CR0_DFS(n)   		((uint32_t)((n-1)&0x0F)<<0)
/** SSP control 0 Motorola SPI mode */
#define SSP_CR0_FRF_SPI  		((uint32_t)(0<<4))
/** SSP control 0 TI synchronous serial mode */
#define SSP_CR0_FRF_TI   		((uint32_t)(1<<4))
/** SSP control 0 National Micro-wire mode */
#define SSP_CR0_FRF_MICROWIRE  	((uint32_t)(2<<4))
/** SPI clock out phase bit (used in SPI mode only), (1) = captures data
   on the second clock transition of the frame, (0) = first */
#define SSP_CR0_CPHA_SECOND		((uint32_t)(1<<6))
/** SPI clock polarity bit (used in SPI mode only), (1) = maintains the
   bus clock high between frames, (0) = low */
#define SSP_CR0_CPOL_HI			((uint32_t)(1<<7))

/** SSP  Transfer Mode,Transmit & Receive */
#define SSP_CR0_TMOD_RT  		((uint32_t)(0<<8))
/** SSP  Transfer Mode,Transmit Only */
#define SSP_CR0_TMOD_TO   		((uint32_t)(1<<8))
/** SSP  Transfer Mode,Receive Only */
#define SSP_CR0_TMOD_RO  		((uint32_t)(2<<8))
/** SSP  Transfer Mode,EEPROM Read */
#define SSP_CR0_TMOD_EEPROM  	((uint32_t)(3<<8))

/** SSP   Slave Output Enable */
#define SSP_CR0_SLAVE_EN		((uint32_t)(1<<10))

/** SSP   Shift Register Loop Enable */
#define SSP_CR0_LOOPBACK_EN		((uint32_t)(1<<11))
/** SSP data size select  for the Microwire frame format.must be 4 bits to 16 bits */
#define SSP_CR0_CFS(n)   		((uint32_t)((n-1)&0x1F)<<12)

/** SSP data size select, must be 5 bits to 32 bits */
#define SSP_CR0_DFS32(n)   		((uint32_t)((n-1)&0x1F)<<16)
#define SSP_CR0_DFS32_BITMASK	((uint32_t)(0x1F)<<16)
/** SSP SPI Frame Format,Standard SPI Frame Format */
#define SSP_CR0_FRF_STD  		((uint32_t)(0<<21))
/** SSP SPI Frame Format,Dual SPI Frame Format */
#define SSP_CR0_FRF_DUAL   		((uint32_t)(1<<21))
/** SSP SPI Frame Format,Quad SPI Frame Format */
#define SSP_CR0_FRF_QUAD  		((uint32_t)(2<<21))
/** SSP SPI Frame Format,Octal SPI Frame Format */
#define SSP_CR0_FRF_OCTAL  		((uint32_t)(3<<21))


/** SSP CR0 bit mask */
#define SSP_CR0_BITMASK			((uint32_t)(0xFFFF))





/*********************************************************************//**
 * Macro defines for CR1 register
 **********************************************************************/
/** Number of Data Frames */
#define SSP_CR1_NDF(n)   		((uint32_t)((n)&0xFFFF))
/** SSP CR1 bit mask */
#define SSP_CR1_BITMASK			((uint32_t)(0xFFFF))


/*********************************************************************//**
 * Macro defines for SSIENR register
 **********************************************************************/

/** SSP control 1 enable bit */
#define SSP_SSIENR_SSP_EN		((uint32_t)(1<<0))

/*********************************************************************//**
 * Macro defines for MWCR register
 **********************************************************************/

/** Microwire Handshaking 1 Handshaking interface is enabled */
#define SSP_MWCR_MHS		((uint32_t)(1<<2))

/** Microwire Control 1 SSI transmits data */
#define SSP_MWCR_MDD		((uint32_t)(1<<1))

/** Microwire Transfer Mode 1 Sequential Microwire Transfer */
#define SSP_MWCR_MWMOD		((uint32_t)(1<<0))

/*********************************************************************//**
 * Macro defines for SER register
 **********************************************************************/

/** Slave Select Enable Flag 1 Slave is selected */
#define SSP_SER_EN		((uint32_t)(1<<0))
#define SSP_SER_DE		((uint32_t)(0<<0))

/*********************************************************************//**
 * Macro defines for BAUDR register
 **********************************************************************/
#define SSP_BAUDR_SCKDV ((uint32_t)(0x4))

/** SSI Clock Divider bit mask  */
#define SSP_BAUDR_BITMASK		((uint32_t)(0xffff))

/*********************************************************************//**
 * Macro defines for TXFTLR register
 **********************************************************************/
#define SSP_TXFTLR_TFT		((uint32_t)(0x7))
/** Transmit FIFO Threshold  */
#define SSP_TXFTLR_BITMASK		((uint32_t)(0x7))

/*********************************************************************//**
 * Macro defines for RXFTLR register
 **********************************************************************/
#define SSP_RXFTLR_RFT		((uint32_t)(0x7))

/** Receive FIFO Threshold  */
#define SSP_RXFTLR_BITMASK		((uint32_t)(0x7))


/*********************************************************************//**
 * Macro defines for TXFLR register
 **********************************************************************/

/** Transmit FIFO Level  */
#define SSP_TXFLR_BITMASK		((uint32_t)(0x7))


/*********************************************************************//**
 * Macro defines for RXFLR register
 **********************************************************************/

/** Transmit FIFO Level  */
#define SSP_RXFLR_BITMASK		((uint32_t)(0x7))


/*********************************************************************//**
 * Macro defines for DR register
 **********************************************************************/
/** SSP data bit mask */
#define SSP_DR_BITMASK(n)   ((n)&0xFFFF)

/*********************************************************************//**
 * Macro defines for SR register
 **********************************************************************/
/** SSP status SSP Busy bit */
#define SSP_SR_BSY      ((uint32_t)(1<<0))
/** SSP status TX FIFO Not Full bit */
#define SSP_SR_TFNF     ((uint32_t)(1<<1))
/** SSP status TX FIFO Empty bit */
#define SSP_SR_TFE      ((uint32_t)(1<<2))
/** SSP status RX FIFO Not empty bit */
#define SSP_SR_RFNE     ((uint32_t)(1<<3))
/** SSP status RX FIFO full bit */
#define SSP_SR_RFF      ((uint32_t)(1<<4))
/** SSP status TX FIFO Error bit */
#define SSP_SR_TXE      ((uint32_t)(1<<5))
/** SSP status Data Collision Error bit */
#define SSP_SR_DCOL     ((uint32_t)(1<<6))


/** SSP SR bit mask */
#define SSP_SR_BITMASK	((uint32_t)(0x2F))


/*********************************************************************//**
 * Macro define for (IMR) Interrupt Mask registers
 **********************************************************************/
/** Receive FIFO Full Interrupt Mask */
#define SSP_IMR_MSTIM		((uint32_t)(1<<5))
/** Receive FIFO Full Interrupt Mask */
#define SSP_IMR_RXFIM		((uint32_t)(1<<4))
/** Receive FIFO Overflow Interrupt Mask */
#define SSP_IMR_RXOIM		((uint32_t)(1<<3))
/** Receive FIFO Underflow Interrupt Mask */
#define SSP_IMR_RXUIM		((uint32_t)(1<<2))
/**  Transmit FIFO Overflow Interrupt Mask */
#define SSP_IMR_TXOIM		((uint32_t)(1<<1))
/**  Transmit FIFO Empty Interrupt Mask */
#define SSP_IMR_TXEIM		((uint32_t)(1<<0))

/** IMR bit mask */
#define SSP_IMR_BITMASK		((uint32_t)(0x3F))

/*********************************************************************//**
 * Macro define for (ISR) Interrupt Status registers
 **********************************************************************/
/** Transmit FIFO Empty Interrupt Status */
#define SSP_ISR_TXEIS		((uint32_t)(1<<0))
/** Transmit FIFO Overflow Interrupt Status */
#define SSP_ISR_TXOIS		((uint32_t)(1<<1))
/** Receive FIFO Underflow Interrupt Status */
#define SSP_ISR_RXUIS		((uint32_t)(1<<2))
/** Receive FIFO Overflow Interrupt Status */
#define SSP_ISR_RXOIS		((uint32_t)(1<<3))
/** Receive FIFO Full Interrupt Status */
#define SSP_ISR_RXFIS		((uint32_t)(1<<4))
/** Multi-Master Contention Interrupt Status */
#define SSP_ISR_MSTIS		((uint32_t)(1<<5))

/** ISR bit mask */
#define SSP_ISR_BITMASK	((uint32_t)(0x3F))


/*********************************************************************//**
 * Macro define for (RISR) Raw Interrupt Status registers
 **********************************************************************/
/** Transmit FIFO Empty Raw Interrupt Status */
#define SSP_RISR_TXEIR		((uint32_t)(1<<0))
/** Transmit FIFO Overflow Raw Interrupt Status */
#define SSP_RISR_TXOIR		((uint32_t)(1<<1))
/** Receive FIFO Underflow Raw Interrupt Status */
#define SSP_RISR_RXUIR		((uint32_t)(1<<2))
/** Receive FIFO Overflow Raw Interrupt Status */
#define SSP_RISR_RXOIR		((uint32_t)(1<<3))
/** Receive FIFO Full Raw Interrupt Status */
#define SSP_RISR_RXFIR		((uint32_t)(1<<4))
/** Multi-Master Contention Raw Interrupt Status */
#define SSP_RISR_MSTIR		((uint32_t)(1<<5))

/** RISR bit mask */
#define SSP_RISR_BITMASK	((uint32_t)(0x3F))

/*********************************************************************//**
 * Macro define for (TXOICR) Transmit FIFO Overflow Interrupt Clear Register 
 **********************************************************************/

/**  Clear Transmit FIFO Overflow Interrupt */
#define SSP_TXOICR_CLR		((uint32_t)(1<<0))

/*********************************************************************//**
 * Macro define for (RXOICR) Receive FIFO Overflow Interrupt Clear Register 
 **********************************************************************/

/**  Clear Receive FIFO Overflow Interrupt */
#define SSP_RXOICR_CLR		((uint32_t)(1<<0))

/*********************************************************************//**
 * Macro define for (RXUICR) Receive FIFO Underflow Interrupt Clear Register 
 **********************************************************************/

/**  Clear Receive FIFO Underflow Interrupt */
#define SSP_RXUICR_CLR		((uint32_t)(1<<0))

/*********************************************************************//**
 * Macro define for (MSTICR) Multi-Master Interrupt Clear Register 
 **********************************************************************/

/**  Clear Multi-Master Contention Interrupt */
#define SSP_MSTICR_CLR		((uint32_t)(1<<0))


/*********************************************************************//**
 * Macro define for (ICR) Interrupt Clear registers
 **********************************************************************/
/** Writing a 1 to this bit clears the interrupt */
#define SSP_ICR_CLR		((uint32_t)(1<<0))


/*********************************************************************//**
 * Macro defines for DMACR register
 **********************************************************************/
/** SSP bit for enabling RX DMA */
#define SSP_DMA_RXDMA_EN  	((uint32_t)(1<<0))
/** SSP bit for enabling TX DMA */
#define SSP_DMA_TXDMA_EN  	((uint32_t)(1<<1))
/** DMACR	bit mask */
#define SSP_DMA_BITMASK		((uint32_t)(0x03))

/*********************************************************************//**
 * Macro defines for DMATDLR register
 **********************************************************************/
/** DMATDLR	bit mask */
#define SSP_DMATDLR_BITMASK		((uint32_t)(0x07))


/*********************************************************************//**
 * Macro defines for SPI_CTRLR0 register
 **********************************************************************/
/** Read data strobe enable bit */
#define SSP_SPI_CTRLR0_RXDS_EN		((uint32_t)(1<<0))
/**  Instruction DDR Enable bit */
#define SSP_SPI_CTRLR0_INST_DDR_EN		((uint32_t)(1<<0))
/**  SPI DDR Enable bit */
#define SSP_SPI_CTRLR0_SPI_DDR_EN		((uint32_t)(1<<0))

/** Wait cycles bit mask */
#define SSP_SPI_CTRLR0_WAIT_CYCLES_BITMASK   (0x1F<<11)
/**  Instruction Length bit mask */
#define SSP_SPI_CTRLR0_INST_L_BITMASK		((uint32_t)(0x3<<8))

/**  Address Length bit mask */
#define SSP_SPI_CTRLR0_ADDR_L_BITMASK		((uint32_t)(0x3<<8))

/**  Address and instruction transfer format */
#define SSP_SPI_CTRLR0_TRANS_TYPE_BITMASK		((uint32_t)(0x3<<0))

/*********************************************************************//**
 * Macro defines for TXD_DRIVE_EDGE register
 **********************************************************************/

/**  TXD Drive edge */
#define SSP_TXD_DRIVE_EDGE_TDE_BITMASK		((uint32_t)(0xFF))



/**
 * @}
 */

/* Public Types --------------------------------------------------------------- */
/** @defgroup SSP_Public_Types SSP Public Types
 * @{
 */

/** @brief SSP configuration structure */
typedef struct {
	uint32_t Databit; 		/** Databit number, should be SSP_DATABIT_x,
							where x is in range from 4 - 16 */
	uint32_t CPHA;			/** Clock phase, should be:
							- SSP_CPHA_FIRST: first clock edge
							- SSP_CPHA_SECOND: second clock edge */
	uint32_t CPOL;			/** Clock polarity, should be:
							- SSP_CPOL_HI: high level
							- SSP_CPOL_LO: low level */
	uint32_t Mode;			/** SSP mode, should be:
							- SSP_MASTER_MODE: Master mode
							- SSP_SLAVE_MODE: Slave mode */
	uint32_t FrameFormat;	/** Frame Format:
							- SSP_FRAME_SPI: Motorola SPI frame format
							- SSP_FRAME_TI: TI frame format
							- SSP_FRAME_MICROWIRE: National Microwire frame format */
	uint32_t ClockRate;		/** Clock rate,in Hz */
	uint32_t TransferMode;
} SSP_CFG_Type;

/**
 * @brief SSP Int Type definitions
 */
typedef enum {
	SSP_INT_TXE = 0, /**< Transmit FIFO Empty Interrupt  */
	SSP_INT_TXO,		/**< Transmit FIFO Overflow Interrupt */
	SSP_INT_RXU,		/**< Receive FIFO Underflow Interrupt  */
	SSP_INT_RXO,		/**< Receive FIFO Overflow Interrupt  */
	SSP_INT_RXF,		/**< Receive FIFO Full Interrupt */
	SSP_INT_MST,		/**< Multi-Master Contention Interrupt */
} SSP_INT_Type;


/**
 * @brief SSP Transfer Type definitions
 */
typedef enum {
	SSP_TRANSFER_POLLING = 0,	/**< Polling transfer */
	SSP_TRANSFER_INTERRUPT		/**< Interrupt transfer */
} SSP_TRANSFER_Type;

/**
 * @brief SPI Data configuration structure definitions
 */
typedef struct {
	void *tx_data;				/**< Pointer to transmit data */
	uint32_t tx_cnt;			/**< Transmit counter */
	void *rx_data;				/**< Pointer to transmit data */
	uint32_t rx_cnt;			/**< Receive counter */
	uint32_t length;			/**< Length of transfer data */
	uint32_t status;			/**< Current status of SSP activity */
} SSP_DATA_SETUP_Type;


/**
 * @}
 */


/* Public Functions ----------------------------------------------------------- */
/** @defgroup SSP_Public_Functions SSP Public Functions
 * @{
 */
	/* SSP Init/DeInit functions --------------------------------------------------*/
	void SSP_Init(HM_SSP_TypeDef *SSPx, SSP_CFG_Type *SSP_ConfigStruct);
	void SSP_DeInit(HM_SSP_TypeDef* SSPx);
	
	/* SSP configure functions ----------------------------------------------------*/
	void SSP_ConfigStructInit(SSP_CFG_Type *SSP_InitStruct);
	
	/* SSP enable/disable functions -----------------------------------------------*/
	void SSP_Cmd(HM_SSP_TypeDef* SSPx, FunctionalState NewState);
	void SSP_LoopBackCmd(HM_SSP_TypeDef* SSPx, FunctionalState NewState);
	void SSP_SlaveOutputCmd(HM_SSP_TypeDef* SSPx, FunctionalState NewState);
	void SSP_DMACmd(HM_SSP_TypeDef *SSPx, uint32_t DMAMode, FunctionalState NewState);
	
	/* SSP get information functions ----------------------------------------------*/
	FlagStatus SSP_GetStatus(HM_SSP_TypeDef* SSPx, uint32_t FlagType);
	uint32_t SSP_GetDataSize(HM_SSP_TypeDef* SSPx);
	IntStatus SSP_GetRawIntStatus(HM_SSP_TypeDef *SSPx, uint32_t RawIntType);
	uint32_t SSP_GetRawIntStatusReg(HM_SSP_TypeDef *SSPx);
	IntStatus SSP_GetIntStatus (HM_SSP_TypeDef *SSPx, uint32_t IntType);
	
	/* SSP transfer data functions ------------------------------------------------*/
	void SSP_SendData(HM_SSP_TypeDef* SSPx, uint16_t Data);
	uint16_t SSP_ReceiveData(HM_SSP_TypeDef* SSPx);
	uint8_t SSP_SendRecvByte (HM_SSP_TypeDef *SSPx,uint8_t byte_s);
	void SSP_ClearRFifo (HM_SSP_TypeDef *SSPx);
	int32_t SSP_ReadWrite (HM_SSP_TypeDef *SSPx, SSP_DATA_SETUP_Type *dataCfg, \
							SSP_TRANSFER_Type xfType);
	
	/* SSP IRQ function ------------------------------------------------------------*/
	void SSP_IntConfig(HM_SSP_TypeDef *SSPx, uint32_t IntType, FunctionalState NewState);
	void SSP_ClearIntPending(HM_SSP_TypeDef *SSPx, uint32_t IntType);

/**
 * @}
 */


#ifdef __cplusplus
}
#endif


#endif /* __HM_SSP_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
