#include <stdlib.h>
#include <assert.h>

#include "maths/maths.h"

void test_vec4fAdd() {
    vec4f result;
    vec4f v1 = {1.0f, 2.0f, 3.0, 4.0};
    vec4f v2 = {1.0f, 1.0f, 1.0, 1.0};
    vec4f_add(&result, v1, v2);

    assert(result.x == 2.0f);
    assert(result.y == 3.0f);
    assert(result.z == 4.0f);
    assert(result.w == 5.0f);
}

void test_vec4fSub() {
    vec4f result;
    vec4f v1 = {1.0f, 2.0f, 3.0, 4.0};
    vec4f v2 = {1.0f, 1.0f, 1.0, 1.0};
    vec4f_subtract(&result, v1, v2);

    assert(result.x == 0.0f);
    assert(result.y == 1.0f);
    assert(result.z == 2.0f);
    assert(result.w == 3.0f);
}

void test_vec4fMult() {
    vec4f result;
    vec4f v1 = {1.0f, 2.0f, 3.0, 4.0};
    vec4f v2 = {1.0f, 1.0f, 1.0, 1.0};
    vec4f_multiply(&result, v1, v2);

    assert(result.x == 1.0f);
    assert(result.y == 2.0f);
    assert(result.z == 3.0f);
    assert(result.w == 4.0f);
}

void test_vec4fDiv() {
    vec4f result;
    vec4f v1 = {1.0f, 2.0f, 3.0, 4.0};
    vec4f v2 = {1.0f, 1.0f, 1.0, 1.0};
    vec4f_divide(&result, v1, v2);

    assert(result.x == 1.0f);
    assert(result.y == 2.0f);
    assert(result.z == 3.0f);
    assert(result.w == 4.0f);
}

int main() {
    test_vec4fAdd();
    test_vec4fSub();
    test_vec4fMult();
    test_vec4fDiv();
    return EXIT_SUCCESS;
}