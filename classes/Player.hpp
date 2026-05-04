#include "data_structures/LkList.hpp"
#include "Cancion.hpp"
#include "Configuracion.hpp"

class Player{
    private:
        LKList<Cancion> registroCanciones;
        LKList<Cancion> listaReproduccion; //Se ocupara para lista de canciones.
        Nodo<Cancion>* nodoActual; //Puntero de cancion que actualmente suena.
        Configuracion config;  //Esto maneja el status.cfg
    
        void cargarMusica();

    public:
        Player();
        ~Player(); //Limpiador del player

        void inicializar();

        //Funciones del menu principal
        void playOPausa();
        void cancionSiguiente();
        void cancionAnterior();
        void ponerAleatorio();
        void ponerRepeticion();

        //Getter para printear canciones en el menu
        Cancion* getCancionActual();
        Configuracion getConfig();

};