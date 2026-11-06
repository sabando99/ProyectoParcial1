/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase GestorArchivos.cpp

#include "GestorArchivos.h"

void GestorArchivos::cargarProfesores(ListaDoble<Profesor>& lista) {
    std::ifstream archivo("profesores.txt");
    if (!archivo.is_open()) return;

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;
        std::stringstream ss(linea);
        std::string cedula, nombres, apellidos;

        std::getline(ss, cedula, ';');
        std::getline(ss, nombres, ';');
        std::getline(ss, apellidos, ';');

        if (!cedula.empty()) {
            Profesor p(cedula, nombres, apellidos);
            lista.insertarFinal(p);
        }
    }
    archivo.close();
}

void GestorArchivos::cargarAulas(ListaDoble<Asignacion>& listaAsig, ListaDoble<Profesor>& listaProf) {
    std::ifstream archivo("aulas.txt");
    if (!archivo.is_open()) return;

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;
        std::stringstream ss(linea);
        std::string cedula, aula, dias, horario;

        std::getline(ss, cedula, ';');
        std::getline(ss, aula, ';');
        std::getline(ss, dias, ';');
        std::getline(ss, horario, ';');

        // Buscar al profesor por cédula
        Nodo<Profesor>* actual = listaProf.getCabeza();
        Profesor* profPtr = nullptr;
        while (actual != nullptr) {
            if (actual->getDato().getCedula() == cedula) {
                profPtr = &(actual->getDato());
                break;
            }
            actual = actual->getSiguiente();
        }

        if (profPtr != nullptr) {
            Asignacion a(*profPtr, aula, dias, horario);
            listaAsig.insertarFinal(a);
        }
    }
    archivo.close();
}

void GestorArchivos::cargarAsistencias(ListaDoble<RegistroClase>& listaReg, ListaDoble<Asignacion>& listaAsig) {
    std::ifstream archivo("asistencias.txt");
    if (!archivo.is_open()) return;

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;
        std::stringstream ss(linea);
        std::string fecha, aula, horario, cedula, horaEntrada, horaSalida, obs, estadoStr;

        std::getline(ss, fecha, ';');
        std::getline(ss, aula, ';');
        std::getline(ss, horario, ';');
        std::getline(ss, cedula, ';');
        std::getline(ss, horaEntrada, ';');
        std::getline(ss, horaSalida, ';');
        std::getline(ss, obs, ';');
        std::getline(ss, estadoStr, ';');

        // Buscar la asignación correspondiente
        Nodo<Asignacion>* actual = listaAsig.getCabeza();
        Asignacion* asigPtr = nullptr;
        while (actual != nullptr) {
            if (actual->getDato().getAula() == aula &&
                actual->getDato().getHorario() == horario &&
                actual->getDato().getProfesor().getCedula() == cedula) {
                asigPtr = &(actual->getDato());
                break;
            }
            actual = actual->getSiguiente();
        }

        if (asigPtr != nullptr) {
            RegistroClase reg(*asigPtr, fecha);
            reg.setHoraEntrada(horaEntrada);
            reg.setHoraSalida(horaSalida);
            reg.setObservaciones(obs);

            int st = std::stoi(estadoStr);
            reg.setEstado(static_cast<EstadoClase>(st));

            listaReg.insertarFinal(reg);
        }
    }
    archivo.close();
}

void GestorArchivos::guardarProfesores(ListaDoble<Profesor>& lista) {
    std::ofstream archivo("profesores.txt", std::ios::trunc);
    if (!archivo.is_open()) return;

    Nodo<Profesor>* actual = lista.getCabeza();
    while (actual != nullptr) {
        Profesor p = actual->getDato();
        archivo << p.getCedula() << ";" << p.getNombres() << ";" << p.getApellidos() << "\n";
        actual = actual->getSiguiente();
    }
    archivo.close();
}

void GestorArchivos::guardarAulas(ListaDoble<Asignacion>& lista) {
    std::ofstream archivo("aulas.txt", std::ios::trunc);
    if (!archivo.is_open()) return;

    Nodo<Asignacion>* actual = lista.getCabeza();
    while (actual != nullptr) {
        Asignacion a = actual->getDato();
        archivo << a.getProfesor().getCedula() << ";" 
                << a.getAula() << ";" 
                << a.getDias() << ";" 
                << a.getHorario() << "\n";
        actual = actual->getSiguiente();
    }
    archivo.close();
}

void GestorArchivos::guardarAsistencias(ListaDoble<RegistroClase>& lista) {
    std::ofstream archivo("asistencias.txt", std::ios::trunc);
    if (!archivo.is_open()) return;

    Nodo<RegistroClase>* actual = lista.getCabeza();
    while (actual != nullptr) {
        RegistroClase r = actual->getDato();
        archivo << r.getFecha() << ";"
                << r.getAsignacion().getAula() << ";"
                << r.getAsignacion().getHorario() << ";"
                << r.getAsignacion().getProfesor().getCedula() << ";"
                << r.getHoraEntrada() << ";"
                << r.getHoraSalida() << ";"
                << r.getObservaciones() << ";"
                << static_cast<int>(r.getEstado()) << "\n";
        actual = actual->getSiguiente();
    }
    archivo.close();
}