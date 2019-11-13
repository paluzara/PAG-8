#include "PAGcamara.h"

#include <math.h>
#include <cmath>
#include <stdexcept>
#include <ext.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx/transform.hpp>



glm::vec3 PAGcamara::vectorUp(glm::vec3 n)
{
	glm::vec3 Y(0, 1, 0);
	glm::vec3 up(Y);

	if (glm::all(glm::epsilonEqual(n, Y, (float) 0.1)))
	{
		up.y = 0;
		up.z = 1;
	}
	else
	{
		if (glm::all(glm::epsilonEqual(n, -Y, (float) 0.1)))
		{
			up.y = 0;
			up.z = -1;
		}
	}

	return up;
}

glm::vec3 PAGcamara::vectorN()
{
	return  glm::normalize(this->posicion - this->lookat);
}

PAGcamara::PAGcamara()
{
	zNear = 0.1;
	zFar = 7;

}


PAGcamara::~PAGcamara()
{
}

void PAGcamara::setPosicion(glm::vec3 nueva)
{
	this->posicion = nueva;
}

void PAGcamara::setPosicion(GLfloat x, GLfloat y, GLfloat z)
{
	this->posicion[0] = x;
	this->posicion[1] = y;
	this->posicion[2] = z;
}

void PAGcamara::setLookAt(glm::vec3 nueva)
{
	this->lookat = nueva;
}

void PAGcamara::setLookAt(GLfloat x, GLfloat y, GLfloat z)
{

	this->lookat[0] = x;
	this->lookat[1] = y;
	this->lookat[2] = z;
}

void PAGcamara::setUp(glm::vec3 nueva)
{
	this->up = nueva;
}

void PAGcamara::setUp(GLfloat x, GLfloat y, GLfloat z)
{
	this->up[0] = x;
	this->up[1] = y;
	this->up[2] = z;
}

void PAGcamara::setFovXRad(GLfloat radianes)
{
	if ((ancho == 0) || (alto == 0))
	{
		throw std::runtime_error("setFovXrad: aún no se ha fijado el ancho y"
			"alto");
	}

	if ((radianes <= 0) || (radianes > M_PIl))
	{
		throw std::runtime_error("setFovXrad: valor de FOV incorrecto");
	}
	float fovY = 2 * (atan(tan(radianes / 2) / ((GLfloat)ancho / (GLfloat)alto)));
	this->fovY = fovY;

}

void PAGcamara::setFovXSex(GLfloat sexagesimales)
{
	if ((ancho == 0) || (alto == 0))
	{
		throw std::runtime_error("setFovXsex: aún no se ha fijado el ancho y"
			" alto");
	}

	if ((sexagesimales <= 0) || (sexagesimales > 180))
	{
		throw std::runtime_error("setFovXsex: valor de FOV incorrecto");
	}
	double radianes = (sexagesimales * M_PIl)/180;
	float fovY = 2 * (atan(tan(radianes / 2) / ((GLfloat)ancho / (GLfloat)alto)));
	this->fovY = fovY;
}

void PAGcamara::setFovYRad(GLfloat radianes)
{
	if ((radianes <= 0) || (radianes > M_PIl))
	{
		throw std::runtime_error("setFovYrad: valor de FOV incorrecto");
	}
	this->fovY = radianes;
}

void PAGcamara::setFovYSex(GLfloat sexagesimales)
{
	if ((sexagesimales <= 0) || (sexagesimales > 180))
	{
		throw std::runtime_error("setFovYsex: valor de FOV incorrecto");
	}

	double radianes = (sexagesimales * M_PIl) / 180;
	this->fovY = radianes;
}

void PAGcamara::setAncho(GLint ancho)
{
	if (ancho <= 0)
	{
		throw std::out_of_range("setAlto: valor no permitido");
	}
	this->ancho = ancho;
}

void PAGcamara::setAlto(GLint alto)
{
	if (alto <= 0)
	{
		throw std::out_of_range("setAlto: valor no permitido");
	}
	this->alto = alto;
}

void PAGcamara::setZnear(GLfloat valor)
{
	if ((valor <= 0) || (valor >= zFar))
	{
		throw std::out_of_range("setZnear: este valor no es valido");
	}
	this->zNear = valor;
}

void PAGcamara::setZfar(GLfloat valor)
{
	if ((valor <= 0) || (valor <= zNear))
	{
		throw std::out_of_range("setZfar: este valor no es valido");
	}
	this->zFar = valor;
}



glm::mat4 PAGcamara::mVision()
{
	return glm::lookAt(posicion, lookat, up);
	
}

glm::mat4 PAGcamara::mProyeccion()
{
	return glm::perspective(fovY, (GLfloat)ancho / (GLfloat)alto, zNear, zFar);
}

glm::mat4 PAGcamara::mPv()
{
	return mProyeccion() * mVision();
}

void PAGcamara::pan(float factor)
{
	auto n = this->vectorN();
	auto  u = glm::cross(this->vectorUp(n), n);
	auto v = glm::cross(n, u);

	/*lookat-=posicion;
	lookat=glm::rotate(lookat, factor, v);
	lookat += posicion;*/

	glm::mat4 mI = glm::mat4(1.0f); //matriz identidad
	auto traslada=glm::translate(mI, -this->posicion);
	auto rotada=glm::rotate(traslada, factor, v);
	auto mposi = glm::translate(rotada, this->posicion);
	auto mtransformacion=mposi*glm::vec4(lookat, 1);
	lookat[0]=mtransformacion[0];
	lookat[1] = mtransformacion[1];
	lookat[2] = mtransformacion[2];
}

void PAGcamara::tilt(float factor)
{
	auto n = this->vectorN();
	auto  u = glm::cross(this->vectorUp(n), n);
	auto v = glm::cross(n, u);

	glm::mat4 mI = glm::mat4(1.0f); //matriz identidad
	auto traslada = glm::translate(mI, -this->posicion);
	auto rotada = glm::rotate(traslada, factor, u);
	auto mposi = glm::translate(rotada, this->posicion);
	auto mtransformacion = mposi * glm::vec4(lookat, 1);
	lookat[0] = mtransformacion[0];
	lookat[1] = mtransformacion[1];
	lookat[2] = mtransformacion[2];
}

void PAGcamara::truckDolly(float factorx, float factory)
{
	auto n = this->vectorN();
	auto  u = glm::cross(this->vectorUp(n), n);
	auto v = u * factorx;

	auto p = n * factory;

	
	this->posicion += v+p;
	this->lookat += v+p;
	


}

void PAGcamara::boom(float factor)
{

	auto n = this->vectorN();
	auto  u = glm::cross(this->vectorUp(n), n);
	auto v = glm::cross(n, u);
	auto f = v * factor;


	this->posicion += f ;
	this->lookat += f ;

}

void PAGcamara::orbit(float factorx, float factory)
{

	glm::vec3 n = this->vectorN();
	glm::vec3 up = vectorUp(n);


	glm::vec3 u = glm::normalize(glm::cross(up, n));
	glm::vec3 v = glm::normalize(glm::cross(n, u));
	

	glm::mat4 t = glm::translate(this->lookat) * glm::rotate(factory, v)
		* glm::rotate(factorx, u) * glm::translate(-this->lookat);
	this->posicion = glm::vec3(t * glm::vec4(this->posicion, 1.0));
}

void PAGcamara::zoom(float factor)
{
	this->fovY = fovY + factor;
}
