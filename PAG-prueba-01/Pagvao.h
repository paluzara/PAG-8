
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

	std::vector<GLuint> indicesPuntos;
	std::vector<GLuint> indicesAlambre;
	std::vector<GLuint> indicesSolido;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normales;


	

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

};

