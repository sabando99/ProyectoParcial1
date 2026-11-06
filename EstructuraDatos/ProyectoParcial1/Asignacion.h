/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase Asignacion.h

#pragma once

#include <iostream>
#include <string>
#include "Profesor.h"

class Asignacion {
private:
    Profesor profesor;
    std::string aula;
    std::string dias;    
    std::string horario; 

public:
    Asignacion();
    Asignacion(const Profesor& profesor, 
               const std::string& aula, 
               const std::string& dias, 
               const std::string& horario);
    
    virtual ~Asignacion();

    // Getters y Setters
    Profesor getProfesor() const;
    std::string getAula() const;
    std::string getDias() const;
    std::string getHorario() const;

    void setProfesor(const Profesor& profesor);
    void setAula(const std::string& aula);
    void setDias(const std::string& dias);
    void setHorario(const std::string& horario);

    // Sobrecarga de igualdad para detectar cruces de aula/horario/día
    bool operator==(const Asignacion& otra) const;
    friend std::ostream& operator<<(std::ostream& os, const Asignacion& asig);
};