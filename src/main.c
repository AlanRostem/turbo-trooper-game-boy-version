#include <stdio.h>

#include "assets/sprites/TileSet.h"
#include "assets/sprites/PlayerTestSprite.h"
#include "assets/tile_maps/TestTileMap.h"

#define TILE_MAP_WIDTH 48 // This is a test value for now
#define TILE_MAP_HEIGHT 16
#define MAX_RENDERED_TILE_MAP_WIDTH 32
#define MAX_ON_SCREEN_TILE_MAP_WIDTH 20
#define OUT_OF_SCREEN_RENDERED_TILE_WIDTH_HALF 6
#define OUT_OF_SCREEN_RENDERED_TILE_WIDTH 12
#define TILE_SIZE 8

#define PLAYER_BODY_WIDTH TILE_SIZE
#define PLAYER_BODY_HEIGHT TILE_SIZE

#define PLAYER_SPRITE_FRAME_COUNT (22)

enum
{
    OAM_SPRITE_ID_PLAYER_TOP_LEFT  = 0,
    OAM_SPRITE_ID_PLAYER_TOP_RIGHT,
    OAM_SPRITE_ID_PLAYER_BOTTOM_LEFT,
    OAM_SPRITE_ID_PLAYER_BOTTOM_RIGHT,
    __OAM_SPRITE_MAX__ = 40,
};

typedef struct
{
    fixed position_x;
    fixed position_y;
    uint8_t hardware_sprite_number;
} PlayerData;

// GBDK suggests assigning variables to RAM using static.
// The best solution is to have all variables in a static struct.
typedef struct
{
    // input states
    uint8_t joypad_input_result;

    // vram states
    uint8_t background_tile_offset_x;
    uint8_t vram_sprite_allocation_count;

    // player entity logic
    PlayerData player_data;
} WorkRAM;

static WorkRAM work_ram;

int main() {

    work_ram.background_tile_offset_x = 0; // OUT_OF_SCREEN_RENDERED_TILE_WIDTH_HALF;
    work_ram.vram_sprite_allocation_count = 0;

    // Write tile set to VRAM
    set_bkg_data(
        0, 
        38, 
        TileSet);

    // Write player sprite to VRAM
    set_sprite_data(
        0, 
        PLAYER_SPRITE_FRAME_COUNT, 
        PlayerTestSprite);

    set_sprite_tile(OAM_SPRITE_ID_PLAYER_TOP_LEFT, 0);
    set_sprite_tile(OAM_SPRITE_ID_PLAYER_TOP_RIGHT, 1);
    set_sprite_tile(OAM_SPRITE_ID_PLAYER_BOTTOM_LEFT, 2);
    set_sprite_tile(OAM_SPRITE_ID_PLAYER_BOTTOM_RIGHT, 3);

    work_ram.player_data.position_x.h = 80;
    work_ram.player_data.position_y.h = 80;
    
    move_sprite(
        OAM_SPRITE_ID_PLAYER_TOP_LEFT, 
        work_ram.player_data.position_x.h, 
        work_ram.player_data.position_y.h);
    
    move_sprite(
        OAM_SPRITE_ID_PLAYER_TOP_RIGHT, 
        work_ram.player_data.position_x.h + TILE_SIZE, 
        work_ram.player_data.position_y.h);

    move_sprite(
        OAM_SPRITE_ID_PLAYER_BOTTOM_LEFT, 
        work_ram.player_data.position_x.h, 
        work_ram.player_data.position_y.h + TILE_SIZE);

    move_sprite(
        OAM_SPRITE_ID_PLAYER_BOTTOM_RIGHT, 
        work_ram.player_data.position_x.h + TILE_SIZE, 
        work_ram.player_data.position_y.h + TILE_SIZE);

    // Set background tiles
    set_bkg_submap(work_ram.background_tile_offset_x, 0, 
        MAX_RENDERED_TILE_MAP_WIDTH, 
        TILE_MAP_HEIGHT, 
        TestTileMap, 
        TILE_MAP_WIDTH);
    move_bkg(work_ram.background_tile_offset_x * TILE_SIZE, 0);

    // Enable bg and sprites
    SHOW_SPRITES;
    SHOW_BKG;

    // Game loop
    while(1) {
        wait_vbl_done();

        // This is only going to be assigned once
        work_ram.joypad_input_result = joypad();

    }

    return 0;
}