#include "PhysicsBody.h"

#define GRAVITY 1
#define GRAVITY_SLOW_DOWN_FRAMES 2

const uint16_t TEST_FLOOR_MAX = 160;

void PhysicsBody_process_with_gravity(PhysicsBody* body) {
    if (!body->is_on_floor)
        body->gravity_slow_down = (body->gravity_slow_down + 1) % GRAVITY_SLOW_DOWN_FRAMES;
    if (body->gravity_slow_down == 0)
        body->velocity.y += GRAVITY;
    PhysicsBody_process(body);
}

void PhysicsBody_process(PhysicsBody *body) {
    body->shape.pos.x += body->velocity.x;
    PhysicsBody_process_x_collision(body);

    body->shape.pos.y += body->velocity.y;
    PhysicsBody_process_y_collision(body);
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

}