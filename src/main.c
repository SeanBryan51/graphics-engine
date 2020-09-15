#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics/graphics.h"
#include "maths/maths.h"
#include "utils/fileutils.h"

int main() {

    Window *window = window_create("My Graphics Engine!", 800, 800);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    
    float vertices[] = {
        0, 0, 0,
        0, 3, 0,
        8, 3, 0,
        8, 0, 0
        // -0.5f, -0.5f, 0.0f,
        // -0.5f,  0.0f, 0.0f,
        //  0.5f,  0.0f, 0.0f,
        //  0.5f, -0.5f, 0.0f
    };

    unsigned int indices[] = {
        0, 1, 2,
        0, 3, 2
    };

    GLuint vbo, vao, ebo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    Shader *shader = shader_create("src/shaders/basic.vert", "src/shaders/basic.frag");
    shader_enable(shader);
    
    shader_set_uniform_mat4f(shader, "mat_perspective", mat4f_orthographic(-1.0f, 16.0f, -2.0f, 9.0f, -1.0f, 1.0f));
    
    vec3f translation = {2.0f, 2.0f, 0.0f};
    shader_set_uniform_mat4f(shader, "mat_model", mat4f_translation(translation));
    
    vec3f zbasis = {0, 0, 1};
    shader_set_uniform_mat4f(shader, "mat_rot", mat4f_rotation(0.0f, zbasis));

    while (!window_closed(window)) {
        window_clear(window);

        float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        vec4f color = {0.0f, greenValue, 0.0f, 1.0f};
        shader_set_uniform4f(shader, "ourColor", color);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        window_update(window);
    }

    return EXIT_SUCCESS;
}