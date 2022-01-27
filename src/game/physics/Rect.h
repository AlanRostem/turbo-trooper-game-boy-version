#include "Vector2.h"
#include "../../util/TypeDefs.h"

typedef struct {
    // position field signifies top-left corner. this makes drawing easier
    Vector2 pos;
    Vector2 size;
} Rect;

extern bool_t Rect_overlap(Rect* rect0, Rect* rect1);