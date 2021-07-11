#version 330 core

layout (location = 0) in vec3 position_raw;
layout (location = 1) in vec2 texture_coord_raw;

out vec3 position;
out vec2 texture_coord;

void main() {
    gl_Position = vec4(position_raw, 1.0);
    position = position_raw;
    texture_coord = texture_coord_raw;
}
