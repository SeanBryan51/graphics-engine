#pragma once

#include <stdbool.h>

#include "maths/maths.h"

typedef struct window Window;
typedef struct shader Shader;
typedef struct buffer Buffer;
typedef struct index_buffer IndexBuffer;
typedef struct vertex_array VertexArray;
typedef struct texture1D Texture1D;
typedef struct texture2D Texture2D;
typedef struct texture3D Texture3D;
typedef struct renderer Renderer;

Window *window_create(const char *name, int width, int height);
int     window_get_width(Window *window);
int     window_get_height(Window *window);
void    window_destroy(Window *window);
void    window_clear(Window *window);
bool    window_key_pressed(Window *window, unsigned int keycode);
bool    window_mouse_button_pressed(Window *window, unsigned int button);
void    window_get_mouse_position(Window *window, float *x, float *y);
void    window_update(Window *window);
bool    window_closed(Window *window);

Shader *shader_create(char * vertex_path, char * fragment_path);
void    shader_destroy(Shader *shader);
void    shader_enable(Shader *shader);
void    shader_disable();
void    shader_set_uniform1f(Shader *shader, char *name, float value);
void    shader_set_uniform2f(Shader *shader, char *name, vec2f vector);
void    shader_set_uniform3f(Shader *shader, char *name, vec3f vector);
void    shader_set_uniform4f(Shader *shader, char *name, vec4f vector);
void    shader_set_uniform_mat4f(Shader *shader, char *name, mat4f *matrix);
void    shader_set_uniform1i(Shader *shader, char *name, int value);

Buffer *buffer_create(float *data, GLuint n_vertices, GLuint n_components, GLenum usage);
void    buffer_destroy(Buffer *buffer);
GLuint  buffer_get_component_number(Buffer *buffer);
void    buffer_bind(Buffer *buffer);
void    buffer_unbind();
void    buffer_set_data(Buffer *buffer, const void *data, GLuint n_vertices, GLuint n_components);

IndexBuffer *index_buffer_create(GLuint *data, size_t size, GLuint length, GLenum usage);
void    index_buffer_destroy(IndexBuffer *buffer);
void    index_buffer_bind(IndexBuffer *buffer);
void    index_buffer_unbind();
void    index_buffer_set_data(IndexBuffer *buffer, GLuint *indices, GLuint length);

VertexArray *vertex_array_create();
void         vertex_array_destroy(VertexArray *va);
void         vertex_array_bind(VertexArray *va);
void         vertex_array_unbind();
void         vertex_array_specify_attribute(VertexArray *vao, Buffer *b, GLuint index, GLuint offset, GLuint attribute_length);

Texture1D *texture1D_create(int length);
void    texture1D_destroy(Texture1D *t);
void    texture1D_bind(Texture1D *t);
void    texture1D_unbind();
void    texture1D_load(Texture1D *t, const void *data, GLsizei internal_format, GLsizei format, GLenum type);

Texture2D *texture2D_create(int width, int height);
void    texture2D_destroy(Texture2D *t);
void    texture2D_bind(Texture2D *t);
void    texture2D_unbind();
void    texture2D_load(Texture2D *t, const void *data, GLsizei internal_format, GLsizei format, GLenum type);
void    texture2D_set_parameteri(Texture2D *t, GLenum parameter, GLint value);

Texture3D *texture3D_create(int width, int height, int depth);
void    texture3D_destroy(Texture3D *t);
void    texture3D_bind(Texture3D *t);
void    texture3D_unbind();
void    texture3D_load(Texture3D *t, const void *data, GLsizei internal_format, GLsizei format, GLenum type);
void    texture3D_set_parameteri(Texture3D *t, GLenum parameter, GLint value);