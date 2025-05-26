#include "anfitrion.h"
#include <iostream>

// Constructor
Anfitrion::Anfitrion() : antiguedad(0), puntuacion(0)
{
    id = new char[16]();   //el parentesis inicializa a \0
    alojamientos = new Alojamiento[50];
}

// Constructor de copia
Anfitrion::Anfitrion(const Anfitrion &otro)
{
    id = new char[16];
    alojamientos = new Alojamiento[50];

    unsigned short i = 0;
    for(i = 0; i < 16; i++){ id[i] = otro.id[i]; }
    antiguedad = otro.antiguedad;
    puntuacion = otro.puntuacion;
    for(i = 0; i < 50; i++){ alojamientos[i] = otro.alojamientos[i]; }
}

// Destructor
Anfitrion::~Anfitrion()
{
    delete[] id;
    delete[] alojamientos;  // sobreacargado por c++
}

// Sobreacarga de Operadores
Anfitrion& Anfitrion::operator=(const Anfitrion& otro) {
    // evitar a = a;
    if(this == &otro){ return *this; }

    // liberar los apuntadores dinámicos
    delete[] id;
    delete[] alojamientos;  // sobreacargado por c++

    id = new char[16];
    alojamientos = new Alojamiento[50];

    unsigned short i = 0;
    for(i = 0; i < 16; i++){ id[i] = otro.id[i]; }
    antiguedad = otro.antiguedad;
    puntuacion = otro.puntuacion;
    for(i = 0; i < 50; i++){ alojamientos[i] = otro.alojamientos[i]; }

    return *this;
}

// Getters
const char* Anfitrion::getId() const { return id; }
unsigned short Anfitrion::getAntiguedad() const { return antiguedad; }
unsigned short Anfitrion::getPuntuacion() const { return puntuacion; }
const Alojamiento* Anfitrion::getAlojamientos() const { return alojamientos; }

// Setters
void Anfitrion::setId(const char id[])
{
    unsigned short i = 0;
    for(i = 0; i < 16; i++)
    {
        if(id[i] == '\0'){ break; }    //frena al llegar a caracter nulo
        this->id[i] = id[i];
    }
    for(i; i < 16; i++){ this->id[i] = '\0'; }
}
void Anfitrion::setAntiguedad(unsigned short antiguedad){ this->antiguedad = antiguedad; }
void Anfitrion::setPuntuacion(unsigned short puntuacion){ this->puntuacion = puntuacion; }
void Anfitrion::setAlojamientos(const Alojamiento alojamientos[])    // necesario un alojamento 0 al final si son menos de 50
{
    unsigned short i = 0;
    for(i = 0; i < 50; i++)
    {
        if(alojamientos[i].getId() == 0){ break; }
        this->alojamientos[i] = alojamientos[i];
    }
    for(i; i < 50; i++){ this->alojamientos[i] = Alojamiento(); }
}

// Métodos adicionales
bool Anfitrion::anularReserva(unsigned short codigo)
{
    //
    return false;
}

void Anfitrion::consultarReservas(unsigned int fecha_i, unsigned int fecha_f) const
{
    // Método sin salida directa por consola
    // Podría llenarse una estructura de datos con las fechas a consultar
}

void Anfitrion::actualizarHistorico(unsigned int &fecha) const
{
    // Método sin salida directa por consola
    // Podría modificarse algún atributo relacionado con historial
}
