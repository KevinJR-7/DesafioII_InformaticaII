
/**
 * @file main.cpp
 * @author Benjamin Ruiz y Kevin Jimenez
 * @brief 
 * @version 0.1
 * @date 2025-05-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include "sistema.h"  
#include "interfaz.h" 
int main() {
    Huesped* huespedLogueado = nullptr; 
    Anfitrion* anfitrionLogueado = nullptr; 
    short int opcionPrincipal = 0;
    cargarDatos(); 
    

    do {
        std::cout << "\n========= UdeAStay Plataforma =========" << std::endl;
        std::cout << "1. Iniciar Sesion como Huesped" << std::endl;
        std::cout << "2. Iniciar Sesion como Anfitrión" << std::endl;
        std::cout << "0. Salir del Sistema" << std::endl;
        opcionPrincipal = leerEntradaInt("Seleccione una opcion: ");


        switch (opcionPrincipal) {
            case 1:
                huespedLogueado = iniciarSesionHuesped();  
                if (huespedLogueado) {
                    menuHuesped(huespedLogueado); 

                }
                break;
            case 2:
                anfitrionLogueado = iniciarSesionAnfitrion(); 
                if (anfitrionLogueado) {
                    menuAnfitrion(anfitrionLogueado); 
                }
                break;
            case 0:
                std::cout << "Saliendo del sistema UdeAStay..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
                
        }
    } while (opcionPrincipal != 0);

    guardarDatos(); 

    std::cout << "Gracias por usar UdeAStay. ¡Hasta pronto!" << std::endl;
    return 0;
}
