#include "Menu.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Menu::Menu(){
    reproductor.inicializar();
}

void Menu::printInterfaz() {
    // limpia la consola para que se vea mas limpio el menu cada vez que se actualice
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    Cancion* actual = reproductor.getCancionActual();
    Configuracion cfg = reproductor.getConfig();

    cout << "=====================================" << endl;
    cout << "            ARES 2.0                 " << endl;
    cout << "=====================================" << endl;

    if (actual != nullptr) {
        string modos = "";
        if (cfg.modoAleatorio) modos += "S";
        if (cfg.modoRepeticion != "Desactivado") {
            if (!modos.empty()) modos += "-";
            modos += cfg.modoRepeticion;
        }

        string estado;
        if (cfg.estaReproduciendo) {
            estado = "Reproduciendo";
        } else {
            estado = "En Pausa";
        }

        if (!modos.empty())
            cout << estado << " (" << modos << "): " << actual->getNombre() << endl;
        else
            cout << estado << ": " << actual->getNombre() << endl;

        cout << "Artista: " << actual->getArtista() << endl;
        cout << "Album: "   << actual->getAlbum() << " [" << actual->getAnio() << "]" << endl;
    } else {
        cout << "Reproduccion Detenida" << endl;
        cout << "No hay canciones cargadas" << endl;
    }

    cout << "=====================================" << endl;
    cout << "OPCIONES: " << endl;
    cout << "W - REPRODUCIR/PAUSAR" << endl;
    cout << "Q - CANCION ANTERIOR" << endl;
    cout << "E - CANCION SIGUIENTE" << endl;
    cout << "S - ACTIVAR/DESACTIVAR MODO ALEATORIO" << endl;    
    cout << "R - REPETICION (" << cfg.modoRepeticion << ")" << endl;
    cout << "A - VER LISTA DE REPRODUCCION ACTUAL" << endl;
    cout << "L - LISTADO DE CANCIONES" << endl;
    cout << "X - SALIR DE ARES" << endl;
    cout << "=====================================" << endl;
    cout << "OPCION: ";
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
            reproductor.cancionAnterior();
            break;

        case 'E': //Pista Siguiente.
            reproductor.cancionSiguiente();
            break;

        case 'S': //Activar/Desactivar modo aleatorio.
            reproductor.ponerAleatorio();
            break;

        case 'R': //Desactivar/Repetir una/Repetir todas.
            reproductor.ponerRepeticion();
            break;

        case 'A': //Ver lista de musica actual.
            reproductor.playlistActual();
            system("pause"); // Pausa para que se pueda ver la playlist antes de volver al menu
            break;

        case 'L': //Listado de canciones
            reproductor.mostrarRegistroTotal();
            system("pause"); // Lo mismo que el caso anterior, para poder ver el listado antes de volver al menu
            break;

        case 'X': //Salir (Cerrar Ares)
            funcionando = false;
            cout << "CERRANDO EL MEJOR REPRODUCTOR $ ARES $, ¡Hasta Luego Usuario!" << endl;
            break;
        
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            system("pause");
            break;
        }
    }
}