#include <stdio.h>
#include <stdlib.h>
#include "PhysicsBody.h"
#include "../../graphics/Graphics.h"
#include "../../system/memory/Memory.h"

#define GRAVITY 1
#define GRAVITY_SLOW_DOWN_FRAMES 4

#define TEST_FLOOR_MAX (160 - 4 * 8)
#define TEST_WALL_MIN 0

void PhysicsBody_process_with_gravity(PhysicsBody *body) {
    if (!body->is_on_floor)
        body->gravity_slow_down = (body->gravity_slow_down + 1) % GRAVITY_SLOW_DOWN_FRAMES;
    if (body->gravity_slow_down == 0)
        body->velocity.y += GRAVITY;
    PhysicsBody_process(body);
}

void PhysicsBody_process(PhysicsBody *body) {
    //body->old_pos.x = body->shape.pos.x;
    //body->old_pos.y = body->shape.pos.y;

    body->shape.pos.x += body->velocity.x;
    // PhysicsBody_process_x_collision(body);
    body->shape.pos.y += body->velocity.y;
    // PhysicsBody_process_y_collision(body);
    body->is_on_floor = FALSE;
    body->is_on_wall = FALSE;
    body->is_on_ceiling = FALSE;

    static int16_t tile_coord_x;
    static int16_t tile_coord_y;

    static int16_t i;
    static int16_t j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            tile_coord_x = (body->shape.pos.x / TILE_SIZE) + j;
            tile_coord_y = (body->shape.pos.y / TILE_SIZE) + i;
            if (!(tile_coord_x < 0 || tile_coord_x >= TILE_MAP_WIDTH || tile_coord_y < 0 || tile_coord_y >= TILE_MAP_HEIGHT) &&
                Graphics_currently_shown_tile_map[tile_coord_y * TILE_MAP_WIDTH + tile_coord_x] > 0 &&
                Rect_overlap_tile(&body->shape, tile_coord_x, tile_coord_y))
            {
                if (body->velocity.x > 0 && body->shape.pos.x + body->shape.size.x > tile_coord_x * TILE_SIZE)// && body->old_pos.x + body->shape.size.x <= tile_rect_test.pos.x)
                {
                    body->is_on_wall = TRUE;
                    body->velocity.x = 0;
                    body->shape.pos.x = tile_coord_x * TILE_SIZE - body->shape.size.x;
                }
                else if (body->velocity.x < 0 && body->shape.pos.x < (tile_coord_x + 1) * TILE_SIZE)// && body->old_pos.x >= tile_rect_test.pos.x + TILE_SIZE)
                {
                    body->is_on_wall = TRUE;
                    body->velocity.x = 0;
                    body->shape.pos.x = (tile_coord_x + 1) * TILE_SIZE;
                }

                if (body->velocity.y > 0 && body->shape.pos.y + body->shape.size.y > tile_coord_y * TILE_SIZE)// && body->old_pos.y + body->shape.size.y <= tile_rect_test.pos.y)
                {
                    body->is_on_floor = TRUE;
                    body->velocity.y = 0;
                    body->shape.pos.y = tile_coord_y * TILE_SIZE - body->shape.size.y;
                } else if (body->velocity.y < 0 && body->shape.pos.y < (tile_coord_y + 1) * TILE_SIZE)// && body->old_pos.y >= tile_rect_test.pos.y + TILE_SIZE)
                {
                    body->is_on_ceiling = TRUE;
                    body->velocity.y = 0;
                    body->shape.pos.y = (tile_coord_y + 1) * TILE_SIZE;
                }
            }
        }
    }
}

void PhysicsBody_process_y_collision(PhysicsBody *body) {
    body->is_on_floor = body->shape.pos.y + body->shape.size.y > TEST_FLOOR_MAX;
    if (body->is_on_floor) {
        body->shape.pos.y = TEST_FLOOR_MAX - body->shape.size.y;
        body->velocity.y = 0;
        body->gravity_slow_down = 0;
    }
}

void PhysicsBody_process_x_collision(PhysicsBody *body) {
    if (body->shape.pos.x < TEST_WALL_MIN) {
        body->shape.pos.x = TEST_WALL_MIN;
        body->velocity.x = 0;
        body->is_on_wall = TRUE;
    }
}