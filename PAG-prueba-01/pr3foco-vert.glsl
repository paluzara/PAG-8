
#version 400

layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec3 vNormal;
layout (location = 2) in vec2 textura;

uniform mat4 mvpMatrix;
uniform mat4 mModelView;
uniform mat4 mModel;

out vec3 position;
out vec3 normal;
out vec2 texCoord;

void main() {
 normal = vec3( mModelView *transpose(inverse(mModel))* vec4(vNormal, 0.0) );
 position = vec3( mModelView * vec4(vPosition, 1.0) );
texCoord = textura; 
 gl_Position =  mvpMatrix * mModel * vec4(vPosition, 1.0);
}