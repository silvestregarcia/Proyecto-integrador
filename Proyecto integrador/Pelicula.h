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

    double getCalificacion();
    void mostrar();
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

// ----- Get ----- //
double Pelicula::getCalificacion()
{
    return calificacion;
}

// -----Metodos------ //
void Pelicula::mostrar()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Género: " << genero << endl;
    cout << "Duración: " << duracion << endl;
    cout << "Calificación: " << calificacion << endl;
    cout << endl;
}
#endif
