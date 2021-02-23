#include <fstream>
#include "../header/archivo.h"


void cargarArchivo(tLista &lista)
{
    ifstream cArchivo;
    cArchivo.open("Asistencia_Alumnos.txt", ios::in);
    if(cArchivo.is_open())
    {
        while (!cArchivo.eof())
        {
            cArchivo >> lista.elementos[lista.contador].nombre;
            cArchivo.get( );
            cArchivo >> lista.elementos[lista.contador].apellido;
            cArchivo.get( );
            cArchivo >> lista.elementos[lista.contador].fecha;
            cArchivo.get( );
            cArchivo >> lista.elementos[lista.contador].estado;
            cArchivo.get( );

            if((!lista.elementos[lista.contador].nombre.empty())&&(!lista.elementos[lista.contador].apellido.empty())&&(!lista.elementos[lista.contador].fecha.empty())&&(!lista.elementos[lista.contador].estado.empty()))
            {
                lista.contador++;
            }
        }
    }
    cArchivo.close();
}

void guardarArchivo(tLista &lista)
{
    ofstream gArchivo;
    gArchivo.open("Asistencia_Alumnos.txt", ios::out);
    if(gArchivo.is_open())
    {
        for(int i = 0; i < lista.contador; i++)
        {
             gArchivo << lista.elementos[i].nombre<< " " << lista.elementos[i].apellido << " " <<lista.elementos[i].fecha << " " << lista.elementos[i].estado << endl;
        }
    }
    gArchivo.close();
}
