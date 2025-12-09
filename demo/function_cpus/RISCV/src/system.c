#include "system.h"
#include "uart_print.h"

// uint32_t __get_SP(void)
// {
//     uint32_t result;

//     __ASM volatile("mv %0, sp" : "=r"(result));
//     return (result);
// }

// void __set_SP(uint32_t sp)
// {
//     __ASM volatile("mv sp, %0" : : "r"(sp): "sp");
// }

__ALWAYS_STATIC_INLINE uint32_t __get_MSTATUS(void)
{
    uint32_t result;

    __ASM volatile("csrr %0, mstatus" : "=r"(result));
    return (result);
}

/**
  \brief   Set MSTATUS
  \details Writes the given value to the MSTATUS Register.
  \param [in]    mstatus  MSTATUS Register value to set
 */
__ALWAYS_STATIC_INLINE void __set_MSTATUS(uint32_t mstatus)
{
    __ASM volatile("csrw mstatus, %0" : : "r"(mstatus));
}

/**
  \brief   Get MIE Register
  \details Returns the content of the MIE Register.
  \return               MIE Register value
 */
__ALWAYS_STATIC_INLINE uint32_t __get_MIE(void)
{
    uint32_t result;

    __ASM volatile("csrr %0, mie" : "=r"(result));
    return (result);
}

/**
  \brief   Set MIE
  \details Writes the given value to the MIE Register.
  \param [in]    mie  MIE Register value to set
 */
__ALWAYS_STATIC_INLINE void __set_MIE(uint32_t mie)
{
    __ASM volatile("csrw mie, %0" : : "r"(mie));
}

/**
  \brief   Get MTVEC Register
  \details Returns the content of the MTVEC Register.
  \return               MTVEC Register value
 */
__ALWAYS_STATIC_INLINE uint32_t __get_MTVEC(void)
{
    uint32_t result;

    __ASM volatile("csrr %0, mtvec" : "=r"(result));
    return (result);
}

/**
  \brief   Set MTVEC
  \details Writes the given value to the MTVEC Register.
  \param [in]    mtvec  MTVEC Register value to set
 */
__ALWAYS_STATIC_INLINE void __set_MTVEC(uint32_t mtvec)
{
    __ASM volatile("csrw mtvec, %0" : : "r"(mtvec));
}

/**
  \brief   Set MTVT
  \details Writes the given value to the MTVT Register.
  \param [in]    mtvt  MTVT Register value to set
 */
__ALWAYS_STATIC_INLINE void __set_MTVT(uint32_t mtvt)
{
    __ASM volatile("csrw mtvt, %0" : : "r"(mtvt));
}

/**
  \brief   Get MTVT Register
  \details Returns the content of the MTVT Register.
  \return               MTVT Register value
 */
__ALWAYS_STATIC_INLINE uint32_t __get_MTVT(void)
{
    uint32_t result;

    __ASM volatile("csrr %0, mtvt" : "=r"(result));
    return (result);
}


__STATIC_INLINE void csi_vic_enable_irq(int32_t IRQn)
{
    CLIC->CLICINT[IRQn].IE |= CLIC_INTIE_IE_Msk;
}

__STATIC_INLINE uint32_t csi_vic_get_enabled_irq(int32_t IRQn)
{
    return (uint32_t)(CLIC->CLICINT[IRQn].IE & CLIC_INTIE_IE_Msk);
}

__STATIC_INLINE uint32_t csi_vic_get_pending_irq(int32_t IRQn)
{
    return (uint32_t)(CLIC->CLICINT[IRQn].IP & CLIC_INTIP_IP_Msk);
}

__STATIC_INLINE void csi_vic_set_prio(int32_t IRQn, uint32_t priority)
{
    uint8_t nlbits = (CLIC->CLICINFO & CLIC_INFO_CLICINTCTLBITS_Msk) >> CLIC_INFO_CLICINTCTLBITS_Pos;
    CLIC->CLICINT[IRQn].CTL = (CLIC->CLICINT[IRQn].CTL & (~CLIC_INTCFG_PRIO_Msk)) | (priority << (8 - nlbits));
}

__STATIC_INLINE uint32_t csi_vic_get_prio(int32_t IRQn)
{
    uint8_t nlbits = (CLIC->CLICINFO & CLIC_INFO_CLICINTCTLBITS_Msk) >> CLIC_INFO_CLICINTCTLBITS_Pos;
    return CLIC->CLICINT[IRQn].CTL >> (8 - nlbits);
}

__STATIC_INLINE uint32_t csi_vic_get_ctrl(int32_t IRQn)
{
    return (uint32_t)(CLIC->CLICINT[IRQn].CTL);
}

__STATIC_INLINE void csi_vic_set_shv_vector(int32_t IRQn)
{
     CLIC->CLICINT[IRQn].ATTR |= CLIC_INTATTR_SHV_Msk;    // vector mode interrupt
}

__STATIC_INLINE void csi_vic_set_shv_non_vector(int32_t IRQn)
{
    CLIC->CLICINT[IRQn].ATTR &= ~CLIC_INTATTR_SHV_Msk; // non-vector mode interrupt
}

