
#include "Pagluz.h"

class PAGLuzPuntual:public Pagluz
{


glm::vec3 posicion;


public:
	PAGLuzPuntual(PAGstipoluz tipo,glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _Ia , glm::vec3 posicion);
	~PAGLuzPuntual();

	void setPosicion(glm::vec3 posicion);
	glm::vec3 getPosicion();

};

