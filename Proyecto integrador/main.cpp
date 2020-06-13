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

//--- 1) Cargar archivos de datos --- //
string leerDatos(vector<Video *> &videos, vector<Serie *> &series)
{
    string validacion = "";

    ifstream peliculasArchivo("Peliculas-1.csv");
    ifstream seriesArchivo("Series-1.csv");
    ifstream episodiosArchivo("Episodios-1.csv");

    string line;
    string valor;
    char delim = ',';

    double calificacion;
    int col, temporadas, temporada;
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
                    if (valor2 == "20110125")
                    {
                        genero = "Drama";
                    }
                    else if (valor2 == "20170120")
                    {
                        genero = "Misterio";
                    }
                    else if (valor2 == "20160150")
                    {
                        genero = "Accion";
                    }
                    else
                    {
                        genero = "Drama";
                    }
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
            videos.push_back(new Episodio(idA, idEp, nombre, duracion, genero, calificacion, temporada));
        }
        episodiosArchivo.close();
    }
    else
    {
        validacion = validacion + "Error al leer el archivo.\n";
    }
    return validacion;
}

// --- 2) Mostrar los videos en general con un cierto rango de calificación de un cierto género --- //
string videosCalif(vector<Video *> videos, vector<Serie *> series, string genero)
{
    // - Le asignamos la id de las series del genero que se pidió a sus episodios - //
    string idSerie;
    for (int i = 0; i < series.size(); i++)
    {
        if (series[i]->getGenero() == genero)
        {
            idSerie = series[i]->getId();
            for (int j = 0; j < videos.size(); j++)
            {
                if (videos[j]->getId() == idSerie)
                {
                    videos[j]->setGenero(genero);
                }
            }
        }
    }
    // - Rango inferiores y superiores - //
    string rangI, rangS;
    double rangInf, rangSup;
    bool a = true;

    while (a)
    {
        int cont = 1;

        cout << "Ingrese el rango inferior: ";
        cin >> rangI;
        cout << "Ingrese el rango superior: ";
        cin >> rangS;

        try
        {
            rangInf = stod(rangI);
            rangSup = stod(rangS);
            a = false;
        }
        catch (invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    cout << endl;
    int cont = 1;

    for (int i = 0; i < videos.size(); i++)
    {
        if (videos[i]->getCalificacion() >= rangInf && videos[i]->getCalificacion() <= rangSup && videos[i]->getGenero() == genero)
        {
            cout << cont << ")" << endl;
            videos[i]->mostrar();
            cont++;
        }
    }
    return "";
}

// --- 3) Mostrar los videos en general de un cierto género --- //
string videosGenero(vector<Video *> videos, vector<Serie *> series, string genero)
{
    // - Le asignamos la id de las series del genero que se pidió a sus episodios - //
    string idSerie;
    for (int i = 0; i < series.size(); i++)
    {
        if (series[i]->getGenero() == genero)
        {
            idSerie = series[i]->getId();
            for (int j = 0; j < videos.size(); j++)
            {
                if (videos[j]->getId() == idSerie)
                {
                    videos[j]->setGenero(genero);
                }
            }
        }
    }
    int cont = 1;
    for (int i = 0; i < videos.size(); i++)
    {
        if (videos[i]->getGenero() == genero)
        {
            cout << cont << ")" << endl;
            videos[i]->mostrar();
            cont++;
        }
    }
    return "";
}

// --- 4) Mostrar los episodios de una determinada serie con un rango de calificación determinada --- //
string mostrarEpisodios(vector<Video *> videos, string idSerie, vector<Serie *> series, string genero)
{
    for (int i = 0; i < videos.size(); i++)
    {
        if (videos[i]->getId() == idSerie)
        {
            videos[i]->setGenero(genero);
        }
    }

    double rangInf, rangSup;
    string rangI, rangS;
    bool a = true;
    while (a)
    {
        cout << "Ingrese el rango inferior de la calificación: ";
        cin >> rangI;
        cout << "Ingrese el rango superior de la calificación: ";
        cin >> rangS;
        try
        {
            rangInf = stod(rangI);
            rangSup = stod(rangS);
            a = false;
        }
        catch (invalid_argument &e)
        {
            cout << "Error. " << e.what() << endl;
        }
        int cont = 1;
        for (int i = 0; i < videos.size(); i++)
        {
            if (videos[i]->getCalificacion() >= rangInf && videos[i]->getCalificacion() <= rangSup && videos[i]->getId() == idSerie)
            {
                cout << cont << ")" << endl;
                videos[i]->mostrar();
                cont++;
            }
        }
    }

    return idSerie;
}

// --- 5) Mostrar peliculas con cierto rango de calificacion --- //
string califPeliculas(vector<Video *> videos, double rangInf, double rangSup)
{
    int cont = 1;
    for (int i = 0; i < 7; i++)
    {
        if (videos[i]->getCalificacion() >= rangInf && videos[i]->getCalificacion() <= rangSup)
        {
            cout << cont << ")" << endl;
            cout << videos[i];
            cont++;
        }
    }
    return "";
}

// -- 6) Calificar un video --- //
string calificarVideo(vector<Video *> videos)
{
    int num;
    double nuevaCalificacion;
    for (int i = 0; i < videos.size(); i++)
    {
        cout << i + 1 << ")" << endl;
        videos[i]->mostrar();
    }

    string numero;
    bool a = true;
    while (a)
    {
        cout << "Ingrese el número del video que desea calificar: ";
        cin >> numero;
        try
        {
            num = stoi(numero);
            a = false;
        }
        catch (invalid_argument &e)
        {
            cout << "Error. " << e.what() << endl;
        }
    }
    cout << "Seleccionó el video: " << videos[num - 1]->getNombre() << ". Con calificación de: " << videos[num - 1]->getCalificacion() << endl;
    cout << "Ingrese la califcación nueva: ";
    cin >> nuevaCalificacion;
    videos[num - 1]->setCalificacion(nuevaCalificacion);

    return "";
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

        bool a = true;
        string op;
        string rangI, rangS;
        int opF;

        while (a)
        {
            cout << "Ingresa el número de la opción: ";
            cin >> op;
            try
            {
                opF = stoi(op);
                if (opF < 0 || opF > 6)
                {
                    throw invalid_argument(" No elegiste una opción del menú. ");
                }
                a = false;
                // - Variables - //
                int num;
                string numP;
                double rangInf, rangSup;
                string idSerie, genero;

                switch (opF)
                {
                case 1:
                    leerDatos(videos, series);
                    break;
                case 2:
                    cout << "Drama." << endl;
                    cout << "Misterio." << endl;
                    cout << "Accion." << endl;
                    cout << "Ingrese el genero de los videos que desea ver: ";
                    cin >> genero;
                    videosCalif(videos, series, genero);
                    break;
                case 3:
                    cout << "Drama." << endl;
                    cout << "Misterio." << endl;
                    cout << "Accion." << endl;
                    cout << "Ingrese el genero de los videos que desea ver: ";
                    cin >> genero;

                    videosGenero(videos, series, genero);
                    break;
                case 4:

                    for (int i = 0; i < series.size(); i++)
                    {
                        cout << i + 1 << ")" << endl;
                        cout << series[i];
                    }
                    cout << endl;
                    a = true;
                    while (a)
                    {
                        cout << "Ingresa el número de la serie: ";
                        cin >> numP;
                        try
                        {
                            num = stoi(numP);
                            a = false;
                        }
                        catch (invalid_argument &e)
                        {
                            cout << "Error. " << e.what() << endl;
                        }
                    }
                    idSerie = series[num - 1]->getId();
                    genero = series[num - 1]->getGenero();
                    mostrarEpisodios(videos, idSerie, series, genero);

                    break;
                case 5:
                    a = true;
                    while (a)
                    {
                        cout << "Introduzca el rango inferior de la calificación: ";
                        cin >> rangI;
                        cout << "Introduzca el rango superior de la calificación: ";
                        cin >> rangS;
                        try
                        {
                            rangInf = stod(rangI);
                            rangSup = stod(rangS);
                            a = false;
                        }
                        catch (invalid_argument &e)
                        {
                            cout << "Error. " << e.what() << endl;
                        }
                    }
                    califPeliculas(videos, rangInf, rangSup);

                    break;
                case 6:
                    calificarVideo(videos);
                    break;
                case 0:
                    opcion = false;
                    break;
                }
            }
            catch (invalid_argument &e)
            {
                cout << "Error. " << e.what() << endl;
            }
        }
    }

    return 0;
}
