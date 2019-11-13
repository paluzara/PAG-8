#include "PAGfoco.h"



PAGfoco::PAGfoco(PAGstipoluz tipo,glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _Ia, glm::vec3 _posicion, glm::vec3 _direccion,float _angulo):Pagluz(tipo,_Id,_Is,_Ia),posicion(_posicion),direccion(_direccion),angulo(_angulo)
{
	
}


PAGfoco::~PAGfoco()
{
}

void PAGfoco::setPosicion(glm::vec3 _posicion)
{
	this->posicion = _posicion;
}

void PAGfoco::setDireccion(glm::vec3 _direccion)
{
	this->direccion = _direccion;
}

void PAGfoco::setAngulo(float _angulo)
{
	this->angulo = _angulo;
}

glm::vec3 PAGfoco::getPosicion()
{
	return this->posicion;
}

glm::vec3 PAGfoco::getDireccion()
{
	return this->direccion;
}

float PAGfoco::getAngulo()
{
	return this->angulo;
}
