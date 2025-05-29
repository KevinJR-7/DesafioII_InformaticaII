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
const int MAX_RESERVAS = 500; 

/**
 * @brief Definición de nombres de archivo para cargar y guardar datos.
 * 
 * 
 */
extern Huesped g_huespedes[MAX_HUESPEDES];
extern unsigned int g_numHuespedes;

extern Anfitrion g_anfitriones[MAX_ANFITRIONES];
extern unsigned int g_numAnfitriones;

extern Alojamiento g_alojamientos[MAX_ALOJAMIENTOS];
extern unsigned int g_numAlojamientos;

extern Reserva g_reservasVigentes[MAX_RESERVAS];
extern unsigned int g_numReservasVigentes;

extern Reserva g_reservasHistoricas[MAX_RESERVAS];
extern unsigned int g_numReservasHistoricas;




// Funciones principales de manejo de datos
/**
 * @brief Función para cargar los datos del sistema desde archivos.
 * 
 * Esta función debe leer los archivos de datos y cargar la información
 * de huéspedes, anfitriones, alojamientos y reservas en las estructuras
 * de datos correspondientes. Debe manejar errores de formato y
 * validación de datos.
 * 
 * 
 */
void cargarDatos();

/**
 * @brief Funcion para guardar los datos del sistema en archivos.
 * Esta función debe guardar los historicos de todos los objetos del sistema
 * que sean necesarios, como huéspedes, anfitriones, alojamientos y reservas actuales como históricos.
 * 
 */
void guardarDatos(); // Implementar si es necesario

// Funciones de utilidad para leer entrada del usuario
/**
 * @brief Función para leer un número entero desde la entrada estándar.
 * 
 * @param mensaje 
 * @return unsigned int 
 */
unsigned int leerEntradaInt(const char* mensaje);

/**
 * @brief Funcion para leer un número de punto flotante desde la entrada estándar.
 * 
 * @param mensaje 
 * @return float 
 */
float leerEntradaFloat(const char* mensaje);

/**
 * @brief Función para leer una cadena de texto desde la entrada estándar.
 * Esta función solicita al usuario un mensaje y almacena la entrada en el bufferDestino.
 * Si permitirVacio es false, no se permitirá que el usuario deje el campo vacío.
 * * @note El bufferDestino debe tener suficiente espacio para almacenar la cadena ingresada.
 * 
 * @param mensaje 
 * @param bufferDestino 
 * @param bufferSize 
 * @param permitirVacio 
 */
void leerEntradaTexto(const char* mensaje, char* bufferDestino, int bufferSize, bool permitirVacio = false);

/**
 * @brief Leer una fecha en formato YYYYMMDD desde la entrada estándar.
 * 
 * Esta función solicita al usuario que ingrese una fecha en formato YYYYMMDD.
 * Valida que la entrada sea un número de 8 dígitos y maneja errores de formato.
 * Si la entrada es válida, devuelve la fecha como un número entero.
 * 
 * @param mensaje 
 * @return unsigned int 
 */
unsigned int leerEntradaFecha(const char* mensaje); // Devuelve YYYYMMDD

/**
 * @brief Función para leer el método de pago desde la entrada estándar.
 * 
 * Esta función solicita al usuario que ingrese un método de pago (PSE o TCredito).
 * Valida la entrada y almacena el valor en bufferDestino.
 * 
 * @param mensaje Mensaje a mostrar al usuario.
 * @param bufferDestino Buffer donde se almacenará el método de pago.
 * @param bufferSize Tamaño del bufferDestino.
 */
void leerEntradaMetodoPago(const char* mensaje, char* bufferDestino, int bufferSize);
/**
 * @brief Función para iniciar sesión como huésped.
 * 
 * Esta función solicita al usuario que ingrese su ID de huésped.
 * Busca en la lista de huéspedes y, si encuentra una coincidencia,
 * devuelve un puntero al objeto Huesped correspondiente.
 * 
 * @return Huesped* 
 */
Huesped* iniciarSesionHuesped();       // Devuelve un puntero al Huesped si es exitoso, nullptr si no

/**
 * @brief Función para iniciar sesión como anfitrión.
 * 
 * Esta función solicita al usuario que ingrese su ID de anfitrión.
 * Busca en la lista de anfitriones y, si encuentra una coincidencia,
 * devuelve un puntero al objeto Anfitrion correspondiente.
 * 
 * @return Anfitrion* 
 */
Anfitrion* iniciarSesionAnfitrion(); // Devuelve un puntero al Anfitrion si es exitoso, nullptr si no


#endif // SISTEMA_H