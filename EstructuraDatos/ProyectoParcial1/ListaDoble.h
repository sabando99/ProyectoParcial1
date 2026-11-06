/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase ListaDoble.h

#pragma once
#include <iostream>
#include "Nodo.h"

template <typename T>
class ListaDoble {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    int tamanio;

public:
    // Constructor
    ListaDoble() : cabeza(nullptr), cola(nullptr), tamanio(0) {}

    // Destructor 
    virtual ~ListaDoble() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->getSiguiente();
            delete actual;
            actual = siguiente;
        }
        cabeza = nullptr;
        cola = nullptr;
        tamanio = 0;
    }

    //metodo verificacion si esta vacia
    bool estaVacia() const {
        return cabeza == nullptr; 
    }

    // Inserta al inicio de la lista
    void insertarInicio(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (estaVacia()) {
            cabeza = nuevo;
            cola = nuevo;
        } else {
            nuevo->setSiguiente(cabeza);
            cabeza->setAnterior(nuevo);
            cabeza = nuevo;
        }
        tamanio++;
    }

    // Inserta al final de la lista
    void insertarFinal(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (estaVacia()) {
            cabeza = nuevo;
            cola = nuevo;
        } else {
            cola->setSiguiente(nuevo);
            nuevo->setAnterior(cola);
            cola = nuevo;
        }
        tamanio++;
    }

    // Elimina nodos repetidos
    bool eliminar(T dato) {
        if (estaVacia()) return false;

        Nodo<T>* actual = cabeza;

        while (actual != nullptr) {
            if (actual->getDato() == dato) {
                if (actual == cabeza && actual == cola) {
                    cabeza = nullptr;
                    cola = nullptr;
                } else if (actual == cabeza) {
                    cabeza = cabeza->getSiguiente();
                    cabeza->setAnterior(nullptr);
                } else if (actual == cola) {
                    cola = cola->getAnterior();
                    cola->setSiguiente(nullptr);
                } else {
                    actual->getAnterior()->setSiguiente(actual->getSiguiente());
                    actual->getSiguiente()->setAnterior(actual->getAnterior());
                }

                delete actual;
                tamanio--;
                return true;
            }
            actual = actual->getSiguiente();
        }
        return false;
    }

    // Metodo imprimir
    void mostrar() const {
        if (estaVacia()) {
            std::cout << "La lista esta vacia.\n";
            return;
        }
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->getDato() << std::endl;
            actual = actual->getSiguiente();
        }
    }

    //Metodo buscar a profesor por cedula
    Nodo<T>* buscarPorCedula(const std::string& cedula) {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        if (actual->getDato().getCedula() == cedula) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

    // Getters y Setters con const correctness
    void setCabeza(Nodo<T>* value) { cabeza = value; }
    Nodo<T>* getCabeza() const { return cabeza; }

    void setCola(Nodo<T>* value) { cola = value; }
    Nodo<T>* getCola() const { return cola; }

    void setTamanio(int value) { tamanio = value; }
    int getTamanio() const { return tamanio; }
};

 




