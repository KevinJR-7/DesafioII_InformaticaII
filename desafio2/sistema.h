#ifndef SISTEMA_H
#define SISTEMA_H

#include <string> // Para std::string en algunas declaraciones de leerEntrada

// --- Inclusión de tus clases (asegúrate que estas cabeceras existan y sean correctas) ---
#include "huesped.h"
#include "anfitrion.h"
#include "alojamiento.h"
#include "reserva.h"

// --- Constantes Globales para Tamaños de Arrays ---
const int MAX_HUESPEDES = 100;
const int MAX_ANFITRIONES = 50;
const int MAX_ALOJAMIENTOS = 200;
const int MAX_RESERVAS = 500; // Para vigentes e históricas, ajusta si son separadas

// --- Declaraciones de Variables Globales (extern) ---
// Estas serán definidas en sistema.cpp
extern Huesped g_huespedes[MAX_HUESPEDES];
extern unsigned int g_numHuespedes;

extern Anfitrion g_anfitriones[MAX_ANFITRIONES];
extern unsigned int g_numAnfitriones;

extern Alojamiento g_alojamientos[MAX_ALOJAMIENTOS];
extern unsigned int g_numAlojamientos;

extern Reserva g_reservasVigentes[MAX_RESERVAS];
extern unsigned int g_numReservasVigentes;

extern Reserva g_reservasHistoricas[MAX_RESERVAS]; // Asumiendo mismo tamaño máximo
extern unsigned int g_numReservasHistoricas;


// --- Declaraciones de Funciones del Sistema ---

// Funciones principales de manejo de datos
void cargarDatos();
void guardarDatos(); // Implementar si es necesario

// Funciones de utilidad para leer entrada del usuario
unsigned int leerEntradaInt(const char* mensaje);
float leerEntradaFloat(const char* mensaje);
void leerEntradaTexto(const char* mensaje, char* bufferDestino, int bufferSize, bool permitirVacio = false);
bool leerEntradaBool(const char* mensaje, const char* opcionVerdadera = "S", const char* opcionFalsa = "N");
unsigned int leerEntradaFecha(const char* mensaje); // Devuelve YYYYMMDD
// void leerEntradaMetodoPago(const char* mensaje, char* bufferDestino, int bufferSize); // Puedes usar leerEntradaBool o esta


#endif // SISTEMA_H