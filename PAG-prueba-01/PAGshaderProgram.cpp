#include "PAGshaderProgram.h"



GLuint PAGshaderProgram::compilar(std::string nombreArchivo, GLenum tipoShader)
{

	std::string  codigo;
	if (nombreArchivo != "") {
		std::ifstream fe; //Creamos un flujo de entrada
		std::string linea;

		// Asociamos el flujo con un fichero y lo abrimos
		fe.open(nombreArchivo);
		if (fe.good()) {
			while (!fe.eof()) {
				getline(fe, linea); // Toma una línea del fichero
				if (linea != "") { // Ignoramos líneas en blanco

					codigo += linea += "\n";

				}
			}
			fe.close(); //Cerramos el flujo de entrada
		}
		else {
			std::cerr << " No se puede abrir el fichero " << std::endl;
		}



	}


	GLuint idShader = 0;
	idShader = glCreateShader(tipoShader);
	const GLchar* fuenteVS = codigo.c_str();
	glShaderSource(idShader, 1, &fuenteVS, nullptr);
	glCompileShader(idShader);


	GLint resultadoCompilacion = 0;
	glGetShaderiv(idShader, GL_COMPILE_STATUS, &resultadoCompilacion);
	if (resultadoCompilacion == GL_FALSE)
	{
		GLint tamMensaje = 0;

		glGetShaderiv(idShader, GL_INFO_LOG_LENGTH, &tamMensaje);
		if (tamMensaje > 0)
		{
			GLchar* textoMensaje = new GLchar[tamMensaje];
			if (textoMensaje == nullptr)
			{
				throw std::runtime_error("error reservando memoria");
			}

			GLint numCaracteres = 0;
			glGetShaderInfoLog(idShader, tamMensaje, &numCaracteres, textoMensaje);
			mensajeGLSL += textoMensaje;
			delete textoMensaje;
		}
		throw std::runtime_error("compilar: error al compilar " + mensajeGLSL);
	}


	return idShader;
}



void PAGshaderProgram::activar()
{
	glUseProgram(identificador);

}

GLuint PAGshaderProgram::creaShaderProgram(std::string nombreBase)
{
	identificador = glCreateProgram();
	GLuint miVS;
	GLuint miFS;
	try {
		miVS = compilar(nombreBase + "-vert.glsl", GL_VERTEX_SHADER);
		miFS = compilar(nombreBase + "-frag.glsl", GL_FRAGMENT_SHADER);

		glAttachShader(identificador, miVS);
		glAttachShader(identificador, miFS);
	}
	catch (std::exception& e) { std::cerr << "Error al comilar el Shader"; };

	glLinkProgram(identificador);


	GLint resultadoEnlazado = 0;
	glGetProgramiv(identificador, GL_LINK_STATUS, &resultadoEnlazado);


	//Comprobamos si enlaza bien
	if (resultadoEnlazado == GL_FALSE)
	{
		GLint tamMensaje = 0;

		glGetProgramiv(identificador, GL_INFO_LOG_LENGTH, &tamMensaje);

		if (tamMensaje > 0)
		{
			GLchar* textoMensaje = new GLchar[tamMensaje];
			if (textoMensaje == nullptr)
			{
				throw std::runtime_error("error reservando memoria");
			}
			GLint numCaracteres = 0;
			glGetProgramInfoLog(identificador, tamMensaje, &numCaracteres,
				textoMensaje);
			mensajeGLSL += textoMensaje;
			delete textoMensaje;
		}
		throw std::runtime_error("creaShaderProgram: error al enlazar el programa "
			+ nombreBase + ": " + mensajeGLSL);
	}
	else {
		enlazado = true;
	}
	
	glDeleteShader(miVS);
	glDeleteShader(miFS);
	return identificador;
}

GLuint PAGshaderProgram::creaShaderProgram(std::string nombreBase, PAGstipoluz tipo)
{
	identificador = glCreateProgram();
	GLuint miVS;
	GLuint miFS;
	try {
		miVS = compilar(nombreBase + "-vert.glsl", GL_VERTEX_SHADER);
		miFS = compilar(nombreBase + "-frag.glsl", GL_FRAGMENT_SHADER);

		glAttachShader(identificador, miVS);
		glAttachShader(identificador, miFS);
	}
	catch (std::exception& e) { std::cerr <<e.what(); };

	glLinkProgram(identificador);


	GLint resultadoEnlazado = 0;
	glGetProgramiv(identificador, GL_LINK_STATUS, &resultadoEnlazado);


	//Comprobamos si enlaza bien
	if (resultadoEnlazado == GL_FALSE)
	{
		GLint tamMensaje = 0;
		mensajeGLSL = "";
		glGetProgramiv(identificador, GL_INFO_LOG_LENGTH, &tamMensaje);

		if (tamMensaje > 0)
		{
			GLchar* textoMensaje = new GLchar[tamMensaje];
			if (textoMensaje == nullptr);
			{
				throw std::runtime_error("error reservando memoria");
			}
			GLint numCaracteres = 0;
			glGetProgramInfoLog(identificador, tamMensaje, &numCaracteres,
				textoMensaje);
			mensajeGLSL = textoMensaje;
			std::cerr << textoMensaje;
			delete textoMensaje;
		}
		throw std::runtime_error("creaShaderProgram: error al enlazar el programa "
			+ nombreBase + ": " + mensajeGLSL);
	}
	enlazado = true;
	glDeleteShader(miVS);
	glDeleteShader(miFS);
	this->tipo = tipo;
	return identificador;
}

std::string PAGshaderProgram::getMensajeGLSL()
{
	return mensajeGLSL;
}

PAGstipoluz PAGshaderProgram::getTipoLuz()
{
	return this->tipo;
}

void PAGshaderProgram::setUniform(std::string nombre, GLint valor)
{
	auto x = glGetUniformLocation(identificador, nombre.c_str());
	if(x!=-1)
	glUniform1i(x, valor);
}

void PAGshaderProgram::setUniform(std::string nombre, GLfloat valor)
{
	auto x = glGetUniformLocation(identificador, nombre.c_str());
	if (x != -1)
	glUniform1f(x, valor);
}

void PAGshaderProgram::setUniform(std::string nombre, glm::vec3 valor)
{
	auto x = glGetUniformLocation(identificador, nombre.c_str());
	if (x != -1)
	glUniform3fv(x,1,&valor[0]);
}

void PAGshaderProgram::setUniform(std::string nombre, glm::mat4 valor)
{
	auto x = glGetUniformLocation(identificador, nombre.c_str());
	if (x != -1)
	glUniformMatrix4fv(x, 1, false, &valor[0][0]);
}

PAGshaderProgram::PAGshaderProgram()
{
}


PAGshaderProgram::~PAGshaderProgram()
{
}
