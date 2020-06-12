#ifndef Serie_h
#define Serie_h
#include <iostream>
#include <string>

#include "Video.h"

using namespace std;

class Serie
{
protected:
    string id;
    string nombre;
    string genero;
    int temporadas;

public:
    Serie();
    Serie(string id, string nombre, string genero, int temporadas);

    string getId();
    string getGenero();
    void mostrar();
};

//---Constructores--- //
Serie::Serie()
{
    id = "";
    nombre = "";
    genero = "";
    temporadas = 0;
}
Serie::Serie(string id, string nombre, string genero, int temporadas)
{
    this->id = id;
    this->nombre = nombre;
    this->genero = genero;
    this->temporadas = temporadas;
}

// ---- Get ---- //
string Serie::getId()
{
    return id;
}
string Serie::getGenero()
{
    return genero;
}
// ---- Mostrar ---- //
void Serie::mostrar()
{
    cout << "Id Serie: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Género: " << genero << endl;
    cout << "Temporadas: " << temporadas << endl;
}
#endif
