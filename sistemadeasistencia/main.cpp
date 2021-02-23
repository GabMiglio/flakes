#include <iostream>
#include "lista.h"
#include "asistencia.h"

using namespace std;

int main()
{
    tLista lista;
    string tempText,tempText1,tempText2;
    int op,pos;
    bool ok;
    lista.contador = 0;
    cargarArchivo(lista);
   do {
        cout << "1 - Añadir un nuevo alumno" << endl;
        cout << "2 - Eliminar un alumno" << endl;
        cout << "3 - Listado de alumnos" << endl;
        cout << "4 - Alumnos Presentes y Ausentes a Determinada Fecha" << endl;
        cout << "0 - Salir" << endl;
        cin >> op;

        switch(op)
        {
        case 1:
            //Añadir alumnos
            addAlumno(lista,ok);
            break;
        case 2:
            //Eliminar alumno
            cout << "Ingrese el nombre del alumno que desee eliminar: ";
            cin >> tempText;
            cout << "Ingrese el apellido del alumno que desee eliminar: ";
            cin >> tempText1;
            eliminarAlumno(lista,tempText, tempText1);
            break;
        case 3:
            //Listado de alumnos
            mostrarAlumnos(lista);
            break;
        case 4:
            cout << "Ingrese la fecha a sacar registro de los alumnos (dd/mm/aaaa):" << endl;
            cin >> tempText2;
            totalAlumunosAusentesPresentes(lista,tempText2);
        case 0:
            //Guardamos y salimos
            guardarArchivo(lista);
            break;
        default:
            cout << "Opcion desconocida!" << endl;
            break;
        }
    } while (op != 0);
return 0;
}
