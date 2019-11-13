
#include <iostream>
#include"lodepng.h"
#include <GL/glew.h>
#include <glm.hpp>


class PAGtextura
{
	GLuint texture;

public:
	PAGtextura(std::string filename);
	~PAGtextura();
};

