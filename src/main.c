#include <stdio.h>

#include "assets/sprites/TileSet.h"
#include "assets/sprites/PlayerTestSprite.h"
// #include "assets/sprites/RectTestSprite.h"
#include "assets/tile_maps/TestTileMap.h"

#define TILE_MAP_WIDTH (48) // This is a test value for now
#define TILE_MAP_HEIGHT (16)
#define MAX_RENDERED_TILE_MAP_WIDTH (32)
#define MAX_ON_SCREEN_TILE_MAP_WIDTH (20)
#define OUT_OF_SCREEN_RENDERED_TILE_WIDTH_HALF (6)
#define OUT_OF_SCREEN_RENDERED_TILE_WIDTH (12)
#define TILE_SIZE (8)

#define PLAYER_BODY_WIDTH TILE_SIZE
#define PLAYER_BODY_HEIGHT TILE_SIZE

#define PLAYER_SPRITE_FRAME_COUNT (22)

#define PHYSICS_AABB_POOL_MAX_COUNT (12)

#define PLAYER_PHYSICS_AABB_INDEX (0)

// Bitshift equivalent to (x / 8)
#define PIXEL_TO_TILE(x) (x >> 3)

#define TILE_TO_PIXEL(x) (x << 3)

#define TILE_TO_IDX(x, y) (y * TILE_MAP_WIDTH + x)

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
    fixed x;
    fixed y;
} Vec2Fixed;

typedef struct
{
    bool_t is_colliding;
    uint8_t extents_x;
    uint8_t extents_y;
    Vec2Fixed position;
    Vec2Fixed velocity;
} PhysicsAABB;

typedef struct
{
    // Test for now
    unsigned char state;
} PlayerData;

/// Union which stores function arguments. Use this in place of 
/// stack variables and/or function parameters. GBDK recommends
/// all variables be stored in Work RAM instead pushing and 
/// popping them on the stack every frame. 
typedef union
{
    struct
    {
        uint8_t sprite_number_start;
        uint8_t x;
        uint8_t y;
    } move_meta_sprite_2x2;
} FuncArgs;

/// Union which stores local function variables. Use this in place of 
/// stack variables. GBDK recommends all variables be stored in Work RAM instead pushing and 
/// popping them on the stack every frame. 
typedef union
{
    struct
    {
        uint8_t tile_x;
        uint8_t tile_y;
        uint8_t tile_value;
        uint16_t index;
    } physics_aabb_update;
} FuncStates;

// GBDK suggests assigning variables to RAM using static.
// The best solution is to have all variables in a static struct.
typedef struct
{
    // 
    FuncArgs func_args;
    FuncStates func_states;

    uint8_t idx8bit;
    uint16_t idx16bit;

    // input states
    uint8_t joypad_input_result;

    // vram states
    uint8_t background_tile_offset_x;
    uint8_t vram_sprite_allocation_count;
    uint8_t* current_tilemap_ptr;

    // player entity logic
    PlayerData player_data;
    
    // physics
    uint8_t physics_aabb_active_count;
    PhysicsAABB physics_aabb_pool[PHYSICS_AABB_POOL_MAX_COUNT];

    
    uint8_t physics_tilemap[MAX_RENDERED_TILE_MAP_WIDTH * TILE_MAP_HEIGHT];
} WorkRAM;

static uint16_t i = 0;
static uint16_t j = 0;
static WorkRAM work_ram;

inline void move_meta_sprite_2x2(void)
{
    // Must be done to correctly align the sprite
    work_ram.func_args.move_meta_sprite_2x2.x += 8;
    work_ram.func_args.move_meta_sprite_2x2.y += 16;

    move_sprite(
        work_ram.func_args.move_meta_sprite_2x2.sprite_number_start,
        work_ram.func_args.move_meta_sprite_2x2.x, 
        work_ram.func_args.move_meta_sprite_2x2.y);

    move_sprite(
        work_ram.func_args.move_meta_sprite_2x2.sprite_number_start + 1, 
        work_ram.func_args.move_meta_sprite_2x2.x + TILE_SIZE, 
        work_ram.func_args.move_meta_sprite_2x2.y);

    move_sprite(
        work_ram.func_args.move_meta_sprite_2x2.sprite_number_start + 2, 
        work_ram.func_args.move_meta_sprite_2x2.x, 
        work_ram.func_args.move_meta_sprite_2x2.y + TILE_SIZE);

    move_sprite(
        work_ram.func_args.move_meta_sprite_2x2.sprite_number_start + 3, 
        work_ram.func_args.move_meta_sprite_2x2.x + TILE_SIZE, 
        work_ram.func_args.move_meta_sprite_2x2.y + TILE_SIZE);
}

