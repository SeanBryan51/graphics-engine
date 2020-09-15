#include <stdlib.h>
#include <assert.h>

#include "maths/maths.h"


void test_vec3fAdd() {
    vec3f result;
    vec3f v1 = {1.0f, 2.0f, 3.0};
    vec3f v2 = {1.0f, 1.0f, 1.0};
    vec3f_add(&result, v1, v2);

    assert(result.x == 2.0f);
    assert(result.y == 3.0f);
    assert(result.z == 4.0f);
}

void test_vec3fSub() {
    vec3f result;
    vec3f v1 = {1.0f, 2.0f, 3.0};
    vec3f v2 = {1.0f, 1.0f, 1.0};
    vec3f_subtract(&result, v1, v2);

    assert(result.x == 0.0f);
    assert(result.y == 1.0f);
    assert(result.z == 2.0f);
}

void test_vec3fMult() {
    vec3f result;
    vec3f v1 = {1.0f, 2.0f, 3.0};
    vec3f v2 = {1.0f, 1.0f, 1.0};
    vec3f_multiply(&result, v1, v2);

    assert(result.x == 1.0f);
    assert(result.y == 2.0f);
    assert(result.z == 3.0f);
}

void test_vec3fDiv() {
    vec3f result;
    vec3f v1 = {1.0f, 2.0f, 3.0};
    vec3f v2 = {1.0f, 1.0f, 1.0};
    vec3f_divide(&result, v1, v2);

    assert(result.x == 1.0f);
    assert(result.y == 2.0f);
    assert(result.z == 3.0f);
}

void test_vec3fCross() {

    // success case: basis vectors
    vec3f result;
    vec3f v1 = {1.0f, 0.0f, 0.0f};
    vec3f v2 = {0.0f, 1.0f, 0.0f};

    vec3f_cross(&result, v1, v2);

    assert(result.x == 0.0f);
    assert(result.y == 0.0f);
    assert(result.z == 1.0f);
}

void test_vec3fDot() {
    vec3f v1 = {1.0f, 2.0f, 3.0};
    vec3f v2 = {1.0f, 1.0f, 1.0};
    assert(ve3f_dot(v1, v2) == 6.0f);
}

void test_vec3fMagnitude() {
    vec3f v = {1.0f, 0.0f, 0.0f};
    assert(vec3f_magnitude(v) == 1.0f);
}

int main() {
    test_vec3fAdd();
    test_vec3fSub();
    test_vec3fMult();
    test_vec3fDiv();
    test_vec3fCross();
    test_vec3fDot();
    test_vec3fMagnitude();
    return EXIT_SUCCESS;
}