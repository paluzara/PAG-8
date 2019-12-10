#include "Pagmaterial.h"



Pagmaterial::Pagmaterial()
{
	this->Ka = glm::vec3(1,1,1);
	this->Kd = glm::vec3(1, 1, 1);
	this->Ks = glm::vec3(1, 1, 1);
	this->Sh = 10;
}

Pagmaterial::Pagmaterial(glm::vec3 _Ka, glm::vec3 _Kd, glm::vec3 _Ks, float _Sh):Ka(_Ka),Kd(_Kd),Ks(_Ks),Sh(_Sh)
{
}


Pagmaterial::~Pagmaterial()
{
}

void Pagmaterial::setKa(glm::vec3 ka)
{
	this->Ka = ka;
}

void Pagmaterial::setKd(glm::vec3 kd)
{
	this->Kd = kd;
}

void Pagmaterial::setKs(glm::vec3 ks)
{
	this->Ks = ks;
}

void Pagmaterial::setSh(float sh)
{
	this->Sh = sh;
}

glm::vec3  Pagmaterial::getKa()
{
	return this->Ka;
}

glm::vec3  Pagmaterial::getKd()
{
	return this->Kd;
}

glm::vec3 Pagmaterial::getKs()
{
	return this->Ks;
}

float Pagmaterial::getSh()
{
	return this->Sh;
}
