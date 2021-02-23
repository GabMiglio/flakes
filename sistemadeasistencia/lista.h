#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include string

using namespace std;

const int MAX = 100

typedef struct{
    string nombre;
    string apellido;
    string fecha;
    string estado;

}tAlumno;

typedef tAlumno tArray[MAX];

typedef struct{
    tArray elementos;
    int contador;
} tLista;

void addAlumno(tLista &lista, bool &ok);
void eliminarAlumno(tLista &lista, string nombre, string apellido);
void buscarAlumno(tLista &lista, string nombre, string apellido);
void mostrarAlumnoPorPos(tLista &lista, int pos);
void mostrarAlumnos(tLista &lista);
void totalAlumunosAusentesPresentes(tLista &lista, string fecha);


bool operator>(tAlumno opIzq, tAlumno opDer);
bool operator<(tAlumno opIzq, tAlumno opDer);

void ordenarLista(tLista &lista);

void ordenarListaDesc(tLista &lista);



#endif // LISTA_H_INCLUDED
