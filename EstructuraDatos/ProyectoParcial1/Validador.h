/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase Validador.h

#pragma once
#include <iostream>
#include <string>

class Validador {
public:
    Validador();
    virtual ~Validador();

    static bool validarCedula(const std::string& cedula);
    static bool soloNumeros(const std::string& cadena);
    static bool soloLetras(const std::string& cadena);
    static bool validarCodigoAula(const std::string& aula);
    static bool validarFecha(const std::string& fecha);
    static std::string obtenerNombreDia2026(int dia, int mes);
};