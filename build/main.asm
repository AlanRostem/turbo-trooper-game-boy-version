;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.6 #12539 (MINGW32)
;--------------------------------------------------------
	.module main
	.optsdcc -mgbz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _set_sprite_data
	.globl _Assets_TestTile
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
_Assets_TestTile::
	.ds 16
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
;..\src\main.c:6: int main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
;..\src\main.c:8: set_sprite_data(0, 1, Assets_TestTile);
	ld	de, #_Assets_TestTile
	push	de
	xor	a, a
	inc	a
	push	af
	call	_set_sprite_data
	add	sp, #4
;C:/gbdk/include/gb/gb.h:1326: shadow_OAM[nb].tile=tile;
	ld	hl, #(_shadow_OAM + 2)
	ld	(hl), #0x00
;C:/gbdk/include/gb/gb.h:1399: OAM_item_t * itm = &shadow_OAM[nb];
	ld	hl, #_shadow_OAM
;C:/gbdk/include/gb/gb.h:1400: itm->y=y, itm->x=x;
	ld	a, #0x4e
	ld	(hl+), a
	ld	(hl), #0x58
;..\src\main.c:11: SHOW_SPRITES;
	ldh	a, (_LCDC_REG + 0)
	or	a, #0x02
	ldh	(_LCDC_REG + 0), a
;..\src\main.c:12: return 0;
	ld	de, #0x0000
;..\src\main.c:13: }
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__Assets_TestTile:
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x91	; 145
	.db #0x91	; 145
	.db #0xff	; 255
	.db #0x91	; 145
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x89	; 137
	.db #0x89	; 137
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.area _CABS (ABS)
