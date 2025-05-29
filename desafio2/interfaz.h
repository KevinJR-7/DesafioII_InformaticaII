#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "huesped.h"    // Para Huesped*
#include "anfitrion.h"  // Para Anfitrion*

/**
 * @brief Función para reservar un alojamiento.
 * * Esta función solicita al usuario que ingrese los detalles de la reserva,
 * * como el número de noches, fecha de inicio y método de pago.
 * * Luego, busca alojamientos disponibles y permite al usuario seleccionar uno.
 * * Finalmente, crea una reserva y la asocia al huésped actual.
 * 
 * @param huespedActual 
 */
void reservarAlojamiento(Huesped* huespedActual);

/**
 * @brief Función para anular una reservación.
 * 
 * Esta función permite al huésped o anfitrión anular una reserva existente.
 * Solicita al usuario que seleccione la reserva a anular y realiza la operación.
 * 
 * @param huespedActual Puntero al objeto Huesped actual, si es un huésped.
 * @param anfitrionActual Puntero al objeto Anfitrion actual, si es un anfitrión.
 */
void anularReservacion(Huesped* huespedActual, Anfitrion* anfitrionActual);

/**
 * @brief Función para consultar las reservaciones de un anfitrión.
 * 
 * Esta función permite al anfitrión consultar las reservas vigentes de sus alojamientos.
 * Muestra una lista de reservas y permite al anfitrión ver detalles específicos.
 * 
 * @param anfitrionActual Puntero al objeto Anfitrion actual.
 */
void consultarReservacionesAnfitrion(Anfitrion* anfitrionActual);

/**
 * @brief Función para actualizar el histórico de reservas de un anfitrión.
 * 
 * Esta función permite al anfitrión actualizar su histórico de reservas,
 * moviendo las reservas vigentes a un archivo histórico.
 * 
 * @param anfitrionActual Puntero al objeto Anfitrion actual.
 */
void actualizarHistorico(Anfitrion* anfitrionActual);

// --- Declaraciones de Funciones de Menú ---

/**
 * @brief Muestra el menú principal del huésped y maneja las opciones seleccionadas.
 * 
 * Este menú permite al huésped reservar alojamientos, anular reservas propias
 * y cerrar sesión. Se ejecuta en un bucle hasta que el usuario decide salir.
 * 
 * @param huespedActual Puntero al objeto Huesped actual.
 */
void menuHuesped(Huesped* huespedActual);

/**
 * @brief Muestra el menú principal del anfitrión y maneja las opciones seleccionadas.
 * 
 * Este menú permite al anfitrión anular reservas de sus alojamientos,
 * consultar reservas vigentes y actualizar su histórico de reservas.
 * Se ejecuta en un bucle hasta que el usuario decide salir.
 * 
 * @param anfitrionActual Puntero al objeto Anfitrion actual.
 */
void menuAnfitrion(Anfitrion* anfitrionActual);

#endif // INTERFAZ_H