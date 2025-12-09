/**********************************************************************
* $Id$		hm_types.h			2021-09-28
*//**
* @file		hm_types.h
* @brief	Contains the PML ABL typedefs for C standard types.
*			It is intended to be used in ISO C conforming development
*			environments and checks for this insofar as it is possible
*			to do so.
* @version	0.01
* @date		28. Sept. 2021
* @author	PML MCU SW Application Team
* 
* Copyright(C) 2024, Purple Moutain Laboratories
* All rights reserved.
*
**********************************************************************/

/* Type group ----------------------------------------------------------- */
#ifndef __HM_TYPES_H
#define __HM_TYPES_H

/* Includes ------------------------------------------------------------------- */
#include <stdint.h>

/** @defgroup HM_Type_Def Data Types Definitions
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */
 
/* Public Types --------------------------------------------------------------- */
/** @defgroup HM_Types_Public_Types Basic Public Data Types
 * @{
 */

/**
 * @brief Boolean Type definition
 */
typedef enum {FALSE = 0, TRUE = !FALSE} Bool;

/**
 * @brief Flag Status and Interrupt Flag Status type definition
 */
typedef enum {RESET = 0, SET = !RESET} FlagStatus, IntStatus, SetState;
#define PARAM_SETSTATE(State) ((State==RESET) || (State==SET))

/**
 * @brief Functional State Definition
 */
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define PARAM_FUNCTIONALSTATE(State) ((State==DISABLE) || (State==ENABLE))

/**
 * @ Status type definition
 */
typedef enum {ERROR = 0, SUCCESS = !ERROR} Status;


/**
 * Read/Write transfer type mode (Block or non-block)
 */
typedef enum
{
	NONE_BLOCKING = 0,		/**< None Blocking type */
	BLOCKING,				/**< Blocking type */
} TRANSFER_BLOCK_Type;


/** Pointer to Function returning Void (any number of parameters) */
typedef void (*PFV)();

/** Pointer to Function returning int32_t (any number of parameters) */
typedef int32_t(*PFI)();

/**
 * @}
 */


/* Public Macros -------------------------------------------------------------- */
/** @defgroup HM_Types_Public_Macros  Basic Public Macros
 * @{
 */

/** _BIT(n) sets the bit at position "n"
 * _BIT(n) is intended to be used in "OR" and "AND" expressions:
 * e.g., "(_BIT(3) | _BIT(7))".
 */
#undef _BIT
/** Set bit macro */
#define _BIT(n)	(1<<n)

/** _SBF(f,v) sets the bit field starting at position "f" to value "v".
 * _SBF(f,v) is intended to be used in "OR" and "AND" expressions:
 * e.g., "((_SBF(5,7) | _SBF(12,0xF)) & 0xFFFF)"
 */
#undef _SBF
/* Set bit field macro */
#define _SBF(f,v) (v<<f)

/* _BITMASK constructs a symbol with 'field_width' least significant
 * bits set.
 * e.g., _BITMASK(5) constructs '0x1F', _BITMASK(16) == 0xFFFF
 * The symbol is intended to be used to limit the bit field width
 * thusly:
 * <a_register> = (any_expression) & _BITMASK(x), where 0 < x <= 32.
 * If "any_expression" results in a value that is larger than can be
 * contained in 'x' bits, the bits above 'x - 1' are masked off.  When
 * used with the _SBF example above, the example would be written:
 * a_reg = ((_SBF(5,7) | _SBF(12,0xF)) & _BITMASK(16))
 * This ensures that the value written to a_reg is no wider than
 * 16 bits, and makes the code easier to read and understand.
 */
#undef _BITMASK
/* Bitmask creation macro */
#define _BITMASK(field_width) ( _BIT(field_width) - 1)

/* NULL pointer */
#ifndef NULL
#define NULL ((void*) 0)
#endif

/* Number of elements in an array */
#define NELEMENTS(array)  (sizeof (array) / sizeof (array[0]))

/* Static data/function define */
#define STATIC static
/* External data/function define */
#define EXTERN extern

#if !defined(MAX)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif
#if !defined(MIN)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

/**
 * @}
 */


/* Old Type Definition compatibility ------------------------------------------ */
/** @addtogroup HM_Types_Public_Types HM_Types Public Types
 * @{
 */

/** SMA type for character type */
typedef char CHAR;

/** SMA type for 8 bit unsigned value */
typedef uint8_t UNS_8;

/** SMA type for 8 bit signed value */
typedef int8_t INT_8;

/** SMA type for 16 bit unsigned value */
typedef	uint16_t UNS_16;

/** SMA type for 16 bit signed value */
typedef	int16_t INT_16;

/** SMA type for 32 bit unsigned value */
typedef	uint32_t UNS_32;

/** SMA type for 32 bit signed value */
typedef	int32_t INT_32;

/** SMA type for 64 bit signed value */
typedef int64_t INT_64;

/** SMA type for 64 bit unsigned value */
typedef uint64_t UNS_64;

/** 32 bit boolean type */
typedef Bool BOOL_32;

/** 16 bit boolean type */
typedef Bool BOOL_16;

/** 8 bit boolean type */
typedef Bool BOOL_8;

/**
 * @}
 */
#define delay_cnt(n) { \
			volatile unsigned int i = (n); \
			while(i--); \
	}
    
#define WRITE_REG(x, y) do {			\
            *((volatile uint32_t *)(x)) = y;   \
        } while(0)

#define read_reg_u32(where)	(*(volatile uint32_t *) (where))
    
#define write_reg_u32(where, val)  WRITE_REG(where, val)

#define read_ahb_u32(where)		read_reg_u32(where)
#define write_ahb_u32(where, val)	write_reg_u32(where, val)


#endif /* __HM_TYPES_H */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
