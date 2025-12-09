/**********************************************************************
* $Id$		hm_emac.h			2021-11-13
*//**
* @file		hm_emac.h
* @brief	Contains all functions support for EMAC firmware library
*			on HM3C1788,HM4C123,HM3S9B96
* @version	1.0
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
/** @defgroup EMAC	
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_EMAC_H_
#define __HM_EMAC_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"
#include "hr3_gem.h"


#ifdef __cplusplus
extern "C"
{
#endif


/* Private Macros ------------------------------------------------------------- */
/** @defgroup EMAC_Private_Macros emac Private Macros
 * @{
 */


/**
 * @}
 */

/**************************** GLOBAL/PUBLIC TYPES ***************************/

/** @defgroup EMAC_Public_Types EMAC Public Types
 * @{
 */



/**
 * @}
 */




/* Public Functions ----------------------------------------------------------- */
/** @defgroup EMAC_Public_Functions emac Public Functions
 * @{
 */
void EMAC_PhyInit(void);

/** Init/DeInit */
void EMAC_RmiiInit(void);
void EMAC_MiiInit(void);
void EMAC_Init(void);


/** Send/Receive data */
void EMAC_TxEnable( void );
void EMAC_RxEnable( void );

/** MDIO */
void EMAC_SetMdioEnable(uint8_t enable);
uint32_t EMAC_MdioReadReg(uint32_t offset);
void EMAC_MdioWriteReg(uint32_t offset,uint32_t value);

int hr3_gem_setup_mac(struct hr3_gem_priv *priv,char *macAddr);
int hr3_gem_probe(struct hr3_gem_priv *priv);
int hr3_gem_init(struct hr3_gem_priv *priv);
int hr3_gem_send(struct hr3_gem_priv *priv, void *ptr, int len);
/* Do not check frame_recd flag in rx_status register 0x20 - just poll BD */
int hr3_gem_recv(struct hr3_gem_priv *priv);
int hr3_gem_recv2(struct hr3_gem_priv *priv, int flags, unsigned char **packetp);
int hr3_gem_free_pkt(struct hr3_gem_priv *priv, unsigned char *packet, int length);
void hr3_gem_stop(struct hr3_gem_priv *priv);
void data_init(unsigned int addr);
void ethernet_port_init(void);




/**
 * @}
 */


#ifdef __cplusplus
}
#endif


#endif /* __HM_EMAC_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
