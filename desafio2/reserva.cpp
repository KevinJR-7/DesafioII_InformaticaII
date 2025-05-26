#include "reserva.h"

// Constructor
Reserva::Reserva() : codigo(0), alojamiento(0), num_noches(0),
    fecha_i(0), pago(false), fecha_pago(0), precio(0)
{
    huesped = new char[16]();
    comentarios = new char[1001]();
}

// Constructor de copia
Reserva::Reserva(const Reserva &otro)
{
    huesped = new char[16];
    comentarios = new char[1001];

    codigo = otro.codigo;
    alojamiento = otro.alojamiento;
    unsigned short i = 0;
    for(i = 0; i < 16; i++){ huesped[i] = otro.huesped[i]; }
    num_noches = otro.num_noches;
    fecha_i = otro.fecha_i;
    pago = otro.pago;
    fecha_pago = otro.fecha_pago;
    precio = otro.precio;
    for(i = 0; i < 1001; i++){ comentarios[i] = otro.comentarios[i]; }
}

// Destructor
Reserva::~Reserva()
{
    delete[] huesped;
    delete[] comentarios;
}

// Sobreacarga de Operadores
Reserva& Reserva::operator=(const Reserva& otro) {
    // evitar a = a;
    if(this == &otro){ return *this; }

    // liberar los apuntadores dinámicos
    delete[] huesped;
    delete[] comentarios;

    huesped = new char[16];
    comentarios = new char[1001];

    codigo = otro.codigo;
    alojamiento = otro.alojamiento;
    unsigned short i = 0;
    for(i = 0; i < 16; i++){ huesped[i] = otro.huesped[i]; }
    num_noches = otro.num_noches;
    fecha_i = otro.fecha_i;
    pago = otro.pago;
    fecha_pago = otro.fecha_pago;
    precio = otro.precio;
    for(i = 0; i < 1001; i++){ comentarios[i] = otro.comentarios[i]; }

    return *this;
}

// Getters
unsigned short Reserva::getCodigo() const { return codigo; }
unsigned short Reserva::getIdAlojamiento() const { return alojamiento; }
const char* Reserva::getIdHuesped() const { return huesped; }
unsigned short Reserva::getNumNoches() const { return num_noches; }
unsigned int Reserva::getFechaInicio() const { return fecha_i; }
bool Reserva::getMetodoPago() const { return pago; }
unsigned int Reserva::getFechaPago() const { return fecha_pago; }
unsigned int Reserva::getPrecio() const { return precio; }
const char* Reserva::getComentarios() const { return comentarios; }

// Setters
void Reserva::setCodigo(unsigned short codigo) { this->codigo = codigo; }

void Reserva::setIdAlojamiento(unsigned short alojamiento) { this->alojamiento = alojamiento; }

void Reserva::setIdHuesped(const char huesped[])
{
    unsigned short i = 0;
    for(i = 0; i < 16; i++)
    {
        if(huesped[i] == '\0'){ break; }    //frena al llegar a caracter nulo
        this->huesped[i] = huesped[i];
    }
    for(i; i < 16; i++){ this->huesped[i] = '\0'; }
}

void Reserva::setNumNoches(unsigned short num_noches) { this->num_noches = num_noches; }

void Reserva::setFechaInicio(unsigned int fecha_i) { this->fecha_i = fecha_i; }

void Reserva::setMetodoPago(bool pago) { this->pago = pago; }

void Reserva::setFechaPago(unsigned int fecha_pago) { this->fecha_pago = fecha_pago; }

void Reserva::setPrecio(unsigned int precio) { this->precio = precio; }

void Reserva::setComentarios(const char comentarios[])
{
    unsigned short i = 0;
    for(i = 0; i < 1001; i++)
    {
        if(comentarios[i] == '\0'){ break; }    //frena al llegar a caracter nulo
        this->comentarios[i] = comentarios[i];
    }
    for(i; i < 1001; i++){ this->comentarios[i] = '\0'; }
}
