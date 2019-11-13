#pragma once

#include <iostream>
#include <GL\glew.h>
#include <vector>
#include <glm.hpp>

class Pagmaterial
{
	glm::vec3 Ka;
	glm::vec3 Kd;
	glm::vec3 Ks;
	float Sh;



public:
	Pagmaterial();
	Pagmaterial(glm::vec3 Ka,glm::vec3 Kd,glm::vec3 Ks,float Sh);

	~Pagmaterial();

	void setKa(glm::vec3 ka);
	void setKd(glm::vec3 kd);
	void setKs(glm::vec3 ks);
	void setSh(float sh);

	glm::vec3 getKa();
	glm::vec3 getKd();
	glm::vec3 getKs();
	float getSh();
};

