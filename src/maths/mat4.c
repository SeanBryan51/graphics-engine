#include <stdio.h>
#include <stdlib.h>
#include "maths.h"

mat4f mat4f_identity() {
    return mat4f_diagonal(1.0f);
}

mat4f mat4f_diagonal(float diagonal) {
    mat4f ret;
    mat4f_set_diagonal(&ret, diagonal);
    return ret;
}

mat4f mat4f_orthographic(float left, float right, float top, float bottom , float near, float far) {
    mat4f ret = mat4f_identity();
    mat4f_set_orthographic(&ret, left, right, top, bottom, near, far);
    return ret;
}

mat4f mat4f_perspective(float fov, float aspectRatio, float near, float far) {
    mat4f ret = mat4f_identity();
    mat4f_set_perspective(&ret, fov, aspectRatio, near, far);
    return ret;
}

mat4f mat4f_translation(vec3f translation) {
    mat4f ret = mat4f_identity();
    mat4f_set_translation(&ret, translation);
    return ret;
}

mat4f mat4f_rotation(float angle, vec3f axis) {
    mat4f ret = mat4f_identity();
    mat4f_set_rotation(&ret, angle, axis);
    return ret;
}

mat4f mat4f_scale(vec3f scale) {
    mat4f ret = mat4f_identity();
    mat4f_set_scale(&ret, scale);
    return ret;
}

void mat4f_set_diagonal(mat4f *m, float diagonal) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) m->elements[i + j * 4] = diagonal;
            else m->elements[i + j * 4] = 0.0f;
        }
    }
}

void mat4f_set_orthographic(mat4f *m, float left, float right, float top, float bottom , float near, float far) {

    m->elements[0 + 0 * 4] = 2.0f / (right - left);
    m->elements[1 + 1 * 4] = 2.0f / (top - bottom);
    m->elements[2 + 2 * 4] = 2.0f / (near - far);

    m->elements[0 + 3 * 4] = (left + right) / (left - right);
    m->elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
    m->elements[2 + 3 * 4] = (far + near) / (far - near);
}

void mat4f_set_perspective(mat4f *m, float fov, float aspectRatio, float near, float far) {

    float q = 1.0f / tan(to_radians(0.5f * fov));
    float a = q / aspectRatio;

    float b = (near + far) / (near - far);
    float c = (2.0f * near * far) / (near - far);

    m->elements[0 + 0 * 4] = a;
    m->elements[1 + 1 * 4] = q;
    m->elements[2 + 2 * 4] = b;
    m->elements[2 + 3 * 4] = -1.0f;
    m->elements[3 + 2 * 4] = c;
}

void mat4f_set_translation(mat4f *m, vec3f translation) {

    mat4f_set_diagonal(m, 1.0f);
    m->elements[0 + 3 * 4] = translation.x;
    m->elements[1 + 3 * 4] = translation.y;
    m->elements[2 + 3 * 4] = translation.z;

}

void mat4f_set_rotation(mat4f *m, float angle, vec3f axis) {

    float r = to_radians(angle);
    
    float c = cosf(r);
    float s = sinf(r);
    float omc = 1.0f - c;
    
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    m->elements[0 + 0 * 4] = x * x * omc + c;
    m->elements[0 + 1 * 4] = y * x * omc + z * s;
    m->elements[0 + 2 * 4] = x * z * omc - y * s;

    m->elements[1 + 0 * 4] = x * y * omc - z * s;
    m->elements[1 + 1 * 4] = y * y * omc + c;
    m->elements[1 + 2 * 4] = y * z * omc + x * s;

    m->elements[2 + 0 * 4] = x * z * omc + y * s;
    m->elements[2 + 1 * 4] = y * z * omc - x * s;
    m->elements[2 + 2 * 4] = z * z * omc + c;

}

void mat4f_set_scale(mat4f *m, vec3f scale) {

    m->elements[0 + 0 * 4] = scale.x;
    m->elements[1 + 1 * 4] = scale.y;
    m->elements[2 + 2 * 4] = scale.z;

}

mat4f mat4f_multiply(mat4f m1, mat4f m2) {
    mat4f ret = mat4f_identity();
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            float sum = 0.0f;
            for (int e = 0; e < 4; e++) {
                sum += m1.elements[x + e * 4] * m2.elements[e + y * 4];
            }
            ret.elements[x + y * 4] = sum;
        }
    }
    return ret;
}

vec4f mat4f_apply(mat4f m, vec4f v) {
    float ret[4] = {0};
    for (int y = 0; y < 4; y++) {
        float sum = 0.0f;
        sum += m.elements[y + 0 * 4] * v.x;
        sum += m.elements[y + 1 * 4] * v.y;
        sum += m.elements[y + 2 * 4] * v.z;
        sum += m.elements[y + 3 * 4] * v.w;
        ret[y] = sum;
    }

    return vec4f_create(ret[0], ret[1], ret[2], ret[3]);
}

void mat4f_show(mat4f m) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            printf("%f ,", m.elements[y + x * 4]);
        }
        printf("\n");
    }
}