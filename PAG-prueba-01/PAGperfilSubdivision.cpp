#include "PAGperfilSubdivision.h"



PAGperfilSubdivision::PAGperfilSubdivision()
{
}

PAGperfilSubdivision::PAGperfilSubdivision(std::vector<glm::vec2> puntos)
{
	bool tapaSuperior=false ,tapaInferior=false;

	for (int i = 0; i < puntos.size(); i++) {
		auto p = puntos[i];
		if (i == 0 && p[0] == 0)
			tapaSuperior = true;
		if (i == puntos.size() && p[0] == 0)
			tapaInferior = true;

		if (p[0] < 0) {
			puntos.erase(puntos.begin() + i);
		}

	}
}


PAGperfilSubdivision::~PAGperfilSubdivision()
{
}

PAGperfilSubdivision PAGperfilSubdivision::subdivide(unsigned int nVeces)
{
	return PAGperfilSubdivision();
}
