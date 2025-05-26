#include <iostream>

// Incluir todas las cabeceras necesarias
#include "administrador.h" // Contiene Administrador
#include "anfitrion.h"     // Contiene Anfitrion
#include "alojamiento.h"   // Contiene Alojamiento
#include "reserva.h"       // Contiene Reserva

// --- Constantes para tamaños (se asumen de las clases .h) ---
const unsigned short MAX_ANFITRIONES = 2000; // De Administrador::anfitriones
const unsigned short ID_ANFITRION_SIZE = 16; // De Anfitrion::id
const unsigned short NOMBRE_SIZE = 100;      // De Alojamiento::nombre
const unsigned short EMAIL_SIZE = 50;        // Asumido para Anfitrion::email (no en tu snippet, pero común)
const unsigned short MAX_ALOJAMIENTOS_ANFITRION = 50; // De Anfitrion::alojamientos (asumido)

// --- Funciones Auxiliares para Imprimir (sin cstring) ---

// Imprime un array de char de tamaño fijo, asumiendo terminación nula o tamaño máximo
void imprimirCharArray(const char* arr, unsigned short size) {
    if (arr == nullptr) {
        std::cout << "[nullptr]";
        return;
    }
    for (unsigned short i = 0; i < size; ++i) {
        if (arr[i] == '\0') { // Se detiene si encuentra un terminador nulo
            break;
        }
        std::cout << arr[i];
    }
}

// Imprime detalles de una Reserva (repetido del test de Alojamiento para referencia)
void imprimirReserva(const Reserva* r, const char* prefix = "") {
    if (r == nullptr) {
        std::cout << prefix << "Reserva: nullptr\n";
        return;
    }
    std::cout << prefix << "Reserva en direccion: " << r << std::endl;
    std::cout << prefix << "  Codigo: " << r->getCodigo() << std::endl;
    std::cout << prefix << "  Huesped: ";
    imprimirCharArray(r->getIdHuesped(), 16); // Asumiendo tamaño 16 para huesped
    std::cout << std::endl;
    std::cout << prefix << "  Num Noches: " << r->getNumNoches() << std::endl;
}

// Imprime las reservas de un Alojamiento (adaptado del test de Alojamiento)
void imprimirReservasAlojamiento(const Alojamiento* a, const char* titulo) {
    if (a == nullptr) {
        std::cout << "\n--- " << titulo << " (Alojamiento nulo) ---\n";
        return;
    }
    std::cout << "\n--- " << titulo << " ---\n";
    std::cout << "  ID Alojamiento: " << a->getId() << std::endl;
    const Reserva* const* reservas = a->getReservas();
    bool hayReservas = false;
    for (unsigned short i = 0; i < 365; ++i) { // Tamaño fijo 365 de Alojamiento::reservas
        if (reservas[i] != nullptr) {
            hayReservas = true;
            std::cout << "    reservas[" << i << "]: ";
            imprimirReserva(reservas[i], "      ");
        }
    }
    if (!hayReservas) {
        std::cout << "    No hay reservas activas en este alojamiento.\n";
    }
    std::cout << "---------------------\n";
}

// Imprime detalles de un Alojamiento (para Anfitrion)
void imprimirAlojamiento(const Alojamiento* al, const char* prefix = "  ") {
    if (al == nullptr) {
        std::cout << prefix << "Alojamiento: nullptr\n";
        return;
    }
    std::cout << prefix << "Alojamiento en direccion: " << al << std::endl;
    std::cout << prefix << "  ID: " << al->getId() << std::endl;
    std::cout << prefix << "  Nombre: "; imprimirCharArray(al->getNombre(), NOMBRE_SIZE); std::cout << std::endl;
    // Puedes añadir más detalles si lo deseas
    imprimirReservasAlojamiento(al, "Reservas del Alojamiento anterior"); // Muestra sus reservas
}

