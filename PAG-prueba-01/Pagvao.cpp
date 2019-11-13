#include "Pagvao.h"



void Pagvao::addvertice(glm::vec3 vertice)
{
	vertices.push_back(vertice);
}



void Pagvao::addtriangulo(glm::vec3 vertice, glm::vec3 vertice1, glm::vec3 vertice2)
{
	auto normal = glm::triangleNormal(vertice,vertice1,vertice2);
	normales.push_back(vertice);
	normales.push_back(normal);
	normales.push_back(vertice1);
	normales.push_back(normal);
	normales.push_back(vertice2);
	normales.push_back(normal);
}

void Pagvao::addIndice(GLenum modoDibujo, GLuint valor)
{
	switch (modoDibujo) {
	case GL_POINTS:
		indicesPuntos.push_back(valor);
		break;
	case GL_LINES:
		indicesAlambre.push_back(valor);
		break;
	case GL_TRIANGLES:
		indicesSolido.push_back(valor);
		break;

	}
}

void Pagvao::generaArray()
{

	glGenVertexArrays(1, &identificador);
	glBindVertexArray(identificador);

	glGenBuffers(1, &vboVertices);
	glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, sizeof(glm::vec3) / sizeof(GLfloat),GL_FLOAT, GL_FALSE, sizeof(glm::vec3)*2,
		((GLubyte *)NULL + (0)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, sizeof(glm::vec3) / sizeof(GLfloat),GL_FLOAT, GL_FALSE, sizeof(glm::vec3)*2,
		((GLubyte *)NULL +(sizeof(glm::vec3))));


	//Vertices + normales
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*normales.size(), normales.data(),
		GL_STATIC_DRAW);

	//Texturas
	glGenBuffers(1, &vbocoordText);
	glBindBuffer(GL_ARRAY_BUFFER, vbocoordText);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, sizeof(glm::vec2) / sizeof(GLfloat), GL_FLOAT, GL_FALSE, sizeof(glm::vec2), nullptr);
	glBufferData(GL_ARRAY_BUFFER, coordText.size() * sizeof(glm::vec2), coordText.data(), GL_STATIC_DRAW);

	

	glGenBuffers(1, &_iboSolido);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _iboSolido);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indicesSolido.size(),
		indicesSolido.data(), GL_STATIC_DRAW);
	glGenBuffers(1, &_iboPuntos);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _iboPuntos);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indicesPuntos.size(),
		indicesPuntos.data(), GL_STATIC_DRAW);
	glGenBuffers(1, &_iboAlambre);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _iboAlambre);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indicesAlambre.size(),
		indicesAlambre.data(), GL_STATIC_DRAW);

}

void Pagvao::activaArray(GLenum modoDibujo)
{
	glBindVertexArray(identificador);
	glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
	switch (modoDibujo)
	{
	case GL_TRIANGLES:
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _iboSolido);
		break;
	case GL_LINES:
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _iboAlambre);
		break;
	case GL_POINTS:
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _iboPuntos);
		break;
	}
	
	listo = true;
}

void Pagvao::pintaArray(GLenum modoDibujo)
{
	switch (modoDibujo)
	{
	case GL_TRIANGLES:
		glDrawElements(GL_TRIANGLES, indicesSolido.size(), GL_UNSIGNED_INT, NULL);
		break;
	case GL_LINES:
		glDrawElements(GL_LINES, indicesAlambre.size(), GL_UNSIGNED_INT, NULL);
		break;
	case GL_POINTS:
		glDrawElements(GL_POINTS, indicesPuntos.size(), GL_UNSIGNED_INT, NULL);
		break;
	}

}

bool Pagvao::listoparaDibujar()
{
	return listo;
	
}

void Pagvao::addTodo(glm::vec3 vertice, glm::vec3 vertice1, glm::vec3 vertice2, glm::vec2 coordenada, glm::vec2 coordenada1, glm::vec2 coordenada2)
{
	auto normal = glm::triangleNormal(vertice, vertice1, vertice2);
	normales.push_back(vertice);
	normales.push_back(normal);
	coordText.push_back(coordenada);
	normales.push_back(vertice1);
	normales.push_back(normal);
	coordText.push_back(coordenada1);
	normales.push_back(vertice2);
	normales.push_back(normal);
	coordText.push_back(coordenada2);
}



Pagvao::Pagvao()
{
}


Pagvao::~Pagvao()
{
}
