#include <string>
#include <iostream>
using namespace std;


class Configuracion{
    public:
        bool estaReproduciendo; // True = Reproduciendo, False = pausa.
        bool modoAleatorio;     // Estado del modo aleatorio, False = Desactivado, True =  Activado.
        string modoRepeticion;  // Se activa con "R1" y "RA"
        int idCancionActual; // Este servira para saber en que quedo la reproduccion (Musica).

        Configuracion();


        void cargarEstado();
        void guardarEstado();
};