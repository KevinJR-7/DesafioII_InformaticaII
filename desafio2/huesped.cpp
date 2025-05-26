#include "huesped.h"

// Constructor por defecto
Huesped::Huesped() : antiguedad(0), puntuacion(0)
{
    id = new char[16]();   //el parentesis inicializa a \0
    reservas = new Reserva[365]();
}

// Constructor de copia
Huesped::Huesped(const Huesped &otro)
{
    id = new char[16];
    reservas = new Reserva[365];

    unsigned short i = 0;
    for(i = 0; i < 16; i++){ id[i] = otro.id[i]; }
    antiguedad = otro.antiguedad;
    puntuacion = otro.puntuacion;
    for(i = 0; i < 365; i++){ reservas[i] = otro.reservas[i]; }
}

// Destructor
Huesped::~Huesped()
{
    delete[] id;
    delete[] reservas;
}

// Sobreacarga de Operadores
Huesped& Huesped::operator=(const Huesped& otro) {
    // evitar a = a;
    if(this == &otro){ return *this; }

    // liberar los apuntadores dinámicos
    delete[] id;
    delete[] reservas;

    id = new char[16];
    reservas = new Reserva[365];

    unsigned short i = 0;
    for(i = 0; i < 16; i++){ id[i] = otro.id[i]; }
    antiguedad = otro.antiguedad;
    puntuacion = otro.puntuacion;
    for(i = 0; i < 365; i++){ reservas[i] = otro.reservas[i]; }

    return *this;
}

// Getters
const char* Huesped::getId() const { return id; }
unsigned short Huesped::getAntiguedad() const { return antiguedad; }
unsigned short Huesped::getPuntuacion() const { return puntuacion; }
const Reserva* Huesped::getReservas() const { return reservas; }

// Setters
void Huesped::setId(const char id[])
{
    unsigned short i = 0;
    for(i = 0; i < 16; i++)
    {
        if(id[i] == '\0'){ break; }    //frena al llegar a caracter nulo
        this->id[i] = id[i];
    }
    for(i; i < 16; i++){ this->id[i] = '\0'; }
}
void Huesped::setAntiguedad(unsigned short antiguedad){ this->antiguedad = antiguedad; }
void Huesped::setPuntuacion(unsigned short puntuacion){ this->puntuacion = puntuacion; }
void Huesped::setReservas(const Reserva reservas[])
{
    unsigned short i = 0;
    for(i = 0; i < 365; i++)
    {
        if(reservas[i].getCodigo() == 0){ break; }
        this->reservas[i] = reservas[i];
    }
    for(i; i < 50; i++){ this->reservas[i] = Reserva(); }
}

// Métodos adicionales
bool Huesped::reservar()
{
    //
    return false;
}

bool Huesped::anularReserva(unsigned short codigo)
{
    //
    return false;
}
