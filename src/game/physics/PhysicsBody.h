#pragma once
#include "Rect.h"
#include "../../graphics/sprite/Sprite.h"
#include "../../graphics/sprite/MetaSprite.h"

extern const uint16_t GRAVITY;

typedef struct {
    Rect shape;
    Vector2i16 velocity;
    uint8_t gravity_slow_down;

    bool_t is_on_floor;
} PhysicsBody;

extern void PhysicsBody_process(PhysicsBody* body);
extern void PhysicsBody_process_with_gravity(PhysicsBody* body);

extern void PhysicsBody_process_x_collision(PhysicsBody* body);
extern void PhysicsBody_process_y_collision(PhysicsBody* body);