// Imprime detalles de un Anfitrion
void imprimirAnfitrion(const Anfitrion* a, const char* prefix = "  ") {
    if (a == nullptr) {
        std::cout << prefix << "Anfitrion: nullptr\n";
        return;
    }
    std::cout << prefix << "Anfitrion en direccion: " << a << std::endl;
    std::cout << prefix << "  ID: "; imprimirCharArray(a->getId(), ID_ANFITRION_SIZE); std::cout << std::endl;
    std::cout << prefix << "  Antiguedad: " << a->getAntiguedad() << " meses" << std::endl;
    std::cout << prefix << "  Puntuacion: " << a->getPuntuacion() << std::endl;

    // Asumiendo que getAlojamientos() devuelve un puntero al inicio del array de alojamientos
    const Alojamiento* alojamientosAnfitrion = a->getAlojamientos();
    if (alojamientosAnfitrion != nullptr) {
        std::cout << prefix << "  Alojamientos gestionados por este Anfitrion:\n";
        bool hayAlojamientos = false;
        // Tendrías que tener una forma de saber cuántos alojamientos tiene el Anfitrion
        // o si es un array de tamaño fijo (como 50), iterar sobre ese tamaño.
        // Asumo 50 por la descripción de tu clase.
        for (unsigned short i = 0; i < MAX_ALOJAMIENTOS_ANFITRION; ++i) {
            // Se asume que Alojamiento::setAlojamientos copia por valor (profunda)
            // entonces aqui necesitamos el Alojamiento *en esa posicion* del array
            // si solo apunta a uno, esta logica de array no aplica.
            // Dada tu definicion `Alojamiento* alojamientos;` en Anfitrion,
            // la interpretacion mas comun es que es un solo Alojamiento o el inicio de un array.
            // Para probar, asumiremos que es el inicio de un array de MAX_ALOJAMIENTOS_ANFITRION.
            // Si es un solo Alojamiento, solo imprimiríamos 'alojamientosAnfitrion'.
            if ((alojamientosAnfitrion + i) != nullptr && (alojamientosAnfitrion + i)->getId() != 0) { // Check for valid Alojamiento (non-zero ID as a simple heuristic)
                hayAlojamientos = true;
                std::cout << prefix << "    Alojamiento[" << i << "]:\n";
                imprimirAlojamiento((alojamientosAnfitrion + i), prefix);
            }
        }
        if (!hayAlojamientos) {
            std::cout << prefix << "    Ningun alojamiento valido listado.\n";
        }
    } else {
        std::cout << prefix << "  No hay alojamientos asociados a este Anfitrion.\n";
    }
}

// Imprime los anfitriones gestionados por el Administrador
void imprimirAnfitrionesAdministrador(const Administrador& admin, const char* titulo) {
    std::cout << "\n--- " << titulo << " ---\n";
    std::cout << "Indice actual del Administrador: " << admin.getIndice() << std::endl;
    const Anfitrion* const* anfitriones = admin.getAnfitriones();
    bool hayAnfitriones = false;
    // Iteramos hasta el 'indice' actual para ver los Anfitriones que se han añadido.
    for (unsigned short i = 0; i < admin.getIndice(); ++i) {
        if (anfitriones[i] != nullptr) {
            hayAnfitriones = true;
            std::cout << "  anfitriones[" << i << "]:\n";
            imprimirAnfitrion(anfitriones[i], "    "); // Usa la función de impresión de Anfitrion
        }
    }
    if (!hayAnfitriones) {
        std::cout << "  No hay anfitriones activos en este Administrador.\n";
    }
    std::cout << "---------------------\n";
}

