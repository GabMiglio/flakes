#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX = 100;
typedef struct {

   string nombre;
   string apellido;
   string carrera;
   string anio;

} tAlumno;

typedef tAlumno tArray[MAX];

typedef struct {

    tArray elementos;
    int contador;

} tLista;

int i;

void cargarArchivo(tLista &lista);
void guardarArchivo (tLista &lista);


void addAlumno (tLista &lista, bool &ok);
void eliminarAlumno (tLista &lista, string nombre, string apellido);
void buscarAlumno (tLista &lista, string nombre, string apellido);
void mostrarAlumnoPorPos (tLista &lista, int pos);
void mostrarAlumnos (tLista &lista);
void ordenarLista (tLista &lista);
void ordenarListaDesc (tLista &lista);
bool operator > (tAlumno opIzq, tAlumno opDer);
bool operator < (tAlumno opIzq, tAlumno opDer);

int main(){

    tLista lista;
    string tempText,tempText1;
    int op, pos;
    bool ok;
    lista.contador = 0;
    cargarArchivo(lista);
    do {
            cout << "1 - Añadir un nuevo alumno" << endl;
            cout << "2 - Eliminar un alumno" << endl;
            cout << "3 - Buscar alumnos" << endl;
            cout << "4 - Listado de alumnos" << endl;
            cout << "5 - Mostrar alumno por posicion" << endl;
            cout << "6 - Ordenar lista por nombre de manera ascendiente" << endl;
            cout << "7 - Ordenar lista por nombre de manera descendiente" << endl;
            cout << "0 - Salir" << endl;
            cin >> op;

            switch (op)
            {

            case 1:
            addAlumno(lista,ok);
            break;

            case 2:
            cout << "Ingrese el nombre del alumno que desee eliminar: ";
            cin >> tempText;
            cout << "Ingrese el apellido del alumno que desee eliminar: ";
            cin >> tempText1;
            eliminarAlumno (lista,tempText,tempText1);
            break;

            case 3:
            cout << "Ingrese el nombre del alumno que desea buscar: ";
            cin >> tempText;
            cout << "Ingrese el apellido del alumno que desea buscar: ";
            cin >> tempText1;
            buscarAlumno(lista,tempText,tempText1);
            break;

            case 4:
            mostrarAlumnos(lista);
            break;

            case 5:
            cout << "Ingrese la posicion que corresponde al alumno: ";
            cin >> pos;
            mostrarAlumnoPorPos(lista, pos);
            break;

            case 6:
            ordenarLista(lista);
            break;

            case 7:
            ordenarListaDesc(lista);
            break;

            case 0:
            guardarArchivo(lista);
            break;
            }

    } while (op != 0)
  return 0;
 }

 void cargarArchivo (tLista &lista)

 {
     ifstream cArchivo;
     cArchivo.open("alumnos.txt", ios::in);
     if (cArchivo.is_open())
     {
         while (!cArchivo.eof())
            {
                cArchivo >> lista.elementos[lista.contador].nombre;
                cArchivo.get( );
                cArchivo >> lista.elementos[lista.contador].apellido;
                cArchivo.get( );
                cArchivo >> lista.elementos[lista.contador].carrera;
                cArchivo >> lista.elementos[lista.contador].anio;

                if ((!lista.elementos[lista.contador].nombre.empty())&&(!lista.elementos[lista.contador].apellido.empty())&&(!lista.elementos[lista.contador].carrera.empty())&&(!lista.elementos[lista.contador].anio.empty()))
                {
                    lista.contador++;
                }
            }
     }

     cArchivo.close();
 }

 void guardarArchivo (tLista &lista)

 {
     ofstream gArchivo;
     gArchivo.open("alumnos.txt", ios::out);
     if (gArchivo.is_open())
     {
         for(i=0; i < lista.contador; i++)
         {
             gArchivo << lista.elementos[i].nombre << " " << lista.elementos[i].apellido << " " << lista.elementos[i]carrera << " " << lista.elementos[i]anio << endl;
         }
     }
     gArchivo.close();
 }

 bool operator>(tAlumno opIzq, tAlumno opDer)
{
    return(opIzq.nombre > opDer.nombre);
}

bool operator<(tAlumno opIzq, tAlumno opDer)
{
    return(opIzq.nombre < opDer.nombre);
}


void addAlumno(tLista &lista, bool &ok)
{
    tAlumno alumno;
    ok = true;

    cout << "Ingrese el nombre del alumno: ";
    cin.ignore();
    getline(cin,alumno.nombre);
    cout << "Ingrese el apellido del alumno: ";
    getline(cin,alumno.apellido);
    cout << "Ingrese la carrera del alumno: ";
    getline(cin,alumno.carrera);
    cout << "Ingrese el año en que se encuentra el alumno: ";
    cin >> alumno.anio;

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
    for(i = 0; i < lista.contador; i++)
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

void buscarAlumno(tLista &lista, string nombre, string apellido)
{
    int pos = 0;
    bool encontrado = false;
    for(i = 0; i < lista.contador; i++)
    {
        if((lista.elementos[i].nombre == nombre)&&(lista.elementos[i].apellido == apellido))
        {
            cout << "El alumno se encuentra en la posicion: " << i << endl;
            cout << " " << endl;
            encontrado = true;
        }
    }
    if(!encontrado)
    {
        cout << "El alumno no se encuentra en la lista." << endl;
        cout << " " << endl;
    }

}

void mostrarAlumnos(tLista &lista)
{
    cout << "Listado de alumnos:" << endl;
    cout << " " << endl;
    for(i = 0; i < lista.contador; i++)
    {
        cout << "Nombre: " << lista.elementos[i].nombre << endl;
        cout << "Apellido: " << lista.elementos[i].apellido << endl;
        cout << "Carrera: " << lista.elementos[i].carrera << endl;
        cout << "Año: " << lista.elementos[i].anio << endl;
        cout << " " << endl;
    }
}

void mostrarAlumnoPorPos(tLista &lista, int pos)
{
    if(!lista.elementos[pos].nombre.empty())
    {
        cout << "Alumno en posicion: " << pos << endl;
        cout << "Nombre: " << lista.elementos[pos].nombre << endl;
        cout << "Apellido: " << lista.elementos[pos].apellido << endl;
        cout << "Carrera: " << lista.elementos[pos].carrera << endl;
        cout << "Anio: " << lista.elementos[pos].anio << endl;
        cout << " " << endl;
    }
}

void ordenarLista(tLista &lista)
{
    tAlumno temp;
    for(int i = 0; i < lista.contador; i++)
    {
       for(int j = 0; j < lista.contador - 1; j++)
        if(lista.elementos[j] > lista.elementos[j+1])
       {
           temp = lista.elementos[j];
           lista.elementos[j] = lista.elementos[j+1];
           lista.elementos[j+1] = temp;
       }
    }
    mostrarAlumnos(lista);
}

void ordenarListaDesc(tLista &lista)
{
    tAlumno temp;
    for(int i = 0; i < lista.contador; i++)
    {
       for(int j = 0; j < lista.contador - 1; j++)
        if(lista.elementos[j] < lista.elementos[j+1])
       {
           temp = lista.elementos[j];
           lista.elementos[j] = lista.elementos[j+1];
           lista.elementos[j+1] = temp;
       }
    }
    mostrarAlumnos(lista);
}
