
#include <iostream>
#include <GL\glew.h>
#include <vector>
#include <glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx/normal.hpp>


class Pagvao
{
	GLuint identificador;
	GLuint vboVertices;
	GLuint _iboPuntos;
	GLuint _iboAlambre;
	GLuint _iboSolido;
	bool listo;
	GLuint vbocoordText;
	GLuint vboTangentes;

	std::vector<GLuint> indicesPuntos;
	std::vector<GLuint> indicesAlambre;
	std::vector<GLuint> indicesSolido;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normales;
	std::vector<glm::vec2> coordText;
	std::vector<glm::vec3> tangentes;
	


	

public:
	Pagvao();
	~Pagvao();
	void addvertice(glm::vec3 vertice);
	
	void addtriangulo(glm::vec3 vertice, glm::vec3 vertice1, glm::vec3 vertice2);

	void addIndice(GLenum modoDibujo,GLuint valor);
	void generaArray();
	void activaArray(GLenum modoDibujo);
	void pintaArray(GLenum modoDibujo);
	bool listoparaDibujar();
	void addTodo(glm::vec3 vertice, glm::vec3 vertice1, glm::vec3 vertice2,glm::vec2 coordenada, glm::vec2 coordenada1, glm::vec2 coordenada2);
	void addverticenormal(glm::vec3 vertice, glm::vec3 normal);
	void addCoorText(glm::vec2 coord);
	void addTangete(glm::vec3 tangente);
	void setVer(std::vector<glm::vec3> vertices);
	void setNorm(std::vector<glm::vec3> vertices);
	void setCoordt(std::vector<glm::vec2> vertices);
	void setIndices(std::vector<GLuint> indicesSolido);
	void setTangents(std::vector<glm::vec3> tangents);
};

