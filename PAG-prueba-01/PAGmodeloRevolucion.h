
#include "Pagmodelo.h"


class PAGmodeloRevolucion :public Pagmodelo
{
public:
	PAGmodeloRevolucion();
	~PAGmodeloRevolucion();
	PAGmodeloRevolucion(std::vector<glm::vec2> puntos,
		unsigned int subdivisiones,
		unsigned int lonchas);
};

