#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>

#include "graphics.h"
#include "utils/fileutils.h"

struct shader {
    GLuint m_shader_id;
};

static GLuint shader_load(char * vertex_path, char * fragment_path);
static GLuint shader_compile(GLuint type, char const *source);

Shader *shader_create(char * vertex_path, char * fragment_path) {
    Shader *new = calloc(1, sizeof(Shader));
    new->m_shader_id = shader_load(vertex_path, fragment_path);
    return new;
}

void shader_destroy(Shader *shader) {
    glDeleteShader(shader->m_shader_id);
    free(shader);
}

void shader_enable(Shader *shader) {
    glUseProgram(shader->m_shader_id);
}

void shader_disable() {
    glUseProgram(0);
}

void shader_set_uniform1f(Shader *shader, char *name, float value) {
    glUniform1f(glGetUniformLocation(shader->m_shader_id, name), value);
}

void shader_set_uniform2f(Shader *shader, char *name, vec2f vector) {
    glUniform2f(glGetUniformLocation(shader->m_shader_id, name), vector.x, vector.y);
}

void shader_set_uniform3f(Shader *shader, char *name, vec3f vector) {
    glUniform3f(glGetUniformLocation(shader->m_shader_id, name), vector.x, vector.y, vector.z);
}

void shader_set_uniform4f(Shader *shader, char *name, vec4f vector) {
    glUniform4f(glGetUniformLocation(shader->m_shader_id, name), vector.x, vector.y, vector.z, vector.w);
}

void shader_set_uniform_mat4f(Shader *shader, char *name, mat4f *matrix) {
    glUniformMatrix4fv(glGetUniformLocation(shader->m_shader_id, name), 1, GL_FALSE, matrix->elements);
}

void shader_set_uniform1i(Shader *shader, char *name, int value) {
    glUniform1i(glGetUniformLocation(shader->m_shader_id, name), value);
}

static GLuint shader_load(char *vertex_path, char *fragment_path) {

    GLuint program = glCreateProgram();

    char const *vertex_source = read_file(vertex_path);
    GLuint vs = shader_compile(GL_VERTEX_SHADER, vertex_source);
    glAttachShader(program, vs);
    
    char const *fragment_source = read_file(fragment_path);
    GLuint fs = shader_compile(GL_FRAGMENT_SHADER, fragment_source);
    glAttachShader(program, fs);

    glLinkProgram(program);

    // error handling:
    // TODO: log this
    int result;
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    if(result == GL_FALSE) {
        int length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
        char *message = (char *) alloca(length * sizeof(char));
        glGetProgramInfoLog(program, length, &length, message);
        printf("Failed to link shader program.\n");
        printf("%s\n", message);
    }

    glDeleteShader(vs);
    glDeleteShader(fs);

    free((void *)vertex_source);
    free((void *)fragment_source);

    return program;
}

static GLuint shader_compile(GLuint type, char const *source) {
    
    GLuint id = glCreateShader(type);
    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);

    // error handling:
    // TODO: log this
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = (char *) alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        printf("Failed to compile %s shader.\n", (type == GL_VERTEX_SHADER ? "vertex" : "fragment"));
        printf("%s\n", message);
        return 0;
    }

    return id;
}
