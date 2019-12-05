
#include "Pagmodelo.h"
#include "PAGperfilSubdivision.h"


class PAGmodeloRevolucion :public Pagmodelo
{
	PAGperfilSubdivision perfil;
	Pagvao *vaoTapaArriba;
	Pagvao *vaoTapaAbajo;

public:
	PAGmodeloRevolucion();
	~PAGmodeloRevolucion();
	PAGmodeloRevolucion(std::vector<glm::vec2> puntos,
		unsigned int subdivisiones,
		unsigned int lonchas);	bool esValido();		 	void pintate() override;
};

