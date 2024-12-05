#version 330 core
in vec2 vUv0;
uniform sampler2D Water;
out vec4 fFragColor;

void main() {
    fFragColor = texture(Water, vUv0);
}