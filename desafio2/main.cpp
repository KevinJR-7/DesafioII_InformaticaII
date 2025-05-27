// #include <iostream>

// // Incluir todas las cabeceras necesarias para las clases
// #include "reserva.h"
// #include "alojamiento.h"
// #include "anfitrion.h" // La clase principal a probar

// // --- Constantes para tamaños (se asumen de las clases .h) ---
// const unsigned short ID_ANFITRION_SIZE = 16;
// const unsigned short NOMBRE_ALOJAMIENTO_SIZE = 100;
// const unsigned short MAX_ALOJAMIENTOS_ANFITRION = 50; // De Anfitrion::alojamientos
// const unsigned short MAX_RESERVAS_ALOJAMIENTO = 365; // De Alojamiento::reservas
// const unsigned short ID_HUESPED_SIZE = 16; // De Reserva::huesped

// // --- Funciones Auxiliares de Impresión (sin cstring.h) ---

// // Imprime un array de char de tamaño fijo, asumiendo terminación nula o tamaño máximo
// void imprimirCharArray(const char* arr, unsigned short size) {
//     if (arr == nullptr) {
//         std::cout << "[nullptr]";
//         return;
//     }
//     for (unsigned short i = 0; i < size; ++i) {
//         if (arr[i] == '\0') {
//             break;
//         }
//         std::cout << arr[i];
//     }
// }

// // Imprime una fecha (formato YYYYMMDD)
// void imprimirFecha(unsigned int fecha) {
//     unsigned int anio = fecha / 10000;
//     unsigned int mes = (fecha / 100) % 100;
//     unsigned int dia = fecha % 100;
//     std::cout << anio;
//     if (mes < 10) std::cout << "0";
//     std::cout << mes;
//     if (dia < 10) std::cout << "0";
//     std::cout << dia;
// }

// // Imprime detalles de una Reserva (usado por consultarReservas)
// void mostrarReserva(const Reserva* r, const char* prefix = "") {
//     if (r == nullptr) {
//         std::cout << prefix << "Reserva: nullptr\n";
//         return;
//     }
//     std::cout << prefix << "Codigo: " << r->getCodigo();
//     std::cout << ", Alojamiento ID: " << r->getIdAlojamiento();
//     std::cout << ", Huesped ID: "; imprimirCharArray(r->getIdHuesped(), ID_HUESPED_SIZE);
//     std::cout << ", Fecha Inicio: "; imprimirFecha(r->getFechaInicio());
//     std::cout << ", Noches: " << r->getNumNoches();
//     std::cout << ", Precio: " << r->getPrecio();
//     std::cout << std;
// }

// // --- MAIN para probar Anfitrion::consultarReservas() ---
// int main() {
//     std::cout << "--- Prueba de Anfitrion::consultarReservas() ---\n\n";

//     // 1. Crear un Anfitrion de prueba
//     Anfitrion anfitrionPrueba;
//     char idAnfitrion[ID_ANFITRION_SIZE] = {'A', 'N', 'F', '0', '0', '7', '\0'};
//     anfitrionPrueba.setId(idAnfitrion);
//     anfitrionPrueba.setAntiguedad(36);
//     anfitrionPrueba.setPuntuacion(48);
//     std::cout << "Anfitrion de prueba creado con ID: ";
//     imprimirCharArray(anfitrionPrueba.getId(), ID_ANFITRION_SIZE);
//     std::cout << std;

//     // 2. Crear objetos Alojamiento y Reservas para el Anfitrion
//     // Necesitamos un array temporal de Alojamientos para pasar a Anfitrion::setAlojamientos
//     // Alojamiento tempAlojamientos[MAX_ALOJAMIENTOS_ANFITRION];

//     // // --- Alojamiento 1 ---
//     // Alojamiento alj1;
//     // alj1.setId(101);
//     // char nombreAlj1[NOMBRE_ALOJAMIENTO_SIZE] = {'C', 'a', 's', 'a', ' ', 'P', 'l', 'a', 'y', 'a', '\0'};
//     // alj1.setNombre(nombreAlj1);

