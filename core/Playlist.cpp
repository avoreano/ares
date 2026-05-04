#include "Playlist.hpp"
#include <iostream>

Playlist::Playlist(string nombre){
    nombrePlaylist = nombre;
}

Playlist::~Playlist(){
    /*Clase destructor, para vaciar memoria, pero creo que esta en LKList
    si esta borrala nomas.*/

}

void Playlist::agregarCanciones(Cancion c){
    lista.insertarFinal(c);
}

void Playlist::mostrarPlaylist(){
    if(lista.estaVacia()){
        cout << "La Playlist: " << nombrePlaylist << " esta vacia" << endl;
        return; 
    }
    cout << "----- PLAYLIST : " << nombrePlaylist << "-----" << endl;

    //Recorrer la lista de la playlist

    Nodo<Cancion>* actual = lista.getCabeza();
    int contador = 1;

    while(actual != nullptr){
        
        cout << contador << ". " << actual->dato.getNombre() << " - " << actual->dato.getArtista() << endl;
        
        actual = actual->siguiente;
        contador++;
    }
    cout << "--------------"<< endl;
}

int Playlist::getCantidadCanciones(){
    return lista.getTamanio();
}

LKList<Cancion>& Playlist::getLista(){
    return lista;
}