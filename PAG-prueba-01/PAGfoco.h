
#include "Pagluz.h"

class PAGfoco:public Pagluz
{
	glm::vec3 posicion;
	glm::vec3 direccion;
	float angulo;

public:
	PAGfoco(PAGstipoluz tipo,glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _Ia ,glm::vec3 posicion, glm::vec3 direccion,float angulo);
	~PAGfoco();

	void setPosicion(glm::vec3 _posicion);
	void setDireccion(glm::vec3 _direccion);
	void setAngulo(float _angulo);

	glm::vec3 getPosicion();
	glm::vec3 getDireccion();
	float getAngulo();

};

