/* Universidad de las Fuerzas Armadas 
     Ciencias de la Computacion
        Estructura de Datos

    Nombre: Erick Sabando 
    Fecha: 06/11/2026              
    Tema: Registro de Profesores
*/

// Clase Menu.cpp

#include "Menu.h"
#include "RegistroClase.h"
#include "Validador.h"
#include <iostream>
#include <string>

void Menu::mostrarSubmenuProfesores(ListaDoble<Profesor> &listaProfesores) {
    char opcion = '0';

    do {
        std::cout << "\nGestion de Profesores";
        std::cout << "\n1. Registrar profesor";
        std::cout << "\n2. Profesores registrados";
        std::cout << "\n3. Regresar";
        std::cout << "\nSeleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(10000, '\n');

        switch (opcion) {
        case '1': {
            std::cout << "\nRegistro de Profesor\n";
            std::string cedula, nombres, apellidos;

            // Validar Cédula de 10 dígitos
            bool cedulaValida = false;
            do {
                std::cout << "Ingrese Cedula: ";
                std::getline(std::cin, cedula);

                if (!Validador::validarCedula(cedula)) {
                    std::cout << "Cedula no valida\n";
                    continue;
                }

                // Verificar si ya existe en la lista
                bool existe = false;
                Nodo<Profesor> *actual = listaProfesores.getCabeza();
                while (actual != nullptr) {
                    if (actual->getDato().getCedula() == cedula) {
                        existe = true;
                        break;
                    }
                    actual = actual->getSiguiente();
                }

                if (existe) {
                    std::cout << "Ya existe un profesor registrado con la cedula: " << cedula << "\n";
                } else {
                    cedulaValida = true;
                }
            } while (!cedulaValida);

            // Validar nombres solo letras
            do {
                std::cout << "Ingrese Nombres: ";
                std::getline(std::cin, nombres);
            } while (!Validador::soloLetras(nombres));

            // Validar apellidos solo letras
            do {
                std::cout << "Ingrese Apellidos: ";
                std::getline(std::cin, apellidos);
            } while (!Validador::soloLetras(apellidos));

            Profesor nuevoProfesor(cedula, nombres, apellidos);
            listaProfesores.insertarFinal(nuevoProfesor);
            std::cout << "\nProfesor registrado correctamente\n";
            break;
        }

        case '2':
            std::cout << "\nProfesores registrados\n";
            if (listaProfesores.estaVacia()) {
                std::cout << "No hay profesores registrados actualmente.\n";
            } else {
                listaProfesores.mostrar();
            }
            break;

        case '3':
            std::cout << "Regresando al menu principal...\n";
            break;

        default:
            std::cout << "Opcion no valida. Intente de nuevo.\n";
            break;
        }

    } while (opcion != '3');
}


  void Menu::mostrarSubmenuAulas(ListaDoble<Asignacion> & listaAsignaciones,
                                 ListaDoble<Profesor> & listaProfesores) {
    char opcion = '0';

    do {
      std::cout << "\nGestion de Cursos";

      std::cout << "\n1. Registrar aulas";
      std::cout << "\n2. Aulas registradas";
      std::cout << "\n3. Regresar";
      std::cout << "\nSeleccione una opcion: ";
      std::cin >> opcion;
      std::cin.ignore(10000, '\n');
      switch (opcion) {
      case '1': {
        std::cout << "\nRegistro de Aula\n";
        if (listaProfesores.estaVacia()) {
          std::cout << "No hay profesores registrados\n";
          break;
        }

        std::string cedula;
        std::cout << "Ingrese Cedula del profesor: ";
        std::getline(std::cin, cedula);

        if (!Validador::validarCedula(cedula)) {
          std::cout << "Cedula invalida.\n";
          break;
        }



        // Buscar si el profesor existe
        Nodo<Profesor> *actualProf = listaProfesores.getCabeza();
        Profesor *profEncontrado = nullptr;

        while (actualProf != nullptr) {
          if (actualProf->getDato().getCedula() == cedula) {
            profEncontrado = &(actualProf->getDato());
            break;
          }
          actualProf = actualProf->getSiguiente();
        }

        if (profEncontrado == nullptr) {
          std::cout << "Profesor no registrado\n";
          break;
        }

        // Validación de Código de Aula (A001 - D200)
        std::string aula;
        do {
          std::cout << "Ingrese codigo de Aula\nDebe iniciar con A, B, C o D "
                       "seguido de 001 a 200.(Ej: A001, B115, D200): ";
          std::getline(std::cin, aula);

          if (!Validador::validarCodigoAula(aula)) {
            std::cout << "Formato invalido\n";
          }
        } while (!Validador::validarCodigoAula(aula));

        // Convertir la letra inicial a mayúscula
        aula[0] = std::toupper(aula[0]);

        // Selección de Días
        char opcDia;
        std::string dias = "";
        do {
          std::cout << "\nSeleccione el esquema de dias:\n";
          std::cout << "1. Lunes - Miercoles - Viernes (L-M-V)\n";
          std::cout << "2. Martes - Jueves (M-J)\n";
          std::cout << "Opcion: ";
          std::cin >> opcDia;
          std::cin.ignore(10000, '\n');

          if (opcDia == '1')
            dias = "L-M-V";
          else if (opcDia == '2')
            dias = "M-J";
          else
            std::cout << "Opcion no valida.\n";
        } while (dias.empty());

        // Selección de Franja Horaria
        char opcHorario;
        std::string horario = "";
        do {
          std::cout << "\nSeleccione la franja horaria:\n";
          std::cout << "1. 07:00 - 09:00\n";
          std::cout << "2. 09:00 - 11:00\n";
          std::cout << "3. 11:00 - 13:00\n";
          std::cout << "Opcion: ";
          std::cin >> opcHorario;
          std::cin.ignore(10000, '\n');

          if (opcHorario == '1')
            horario = "07:00-09:00";
          else if (opcHorario == '2')
            horario = "09:00-11:00";
          else if (opcHorario == '3')
            horario = "11:00-13:00";
          else
            std::cout << "Opcion no valida.\n";
        } while (horario.empty());

        // Verificar cruces en la asignación
        Asignacion nuevaAsig(*profEncontrado, aula, dias, horario);

        bool ocupado = false;
        Nodo<Asignacion> *actualAsig = listaAsignaciones.getCabeza();
        while (actualAsig != nullptr) {
          if (actualAsig->getDato() == nuevaAsig) {
            ocupado = true;
            break;
          }
          actualAsig = actualAsig->getSiguiente();
        }

        if (ocupado) {
          std::cout << "\nEl aula " << aula << " ya esta ocupada en el horario "
                    << horario << " (" << dias << ").\n";
        } else {
          listaAsignaciones.insertarFinal(nuevaAsig);
          std::cout << "\nAula " << aula
                    << " asignada correctamente al docente "
                    << profEncontrado->getNombres() << " "
                    << profEncontrado->getApellidos() << ".\n";
        }
        break;
      }

      case '2':
        std::cout << "\nAulas Registradas\n";
        if (listaAsignaciones.estaVacia()) {
          std::cout << "No hay aulas asignadas actualmente.\n";
        } else {
          listaAsignaciones.mostrar();
        }
        break;

      case '3':
        std::cout << "Regresando al menu principal...\n";
        break;

      default:
        std::cout << "Opcion no valida. Intente de nuevo.\n";
        break;
      }

    } while (opcion != '3');
  }

  void Menu::mostrarSubmenuLogueo(ListaDoble<RegistroClase> & listaRegistros,
                                  ListaDoble<Asignacion> & listaAsignaciones,
                                  ListaDoble<Profesor> & listaProfesores) {
    char opcion = '0';
    do {
      std::cout << "\nGestion de Logueo";

      std::cout << "\n1. Registrar entradas";
      std::cout << "\n2. Registrar salidas";
      std::cout << "\n3. Regresar";
      std::cout << "\nSeleccione una opcion: ";
      std::cin >> opcion;
      std::cin.ignore(10000, '\n');
      switch (opcion) {
     case '1': {
        std::cout << "\nRegistro de entrada\n";
        if (listaAsignaciones.estaVacia()) {
          std::cout << "No hay aulas asignadas registradas \n";
          break;
        }

        std::string cedula;
        std::cout << "Ingrese Cedula del profesor: ";
        std::getline(std::cin, cedula);

        if (!Validador::validarCedula(cedula)) {
          std::cout << "Cedula invalida.\n";
          break;
        }

        Nodo<Asignacion> *actualAsig = listaAsignaciones.getCabeza();
        ListaDoble<Asignacion *> asignacionesProfesor;

        while (actualAsig != nullptr) {
          if (actualAsig->getDato().getProfesor().getCedula() == cedula) {
            Asignacion *ptr = &(actualAsig->getDato());
            asignacionesProfesor.insertarFinal(ptr);
          }
          actualAsig = actualAsig->getSiguiente();
        }

        if (asignacionesProfesor.estaVacia()) {
          std::cout << "El profesor con cedula " << cedula
                    << " no tiene aulas asignadas.\n";
          break;
        }

        // Mostrar la lista de cursos 
        std::cout << "\nCursos asignados al docente:\n";
        Nodo<Asignacion *> *nodoOpcion = asignacionesProfesor.getCabeza();
        int indice = 1;
        while (nodoOpcion != nullptr) {
          Asignacion *asigPtr = nodoOpcion->getDato();
          std::cout << indice << ". Aula: " << asigPtr->getAula()
                    << " | Horario: " << asigPtr->getHorario() << " ("
                    << asigPtr->getDias() << ")\n";
          nodoOpcion = nodoOpcion->getSiguiente();
          indice++;
        }

        std::string strSeleccion;
        int seleccion = 0;
        do {
          std::cout << "Seleccione el numero de curso: ";
          std::getline(std::cin, strSeleccion);
          if (Validador::soloNumeros(strSeleccion)) {
            seleccion = std::stoi(strSeleccion);
          }
        } while (seleccion < 1 || seleccion >= indice);

        // Recuperar la asignación seleccionada
        Nodo<Asignacion *> *nodoSel = asignacionesProfesor.getCabeza();
        for (int i = 1; i < seleccion; i++) {
          nodoSel = nodoSel->getSiguiente();
        }
        Asignacion *asigSeleccionada = nodoSel->getDato();

        // Validación de Fecha
        std::string fecha;
        do {
          std::cout << "Ingrese la fecha de la clase (DD/MM/2026): ";
          std::getline(std::cin, fecha);
          if (!Validador::validarFecha(fecha)) {
            std::cout << "Fecha invalida. Formato requerido: DD/MM/2026.\n";
          }
        } while (!Validador::validarFecha(fecha));

        // Extraer Día y Mes de la cadena "DD/MM/2026"
        int diaIngresado = std::stoi(fecha.substr(0, 2));
        int mesIngresado = std::stoi(fecha.substr(3, 2));

        // Obtener el nombre del día para la fecha en 2026
        std::string diaSemana = Validador::obtenerNombreDia2026(diaIngresado, mesIngresado);
        std::string esquemaDias = asigSeleccionada->getDias(); // "L-M-V" o "M-J"

        // Validar si el día de la semana coincide con el horario asignado
        bool diaValido = false;
        if (esquemaDias == "L-M-V" && (diaSemana == "Lunes" || diaSemana == "Miercoles" || diaSemana == "Viernes")) {
          diaValido = true;
        } else if (esquemaDias == "M-J" && (diaSemana == "Martes" || diaSemana == "Jueves")) {
          diaValido = true;
        }

        if (!diaValido) {
          std::cout << "\nLa fecha " << fecha << " cae un dia " << diaSemana << ".\n";
          std::cout << "Esta clase esta programada unicamente para los dias (" << esquemaDias << ").\n";
          break;
        }

        // Verificar si ya existe registro para esa Asignación y esa Fecha
        Nodo<RegistroClase> *actualReg = listaRegistros.getCabeza();
        RegistroClase *registroExistente = nullptr;

        while (actualReg != nullptr) {
          if (actualReg->getDato().getAsignacion() == *asigSeleccionada &&
              actualReg->getDato().getFecha() == fecha) {
            registroExistente = &(actualReg->getDato());
            break;
          }
          actualReg = actualReg->getSiguiente();
        }

        if (registroExistente != nullptr) {
          if (registroExistente->getEstado() == EN_CURSO) {
            std::cout
                << "Ya existe un inicio de sesion activo para esta "
                   "fecha.\n";
            break;
          } else if (registroExistente->getEstado() == FINALIZADA) {
            std::cout << "La clase para el dia " << fecha
                      << " en la aula " << asigSeleccionada->getAula()
                      << " ya fue FINALIZADA.\n";
            break;
          }
        }

        //Captura de Hora y Minutos 
        std::string strHora, strMinutos;
        int h = -1, m = -1;

        do {
          std::cout << "Ingrese Hora de entrada (0 - 23): ";
          std::getline(std::cin, strHora);
          if (Validador::soloNumeros(strHora))
            h = std::stoi(strHora);
        } while (h < 0 || h > 23);

        do {
          std::cout << "Ingrese Minuto de entrada (0 - 59): ";
          std::getline(std::cin, strMinutos);
          if (Validador::soloNumeros(strMinutos))
            m = std::stoi(strMinutos);
        } while (m < 0 || m > 59);

        // Extraer hora de inicio
        int horaInicioBloque =
            std::stoi(asigSeleccionada->getHorario().substr(0, 2));

        
        // horaInicio
        int minutosIngresadosTotales = h * 60 + m;
        int minutosInicioPermitido = horaInicioBloque * 60;
        int minutosFinPermitido = horaInicioBloque * 60 + 10;

        if (minutosIngresadosTotales < minutosInicioPermitido ||
            minutosIngresadosTotales > minutosFinPermitido) {
          std::cout << "\nFuera del tiempo permitido.\n";
          std::cout << "El horario de ingreso permitido para el bloque "
                    << asigSeleccionada->getHorario() << " es estrictamente de "
                    << horaInicioBloque << ":00 a " << horaInicioBloque
                    << ":10.\n";
          break;
        }

        // Crear el registro de clase 
        if (registroExistente == nullptr) {
          RegistroClase nuevoReg(*asigSeleccionada, fecha);
          listaRegistros.insertarFinal(nuevoReg);
          registroExistente = &(listaRegistros.getCola()->getDato());
        }

        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%02d:%02d", h, m);
        registroExistente->registrarEntrada(std::string(buffer));

        std::cout << "\nEntrada registrada correctamente a las "
                  << buffer << " para la fecha " << fecha << ".\n";
        break;
      }

      case '2': { 
        std::cout << "\nRegistro de Salida\n";
        if (listaRegistros.estaVacia()) {
          std::cout << "No hay clases en curso\n";
          break;
        }

        std::string cedula;
        std::cout << "Ingrese Cedula del profesor: ";
        std::getline(std::cin, cedula);

        // Registros en estado EN_CURSO 
        Nodo<RegistroClase> *actualReg = listaRegistros.getCabeza();
        ListaDoble<RegistroClase *> registrosEnCurso;

        while (actualReg != nullptr) {
          if (actualReg->getDato().getAsignacion().getProfesor().getCedula() ==
                  cedula &&
              actualReg->getDato().getEstado() == EN_CURSO) {
            registrosEnCurso.insertarFinal(&(actualReg->getDato()));
          }
          actualReg = actualReg->getSiguiente();
        }

        if (registrosEnCurso.estaVacia()) {
          std::cout
              << "No se encontraron clases EN CURSO iniciadas por "
                 "la cedula ingresada.\n";
          break;
        }

        std::cout << "\nClases activas en curso:\n";
        Nodo<RegistroClase *> *nodoReg = registrosEnCurso.getCabeza();
        int idx = 1;
        while (nodoReg != nullptr) {
          RegistroClase *regPtr = nodoReg->getDato();
          std::cout << idx << ". Fecha: " << regPtr->getFecha()
                    << " | Aula: " << regPtr->getAsignacion().getAula()
                    << " | Entrada: " << regPtr->getHoraEntrada() << "\n";
          nodoReg = nodoReg->getSiguiente();
          idx++;
        }

        std::string strSel;
        int sel = 0;
        do {
          std::cout << "Seleccione la clase a desloguear: ";
          std::getline(std::cin, strSel);
          if (Validador::soloNumeros(strSel))
            sel = std::stoi(strSel);
        } while (sel < 1 || sel >= idx);

        Nodo<RegistroClase *> *nodoSelReg = registrosEnCurso.getCabeza();
        for (int i = 1; i < sel; i++) {
          nodoSelReg = nodoSelReg->getSiguiente();
        }
        RegistroClase *regSeleccionado = nodoSelReg->getDato();

        // Captura de Hora y Minutos de Salida
        std::string strHora, strMinutos;
        int h = -1, m = -1;

        do {
          std::cout << "Ingrese Hora de salida (0 - 23): ";
          std::getline(std::cin, strHora);
          if (Validador::soloNumeros(strHora))
            h = std::stoi(strHora);
        } while (h < 0 || h > 23);

        do {
          std::cout << "Ingrese Minuto de salida (0 - 59): ";
          std::getline(std::cin, strMinutos);
          if (Validador::soloNumeros(strMinutos))
            m = std::stoi(strMinutos);
        } while (m < 0 || m > 59);

        // Validar que la hora de salida s
        int minEntrada =
            std::stoi(regSeleccionado->getHoraEntrada().substr(0, 2)) * 60 +
            std::stoi(regSeleccionado->getHoraEntrada().substr(3, 2));
        int minSalida = h * 60 + m;

        if (minSalida < minEntrada) {
          std::cout << "\nLa hora de salida (" << h << ":" << m
                    << ") no coincide ("
                    << regSeleccionado->getHoraEntrada() << ").\n";
          break;
        }
        std::string horarioStr = regSeleccionado->getAsignacion().getHorario();
        int horaFinOficial = std::stoi(horarioStr.substr(6, 2));
        int minFinOficial = horaFinOficial * 60;

     
        if (minSalida > minFinOficial) {
          regSeleccionado->setObservaciones("ENTRADA A TIEMPO | SALIDA TARDE");
        } else {
          regSeleccionado->setObservaciones(
              "ENTRADA A TIEMPO | SALIDA A TIEMPO");
        }

        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%02d:%02d", h, m);
        regSeleccionado->registrarSalida(std::string(buffer));

        std::cout << "\nSalida registrada a las " << buffer
                  << ". Clase FINALIZADA.\n";
        break;
      }

      case '3':
        std::cout << "Regresando al menu principal...\n";
        break;

      default:
        std::cout << "Opcion no valida.\n";
        break;
      }

    } while (opcion != '3');
  }