#include "interfaz.h"
#include "sistema.h"       
#include "alojamiento.h"   
#include "reserva.h"       
#include <iostream>

// --- Implementaciones de Funcionalidades del Menú ---

void reservarAlojamiento(Huesped* huespedActual) {
    std::cout << "\n--- Reservar Alojamiento ---" << std::endl;
    

    }
    


void anularReservacion(Huesped* huespedActual, Anfitrion* anfitrionActual) {
    std::cout << "\n--- Anular Reservación ---" << std::endl;

    // Falta código para Anular Reservación
}

void consultarReservacionesAnfitrion(Anfitrion* anfitrionActual) {
    std::cout << "\n--- Consultar Reservaciones (Anfitrión) ---" << std::endl;
    // Falta código para Consultar Reservaciones
}

void actualizarHistorico(Anfitrion* anfitrionActual) {
    std::cout << "\n--- Actualizar Histórico (Anfitrión) ---" << std::endl;
    // Falta código para Actualizar Histórico
}

// --- Implementaciones de Menús Específicos por Rol ---
void menuHuesped(Huesped* huespedActual) {
    short int opcion;
    do {
        std::cout << "\n--- Menú Huésped (" << huespedActual->getId() << ") ---" << std::endl;
        std::cout << "1. Reservar Alojamiento" << std::endl;
        std::cout << "2. Anular Reservación Propia" << std::endl;
        std::cout << "0. Cerrar Sesión" << std::endl;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                reservarAlojamiento(huespedActual);
                break;
            case 2:
                anularReservacion(huespedActual, nullptr);
                break;
            case 0:
                std::cout << "Cerrando sesión de huésped..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 0);
}

void menuAnfitrion(Anfitrion* anfitrionActual) {
    int opcion;
    do {
        std::cout << "\n--- Menú Anfitrión (" << anfitrionActual->getId() << ") ---" << std::endl;
        std::cout << "1. Anular Reservación (de sus alojamientos)" << std::endl;
        std::cout << "2. Consultar Reservaciones" << std::endl;
        std::cout << "3. Actualizar Histórico de Reservas" << std::endl;
        std::cout << "0. Cerrar Sesión" << std::endl;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;


        switch (opcion) {
            case 1:
                anularReservacion(nullptr, anfitrionActual);
                break;
            case 2:
                consultarReservacionesAnfitrion(anfitrionActual);
                break;
            case 3:
                actualizarHistorico(anfitrionActual);
                break;
            case 0:
                std::cout << "Cerrando sesión de anfitrión..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 0);
}