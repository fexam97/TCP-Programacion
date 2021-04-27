#include "fecha.h"

using namespace std;

/*
Fecha::Fecha()
{
    this->diaRel = 1;
}
*/

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

/*
Fecha Fecha::sumarDias(int dias) const
{
    return Fecha();
}
*/

void Fecha::mostrarFecha()
{
    cout << "la fecha es : " << _dia << '/' << _mes << '/' << _anio << endl;
}

