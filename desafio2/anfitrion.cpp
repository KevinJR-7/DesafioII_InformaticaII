#include "anfitrion.h"
#include <iostream>

// Constructor
Anfitrion::Anfitrion() : antiguedad(0), puntuacion(0)
{
    id = new char[16]();   //el parentesis inicializa a \0
    alojamientos = new Alojamiento[50]();
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
unsigned short Anfitrion::anularReserva(Reserva reserva[])
{
    // muestra por consola al usuario todas las reservas de este anfitrion (llamar a consultarReservas con fechas min y max)
    // recibir un valor(puede ser un codigo de reserva o el numero de reserva mostrada)
        // una buena opción es conservar un contador de las reservas que se muestran para así acceder a la reserva correcta con un switch (??)
    /*   Esta primera parte puede estar fuera y enviar el índice o código como parametro   */
    // reset a esa reserva
    // cambiar apuntador en alojamiento a nullptr
    // retorna true si todo melo;
    return 0;
}

unsigned short Anfitrion::consultarReservas(unsigned int fecha_i, unsigned int fecha_f) const     // rectificar que las fechas están dentro de 12meses
{
    // muestra por consola al usuario todas las reservas en estas fechas (itera por las reservas dentro de alojamientos comparando fechas)
    unsigned int fecha_aux = 00000000;
    unsigned short cnt = 0;

    if(this->alojamientos[0].getId() == 0){ return 1; }
    for(unsigned short i = 0; i < 50; i++)
    {
        if(this->alojamientos[i].getId() == 0){ break; }
        for(unsigned short j = 0; j < 365; j++)
        {
            if(this->alojamientos[i].getReservas()[j] != nullptr)
            {
                fecha_aux = this->alojamientos[i].getReservas()[j]->getFechaInicio();
                if((fecha_aux > fecha_i) && (fecha_aux < fecha_f))
                {
                    //mostrarReserva(this->alojamientos[i].getReservas()[j])
                    unsigned short code = this->alojamientos[i].getReservas()[j]->getCodigo();
                    std::cout << "Reserva encontrada el " << fecha_aux << " con codigo: " << code << std::endl;
                    // si queda tiempo, implementar un organizador en orden de fechas de los indices para imprimir en orden
                    cnt++;
                }
            }
        }
    }
    if(cnt == 0){ return 2; }
    else{ return 0; }
}

unsigned short Anfitrion::actualizarHistorico(unsigned int &fecha) const
{
    // tengo sueño, luego pienso el paso a paso de este método
    return 0;
}
