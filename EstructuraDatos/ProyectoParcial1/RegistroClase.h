/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase RegistroClase.h

#pragma once

#include <iostream>
#include <string>
#include "Asignacion.h"

enum EstadoClase {
    PENDIENTE,
    EN_CURSO,
    FINALIZADA
};

class RegistroClase {
private:
    Asignacion asignacion;
    std::string fecha; 
    std::string horaEntrada;
    std::string horaSalida;
    std::string observaciones;
    EstadoClase estado;

public:
    RegistroClase();
    RegistroClase(const Asignacion& asignacion, const std::string& fecha);
    virtual ~RegistroClase();

    Asignacion getAsignacion() const;
    std::string getFecha() const;
    std::string getHoraEntrada() const;
    std::string getHoraSalida() const;
    std::string getObservaciones() const;
    EstadoClase getEstado() const;

    void setHoraEntrada(const std::string& hora);
    void setHoraSalida(const std::string& hora);
    void setObservaciones(const std::string& obs);
    void setEstado(EstadoClase nuevoEstado);

    void registrarEntrada(const std::string& horaIngresada);
    void registrarSalida(const std::string& horaIngresada);

    std::string getEstadoTexto() const;
    
    bool operator==(const RegistroClase& otro) const;
    friend std::ostream& operator<<(std::ostream& os, const RegistroClase& reg);
};