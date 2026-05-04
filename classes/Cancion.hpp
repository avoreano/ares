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
    Cancion(int id, string nombre, string artista, string album, int anio, int duracion, string ruta);
    
    //Getters para llamadas
    int getId() const;
    string getNombre() const;
    string getArtista() const;
    string getAlbum() const;
    int getAnio() const;
    int getDuracion() const;
    string getRuta() const;

};  