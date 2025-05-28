#ifndef IDMANAGER_H
#define IDMANAGER_H

unsigned int generarCodigoReserva();
unsigned int fechaFinal(unsigned int fecha_i, unsigned short num_noches);
void imprimirFechaFormatoExtendido(unsigned int fecha_AAAAMMDD);
unsigned short calcularDiaDeLaSemana(unsigned short dia, unsigned short mes, unsigned short anio);

#endif // IDMANAGER_H
