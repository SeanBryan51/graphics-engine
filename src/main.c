#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics/graphics.h"
#include "maths/maths.h"
#include "utils/fileutils.h"
#include "gadget_tools/reader.h"

#define WINDOW_SIZE 800
#define PIXEL_SIZE (1.0 / WINDOW_SIZE)

void initialise_data(GLubyte *data, float *positions, int n_particles, mat4f net_transformation);
void get_mouse_pos(Window *window, vec2f *mouse);
mat4f get_transformation_matrix(float v);

int main() {

    Window *window = window_create("You feeling dizzy? Cunt.", WINDOW_SIZE, WINDOW_SIZE);
    glClearColor(0.93f, 0.33f, 0.33f, 1.0f);

    float vertices[] = {
        // positions           // texture coords
        -1.0f, -1.0f, 0.0f,    0.0f, 0.0f,
        -1.0f,  1.0f, 0.0f,    0.0f, 1.0f,
         1.0f,  1.0f, 0.0f,    1.0f, 1.0f,
         1.0f, -1.0f, 0.0f,    1.0f, 0.0f,
    };

    VertexArray *vao = vertex_array_create();
    Buffer *vbo = buffer_create(vertices, 8, 5, GL_STATIC_DRAW);
    vertex_array_specify_attribute(vao, vbo, 0, 0, 3); // positions
    vertex_array_specify_attribute(vao, vbo, 1, 3, 2); // texture coords

    unsigned int indices[] = {
        0, 1, 2,
        0, 3, 2,
    };

    IndexBuffer *ibo = index_buffer_create(indices, sizeof(indices), 6, GL_STATIC_DRAW);

    Shader *shader = shader_create("src/shaders/gadget_visualisation.vert", "src/shaders/gadget_visualisation.frag");
    shader_enable(shader);

    GLubyte data[WINDOW_SIZE * WINDOW_SIZE];
    float * positions = read_positions("snapshot_005");
    int n_particles = header_get_n_particles(read_header("snapshot_005"));

    initialise_data(data, positions, n_particles, get_transformation_matrix(0.0f));

    Texture2D *texture = texture2D_create(WINDOW_SIZE, WINDOW_SIZE);

    texture2D_set_parameteri(texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    texture2D_set_parameteri(texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    texture2D_load(texture, data, GL_R8, GL_RED, GL_UNSIGNED_BYTE);

    vec2f mouse;
    float rotation_value = 0.0f;

    texture2D_bind(texture);
    buffer_bind(vbo);
    vertex_array_bind(vao);
    index_buffer_bind(ibo);

    while (!window_closed(window)) {
        window_clear(window);

        get_mouse_pos(window, &mouse);
        shader_set_uniform2f(shader, "mouse", mouse);

        rotation_value += 2.0f;
        initialise_data(data, positions, n_particles, get_transformation_matrix(rotation_value));
        texture2D_load(texture, data, GL_R8, GL_RED, GL_UNSIGNED_BYTE);
        texture2D_bind(texture);
#if 0
        if (window_key_pressed(window, GLFW_KEY_W)) {
        }

        if (window_key_pressed(window, GLFW_KEY_A)) {
        }

        if (window_key_pressed(window, GLFW_KEY_D)) {
        }

        if (window_key_pressed(window, GLFW_KEY_S)) {
        }
#endif
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        window_update(window);
    }

    texture2D_destroy(texture);
    index_buffer_destroy(ibo);
    buffer_destroy(vbo);
    vertex_array_destroy(vao);
    shader_destroy(shader);
    window_destroy(window);

    return EXIT_SUCCESS;
}

void get_mouse_pos(Window *window, vec2f *mouse) {
    window_get_mouse_position(window, &mouse->x, &mouse->y);
    mouse->x = map(mouse->x, 0.0f, window_get_width(window), -1.0f, 1.0f);
    mouse->y = -1.0f * map(mouse->y, 0.0f, window_get_height(window), -1.0f, 1.0f);
}

mat4f get_transformation_matrix(float v) {

    mat4f identity = mat4f_identity();
    mat4f scale = mat4f_scale(vec3f_create(2.0f / 256.0f, 2.0f / 256.0f, 2.0f / 256.0f)); 
    mat4f center_on_origin = mat4f_translation(vec3f_create(-0.5f, -0.5f, -0.5f)); 
    mat4f rotation = mat4f_rotation(v, vec3f_create(0.7071f, 0.7071f, 0.0f)); 
    mat4f center_on_origin_inv = mat4f_translation(vec3f_create(0.5, 0.5, 0.5)); 
    mat4f scale_inv = mat4f_scale(vec3f_create(256.0f, 256.0f, 256.0f)); 
    mat4f model = mat4f_translation(vec3f_create(0.0f, 0.0f, -5.0f)); 
    mat4f perspective = mat4f_perspective(60.0f, 1.0f, 0.1f, 100.0f); 
    mat4f orthographic = mat4f_orthographic(-0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f);

    return mat4f_multiply(perspective, mat4f_multiply(model, mat4f_multiply(rotation, mat4f_multiply(center_on_origin, scale))));
}

void initialise_data(GLubyte *data, float *positions, int n_particles, mat4f net_transformation) {

    int histogram[WINDOW_SIZE * WINDOW_SIZE] = {0};
    int max_count = 0;
    vec4f particle_position, mapped_position;
    for (int index = 0; index < 3 * n_particles; index += 3) {

        particle_position.x = positions[index];
        particle_position.y = positions[index + 1];
        particle_position.z = positions[index + 2];
        particle_position.w = 1.0f;

        mapped_position = mat4f_apply(net_transformation, particle_position);

        int pixel_x = floor((mapped_position.x / mapped_position.z + 0.5f) / PIXEL_SIZE * 1.0f);
        int pixel_y = floor((mapped_position.y / mapped_position.z + 0.5f) / PIXEL_SIZE * 1.0f);

        if (pixel_x >= 0 && pixel_x < WINDOW_SIZE && pixel_y >= 0 && pixel_y < WINDOW_SIZE) {
            histogram[pixel_x + WINDOW_SIZE * pixel_y] += 1;
            if (histogram[pixel_x + WINDOW_SIZE * pixel_y] > max_count) {
                max_count = histogram[pixel_x + WINDOW_SIZE * pixel_y];
            }
        }
    }

    for (int i = 0; i < WINDOW_SIZE*WINDOW_SIZE; i++)
        data[i] = (GLubyte) map(histogram[i], 0, max_count, 0.0, 255.0);

}