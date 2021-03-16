#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct FileData
{
    string name;// Nombre del archivo
    long size;// El tamaño en bytes
};

int numberOfFiles;
int i;
int option;

string tempText;
int tempNumber;
int main()

{
    FileData files[1000];
    cout << "Si es la primera vez corriendo el codigo y no existe el archivo, ingrese 0" << endl;
    cout << "Cuantos registros ingresó la ultima vez" << endl;
     cin >> numberOfFiles;
    if(numberOfFiles > 0)
    {
        ifstream entrada("archivo.dat",ios::in| ios::binary);
        if(!entrada)
            {
            cout << "Error al abrir el archivo" << endl;
            return 1;
            }
            for(i=0;i < numberOfFiles;i++ )
            {
            entrada.read((char*) &files[i], sizeof(FileData));
            }
            entrada.close();
            if(!entrada.good())
            {
            cout << "Ocurrio un error al leer el archivo" << endl;
            return 1;
            }
    }

    do

    {
        cout << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Añadir datos de un nuevo archivo" << endl;
        cout << "2.- Mostrar los nombres de todos los archivos" << endl;
        cout << "3.- Mostrar archivos que sean de mas de un cierto tamaño" << endl;
        cout << "4.- Ver datos de un archivo" << endl;
        cout << "5.- Salir" << endl;
        cin >> option;

        switch(option)
        {
            case 1:
            if (numberOfFiles < 1000)
                {
                    cout << "Introduce el nombre del archivo: ";
                    cin.ignore(); //
                    getline(cin,files[numberOfFiles].name);
                    cout << "Introduce el tamaño en KB: ";
                    cin >> files[numberOfFiles].size;
                    numberOfFiles++;
                }
                else
                  cout << "¡Máximo de archivos alcanzado (1000)!" << endl;
                break;

            case 2:
            for (i=0; i<numberOfFiles; i++)
                    cout << "Nombre: " << files[i].name
                        << "; Tamaño: " << files[i].size
                        << "Kb" << endl;
                break;

            case 3:
             cout << "¿A partir de que tamaño quieres que te muestre? ";
             cin >> tempNumber;
                for (i=0; i<numberOfFiles; i++)
                    if (files[i].size >= tempNumber)
                        cout << "Nombre: " << files[i].name
                            << "; Tamaño: " << files[i].size
                            << " Kb" << endl;
                break;

            case 4:
             cout << "¿De qué archivo quieres ver todos los datos?";
             cin.ignore();
                getline(cin,tempText);
                for (i=0; i<numberOfFiles; i++)
                    if (files[i].name == tempText)
                        cout << "Nombre: " << files[i].name
                            << "; Tamaño: " << files[i].size
                            << " Kb" << endl;
                break;


            case 5:
               {
                ofstream salida ("archivo.dat", ios::out | ios::binary);
                if(!salida) {
                        cout << "No se pudo abrir el archivo";
                        return 1;
                    }
                 for (i=0; i<numberOfFiles; i++)
                    {
                        salida.write((char*)&files[i],sizeof(FileData));
                    }
                    salida.close();
                    if(!salida.good())
                    {
                        cout<<"Hubo un problema en la escritura" << endl;
                        return 1;
                    }
                cout << "Fin del programa" << endl;
                break;
                }

                default:
                  cout << "¡Opción desconocida!" << endl;
                break;
        }
    } while (option != 5);

    return 0;
}
