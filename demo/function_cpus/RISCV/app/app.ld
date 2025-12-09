/*************************************************************
// <<< Use Configuration Wizard in Context Menu >>>
*************************************************************/

/*************************************************************
// <m> Entry Point <2>
// <i> config start function for this application
*************************************************************/
ENTRY( Reset_Handler )

MEMORY
{
  ROM : 
/*************************************************************
// <o> ROM Start Address (in Bytes) <0x0-0xFFFFFFFF:0x100>
// <i> config start address of (text, rodata) area for this application
*************************************************************/
  /* error! cause rv find vector from flash */
  /* ORIGIN = 0x0 ,  */
  ORIGIN = 0x00100000 , 
/*************************************************************
// <o> Memory Length (in Bytes) <0x0-0xFFFFFFFF:0x1>
// <i> config the length of (text, rodata) area for this application
*************************************************************/
  LENGTH = 0x1C800 /*114K*/

  RAM1 :

  ORIGIN = 0x00100000, 

  LENGTH = 0x1C800 
  
  RAM : 
/*************************************************************
// <o> RAM Start Address (in Bytes) <0x0-0xFFFFFFFF:0x100>
// <i> config start address of (bss, data) area for this application
*************************************************************/
  ORIGIN = 0x20120000 , 
/*************************************************************
// <o> Memory Length (in Bytes) <0x0-0xFFFFFFFF:0x1>
// <i> config the length of (text, rodata) area for this application
*************************************************************/
  LENGTH = 0xC000 /* 48KB */
}

