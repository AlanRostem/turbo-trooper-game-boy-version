#include "Rect.h"

bool_t Rect_overlap(Rect* a, Rect* b) {
    return  (a->pos.y + a->size.y) > b->pos.y
        &&  a->pos.y < (b->pos.y + b->size.y)
        &&  (a->pos.x + a->size.x) > b->pos.x
        &&  a->pos.x < (b->pos.x + b->size.x);
}