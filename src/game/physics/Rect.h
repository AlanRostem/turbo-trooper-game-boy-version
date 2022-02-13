#include "Vector2.h"
#include "../../util/TypeDefs.h"

#define RECT_OVERLAP(a, b) (((a).pos.y + (a).size.y) > (b).pos.y\
&&  (a).pos.y < ((b).pos.y + (b).size.y)\
&&  ((a).pos.x + (a).size.x) > (b).pos.x\
&&  (a).pos.x < ((b).pos.x + (b).size.x))\

typedef struct {
    // leaving size as const and on top for memory conservation
    Vector2i16 size;
    // position field signifies top-left corner. this makes drawing easier
    Vector2i16 pos;
} Rect;

extern bool_t Rect_overlap(Rect* a, Rect* b);