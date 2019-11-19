#include "PagRenderer.h"



PagRenderer * PagRenderer::instance = nullptr;

PagRenderer* PagRenderer::getInstance() {
	if (!instance) {
		instance = new PagRenderer();
	}
	return instance;
}

void PagRenderer::refreshCallback() {
	borraBuffers();
	bool primeraLuz = true;
	for (int i = 0; i < modelos.size(); i++) {
		for (auto program : programas) {

			for (auto luz : luces) {
				if (program->getTipoLuz() == luz->getTipoLuz()) {
					if (program != nullptr) {
						program->activar();
					}

					if (primeraLuz) {
						glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
						primeraLuz = false;
					}
					else {
						glBlendFunc(GL_SRC_ALPHA, GL_ONE);
					}

					auto mproyec = camara->mProyeccion();
					auto mvision = camara->mVision();
					auto mv = camara->mPv();
					auto modelo = modelos[i];
					auto material = modelo->getMaterial();

					program->setUniform("mModel", modelo->getTransformacion());
					program->setUniform("mModelViewProj", mv);
					program->setUniform("mModelView", mvision);
					program->setUniform("Ks", material->getKs());
					program->setUniform("Ia", luz->getIa());
					program->setUniform("Id", luz->getId());
					program->setUniform("Is", luz->getIs());
					program->setUniform("shininess", material->getSh());
					program->setUniform("TexSamplerColor", 0);

					auto textura = modelo->getTextura();
					textura->activarTextura(GL_TEXTURE0);



					PAGLuzPuntual* puntual = dynamic_cast<PAGLuzPuntual*>(luz);
					PAGfoco* foco = dynamic_cast<PAGfoco*>(luz);

					if (puntual) {
						program->setUniform("lightPosition", glm::vec3(mvision*glm::vec4(puntual->getPosicion(), 1.0f)));
					}

					if (foco) {
						program->setUniform("mvpMatrix", mv);
						program->setUniform("lightPosition", glm::vec3(mvision*glm::vec4(foco->getPosicion(), 1.0f)));
						program->setUniform("lightDirection", glm::normalize(glm::vec3(mvision*glm::vec4(foco->getDireccion(), 1.0f))));
						program->setUniform("spotAngle", foco->getAngulo());
					}

					modelo->pintate();

				}
			}
		}
	}

}
void PagRenderer::viewPort(int x, int y, int width, int heigh) {
	glViewport(x, y, width, heigh);

	camara->setAlto(heigh);
	camara->setAncho(width);


}


void PagRenderer::colorFondo(float red, float green, float blue) {

	glClearColor(red, green, blue, 1.0);
}

void PagRenderer::addColorBorrado(GLclampf incR, GLclampf incG, GLclampf incB, GLclampf incA)
{
	colorBorrado[0] += incR;
	colorBorrado[1] += incG;
	colorBorrado[2] += incB;
	colorBorrado[3] += incA;
	glClearColor(colorBorrado[0], colorBorrado[1], colorBorrado[2], colorBorrado[3]);
}

void PagRenderer::addColorBorrado(GLclampf inc)
{
	for (int i = 0; i < 4; i++)
	{
		colorBorrado[i] += inc;
	}
	glClearColor(colorBorrado[0], colorBorrado[1], colorBorrado[2], colorBorrado[3]);
}

void PagRenderer::setColorBorrado(GLclampf incR, GLclampf incG, GLclampf incB, GLclampf incA)
{
	colorBorrado[0] = incR;
	colorBorrado[1] = incG;
	colorBorrado[2] = incB;
	colorBorrado[3] = incA;
	glClearColor(colorBorrado[0], colorBorrado[1], colorBorrado[2], colorBorrado[3]);
}

void PagRenderer::activaZBuffer()
{
	glEnable(GL_DEPTH_TEST);
}

void PagRenderer::activarLuces()
{
	glEnable(GL_BLEND);
	glDepthFunc(GL_LEQUAL);
}

void PagRenderer::addShaderProgram(std::string nombreBase, PAGstipoluz tipo)
{
	PAGshaderProgram *program = new PAGshaderProgram();
	try {
		program->creaShaderProgram(nombreBase, tipo);
		programas.push_back(program);
	}
	catch (std::runtime_error &e) { std::cerr << "Error al crear el shader" << std::endl; }



}

void PagRenderer::borraBuffers()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void PagRenderer::addModelo(Pagmodelo::tipoModelo tipo)
{
	Pagmodelo* modelo = new Pagmodelo(tipo);
	modelo->setModoVisualizacion(GL_TRIANGLES);
	modelos.push_back(modelo);
}

void PagRenderer::addModelo(Pagmodelo::tipoModelo tipo, GLenum tipopintar, Pagmaterial *material, PAGtextura *textura)
{
	Pagmodelo* modelo = new Pagmodelo(tipo);
	modelo = new Pagmodelo(tipo);
	modelo->setModoVisualizacion(tipopintar);
	modelo->setMaterial(material);
	modelo->añadirTextura(textura);

	modelos.push_back(modelo);

}


