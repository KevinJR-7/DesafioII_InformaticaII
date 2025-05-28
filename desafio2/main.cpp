

/////////// MAIN MENU TESTING AREA ///////////
// Voy a tratar de ir haciendo el menú principal, eso que usted tiene me da toc
// luego vemos que tanto lo podemos simplificar o mejorar
// Quiero crear otro archivo puede ser interface.cpp o menu.cpp y condensar todo allí
#include <iostream>
#include "sistema.h"  // Para cargarDatos, guardarDatos, iniciarSesionHuesped, iniciarSesionAnfitrion, etc.
#include "interfaz.h" // Para los menús de Huesped y Anfitrión
int main() {
    cargarDatos(); // Funcionalidad I (No debe verla el usuario, solo se carga al inicio)
                    //Hay que crearla
    int opcionPrincipal;
    Huesped* huespedLogueado = nullptr; // Inicializar como nullptr
    Anfitrion* anfitrionLogueado = nullptr; // Inicializar como nullptr

    do {
        std::cout << "\n========= UdeAStay Plataforma =========" << std::endl;
        std::cout << "1. Iniciar Sesión como Huésped" << std::endl;
        std::cout << "2. Iniciar Sesión como Anfitrión" << std::endl;
        std::cout << "0. Salir del Sistema" << std::endl;
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
                std::cout << "Saliendo del sistema UdeAStay..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                
        }
    } while (opcionPrincipal != 0);

    guardarDatos(); // Funcionalidad I (Hay que crearla)
                    // Guardar los datos antes de salir del sistema

    std::cout << "Gracias por usar UdeAStay. ¡Hasta pronto!" << std::endl;
    return 0;
}
