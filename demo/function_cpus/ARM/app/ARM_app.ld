
MEMORY
{
    /* HM3C1788 : 1024k ROM + 64k SRAM */
    /*------------------------------ */

	/* On-chip ROM is a readable (r), executable region (x) */
	/* On-chip SRAM is a readable (r), writable (w) and */
	/* executable region (x) */

	/* Main ROM region - 1024k for HM3C1788 */
	IROM (rx) : ORIGIN = 0x00100000, LENGTH = 114k
    IRAM0 (rwx) : ORIGIN = 0x00120000, LENGTH = 48k
	IRAM1 (rx) : ORIGIN = 0x00100000, LENGTH = 114k
}

/* SECTION command : Define mapping of input sections */
/* into output sections. */

SECTIONS
{
	/******************************************/
	/* code section */

        /* "normal" code */
	
	.text :
	{
		KEEP(*(.isr_vector .isr_vector.*))
		*(.text .text.*)
		*(.gnu.linkonce.t.*)
		*(.glue_7)
		*(.glue_7t)
		*(.gcc_except_table)
		*(.rodata .rodata*)

		. = ALIGN(4);
        __label_start__ = .;
		KEEP(*(.label*))
		__label_end__ = .;

		*(.gnu.linkonce.r.*)
	} >IRAM1 AT>IROM

	/******************************************/
	/* .ctors .dtors are used for c++ constructors/destructors */
	.ctors :
	{
		. = ALIGN(4);
		PROVIDE(__ctors_start = .);
		KEEP(*(SORT(.ctors.*)))
		KEEP(*(.ctors))
		PROVIDE(__ctors_end = .);
	} >IRAM1 AT>IROM

	.dtors :
	{
		. = ALIGN(4);
		PROVIDE(__dtors_start = .);
		KEEP(*(SORT(.dtors.*)))
		KEEP(*(.dtors))
		PROVIDE(__dtors_end = .);

		. = ALIGN(4);
		/* End Of .text section */
		_etext = .;
                _sifastcode = .;
	} >IRAM1 AT>IROM

	.fastcode :
	{
		. = ALIGN (4);
		_sfastcode = . ;

		*(.glue_7t) *(.glue_7)
		*(.fastcode)
		
		/* add other modules here ... */

		. = ALIGN (4);
		_efastcode = . ;
		_sidata = .;
	} >IRAM0 AT>IROM

    /******************************************/
	/* data section */
	.data :
  	{
        	_sidata = LOADADDR (.data);
  		. = ALIGN(4);
		_sdata = .;

		*(vtable vtable.*)
		*(.data .data.*)
		*(.gnu.linkonce.d*)

		. = ALIGN(4);
		_edata = . ;
	} >IRAM0 AT>IROM

	/******************************************/
	/* For no-init variables section */
	.bss (NOLOAD) :
	{
		. = ALIGN(4);
		_sbss = . ;

		*(.bss .bss.*)
		*(.gnu.linkonce.b*)
		*(COMMON)

		. = ALIGN(4);
		_ebss = . ;
	} >IRAM0

	. = ALIGN(4);
	.heaparea (NOLOAD) :
  	{
	    . = ALIGN(8);
	    _sheap = .;

		*(.heaparea .heaparea.*)

		. = ALIGN(8);
		_eheap = .;

		. = ALIGN(4);
		_end = . ;
		PROVIDE (end = .);

  	} > IRAM0

	/******************************************/
	/* For stack section */
  	.stackarea (NOLOAD) :
  	{
	    . = ALIGN(8);
	    _sstack = .;

		*(.stackarea .stackarea.*)

		. = ALIGN(8);
		_estack = .;

		. = ALIGN(4);
		_end = . ;
		PROVIDE (end = .);

  	} > IRAM0

	__StackTop = ORIGIN(IRAM0) + LENGTH(IRAM0);
	__StackLimit = __StackTop - SIZEOF(.stackarea);
	PROVIDE(__stack = __StackTop);

	/******************************************/
	/* Stabs debugging sections.  */
	.stab          0 : { *(.stab) }
	.stabstr       0 : { *(.stabstr) }
	.stab.excl     0 : { *(.stab.excl) }
	.stab.exclstr  0 : { *(.stab.exclstr) }
	.stab.index    0 : { *(.stab.index) }
	.stab.indexstr 0 : { *(.stab.indexstr) }
	/* .comment       0 : { *(.comment) } */
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
}
