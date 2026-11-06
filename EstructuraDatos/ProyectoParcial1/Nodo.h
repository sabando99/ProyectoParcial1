/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase Nodo.h


#pragma once

template <typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;

public:
    // Constructores
    Nodo(T dato) : dato(dato), siguiente(nullptr), anterior(nullptr) {}

    // Getters y Setters (DEBEN SER PUBLICOS)
    T getDato() const {
        return dato;
    }

    T& getDato() {
        return dato;
    }

    void setDato(T dato) {
        this->dato = dato;
    }

    Nodo<T>* getSiguiente() const {
        return siguiente;
    }

    void setSiguiente(Nodo<T>* siguiente) {
        this->siguiente = siguiente;
    }

    Nodo<T>* getAnterior() const {
        return anterior;
    }

    void setAnterior(Nodo<T>* anterior) {
        this->anterior = anterior;
    }
};