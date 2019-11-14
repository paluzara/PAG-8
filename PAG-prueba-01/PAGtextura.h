
#include <iostream>
#include"lodepng.h"
#include <GL/glew.h>
#include <glm.hpp>


class PAGtextura
{
	GLuint texture;
	GLenum gltexture;
	std::vector<unsigned char> image;
	unsigned width, heigth;



public:
	PAGtextura(std::string filename);
	~PAGtextura();

	void activarTextura(GLenum numero);

	
};

