/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase Validador.cpp

#include "Validador.h"
#include <regex>

Validador::Validador() {}
Validador::~Validador() {}

bool Validador::validarCedula(const std::string &cedula) {
  // Exactamente 10 dígitos y solo números
  if (cedula.length() != 10 || !soloNumeros(cedula)) {
    return false;
  }

  // Paso B: Validar código de provincia 
  int provincia = std::stoi(cedula.substr(0, 2));
  if ((provincia < 1 || provincia > 24) && provincia != 30) {
    return false;
  }

  // Paso C: Validar tercer dígito 
  int tercerDigito = cedula[2] - '0';
  if (tercerDigito >= 6) {
    return false;
  }

  // Algoritmo Módulo 10
  int coeficientes[] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
  int suma = 0;

  for (int i = 0; i < 9; ++i) {
    int valor = (cedula[i] - '0') * coeficientes[i];
    if (valor >= 10) {
      valor -= 9;
    }
    suma += valor;
  }

  int digitoVerificadorEsperado = (suma % 10 == 0) ? 0 : (10 - (suma % 10));
  int digitoVerificadorReal = cedula[9] - '0';

  return digitoVerificadorEsperado == digitoVerificadorReal;
}

bool Validador::soloNumeros(const std::string &cadena) {
  if (cadena.empty())
    return false;
  std::regex patron("^[0-9]+$");
  return std::regex_match(cadena, patron);
}

bool Validador::soloLetras(const std::string &cadena) {
  if (cadena.empty())
    return false;
  std::regex validar("^[a-zA-ZáéíóúÁÉÍÓÚñÑ ]+$");
  return std::regex_match(cadena, validar);
}

bool Validador::validarCodigoAula(const std::string &aula) {
  std::regex patron("^[A-Da-d](00[1-9]|0[1-9][0-9]|1[0-9]{2}|200)$");
  return std::regex_match(aula, patron);
}

bool Validador::validarFecha(const std::string &fecha) {

  std::regex patron("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[012])/2026$");
  return std::regex_match(fecha, patron);
}

std::string Validador::obtenerNombreDia2026(int dia, int mes) {
  
    static const int diasAcumulados[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    int diaDelAnio = diasAcumulados[mes - 1] + dia;

    int indiceDia = (4 + (diaDelAnio - 1)) % 7;

    switch (indiceDia) {
        case 0: return "Domingo";
        case 1: return "Lunes";
        case 2: return "Martes";
        case 3: return "Miercoles";
        case 4: return "Jueves";
        case 5: return "Viernes";
        case 6: return "Sabado";
        default: return "";
    }
}