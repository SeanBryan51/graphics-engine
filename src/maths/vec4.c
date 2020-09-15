
#include <stdlib.h>
#include "maths.h"

Vec4 vec4_create(double x, double y, double z, double w) {
    Vec4 new = calloc(1, sizeof(vec4));
    new->x = x;
    new->y = y;
    new->z = z;
    new->w = w;
    return new;
}

void vec4_destroy(Vec4 v) {
    free(v);
}

void vec4_add(vec4 *a, vec4 b, vec4 c) {
    a->x = b.x + c.x;
    a->y = b.y + c.y;
    a->z = b.z + c.z;
    a->w = b.w + c.w;
}

void vec4_subtract(vec4 *a, vec4 b, vec4 c) {
    a->x = b.x - c.x;
    a->y = b.y - c.y;
    a->z = b.z - c.z;
    a->w = b.w - c.w;
}

void vec4_multiply(vec4 *a, vec4 b, vec4 c) {
    a->x = b.x * c.x;
    a->y = b.y * c.y;
    a->z = b.z * c.z;
    a->w = b.w * c.w;
}

void vec4_divide(vec4 *a, vec4 b, vec4 c) {
    a->x = b.x / c.x;
    a->y = b.y / c.y;
    a->z = b.z / c.z;
    a->w = b.w / c.w;
}


Vec4f vec4f_create(float x, float y, float z, float w) {
    Vec4f new = calloc(1, sizeof(vec4f));
    new->x = x;
    new->y = y;
    new->z = z;
    new->w = w;
    return new;
}

void vec4f_destroy(Vec4f v) {
    free(v);
}

void vec4f_add(vec4f *a, vec4f b, vec4f c) {
    a->x = b.x + c.x;
    a->y = b.y + c.y;
    a->z = b.z + c.z;
    a->w = b.w + c.w;
}

void vec4f_subtract(vec4f *a, vec4f b, vec4f c) {
    a->x = b.x - c.x;
    a->y = b.y - c.y;
    a->z = b.z - c.z;
    a->w = b.w - c.w;
}

void vec4f_multiply(vec4f *a, vec4f b, vec4f c) {
    a->x = b.x * c.x;
    a->y = b.y * c.y;
    a->z = b.z * c.z;
    a->w = b.w * c.w;
}

void vec4f_divide(vec4f *a, vec4f b, vec4f c) {
    a->x = b.x / c.x;
    a->y = b.y / c.y;
    a->z = b.z / c.z;
    a->w = b.w / c.w;
}