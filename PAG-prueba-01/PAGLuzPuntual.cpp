#include "PAGLuzPuntual.h"



PAGLuzPuntual::PAGLuzPuntual(PAGstipoluz tipo, glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _Ia , glm::vec3 _posicion):Pagluz(tipo,_Id, _Is, _Ia), posicion(_posicion)
{
}


PAGLuzPuntual::~PAGLuzPuntual()
{
}

void PAGLuzPuntual::setPosicion(glm::vec3 _posicion)
{
	this->posicion = _posicion;
}

glm::vec3 PAGLuzPuntual::getPosicion()
{
	return this->posicion;
}
