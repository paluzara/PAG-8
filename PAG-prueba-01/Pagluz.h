#pragma once
#include "PAGvalues.h"
#include <iostream>
#include <GL\glew.h>
#include <vector>
#include <glm.hpp>

class Pagluz
{
	
	PAGstipoluz tipo;
	glm::vec3 Id;
	glm::vec3 Is;
	glm::vec3 Ia;
	


public:

	void setTipoLuz(PAGstipoluz tipo);
	PAGstipoluz getTipoLuz();

	void setId(glm::vec3 _id);
	void setIs(glm::vec3 _is);
	void setIa(glm::vec3 _ia);

	glm::vec3 getId();
	glm::vec3 getIs();
	glm::vec3 getIa();


	Pagluz(PAGstipoluz _tipo, glm::vec3 Id, glm::vec3 Is, glm::vec3 Ia);
	virtual ~Pagluz();
};

