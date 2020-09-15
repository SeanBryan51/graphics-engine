#pragma once

#include <stdbool.h>

#include "maths/maths.h"

typedef struct window Window;

Window *window_create(const char *name, int width, int height);
void    window_destroy(Window *window);
void    window_clear(Window *window);
bool    window_key_pressed(Window *window, unsigned int keycode);
bool    window_mouse_button_pressed(Window *window, unsigned int button);
void    window_get_mouse_position(Window *window, double *x, double *y);
void    window_update(Window *window);
bool    window_closed(Window *window);


typedef struct shader Shader;

Shader *shader_create(char * vertex_path, char * fragment_path);
void    shader_destroy(Shader *shader);
void    shader_enable(Shader *shader);
void    shader_disable();
void    shader_set_uniform1f(Shader *shader, char *name, float value);
void    shader_set_uniform2f(Shader *shader, char *name, vec2f vector);
void    shader_set_uniform3f(Shader *shader, char *name, vec3f vector);
void    shader_set_uniform4f(Shader *shader, char *name, vec4f vector);
void    shader_set_uniform_mat4f(Shader *shader, char *name, mat4f matrix);