SECTIONS
{
    .text : {
		. = ALIGN(0x4) ;
		KEEP(*startup.o(*.text*))
		__stext = . ;
		*(.text)
		*(.text*)
		*(.text.*)

		*(.gnu.warning)
		*(.stub)
		*(.gnu.linkonce.t*)
		*(.glue_7t)
		*(.glue_7)
		*(.jcr)

		KEEP (*(.init))
		KEEP (*(.fini))
		
		/* This is special code area at the end of the normal
		   text section.  It contains a small lookup table at
		   the start followed by the code pointed to by entries
		   in the lookup table.  
		 */
		. = ALIGN (4) ;
		PROVIDE(__ctbp = .);
		*(.call_table_data)
		*(.call_table_text)
		
		. = ALIGN(0x10) ;
		__etext = . ;
    } >RAM1 AT>ROM

    .rodata : {
		. = ALIGN(0x4) ;
		__srodata = .;
		*(.rdata)
		*(.rdata*)
		*(.rdata1)
		*(.rdata.*)
		*(.rodata)
		*(.rodata1)
		*(.rodata*)
		*(.rodata.*)
		*(.rodata.str1.4)

		. = ALIGN(4);
        __label_start__ = .;
		KEEP(*(.label*))
		__label_end__ = .;

		. = ALIGN(0x4) ;
		__e_rom = .;
    } >RAM1 AT>ROM
    .data : {
		__l_s_ram = LOADADDR (.data);
		. = ALIGN(0x4) ;
		__s_ram_data_1 = . ;
		__data_start = . ;
		data_start = . ;
		KEEP(*startup.o(*.vectors*))
		*(.got.plt)
		*(.got)
		*(.gnu.linkonce.r*)
		*(.data)
		*(.data*)
		*(.data1)
		*(.data.*)
		*(.gnu.linkonce.d*)
		*(.data1)
		*(.gcc_except_table)
		*(.gcc_except_table*)
		*(.sdata) 
		*(.sdata.*)
		*(.gnu.linkonce.s.*)
		*(__libc_atexit)
		*(__libc_subinit)
		*(__libc_subfreeres)
		*(.note.ABI-tag)
		. = ALIGN(0x4) ; 
		__e_ram_data_1 = . ;
	} > RAM  AT>ROM

    .bss : {
		. = ALIGN(0x4) ;
		__sbss = ALIGN(0x4) ;
		__s_ram_bss_1 = . ;
		*(.dynsbss)
		*(.sbss)
		*(.sbss.*)
		*(.scommon)
		*(.dynbss)
		*(.bss)
		*(.bss.*)
		*(COMMON)
		. = ALIGN(0x10) ;
		__e_ram_bss_1 = .;
		KEEP(*crt0.o(.app_stack))
		KEEP(*crt0.o(.app_heap))
		__end = . ;
		_end = . ;
		end = . ;
	} > RAM

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
	  
	.eh_frame           : ONLY_IF_RO { KEEP (*(.eh_frame)) } > RAM
	.gcc_except_table   : ONLY_IF_RO { *(.gcc_except_table .gcc_except_table.*) } > RAM
	.eh_frame           : ONLY_IF_RW { KEEP (*(.eh_frame)) }
	.gcc_except_table   : ONLY_IF_RW { *(.gcc_except_table .gcc_except_table.*) }
	.eh_frame_hdr       : { *(.eh_frame_hdr) }

	.preinit_array		:
	{
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP (*(.preinit_array))
		PROVIDE_HIDDEN (__preinit_array_end = .);
	}
	.init_array			:
	{
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP (*(SORT(.init_array.*)))
		KEEP (*(.init_array))
		PROVIDE_HIDDEN (__init_array_end = .);
	}
	.fini_array			:
	{
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP (*(.fini_array))
		KEEP (*(SORT(.fini_array.*)))
		PROVIDE_HIDDEN (__fini_array_end = .);
	} 
	 
	.ctors :
	{
		/* gcc uses crtbegin.o to find the start of
			the constructors, so we make sure it is
			first.  Because this is a wildcard, it
			doesn't matter if the user does not
			actually link against crtbegin.o; the
			linker won't look for a file to match a
			wildcard.  The wildcard also means that it
			doesn't matter which directory crtbegin.o
			is in.  */
		KEEP (*crtbegin.o(.ctors))
		KEEP (*crtbegin?.o(.ctors))
		/* We don't want to include the .ctor section from
			the crtend.o file until after the sorted ctors.
			The .ctor section from the crtend file contains the
			end of ctors marker and it must be last */
		KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
		KEEP (*(SORT(.ctors.*)))
		KEEP (*(.ctors))
	} > RAM
	.dtors :
	{
		KEEP (*crtbegin.o(.dtors))
		KEEP (*crtbegin?.o(.dtors))
		KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
		KEEP (*(SORT(.dtors.*)))
		KEEP (*(.dtors))
	} > RAM

	.junk 0 : { *(.rel*) *(.rela*) }
	/* Stabs debugging sections.    */
	.stab 0 : { *(.stab) }
	.stabstr 0 : { *(.stabstr) }
	.stab.excl 0 : { *(.stab.excl) }
	.stab.exclstr 0 : { *(.stab.exclstr) }
	.stab.index 0 : { *(.stab.index) }
	.stab.indexstr 0 : { *(.stab.indexstr) }
	.comment 0 : { *(.comment) }
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
	.debug          0 : { *(.debug) }
	.line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
	.debug_srcinfo  0 : { *(.debug_srcinfo) }
	.debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
	.debug_aranges  0 : { *(.debug_aranges) }
	.debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
	.debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
	.debug_abbrev   0 : { *(.debug_abbrev) }
	.debug_line     0 : { *(.debug_line) }
	.debug_frame    0 : { *(.debug_frame) }
	.debug_str      0 : { *(.debug_str) }
	.debug_loc      0 : { *(.debug_loc) }
	.debug_macinfo  0 : { *(.debug_macinfo) }
  /* SGI/MIPS DWARF 2 extensions */
	.debug_weaknames 0 : { *(.debug_weaknames) }
	.debug_funcnames 0 : { *(.debug_funcnames) }
	.debug_typenames 0 : { *(.debug_typenames) }
	.debug_varnames  0 : { *(.debug_varnames) }
  /* DWARF 3 */
	.debug_pubtypes 0 : { *(.debug_pubtypes) }
	.debug_ranges   0 : { *(.debug_ranges) }
	.gnu.attributes 0 : { KEEP (*(.gnu.attributes)) }
	/DISCARD/ : { *(.note.GNU-stack) *(.gnu_debuglink) *(.gnu.lto_*) }
}