//     // // Crear Reservas para Alojamiento 1
//     // // Reserva* reservasAlj1[MAX_RESERVAS_ALOJAMIENTO];
//     // // for (unsigned short i = 0; i < MAX_RESERVAS_ALOJAMIENTO; ++i) {
//     // //     reservasAlj1[i] = nullptr; // Inicializar a nullptr
//     // // }

//     // // // Reserva 1.1 (dentro del rango)
//     // // Reserva* res1_1 = new Reserva();
//     // // res1_1->setCodigo(1001);
//     // // res1_1->setIdAlojamiento(101);
//     // // res1_1->setFechaInicio(20250715); // 15 de Julio de 2025
//     // // res1_1->setNumNoches(5);
//     // // char huesped1_1[ID_HUESPED_SIZE] = {'H', 'U', 'E', 'S', 'P', '0', '1', '\0'}; res1_1->setIdHuesped(huesped1_1);
//     // // reservasAlj1[0] = res1_1;

//     // // // Reserva 1.2 (fuera del rango - muy temprana)
//     // // Reserva* res1_2 = new Reserva();
//     // // res1_2->setCodigo(1002);
//     // // res1_2->setIdAlojamiento(101);
//     // // res1_2->setFechaInicio(20250101); // 01 de Enero de 2025
//     // // res1_2->setNumNoches(7);
//     // // char huesped1_2[ID_HUESPED_SIZE] = {'H', 'U', 'E', 'S', 'P', '0', '2', '\0'}; res1_2->setIdHuesped(huesped1_2);
//     // // reservasAlj1[1] = res1_2;

//     // // // Reserva 1.3 (dentro del rango)
//     // // Reserva* res1_3 = new Reserva();
//     // // res1_3->setCodigo(1003);
//     // // res1_3->setIdAlojamiento(101);
//     // // res1_3->setFechaInicio(20250820); // 20 de Agosto de 2025
//     // // res1_3->setNumNoches(3);
//     // // char huesped1_3[ID_HUESPED_SIZE] = {'H', 'U', 'E', 'S', 'P', '0', '3', '\0'}; res1_3->setIdHuesped(huesped1_3);
//     // // reservasAlj1[2] = res1_3;

//     // // // Reserva 1.4 (fuera del rango - muy tardía)
//     // // Reserva* res1_4 = new Reserva();
//     // // res1_4->setCodigo(1004);
//     // // res1_4->setIdAlojamiento(101);
//     // // res1_4->setFechaInicio(20260101); // 01 de Enero de 2026
//     // // res1_4->setNumNoches(10);
//     // // char huesped1_4[ID_HUESPED_SIZE] = {'H', 'U', 'E', 'S', 'P', '0', '4', '\0'}; res1_4->setIdHuesped(huesped1_4);
//     // // reservasAlj1[3] = res1_4;

//     // // alj1.setReservas(reservasAlj1); // Asignar el array de punteros a Reservas al Alojamiento

//     // // Asignar Alojamiento 1 al array temporal para Anfitrion
//     // tempAlojamientos[0] = alj1; // Llama al operador de asignación de Alojamiento (copia profunda de sus miembros de char*, pero superficial de Reserva**)

//     // // --- Alojamiento 2 ---
//     // Alojamiento alj2;
//     // alj2.setId(202);
//     // char nombreAlj2[NOMBRE_ALOJAMIENTO_SIZE] = {'C', 'a', 'b', 'a', 'n', 'a', ' ', 'M', 'o', 'n', 't', 'a', 'n', 'a', '\0'};
//     // alj2.setNombre(nombreAlj2);

//     // Reserva* reservasAlj2[MAX_RESERVAS_ALOJAMIENTO];
//     // for (unsigned short i = 0; i < MAX_RESERVAS_ALOJAMIENTO; ++i) {
//     //     reservasAlj2[i] = nullptr;
//     // }

