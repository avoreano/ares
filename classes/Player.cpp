#include "Player.hpp"
#include <iostream>

Player::Player(){
    nodoActual = nullptr;
}

Player::~Player(){
}

void Player::inicilizar(){
    cargarMusica();
    config.cargarEstado();
}

void Player::playOPausa(){
    if(registroCanciones.getTamanio == 0){
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
            nodo.actual = listaReproduccion.getCabeza();//Vuelve a la primer cancion de la lista.
        }
    }

    config.idCancionActual = nodoActual->dato.id;
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
            nodo.actual = listaReproduccion.getCola(); //Vuelve al final de la lista de reproduccion.
        }
    }

    config.idCancionActual = nodoActual->dato.id;
    config.guardarEstado();
}

void Player::ponerAleatorio(){
    config.modoAleatorio = !config.modoAleatorio; 
    if(config.modoAleatorio){
        //Falta por implementar un modo aleatorio.
    }
}

void Player::ponerRepeticion(){
    if (confi.modoRepeticion == "Desactivado"){
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
        return $(nodoActual->dato);
    }
    return nullptr;
}

Configuracion Player::getConfig(){
    return config;
}

void Player::cargarMusica(){
    /*Falta implementar logica para leer el txt de las canciones
    Agregar con la logica que puso el profe del txt
    id_interno,nombre_cancion,nombre_artista,nombre_album,año,duración_en_segundos,ubicacion_archivo */
}