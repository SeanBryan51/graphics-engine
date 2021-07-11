#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define glCheckError() glCheckError_(__FILE__, __LINE__)

GLenum glCheckError_(const char *file, int line);