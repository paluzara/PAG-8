#pragma once

#include <iostream>
#include <GL\glew.h>
#include <string>
#include "PAGshaderProgram.h"
#include "Pagmodelo.h"
#include "PAGcamara.h"
#include "PAGvalues.h"
#include "Pagluz.h"
#include "PAGLuzPuntual.h"
#include "PAGfoco.h"


class PagRenderer
{

	PagRenderer();
	static PagRenderer *instance;
	float colorBorrado[4];
	
	
	
	std::vector<PAGshaderProgram*> programas;
	std::vector<Pagluz*> luces;

	
	
	int modeloactivo;
	std::vector<Pagmodelo*> modelos;

	PAGcamara *camara;



public:
	~PagRenderer();
	static PagRenderer *getInstance();	void refreshCallback();
	void viewPort(int x, int y, int width, int heigh);
	void colorFondo(float red, float green, float blue);
	void addColorBorrado(GLclampf incR, GLclampf incG, GLclampf incB, GLclampf incA);
	void addColorBorrado(GLclampf inc);
	void setColorBorrado(GLclampf incR, GLclampf incG, GLclampf incB, GLclampf incA);

	void activaZBuffer();
	void activarLuces();
	
	void addShaderProgram(std::string nombreBase, PAGstipoluz tipo);
	void borraBuffers();
	
	void addModelo(Pagmodelo::tipoModelo tipo);
	void addModelo(Pagmodelo::tipoModelo tipo, GLenum tipopintar, Pagmaterial *material=nullptr, PAGtextura *textura=nullptr);
	void addModelo(std::string archivo, GLenum tipopintar, Pagmaterial *material, PAGtextura *textura);

	
	void vistaPlanta();
	void vistaAlzado();
	void vistaPerfil();
	void vistaDiagonal();
	void moverCamara(PAGstipomovimiento tipo , double factorX,double factorY);
	
	void addLuzPuntual( glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _Ia, glm::vec3 posicion);
	void addFoco( glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _Ia, glm::vec3 posicion, glm::vec3 direccion,float angulo);
	void addLuzAmbiente(glm::vec3 _Ia);


	void rotarModelo(glm::vec3 eje, float grados);
	void trasladarModelo(float x ,float y,float z);
    void escalarModelo(float x , float y , float z);
	int  getModeloActivo();
	void setModeloActivo(int x);


};

