#include <iostream>
#include <iomanip>

#include "Fecha.h"
#include "FechaException.h"

#define ERR_INGR_FECHA 1
#define ARG_TXT_SAL 1

using namespace std;


int main()
{
	Fecha hoy;

	try
	{
	    hoy = Fecha(24, 2, 2020);
	}
	catch(FechaException& ex)
	{
        cout << "hubo un error en el ingreso de la fecha:  " << ex.getMensaje() << endl;
        return ERR_INGR_FECHA;
	}


    Fecha pepito;
   // Fecha ayer = Fecha();   esto retornaria 1/1/1601

    //int diaAyer, mesAyer, anioAyer;
    //ayer.getDMA(&diaAyer, &mesAyer, &anioAyer);
    //cout << "La fecha ayer es: " << setw(2) << fixed << diaAyer << '/' << setw(2) << fixed << mesAyer << '/' << setw(4) << fixed << anioAyer << endl;

    pepito = hoy.sumarDias(30);

    int dia, mes, anio;

    pepito.getDMA(&dia, &mes, &anio);
    pepito.esBisiesto(anio);

    cout << "Anio: " << anio << setw(2) << (Fecha::esBisiesto(anio)?" ":" No ") << "es bisiesto" << endl;

    cout << "La fecha suma es: " << setw(2) << fixed << dia << '/' << setw(2) << fixed << mes << '/' << setw(4) << fixed << anio << endl;

    hoy = Fecha::hoy();
   /* cout << hoy << endl;
      cout << hoy++ << endl;
      cout << ++hoy << endl; */



    // cout << "Mas 4 meses ==> " << hoy.sumarMeses(4) << endl;


    Fecha maniana = hoy;  // no use maniana, debi llamarlo today
    hoy.getDMA(&dia, &mes, &anio);
    cout << "hoy es: " << setw(2) << fixed << dia << '/' << setw(2) << fixed << mes << '/' << setw(4) << fixed << anio << endl;

    ++hoy;
    hoy.getDMA(&dia, &mes, &anio);
    cout << "maniana es: " << setw(2) << fixed << dia << '/' << setw(2) << fixed << mes << '/' << setw(4) << fixed << anio << endl;


    return 0;
}
