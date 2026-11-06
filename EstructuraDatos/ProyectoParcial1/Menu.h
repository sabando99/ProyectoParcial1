/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase Menu.h

#pragma once

#include "Asignacion.h"
#include "ListaDoble.h"
#include "Profesor.h"
#include "RegistroClase.h"
#include "Validador.h"
#include <iostream>
#include <string>

class Menu {
public:
 
  void mostrarSubmenuProfesores(ListaDoble<Profesor> &listaProfesores);

  void mostrarSubmenuAulas(ListaDoble<Asignacion> &listaAsignaciones,
                           ListaDoble<Profesor> &listaProfesores);

  void mostrarSubmenuLogueo(ListaDoble<RegistroClase> &listaRegistros,
                            ListaDoble<Asignacion> &listaAsignaciones,
                            ListaDoble<Profesor> &listaProfesores);

  void mostrarMenuPrincipal(ListaDoble<Profesor> &listaProfesores,
                            ListaDoble<Asignacion> &listaAsignaciones,
                            ListaDoble<RegistroClase> &listaRegistros);
};