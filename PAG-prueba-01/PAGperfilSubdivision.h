
#include <iostream>
#include <GL\glew.h>
#include <vector>
#include <glm.hpp>


class PAGperfilSubdivision
{

	std::vector<glm::vec2> puntos;
	std::vector<glm::vec2> normales;

	bool tapaSuperior;
	bool tapaInferior;


public:
	PAGperfilSubdivision();
	PAGperfilSubdivision(std::vector<glm::vec2> puntos);
	~PAGperfilSubdivision();
	bool hayTapaSuperior();
	bool hayTapaInferior();
	int Size();
	std::vector<glm::vec2> getPuntos();

	std::vector<glm::vec2> calcularNormales();

	PAGperfilSubdivision subdivide(unsigned int nVeces);
};

