#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics.h"

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

struct window {
    const char *m_title;
    int         m_width, m_height;
    GLFWwindow *m_window;
    bool        m_keys[MAX_KEYS];
    bool        m_mouse_buttons[MAX_BUTTONS];
    float       m_mousex, m_mousey;
};

static bool window_init(Window *window);
static void key_callback(GLFWwindow* glfw_window, int key, int scancode, int action, int mods);
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

Window *window_create(const char *title, int width, int height) {
    Window *new = calloc(1, sizeof(Window));
    new->m_title = title;
    new->m_width = width;
    new->m_height = height;

    if (!window_init(new)) glfwTerminate();

    for (int i = 0; i < MAX_KEYS; i++) {
        new->m_keys[i] = false;
    }
    
    for (int i = 0; i < MAX_BUTTONS; i++) {
        new->m_mouse_buttons[i] = false;
    }
    
    new->m_mousex = new->m_mousey = 0;

    return new;
}

void window_destroy(Window *window) {
    glfwTerminate();
    free(window);
}

int window_get_width(Window *window) {
    return window->m_width;
}
int window_get_height(Window *window) {
    return window->m_height;
}

void window_clear(Window *window) {
    // TODO: what does this do?
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool window_key_pressed(Window *window, unsigned int keycode) {
    
    // TODO: log keycode 
    if (keycode > MAX_KEYS) return false;

    return window->m_keys[keycode];
}

bool window_mouse_button_pressed(Window *window, unsigned int button) {
    
    // TODO: log button
    if (button > MAX_BUTTONS) return false;

    return window->m_mouse_buttons[button];
}

void window_get_mouse_position(Window *window, float *x, float *y) {
    *x = window->m_mousex;
    *y = window->m_mousey;
}

void window_update(Window *window) {
    glfwGetFramebufferSize(window->m_window, &window->m_width, &window->m_height);
    glViewport(0, 0, window->m_width, window->m_height);
    glfwSwapBuffers(window->m_window);
    glfwPollEvents();
}

bool window_closed(Window *window) {
    return glfwWindowShouldClose(window->m_window);
}

static bool window_init(Window *window) {

    if (!glfwInit()) {
        printf("Failed to initialise glfw.\n");
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window->m_window = glfwCreateWindow(window->m_width, window->m_height, window->m_title, NULL, NULL);
    if (!window->m_window) {
        printf("Failed to create glfw window.");
        return false;
    }

    glfwMakeContextCurrent(window->m_window);

    // function callbacks:
    glfwSetKeyCallback(window->m_window, key_callback);
    glfwSetCursorPosCallback(window->m_window, cursor_position_callback);
    glfwSetMouseButtonCallback(window->m_window, mouse_button_callback);
    

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        printf("Failed to initialise GLEW.\n");
        return false;
    }

    glfwSetWindowUserPointer(window->m_window, window);

    printf("Running OpenGL %s\n", glGetString(GL_VERSION));
    return true;
}

static void key_callback(GLFWwindow* glfw_window, int key, int scancode, int action, int mods) {
    Window *window = (Window *) glfwGetWindowUserPointer(glfw_window);
    window->m_keys[key] = (action != GLFW_RELEASE);
}

static void cursor_position_callback(GLFWwindow* glfw_window, double xpos, double ypos) {
    Window *window = (Window *) glfwGetWindowUserPointer(glfw_window);
    window->m_mousex = xpos;
    window->m_mousey = ypos;
}

static void mouse_button_callback(GLFWwindow* glfw_window, int button, int action, int mods) {
    Window *window = (Window *) glfwGetWindowUserPointer(glfw_window);
    window->m_mouse_buttons[button] = (action != GLFW_RELEASE);
}