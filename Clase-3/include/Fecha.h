#ifndef FECHA_H
#define FECHA_H

#include <time.h>

class Fecha
{
private:
	unsigned long diaRel;

	static const int acumuladoMesesNoBisiesto[13];
	static const int acumuladoMesesBisiesto[13];

	static int diaDelAnio(int dia, int mes, int anio);
	static void diaDelAnioADiaMes(int diaDelAnio, int anio, int* d, int* m);
	static bool esFechaValida(int dia, int mes, int anio);
	static int cantDiasMes(int mes, int anio);

	//ostream& operator <<(ostream& sal, const Fecha& f);
	Fecha sumarMeses(int cantmeses)const;

public:
	Fecha();
	Fecha(int dia, int mes, int anio);

	Fecha sumarDias(int dias) const; // no va a modificar un atributo de la clase

	void getDMA(int* d, int* m, int* a) const;

	static bool esBisiesto(int anio);
	static Fecha hoy();

	Fecha operator +(int dias) const;
	Fecha& operator +=(int dias); // devuelve una direccion de memoria porque trabaja sobre el objeto this (dato curioso: no es const)

	Fecha& operator ++();
	Fecha& operator ++(int);


};


#endif // FECHA_H
