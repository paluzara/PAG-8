#version 400
layout (location = 0) in vec3 posicion;
layout (location = 1) in vec3 vNormal; 

uniform mat4 mModelViewProj;
uniform mat4 mModelView;
uniform mat4 mModel;

out vec3 position;
out vec3 normal;  


void main ()
{
 normal = vec3( mModelView * vec4(vNormal, 0.0) );
 position = vec3( mModelView * vec4(posicion, 1.0) ); 
 gl_Position = mModelViewProj * mModel * vec4 (posicion.x, posicion.y, posicion.z, 1);
}