//     // // Reserva 2.1 (dentro del rango)
//     // Reserva* res2_1 = new Reserva();
//     // res2_1->setCodigo(2001);
//     // res2_1->setIdAlojamiento(202);
//     // res2_1->setFechaInicio(20250910); // 10 de Septiembre de 2025
//     // res2_1->setNumNoches(2);
//     // char huesped2_1[ID_HUESPED_SIZE] = {'H', 'U', 'E', 'S', 'P', '0', '5', '\0'}; res2_1->setIdHuesped(huesped2_1);
//     // reservasAlj2[0] = res2_1;

//     // alj2.setReservas(reservasAlj2);
//     // tempAlojamientos[1] = alj2; // Asignar Alojamiento 2

//     // // Finalizar el array de alojamientos con un Alojamiento "nulo" (ID 0)
//     // // tal como se espera en Anfitrion::setAlojamientos y Anfitrion::consultarReservas
//     // Alojamiento nuloAlj; // Su constructor ya pone id=0
//     // tempAlojamientos[2] = nuloAlj; // Copia el Alojamiento con ID 0

//     // anfitrionPrueba.setAlojamientos(tempAlojamientos);

//     std::cout << "\nAnfitrion de prueba configurado con 2 alojamientos y varias reservas.\n";
//     std::cout << "--------------------------------------------------------\n";

//     // 3. Probar consultarReservas() con diferentes rangos de fechas
//     unsigned int fecha_inicio_busqueda, fecha_fin_busqueda;
//     unsigned short num_reservas_encontradas;

//     std::cout << "\n--- Prueba 1: Rango que incluye varias reservas ---\n";
//     fecha_inicio_busqueda = 20250701; // 1 de Julio de 2025
//     fecha_fin_busqueda = 20251001;   // 1 de Octubre de 2025 (exclusiva)
//     std::cout << "Buscando reservas entre "; imprimirFecha(fecha_inicio_busqueda);
//     std::cout << " y "; imprimirFecha(fecha_fin_busqueda); std::cout << std;

//     num_reservas_encontradas = anfitrionPrueba.consultarReservas(fecha_inicio_busqueda, fecha_fin_busqueda);

//     if (num_reservas_encontradas == 0) {
//         std::cout << "  Resultado: 0 reservas encontradas (OK)\n";
//     } else if (num_reservas_encontradas == 1) {
//         std::cout << "  Resultado: Error de estado, se esperaba un conteo de reservas.\n";
//     } else if (num_reservas_encontradas == 2) {
//         std::cout << "  Resultado: No hay reservas activas en este anfitrion (ERROR - si esperamos reservas).\n";
//     } else {
//         std::cout << "  Numero de reservas encontradas: " << num_reservas_encontradas << std;
//         std::cout << "  (Las reservas se imprimen dentro del metodo consultarReservas)\n";
//     }

//     std::cout << "\n--- Prueba 2: Rango sin reservas ---\n";
//     fecha_inicio_busqueda = 20250401; // 1 de Abril de 2025
//     fecha_fin_busqueda = 20250501;   // 1 de Mayo de 2025
//     std::cout << "Buscando reservas entre "; imprimirFecha(fecha_inicio_busqueda);
//     std::cout << " y "; imprimirFecha(fecha_fin_busqueda); std::cout << std;

//     num_reservas_encontradas = anfitrionPrueba.consultarReservas(fecha_inicio_busqueda, fecha_fin_busqueda);

//     if (num_reservas_encontradas == 0) {
//         std::cout << "  Resultado: " << 0 << " reservas encontradas. Esto esta bien si la funcion retorna 0 para exito.\n";
//         // Si tu funcion devuelve 2 para "no hay reservas", entonces este es el resultado esperado.
//     } else if (num_reservas_encontradas == 1) {
//         std::cout << "  Resultado: Error de estado (retorno 1).\n";
//     } else if (num_reservas_encontradas == 2) {
//         std::cout << "  Resultado: No hay reservas en el rango (OK).\n";
//     } else {
//         std::cout << "  Numero de reservas encontradas: " << num_reservas_encontradas << std;
//     }

//     std::cout << "\n--- Prueba 3: Rango con una sola reserva --- \n";
//     fecha_inicio_busqueda = 20250911; // 1 de Septiembre de 2025
//     fecha_fin_busqueda = 20250915;   // 15 de Septiembre de 2025
//     std::cout << "Buscando reservas entre "; imprimirFecha(fecha_inicio_busqueda);
//     std::cout << " y "; imprimirFecha(fecha_fin_busqueda); std::cout << std;

