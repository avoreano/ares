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
bool LKList<A>::estaVacia() const {
    return cabeza == nullptr;
}
template <typename A>
int LKList<A>::getTamanio() const {
    return tamanio;
}

// Funciones relacionadas a la insercion de nodos
template <typename A>
void LKList<A>::insertarInicio(A valor) {
    Nodo<A>* nuevo = new Nodo<A>(valor);
    if (estaVacia()) {
        cabeza = cola = nuevo;
    } else {
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
        cabeza = nuevo;
    }
    tamanio++;
}

template <typename A>
void LKList<A>::insertarFinal(A valor) {
    Nodo<A>* nuevo = new Nodo<A>(valor);
    if (estaVacia()) {
        cabeza = cola = nuevo;
    } else {
        nuevo-> anterior = cola;
        cola->siguiente = nuevo;
        cola = nuevo;
    }
    tamanio++;
}

template <typename A>
void LKList<A>::insertarEnPos(A valor, int pos) {
    if (pos < 0 || pos > tamanio) {
        std::cerr << "Posición inválida" << std::endl;
        return;
    }
    if (pos == 0) {
        insertarInicio(valor);
        return;
    }
    if (pos == tamanio) {
        insertarFinal(valor);
        return;
    }
    Nodo<A>* actual = getNodo(pos);
    Nodo<A>* nuevo = new Nodo<A>(valor);

    nuevo->siguiente = actual;
    nuevo->anterior = actual->anterior;
    actual->anterior->siguiente = nuevo;
    actual->anterior = nuevo;

    tamanio++;

}

// Funciones relacionadas a la eliminacion de nodos
template <typename A>
void LKList<A>::eliminarInicio() {
    if (estaVacia()) {
        std::cerr << "La lista está vacía" << std::endl;
        return;
    }
    Nodo<A>* temp = cabeza;
    if (cabeza == cola) {
        cabeza = cola = nullptr;
    } else {
        cabeza = cabeza->siguiente;
        cabeza->anterior = nullptr;
    }
    delete temp;
    tamanio--;
}

template <typename A>
void LKList<A>::eliminarFinal() {
    if (estaVacia()) {
        std::cerr << "La lista está vacía" << std::endl;
        return;
    }
    Nodo<A>* temp = cola;
    if (cabeza == cola) {
        cabeza = cola = nullptr;
    } else {
        cola = cola->anterior;
        cola->siguiente = nullptr;
    }
    delete temp;
    tamanio--;
}

template <typename A>
void LKList<A>::eliminarEnPos(int pos) {
    if (pos < 0 || pos >= tamanio) {
        std::cerr << "Posición inválida" << std::endl;
        return;
    }
    if (pos == 0) {
        eliminarInicio();
        return;
    }
    if (pos == tamanio - 1) {
        eliminarFinal();
        return;
    }
    Nodo<A>* temp = getNodo(pos);
    temp->anterior->siguiente = temp->siguiente;
    temp->siguiente->anterior = temp->anterior;
    delete temp;
    tamanio--;
}

template <typename A>
bool LKList<A>::eliminarPorValor(A valor) {
    Nodo<A>* actual = cabeza;
    while (actual) {
        if (actual->dato == valor) {
            if (actual == cabeza) {
                eliminarInicio();
            } else if (actual == cola) {
                eliminarFinal();
            } else {
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
                delete actual;
                tamanio--;
            }
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

// Getters
template <typename A>
A LKList<A>::obtener(int pos) const {
    return getNodo(pos)->dato;
}

template <typename A>
A LKList<A>::primero() const {
    if (estaVacia()) {
        std::cerr << "La lista está vacía" << std::endl;
        return A();
}
    return cabeza->dato;
}

template <typename A>
A LKList<A>::ultimo() const {
    if (estaVacia()) {
        std::cerr << "La lista está vacía" << std::endl;
        return A();
    }
    return cola->dato;
}

template <typename A>
Nodo<A>* LKList<A>::getCabeza() const {
    return cabeza;
}

template <typename A>
Nodo<A>* LKList<A>::getCola() const {
    return cola;
}

template <typename A>
Nodo<A>* LKList<A>::getNodo(int pos) const {
    if (pos < 0 || pos >= tamanio) {
        std::cerr << "Posición inválida" << std::endl;
        return nullptr;
    }
    Nodo<A>* actual;
    if (pos <= tamanio / 2) {
        actual = cabeza;
        for (int i = 0; i < pos; i++) {
            actual = actual->siguiente;
        }
    } else {
        actual = cola;
        for (int i = tamanio - 1; i > pos; i--) {
            actual = actual->anterior;
        }
    }
    return actual;
}

// Funciones relacionadas a la busqueda de nodos
template <typename A>
int LKList<A>::buscar(A valor) const {
    Nodo<A>* actual = cabeza;
    int pos = 0;
    while (actual != nullptr) {
        if (actual->dato == valor) {
            return pos;
        }
        actual = actual->siguiente;
        pos++;
    }
    return -1;
}

template <typename A>
bool LKList<A>::contiene(A valor) const {
    return buscar(valor) != -1;
}

// Prints
template <typename A>
void LKList<A>::mostrarAdelante() const {
    if (estaVacia()) {
        std::cout << "La lista está vacía" << std::endl;
        return;
    }
    Nodo<A>* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

template <typename A>
void LKList<A>::mostrarAtras() const {
    if (estaVacia()) {
        std::cout << "La lista está vacía" << std::endl;
        return;
    }
    Nodo<A>* actual = cola;
    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->anterior;
    }
    std::cout << std::endl;
}

// Operaciones necesarias para el reproductor
template <typename A>
void LKList<A>::invertir() {
    if (tamanio <= 1) return;
    Nodo<A>* actual = cabeza;
    // Intercambiar los punteros siguiente y anterior de cada nodo
    while(actual != nullptr) {
        Nodo<A>* temp = actual->siguiente;
        actual->siguiente = actual->anterior;
        actual->anterior = temp;
        actual = temp;
    }
    // Intercambiar cabeza y cola
    Nodo<A>* temp = cabeza;
    cabeza = cola;
    cola = temp;
    // No es necesario actualizar el tamaño ya que no cambia
}

template <typename A>
void LKList<A>::ordenar() {
    // Implementacion de bubble sort para ordenar la lista
    if (tamanio <= 1) return;

    bool intercambiado;
    for (int i = 0; i < tamanio - 1; i++) {
        intercambiado = false;
        Nodo<A>* actual = cabeza;

        for (int j = 0; j < tamanio - i - 1; j++) {
            if (actual->dato > actual->siguiente->dato) {
                A temp = actual->dato;
                actual->dato = actual->siguiente->dato;
                actual->siguiente->dato = temp;
                intercambiado = true;
            }
            actual = actual->siguiente;
        }
        if (!intercambiado) break; // Si no se hicieron intercambios, la lista ya está ordenada
    }
}

template <typename A>
void LKList<A>::vaciar() { 
    while (!estaVacia()) {
        eliminarInicio();
    }
}