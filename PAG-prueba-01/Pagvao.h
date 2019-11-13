
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

	std::vector<GLuint> indicesPuntos;
	std::vector<GLuint> indicesAlambre;
	std::vector<GLuint> indicesSolido;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normales;
	std::vector<glm::vec2> coordText;
	


	

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

};