//     num_reservas_encontradas = anfitrionPrueba.consultarReservas(fecha_inicio_busqueda, fecha_fin_busqueda);

//     if (num_reservas_encontradas == 0) {
//         std::cout << "  Resultado: " << 0 << " reservas encontradas. Esto esta bien si la funcion retorna 0 para exito.\n";
//         // Si tu funcion devuelve 2 para "no hay reservas", entonces este es el resultado esperado.
//     } else if (num_reservas_encontradas == 1) {
//         std::cout << "  Resultado: Error de estado (retorno 1).\n";
//     } else if (num_reservas_encontradas == 2) {
//         std::cout << "  Resultado: No hay reservas en el rango (ERROR - si esperamos reservas).\n";
//     } else {
//         std::cout << "  Numero de reservas encontradas: " << num_reservas_encontradas << std;
//     }


//     // 4. Liberar la memoria de los objetos creados manualmente
//     std::cout << "\n--- Limpieza de memoria ---\n";
//     // Liberar las Reservas creadas manualmente para alj1
//     // delete res1_1; res1_1 = nullptr;
//     // delete res1_2; res1_2 = nullptr;
//     // delete res1_3; res1_3 = nullptr;
//     // delete res1_4; res1_4 = nullptr;

//     // Liberar las Reservas creadas manualmente para alj2
//     // delete res2_1; res2_1 = nullptr;

//     // Los objetos Alojamiento (alj1, alj2) se copiaron en anfitrionPrueba.setAlojamientos
//     // por lo tanto, no necesitamos eliminarlos aquí, a menos que se hayan creado con new
//     // Si 'alj1' y 'alj2' fueran punteros new Alojamiento(), necesitaríamos eliminarlos aquí.
//     // Como son objetos en el stack, se destruirán automáticamente.

//     std::cout << "\n--- Fin de la prueba ---\n";

//     return 0;
// }



/////////// MAIN MENU TESTING AREA ///////////
// Voy a tratar de ir haciendo el menú principal, eso que usted tiene me da toc
// luego vemos que tanto lo podemos simplificar o mejorar
// Quiero crear otro archivo puede ser interface.cpp o menu.cpp y condensar todo allí

using namespace std;
int main() {
    cargarDatos(); // Funcionalidad I (No debe verla el usuario, solo se carga al inicio)
                    //Hay que crearla
    int opcionPrincipal;
    do {
        cout << "\n========= UdeAStay Plataforma =========" << std;
        cout << "1. Iniciar Sesión como Huésped" << std;
        cout << "2. Iniciar Sesión como Anfitrión" << std;
        cout << "0. Salir del Sistema" << std;
        opcionPrincipal = leerEntradaInt("Seleccione una opción: ");


        switch (opcionPrincipal) {
            case 1:
                huespedLogueado = iniciarSesionHuesped();  // Hay que crear esta función
                // iniciarSesionHuesped() debe retornar un objeto Huesped o nullptr
                if (huespedLogueado) {
                    menuHuesped(huespedLogueado); // Hay que crear esta función

                }
                break;
            case 2:
                anfitrionLogueado = iniciarSesionAnfitrion(); // Hay que crear esta función
                // iniciarSesionAnfitrion() debe retornar un objeto Anfitrion o nullptr
                if (anfitrionLogueado) { 
                    menuAnfitrion(anfitrionLogueado); // Hay que crear esta función
                }
                break;
            case 0:
                std::cout << "Saliendo del sistema UdeAStay..." << std;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std;
                // Mostrar medición de recursos incluso para opción inválida si se desea
                // iteracionesGlobales = 1; // Por la comparación de la opción
                // mostrarMedicionRecursos();
        }
    } while (opcionPrincipal != 0);

    guardarDatos(); // Funcionalidad I (Hay que crearla)
                    // Guardar los datos antes de salir del sistema

    std::cout << "Gracias por usar UdeAStay. ¡Hasta pronto!" << std;
    return 0;
}