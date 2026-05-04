#include "Nodo.hpp"
/*Lista doblemente enlazada la cual vamos a ocupar para usar como base para
stack y queue, ademas va a contener la playlist*/

template <typename A>
class LKList {
protected:
    Nodo<A>* cabeza;
    Nodo<A>* cola;
    int tamanio;

public:
    LKList();
    ~LKList();

    // Funciones relacionadas al estado de la lista
    bool estaVacia() const;
    int getTamanio() const;

    // Funciones relacionadas a la insercion de nodos
    void insertarInicio(A valor);
    void insertarFinal(A valor);
    void insertarEnPos(A valor, int pos);

    // Funciones relacionadas a la eliminacion de nodos
    void eliminarInicio();
    void eliminarFinal();
    void eliminarEnPos(int pos);
    bool eliminarPorValor(A valor);

    // Getters
    A obtener(int pos) const;
    A primero() const;
    A ultimo() const;
    Nodo<A>* getCabeza() const;
    Nodo<A>* getCola() const;
    Nodo<A>* getNodo(int pos) const; // un puntero directo al nodo

    // Funciones relacionadas a la busqueda de nodos
    int buscar(A valor) const;
    bool contiene(A valor) const;

    // Prints
    void mostrarAdelante() const;
    void mostrarAtras() const;

    // Operaciones necesarias para el reproductor
    void invertir();
    void ordenar();
    void vaciar();

    #include "LKList.cpp"
};