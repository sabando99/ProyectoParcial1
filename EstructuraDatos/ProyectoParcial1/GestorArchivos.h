/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase GestorArchivos.h

#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include "ListaDoble.h"
#include "Profesor.h"
#include "Asignacion.h"
#include "RegistroClase.h"

class GestorArchivos {
public:
    // Carga de datos inicial
    static void cargarProfesores(ListaDoble<Profesor>& lista);
    static void cargarAulas(ListaDoble<Asignacion>& listaAsig, ListaDoble<Profesor>& listaProf);
    static void cargarAsistencias(ListaDoble<RegistroClase>& listaReg, ListaDoble<Asignacion>& listaAsig);

    // Guardado completo
    static void guardarProfesores(ListaDoble<Profesor>& lista);
    static void guardarAulas(ListaDoble<Asignacion>& lista);
    static void guardarAsistencias(ListaDoble<RegistroClase>& lista);
};