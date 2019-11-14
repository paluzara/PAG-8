#include <iostream>
#include <cstdlib>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <string>
#include "PagRenderer.h"
#include "PAGstatus.h"


float red = 0.0;
float green = 0.0;
float blue = 0.6;

PAGstatus estado;


void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	if (key == GLFW_KEY_1 && action == GLFW_PRESS) { //  1 vista alzado
		PagRenderer::getInstance()->vistaAlzado();
	}
	if (key == GLFW_KEY_2 && action == GLFW_PRESS) { // 2 vista perfil
		PagRenderer::getInstance()->vistaPerfil();
	}
	if (key == GLFW_KEY_3 && action == GLFW_PRESS) { // 3 vista planta
		PagRenderer::getInstance()->vistaPlanta();
	}
	if (key == GLFW_KEY_4 && action == GLFW_PRESS) { // 4 vista diagonal (default)
		PagRenderer::getInstance()->vistaDiagonal();
	}
	if (key == GLFW_KEY_A && action == GLFW_PRESS) { //A tilt
		estado.setModoMovimiento(PAG_TTILT);
	}

	if (key == GLFW_KEY_F1 && action == GLFW_PRESS) { //F1 zoom
		estado.setModoMovimiento(PAG_ZOOM);
	}
	if (key == GLFW_KEY_F2 && action == GLFW_PRESS) { //F2 orbit
		estado.setModoMovimiento(PAG_ORBIT);
	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS) { // S Pan
		estado.setModoMovimiento(PAG_PAN);
	}
	if (key == GLFW_KEY_Q && action == GLFW_PRESS) {   // Q Boom
		estado.setModoMovimiento(PAG_BOOM);
	}
	if (key == GLFW_KEY_W && action == GLFW_PRESS) {     // W Truck
		estado.setModoMovimiento(PAG_TRUCK);
	}
	if (key == GLFW_KEY_P && action == GLFW_PRESS) {     // W Truck
		PagRenderer::getInstance()->escalarModelo(0.2,0.2 ,0.2 );
	}
}




void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
	PagRenderer::getInstance()->viewPort(0, 0, width, height);
	std::cout << "Resize callback called" << std::endl;
}


void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
	std::cout << "Movida la rueda del raton " << xoffset <<
		" Unidades en horizontal y " << yoffset << " unidades en vertical" << std::endl;
	if (yoffset > 0) {
		blue += 0.1;
		if (blue >= 1.0)
			blue = 1.0;
		PagRenderer::getInstance()->colorFondo(red, green, blue);
	}
	else if (yoffset < 0) {
		blue -= 0.1;
		if (blue < 0.0)
			blue = 0.0;
		PagRenderer::getInstance()->colorFondo(red, green, blue);
	}

}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
	if (action == GLFW_PRESS) {
		estado.setBotonIzqPulsado(true);
	}
	else if (action == GLFW_RELEASE)
	{
		estado.setBotonIzqPulsado(false);
	}
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	double antX, antY, difX,difY;
	if (estado.getBotonIzqPulsado()) {
		estado.getPosRaton(antX, antY);
		difX = xpos - antX;
		difY = ypos - antY;
		PagRenderer::getInstance()->moverCamara(estado.getModoMovimiento(),  difX*0.01 , difY*0.01);

	}

	std::cout << "Raton en" << xpos << "" << ypos << std::endl;
	estado.setPosRaton(xpos, ypos);
}



void window_refresh_callback(GLFWwindow *window) {	PagRenderer::getInstance()->refreshCallback();
	
}

void crearPrograma(std::string nombreBase, PAGstipoluz tipo) {
	PagRenderer::getInstance()->addShaderProgram(nombreBase,tipo);
}


int main() {
	glfwInit();

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	GLFWwindow* ventana;
	ventana = glfwCreateWindow(1024, 576, "Ventana 1", nullptr, nullptr);
	PagRenderer::getInstance()->viewPort(0, 0, 1024, 576);
	glfwMakeContextCurrent(ventana);

	glewExperimental = true;
	glewInit();


	glfwSetWindowRefreshCallback(ventana, window_refresh_callback);
	glfwSetFramebufferSizeCallback(ventana, framebuffer_size_callback);
	glfwSetKeyCallback(ventana, key_callback);
	glfwSetMouseButtonCallback(ventana, mouse_button_callback);
	glfwSetScrollCallback(ventana, scroll_callback);
	glfwSetCursorPosCallback(ventana, cursor_position_callback);

	glfwSetMouseButtonCallback(ventana, mouse_button_callback);
	

	

	PagRenderer::getInstance()->colorFondo(red, green, blue);
	PagRenderer::getInstance()->activaZBuffer();
	PagRenderer::getInstance()->activarLuces();
	
	
	crearPrograma("pr3foco", PAGstipoluz::SPOT);
	
	crearPrograma("pr3",PAGstipoluz::PUNTUAL);

	crearPrograma("pr3ambiente", PAGstipoluz::AMBIENTE);
	
	


	PagRenderer::getInstance()->addFoco(glm::vec3(0.0, 0.5, 0.0), glm::vec3(0.0, 0.5, 0.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0,0.75, 0),glm::vec3(1, 0.0, 0.0),glm::radians(3.0));
	PagRenderer::getInstance()->addLuzAmbiente(glm::vec3(0.1, 0.1, 0.1));
	PagRenderer::getInstance()->addLuzPuntual(glm::vec3 (0.7,0,0.5), glm::vec3(0.7, 0, 0.5), glm::vec3(0, 0, 0), glm::vec3(5,5, 5));
	

	
	


	Pagmaterial *blancoMetalico = new Pagmaterial(glm::vec3(1.0, 1.0, 1.0), glm::vec3(1.0, 1.0,1.0), glm::vec3(1.0, 1.0, 1.0), 0.25);
	PAGtextura * dado = new PAGtextura("dice_texture.png");


	PagRenderer::getInstance()->addModelo(Pagmodelo::PAG_CUBO,GL_TRIANGLES,blancoMetalico,dado);
	
	
	Pagmaterial *azulMetalico = new Pagmaterial(glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 0.0), 0.25);
	PagRenderer::getInstance()->addModelo(Pagmodelo::PAG_SUELO, GL_TRIANGLES,azulMetalico);
	

	
	
	while (!glfwWindowShouldClose(ventana))
	{
		PagRenderer::getInstance()->refreshCallback();
		
		glfwPollEvents();
		glfwSwapBuffers(ventana);
		
	}

	glfwTerminate();
	return 0;

}