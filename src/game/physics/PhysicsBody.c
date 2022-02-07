#include <stdio.h>
#include "PhysicsBody.h"
#include "../../graphics/Graphics.h"
#include "../../system/memory/Memory.h"

#define GRAVITY 1
#define GRAVITY_SLOW_DOWN_FRAMES 4

#define TEST_FLOOR_MAX (160 - 4 * 8)
#define TEST_WALL_MIN 0

void PhysicsBody_process_with_gravity(PhysicsBody* body) {
    if (!body->is_on_floor)
        body->gravity_slow_down = (body->gravity_slow_down + 1) % GRAVITY_SLOW_DOWN_FRAMES;
    if (body->gravity_slow_down == 0)
        body->velocity.y += GRAVITY;
    PhysicsBody_process(body);
}

void PhysicsBody_process(PhysicsBody *body) {
    body->shape.pos.x += body->velocity.x;
    //PhysicsBody_process_x_collision(body);
    body->shape.pos.y += body->velocity.y;
    //PhysicsBody_process_y_collision(body);

    static int16_t i;
    static int16_t j;
    static int16_t xx;
    static int16_t yy;
    static uint8_t tile;
    static Rect tile_rect_test = {{TILE_SIZE, TILE_SIZE}};
    for (i = -1; i <= -1; i++) {
        for (j = -1; j <= -1; j++) {
            xx = body->shape.pos.x / TILE_SIZE + j;
            yy = body->shape.pos.y / TILE_SIZE + i;
            tile = Graphics_currently_shown_tile_map[yy * 3 + xx];
            if (tile > 0) {
                tile_rect_test.pos.x = xx * TILE_SIZE;
                tile_rect_test.pos.y = yy * TILE_SIZE;
                if (Rect_overlap(&body->shape, &tile_rect_test)) {
                    if (body->velocity.x > 0) {
                        body->shape.pos.x = tile_rect_test.pos.x - body->shape.size.x;
                        body->velocity.x = 0;
                        body->is_on_wall = TRUE;
                    } else if (body->velocity.x < 0) {
                        body->shape.pos.x = tile_rect_test.pos.x;
                        body->velocity.x = 0;
                        body->is_on_wall = TRUE;
                    }

                    if (body->velocity.y > 0) {
                        body->shape.pos.y = tile_rect_test.pos.y - body->shape.size.y;
                        body->velocity.y = 0;
                        body->is_on_floor = TRUE;

                    } else if (body->velocity.y < 0) {
                        body->shape.pos.y = tile_rect_test.pos.y;
                        body->velocity.y = 0;
                        body->is_on_ceiling = TRUE;
                    }
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