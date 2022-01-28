#pragma once
#include "Rect.h"

extern const uint16_t GRAVITY;

typedef struct {
    Rect shape;
    Vector2i16 velocity;
} PhysicsBody;

extern void PhysicsBody_process(PhysicsBody* body);
extern void PhysicsBody_process_with_gravity(PhysicsBody* body);

extern void PhysicsBody_process_x_collision(PhysicsBody* body);
extern void PhysicsBody_process_y_collision(PhysicsBody* body);

extern bool_t PhysicsBody_is_on_floor(PhysicsBody* body);