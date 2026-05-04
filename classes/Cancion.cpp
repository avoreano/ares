#include "Cancion.hpp"
#include <string>
using namespace std;


//Contructor para las canciones
Cancion::Cancion(){
    id = 0;
    nombre = "SinNombre";
    artista = "SinNombre";
    album = "SinNombre";
    anio = 0;
    duracion = 0;
    ruta = "";

};
//Constructor para parametros cuando se lean canciones
Cancion::Cancion(int _id, string _nombre, string _artista, string _album, int _anio, int _duracion, string _ruta){
    id = _id;
    nombre = _nombre;
    artista = _artista;
    album = _album;
    anio = _anio;
    duracion = _duracion;
    ruta = _ruta;

}