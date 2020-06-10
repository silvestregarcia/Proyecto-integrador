#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>

#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"

using namespace std;

// -------- FUNCIONES -------- //

//--- Cargar archivos de datos --- //
string leerDatos(vector<Video *> videos, vector<Serie *> series)
{
    string validacion = "";

    ifstream peliculasArchivo("Peliculas-1.csv");
    ifstream seriesArchivo("Series-1.csv");
    ifstream episodiosArchivo("Episodios-1.csv");

    string line;
    string valor;
    char delim = ',';

    double calificacion;
    int col, serie, temporadas, temporada;
    string id, idEp, nombre, genero, duracion, idA;

    //-- Leemos el archivo de peliculas -- //
    if (peliculasArchivo.is_open())
    {
        getline(peliculasArchivo, line);
        while (getline(peliculasArchivo, line))
        {
            stringstream ss(line);
            col = 0;
            while (getline(ss, valor, delim))
            {
                switch (col)
                {
                case 0:
                    id = valor;
                    break;
                case 1:
                    nombre = valor;
                    break;
                case 2:
                    duracion = valor;
                    break;
                case 3:
                    genero = valor;
                    break;
                case 4:
                    calificacion = stod(valor);
                    break;
                }
                col++;
            }
            videos.push_back(new Pelicula(id, nombre, duracion, genero, calificacion));
        }
        peliculasArchivo.close();
    }
    else
    {
        validacion = validacion + "Error al leer el archivo.\n";
    }

    // -- Leemos el archivo de Series -- //
    if (seriesArchivo.is_open())
    {
        getline(seriesArchivo, line);
        while (getline(seriesArchivo, line))
        {
            stringstream ss(line);
            col = 0;
            while (getline(ss, valor, delim))
            {
                switch (col)
                {
                case 0:
                    id = valor;
                    break;
                case 1:
                    nombre = valor;
                    break;
                case 2:
                    genero = valor;
                    break;
                case 3:
                    temporadas = stoi(valor);
                    break;
                }
                col++;
            }
            series.push_back(new Serie(id, nombre, genero, temporadas));
        }
        seriesArchivo.close();
    }
    else
    {
        validacion = validacion + "Error al leer el archivo.\n";
    }

    // -- Leemos archivo de episodios -- //
    string valor2;
    if (episodiosArchivo.is_open())
    {
        getline(episodiosArchivo, line);
        while (getline(episodiosArchivo, line))
        {
            stringstream ss(line);
            col = 0;
            while (getline(ss, valor2, delim))
            {
                switch (col)
                {
                case 0:
                    idA = valor2;
                    break;
                case 1:
                    idEp = valor2;
                    break;
                case 2:
                    nombre = valor2;
                    break;
                case 3:
                    duracion = valor2;
                    break;
                case 4:
                    calificacion = stod(valor2);
                    break;
                case 5:
                    temporada = stoi(valor2);
                    break;
                }
                col++;
            }
            videos.push_back(new Episodio(idA, idEp, nombre, duracion, calificacion, temporada));
        }
        episodiosArchivo.close();
    }
    else
    {
        validacion = validacion + "Error al leer el archivo.\n";
    }

    return validacion;
}

// --- Mostrar peliculas con cierto rango de calificacion --- //

string califPeliculas(vector<Video *> videos, double rangInf, double rangSup)
{
    for (int i = 0; i < videos.size(); i++)
    {
        if (videos[i]->getCalificacion() >= rangInf && videos[i]->getCalificacion() <= rangSup)
        {
            videos[i]->mostrar();
        }
    }
}

int main()
{
    vector<Video *> videos;
    vector<Serie *> series;

    bool opcion = true;

    while (opcion == true)
    {
        cout << "------ MENU ------" << endl;
        cout << endl;
        cout << "1.- Cargar archivos de datos" << endl;
        cout << "2.- Mostrar los videos en general con un cierto rango de calificación de un cierto género" << endl;
        cout << "3.- Mostrar los videos en general de un cierto género" << endl;
        cout << "4.- Mostrar los episodios de una determinada serie con un rango de calificación determinada" << endl;
        cout << "5.- Mostrar las películas con cierto rango de calificación" << endl;
        cout << "6.- Calificar un video" << endl;
        cout << "0.- Salir" << endl;
        int op;
        cin >> op;

        double rangInf, rangSup;
        switch (op)
        {
        case 1:
            leerDatos(videos, series);
            break;
        case 2:

            cout << "Introduzca el rango inferior de la calificación: ";
            cin >> rangInf;
            cout << "Introduzca el rango superior de la calificación: ";
            cin >> rangSup;
            for (int i = 0; i < videos.size(); i++)
            {
                cout << "Genero: " << endl;
                videos[i]->getGenero();
            }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            cout << "Introduzca el rango inferior de la calificación: ";
            cin >> rangInf;
            cout << "Introduzca el rango superior de la calificación: ";
            cin >> rangSup;
            califPeliculas(videos, rangInf, rangSup);
            break;
        case 6:
            break;
        case 0:
            opcion = false;
            break;
        }
    }

    return 0;
}