#include "Player.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;



Player::Player(){
    nodoActual = nullptr;
}

Player::~Player(){
}

void Player::inicializar(){
    cargarMusica();
    config.cargarEstado();

    if(!listaReproduccion.getLista().estaVacia() && nodoActual == nullptr){
        nodoActual = listaReproduccion.getLista().getCabeza();
    }
}

void Player::playOPausa(){
    if(registroCanciones.getTamanio() == 0){
        return;
    }
    config.estaReproduciendo = !config.estaReproduciendo;
    config.guardarEstado();
}

void Player::cancionSiguiente(){
    if(!nodoActual){
        return;
    }  

    if(config.modoRepeticion == "R1"){

    } else if (nodoActual-> siguiente != nullptr){
        nodoActual =  nodoActual-> siguiente;
    } else {
        //Lista de canciones llego al final
        if(config.modoRepeticion == "RA"){
            nodoActual = listaReproduccion.getLista().getCabeza();//Vuelve a la primer cancion de la lista.
        }
    }

    config.idCancionActual = nodoActual->dato.getId();
    config.guardarEstado();
}

void Player::cancionAnterior(){
    if(!nodoActual){
        return;
    }  

    if(config.modoRepeticion == "R1"){

    } else if (nodoActual->anterior != nullptr){
        nodoActual =  nodoActual-> anterior;
    } else {
        //Lista de canciones llego al principio de la lista
        if(config.modoRepeticion == "RA"){
            nodoActual = listaReproduccion.getLista().getCola(); //Vuelve al final de la lista de reproduccion.
        }
    }

    config.idCancionActual = nodoActual->dato.getId();
    config.guardarEstado();
}

void Player::ponerAleatorio(){
    config.modoAleatorio = !config.modoAleatorio; 
    if(config.modoAleatorio){
        //Falta por implementar un modo aleatorio.
    }
    config.guardarEstado();
}

void Player::ponerRepeticion(){
    if (config.modoRepeticion == "Desactivado"){
        config.modoRepeticion = "R1";

    } else if(config.modoRepeticion == "R1"){
        config.modoRepeticion = "RA";

    } else {
        config.modoRepeticion = "Desactivado";

    }
    config.guardarEstado();
}

Cancion* Player::getCancionActual(){
    if(nodoActual != nullptr){
        return &(nodoActual->dato);
    }
    return nullptr;
}

Configuracion Player::getConfig(){
    return config;
}

void Player::playlistActual(){ 
    if(listaReproduccion.getLista().estaVacia()){
        cout << "Lista de reproduccion vacia"<< endl;
        return;
    }
    cout << "--------PLAYLIST ACTUAL--------" << endl;
    Nodo<Cancion>* actual = listaReproduccion.getLista().getCabeza();
    int contador = 1;
    
    while(actual != nullptr){
        if(nodoActual != nullptr && actual->dato.getId() == nodoActual->dato.getId()){
            cout << "->";
        } else{
            cout << "Vacia";
        }

        cout << contador << ". "<< actual->dato.getNombre() << " - " << actual->dato.getArtista() << endl;
        actual = actual->siguiente;
        contador++;
    }
    cout << "-------------"<< endl;
}

void Player::mostrarRegistroTotal(){
    if(registroCanciones.estaVacia()){
        cout << "El registro de canciones esta vacio" << endl;
        return;
    }

    cout << "---- MUSICA DISPONIBLE ----" << endl;
    Nodo<Cancion>* actual = registroCanciones.getCabeza();
    while(actual != nullptr){
        
        cout << "ID" << actual->dato.getId() << " | " << actual->dato.getNombre() << " - " << actual->dato.getArtista() 
        << "( " << actual->dato.getAlbum() << endl;
        
        actual = actual->siguiente;
    }
    cout << "----------------------" << endl;
}

void Player::cargarMusica(){
    /*Falta implementar logica para leer el txt de las canciones
    Agregar con la logica que puso el profe del txt
    id_interno,nombre_cancion,nombre_artista,nombre_album,año,duración_en_segundos,ubicacion_archivo */

    ifstream arch("music_source.txt");

    if(!arch.is_open()){
        cout << "No se encontro el archivo music_source.txt";
        return;
    }
    string linea;
    int numeroLinea = 0;
    while(getline(arch, linea)){
        numeroLinea++;

        if(linea.empty()){
            continue;
        }
        stringstream ss(linea);
        string id_interno, nombre, artista, album, str_anio, str_duracion, ruta;

        getline(ss, id_interno ,',');//int
        getline(ss, nombre,',');
        getline(ss, artista,',');
        getline(ss, album,',');
        getline(ss, str_anio,','); //int
        getline(ss, str_duracion,',');//int
        getline(ss, ruta,',');

        try
        {
            int id = stoi(id_interno);
            int anio = stoi(anio);
            int duracion = stoi(duracion);

            Cancion c(id, nombre, artista, album, anio, duracion, ruta);

            registroCanciones.insertarFinal(c);

            listaReproduccion.agregarCancion(c);
        }

        catch(const std::exception& e)
        {
            cout << "Error en las lineas o en la lectura" << e.what() << endl;
        }
        

    }
    arch.close();
}