int main(void) {

    work_ram.background_tile_offset_x = 0; // OUT_OF_SCREEN_RENDERED_TILE_WIDTH_HALF;
    work_ram.vram_sprite_allocation_count = 0;
    work_ram.current_tilemap_ptr = TestTileMap;

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

    // Player sprite frame set
    set_sprite_tile(OAM_SPRITE_ID_PLAYER_TOP_LEFT, 0);
    set_sprite_tile(OAM_SPRITE_ID_PLAYER_TOP_RIGHT, 1);
    set_sprite_tile(OAM_SPRITE_ID_PLAYER_BOTTOM_LEFT, 2);
    set_sprite_tile(OAM_SPRITE_ID_PLAYER_BOTTOM_RIGHT, 3);

    // Move player AABB
    work_ram.physics_aabb_active_count = 1;
    PhysicsAABB* player_aabb = &work_ram.physics_aabb_pool[PLAYER_PHYSICS_AABB_INDEX];

    player_aabb->position.x.h = 80;
    player_aabb->position.y.h = 80;

    // Copy the tile map to Work RAM
    // TODO: no stack

#define region_w            MAX_RENDERED_TILE_MAP_WIDTH
#define region_h            TILE_MAP_HEIGHT
#define original_rom_map_w  TILE_MAP_WIDTH
    i = 0;
    for (; i < region_h; i++)
    {
        j = 0;
        for (; j < region_w; j++)
        {
            // BUG: values are not being set correctly here.
            work_ram.physics_tilemap[i * region_w + j] = work_ram.current_tilemap_ptr[i * original_rom_map_w + j];
        }
    }

    // Set background tiles
    set_bkg_submap(0, 0, 
        MAX_RENDERED_TILE_MAP_WIDTH, 
        TILE_MAP_HEIGHT, 
        work_ram.physics_tilemap, 
        MAX_RENDERED_TILE_MAP_WIDTH);
    
    move_bkg(work_ram.background_tile_offset_x * TILE_SIZE, 0);

    // Enable bg and sprites
    SHOW_SPRITES;
    SHOW_BKG;

    // Game loop
    while(1) {
        vsync();

        // This is only going to be assigned once
        work_ram.joypad_input_result = joypad();

        // Player input
#define SPEED (1)
        player_aabb->velocity.x.h = 0;
        if (work_ram.joypad_input_result & J_LEFT)
        {
            player_aabb->velocity.x.h = -SPEED;
        }

        if (work_ram.joypad_input_result & J_RIGHT)
        {
            player_aabb->velocity.x.h = SPEED;
        }
        
        player_aabb->velocity.y.h = 0;
        if (work_ram.joypad_input_result & J_UP)
        {
            player_aabb->velocity.y.h = -SPEED;
        }

        if (work_ram.joypad_input_result & J_DOWN)
        {
            player_aabb->velocity.y.h = SPEED;
        }

        // Physics AABB update
        PhysicsAABB* aabb = work_ram.physics_aabb_pool;
        static uint8_t i = 0;
        for (work_ram.idx8bit = 0; work_ram.idx8bit < work_ram.physics_aabb_active_count; work_ram.idx8bit++)
        {
            // Movement
            aabb->position.x.h += aabb->velocity.x.h;
            aabb->position.y.h += aabb->velocity.y.h;

            work_ram.func_states.physics_aabb_update.tile_x = PIXEL_TO_TILE(aabb->position.x.h);
            work_ram.func_states.physics_aabb_update.tile_y = PIXEL_TO_TILE(aabb->position.y.h);

            work_ram.func_states.physics_aabb_update.tile_value = work_ram.physics_tilemap[
                work_ram.func_states.physics_aabb_update.tile_y * region_w +
                work_ram.func_states.physics_aabb_update.tile_x];
            aabb->is_colliding = (work_ram.func_states.physics_aabb_update.tile_value != 0);
            aabb++; // Performant iterator for structs
        }

        // Player sprite movement
        // work_ram.func_args.move_meta_sprite_2x2.sprite_number_start = OAM_SPRITE_ID_PLAYER_TOP_LEFT;
        // work_ram.func_args.move_meta_sprite_2x2.x = player_aabb->position.x.h;
        // work_ram.func_args.move_meta_sprite_2x2.y = player_aabb->position.y.h;
        // move_meta_sprite_2x2();

        move_sprite(
            player_aabb->is_colliding ? OAM_SPRITE_ID_PLAYER_BOTTOM_LEFT : OAM_SPRITE_ID_PLAYER_TOP_LEFT, 
            player_aabb->position.x.h + 8, 
            player_aabb->position.y.h + 16);
        
        move_sprite(
            player_aabb->is_colliding ? OAM_SPRITE_ID_PLAYER_TOP_LEFT : OAM_SPRITE_ID_PLAYER_BOTTOM_LEFT, 
            0, 
            0);
    }

    return 0;
}