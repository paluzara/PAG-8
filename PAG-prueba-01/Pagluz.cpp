#include "Pagluz.h"



void Pagluz::setTipoLuz(PAGstipoluz tipo)
{
	this->tipo = tipo;
}

PAGstipoluz Pagluz::getTipoLuz()
{
	return this->tipo;
}

void Pagluz::setId(glm::vec3 _id)
{
	this->Id = _id;
}

void Pagluz::setIs(glm::vec3 _is)
{
	this->Is = _is;
}

void Pagluz::setIa(glm::vec3 _ia)
{
	this->Ia = _ia;
}

glm::vec3 Pagluz::getId()
{
	return this->Id;
}

glm::vec3 Pagluz::getIs()
{
	return this->Is;
}

glm::vec3 Pagluz::getIa()
{
	return this->Ia;
}

Pagluz::Pagluz(PAGstipoluz _tipo,glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _Ia): tipo(_tipo),Id(_Id),Is(_Is),Ia(_Ia)
{
}


Pagluz::~Pagluz()
{
}
