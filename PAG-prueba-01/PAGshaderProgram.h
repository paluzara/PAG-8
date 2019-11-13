#include <string>
#include <iostream>
#include <GL\glew.h>
#include <fstream>
#include <glm.hpp>
#include "PAGvalues.h"


class PAGshaderProgram
{

	GLuint identificador;
	bool enlazado;
	std::string mensajeGLSL;

	PAGstipoluz tipo;
	

	GLuint compilar(std::string nombreArchivo, GLenum tipoShader);

public:
	PAGshaderProgram();
	~PAGshaderProgram();
	void activar();
	GLuint creaShaderProgram(std::string nombreBase);
	GLuint creaShaderProgram(std::string nombreBase, PAGstipoluz tipo);

	std::string getMensajeGLSL();
	PAGstipoluz getTipoLuz();

	void setUniform(std::string nombre,GLint valor);
	void setUniform(std::string nombre,GLfloat valor);
	void setUniform(std::string nombre,glm::vec3 valor);
	void setUniform(std::string nombre,glm::mat4 valor);

};

