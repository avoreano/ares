#pragma once
#include "../classes/Player.hpp"


class Menu {
    private:
        Player reproductor;

        void limpiador();
        void printInterfaz();
    
    public:
        Menu();
        void iniciar(); 
};