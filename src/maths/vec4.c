
#include <stdlib.h>
#include "maths.h"

vec4 vec4_create(double x, double y, double z, double w) {
    vec4 new = {x, y, z, w};
    return new;
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


vec4f vec4f_create(float x, float y, float z, float w) {
    vec4f new = {x, y, z, w};
    return new;
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

void  vec4f_show(vec4f v) {
    printf("[%f, %f, %f, %f]\n", v.x, v.y, v.z, v.w);
}