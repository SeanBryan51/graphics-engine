#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics.h"

struct buffer {
    GLuint id;
    GLenum usage;
    GLuint n_vertices;
    GLuint n_components;
};

/*
 * Creates an instance for the buffer abstract data type.
 * Note that 'usage' is either has the value GL_STREAM_DRAW, GL_STATIC_DRAW
 * or GL_DYNAMIC_DRAW.
 * 
 * NOTE: DATA IS ASSUMED TO BE A FLOAT. (SEE vertexarray.c/vertex_array_add_buffer())
 */
Buffer *buffer_create(float *data, GLuint n_vertices, GLuint n_components, GLenum usage) {

    Buffer *buffer = calloc(1, sizeof(Buffer));

    buffer->usage = usage;
    buffer->n_vertices = n_vertices;
    buffer->n_components = n_components;

    // Declare a memory instance on the GPU and generate
    // an ID:
    glGenBuffers(1, &buffer->id);

    // Fill memory on GPU with data:
    buffer_bind(buffer);
    buffer_set_data(buffer, data, n_vertices, n_components);
    buffer_unbind(buffer);

    return buffer;
}

void buffer_destroy(Buffer *buffer) {
    glDeleteBuffers(1, &buffer->id);
    free(buffer);
}

GLuint buffer_get_component_number(Buffer *buffer) {
    return buffer->n_components;
}

// Selects the buffer for OpenGL.
void buffer_bind(Buffer *buffer) {
    glBindBuffer(GL_ARRAY_BUFFER, buffer->id);
}

// Deselects all buffers.
void buffer_unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Stores a block of memory onto the GPU.
void buffer_set_data(Buffer *buffer, const void *data, GLuint n_vertices, GLuint n_components) {
    buffer->n_vertices = n_vertices;
    buffer->n_components = n_components;
    glBufferData(GL_ARRAY_BUFFER, n_vertices * n_components * sizeof(float), data, buffer->usage);
}
