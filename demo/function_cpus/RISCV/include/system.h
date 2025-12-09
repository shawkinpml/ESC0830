#ifndef RISCV_E906_SYSTEM_H
#define RISCV_E906_SYSTEM_H
#include "io_e906.h"

#ifndef __ALWAYS_STATIC_INLINE
#define __ALWAYS_STATIC_INLINE  __attribute__((always_inline)) static inline
#endif

#ifndef __STATIC_INLINE
#define __STATIC_INLINE         static inline
#endif

#ifndef __ASM
#define __ASM                   __asm     /*!< asm keyword for GNU Compiler */
#endif

// typedef unsigned      uint32_t;
// typedef	unsigned char uint8_t;
// typedef int           int32_t;
#include <stdint.h>


/* following defines should be used for structure members */
#define     __IM     volatile const       /*! Defines 'read only' structure member permissions */
#define     __OM     volatile             /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile             /*! Defines 'read / write' structure member permissions */

typedef struct {
    __IOM uint8_t IP;           /*!< Offset: 0x000 (R/W)  Interrupt set pending register */
    __IOM uint8_t IE;           /*!< Offset: 0x004 (R/W)  Interrupt set enable register */
    __IOM uint8_t ATTR;         /*!< Offset: 0x008 (R/W)  Interrupt set attribute register */
    __IOM uint8_t CTL;          /*!< Offset: 0x00C (R/W)  Interrupt control register */
} CLIC_INT_Control;

typedef struct {
    __IOM uint32_t CLICCFG:8;                 /*!< Offset: 0x000 (R/W)  CLIC configure register */
    __IM  uint32_t CLICINFO;
    __IOM uint32_t MINTTHRESH;
    uint32_t RESERVED[1021];
    CLIC_INT_Control CLICINT[4096];
} CLIC_Type;

#define CLIC_INFO_CLICINTCTLBITS_Pos           21U
#define CLIC_INFO_CLICINTCTLBITS_Msk           (0xFUL << CLIC_INFO_CLICINTCTLBITS_Pos)

#define CLIC_INTIP_IP_Pos                      0U                                    /*!< CLIC INTIP: IP Position */
#define CLIC_INTIP_IP_Msk                      (0x1UL << CLIC_INTIP_IP_Pos)          /*!< CLIC INTIP: IP Mask */

#define CLIC_INTIE_IE_Pos                      0U                                    /*!< CLIC INTIE: IE Position */
#define CLIC_INTIE_IE_Msk                      (0x1UL << CLIC_INTIE_IE_Pos)          /*!< CLIC INTIE: IE Mask */

#define CLIC_INTIE_T_Pos                       7U                                    /*!< CLIC INTIE: T Position */
#define CLIC_INTIE_T_Msk                       (0x1UL << CLIC_INTIE_T_Pos)           /*!< CLIC INTIE: T Mask */

#define CLIC_INTATTR_TRIG_Pos                  1U                                    /*!< CLIC INTATTR: TRIG Position */
#define CLIC_INTATTR_TRIG_Msk                  (0x3UL << CLIC_INTATTR_TRIG_Pos)      /*!< CLIC INTATTR: TRIG Mask */

#define CLIC_INTATTR_SHV_Pos                   0U                                    /*!< CLIC INTATTR: SHV Position */
#define CLIC_INTATTR_SHV_Msk                   (0x1UL << CLIC_INTATTR_SHV_Pos)       /*!< CLIC INTATTR: SHV Mask */

#define CLIC_INTCFG_NVBIT_Pos                  5U                                    /*!< CLIC INTCFG: NVBIT Position */
#define CLIC_INTCFG_NVBIT_Msk                  (0x1UL << CLIC_INTCFG_NVBIT_Pos)      /*!< CLIC INTCFG: NVBIT Mask */

#define CLIC_INTCFG_PRIO_Pos                   5U                                    /*!< CLIC INTCFG: INTCFG Position */
#define CLIC_INTCFG_PRIO_Msk                   (0x7UL << CLIC_INTCFG_PRIO_Pos)       /*!< CLIC INTCFG: INTCFG Mask */

#define CLIC_CLICCFG_NVBIT_Pos                 0U                                    /*!< CLIC CLICCFG: NVBIT Position */
#define CLIC_CLICCFG_NVBIT_Msk                 (0x1UL << CLIC_CLICCFG_NVBIT_Pos)     /*!< CLIC CLICCFG: NVBIT Mask */

#define CLIC_CLICCFG_NLBIT_Pos                 1U                                    /*!< CLIC CLICCFG: NLBIT Position */
#define CLIC_CLICCFG_NLBIT_Msk                 (0xFUL << CLIC_CLICCFG_NLBIT_Pos)     /*!< CLIC CLICCFG: NLBIT Mask */

#define CLIC_CLICCFG_NMBIT_Pos                 5U                                    /*!< CLIC CLICCFG: NMBIT Position */
#define CLIC_CLICCFG_NMBIT_Msk                 (0x3UL << CLIC_CLICCFG_NMBIT_Pos)     /*!< CLIC CLICCFG: NMBIT Mask */

#define CLIC_BASE           (0xE0800000UL)  
#define CLIC                ((CLIC_Type    *)     CLIC_BASE   )       /*!< CLIC configuration struct */

void print_status();
void print_clic_irq(uint32_t n);
void enable_irq(int32_t n);

#endif