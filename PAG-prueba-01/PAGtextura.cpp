#include "PAGtextura.h"



PAGtextura::PAGtextura(std::string filename) 
{
	
	
	
	
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	
	std::vector<unsigned char> image; // Los píxeles de la imagen
	unsigned width, height;
	unsigned error = lodepng::decode(image, width, height, filename);
	if (error)
	{
		std::string message = filename + " can not be loaded";
			throw std::runtime_error(message);
	}
	// La textura se carga del revés, así que vamos a darle la vuelta
	unsigned char *imgPtr = &image[0];
	int numColorComponents = 4;
	int wInc = width * 4; //width in char
	unsigned char* top = nullptr;
	unsigned char* bot = nullptr;
	unsigned char temp = 0;
	for (int i = 0; i < height / 2; i++)
	{
		top = imgPtr + i * wInc;
		bot = imgPtr + (height - i - 1) * wInc;
		for (int j = 0; j < wInc; j++)
		{
			temp = *top;
			*top = *bot;
			*bot = temp;
			++top;
			++bot;
		}
	}
	
		// Finalmente, pasamos la textura a OpenGL
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
		0, GL_RGBA, GL_UNSIGNED_BYTE, image.data());
	glGenerateMipmap(GL_TEXTURE_2D);
}


PAGtextura::~PAGtextura()
{
}
