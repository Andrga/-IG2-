#version 330 core

in vec4 vertex; // Atributos de los vertices a procesar.

in vec2 uv0; // Coordenadas de textura 0.
out vec2 vUv0; // Out del vertex shader.

uniform mat4 modelViewProjMat; // Constante – uniform - de programa.

uniform float time;
uniform float zoomMin; // 0.3
uniform float zoomMax; // 1

void main() {
    float nextZoom =0.1;// (zoomMin + zoomMax) / 2;
    float nextFactor = zoomMax - nextZoom;

    float factor = (time * nextFactor) + nextZoom;

    // Ajustar la textura:
    vUv0.s = (uv0.s - zoomMin) * (factor) + zoomMin;
    vUv0.t = (uv0.t - zoomMin) * (factor) + zoomMin;

    gl_Position = modelViewProjMat * vertex;
}