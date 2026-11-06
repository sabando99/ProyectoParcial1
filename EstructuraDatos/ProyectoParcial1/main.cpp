/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase Principal

#include <iostream>
#include "Menu.h"
#include "ListaDoble.h"
#include "Profesor.h"
#include "Asignacion.h"
#include "RegistroClase.h"
#include "GestorArchivos.h"

int main() {
    Menu menu;
    ListaDoble<Profesor> listaProfesores;
    ListaDoble<Asignacion> listaAsignaciones;
    ListaDoble<RegistroClase> listaRegistros;  

    // 1. Carga automática de datos al iniciar el programa
    GestorArchivos::cargarProfesores(listaProfesores);
    GestorArchivos::cargarAulas(listaAsignaciones, listaProfesores);
    GestorArchivos::cargarAsistencias(listaRegistros, listaAsignaciones);

    char a = '0';

    do {
        std::cout << "\nSISTEMA DE ASISTENCIA ";
        std::cout << "\n1. Gestion de profesores";
        std::cout << "\n2. Gestion de aulas";
        std::cout << "\n3. Modulo de logueo";
        std::cout << "\n4. Registro de asistencias";
        std::cout << "\n5. Salir";
        std::cout << "\nSeleccione una opcion: ";
        
        std::cin >> a;
        std::cin.ignore(10000, '\n');

        switch (a) { 
            case '1': 
                menu.mostrarSubmenuProfesores(listaProfesores);
                GestorArchivos::guardarProfesores(listaProfesores); // Guarda cambios
                break;

            case '2':
                menu.mostrarSubmenuAulas(listaAsignaciones, listaProfesores);
                GestorArchivos::guardarAulas(listaAsignaciones); // Guarda cambios
                break;

            case '3':
                menu.mostrarSubmenuLogueo(listaRegistros, listaAsignaciones, listaProfesores);
                GestorArchivos::guardarAsistencias(listaRegistros); // Guarda cambios
                break;

            case '4':
                std::cout << "\nRegistro de Asistencias\n";
                if (listaRegistros.estaVacia()) {
                    std::cout << "No hay asistencias registradas.\n";
                } else {
                    listaRegistros.mostrar();
                }
                break;

            case '5':
               
                GestorArchivos::guardarProfesores(listaProfesores);
                GestorArchivos::guardarAulas(listaAsignaciones);
                GestorArchivos::guardarAsistencias(listaRegistros);
                std::cout << "Saliendo..\n";
                break;
            
            default:
                std::cout << "Opcion no valida";
                break;
        }

    } while (a != '5');

    return 0;
}