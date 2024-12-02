#version 330 core
in vec4 vertex;
in vec2 uv0;

uniform mat4 modelViewProjMat;
uniform float sintime;
uniform vec2 center;

out vec2 vUv0;

void main() {
    vUv0 = uv0;
    vec4 vertexCoord = vertex;

    float distanceCenter = distance(vec2(vertexCoord.x, vertexCoord.z), center);

    float a = 50;
    float b = 1;

    vertexCoord.y += sin(vertexCoord.x + (sintime*a)) * b +
                    sin(vertexCoord.z + (distanceCenter) + (sintime * a)) * b;
    
    gl_Position = modelViewProjMat * vertexCoord;
}