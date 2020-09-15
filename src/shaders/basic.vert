#version 330 core

layout (location = 0) in vec4 position;

uniform mat4 mat_perspective;
uniform mat4 mat_view = mat4(1.0);
uniform mat4 mat_model = mat4(1.0);
uniform mat4 mat_rot = mat4(1.0);

void main() {
    gl_Position = mat_perspective * mat_view * mat_rot * mat_model * position;
}
