;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.6 #12539 (MINGW32)
;--------------------------------------------------------
	.module Test
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _gotogxy
	.globl _gprintf
	.globl _waitpad
	.globl _Test
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;src/Test.c:6: void Test()
;	---------------------------------
; Function Test
; ---------------------------------
_Test::
;src/Test.c:9: gotogxy(3,8); // set text start position
	ld	hl, #0x803
	push	hl
	call	_gotogxy
	pop	hl
;src/Test.c:10: gprintf("Press Start...");
	ld	de, #___str_0
	push	de
	call	_gprintf
	pop	hl
;src/Test.c:11: waitpad(J_START); // wait for start
	ld	a, #0x80
	push	af
	inc	sp
	call	_waitpad
	inc	sp
;src/Test.c:12: gotogxy(3,8); // reset text start position
	ld	hl, #0x803
	push	hl
	call	_gotogxy
	pop	hl
;src/Test.c:13: gprintf("              "); // clear message
	ld	de, #___str_1
	push	de
	call	_gprintf
	pop	hl
;src/Test.c:16: gotogxy(3,8); // set text start position
	ld	hl, #0x803
	push	hl
	call	_gotogxy
	pop	hl
;src/Test.c:17: gprintf("Lol!"); // print message
	ld	de, #___str_2
	push	de
	call	_gprintf
	pop	hl
;src/Test.c:18: }
	ret
___str_0:
	.ascii "Press Start..."
	.db 0x00
___str_1:
	.ascii "              "
	.db 0x00
___str_2:
	.ascii "Lol!"
	.db 0x00
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
