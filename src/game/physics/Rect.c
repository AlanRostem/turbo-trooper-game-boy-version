#include "Rect.h"

bool_t Rect_overlap(Rect* a, Rect* b) {
    return  (a->pos.y + a->size.y) > b->pos.y
        &&  a->pos.y < (b->pos.y + b->size.y)
        &&  (a->pos.x + a->size.x) > b->pos.x
        &&  a->pos.x < (b->pos.x + b->size.x);
}

bool_t Rect_overlap_tile(Rect *rect, int16_t tile_x, int16_t tile_y) {
    return  (rect->pos.y + rect->size.y) > tile_y * TILE_SIZE
            && rect->pos.y < ((tile_y + 1) * TILE_SIZE)
            && (rect->pos.x + rect->size.x) > tile_x * TILE_SIZE
            && rect->pos.x < ((tile_x + 1) * TILE_SIZE);
}
