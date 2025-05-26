#include <iostream> // Para cout, endl, etc.
#include "anfitrion.h" // Incluye la definición e implementación de tu clase Anfitrion

using namespace std; // Usamos el espacio de nombres std

int main() {
    cout << "--- PRUEBA DE LA CLASE ANFITRION ---" << endl;

    // 1. Prueba del Constructor por defecto
    cout << "\n--- Probando Constructor por Defecto ---" << endl;
    Anfitrion anfitrion1; // Se llama al constructor por defecto
    cout << "Valores iniciales de Anfitrion 1:" << endl;
    cout << "  ID: '" << anfitrion1.getId() << "'" << endl;
    cout << "  Antiguedad: " << anfitrion1.getAntiguedad() << " años" << endl;
    cout << "  Puntuacion: " << anfitrion1.getPuntuacion() << endl;
    cout << "  Alojamientos: ";
    const unsigned short* alojamientos1 = anfitrion1.getAlojamientos();
    for (int i = 0; i < 50; ++i) {
        if (alojamientos1[i] == 0) { // Asumimos 0 como terminador o valor por defecto
            break;
        }
        cout << alojamientos1[i] << " ";
    }
    cout << endl;

    // 2. Prueba de los Setters
    cout << "\n--- Probando Setters en Anfitrion 1 ---" << endl;
    anfitrion1.setId("AnfitrionTest12"); // Se truncará a 15 caracteres + null
    anfitrion1.setAntiguedad(5);
    anfitrion1.setPuntuacion(95);

    unsigned short listaAlojamientos[] = {1, 5, 10, 25, 0}; // 0 como terminador
    anfitrion1.setAlojamientos(listaAlojamientos);

    cout << "Valores de Anfitrion 1 despues de usar setters:" << endl;
    cout << "  ID: '" << anfitrion1.getId() << "'" << endl;
    cout << "  Antiguedad: " << anfitrion1.getAntiguedad() << " años" << endl;
    cout << "  Puntuacion: " << anfitrion1.getPuntuacion() << endl;
    cout << "  Alojamientos: ";
    const unsigned short* alojamientos1_updated = anfitrion1.getAlojamientos();
    for (int i = 0; i < 50; ++i) {
        if (alojamientos1_updated[i] == 0) {
            break;
        }
        cout << alojamientos1_updated[i] << " ";
    }
    cout << endl;

    // Probar ID más corto para asegurar el rellenado con '\0'
    anfitrion1.setId("Bob");
    cout << "\nAnfitrion 1 con ID mas corto: '" << anfitrion1.getId() << "'" << endl;

    // Probar setAlojamientos con una lista más grande
    unsigned short listaAlojamientos2[50];
    for (unsigned short i = 0; i < 49; i++) {
        listaAlojamientos2[i] = i + 1; // Llenar con 1, 2, ..., 50
    }
    listaAlojamientos2[49] = 0;

    cout << "Prueba: ";
    for (int i = 0; i < 50; ++i) { // Solo imprimimos los primeros para no saturar
        cout << listaAlojamientos2[i] << " ";
    }
    cout << endl;

    anfitrion1.setAlojamientos(listaAlojamientos2);
    cout << "Anfitrion 1 con 50 alojamientos (primeros 5): ";
    const unsigned short* alojamientos1_full = anfitrion1.getAlojamientos();
    for (int i = 0; i < 50; ++i) { // Solo imprimimos los primeros para no saturar
        cout << alojamientos1_full[i] << " ";
    }
    cout << endl;


    // 3. Prueba del Constructor de Copia
    cout << "\n--- Probando Constructor de Copia ---" << endl;
    Anfitrion anfitrion2 = anfitrion1; // Se llama al constructor de copia
    cout << "Valores de Anfitrion 2 (copia de Anfitrion 1):" << endl;
    cout << "  ID: '" << anfitrion2.getId() << "'" << endl;
    cout << "  Antiguedad: " << anfitrion2.getAntiguedad() << " años" << endl;
    cout << "  Puntuacion: " << anfitrion2.getPuntuacion() << endl;
    cout << "  Alojamientos: ";
    const unsigned short* alojamientos2 = anfitrion2.getAlojamientos();
    for (int i = 0; i < 50; ++i) {
        if (alojamientos2[i] == 0) {
            break;
        }
        cout << alojamientos2[i] << " ";
    }
    cout << endl;

    // Modificar anfitrion1 para demostrar que anfitrion2 es una copia independiente (Deep Copy)
    anfitrion1.setId("HostModified");
    anfitrion1.setAntiguedad(10);
    unsigned short listaAlojamientos3[] = {100, 200, 0};
    anfitrion1.setAlojamientos(listaAlojamientos3);

    cout << "\nModificando Anfitrion 1 (ID, antiguedad y alojamientos) para verificar la copia profunda:" << endl;
    cout << "Anfitrion 1 ahora:" << endl;
    cout << "  ID: '" << anfitrion1.getId() << "'" << endl;
    cout << "  Antiguedad: " << anfitrion1.getAntiguedad() << " años" << endl;
    cout << "  Alojamientos: ";
    const unsigned short* alojamientos1_modified = anfitrion1.getAlojamientos();
    for (int i = 0; i < 50; ++i) {
        if (alojamientos1_modified[i] == 0) {
            break;
        }
        cout << alojamientos1_modified[i] << " ";
    }
    cout << endl;

    cout << "Anfitrion 2 (deberia seguir con los valores originales de la copia):" << endl;
    cout << "  ID: '" << anfitrion2.getId() << "'" << endl;
    cout << "  Antiguedad: " << anfitrion2.getAntiguedad() << " años" << endl;
    cout << "  Alojamientos: ";
    for (int i = 0; i < 50; ++i) {
        if (alojamientos2[i] == 0) {
            break;
        }
        cout << alojamientos2[i] << " ";
    }
    cout << endl;

    // 4. Prueba del Destructor (se llamará automáticamente al finalizar main)
    cout << "\n--- Probando Destructor ---" << endl;
    cout << "Los destructores de anfitrion1 y anfitrion2 se llamaran automaticamente al salir de main." << endl;
    cout << "Si hay problemas de memoria (como 'double free' o 'memory leak'), un depurador lo indicara." << endl;

    cout << "\n--- Fin de la prueba de la clase Anfitrion ---" << endl;

    return 0;
}
