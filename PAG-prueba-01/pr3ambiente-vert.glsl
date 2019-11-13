
#version 400

layout (location = 0) in vec3 posicion;
layout (location = 1) in vec3 vNormal; 

uniform mat4 mModelViewProj;
uniform mat4 mModelView;
uniform mat4 mModel;


void main() {
 gl_Position = mModelViewProj * mModel * vec4(posicion, 1.0);
}


