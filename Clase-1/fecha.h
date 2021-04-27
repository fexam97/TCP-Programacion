#ifndef FECHA_H
#define FECHA_H

#include <iostream>

class Fecha
{

private:
    //unsigned long diaRel; // supongo que se guardaria un numero asi 1442021
    int _dia, _mes, _anio;

public:
   // Fecha();
    Fecha(int dia, int mes, int anio);

    Fecha sumarDias(int dias) const;

    void mostrarFecha();

};

#endif // FECHA_H
