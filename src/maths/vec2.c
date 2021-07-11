#include <stdlib.h>

#include "maths.h"

// double implementation:

vec2 vec2_create(double x, double y) {
    vec2 new = {x, y};
    return new;
}

void vec2_add(vec2 *a, vec2 b, vec2 c) {
    a->x = b.x + c.x;
    a->y = b.y + c.y;
}

void vec2_subtract(vec2 *a, vec2 b, vec2 c) {
    a->x = b.x - c.x;
    a->y = b.y - c.y;
}

void vec2_multiply(vec2 *a, vec2 b, vec2 c) {
    a->x = b.x * c.x;
    a->y = b.y * c.y;
}

void vec2_divide(vec2 *a, vec2 b, vec2 c) {
    a->x = b.x / c.x;
    a->y = b.y / c.y;
}

double vec2_magnitude(vec2 v) {
    return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

// float implementation:

vec2f vec2f_create(float x, float y) {
    vec2f new = {x, y};
    return new;
}

void vec2f_add(vec2f *a, vec2f b, vec2f c) {
    a->x = b.x + c.x;
    a->y = b.y + c.y;
}

void vec2f_subtract(vec2f *a, vec2f b, vec2f c) {
    a->x = b.x - c.x;
    a->y = b.y - c.y;
}

void vec2f_multiply(vec2f *a, vec2f b, vec2f c) {
    a->x = b.x * c.x;
    a->y = b.y * c.y;
}

void vec2f_divide(vec2f *a, vec2f b, vec2f c) {
    a->x = b.x / c.x;
    a->y = b.y / c.y;
}

float vec2f_magnitude(vec2f v) {
    return sqrt(pow(v.x, 2) + pow(v.y, 2));
}