#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics.h"

struct index_buffer {
    GLuint id;
    GLenum usage;
    size_t size;
    GLuint length;
};

IndexBuffer *index_buffer_create(GLuint *indices, size_t size, GLuint length, GLenum usage) {

    IndexBuffer *ret = calloc(1, sizeof(IndexBuffer));

    ret->size = size;
    ret->length = length;
    ret->usage = usage;

    // Declare a memory instance on the GPU and generate
    // an ID:
    glGenBuffers(1, &ret->id);

    // Fill memory on GPU with indices:
    index_buffer_bind(ret);
    index_buffer_set_data(ret, indices, length);
    index_buffer_unbind();

    return ret;
}

void index_buffer_destroy(IndexBuffer *buffer) {
    glDeleteBuffers(1, &buffer->id);
    free(buffer);
}

// Selects the buffer for OpenGL. 
void index_buffer_bind(IndexBuffer *buffer) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->id);
}

// Deselects all buffers.
void index_buffer_unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Stores a block of memory onto the GPU.
void index_buffer_set_data(IndexBuffer *buffer, GLuint *indices, GLuint length) {
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, length * sizeof(GLuint), indices, buffer->usage);
}
