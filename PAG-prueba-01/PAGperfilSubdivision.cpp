#include "PAGperfilSubdivision.h"



PAGperfilSubdivision::PAGperfilSubdivision()
{
}

PAGperfilSubdivision::PAGperfilSubdivision(std::vector<glm::vec2> puntos)
{
	this->tapaSuperior = false;
	this->tapaInferior = false;

	for (int i = 0; i < puntos.size(); i++) {
		auto p = puntos[i];
		if (i == 0 && p[0] == 0)
			this->tapaSuperior = true;
		if (i == puntos.size()-1 && p[0] == 0)
			this->tapaInferior = true;

		if (p[0] < 0) {
			puntos.erase(puntos.begin() + i);
		}

	}
	this->puntos = puntos;
}


PAGperfilSubdivision::~PAGperfilSubdivision()
{
}

bool PAGperfilSubdivision::hayTapaSuperior()
{
	return tapaSuperior;
}

bool PAGperfilSubdivision::hayTapaInferior()
{
	return tapaInferior;
}

int PAGperfilSubdivision::Size()
{
	return this->puntos.size();
}

std::vector<glm::vec2> PAGperfilSubdivision::getPuntos()
{
	return puntos;
}

std::vector<glm::vec2> PAGperfilSubdivision::calcularNormales()
{
	normales.push_back(glm::vec2(0, 1));

	for (int i = 1; i < puntos.size() - 1; i++) {
		auto p0 = puntos[i - 1];
		auto p1 = puntos[i];
		auto p2 = puntos[i + 1];
		
		auto vi = glm::normalize(p2 - p1);
		auto vimenos1 = glm::normalize(p1 - p0);
		glm::vec2 n(vi[1], -vi[0]);
		glm::vec2 nvimenos(vimenos1[1], -vimenos1[0]);
		glm::vec2 normalfinal=(n + nvimenos) / 2.0f;
		normales.push_back(normalfinal);

	}
	normales.push_back(glm::vec2(0, -1));

	return normales;
}

PAGperfilSubdivision PAGperfilSubdivision::subdivide(unsigned int nVeces)
{
	
	std::vector<glm::vec2> auxiliar;
	auxiliar = puntos;

	std::vector<glm::vec2> pprima;


	for (int j = 0; j < nVeces; j++) {

		pprima.push_back(auxiliar[0]);
		for (int i = 0; i < auxiliar.size() - 2; i++) {
			auto p1 = auxiliar[i];
			auto p2 = auxiliar[i + 1];
			auto pmedio = (p1 + p2) / 2.0f;
			auto pcalc = ((3.0f * p2) / 4.0f) + ((p1) / 8.0f) + ((p2) / 8.0f);
			pprima.push_back(pmedio);
			pprima.push_back(pcalc);
		}
		auto p1 = auxiliar[auxiliar.size() - 2];
		auto p2 = auxiliar[auxiliar.size() - 1];
		auto pmedio = (p1 + p2) / 2.0f;
		pprima.push_back(pmedio);
		pprima.push_back(p2);

		auxiliar = pprima;

	}
	return PAGperfilSubdivision(pprima);
}
