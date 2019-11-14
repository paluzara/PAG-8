#include "Pagmodelo.h"




Pagmodelo::Pagmodelo(tipoModelo tipo, int x , int y )
{
	transformacion = glm::mat4(1.0f); //matriz identidad
	posicion = glm::vec3(0, 0, 0);
	this->material = new Pagmaterial();



	vao = new Pagvao();
	switch (tipo) {

	case PAG_SUELO:{
		int j = 0;
		for (int i = -4; i <= 4; i+=2) {
			for (int x = -4; x <= 4; x+=2) {
				vao->addverticenormal(glm::vec3(-1.0f + x, -0.45f, -1.0f + i), glm::vec3(0.0f, 1.0f, 0.0f));
				vao->addverticenormal(glm::vec3(1.0f + x, -0.45f, -1.0f + i), glm::vec3(0.0f, 1.0f, 0.0f));
				vao->addverticenormal(glm::vec3(-1.0f + x, -0.45f, 1.0f + i), glm::vec3(0.0f, 1.0f, 0.0f));
				vao->addverticenormal(glm::vec3(1.0f + x, -0.45f, 1.0f + i), glm::vec3(0.0f, 1.0f, 0.0f));
				vao->addCoorText(glm::vec2(0.0f, 0.0f));
				vao->addCoorText(glm::vec2(1.0f, 0.0f));
				vao->addCoorText(glm::vec2(0.0f, 1.0f));
				vao->addCoorText(glm::vec2(1.0f, 1.0f));
				
				vao->addIndice(GL_TRIANGLES, 0 + 4 * j);
				vao->addIndice(GL_TRIANGLES, 1 + 4 * j);
				vao->addIndice(GL_TRIANGLES, 2 + 4 * j);
				vao->addIndice(GL_TRIANGLES, 1 + 4 * j);
				vao->addIndice(GL_TRIANGLES, 2 + 4 * j);
				vao->addIndice(GL_TRIANGLES, 3 + 4 * j);
				j++;
			}
		}

	

	}
		break;

	case PAG_TRIANGULO:
		vao->addvertice(glm::vec3(-0.5, -0.5, 0));
		vao->addvertice(glm::vec3(0.5, -0.5, 0));
		vao->addvertice(glm::vec3(0, 0.5, 0));

		vao->addIndice(GL_TRIANGLES, 0);
		vao->addIndice(GL_TRIANGLES, 1);
		vao->addIndice(GL_TRIANGLES, 2);

		vao->addIndice(GL_POINTS, 0);
		vao->addIndice(GL_POINTS, 1);
		vao->addIndice(GL_POINTS, 2);

		vao->addIndice(GL_LINES, 0);
		vao->addIndice(GL_LINES, 1);
		vao->addIndice(GL_LINES, 1);
		vao->addIndice(GL_LINES, 2);
		vao->addIndice(GL_LINES, 2);
		vao->addIndice(GL_LINES, 0);

		break;
	case PAG_CUADRADO:
		vao->addvertice(glm::vec3(-0.25, -0.45, 0));
		vao->addvertice(glm::vec3(0.25, -0.45, 0));
		vao->addvertice(glm::vec3(0.25, 0.45, 0));
		vao->addvertice(glm::vec3(-0.25, 0.45, 0));

		vao->addIndice(GL_TRIANGLES, 0);
		vao->addIndice(GL_TRIANGLES, 2);
		vao->addIndice(GL_TRIANGLES, 3);
		vao->addIndice(GL_TRIANGLES, 0);
		vao->addIndice(GL_TRIANGLES, 1);
		vao->addIndice(GL_TRIANGLES, 2);

		vao->addIndice(GL_POINTS, 0);
		vao->addIndice(GL_POINTS, 1);
		vao->addIndice(GL_POINTS, 2);
		vao->addIndice(GL_POINTS, 3);

		vao->addIndice(GL_LINES, 0);
		vao->addIndice(GL_LINES, 1);
		vao->addIndice(GL_LINES, 1);
		vao->addIndice(GL_LINES, 2);
		vao->addIndice(GL_LINES, 2);
		vao->addIndice(GL_LINES, 3);
		vao->addIndice(GL_LINES, 3);
		vao->addIndice(GL_LINES, 0);

		break;
	case PAG_CUBO:
		auto v0 = glm::vec3(-0.45, -0.45, 0.45);
		auto v1 = glm::vec3(0.45, -0.45, 0.45);
		auto v2 = glm::vec3(0.45, 0.45, 0.45);
		auto v3 = glm::vec3(-0.45, 0.45, 0.45);
		auto v4 = glm::vec3(-0.45, -0.45, -0.45);
		auto v5 = glm::vec3(0.45, -0.45, -0.45);
		auto v6 = glm::vec3(0.45, 0.45, -0.45);
		auto v7 = glm::vec3(-0.45, 0.45, -0.45);

		// Cara 5
		auto c0 = glm::vec2(0, 0.25);
		auto c1 = glm::vec2(0, 0.5);
		auto c2 = glm::vec2(0.25, 0.25);
		auto c3 = glm::vec2(0.25, 0.5);
		//Cara 3

		auto c4 = glm::vec2(0.25, 0.25);
		auto c5 = glm::vec2(0.25, 0.5);
		auto c6 = glm::vec2(0.5, 0.25);
		auto c7 = glm::vec2(0.5, 0.5);



		//Cara 1 
		auto c12 = glm::vec2(0.25, 0.25);
		auto c13 = glm::vec2(0.5, 0.25);
		auto c14 = glm::vec2(0.25, 0);
		auto c15 = glm::vec2(0.5, 0);

		//Cara 4
		auto c20 = glm::vec2(0.75, 0.25);
		auto c21 = glm::vec2(0.75, 0.5);
		auto c22 = glm::vec2(1, 0.25);
		auto c23 = glm::vec2(1, 0.5);

		

		//Cara 6
		auto c8 = glm::vec2(0.25, 0.5);
		auto c9 = glm::vec2(0.5, 0.5);
		auto c10 = glm::vec2(0.25, 0.75);
		auto c11 = glm::vec2(0.5, 0.75);

		vao->addvertice(v0);
		vao->addvertice(v1);
		vao->addvertice(v2);
		vao->addvertice(v3);

		vao->addvertice(v4);
		vao->addvertice(v5);
		vao->addvertice(v6);
		vao->addvertice(v7);

		//cara 5
		vao->addTodo(v0, v2, v3, c0, c3, c1);
		vao->addTodo(v0, v1, v2, c0, c2, c3);


		//cara 3
		vao->addTodo(v1, v5, v2, c4, c5, c6);
		vao->addTodo(v5, v6, v2, c5, c7, c6);


		//cara1
		vao->addTodo(v0, v1, v5, c14, c12, c13);
		vao->addTodo(v0, v5, v4, c14, c13, c15);


		//cara 4
		vao->addTodo(v4, v0, v3, c20, c22, c23);
		vao->addTodo(v4, v3, v7, c20, c23, c21);
		//cara 2
		//Cara 2
		
		auto c16 = glm::vec2(0.5, 0.5);
		auto c17 = glm::vec2(0.5, 0.25);
		auto c18 = glm::vec2(0.75, 0.25);
		auto c19 = glm::vec2(0.75, 0.5);

		vao->addTodo(v4, v7, v5, c17, c16, c18);
		vao->addTodo(v5, v7, v6, c18, c16, c19);
		//Cara 6


		vao->addTodo(v3, v6, v2, c8, c11, c9);
		vao->addTodo(v3, v7, v6, c8, c10, c11);



		//cara frente
		vao->addIndice(GL_TRIANGLES, 0);
		vao->addIndice(GL_TRIANGLES, 1);
		vao->addIndice(GL_TRIANGLES, 2);
		vao->addIndice(GL_TRIANGLES, 3);
		vao->addIndice(GL_TRIANGLES, 4);
		vao->addIndice(GL_TRIANGLES, 5);
		//cara derecha
		vao->addIndice(GL_TRIANGLES, 6);
		vao->addIndice(GL_TRIANGLES, 7);
		vao->addIndice(GL_TRIANGLES, 8);
		vao->addIndice(GL_TRIANGLES, 9);
		vao->addIndice(GL_TRIANGLES, 10);
		vao->addIndice(GL_TRIANGLES, 11);
		//cara abajo
		vao->addIndice(GL_TRIANGLES, 12);
		vao->addIndice(GL_TRIANGLES, 13);
		vao->addIndice(GL_TRIANGLES, 14);
		vao->addIndice(GL_TRIANGLES, 15);
		vao->addIndice(GL_TRIANGLES, 16);
		vao->addIndice(GL_TRIANGLES, 17);
		//cara izquierda
		vao->addIndice(GL_TRIANGLES, 18);
		vao->addIndice(GL_TRIANGLES, 19);
		vao->addIndice(GL_TRIANGLES, 20);
		vao->addIndice(GL_TRIANGLES, 21);
		vao->addIndice(GL_TRIANGLES, 22);
		vao->addIndice(GL_TRIANGLES, 23);
		//cara detras
		vao->addIndice(GL_TRIANGLES, 24);
		vao->addIndice(GL_TRIANGLES, 25);
		vao->addIndice(GL_TRIANGLES, 26);
		vao->addIndice(GL_TRIANGLES, 27);
		vao->addIndice(GL_TRIANGLES, 28);
		vao->addIndice(GL_TRIANGLES, 29);
		//cara arriba
		vao->addIndice(GL_TRIANGLES, 30);
		vao->addIndice(GL_TRIANGLES, 31);
		vao->addIndice(GL_TRIANGLES, 32);
		vao->addIndice(GL_TRIANGLES, 33);
		vao->addIndice(GL_TRIANGLES, 34);
		vao->addIndice(GL_TRIANGLES, 35);


		vao->addIndice(GL_POINTS, 0);
		vao->addIndice(GL_POINTS, 1);
		vao->addIndice(GL_POINTS, 2);
		vao->addIndice(GL_POINTS, 3);
		vao->addIndice(GL_POINTS, 4);
		vao->addIndice(GL_POINTS, 5);
		vao->addIndice(GL_POINTS, 6);
		vao->addIndice(GL_POINTS, 7);


		vao->addIndice(GL_LINES, 0);
		vao->addIndice(GL_LINES, 1);
		vao->addIndice(GL_LINES, 1);
		vao->addIndice(GL_LINES, 2);
		vao->addIndice(GL_LINES, 2);
		vao->addIndice(GL_LINES, 3);
		vao->addIndice(GL_LINES, 3);
		vao->addIndice(GL_LINES, 0);

		vao->addIndice(GL_LINES, 1);
		vao->addIndice(GL_LINES, 5);
		vao->addIndice(GL_LINES, 0);
		vao->addIndice(GL_LINES, 4);
		vao->addIndice(GL_LINES, 4);
		vao->addIndice(GL_LINES, 5);
		vao->addIndice(GL_LINES, 4);
		vao->addIndice(GL_LINES, 7);
		vao->addIndice(GL_LINES, 7);
		vao->addIndice(GL_LINES, 3);
		vao->addIndice(GL_LINES, 3);
		vao->addIndice(GL_LINES, 2);
		vao->addIndice(GL_LINES, 2);
		vao->addIndice(GL_LINES, 6);
		vao->addIndice(GL_LINES, 6);
		vao->addIndice(GL_LINES, 5);
		vao->addIndice(GL_LINES, 7);
		vao->addIndice(GL_LINES, 6);

		break;
	case PAG_TETRAEDRO:

		vao->addvertice(glm::vec3(-0.5, -0.5, 0));
		vao->addvertice(glm::vec3(0.5, -0.5, 0));
		vao->addvertice(glm::vec3(0, 0.5, 0));
		vao->addvertice(glm::vec3(0, 0.25, -0.5));


		vao->addIndice(GL_TRIANGLES, 0);
		vao->addIndice(GL_TRIANGLES, 1);
		vao->addIndice(GL_TRIANGLES, 2);

		vao->addIndice(GL_TRIANGLES, 1);
		vao->addIndice(GL_TRIANGLES, 3);
		vao->addIndice(GL_TRIANGLES, 2);

		vao->addIndice(GL_TRIANGLES, 3);
		vao->addIndice(GL_TRIANGLES, 0);
		vao->addIndice(GL_TRIANGLES, 2);

		vao->addIndice(GL_POINTS, 0);
		vao->addIndice(GL_POINTS, 1);
		vao->addIndice(GL_POINTS, 2);
		vao->addIndice(GL_POINTS, 3);


		vao->addIndice(GL_LINES, 0);
		vao->addIndice(GL_LINES, 1);
		vao->addIndice(GL_LINES, 1);
		vao->addIndice(GL_LINES, 2);
		vao->addIndice(GL_LINES, 2);
		vao->addIndice(GL_LINES, 0);

		vao->addIndice(GL_LINES, 0);
		vao->addIndice(GL_LINES, 3);
		vao->addIndice(GL_LINES, 1);
		vao->addIndice(GL_LINES, 3);
		vao->addIndice(GL_LINES, 3);
		vao->addIndice(GL_LINES, 2);
		break;


	}

	vao->generaArray();


}

