#include "Vector2.h"
#include "../../util/TypeDefs.h"

typedef struct {
    // leaving size as const and on top for memory conservation
    const Vector2i16 size;
    // position field signifies top-left corner. this makes drawing easier
    Vector2i16 pos;
} Rect;

extern bool_t Rect_overlap(Rect* rect0, Rect* rect1);