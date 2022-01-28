#include "Vector2.h"
#include "../../util/TypeDefs.h"

typedef struct {
    // position field signifies top-left corner. this makes drawing easier
    const Vector2i16 size;
    Vector2i16 pos;
} Rect;

extern bool_t Rect_overlap(Rect* rect0, Rect* rect1);