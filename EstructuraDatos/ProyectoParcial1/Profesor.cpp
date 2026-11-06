/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase Profesor.cpp

#include "Profesor.h"

Profesor::Profesor() 
    : cedula(""), nombres(""), apellidos("") {}

Profesor::Profesor(const std::string& cedula, 
                   const std::string& nombres, 
                   const std::string& apellidos)
    : cedula(cedula), nombres(nombres), apellidos(apellidos) {}

Profesor::~Profesor() {}

void Profesor::setCedula(const std::string& cedula) {
    this->cedula = cedula;
}

std::string Profesor::getCedula() const {
    return this->cedula;
}

void Profesor::setNombres(const std::string& nombres) {
    this->nombres = nombres;
}

std::string Profesor::getNombres() const {
    return this->nombres;
}

void Profesor::setApellidos(const std::string& apellidos) {
    this->apellidos = apellidos;
}

std::string Profesor::getApellidos() const {
    return this->apellidos;
}

void Profesor::mostrarInformacion() const {
    std::cout << "Docente: " << nombres << " " << apellidos 
              << " | CI: " << cedula << std::endl;
}

bool Profesor::operator==(const Profesor& otro) const {
    return this->cedula == otro.cedula;
}

std::ostream& operator<<(std::ostream& os, const Profesor& prof) {
    os << "Docente: " << prof.nombres << " " << prof.apellidos 
       << " [CI: " << prof.cedula << "]";
    return os;
}