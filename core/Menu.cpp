#include "Menu.hpp"
#include <iostream>
#include <string>
#include <cstdlib>


Menu::Menu(){
    reproductor.inicializar();
}

void Menu::printInterfaz(){

    cout << "=====================================" << endl;
    cout << "                ARES 2.0             " << endl;
    cout << "=====================================" << endl;
    cout << "OPCIONES: "<< endl;
    cout << "W - REPRODUCIR/PAUSAR"<< endl;
    cout << "Q - CANCION ANTERIOR"<< endl;
    cout << "E - CANCION SIGUIENTE"<< endl;
    cout << "S - ACTIVAR/DESACTIVAR MODO ALEATORIO"<< endl;
    cout << "R - REPETICION (DESACTIVADO / REPETIR UNA / REPETIR TODAS)"<< endl;
    cout << "A - VER LISTA DE REPRODUCCION ACTUAL"<< endl;
    cout << "L - LISTADO DE CANCIONES"<< endl;
    cout << "X - SALIR DE ARES"<< endl;
    cout << "OPCION: " << endl;
}

void Menu::iniciar(){
    char opcion;
    bool funcionando = true;

    while(funcionando){
        printInterfaz();
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion)
        {
        case 'W': //Reproduce/Pausa.
            reproductor.playOPausa();
            break;

        case 'Q': //Pista Anterior.
            reproductor.cancionSiguiente();
            break;

        case 'E': //Pista Siguiente.
            reproductor.cancionAnterior();
            break;

        case 'S': //Activar/Desactivar modo aleatorio.
            reproductor.ponerAleatorio();
            break;

        case 'R': //Desactivar/Repetir una/Repetir todas.
            reproductor.ponerRepeticion();
            break;

        case 'A': //Ver lista de musica actual.
            reproductor.playlistActual();
            break;

        case 'L': //Listado de canciones
            reproductor.mostrarRegistroTotal();
            break;

        case 'X': //Salir (Cerrar Ares)
            funcionando = false;
            cout << "CERRANDO EL MEJOR REPRODUCTOR $ ARES $, ¡Hasta Luego Usuario!"
            break;
        
        default:
            break;
        }
    }
}