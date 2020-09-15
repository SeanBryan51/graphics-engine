#include <stdlib.h>
#include <assert.h>

#include "maths/maths.h"

void test_vec2fAdd() {
    vec2f result;
    vec2f v1 = {1.0f, 2.0f};
    vec2f v2 = {1.0f, 1.0f};
    vec2f_add(&result, v1, v2);

    assert(result.x == 2.0f);
    assert(result.y == 3.0f);
}

void test_vec2fSub() {
    vec2f result;
    vec2f v1 = {1.0f, 2.0f};
    vec2f v2 = {1.0f, 1.0f};
    vec2f_subtract(&result, v1, v2);

    assert(result.x == 0.0f);
    assert(result.y == 1.0f);
}

void test_vec2fMult() {
    vec2f result;
    vec2f v1 = {1.0f, 2.0f};
    vec2f v2 = {1.0f, 1.0f};
    vec2f_multiply(&result, v1, v2);

    assert(result.x == 1.0f);
    assert(result.y == 2.0f);
}

void test_vec2fDiv() {
    vec2f result;
    vec2f v1 = {1.0f, 2.0f};
    vec2f v2 = {1.0f, 1.0f};
    vec2f_divide(&result, v1, v2);

    assert(result.x == 1.0f);
    assert(result.y == 2.0f);
}

void test_vec2fMagnitude() {
    vec2f v = {3.0f, 4.0f};
    assert(vec2f_magnitude(v) == 5.0f);
}

int main() {
    test_vec2fAdd();
    test_vec2fSub();
    test_vec2fMult();
    test_vec2fDiv();
    test_vec2fMagnitude();
    return EXIT_SUCCESS;
}