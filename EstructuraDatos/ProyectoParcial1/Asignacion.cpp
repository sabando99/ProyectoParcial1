/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase Asignacion.cpp

#include "Asignacion.h"

Asignacion::Asignacion() 
    : profesor(), aula(""), dias(""), horario("") {}

Asignacion::Asignacion(const Profesor& profesor, 
                       const std::string& aula, 
                       const std::string& dias, 
                       const std::string& horario)
    : profesor(profesor), aula(aula), dias(dias), horario(horario) {}

Asignacion::~Asignacion() {}

Profesor Asignacion::getProfesor() const { return profesor; }
std::string Asignacion::getAula() const { return aula; }
std::string Asignacion::getDias() const { return dias; }
std::string Asignacion::getHorario() const { return horario; }

void Asignacion::setProfesor(const Profesor& profesor) { this->profesor = profesor; }
void Asignacion::setAula(const std::string& aula) { this->aula = aula; }
void Asignacion::setDias(const std::string& dias) { this->dias = dias; }
void Asignacion::setHorario(const std::string& horario) { this->horario = horario; }

// Hay cruce si coincide el Aula, los Días y la Franja Horaria
bool Asignacion::operator==(const Asignacion& otra) const {
    return (this->aula == otra.aula && 
            this->dias == otra.dias && 
            this->horario == otra.horario);
}

std::ostream& operator<<(std::ostream& os, const Asignacion& asig) {
    os << "\nAula: " << asig.aula 
       << "\nDias: " << asig.dias 
       << "\nHorario: " << asig.horario 
       << "\nDocente: " << asig.profesor.getNombres() << " " << asig.profesor.getApellidos()
       << "\nCI: " << asig.profesor.getCedula() ;
    return os;
}