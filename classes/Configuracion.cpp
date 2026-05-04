#include "Configuracion.hpp"
#include <fstream> //libreria para poder modificar el archivo
#include <iostream>
#include <string>

Configuracion::Configuracion(){ //Valores por defecto del status.cfg
    estaReproduciendo = false;
    modoAleatorio = false;
    modoRepeticion = "Desactivado";
    idCancionActual = -1;
};

void Configuracion::guardarEstado(){
    ofstream arch("status.cfg"); // Se abre el archivo, para escribirlo
    if(arch.is_open()){
        arch << "REPRODUCIENDO "; if(estaReproduciendo == true){arch << "1"; } else{arch << "0";} arch << "\n";
        arch << "ALEATORIO "; if(modoAleatorio == true){arch << "1"; } else{arch << "0";} arch << "\n";
        arch << "REPETICION " << modoRepeticion << "\n";
        arch << "CANCION_ACTUAL " << idCancionActual << "\n";
        arch.close(); // Cierre del archivo
    } else {
        cout << "No se pudo abrir el archivo"<< endl;
    }
};

void Configuracion::cargarEstado(){
    ifstream arch("status.cfg");

    if(arch.is_open()){ //Revisa si el archivo esta abierto

        string parametro;
        string valor;
        
        
        while(arch >> parametro >> valor){ //Lee el archivo

            if(parametro == "REPRODUCIENDO"){
                estaReproduciendo = (valor == "1");

            } else if(parametro == "ALEATORIO"){
                modoAleatorio = (valor == "1");

            } else if(parametro == "REPETICION"){
                modoRepeticion = valor;

            } else if(parametro == "CANCION_ACTUAL"){
                idCancionActual = stoi(valor); //Se pasa el valor String a int con el stoi, para que veas que hace.
            }
            
        }
        
        arch.close();

    }else{
        cout << "Archivo no se encuentra" << endl;
    }

    

};