

#include <iostream>
#include <GL\glew.h>
#include <glm.hpp>
#include <vector>
#include <cmath>
#include <ext.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx/rotate_vector.hpp>
#include <gtx/transform.hpp>

# define M_PIl          3.141592653589793238462643383279502884L /* pi */

class PAGcamara
{
	glm::vec3 posicion;
	glm::vec3 lookat;
	glm::vec3 up;
	GLfloat fovY;
	GLint ancho;
	GLint alto;
	GLfloat zNear;
	GLfloat zFar;

	glm::vec3 vectorUp(glm::vec3 v);
	glm::vec3 vectorN();

public:
	PAGcamara();
	~PAGcamara();
	
	void setPosicion(glm::vec3 nueva);
	void setPosicion(GLfloat x, GLfloat y, GLfloat z);

	void setLookAt(glm::vec3 nueva);
	void setLookAt(GLfloat x, GLfloat y, GLfloat z);

	void setUp(glm::vec3 nueva);
	void setUp(GLfloat x, GLfloat y, GLfloat z);

	void setFovXRad(GLfloat radianes);
	void setFovXSex(GLfloat sexagesimales);
	void setFovYRad(GLfloat radianes);
	void setFovYSex(GLfloat sexagesimales);

	void setAncho(GLint ancho);
	void setAlto(GLint alto);

	void setZnear(GLfloat valor);
	void setZfar(GLfloat valor);
	
	glm::mat4 mVision();
	glm::mat4 mProyeccion();
	glm::mat4 mPv();



	//Practica 6

	void pan(float factor);
	void tilt(float factor);
	void truckDolly(float factorx,float factory);
	void boom(float factor);
	void orbit(float factorx, float factory);
	void zoom(float factor);

};

