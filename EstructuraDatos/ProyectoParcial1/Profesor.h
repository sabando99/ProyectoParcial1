/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase Profesor.h

#pragma once

#include <iostream>
#include <string>

class Profesor {
private:
    std::string cedula;
    std::string nombres;
    std::string apellidos;

public:
    // Constructores y Destructor
    Profesor();
    Profesor(const std::string& cedula, 
             const std::string& nombres, 
             const std::string& apellidos);
    
    virtual ~Profesor();

    // Getters y Setters
    void setCedula(const std::string& cedula);
    std::string getCedula() const;

    void setNombres(const std::string& nombres);
    std::string getNombres() const;

    void setApellidos(const std::string& apellidos);
    std::string getApellidos() const;

    // Método para mostrar datos
    void mostrarInformacion() const;

    // Sobrecarga de operadores
    // Cédula como criterio de igualdad único
    bool operator==(const Profesor& otro) const;
    friend std::ostream& operator<<(std::ostream& os, const Profesor& prof);
};