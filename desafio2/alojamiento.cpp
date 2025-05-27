#include "alojamiento.h"

// Constructor
Alojamiento::Alojamiento() : id(0), tipo(false), precio(0)  //inicializa
{
    nombre = new char[100]();   //el parentesis inicializa a \0
    anfitrion = new char[16]();
    departamento = new char[10]();
    municipio = new char[26]();
    direccion = new char[100]();
    amenidades = new bool[20]();
    fechas = new bool[365]();
    reservas = new Reserva*[365]();
}

// Constructor de copia
Alojamiento::Alojamiento(const Alojamiento &otro)
{
    nombre = new char[100];
    anfitrion = new char[16];
    departamento = new char[10];
    municipio = new char[26];
    direccion = new char[100];
    amenidades = new bool[20];
    fechas = new bool[365];
    reservas = new Reserva*[365];

    unsigned short i = 0;
    for(i = 0; i < 100; i++){ nombre[i] = otro.nombre[i]; }
    id = otro.id;
    for(i = 0; i < 16; i++){ anfitrion[i] = otro.anfitrion[i]; }
    for(i = 0; i < 10; i++){ departamento[i] = otro.departamento[i]; }
    for(i = 0; i < 26; i++){ municipio[i] = otro.municipio[i]; }
    tipo = otro.tipo;
    for(i = 0; i < 100; i++){ direccion[i] = otro.direccion[i]; }
    precio = otro.precio;
    for(i = 0; i < 20; i++){ amenidades[i] = otro.amenidades[i]; }
    for(i = 0; i < 365; i++){ fechas[i] = otro.fechas[i]; }
    for(i = 0; i < 365; i++){ reservas[i] = otro.reservas[i]; }     // copia los punteros, no queremos reservas duplicadas
}

// Destructor
Alojamiento::~Alojamiento()
{
    delete[] nombre;
    delete[] anfitrion;
    delete[] departamento;
    delete[] municipio;
    delete[] direccion;
    delete[] amenidades;
    delete[] fechas;
    delete[] reservas;  // solo libera los punteros (huesped se encarga de los Reserva)
}

// Sobreacarga de Operadores
Alojamiento& Alojamiento::operator=(const Alojamiento& otro) {
    // evitar a = a;
    if(this == &otro){ return *this; }

    // liberar los apuntadores dinámicos
    delete[] nombre;
    delete[] anfitrion;
    delete[] departamento;
    delete[] municipio;
    delete[] direccion;
    delete[] amenidades;
    delete[] fechas;
    delete[] reservas;

    nombre = new char[100];
    anfitrion = new char[16];
    departamento = new char[10];
    municipio = new char[26];
    direccion = new char[100];
    amenidades = new bool[20];
    fechas = new bool[365];
    reservas = new Reserva*[365];

    unsigned short i = 0;
    for(i = 0; i < 100; i++){ nombre[i] = otro.nombre[i]; }
    id = otro.id;
    for(i = 0; i < 16; i++){ anfitrion[i] = otro.anfitrion[i]; }
    for(i = 0; i < 10; i++){ departamento[i] = otro.departamento[i]; }
    for(i = 0; i < 26; i++){ municipio[i] = otro.municipio[i]; }
    tipo = otro.tipo;
    for(i = 0; i < 100; i++){ direccion[i] = otro.direccion[i]; }
    precio = otro.precio;
    for(i = 0; i < 20; i++){ amenidades[i] = otro.amenidades[i]; }
    for(i = 0; i < 365; i++){ fechas[i] = otro.fechas[i]; }
    for(i = 0; i < 365; i++){ reservas[i] = otro.reservas[i]; }

    return *this;
}

// Getters
const char* Alojamiento::getNombre() const { return nombre; }
unsigned short Alojamiento::getId() const { return id; }
const char* Alojamiento::getAnfitrion() const { return anfitrion; }
const char* Alojamiento::getDepartamento() const { return departamento; }
const char* Alojamiento::getMunicipio() const { return municipio; }
bool Alojamiento::getTipo() const { return tipo; }
const char* Alojamiento::getDireccion() const { return direccion; }
unsigned int Alojamiento::getPrecio() const { return precio; }
const bool* Alojamiento::getAmenidades() const { return amenidades; }
const bool* Alojamiento::getFechas() const { return fechas; }
const Reserva* const* Alojamiento::getReservas() const { return reservas; }

// Setters
void Alojamiento::setNombre(const char nombre[])
{
    unsigned short i = 0;
    for(i = 0; i < 100; i++)
    {
        if(nombre[i] == '\0'){ break; }    //frena al llegar a caracter nulo
        this->nombre[i] = nombre[i];
    }
    for(i; i < 100; i++){ this->nombre[i] = '\0'; }
}
void Alojamiento::setId(unsigned short id) { this->id = id; }
void Alojamiento::setAnfitrion(const char anfitrion[])
{
    unsigned short i = 0;
    for(i = 0; i < 16; i++)
    {
        if(anfitrion[i] == '\0'){ break; }    //frena al llegar a caracter nulo
        this->anfitrion[i] = anfitrion[i];
    }
    for(i; i < 16; i++){ this->anfitrion[i] = '\0'; }
}
void Alojamiento::setDepartamento(const char departamento[])
{
    unsigned short i = 0;
    for(i = 0; i < 10; i++)
    {
        if(departamento[i] == '\0'){ break; }    //frena al llegar a caracter nulo
        this->departamento[i] = departamento[i];
    }
    for(i; i < 10; i++){ this->departamento[i] = '\0'; }
}
void Alojamiento::setMunicipio(const char municipio[])
{
    unsigned short i = 0;
    for(i = 0; i < 26; i++)
    {
        if(municipio[i] == '\0'){ break; }    //frena al llegar a caracter nulo
        this->municipio[i] = municipio[i];
    }
    for(i; i < 26; i++){ this->municipio[i] = '\0'; }
}
void Alojamiento::setTipo(bool tipo) { this->tipo = tipo; }
void Alojamiento::setDireccion(const char direccion[])
{
    unsigned short i = 0;
    for(i = 0; i < 100; i++)
    {
        if(direccion[i] == '\0'){ break; }    //frena al llegar a caracter nulo
        this->direccion[i] = direccion[i];
    }
    for(i; i < 100; i++){ this->direccion[i] = '\0'; }
}
void Alojamiento::setPrecio(unsigned int precio) { this->precio = precio; }
void Alojamiento::setAmenidades(const bool amenidades[])
{
    unsigned short i = 0;
    for(i = 0; i < 20; i++) this->amenidades[i] = amenidades[i];
}
void Alojamiento::setFechas(const bool fechas[])
{
    unsigned short i = 0;
    for(i = 0; i < 365; i++) this->fechas[i] = fechas[i];
}
void Alojamiento::setReservas(Reserva* const reservas[])    // rectificar size fuera!!
{
    unsigned short i = 0;
    for(i = 0; i < 365; i++)
    {
        //if(reservas[i] == nullptr){ break; }    //frena al llegar a arreglo nulo
        this->reservas[i] = reservas[i];
    }
    //for(i; i < 365; i++){ this->reservas[i] = nullptr; }
}
