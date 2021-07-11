#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>

#include "graphics.h"

struct texture1D {
    GLuint texture_id;
    int length;
};

Texture1D *texture1D_create(int length) {
    Texture1D *new = calloc(1, sizeof(Texture1D));
    new->length = length;

    glGenTextures(1, &new->texture_id);

    return new;
}

void texture1D_destroy(Texture1D *t) {
    free(t);
}

void texture1D_bind(Texture1D *t) {
    glBindTexture(GL_TEXTURE_1D, t->texture_id);
}

void texture1D_unbind() {
    glBindTexture(GL_TEXTURE_1D, 0);
}

/*
 * Sets the data for the texture and how we allocate its storage.
 */
void texture1D_load(Texture1D *t, const void *data, GLsizei internal_format, GLsizei format, GLenum type) {
    texture1D_bind(t);
    // Note on glTexImage*:
    // @target selects the target (GL_TEXTURE_1D, GL_TEXTURE_2D, etc).
    // @level selects the mipmap level.
    // @internalFormat specifys the format that OpenGL will use to store texture data.
    // @width length of data.
    // @border ignore (must always be 0).
    // @format selects number of components per 'texel'.
    // @type the type of each component.
    // @pixels the data to be stored in the texture.
    glTexImage1D(GL_TEXTURE_1D, 0, format, t->length, 0, format, type, data);
    texture1D_unbind();
}

void texture1D_set_parameteri(Texture1D *t, GLenum parameter, GLint value) {
    texture1D_bind(t);
    glTexParameteri(GL_TEXTURE_1D, parameter, value);
    texture1D_unbind();
}

struct texture2D {
    GLuint texture_id;
    int width;
    int height;
};

Texture2D *texture2D_create(int width, int height) {
    Texture2D *new = calloc(1, sizeof(Texture2D));
    new->width = width;
    new->height = height;

    glGenTextures(1, &new->texture_id);

    return new;
}

void texture2D_destroy(Texture2D *t) {
    free(t);
}

void texture2D_bind(Texture2D *t) {
    glBindTexture(GL_TEXTURE_2D, t->texture_id);
}

void texture2D_unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void texture2D_load(Texture2D *t, const void *data, GLsizei internal_format, GLsizei format, GLenum type) {
    texture2D_bind(t);
    glTexImage2D(GL_TEXTURE_2D, 0, internal_format, t->width, t->height, 0, format, type, data);
    texture2D_unbind();
}

void texture2D_set_parameteri(Texture2D *t, GLenum parameter, GLint value) {
    texture2D_bind(t);
    glTexParameteri(GL_TEXTURE_2D, parameter, value);
    texture2D_unbind();
}

struct texture3D {
    GLuint texture_id;
    int width;
    int height;
    int depth;
};

Texture3D *texture3D_create(int width, int height, int depth) {
    Texture3D *new = calloc(1, sizeof(Texture3D));
    new->width = width;
    new->height = height;
    new->depth = depth;

    glGenTextures(1, &new->texture_id);

    return new;
}

void texture3D_destroy(Texture3D *t) {
    free(t);
}

void texture3D_bind(Texture3D *t) {
    glBindTexture(GL_TEXTURE_3D, t->texture_id);
}

void texture3D_unbind() {
    glBindTexture(GL_TEXTURE_3D, 0);
}

void texture3D_load(Texture3D *t, const void *data, GLsizei internal_format, GLsizei format, GLenum type) {
    texture3D_bind(t);
    glTexImage3D(GL_TEXTURE_3D, 0, internal_format, t->width, t->height, t->depth, 0, format, type, data);
    texture3D_unbind();
}

void texture3D_set_parameteri(Texture3D *t, GLenum parameter, GLint value) {
    texture3D_bind(t);
    glTexParameteri(GL_TEXTURE_3D, parameter, value);
    texture3D_unbind();
}