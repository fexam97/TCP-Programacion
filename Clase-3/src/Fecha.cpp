#include "Fecha.h"
#include "FechaException.h"


#define ANIO_BASE 1601

const int Fecha::acumuladoMesesNoBisiesto[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
const int Fecha::acumuladoMesesBisiesto[] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};


Fecha::Fecha()
{
	this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{
     if(!esFechaValida(dia, mes, anio))
		throw FechaException("La fecha es invalida"); /// throw: lanzo una excepcion (un error) para que aquel que haya invocado a este constructor
                                                      /// reciba esa excepcion ( se crea un objeto de tipo fechaException )
	int cantAnios = anio - ANIO_BASE;
	int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
	this->diaRel = diasAniosCompl + diaDelAnio(dia, mes, anio);
}


Fecha Fecha::sumarDias(int dias) const
{


	Fecha fSuma(*this);
	fSuma.diaRel += dias;
	return fSuma;
}


void Fecha::getDMA(int* d, int* m, int* a) const
{
	int cantAniosComplCalc = this->diaRel / 365;
	unsigned long diasAniosComplCalc = cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;

	while(diasAniosComplCalc >= this->diaRel)
	{
		cantAniosComplCalc--;
		diasAniosComplCalc = cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;
	}

	int anio = ANIO_BASE + cantAniosComplCalc;

	*a = anio;

	int diaDelAnio = this->diaRel - diasAniosComplCalc;

	diaDelAnioADiaMes(diaDelAnio, anio, d, m);
}

Fecha Fecha::operator +(int dias) const
{
    return sumarDias(dias);
}

Fecha& Fecha::operator +=(int dias)
{
    this->diaRel += dias;

    return *this; // este era el ampersand Fecha&
}

Fecha& Fecha::operator ++() // pre
{
    ++this->diaRel;
    return *this;
}

Fecha& Fecha::operator ++(int) // pos
{
    Fecha temp(*this);
    this->diaRel++;
    return temp;
}

Fecha Fecha::hoy()
{
    time_t segs = time(NULL);

    struct tm* timeMachine = localtime(&segs);

    int dia = timeMachine->tm_mday;
    int mes = timeMachine->tm_mon + 1;
    int anio = timeMachine->tm_year + 1900;

    return Fecha(dia, mes, anio);
}

/********** Funciones miembro (m?todos) privadas **********/

int Fecha::diaDelAnio(int dia, int mes, int anio)
{
	return (esBisiesto(anio)? acumuladoMesesBisiesto[mes] : acumuladoMesesNoBisiesto[mes]) + dia;
}


bool Fecha::esBisiesto(int anio)
{
	return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}


void Fecha::diaDelAnioADiaMes(int diaDelAnio, int anio, int* d, int* m)
{
	const int* acumuladoMeses = esBisiesto(anio)? acumuladoMesesBisiesto : acumuladoMesesNoBisiesto;

	int mes = 2;

	while(mes <= 12 && diaDelAnio > acumuladoMeses[mes])
		mes++;

	mes--;
	*m = mes;

	*d = diaDelAnio - acumuladoMeses[mes];
}

bool Fecha::esFechaValida(int dia, int mes, int anio)
{
	return (anio >= ANIO_BASE) &&
            (mes >= 1 && mes <= 12) &&
             (dia >= 1 && dia <= cantDiasMes(mes, anio));

    // como es booleano retorna falso o verdadero
}

int Fecha::cantDiasMes(int mes, int anio)
{
	static const int vCantDias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(mes == 2 && esBisiesto(anio))
		return 29;

	return vCantDias[mes];
}
/*
ostream& operator <<(ostream& sal, const Fecha& f)
{
	int dia, mes, anio;
	f.getDMA(&dia, &mes, &anio);

	return sal << setw(2) << fixed << dia << '/' << setw(2) << fixed << mes << '/' << setw(4) << fixed << anio;
//	return sal << d << '/' << m << '/' << a;
}
*/
Fecha Fecha::sumarMeses(int cantmeses)const
{
    Fecha fsuma(*this);
    int dia,mes,anio;
    getDMA(&dia,&mes,&anio);



    if(esBisiesto(anio))
    {
        fsuma.diaRel-=acumuladoMesesBisiesto[mes+1];
        fsuma.diaRel+=acumuladoMesesBisiesto[mes+1+cantmeses];
    }
    else
    {
        fsuma.diaRel-=acumuladoMesesNoBisiesto[mes+1];
        fsuma.diaRel+=acumuladoMesesNoBisiesto[mes+1+cantmeses];
    }
    return(fsuma);
}
