#include "idManager.h"

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
