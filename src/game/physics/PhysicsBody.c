#include "PhysicsBody.h"

const uint16_t GRAVITY = 1;

const uint16_t TEST_FLOOR_MAX = 160;

void PhysicsBody_process_with_gravity(PhysicsBody* body) {
    body->velocity.y += GRAVITY;
    PhysicsBody_process(body);
}

void PhysicsBody_process(PhysicsBody *body) {
    body->shape.pos.x += body->velocity.x;
    PhysicsBody_process_x_collision(body);

    body->shape.pos.y += body->velocity.y;
    PhysicsBody_process_y_collision(body);
}

bool_t PhysicsBody_is_on_floor(PhysicsBody *body) {
    return body->shape.pos.y + body->shape.size.y > TEST_FLOOR_MAX;
}

void PhysicsBody_process_y_collision(PhysicsBody *body) {
    int16_t is_on_floor = PhysicsBody_is_on_floor(body);
    body->shape.pos.y = (!is_on_floor) * body->shape.pos.y + is_on_floor * (TEST_FLOOR_MAX - body->shape.size.y);
    body->velocity.y *= (!is_on_floor);
}

void PhysicsBody_process_x_collision(PhysicsBody *body) {

}
