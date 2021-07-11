#include <stdlib.h>

#include "maths.h"

// double implementation:

vec3 vec3_create(double x, double y, double z) {
    vec3 new = {x, y, z};
    return new;
}

void vec3_add(vec3 *a, vec3 b, vec3 c) {
    a->x = b.x + c.x;
    a->y = b.y + c.y;
    a->z = b.z + c.z;
}

void vec3_subtract(vec3 *a, vec3 b, vec3 c) {
    a->x = b.x - c.x;
    a->y = b.y - c.y;
    a->z = b.z - c.z;
}

void vec3_multiply(vec3 *a, vec3 b, vec3 c) {
    a->x = b.x * c.x;
    a->y = b.y * c.y;
    a->z = b.z * c.z;
}

void vec3_divide(vec3 *a, vec3 b, vec3 c) {
    a->x = b.x / c.x;
    a->y = b.y / c.y;
    a->z = b.z / c.z;
}

double vec3_magnitude(vec3 v) {
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

double vec3_dot(vec3 a, vec3 b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

void vec3_cross(vec3 *a, vec3 b, vec3 c) {
    a->x = b.y*c.z - c.y*b.z;
    a->y = b.z*c.x - c.z*b.x;
    a->z = b.x*c.y - c.x*b.y;
}

// float implementation:

vec3f vec3f_create(float x, float y, float z) {
    vec3f new = {x, y, z};
    return new;
}

void vec3f_add(vec3f *a, vec3f b, vec3f c) {
    a->x = b.x + c.x;
    a->y = b.y + c.y;
    a->z = b.z + c.z;
}

void vec3f_subtract(vec3f *a, vec3f b, vec3f c) {
    a->x = b.x - c.x;
    a->y = b.y - c.y;
    a->z = b.z - c.z;
}

void vec3f_multiply(vec3f *a, vec3f b, vec3f c) {
    a->x = b.x * c.x;
    a->y = b.y * c.y;
    a->z = b.z * c.z;
}

void vec3f_divide(vec3f *a, vec3f b, vec3f c) {
    a->x = b.x / c.x;
    a->y = b.y / c.y;
    a->z = b.z / c.z;
}

float vec3f_magnitude(vec3f v) {
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

float ve3f_dot(vec3f a, vec3f b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

void vec3f_cross(vec3f *a, vec3f b, vec3f c) {
    a->x = b.y*c.z - c.y*b.z;
    a->y = b.z*c.x - c.z*b.x;
    a->z = b.x*c.y - c.x*b.y;
}