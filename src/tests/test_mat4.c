#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "maths/maths.h"

void test_mat4fMultiply() {
    
    // success case: identity
    mat4f identity = mat4f_identity();
    mat4f result = mat4f_multiply(identity, identity);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                assert(result.elements[i + j * 4] == 1.0f);
            } else {
                assert(result.elements[i + j * 4] == 0.0f);
            }
        }
    }
}

void test_mat4fUnion() {

    mat4f matrix = mat4f_identity();
    vec4f col0, col1, col2, col3;
    col0 = matrix.columns[0];
    col1 = matrix.columns[1];
    col2 = matrix.columns[2];
    col3 = matrix.columns[3];

    assert(col0.x == 1.0f);
    assert(col0.y == 0.0f);
    assert(col0.z == 0.0f);
    assert(col0.w == 0.0f);

    assert(col1.x == 0.0f);
    assert(col1.y == 1.0f);
    assert(col1.z == 0.0f);
    assert(col1.w == 0.0f);

    assert(col2.x == 0.0f);
    assert(col2.y == 0.0f);
    assert(col2.z == 1.0f);
    assert(col2.w == 0.0f);

    assert(col3.x == 0.0f);
    assert(col3.y == 0.0f);
    assert(col3.z == 0.0f);
    assert(col3.w == 1.0f);
}

void test_mat4fApply() {

    // success case: identity
    mat4f identity = mat4f_identity();
    vec4f result = mat4f_apply(identity, vec4f_create(1.0f, 2.0f, 3.0f, 4.0f));
    assert(result.x == 1.0f && result.y == 2.0f);
    assert(result.z == 3.0f && result.w == 4.0f);

    // success case: translation
    mat4f translation = mat4f_translation(vec3f_create(1, 0, 0));
    result = mat4f_apply(translation, vec4f_create(1.0f, 2.0f, 3.0f, 1.0f));

    assert(result.x == 2.0f && result.y == 2.0f);
    assert(result.z == 3.0f && result.w == 1.0f);
}

int main() {
    test_mat4fMultiply();
    test_mat4fUnion();
    test_mat4fApply();
    return EXIT_SUCCESS;
}