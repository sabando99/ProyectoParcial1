/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase RegistroClase.cpp

#include "RegistroClase.h"

RegistroClase::RegistroClase() 
    : asignacion(), fecha("--/--/----"), horaEntrada("--:--"), horaSalida("--:--"), observaciones("SIN REGISTRO"), estado(PENDIENTE) {}

RegistroClase::RegistroClase(const Asignacion& asignacion, const std::string& fecha)
    : asignacion(asignacion), fecha(fecha), horaEntrada("--:--"), horaSalida("--:--"), observaciones("PENDIENTE"), estado(PENDIENTE) {}

RegistroClase::~RegistroClase() {}

Asignacion RegistroClase::getAsignacion() const { return asignacion; }
std::string RegistroClase::getFecha() const { return fecha; }
std::string RegistroClase::getHoraEntrada() const { return horaEntrada; }
std::string RegistroClase::getHoraSalida() const { return horaSalida; }
std::string RegistroClase::getObservaciones() const { return observaciones; }
EstadoClase RegistroClase::getEstado() const { return estado; }

void RegistroClase::setHoraEntrada(const std::string& hora) { this->horaEntrada = hora; }
void RegistroClase::setHoraSalida(const std::string& hora) { this->horaSalida = hora; }
void RegistroClase::setObservaciones(const std::string& obs) { this->observaciones = obs; }
void RegistroClase::setEstado(EstadoClase nuevoEstado) { this->estado = nuevoEstado; }

void RegistroClase::registrarEntrada(const std::string& horaIngresada) {
    this->horaEntrada = horaIngresada;
    this->estado = EN_CURSO;
    this->observaciones = "ENTRADA A TIEMPO";
}

void RegistroClase::registrarSalida(const std::string& horaIngresada) {
    this->horaSalida = horaIngresada;
    this->estado = FINALIZADA;
}

std::string RegistroClase::getEstadoTexto() const {
    switch (estado) {
        case PENDIENTE: return "PENDIENTE (Vacia)";
        case EN_CURSO: return "EN CURSO (Profesor logueado)";
        case FINALIZADA: return "FINALIZADA (Profesor deslogueado)";
        default: return "DESCONOCIDO";
    }
}

bool RegistroClase::operator==(const RegistroClase& otro) const {
    return (this->asignacion == otro.asignacion && this->fecha == otro.fecha);
}

std::ostream& operator<<(std::ostream& os, const RegistroClase& reg) {
    os << "Fecha: " << reg.fecha
       << " | Aula: " << reg.asignacion.getAula() 
       << " | Bloque: " << reg.asignacion.getHorario()
       << " | Estado: " << reg.getEstadoTexto()
       << " | Docente (CI): " << reg.asignacion.getProfesor().getCedula()
       << " | Entrada: " << reg.horaEntrada 
       << " | Salida: " << reg.horaSalida
       << " | Obs: " << reg.observaciones;
    return os;
}