#ifndef Video_h
#define Video_h
#include <iostream>
#include <string>

using namespace std;

class Video
{
protected:
    string tipo;
    string id;
    string nombre;
    string duracion;
    string genero;
    double calificacion;

public:
    Video();
    Video(string id, string nombre, string duracion, string genero, double calificacion);

    virtual string getTipo();
    virtual string getId();
    virtual string getNombre();
    virtual string getDuracion();
    virtual string getGenero();
    virtual double getCalificacion();

    virtual void mostrar();
};
//----Constructor----
Video::Video()
{
    id = "";
    nombre = "";
    duracion = "";
    genero = "";
    calificacion = 0;
}
Video::Video(string id, string nombre, string duracion, string genero, double calificacion)
{
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    this->calificacion = calificacion;
}
//----Get----
string Video::getId()
{
    return id;
}
string Video::getTipo()
{
    return tipo;
}
string Video::getNombre()
{
    return nombre;
}
string Video::getDuracion()
{
    return duracion;
}
string Video::getGenero()
{
    return genero;
}
double Video::getCalificacion()
{
    return calificacion;
}
//----Mostrar----
void Video::mostrar()
{
}
#endif