/*En vez de hacer una clase hice un struct por la cantidad de datos que
tiene que tomar el valor del nodo, puede ser tanto un int como un string*/
#pragma once
template <typename A>
struct Nodo {
    A dato;
    Nodo<A>* siguiente;
    Nodo<A>* anterior;

    Nodo(A valor):
    dato(valor), siguiente(nullptr), anterior(nullptr) {}
};