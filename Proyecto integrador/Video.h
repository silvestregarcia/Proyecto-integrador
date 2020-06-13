#ifndef Video_h
#define Video_h
#include <iostream>
#include <string>

using namespace std;

class Video
{
protected:
    string id;
    string nombre;
    string duracion;
    string genero;
    double calificacion;

public:
    Video();
    Video(string id, string nombre, string duracion, string genero, double calificacion);

    void setCalificacion(double calificacion);
    void setGenero(string genero);
    virtual string getId();
    virtual string getNombre();
    virtual string getDuracion();
    virtual string getGenero();
    virtual double getCalificacion();

    bool operator>=(double rangInf);
    bool operator<=(double rangSup);

    virtual void mostrar();
};
//----Constructor----//
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
// ---- Set ---- //
void Video::setCalificacion(double calificacion)
{
    this->calificacion = calificacion;
}
void Video::setGenero(string genero)
{
    this->genero = genero;
}
//----Get----//
string Video::getId()
{
    return id;
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
// ---- Operadores ---- //
bool Video::operator>=(double rangInf)
{
    if (this->calificacion >= rangInf)
    {
        return true;
    }
    return false;
}
#endif
