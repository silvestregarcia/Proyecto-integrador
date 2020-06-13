#ifndef Serie_h
#define Serie_h
#include <iostream>
#include <istream>
#include <ostream>
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

    void setNombre(string nombre);
    string getId();
    string getGenero();
    void mostrar();
    friend ostream &operator<<(ostream &os, Serie *serie);
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
void Serie::setNombre(string nombre)
{
    this->nombre = nombre;
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
// --- operador --- //
ostream &operator<<(ostream &os, Serie *serie)
{
    char c[256];
    int n;
    os << "Id Serie: " << serie->id << endl;
    os << "Nombre: " << serie->nombre << endl;
    os << "Género: " << serie->genero << endl;
    os << "Temporadas " << serie->temporadas << endl;

    return os;
}
#endif
