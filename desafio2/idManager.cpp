#include "idManager.h"
#include <iostream>

unsigned int generarCodigoReserva()
{
    static unsigned int code = 0;
    code++;
    return code;
}

unsigned int fechaFinal(unsigned int fecha_i, unsigned short num_noches)
{
    unsigned int fecha_f;
    unsigned int anio = fecha_i / 10000;
    unsigned int mes = (fecha_i / 100) % 100;
    unsigned int dia = fecha_i % 100;

    // Días en cada mes (sin considerar años bisiestos)
    unsigned int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Ajustar febrero si es año bisiesto
    if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){ diasPorMes[2] = 29; }

    dia += num_noches;
    while(dia > diasPorMes[mes])
    {
        dia -= diasPorMes[mes];
        mes++;

        if(mes > 12)
        {
            mes = 1;
            anio++;
            // Reajustar febrero si el nuevo año es bisiesto
            diasPorMes[2] = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0) ? 29 : 28;
        }
    }

    fecha_f = (anio * 10000) + (mes * 100) + dia;
    return fecha_f;
}

// ---
// ## Función principal para imprimir la fecha
// Recibe un entero sin signo en formato AAAAMMDD e imprime la fecha formateada.
// ---
void imprimirFechaFormatoExtendido(unsigned int fecha_AAAAMMDD) {
    // Extraer los componentes de la fecha: año, mes y día
    unsigned short anio = fecha_AAAAMMDD / 10000;
    unsigned short mes = (fecha_AAAAMMDD / 100) % 100;
    unsigned short dia = fecha_AAAAMMDD % 100;

    // Obtener el índice numérico del día de la semana (0=Domingo, 1=Lunes, ...)
    unsigned short dia_semana_idx = calcularDiaDeLaSemana(dia, mes, anio);

    // Arreglos de nombres para los días de la semana y los meses
    const char* dias_semana[] = {
        "Domingo", "Lunes", "Martes", "Miércoles",
        "Jueves", "Viernes", "Sábado"
    };

    const char* nombres_meses[] = {
        "", // El índice 0 no se usa para que el índice del arreglo coincida con el número del mes (1-12)
        "Enero", "Febrero", "Marzo", "Abril",
        "Mayo", "Junio", "Julio", "Agosto",
        "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    // Imprimir la cadena formateada directamente a la salida estándar (consola)
    std::cout << dias_semana[dia_semana_idx] << ", ";
    std::cout << dia << " de ";
    std::cout << nombres_meses[mes] << " del ";
    std::cout << anio << std::endl;
}

unsigned short calcularDiaDeLaSemana(unsigned short dia, unsigned short mes, unsigned short anio) {
    // Ajustes para enero y febrero según el algoritmo de Zeller
    if (mes < 3) {
        mes += 12;
        anio--;
    }

    unsigned short K = anio % 100; // El año del siglo (los dos últimos dígitos del año)
    unsigned short J = anio / 100; // El siglo (los dos primeros dígitos del año)

    // Fórmula de la Congruencia de Zeller
    unsigned short h = (dia + (13 * (mes + 1)) / 5 + K + K / 4 + J / 4 - 2 * J) % 7;

    // Ajustamos 'h' para que coincida con el mapeo deseado (0=Domingo, 1=Lunes, etc.)
    switch (h) {
    case 0: return 6; // Sábado -> 6
    case 1: return 0; // Domingo -> 0
    case 2: return 1; // Lunes -> 1
    case 3: return 2; // Martes -> 2
    case 4: return 3; // Miércoles -> 3
    case 5: return 4; // Jueves -> 4
    case 6: return 5; // Viernes -> 5
    default: return 7; // Esto no debería ocurrir
    }
}