void Pagmodelo::trasladar(float x, float y, float z)
{

	transformacion = glm::translate(transformacion, glm::vec3(x, y, z));
	posicion.x += x;
	posicion.y += y;
	posicion.z += z;
}

void Pagmodelo::rotar(glm::vec3 eje, float grados)
{
	transformacion = glm::translate(transformacion, -posicion);
	transformacion = glm::rotate(transformacion, grados, eje);
	transformacion = glm::translate(transformacion, posicion);
}

void Pagmodelo::escalar(float x, float y, float z)
{
	transformacion = glm::translate(transformacion, -posicion);
	transformacion = glm::scale(transformacion, glm::vec3(x, y, z));
	transformacion = glm::translate(transformacion, posicion);
}

glm::mat4 Pagmodelo::getTransformacion()
{
	return this->transformacion;
}

void Pagmodelo::añadirTextura(PAGtextura * textura)
{
	this->textura = textura;
}

PAGtextura * Pagmodelo::getTextura()
{
	return this->textura;
}

void Pagmodelo::pintate()
{
	vao->activaArray(modoVisualizacion);
	if (vao->listoparaDibujar())
		vao->pintaArray(modoVisualizacion);
	else {
		vao->activaArray(modoVisualizacion);
		vao->pintaArray(modoVisualizacion);
	}
}

void Pagmodelo::setMaterial(glm::vec3 ka, glm::vec3 kd, glm::vec3 ks, float sh)
{
	this->material->setKa(ka);
	this->material->setKd(kd);
	this->material->setKs(ks);
	this->material->setSh(sh);
}

void Pagmodelo::setMaterial(Pagmaterial * material)
{
	this->material = material;
}

void Pagmodelo::setModoVisualizacion(GLenum modo)
{
	modoVisualizacion = modo;
}

Pagmaterial * Pagmodelo::getMaterial()
{
	return this->material;
}




Pagmodelo::~Pagmodelo()
{
	delete vao;
	delete material;
}
