#include "Rect.h"

bool_t Rect_overlap(Rect* rect0, Rect* rect1) {
    return rect0->pos.x < rect1->pos.x + rect1->size.x && rect0->pos.x + rect0->size.x > rect1->pos.x &&
    rect0->pos.y > rect1->pos.y + rect1->size.y && rect0->pos.y + rect0->size.y < rect1->pos.y;
}