#pragma once
#include <string>
#include "../data_structures/LKList.hpp"
#include "../classes/Cancion.hpp"
using namespace std;

class Playlist{
    private:
        LKList<Cancion> lista;
        string nombrePlaylist;
    
    public:
        Playlist(string nombre = "Mi Playlist");
        ~Playlist();

        void agregarCanciones(Cancion c);
        void mostrarPlaylist();
        int getCantidadCanciones();

        LKList<Cancion>& getLista(); //Esto devuelve una referencia para que se use en la clase player.
        
};