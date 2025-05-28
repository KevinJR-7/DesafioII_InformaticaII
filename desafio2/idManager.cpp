#include "idManager.h"

unsigned int generarCodigoReserva()
{
    static unsigned int code = 0;
    code++;
    return code;
}
