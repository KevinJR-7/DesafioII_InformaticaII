#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "huesped.h"    // Para Huesped*
#include "anfitrion.h"  // Para Anfitrion*


void reservarAlojamiento(Huesped* huespedActual);
void anularReservacion(Huesped* huespedActual, Anfitrion* anfitrionActual);
void consultarReservacionesAnfitrion(Anfitrion* anfitrionActual);
void actualizarHistorico(Anfitrion* anfitrionActual);

// --- Declaraciones de Funciones de Menú ---
void menuHuesped(Huesped* huespedActual);
void menuAnfitrion(Anfitrion* anfitrionActual);

#endif // MENU_H