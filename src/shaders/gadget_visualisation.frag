#version 330 core

in vec3 position;
in vec2 texture_coord;

out vec4 colour;

uniform vec2 mouse;
uniform sampler2D my_texture;

void main() {
    float len = length(position.xy - mouse);

    float intensity = pow(texture(my_texture, texture_coord).r, 0.5);

    colour = vec4(0, intensity, intensity, 0.5);
}