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

Todos los objetos tienen acceso a su propia dirección mediante un apuntador llamado this. El apuntador
this de un objeto no es parte del objeto mismo, es decir, el apuntador this no se refleja en el resultado de
una operación sizeof sobre el objeto. En vez de esto, el apuntador this pasa al objeto (lo hace el compilador)

El apuntador this se utiliza implícitamente para hacer referencia tanto a los datos miembro como a las
funciones miembro de un objeto; también puede utilizarse de manera explícita.

Toda función miembro no estática tiene acceso al apuntador this que apunta al objeto para el cual se invocó a la función miembro.

**/


