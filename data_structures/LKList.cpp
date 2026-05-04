#include <iostream>
#include "LKList.hpp"

// Constructor
template <typename A>
LKList<A>::LKList():
    cabeza(nullptr), cola(nullptr), tamanio(0) {}

// Destructor
template <typename A>
LKList<A>::~LKList() {
    vaciar();
}

// Funciones relacionadas al estado de la lista
template <typename A>
bool LKList::estaVacia() const {
    return cabeza == nullptr;
}
template <typename A>
int LKList::getTamanio() const {
    return tamanio;
}

// Funciones relacionadas a la insercion de valores
template <typename A>
void LKList::insertarInicio(A valor) {
}

template <typename A>
void LKList::insertarFinal(A valor) {
}

template <typename A>
void LKList::insertarEnPos(A valor, int pos) {
}

// Funciones relacionadas a la eliminacion de valores
template <typename A>
void LKList::eliminarInicio() {
}

template <typename A>
void LKList::eliminarFinal() {
}

template <typename A>
void LKList::eliminarEnPos(int pos) {
}

template <typename A>
bool LKList::eliminarPorValor(A valor) {
    return false;
}

// Getters
template <typename A>
A LKList::obtener(int pos) const {
    return A();
}

template <typename A>
A LKList::primero() const {
    return A();
}

template <typename A>
A LKList::ultimo() const {
    return A();
}

template <typename A>
Nodo<A>* LKList::getCabeza() const {
    return cabeza;
}

template <typename A>
Nodo<A>* LKList::getCola() const {
    return cola;
}

template <typename A>
Nodo<A>* LKList::getNodo(int pos) const {
    return nullptr;
}

// Funciones relacionadas a la busqueda de valores
template <typename A>
int LKList::buscar(A valor) const {
    return -1;
}

template <typename A>
bool LKList::contiene(A valor) const {
    return false;
}

// Prints
template <typename A>
void LKList::mostrarAdelante() const {
}

template <typename A>
void LKList::mostrarAtras() const {
}

// Operaciones necesarias para el reproductor
template <typename A>
void LKList::invertir() {
}

template <typename A>
void LKList::ordenar() {
}

template <typename A>
void LKList::vaciar() { 
}