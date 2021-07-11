#version 330 core

layout (location = 0) in vec3 position_raw;

out vec3 position;

uniform mat4 mat_perspective;
uniform mat4 mat_model;
uniform mat4 mat_rot;

void main() {
    gl_Position = mat_perspective * mat_model * mat_rot * vec4(position_raw, 1.0);
    position = position_raw;
}