__STATIC_INLINE uint32_t csi_vic_get_attr(int32_t IRQn)
{
    return (uint32_t)(CLIC->CLICINT[IRQn].ATTR);
}

void print_status(){
  uint32_t temp = __get_MSTATUS();
  uart_printf("mstatus = %x\r\n", temp);

  // temp = __get_MIE();
  // uart_printf("mie     = %x\r\n", temp);
  // __set_MIE(0x888); // FIXME by zcd: all bits are fixed at 0 in hardware
  // temp = __get_MIE();
  // uart_printf("mie     = %x\r\n", temp);
  // __asm volatile( "csrs mie, %0" :: "r"(0x888) );
  // temp = __get_MIE();
  // uart_printf("mie     = %x\r\n", temp);

  temp = __get_MTVEC();
  uart_printf("mtvec   = %x\r\n", temp);
  temp = __get_MTVT();
  uart_printf("mtvt    = %x\r\n", temp);

  // uart_printf("CLICCFG      = %x,%x\r\n", *((volatile uint8_t *)(CLIC_BASE + 4 * 0)), CLIC->CLICCFG);
  uart_printf("CLICCFG(new) = %x\r\n", CLIC->CLICCFG);
  uart_printf("CLICINFO     = %x,%x\r\n", *((volatile uint32_t *)(CLIC_BASE + 4 * 1)), CLIC->CLICINFO);
  uart_printf("MINTTHRESH   = %x,%x\r\n", *((volatile uint32_t *)(CLIC_BASE + 4 * 2)), CLIC->MINTTHRESH);
  // *((volatile uint8_t *)(CLIC_BASE + 4 * 0)) = 0x1f; // 0x07;
  // uart_printf("CLICCFG    = %02x\r\n", *((volatile uint8_t *)(CLIC_BASE + 4 * 0))); // TODO is that right ?

  // uart_printf("CLICCFG    = %02x\r\n", *((volatile uint8_t *)0xE0800000));
  // uart_printf("CLICINFO   = %x\r\n", *((volatile uint32_t *)0xE0800004));
  // uart_printf("MINTTHRESH = %x\r\n", *((volatile uint32_t *)0xE0800008));
  // get interrupt level from info
  // *((volatile uint8_t *)0xE0800000) = 0x1f; // 0x07;
  // CLIC->CLICCFG = (((CLIC->CLICINFO & CLIC_INFO_CLICINTCTLBITS_Msk) >> CLIC_INFO_CLICINTCTLBITS_Pos) << CLIC_CLICCFG_NLBIT_Pos);
//   uart_printf("CLICCFG    = %02x\r\n", *((volatile uint8_t *)(CLIC_BASE + 4 * 0)));
  // uart_printf("CLICCFG    = %02x\r\n", *((volatile uint8_t *)0xE0800000));
}

void print_clic_irq(uint32_t n) {
  n = n + 16; // Very important! CLIC ctrl external irq from 16
  uart_printf("CLICINT[%u]     = %x\r\n", n, *((volatile uint32_t *)(CLIC_INI_BASE + n * CLIC_INT_INTERVAL)));
}


void update_cliccfg(void) {
  CLIC->CLICCFG = (((CLIC->CLICINFO & CLIC_INFO_CLICINTCTLBITS_Msk) >> CLIC_INFO_CLICINTCTLBITS_Pos) << CLIC_CLICCFG_NLBIT_Pos);
}

void enable_irq(int32_t n) {
  n = n + 16; // Very important! CLIC ctrl external irq from 16

  // *((volatile uint8_t *)(CLIC_INI_BASE + n * CLIC_INT_INTERVAL + CLIC_INI_ATTR_OFFSET)) = 0xc1;
  // *((volatile uint8_t *)(CLIC_INI_BASE + n * CLIC_INT_INTERVAL + CLIC_INI_CTL_OFFSET)) = 0x3f; // 63: lllx xxxx = 0011 1111
  // *((volatile uint8_t *)(CLIC_INI_BASE + n * CLIC_INT_INTERVAL + CLIC_INI_IE_OFFSET)) = 1;

  // csi_vic_set_prio(n, 1); // prio = 1, nlbits = 3, ctrl = lllx xxxx = 0011 1111 = 63 !
  csi_vic_set_prio(n, 7 - (n - 16));
  
//   csi_vic_get_prio(n);

//   csi_vic_get_ctrl(n); // got 63 !

//   csi_vic_get_attr(n);
  // csi_vic_set_shv_non_vector(n);
  csi_vic_set_shv_vector(n);
//   csi_vic_get_attr(n);

  csi_vic_enable_irq(n);
//   csi_vic_get_enabled_irq(n);
  // uart_printf("RV External irq %d: IE=%x, ATTR=%x, CTL=%x\r\n", n-16, CLIC->CLICINT[n].IE, CLIC->CLICINT[n].ATTR, CLIC->CLICINT[n].CTL);
}
