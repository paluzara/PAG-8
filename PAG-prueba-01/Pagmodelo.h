#include <iostream>
#include <GL\glew.h>
#include <string>
#include "Pagvao.h"
#include "Pagmaterial.h"
#include <cmath>
#include <ext.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx/rotate_vector.hpp>
#include <gtx/transform.hpp>
#include "PAGtextura.h"




class Pagmodelo
{
	GLenum modoVisualizacion;
	Pagvao *vao;
	Pagmaterial *material;
	glm::mat4 transformacion;
	glm::vec3 posicion;
	PAGtextura *textura;

public:
	enum tipoModelo {
		PAG_TRIANGULO,
		PAG_CUADRADO,
		PAG_TETRAEDRO,
		PAG_CUBO
	};

	void pintate();
	void setMaterial(glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, float sh);
	void setMaterial(Pagmaterial* material);
	void setModoVisualizacion( GLenum modo );
	Pagmaterial * getMaterial();
	
	


	void trasladar(float x ,float y , float z);
	void rotar(glm::vec3 eje, float grados);
	void escalar(float x, float y, float z);
	glm::mat4 getTransformacion();

	void añadirTextura(PAGtextura* textura);

	Pagmodelo(tipoModelo tipo);
	~Pagmodelo();

};

