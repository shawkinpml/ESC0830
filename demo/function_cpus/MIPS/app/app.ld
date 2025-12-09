/***********************************************************************
 *
 * target.memory
 *
 * System dependent part of the primary loader linker script. Maps the 
 * output sections to the memory regions available on the system, and 
 * is included from the linker script bootROM.ld
 *
 ************************************************************************/

/* 
 * All origins are virtual addresses in kseg0 (cached) region. 
 * Primary loader runs uncached till I$ is initialized. 
 *
 * Reserve top of the SRAM for the status and data sections + stack:
 *
  * ----------
 * | STATUS |
 * ----------
 * |  DATA  |
 * ----------
 * | STACK  |
 * ----------
 * | unused |
 * ----------
 */

/*
  20201210: The full AHB_SRAM allocates to rodata&data&bss&stack.
  For CPU test and peripherals test.
*/

/*
ROM: 0xBFC00000 ~ 0xBFC3FFFF, 64K, 0x10000
AHBRAM: 0x82A00000 ~ 0x82A1FFFF, 128K, 0x20000
AXIRAM1: 0x84000000 ~ 0x84200000, 2048K, 0x200000
DPSRAM: 0xBFC80000 ~ 0xBFC8FFFF, 64K, 0x10000
*/

MEMORY
{
  ROM (RX): ORIGIN = 0x80100000, LENGTH = 114k /* TODO */
	RAM (RW): ORIGIN = 0x80120000, LENGTH = 48k
}

/* put .text and .rodata in ROM, all other sections in RAM */
REGION_ALIAS("REGION_ROM", ROM);
REGION_ALIAS("REGION_RAM", RAM);
