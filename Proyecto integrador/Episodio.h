#ifndef Episodio_h
#define Episodio_h
#include <iostream>
#include <string>

#include "Video.h"

using namespace std;

class Episodio : public Video
{
private:
    string idEp;
    int temporada;

public:
    Episodio();
    Episodio(string id, string idEp, string nombre, string duracion, double calificacion, int temporada);

    void setGenero(string genero);
    void setCalificacion(double calificacion);
    string getIdSerie();
    double getCalificacion();
    void mostrar();
};
Episodio::Episodio()
{
    id = "";
    nombre = "";
    duracion = "";
    temporada = 0;
    calificacion = 0;
}
//----Constructor---- //
Episodio::Episodio(string id, string idEp, string nombre, string duracion, double calificacion, int temporada) : Video(id, nombre, duracion, genero, calificacion)
{
    this->id = id;
    this->idEp = idEp;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    this->calificacion = calificacion;
    this->temporada = temporada;
}
// ----- Metodos ----- //
// ---- Set ---- //
void Episodio::setCalificacion(double calificacion)
{
    this->calificacion = calificacion;
}
void Episodio::setGenero(string genero)
{
    this->genero = genero;
}
// ---- Get ---- //
string Episodio::getIdSerie()
{
    return id;
}

double Episodio::getCalificacion()
{
    return calificacion;
}
// ---- Mostrar ----- //
void Episodio::mostrar()
{
    cout << "Id episodio: " << idEp << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Duración: " << duracion << endl;
    cout << "Calificación: " << calificacion << endl;
    cout << "Genero de la serie: " << genero << endl;
    cout << "Temporada: " << temporada << endl;
    cout << endl;
}
#endif