void PagRenderer::addModelo(std::string archivo, GLenum tipopintar, Pagmaterial *material, PAGtextura *textura)
{
	Pagmodelo* modelo = new Pagmodelo(archivo);
	modelo->setModoVisualizacion(tipopintar);
	modelo->setMaterial(material);
	modelo->añadirTextura(textura);

	modelos.push_back(modelo);

}



void PagRenderer::vistaPlanta()
{
	GLfloat x, y, z, x0, y0, z0, ux, uy, uz;
	x = 0;
	y = 5;
	z = 0;

	x0 = 0;
	y0 = 0;
	z0 = 0;

	ux = 1;
	uy = 0;
	uz = 0;



	camara->setPosicion(x, y, z);
	camara->setLookAt(x0, y0, z0);
	camara->setUp(ux, uy, uz);
}

void PagRenderer::vistaAlzado()
{
	GLfloat x, y, z, x0, y0, z0, ux, uy, uz;
	x = 5;
	y = 0;
	z = 0;

	x0 = 0;
	y0 = 0;
	z0 = 0;

	ux = 0;
	uy = 1;
	uz = 0;



	camara->setPosicion(x, y, z);
	camara->setLookAt(x0, y0, z0);
	camara->setUp(ux, uy, uz);
}

void PagRenderer::vistaPerfil()
{
	GLfloat x, y, z, x0, y0, z0, ux, uy, uz;
	x = 0;
	y = 0;
	z = 5;

	x0 = 0;
	y0 = 0;
	z0 = 0;

	ux = 0;
	uy = 1;
	uz = 0;



	camara->setPosicion(x, y, z);
	camara->setLookAt(x0, y0, z0);
	camara->setUp(ux, uy, uz);
}

void PagRenderer::vistaDiagonal()
{
	GLfloat x, y, z, x0, y0, z0, ux, uy, uz;
	x = 3.3;
	y = 3;
	z = 3;

	x0 = 0;
	y0 = 0;
	z0 = 0;

	ux = 0;
	uy = 1;
	uz = 0;



	camara->setPosicion(x, y, z);
	camara->setLookAt(x0, y0, z0);
	camara->setUp(ux, uy, uz);
}

void PagRenderer::moverCamara(PAGstipomovimiento tipo, double factorX, double factorY)
{
	switch (tipo)
	{
	case PAG_TTILT:
		camara->tilt(factorY);
		break;
	case PAG_PAN:
		camara->pan(factorX);
		break;
	case PAG_TRUCK:
		camara->truckDolly(factorX, factorY);
		break;
	case PAG_BOOM:
		camara->boom(factorY);
		break;
	case PAG_ORBIT:
		camara->orbit(-factorY, -factorX);
		break;
	case PAG_ZOOM:
		camara->zoom(factorY);
		break;
	case PAG_NONE:
		break;
	default:
		break;
	}
}

void PagRenderer::addLuzPuntual(glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _Ia, glm::vec3 posicion)
{
	PAGLuzPuntual *luz = new PAGLuzPuntual(PAGstipoluz::PUNTUAL, _Id, _Is, _Ia, posicion);

	this->luces.push_back(luz);
}

void PagRenderer::addFoco(glm::vec3 _Id, glm::vec3 _Is, glm::vec3 _Ia, glm::vec3 posicion, glm::vec3 direccion, float angulo)
{
	PAGfoco *luz = new PAGfoco(PAGstipoluz::SPOT, _Id, _Is, _Ia, posicion, direccion, angulo);

	this->luces.push_back(luz);
}

void PagRenderer::addLuzAmbiente(glm::vec3 _Ia)
{
	Pagluz *luz = new Pagluz(PAGstipoluz::AMBIENTE, glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), _Ia);
	this->luces.push_back(luz);
}

void PagRenderer::rotarModelo(glm::vec3 eje, float grados)
{
	this->modelos[modeloactivo]->rotar(eje, grados);
}

void PagRenderer::trasladarModelo(float x, float y, float z)
{
	this->modelos[modeloactivo]->trasladar(x, y, z);
}

void PagRenderer::escalarModelo(float x, float y, float z)
{
	this->modelos[modeloactivo]->escalar(x, y, z);
}

int PagRenderer::getModeloActivo()
{
	return modeloactivo;
}

void PagRenderer::setModeloActivo(int x)
{
	this->modeloactivo = modeloactivo;
}

PagRenderer::PagRenderer()
{
	camara = new PAGcamara();
	vistaDiagonal();
	camara->setZnear(0.01);
	camara->setZfar(20.0);
	camara->setFovXSex(20.0);

}


PagRenderer::~PagRenderer()
{
	delete camara;

	for (auto p : modelos)
	{
		delete p;
	}
	for (auto p : programas)
	{
		delete p;
	}



	delete instance;
}
