#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics.h"

struct vertex_array {
    GLuint id;
};

VertexArray *vertex_array_create() {
    VertexArray *ret = calloc(1, sizeof(VertexArray)); 
    glGenVertexArrays(1, &ret->id); 
    return ret;
}

void vertex_array_destroy(VertexArray *vao) {
    free(vao);
}

void vertex_array_bind(VertexArray *vao) {
    glBindVertexArray(vao->id);
}

void vertex_array_unbind() {
    glBindVertexArray(0);
}

// Note: remember to bind 'vao' and 'b' before calling this function.
void vertex_array_specify_attribute(VertexArray *vao, Buffer *b, GLuint index, GLuint offset, GLuint attribute_length) {
    vertex_array_bind(vao);
    buffer_bind(b);
    GLuint n_components = buffer_get_component_number(b);
    glVertexAttribPointer(index, attribute_length , GL_FLOAT, GL_FALSE, n_components * sizeof(float), (void *) (offset * sizeof(float)));
    glEnableVertexAttribArray(index);
    buffer_unbind();
    vertex_array_unbind();
}
