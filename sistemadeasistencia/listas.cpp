#include <iostream>
#include "../header/lista.h"

void addAlumno(tLista &lista, bool &ok)
{
    tAlumno alumno;
    ok = true;

    cout << "Ingrese el nombre del alumno: ";
    cin.ignore();
    getline(cin,alumno.nombre);
    cout << "Ingrese el apellido del alumno: ";
    getline(cin,alumno.apellido);
    cout << "Ingrese la fecha a registrar la asistencia: ";
    getline(cin,alumno.fecha);
    cout << "Ingrese el estado del alumno ";
    getline(cin,alumno.estado);
    cout << " " << endl;

    if(lista.contador == MAX)
    {
        ok = false;
    } else {
        int i = 0;
        while ((i < lista.contador) && (lista.elementos[i] < alumno))
        {
            i++;
        }
        for(int j = lista.contador; j > i; j--)
        {
            lista.elementos[j] = lista.elementos[j - 1];
        }
        lista.elementos[i] = alumno;
        lista.contador++;
    }
}

void eliminarAlumno(tLista &lista, string nombre, string apellido)
{
    int pos = 0;
    for(int i = 0; i < lista.contador; i++)
    {
        if((lista.elementos[i].nombre == nombre)&&(lista.elementos[i].apellido == apellido))
        {
            pos = i;
            for(i = pos; i < lista.contador - 1; i++)
            {
             lista.elementos[i] = lista.elementos[i+1];
            }
            lista.contador = (lista.contador - 1);
            cout << "Alumno eliminado correctamente!" << endl;
            cout << " " << endl;
        }
    }
}

void mostrarAlumnos(tLista &lista)
{
    cout << "Listado de alumnos:" << endl;
    cout << " " << endl;
    for(int i = 0; i < lista.contador; i++)
    {
        cout << "Nombre: " << lista.elementos[i].nombre << endl;
        cout << "Apellido: " << lista.elementos[i].apellido << endl;
        cout << "Fecha de la asistencia: " << lista.elementos[i].fecha << endl;
        cout << "Estado: " << lista.elementos[i].estado << endl;
        cout << " " << endl;
    }
}

void totalAlumunosAusentesPresentes(tLista &lista, string fecha)
{
    int cpresentes = 0, causentes = 0, total;
    for(int i = 0; i < lista.contador; i++)
    {
        if(lista.elementos[i].fecha == fecha)
        {
            total += i;
            if(lista.elementos[i].estado == "Presente")
            {
            cpresentes++;
            } else if (lista.elementos[i].estado == "Ausente")
                {
                causentes++;
                }
        }

    }
    cout << "Para el dia " << fecha << endl;
    cout << "Hay " << cpresentes << " alumnos presentes y " << causentes << " alumnos ausentes" << endl;
    cout << " " << endl;
}


bool operator>(tAlumno opIzq, tAlumno opDer)
{
    return(opIzq.estado > opDer.estado);
}

bool operator<(tAlumno opIzq, tAlumno opDer)
{
    return(opIzq.estado < opDer.estado);
}
