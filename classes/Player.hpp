#include "../data_structures/LKList.hpp"
#include "Cancion.hpp"
#include "Configuracion.hpp"
#include "../core/Playlist.hpp"

class Player{
    private:
        LKList<Cancion> registroCanciones;
        Playlist listaReproduccion; //Se ocupara para lista de canciones.
        Nodo<Cancion>* nodoActual; //Puntero de cancion que actualmente suena.
        Configuracion config;  //Esto maneja el status.cfg
    
        void cargarMusica();

    public:
        Player();
        ~Player(); //Limpiador del player

        void inicializar();

        //Funciones del menu principal (Controles de reproduccion)
        void playOPausa();
        void cancionSiguiente();
        void cancionAnterior();
        void ponerAleatorio();
        void ponerRepeticion();

        //Metodos para poder printear en el menu
        void playlistActual();
        void mostrarRegistroTotal();

        //Getter de estado
        Cancion* getCancionActual();
        Configuracion getConfig();
        

};