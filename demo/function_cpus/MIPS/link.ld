/***********************************************************************
 *
 *  link.ld
 *
 *  Linker script for startup code for simulator and M14Kc  
 *
 * ######################################################################
 
Copyright (c) 2007-2018, MIPS Tech, LLC and/or its affiliated group companies or licensors 

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are 
permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of 
conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list 
of conditions and the following disclaimer in the documentation and/or other materials 
provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be 
used to endorse or promote products derived from this software without specific prior 
written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY 
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* INCLUDE uc_rootboot_sram.ld */

OUTPUT_ARCH(mips)

/**** Start point ****/
ENTRY(__reset_vector)

SECTIONS
{
  /* Boot ROM address */
  _boot_rom = ORIGIN(REGION_ROM);

  /************************************/
  /* Text section (boot code)         */
  /************************************/
  .text_init :
  AT( _boot_rom )       /* (Load address is start of Boot ROM.) */
  {
    _ftext_rom = ABSOLUTE(.) ;  /* Start of init code. */
    *start*.o(.text)       /* put reset entry point at the beggining of the .text section */
    *init_cp0.o(.text)
    *init_caches.o(.text)
    *init_gpr.o(.text)
    *init_gp_sp.o(.text)
    *init_isr.o(.text)
    *init_tlb.o(.text)
    *soc_specific.o(.text)
    *gic_isr.o(.text)
    *boot_error.o(.text)
    . = ALIGN(8);   
    _etext_rom = ABSOLUTE(.);  /* End of init code. */
  } > REGION_ROM

  /**** "C" Code and read-only data ****/
  .text_c :      /* Need to copy code and read-only data to ram... */
  {
    _ftext_c_rom = ABSOLUTE(.) ;  /* Start of code and read-only data */
    *(.text)*(.text.*)
    . = ALIGN(8);
    _etext_c_rom = ABSOLUTE(.);  /* End of code and read-only data   */
  } > REGION_ROM

  /************************************/
  /* read-only data section           */
  /************************************/
  .rodata :
  {
    rodata_start = ABSOLUTE(.);
    *(.rodata)
    *(.rodata.*)

    . = ALIGN(4);
    __label_start__ = .;
    KEEP(*(.label*))
    __label_end__ = .;

    rodata_end = ABSOLUTE(.);
  } > REGION_ROM
  
  /**** Initialised data ****/
  . = ALIGN(4);
  _fdata_rom = .;

  /************************************/
  /* data section                     */
  /************************************/
  .data :
  AT( _fdata_rom )        /* (Load address is after rodata in Boot ROM.) */
  {
    _fdata_ram = ABSOLUTE(.); /* Start of initialised data      */
    *(.data)
    *(.data.*)
    . = ALIGN(8);
    _gp = ABSOLUTE(. + 0x7ff0); /* Base of small data       */
    *(.lit8) 
    *(.lit4) 
    *(.sdata) 
    *(.sdata.*) 
    . = ALIGN(8);
    _edata_ram  = ABSOLUTE(.);  /* End of initialised data      */
  } > REGION_RAM

    /**** Uninitialised data ****/

  _fbss = .;      /* Start of uninitialised data      */

  .sbss : 
  { 
    *(.sbss*) 
    *(.scommon)
  } > REGION_RAM
  .bss :
  {
    *(.bss*)
    *(COMMON)
  } > REGION_RAM

  _end = . ;    /* End of uninitialised data      */

  . = ALIGN(4);
  .heap (COPY):
  {
    __HeapBase = .;
    __end__ = .;
    end = __end__;
    KEEP(*(.heap*))
    __HeapLimit = .;
  } > RAM

  /* .stack_dummy section doesn't contains any symbols. It is only
   * used for linker to calculate size of stack sections, and assign
   * values to stack symbols later */
  .stack_dummy (COPY):
  {
    KEEP(*(.stack*))
  } > RAM

  /* Set stack top to end of RAM, and stack limit move down by
   * size of stack_dummy section */
  __StackTop = ORIGIN(RAM) + LENGTH(RAM);
  __StackLimit = __StackTop - SIZEOF(.stack_dummy);
  PROVIDE(__stack = __StackTop);

  /* Check if data + heap + stack exceeds RAM limit */
  ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")

  .gptab.sdata : { *(.gptab.data) *(.gptab.sdata) }
  .gptab.sbss : { *(.gptab.bss) *(.gptab.sbss) }

  /DISCARD/ :
  {
    *(.reginfo)
    *(.MIPS.abiflags)
  }
  _freemem = .;

  /*PROVIDE (__stack = 0);*/
  /************************************/
  /* Stack symbols                    */
  /************************************/
  /* put stack pointer at the top of a stack region (stack is growing down) */
  /* _stack = ORIGIN(REGION_STACK) + LENGTH(REGION_STACK);
  _stack_size = LENGTH(REGION_STACK); */
  
  /************************************/
  /* Boot status.           
  /************************************/
  /* This is where the boot ROM will write error code if anything goes wrong */
  /* .boot_status (NOLOAD) :
  {
    _boot_status = ABSOLUTE(.);
    *(.boot_status)
  } > REGION_STATUS */

  /************************************/
  /* HEAP.           
  /************************************/
  /* _malloc = ORIGIN(REGION_HEAP);
  _malloc_size = LENGTH(REGION_HEAP); */

}
