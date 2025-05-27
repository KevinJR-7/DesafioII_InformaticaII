#include <iostream> // Solo iostream para entrada/salida de consola

// Incluye tus archivos de cabecera
#include "reserva.h"
#include "alojamiento.h"
#include "anfitrion.h"
#include "administrador.h" // Necesaria para el arreglo de Anfitriones
#include "huesped.h"

// --- FUNCIONES AUXILIARES PRIMITIVAS SIN STL ---

// Función para copiar una cadena C (char[])
void copiarCadena(char* destino, const char* origen, unsigned short tamMax) {
    unsigned short i = 0;
    while (i < tamMax - 1 && origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0'; // Asegurar terminador nulo
}

// --- PROGRAMA PRINCIPAL DE PRUEBA ---

int main() {
    std::cout << "--- PRUEBA PRIMITIVA DE HUESPED::ANULARRESERVA (Todos los huespedes reales) ---" << std::endl;

    // 1. Crear todos los Huespedes y asignarles sus propias reservas.
    // Cada huesped es el dueño de sus propias copias profundas de Reserva.
    std::cout << "\nCreando Huespedes (HuespedA, HuespedB, HuespedD) y asignando sus reservas..." << std::endl;

    // Huesped A
    Huesped huespedA;
    huespedA.setId("HuespedA");
    huespedA.setAntiguedad(2);
    huespedA.setPuntuacion(5);

    Reserva reservas_huespedA_temp[365];
    for (int i = 0; i < 365; ++i) { reservas_huespedA_temp[i] = Reserva(); }

    reservas_huespedA_temp[0].setCodigo(101);
    reservas_huespedA_temp[0].setIdAlojamiento(100);
    reservas_huespedA_temp[0].setIdHuesped("HuespedA");
    reservas_huespedA_temp[0].setFechaInicio(20250715);
    reservas_huespedA_temp[0].setNumNoches(3);
    reservas_huespedA_temp[0].setPrecio(300);
    reservas_huespedA_temp[0].setMetodoPago(true);

    reservas_huespedA_temp[1].setCodigo(103);
    reservas_huespedA_temp[1].setIdAlojamiento(100);
    reservas_huespedA_temp[1].setIdHuesped("HuespedA");
    reservas_huespedA_temp[1].setFechaInicio(20250910);
    reservas_huespedA_temp[1].setNumNoches(2);
    reservas_huespedA_temp[1].setPrecio(200);
    reservas_huespedA_temp[1].setMetodoPago(true);
    huespedA.setReservas(reservas_huespedA_temp); // HuespedA hace copias profundas

    // Huesped B
    Huesped huespedB;
    huespedB.setId("HuespedB");
    huespedB.setAntiguedad(1);
    huespedB.setPuntuacion(4);

    Reserva reservas_huespedB_temp[365];
    for (int i = 0; i < 365; ++i) { reservas_huespedB_temp[i] = Reserva(); }

    reservas_huespedB_temp[0].setCodigo(102);
    reservas_huespedB_temp[0].setIdAlojamiento(100);
    reservas_huespedB_temp[0].setIdHuesped("HuespedB");
    reservas_huespedB_temp[0].setFechaInicio(20250820);
    reservas_huespedB_temp[0].setNumNoches(5);
    reservas_huespedB_temp[0].setPrecio(500);
    reservas_huespedB_temp[0].setMetodoPago(false);
    huespedB.setReservas(reservas_huespedB_temp); // HuespedB hace copias profundas

    // Huesped D (para la reserva pasada)
    Huesped huespedD;
    huespedD.setId("HuespedD");
    huespedD.setAntiguedad(3);
    huespedD.setPuntuacion(3);

    Reserva reservas_huespedD_temp[365];
    for (int i = 0; i < 365; ++i) { reservas_huespedD_temp[i] = Reserva(); }

    reservas_huespedD_temp[0].setCodigo(104);
    reservas_huespedD_temp[0].setIdAlojamiento(100);
    reservas_huespedD_temp[0].setIdHuesped("HuespedD");
    reservas_huespedD_temp[0].setFechaInicio(20241225); // Fecha pasada
    reservas_huespedD_temp[0].setNumNoches(7);
    reservas_huespedD_temp[0].setPrecio(700);
    reservas_huespedD_temp[0].setMetodoPago(true);
    huespedD.setReservas(reservas_huespedD_temp); // HuespedD hace copias profundas

    // 2. Crear un Alojamiento y hacer que sus punteros apunten a las reservas de los Huespedes reales
    std::cout << "\nCreando un alojamiento (ID 100) y asignando punteros a las reservas de los huespedes reales..." << std::endl;
    Alojamiento alj1;
    alj1.setId(100);
    alj1.setNombre("Casa junto al mar");
    alj1.setAnfitrion("AnfitrionX");

    Reserva* reservas_alojamiento_ptrs[365]; // Este arreglo local contiene los punteros
    for (int i = 0; i < 365; ++i) { reservas_alojamiento_ptrs[i] = nullptr; }

    // Obtenemos los punteros a las *instancias concretas* de Reserva dentro de cada Huesped
    Reserva* huespedA_reservas_internas = huespedA.getReservas();
    Reserva* huespedB_reservas_internas = huespedB.getReservas();
    Reserva* huespedD_reservas_internas = huespedD.getReservas();

    // Asignamos punteros en el Alojamiento a las reservas de los Huespedes.
    reservas_alojamiento_ptrs[0] = &huespedA_reservas_internas[0]; // Reserva 101 de HuespedA
    reservas_alojamiento_ptrs[1] = &huespedB_reservas_internas[0]; // Reserva 102 de HuespedB
    reservas_alojamiento_ptrs[2] = &huespedA_reservas_internas[1]; // Reserva 103 de HuespedA
    reservas_alojamiento_ptrs[3] = &huespedD_reservas_internas[0]; // Reserva 104 de HuespedD (pasada)

    alj1.setReservas(reservas_alojamiento_ptrs); // Alojamiento copia estos punteros a su arreglo interno

    // 3. Crear un Anfitrion y asignarle el Alojamiento (SOLO UNA VEZ)
    std::cout << "\nCreando un anfitrion (AnfitrionX) y asignando alojamiento (una sola vez)..." << std::endl;
    Anfitrion anfitrion1;
    anfitrion1.setId("AnfitrionX");
    anfitrion1.setAntiguedad(5);
    anfitrion1.setPuntuacion(4);

    Alojamiento alojamientos_anfitrion[50]; // Este arreglo local contiene los Alojamiento
    for(int i = 0; i < 50; ++i) { alojamientos_anfitrion[i] = Alojamiento(); }
    alojamientos_anfitrion[0] = alj1; // alj1 (ya configurado) se copia aquí
    anfitrion1.setAlojamientos(alojamientos_anfitrion); // <--- SOLO SE LLAMA UNA VEZ

    // 4. Crear un arreglo de Anfitriones para pasar a Huesped::anularReserva
    Anfitrion* anfitriones_global_arr[2000];
    for(int i = 0; i < 2000; ++i) { anfitriones_global_arr[i] = nullptr; }
    anfitriones_global_arr[0] = &anfitrion1; // El Huesped recibe punteros a Anfitrion.


    // --- INICIO DE LA PRUEBA DE HUESPED::ANULARRESERVA ---

    std::cout << "\n--- Probando Huesped::anularReserva con HuespedA ---" << std::endl;

    std::cout << "\nMostrando reservas del huesped 'HuespedA' antes de anular:" << std::endl;
    unsigned short cnt_huesped_reservas = 0;
    for(unsigned short k = 0; k < 365; ++k) {
        if(huespedA.getReservas()[k].getCodigo() != 0) {
            cnt_huesped_reservas++;
            std::cout << cnt_huesped_reservas << ". Reserva Codigo: " << huespedA.getReservas()[k].getCodigo()
                      << ", Alojamiento ID: " << huespedA.getReservas()[k].getIdAlojamiento()
                      << ", Fecha Inicio: " << huespedA.getReservas()[k].getFechaInicio() << std::endl;
        }
    }
    if (cnt_huesped_reservas == 0) {
        std::cout << "El huesped no tiene reservas activas." << std::endl;
    }

    std::cout << "\nMostrando todas las reservas del Alojamiento (ID 100) del Anfitrion antes de anular:" << std::endl;
    unsigned short cnt_anfitrion_reservas_antes = 0;
    // Debemos acceder al alojamiento a través del anfitrion. Accedemos a la copia interna del Anfitrion.
    Alojamiento* anfitrion_alojamientos_ptr = anfitrion1.getAlojamientos();
    Alojamiento& current_alj_in_anfitrion = anfitrion_alojamientos_ptr[0];

    for(unsigned short k = 0; k < 365; ++k) {
        if(current_alj_in_anfitrion.getReservas()[k] != nullptr) {
            cnt_anfitrion_reservas_antes++;
            std::cout << cnt_anfitrion_reservas_antes << ". Reserva Codigo: " << current_alj_in_anfitrion.getReservas()[k]->getCodigo()
                      << ", Alojamiento ID: " << current_alj_in_anfitrion.getReservas()[k]->getIdAlojamiento()
                      << ", Huesped ID: " << current_alj_in_anfitrion.getReservas()[k]->getIdHuesped()
                      << ", Fecha Inicio: " << current_alj_in_anfitrion.getReservas()[k]->getFechaInicio() << std::endl;
        }
    }
    if (cnt_anfitrion_reservas_antes == 0) {
        std::cout << "El alojamiento del anfitrion no tiene reservas activas." << std::endl;
    }


    std::cout << "\nAhora llamando a huespedA.anularReserva(). Se le pedira un numero." << std::endl;
    std::cout << "(Intenta anular la reserva 101 o 103 de HuespedA)" << std::endl;
    short resultado_anulacion = huespedA.anularReserva(anfitriones_global_arr);

    if (resultado_anulacion == 0) {
        std::cout << "\nAnulacion de reserva exitosa." << std::endl;
    } else if (resultado_anulacion == -1) {
        std::cout << "\nError: No se encontraron reservas activas para mostrar o no hay anfitriones validos." << std::endl;
    } else if (resultado_anulacion == -2) {
        std::cout << "\nError: No se encontro la reserva en el anfitrion para anular. Posiblemente no apunta a la misma instancia." << std::endl;
    } else {
        std::cout << "\nError desconocido al anular reserva (codigo: " << resultado_anulacion << ")." << std::endl;
    }

    // Mostrar el estado final de las reservas del huesped que anulo
    std::cout << "\n--- Estado final de las reservas del huesped 'HuespedA' ---" << std::endl;
    cnt_huesped_reservas = 0;
    for(unsigned short k = 0; k < 365; ++k) {
        if(huespedA.getReservas()[k].getCodigo() != 0) {
            cnt_huesped_reservas++;
            std::cout << cnt_huesped_reservas << ". Reserva Codigo: " << huespedA.getReservas()[k].getCodigo()
                      << ", Alojamiento ID: " << huespedA.getReservas()[k].getIdAlojamiento()
                      << ", Fecha Inicio: " << huespedA.getReservas()[k].getFechaInicio() << std::endl;
        }
    }
    if (cnt_huesped_reservas == 0) {
        std::cout << "El huesped no tiene reservas activas despues de la anulacion." << std::endl;
    }

    // Mostrar el estado final de las reservas del alojamiento del anfitrion
    std::cout << "\n--- Estado final de las reservas del Alojamiento (ID 100) del Anfitrion ---" << std::endl;
    // Debemos re-obtener la referencia al alojamiento a través del anfitrion, ya que es su copia interna.
    Alojamiento* final_anfitrion_alojamientos_ptr = anfitrion1.getAlojamientos();
    Alojamiento& final_current_alj_in_anfitrion = final_anfitrion_alojamientos_ptr[0];

    unsigned short cnt_anfitrion_reservas_final = 0;
    for(unsigned short k = 0; k < 365; ++k) {
        // La condición para mostrar es que el puntero no sea nullptr Y que el código de la reserva no sea 0
        if(final_current_alj_in_anfitrion.getReservas()[k] != nullptr && final_current_alj_in_anfitrion.getReservas()[k]->getCodigo() != 0) {
            cnt_anfitrion_reservas_final++;
            std::cout << cnt_anfitrion_reservas_final << ". Reserva Codigo: " << final_current_alj_in_anfitrion.getReservas()[k]->getCodigo()
                      << ", Alojamiento ID: " << final_current_alj_in_anfitrion.getReservas()[k]->getIdAlojamiento()
                      << ", Huesped ID: " << final_current_alj_in_anfitrion.getReservas()[k]->getIdHuesped()
                      << ", Fecha Inicio: " << final_current_alj_in_anfitrion.getReservas()[k]->getFechaInicio() << std::endl;
        }
    }
    if (cnt_anfitrion_reservas_final == 0) {
        std::cout << "El alojamiento del anfitrion no tiene reservas activas despues de la anulacion." << std::endl;
    }


    // --- GESTIÓN MANUAL DE MEMORIA ---
    std::cout << "\n--- La memoria de las Reservas es gestionada por sus respectivos Huespedes ---" << std::endl;
    // No hay objetos Reserva creados con 'new' en este main. Todos los Huespedes son objetos automáticos.
    // Los destructores de Huesped (huespedA, huespedB, huespedD) liberarán sus propias copias profundas de Reserva.
    // Los destructores de Alojamiento y Anfitrion se encargarán de sus propios recursos.
    // Nada que liberar manualmente aquí.

    std::cout << "\nFin de la prueba." << std::endl;

    return 0;
}
