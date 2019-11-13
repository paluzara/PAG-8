#include "PAGstatus.h"



PAGstatus::PAGstatus()
{
	modomovimiento = PAGstipomovimiento::PAG_NONE;
	botonIzqPulsado = false;
}


PAGstatus::~PAGstatus()
{
}

void PAGstatus::setModoMovimiento(PAGstipomovimiento nuevo)
{
	this->modomovimiento = nuevo;
}

PAGstipomovimiento PAGstatus::getModoMovimiento()
{
	return this->modomovimiento;
}

void PAGstatus::setTeclaMantenida(int nueva)
{
	this->teclaMantenida = nueva;
}

int PAGstatus::getTeclaMantenida()
{
	return this->teclaMantenida;
}

void PAGstatus::setBotonIzqPulsado(bool nuevo)
{
	this->botonIzqPulsado = nuevo;
}

bool PAGstatus::getBotonIzqPulsado()
{
	return this->botonIzqPulsado;
}

void PAGstatus::setPosRaton(double x, double y)
{
	this->x = x;
	this->y = y;
}

void PAGstatus::getPosRaton(double & x, double & y)
{
	x = this->x;
	y = this->y;
}
