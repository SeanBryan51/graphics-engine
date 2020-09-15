
#include <stdlib.h>
#include "maths.h"

mat4f mat4f_create(float diagonal) {
    mat4f new = calloc(1, sizeof(union mat4f));
    new->elements[0 + 0 * 4] = diagonal;
    new->elements[1 + 1 * 4] = diagonal;
    new->elements[2 + 2 * 4] = diagonal;
    new->elements[3 + 3 * 4] = diagonal;
    return new;
}

void mat4f_destroy(mat4f m) {
    free(m);
}

mat4f mat4f_identity() {
    return mat4f_create(1.0f);
}

mat4f mat4f_orthographic(float left, float right, float top, float bottom , float near, float far) {
    mat4f result = mat4f_create(1.0f);

    result->elements[0 + 0 * 4] = 2.0f / (right - left);
    result->elements[1 + 1 * 4] = 2.0f / (top - bottom);
    result->elements[2 + 2 * 4] = 2.0f / (near - far);

    result->elements[0 + 3 * 4] = (left + right) / (left - right);
    result->elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
    result->elements[2 + 3 * 4] = (far + near) / (far - near);

    return result;
}

mat4f mat4f_perspective(float fov, float aspectRatio, float near, float far) {
    mat4f result = mat4f_create(1.0f);
    
    // convert to radians:
    fov *= M_PI/180.0f;

    result->elements[0 + 0 * 4] = 1.0f / (aspectRatio * tanf(0.5f * fov));
    result->elements[1 + 1 * 4] = 1.0f / tanf(0.5f * fov);
    result->elements[2 + 2 * 4] = (-near - far) / (near - far);
    result->elements[3 + 3 * 4] = 0.0f;
    result->elements[3 + 2 * 4] = 1.0f;
    result->elements[2 + 3 * 4] = (2.0f * far * near) / (near - far);

    return result;
}

mat4f mat4f_translation(vec3f translation) {
    mat4f result = mat4f_create(1.0f);

    result->elements[0 + 3 * 4] = translation.x;
    result->elements[1 + 3 * 4] = translation.y;
    result->elements[2 + 3 * 4] = translation.z;

    return result;
}

mat4f mat4f_rotation(float angle, vec3f axis) {
    mat4f result =  mat4f_create(1.0f);

    float r = to_radians(angle);
    float c = cosf(r);
    float s = sinf(r);
    float omc = 1.0f - c;

    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    result->elements[0 + 0 * 4] = x * x * omc + c;
    result->elements[0 + 1 * 4] = y * x * omc + z * s;
    result->elements[0 + 2 * 4] = x * z * omc - y * s;

    result->elements[1 + 0 * 4] = x * y * omc - z * s;
    result->elements[1 + 1 * 4] = y * y * omc + c;
    result->elements[1 + 2 * 4] = y * z * omc + x * s;

    result->elements[2 + 0 * 4] = x * z * omc + y * s;
    result->elements[2 + 1 * 4] = y * z * omc - x * s;
    result->elements[2 + 2 * 4] = z * z * omc + c;

    return result;
}

mat4f mat4f_scale(vec3f scale) {
    mat4f result = mat4f_create(1.0f);

    result->elements[0 + 0 * 4] = scale.x;
    result->elements[1 + 1 * 4] = scale.y;
    result->elements[2 + 2 * 4] = scale.z;

    return result;
}

void mat4f_multiply(mat4f a, mat4f b, mat4f c) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            float sum = 0.0f;
            for (int e = 0; e < 4; e++) {
                sum += b->elements[x + e * 4] * c->elements[e + y * 4];
            }
            a->elements[x + y * 4] = sum;
        }
    }
}
