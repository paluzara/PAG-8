#include "PAGmodeloRevolucion.h"



PAGmodeloRevolucion::PAGmodeloRevolucion():Pagmodelo()
{
}


PAGmodeloRevolucion::~PAGmodeloRevolucion()
{
}

PAGmodeloRevolucion::PAGmodeloRevolucion(std::vector<glm::vec2> puntos, unsigned int subdivisiones, unsigned int lonchas):perfil(puntos)
{
	vao = new Pagvao();

	auto perfildividido = perfil.subdivide(subdivisiones);
	perfil = perfildividido;

	auto p = perfil.getPuntos();
	
	auto delta = 360 / lonchas;
//Vertices y normales
	auto normales=perfil.calcularNormales();
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j <= lonchas; j++) { //cuidado el igual
			float angulo = lonchas * delta;
			auto punto = puntos[i];
			auto normal = normales[i];
			glm::vec3 pprima(punto[0]*cos(angulo),punto[1]-punto[0],-punto[0]*sin(angulo));
			glm::vec3 nprima(normal[0] * cos(angulo), normal[1] - normal[0], -normal[0] * sin(angulo));
			vao->addverticenormal(pprima, nprima);
		}
	}
//Indices
	for (int s = 0; s < lonchas; s++) { //aqui sin el igual
		for (int i = 0; i < p.size(); i++) {
			int indice1 =(i*(s+1))+s ;
			int indice2 =(i*(s+1))+(s+1) ;
			vao->addIndice(GL_TRIANGLE_STRIP, indice1);
			vao->addIndice(GL_TRIANGLE_STRIP,indice2);
		}
		vao->addIndice(GL_TRIANGLE_STRIP, 0xFFFF);
	}

//Coordenadas de textura
	float incrementoX = 0;
	for (int s = 0; s < lonchas; s++) {
		float incrementoy = 0;
		
		for (int pp = 0; pp < p.size(); pp++) {
			incrementoy += 1 / p.size();
			vao->addCoorText(glm::vec2(incrementoX, incrementoy));
	}
		incrementoX += 1 / lonchas;
}

// Tangentes
	




	
	

}

bool PAGmodeloRevolucion::esValido()
{
	return !perfil.Size() <= 1;
}
