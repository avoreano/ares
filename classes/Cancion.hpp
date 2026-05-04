#pragma once
#include <string>
using namespace std;


class Cancion{
    private:
        int id;
        string nombre;
        string artista;
        string album;
        int anio;
        int duracion;
        string ruta = "";

    public:
    Cancion();
    Cancion(int id, string nombre, string artista, string album, int anio, int duracion, string ruta){
        this-> id = id; 
        this-> nombre = nombre; 
        this-> artista = artista; 
        this-> album = album; 
        this-> anio = anio; 
        this-> duracion = duracion;
        this-> ruta = ruta;
    }

};  