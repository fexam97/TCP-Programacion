#include <iostream>

#include "fecha.h"

using namespace std;

int main()
{

    Fecha hoy(10, 4, 2021);

    //hoy = hoy.sumarDias(30);

    //hoy.diaRel = 45;

    hoy.mostrarFecha();

    return 0;
}

/**

 Uso del apuntador this

Todos los objetos tienen acceso a su propia direcci�n mediante un apuntador llamado this. El apuntador
this de un objeto no es parte del objeto mismo, es decir, el apuntador this no se refleja en el resultado de
una operaci�n sizeof sobre el objeto. En vez de esto, el apuntador this pasa al objeto (lo hace el compilador)

El apuntador this se utiliza impl�citamente para hacer referencia tanto a los datos miembro como a las
funciones miembro de un objeto; tambi�n puede utilizarse de manera expl�cita.

Toda funci�n miembro no est�tica tiene acceso al apuntador this que apunta al objeto para el cual se invoc� a la funci�n miembro.

**/


