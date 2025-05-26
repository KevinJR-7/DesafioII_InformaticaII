#include <iostream> // Para cout, endl, etc.
#include "huesped.h" // Incluye la definición e implementación de tu clase Huesped

using namespace std; // Usamos el espacio de nombres std

int main() {
    cout << "--- PRUEBA DE LA CLASE HUESPED ---" << endl;

    // 1. Prueba del Constructor por defecto
    cout << "\n--- Probando Constructor por Defecto ---" << endl;
    Huesped huesped1; // Se llama al constructor por defecto
    cout << "Valores iniciales de Huesped 1:" << endl;
    cout << "  ID: '" << huesped1.getId() << "'" << endl;
    cout << "  Antiguedad: " << huesped1.getAntiguedad() << " dias" << endl;
    cout << "  Puntuacion: " << huesped1.getPuntuacion() << endl;
    cout << "  Reservas: ";
    const unsigned short* reservas1 = huesped1.getReservas();
    // Imprimimos solo las primeras reservas no nulas para no saturar la salida
    for (int i = 0; i < 365; ++i) {
        if (reservas1[i] == 0) { // Asumimos 0 como terminador o valor por defecto
            break;
        }
        cout << reservas1[i] << " ";
    }
    cout << endl;

    // 2. Prueba de los Setters
    cout << "\n--- Probando Setters en Huesped 1 ---" << endl;
    huesped1.setId("GuestTester123"); // Se truncará a 15 caracteres + null
    huesped1.setAntiguedad(150);
    huesped1.setPuntuacion(88);

    unsigned short listaReservas[] = {101, 205, 310, 425, 0}; // 0 como terminador
    huesped1.setReservas(listaReservas);

    cout << "Valores de Huesped 1 despues de usar setters:" << endl;
    cout << "  ID: '" << huesped1.getId() << "'" << endl;
    cout << "  Antiguedad: " << huesped1.getAntiguedad() << " dias" << endl;
    cout << "  Puntuacion: " << huesped1.getPuntuacion() << endl;
    cout << "  Reservas: ";
    const unsigned short* reservas1_updated = huesped1.getReservas();
    for (int i = 0; i < 365; ++i) {
        if (reservas1_updated[i] == 0) {
            break;
        }
        cout << reservas1_updated[i] << " ";
    }
    cout << endl;

    // Probar ID más corto para asegurar el rellenado con '\0'
    huesped1.setId("Dave");
    cout << "\nHuesped 1 con ID mas corto: '" << huesped1.getId() << "'" << endl;

    // Probar setReservas con una lista más grande (hasta el límite del array)
    unsigned short listaReservas2[365];
    for (int i = 0; i < 365; ++i) {
        listaReservas2[i] = i + 1; // Llenar con 1, 2, ..., 365
    }
    huesped1.setReservas(listaReservas2);
    cout << "Huesped 1 con 365 reservas (primeras 5): ";
    const unsigned short* reservas1_full = huesped1.getReservas();
    for (int i = 0; i < 365; ++i) { // Solo imprimimos las primeras para no saturar
        cout << reservas1_full[i] << " ";
    }
    cout << endl;


    // 3. Prueba del Constructor de Copia
    cout << "\n--- Probando Constructor de Copia ---" << endl;
    Huesped huesped2 = huesped1; // Se llama al constructor de copia
    cout << "Valores de Huesped 2 (copia de Huesped 1):" << endl;
    cout << "  ID: '" << huesped2.getId() << "'" << endl;
    cout << "  Antiguedad: " << huesped2.getAntiguedad() << " dias" << endl;
    cout << "  Puntuacion: " << huesped2.getPuntuacion() << endl;
    cout << "  Reservas: ";
    const unsigned short* reservas2 = huesped2.getReservas();
    for (int i = 0; i < 365; ++i) {
        if (reservas2[i] == 0) {
            break;
        }
        cout << reservas2[i] << " ";
    }
    cout << endl;

    // Modificar huesped1 para demostrar que huesped2 es una copia independiente (Deep Copy)
    huesped1.setId("NewGuestID");
    huesped1.setAntiguedad(300);
    unsigned short listaReservas3[] = {900, 901, 0};
    huesped1.setReservas(listaReservas3);

    cout << "\nModificando Huesped 1 (ID, antiguedad y reservas) para verificar la copia profunda:" << endl;
    cout << "Huesped 1 ahora:" << endl;
    cout << "  ID: '" << huesped1.getId() << "'" << endl;
    cout << "  Antiguedad: " << huesped1.getAntiguedad() << " dias" << endl;
    cout << "  Reservas: ";
    const unsigned short* reservas1_modified = huesped1.getReservas();
    for (int i = 0; i < 365; ++i) {
        if (reservas1_modified[i] == 0) {
            break;
        }
        cout << reservas1_modified[i] << " ";
    }
    cout << endl;

    cout << "Huesped 2 (deberia seguir con los valores originales de la copia):" << endl;
    cout << "  ID: '" << huesped2.getId() << "'" << endl;
    cout << "  Antiguedad: " << huesped2.getAntiguedad() << " dias" << endl;
    cout << "  Reservas: ";
    for (int i = 0; i < 365; ++i) {
        if (reservas2[i] == 0) {
            break;
        }
        cout << reservas2[i] << " ";
    }
    cout << endl;

    // 4. Prueba del Destructor (se llamará automáticamente al finalizar main)
    cout << "\n--- Probando Destructor ---" << endl;
    cout << "Los destructores de huesped1 y huesped2 se llamaran automaticamente al salir de main." << endl;
    cout << "Si hay problemas de memoria (como 'double free' o 'memory leak'), un depurador lo indicara." << endl;

    cout << "\n--- Fin de la prueba de la clase Huesped ---" << endl;

    return 0;
}
