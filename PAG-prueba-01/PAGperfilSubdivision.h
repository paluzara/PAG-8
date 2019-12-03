
#include <iostream>
#include <GL\glew.h>
#include <vector>
#include <glm.hpp>


class PAGperfilSubdivision
{
public:
	PAGperfilSubdivision();
	PAGperfilSubdivision(std::vector<glm::vec2> puntos);
	~PAGperfilSubdivision();

	PAGperfilSubdivision subdivide(unsigned int nVeces);
};

