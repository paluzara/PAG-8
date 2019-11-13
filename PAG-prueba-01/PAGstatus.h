#include "PAGvalues.h"
class PAGstatus
{

	PAGstipomovimiento modomovimiento;
	int teclaMantenida;
	bool botonIzqPulsado;
	
	double x;
	double y;

public:
	PAGstatus();
	~PAGstatus();


	void setModoMovimiento(PAGstipomovimiento nuevo);
	PAGstipomovimiento getModoMovimiento();
	void setTeclaMantenida(int nueva);
	int getTeclaMantenida();
	void setBotonIzqPulsado(bool nuevo);
	bool getBotonIzqPulsado();
	void setPosRaton(double x, double y);
	void getPosRaton(double &x, double&y);


};

