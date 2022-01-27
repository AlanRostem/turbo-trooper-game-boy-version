#pragma once
#include "Rect.h"

typedef struct {
    Rect shape;
    Vector2 velocity;
} PhysicsBody;

extern void PhysicsBody_update_with_gravity(PhysicsBody* body);