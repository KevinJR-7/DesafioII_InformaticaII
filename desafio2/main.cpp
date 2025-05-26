#include <iostream>
#include "alojamiento.h" // Asumiendo alojamiento.h en el mismo directorio
#include "reserva.h"     // Asumiendo reserva.h en el mismo directorio

// Función para imprimir detalles de una reserva (para facilitar la visualización)
void imprimirReserva(const Reserva* r, const char* prefix = "") {
    if (r == nullptr) {
        std::cout << prefix << "Reserva: nullptr\n";
        return;
    }
    std::cout << prefix << "Reserva en dirección: " << r << std::endl;
    std::cout << prefix << "  Codigo: " << r->getCodigo() << std::endl;
    std::cout << prefix << "  Huesped: ";
    const char* huesped = r->getIdHuesped();
    for (unsigned short i = 0; i < 16 && huesped[i] != '\0'; ++i) {
        std::cout << huesped[i];
    }
    std::cout << std::endl;
    std::cout << prefix << "  Num Noches: " << r->getNumNoches() << std::endl;
}

// Función para imprimir las reservas de un Alojamiento
void imprimirReservasAlojamiento(const Alojamiento& a, const char* titulo) {
    std::cout << "\n--- " << titulo << " ---\n";
    std::cout << "ID Alojamiento: " << a.getId() << std::endl;
    const Reserva* const* reservas = a.getReservas();
    bool hayReservas = false;
    for (unsigned short i = 0; i < 365; ++i) {
        if (reservas[i] != nullptr) {
            hayReservas = true;
            std::cout << "  reservas[" << i << "]: ";
            imprimirReserva(reservas[i], "    ");
        }
    }
    if (!hayReservas) {
        std::cout << "  No hay reservas activas en este alojamiento.\n";
    }
    std::cout << "---------------------\n";
}

int main() {
    std::cout << "--- Prueba de Alojamiento y Reservas (Copia Superficial) ---\n";

    // 1. Crear algunas instancias de Reserva
    std::cout << "\n1. Creando objetos Reserva originales:\n";
    Reserva* r1 = new Reserva();
    r1->setCodigo(101);
    char huesped1[16] = {'J', 'u', 'a', 'n', '\0'};
    r1->setIdHuesped(huesped1);
    r1->setNumNoches(5);
    imprimirReserva(r1, "  ");

    Reserva* r2 = new Reserva();
    r2->setCodigo(102);
    char huesped2[16] = {'M', 'a', 'r', 'i', 'a', '\0'};
    r2->setIdHuesped(huesped2);
    r2->setNumNoches(3);
    imprimirReserva(r2, "  ");

    Reserva* r3 = new Reserva();
    r3->setCodigo(103);
    char huesped3[16] = {'P', 'e', 'd', 'r', 'o', '\0'};
    r3->setIdHuesped(huesped3);
    r3->setNumNoches(7);
    imprimirReserva(r3, "  ");

    Reserva* r4 = new Reserva();
    r4->setCodigo(104);
    char huesped4[16] = {'L', 'a', 'u', 'r', 'a', '\0'};
    r4->setIdHuesped(huesped4);
    r4->setNumNoches(2);
    imprimirReserva(r4, "  ");

    // 2. Crear un array de punteros a Reserva para pasar a Alojamiento
    // Este array simula el origen de tus reservas.
    // Los punteros nullptr marcan el fin de las reservas "útiles" en este contexto.
    Reserva* misReservasParaSet[365] = {nullptr};
    misReservasParaSet[0] = r1;
    misReservasParaSet[1] = r2;
    misReservasParaSet[5] = r3; // Saltar algunas posiciones
    misReservasParaSet[300] = r4; // Otra posición distante
    // misReservasParaSet[2] = nullptr; // Si hubiera un nullptr intermedio, setReservas se frenaría allí.

    // 3. Crear una instancia de Alojamiento y asignarle las reservas
    std::cout << "\n2. Creando Alojamiento y asignando reservas (copia superficial):\n";
    Alojamiento albergue;
    albergue.setId(1);
    char nombreAlbergue[100] = {'C', 'a', 's', 'a', ' ', 'd', 'e', 'l', ' ', 'S', 'o', 'l', '\0'};
    albergue.setNombre(nombreAlbergue);
    // Ahora setReservas ya no toma 'cantidad', se asume que usa el tamaño fijo 365
    // y se detiene en el primer nullptr, como tu implementación indica.
    albergue.setReservas(misReservasParaSet);
    imprimirReservasAlojamiento(albergue, "Reservas en Albergue Original");

    // 4. Probar el constructor de copia de Alojamiento
    std::cout << "\n3. Probando constructor de copia de Alojamiento (copia superficial de punteros):\n";
    Alojamiento albergueCopia = albergue; // Llama al constructor de copia
    char nombreAlbergueCopia[100] = {'C', 'o', 'p', 'i', 'a', ' ', 'd', 'e', 'l', ' ', 'A', 'l', 'b', 'e', 'r', 'g', 'u', 'e', '\0'};
    albergueCopia.setNombre(nombreAlbergueCopia); // Cambiar un atributo que no sea reserva
    imprimirReservasAlojamiento(albergueCopia, "Reservas en Albergue Copia");

    // Observar que las direcciones de los objetos Reserva son las mismas
    std::cout << "\n4. Verificando que los punteros apuntan a las mismas Reservas:\n";
    std::cout << "  Direccion r1: " << r1 << std::endl;
    std::cout << "  Direccion albergue.getReservas()[0]: " << albergue.getReservas()[0] << std::endl;
    std::cout << "  Direccion albergueCopia.getReservas()[0]: " << albergueCopia.getReservas()[0] << std::endl;

    // 5. Modificar un objeto Reserva original y ver si se refleja en ambos Alojamientos
    std::cout << "\n5. Modificando r1 (original) y observando cambios en ambos alojamientos:\n";
    r1->setNumNoches(10); // Modificamos r1
    char nuevoHuesped1[16] = {'A', 'n', 'a', '\0'};
    r1->setIdHuesped(nuevoHuesped1);
    imprimirReserva(r1, "  r1 modificado: ");

    imprimirReservasAlojamiento(albergue, "Albergue Original despues de modificar r1");
    imprimirReservasAlojamiento(albergueCopia, "Albergue Copia despues de modificar r1");

    // ¡¡¡Peligro!!! Liberar los objetos Reserva originales
    // Esto ilustra el problema de los punteros colgantes si los Alojamientos no poseen las Reservas.
    std::cout << "\n6. !!! DANGER: Liberando los objetos Reserva originales !!!\n";
    std::cout << "   Despues de esto, los punteros en Alojamiento seran punteros colgantes.\n";
    delete r1;
    delete r2;
    delete r3;
    delete r4;
    r1 = nullptr; r2 = nullptr; r3 = nullptr; r4 = nullptr;

    // Intentar acceder a ellos ahora resultaría en comportamiento indefinido.
    // No accederemos a ellos para evitar un crash inmediato en la demostración.

    std::cout << "\n7. Destruyendo objetos Alojamiento (sus destructores se llaman automaticamente).\n";
    // Cuando 'albergue' y 'albergueCopia' salgan del scope, sus destructores se llamarán.
    // Tus destructores SÓLO liberan el array de punteros, NO los objetos Reserva,
    // lo cual es consistente con la copia superficial.

    std::cout << "\n--- Fin de la prueba ---\n";

    return 0;
}
