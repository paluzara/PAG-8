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
#include "objloader.hpp"




class Pagmodelo
{

 protected:	
	GLenum modoVisualizacion;
	Pagvao *vao;
	Pagmaterial *material;
	glm::mat4 tranlacion;
	glm::mat4 rotacion;
	glm::mat4 escalado;
	
	glm::vec3 posicion;
	
	PAGtextura *textura;
	PAGtextura *normalMap;

public:
	enum tipoModelo {
		PAG_TRIANGULO,
		PAG_CUADRADO,
		PAG_TETRAEDRO,
		PAG_CUBO,
		PAG_SUELO
	};

	virtual void pintate();
	void setMaterial(glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, float sh);
	void setMaterial(Pagmaterial* material);
	void setModoVisualizacion( GLenum modo );
	Pagmaterial * getMaterial();
	
	


	void trasladar(float x ,float y , float z);
	void rotar(glm::vec3 eje, float grados);
	void escalar(float x, float y, float z);
	glm::mat4 getTransformacion();

	void añadirTextura(PAGtextura* textura);
	PAGtextura* getTextura();
	PAGtextura* getNormalMap();

	Pagmodelo(tipoModelo tipo, std::string textura, std::string normalmap,int x=4 , int y=4);
	Pagmodelo(std::string nombreArchivoobj,std::string nombreTextura, std::string normalMap);
	Pagmodelo(std::string nombreArchivoobj, std::string nombreTextura, std::string nomalmap, bool asimp );
	Pagmodelo();


	glm::vec3 calcularTangete(glm::vec3 vertice, glm::vec3 vertice1, glm::vec3 vertice2, glm::vec2 coordenada, glm::vec2 coordenada1, glm::vec2 coordenada2);

	virtual ~Pagmodelo();
};

