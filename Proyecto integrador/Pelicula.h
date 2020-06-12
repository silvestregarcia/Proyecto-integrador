#ifndef Pelicula_h
#define Pelicula_h
#include <iostream>
#include <string>

#include "Video.h"

using namespace std;

class Pelicula : public Video
{
private:
    string genero;

public:
    Pelicula();
    Pelicula(string id, string nombre, string duracion, string genero, double calificacion);

    void setCalificacion(double calificacion);
    string getId();
    double getCalificacion();
    void mostrar();
    friend ostream &operator<<(ostream &os, vector<Video *> videos);
};
//##### CONSTRUCTORES #####

Pelicula::Pelicula(string id, string nombre, string duracion, string genero, double calificacion) : Video(id, nombre, duracion, genero, calificacion)
{
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    this->calificacion = calificacion;
}
// ---- Set ---- //
void Pelicula::setCalificacion(double calificacion)
{
    this->calificacion = calificacion;
}
// ----- Get ----- //
string Pelicula::getId()
{
    return id;
}
double Pelicula::getCalificacion()
{
    return calificacion;
}

// -----Metodos------ //
void Pelicula::mostrar()
{
    cout << "Id: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Género: " << genero << endl;
    cout << "Duración: " << duracion << endl;
    cout << "Calificación: " << calificacion << endl;
    cout << endl;
}

// ---- Operador ---- //

#endif