int main() {
    std::cout << "--- Prueba de la clase Administrador ---\n";

    // 1. Crear una instancia de Administrador
    std::cout << "\n1. Creando Administrador:\n";
    Administrador gestorGlobal;
    imprimirAnfitrionesAdministrador(gestorGlobal, "Administrador recien creado");

    // 2. Crear algunos objetos Anfitrion de prueba
    std::cout << "\n2. Creando objetos Anfitrion originales:\n";
    Anfitrion* anf1 = new Anfitrion();
    char id1[ID_ANFITRION_SIZE] = {'A', 'N', 'F', '0', '0', '1', '\0'};
    anf1->setId(id1);
    anf1->setAntiguedad(12);
    anf1->setPuntuacion(45);
    // Para setAlojamientos, necesitarías pasar un array de Alojamiento.
    // Aquí solo crearemos un Alojamiento de prueba para asociar.
    Alojamiento* alj1_anf1 = new Alojamiento();
    alj1_anf1->setId(101);
    char alj1_nombre[NOMBRE_SIZE] = {'P', 'e', 'q', 'u', 'e', 'n', 'o', ' ', 'A', 'p', 'a', 'r', 't', 'a', 'm', 'e', 'n', 't', 'o', '\0'};
    alj1_anf1->setNombre(alj1_nombre);
    // Asignar el Alojamiento al Anfitrion (se espera una copia profunda en Anfitrion::setAlojamientos)
    Alojamiento tempAlojamientos1[MAX_ALOJAMIENTOS_ANFITRION]; // Array temporal para pasar
    tempAlojamientos1[0] = *alj1_anf1; // Copia el objeto Alojamiento (llama al constructor de copia de Alojamiento)
    anf1->setAlojamientos(tempAlojamientos1); // Pasa el array

    imprimirAnfitrion(anf1, "  ");

    Anfitrion* anf2 = new Anfitrion();
    char id2[ID_ANFITRION_SIZE] = {'A', 'N', 'F', '0', '0', '2', '\0'};
    anf2->setId(id2);
    anf2->setAntiguedad(24);
    anf2->setPuntuacion(50);
    imprimirAnfitrion(anf2, "  ");

    Anfitrion* anf3 = new Anfitrion();
    char id3[ID_ANFITRION_SIZE] = {'A', 'N', 'F', '1', '0', '0', '\0'}; // ID para buscar
    anf3->setId(id3);
    anf3->setAntiguedad(6);
    anf3->setPuntuacion(30);
    imprimirAnfitrion(anf3, "  ");

    // 3. Añadir Anfitriones al Administrador usando addObject
    std::cout << "\n3. Anadiendo Anfitriones al Administrador:\n";
    gestorGlobal.addObject(anf1);
    gestorGlobal.addObject(anf2);
    gestorGlobal.addObject(anf3);
    imprimirAnfitrionesAdministrador(gestorGlobal, "Administrador despues de addObject");

    // 4. Probar la búsqueda de Anfitriones usando searchObject
    std::cout << "\n4. Probando searchObject:\n";
    char idBuscado1[ID_ANFITRION_SIZE] = {'A', 'N', 'F', '0', '0', '2', '\0'};
    std::cout << "  Buscando Anfitrion con ID 'ANF002':\n";
    Anfitrion* encontrado1 = gestorGlobal.searchObject(idBuscado1);
    imprimirAnfitrion(encontrado1, "    ");
    if (encontrado1 != nullptr && encontrado1 == anf2) {
        std::cout << "    -> Busqueda exitosa (Anfitrion esperado).\n";
    } else {
        std::cout << "    -> ERROR en busqueda (Anfitrion no encontrado o incorrecto).\n";
    }

    char idBuscado2[ID_ANFITRION_SIZE] = {'A', 'N', 'F', '1', '0', '0', '\0'}; // ID que existe
    std::cout << "  Buscando Anfitrion con ID 'ANF100':\n";
    Anfitrion* encontrado2 = gestorGlobal.searchObject(idBuscado2);
    imprimirAnfitrion(encontrado2, "    ");
    if (encontrado2 != nullptr && encontrado2 == anf3) {
        std::cout << "    -> Busqueda exitosa (Anfitrion esperado).\n";
    } else {
        std::cout << "    -> ERROR en busqueda (Anfitrion no encontrado o incorrecto).\n";
    }

    char idNoExistente[ID_ANFITRION_SIZE] = {'X', 'Y', 'Z', '0', '0', '0', '\0'}; // ID que no existe
    std::cout << "  Buscando Anfitrion con ID 'XYZ000' (no existente):\n";
    Anfitrion* noEncontrado = gestorGlobal.searchObject(idNoExistente);
    imprimirAnfitrion(noEncontrado, "    ");
    if (noEncontrado == nullptr) {
        std::cout << "    -> Busqueda exitosa (Anfitrion no encontrado, como se esperaba).\n";
    } else {
        std::cout << "    -> ERROR en busqueda (Anfitrion inesperadamente encontrado).\n";
    }

    // 5. Probar el constructor de copia de Administrador
    std::cout << "\n5. Probando constructor de copia de Administrador:\n";
    Administrador gestorCopia = gestorGlobal; // Llama al constructor de copia
    imprimirAnfitrionesAdministrador(gestorCopia, "Administrador Copia");

    // Verificar que los punteros en la copia apuntan a los mismos Anfitriones
    std::cout << "\n6. Verificando que los punteros apuntan a los mismos Anfitriones:\n";
    std::cout << "  Direccion anf1: " << anf1 << std::endl;
    std::cout << "  Direccion gestorGlobal.getAnfitriones()[0]: " << gestorGlobal.getAnfitriones()[0] << std::endl;
    std::cout << "  Direccion gestorCopia.getAnfitriones()[0]: " << gestorCopia.getAnfitriones()[0] << std::endl;

    // Modificar un Anfitrion original y ver si se refleja en ambos Administradores
    std::cout << "\n7. Modificando anf1 (original) y observando cambios:\n";
    anf1->setAntiguedad(36); // Cambiar una propiedad
    imprimirAnfitrion(anf1, "  anf1 modificado: ");

    imprimirAnfitrionesAdministrador(gestorGlobal, "Administrador Original despues de modificar anf1");
    imprimirAnfitrionesAdministrador(gestorCopia, "Administrador Copia despues de modificar anf1");

    // 8. Liberar la memoria de los Alojamiento* creados para los Anfitriones (si los creó en main)
    // ESTO ES CRÍTICO: Si Anfitrion::setAlojamientos HACE COPIA PROFUNDA,
    // entonces los 'alj1_anf1' creados aquí son independientes de los que el Anfitrion contiene.
    // Debes liberarlos aquí.
    delete alj1_anf1;
    alj1_anf1 = nullptr;

    // 9. ¡¡¡Peligro!!! Liberar los objetos Anfitrion originales.
    // Esto ilustra el problema de los punteros colgantes si los Administradores no poseen los Anfitriones.
    std::cout << "\n10. !!! DANGER: Liberando los objetos Anfitrion originales !!!\n";
    std::cout << "    Despues de esto, los punteros en Administrador seran punteros colgantes.\n";
    delete anf1; anf1 = nullptr;
    delete anf2; anf2 = nullptr;
    delete anf3; anf3 = nullptr;

    // No intentamos acceder a los objetos Anfitrion a través de gestorGlobal o gestorCopia
    // después de liberarlos para evitar un crash.

    std::cout << "\n11. Destruyendo objetos Administrador (sus destructores se llaman automaticamente).\n";
    // Cuando 'gestorGlobal' y 'gestorCopia' salgan del scope, sus destructores se llamarán.
    // Tus destructores SÓLO liberan el array de punteros, NO los objetos Anfitrion,
    // lo cual es consistente con la copia superficial de punteros.

    std::cout << "\n--- Fin de la prueba ---\n";

    return 0;
}
