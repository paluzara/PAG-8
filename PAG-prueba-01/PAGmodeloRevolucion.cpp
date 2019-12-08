#include "PAGmodeloRevolucion.h"



PAGmodeloRevolucion::PAGmodeloRevolucion():Pagmodelo()
{
}


PAGmodeloRevolucion::~PAGmodeloRevolucion()
{
	delete vaoTapaAbajo;
	delete vaoTapaArriba;
}

PAGmodeloRevolucion::PAGmodeloRevolucion(std::vector<glm::vec2> puntos, unsigned int subdivisiones, unsigned int lonchas):perfil(puntos)
{
	vao = new Pagvao();
	tranlacion = rotacion = escalado = glm::mat4(1.0f);
	posicion = glm::vec3(0, 0, 0);
	
	this->material = new Pagmaterial();

	



	auto perfildividido = perfil.subdivide(subdivisiones);
	perfil = perfildividido;

	auto p = perfil.getPuntos();
	
	auto delta = 360.0f / float(lonchas);
//Vertices  normales tangentes
	auto normales=perfil.calcularNormales();
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j <= lonchas; j++) { //cuidado el igual
			float angulo = float(j) * float(delta);
			auto punto = p[i];
			auto normal = normales[i];
			glm::vec3 pprima(punto[0]*cos(angulo),punto[1],-punto[0]*sin(angulo));
			glm::vec3 nprima(normal[0] * cos(angulo), normal[1], -normal[0] * sin(angulo));
			glm::vec3 tangente(-sin(angulo), 0, -cos(angulo));//esto puede estar mal no es angulo

			vao->addverticenormal(pprima, nprima);
			vao->addTangete(tangente);
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
		vao->addIndice(GL_TRIANGLE_STRIP, 0xFFFFFFFF);
	}

//Coordenadas de textura
	float incrementoX = 0;
	for (int s = 0; s < lonchas; s++) {
		float incrementoy = 0;
		
		for (int pp = 0; pp < p.size(); pp++) {
			incrementoy += 1 / p.size();
			vao->addCoorText(glm::vec2(incrementoX, incrementoy));
	}
		incrementoX +=( 1 / lonchas);
}


	
	vao->generaArray();


//tapa Arriba

	//Vertices Indices Normales tangntes
	if (perfil.hayTapaSuperior()) {
		vaoTapaArriba = new Pagvao();
		auto p0 = p[0];
		auto p1 = p[1];
		vaoTapaArriba->addverticenormal(glm::vec3(p0,0), glm::vec3(0, 1, 0));
		vaoTapaArriba->addIndice(GL_TRIANGLE_FAN, 0);
		vaoTapaArriba->addTangete(glm::vec3(1, 0, 0));
		vaoTapaArriba->addCoorText(glm::vec2(1, 1));

			for (int j = 0; j <= lonchas; j++) { //cuidado el igual
				float angulo = float(j)* float(delta);
				
			
				glm::vec3 pprima(p1[0] * cos(angulo), p1[1] , -p1[0] * sin(angulo));
			
				vaoTapaArriba->addverticenormal(pprima, glm::vec3(0,1,0));
				vaoTapaArriba->addTangete(glm::vec3(1,0,0));
				vaoTapaArriba->addIndice(GL_TRIANGLE_FAN, j+1);
				vaoTapaArriba->addCoorText(glm::vec2(1,1));
			}
		
			vaoTapaArriba->generaArray();
	}





	//tapa Abajo

	//Vertices Indices Normales
	if (perfil.hayTapaInferior()) {
		vaoTapaAbajo = new Pagvao();
		auto p0 = p[p.size()-1];
		auto p1 = p[p.size()-2];
		vaoTapaAbajo->addverticenormal(glm::vec3(p0, 0), glm::vec3(0, -1, 0));
		vaoTapaAbajo->addIndice(GL_TRIANGLE_FAN, 0);
		vaoTapaAbajo->addTangete(glm::vec3(1, 0, 0));
		vaoTapaAbajo->addCoorText(glm::vec2(1, 1));
		for (int j = 0; j <= lonchas; j++) { //cuidado el igual
			float angulo = float(lonchas) * delta;


			glm::vec3 pprima(p1[0] * cos(angulo), p1[1] , -p1[0] * sin(angulo));

			vaoTapaAbajo->addverticenormal(pprima, glm::vec3(0, -1, 0));
			vaoTapaAbajo->addIndice(GL_TRIANGLE_FAN, j+1);
			vaoTapaAbajo->addTangete(glm::vec3(1, 0, 0));
			vaoTapaAbajo->addCoorText(glm::vec2(1, 1));
		}

		vaoTapaAbajo->generaArray();
	}
	
	

}

bool PAGmodeloRevolucion::esValido()
{
	return !perfil.Size() <= 1;
}

 void PAGmodeloRevolucion::pintate()
{
	
		 vao->activaArray(GL_TRIANGLE_STRIP);
		 vao->pintaArray(GL_TRIANGLE_STRIP);
	
		 vaoTapaAbajo->activaArray(GL_TRIANGLE_FAN);
		 vaoTapaAbajo->pintaArray(GL_TRIANGLE_FAN);
	
		 vaoTapaArriba->activaArray(GL_TRIANGLE_FAN);
		 vaoTapaArriba->pintaArray(GL_TRIANGLE_FAN);
	 

}




