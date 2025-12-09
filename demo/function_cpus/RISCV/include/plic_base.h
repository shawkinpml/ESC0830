#ifndef PML_PLIC_BASE_H
#define PML_PLIC_BASE_H

#include "encoding.h"

#ifndef   __STATIC_FORCEINLINE
  #define __STATIC_FORCEINLINE                   __attribute__((always_inline)) static inline
#endif

#ifndef __ASM
#define __ASM                   __asm     /*!< asm keyword for GNU Compiler */
#endif

#define __STR(s)                #s
#define STRINGIFY(s)            __STR(s)

#define __RV_CSR_SET(csr, val)                                  \
    ({                                                          \
        register uint32_t __v = (uint32_t)(val);                \
        __ASM volatile("csrs " STRINGIFY(csr) ", %0"            \
                     :                                          \
                     : "rK"(__v)                                \
                     : "memory");                               \
    })


#define __RV_CSR_CLEAR(csr, val)                                \
    ({                                                          \
        register uint32_t __v = (uint32_t)(val);                \
        __ASM volatile("csrc " STRINGIFY(csr) ", %0"            \
                     :                                          \
                     : "rK"(__v)                                \
                     : "memory");                               \
    })

__STATIC_FORCEINLINE void rv_enable_irq(void)
{
    __RV_CSR_SET(CSR_MSTATUS, MSTATUS_MIE);
}

__STATIC_FORCEINLINE void rv_disable_irq(void)
{
    __RV_CSR_CLEAR(CSR_MSTATUS, MSTATUS_MIE);
}

__STATIC_FORCEINLINE void rv_enable_ext_irq(void)
{
    __RV_CSR_SET(CSR_MIE, MIE_MEIE);
}

__STATIC_FORCEINLINE void rv_disable_ext_irq(void)
{
    __RV_CSR_CLEAR(CSR_MIE, MIE_MEIE);
}

#endif