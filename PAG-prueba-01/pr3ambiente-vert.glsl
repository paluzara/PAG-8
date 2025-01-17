
#version 400

layout (location = 0) in vec3 posicion;
layout (location = 1) in vec3 vNormal; 
layout (location = 2) in vec2 textura; 
layout (location = 3) in vec3 tangentes; 

uniform mat4 mModelViewProj;
uniform mat4 mModelView;
uniform mat4 mModel;

out vec2 texCoord; 

void main() {
 gl_Position = mModelViewProj * mModel * vec4(posicion, 1.0);
 texCoord = textura; 
}


