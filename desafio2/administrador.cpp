#include "administrador.h"

// Constructor
Administrador::Administrador() : indice(0), fecha_hoy(0)
{
    anfitriones = new Anfitrion*[2000]();   // aprox 8kilobytes
}

// Constructor de copia
Administrador::Administrador(const Administrador &otro)
{
    fecha_hoy = otro.fecha_hoy;
    indice = otro.indice;
    anfitriones = new Anfitrion*[2000];
    for(unsigned short i = 0; i < 365; i++){ anfitriones[i] = otro.anfitriones[i]; }     // copia los punteros, no queremos reservas duplicadas
}

// Destructor
Administrador::~Administrador()
{
    delete[] anfitriones;  // solo libera los punteros
}

// Getters
const Anfitrion* const* Administrador::getAnfitriones() const { return anfitriones; }
unsigned short Administrador::getIndice() const { return indice; }
unsigned int Administrador::getFechaHoy() const { return fecha_hoy; }

// Setters
void Administrador::setAnfitriones(Anfitrion* const anfitriones[])    // rectificar size fuera!!
{
    unsigned short i = 0;
    for(i = 0; i < 2000; i++)
    {
        if(anfitriones[i] == nullptr){ break; }    //frena al llegar a arreglo nulo
        this->anfitriones[i] = anfitriones[i];
    }
    for(i; i < 2000; i++){ this->anfitriones[i] = nullptr; }
}
void Administrador::setIndice(unsigned short indice){ this->indice = indice; }
void Administrador::setFechaHoy(unsigned int fecha_hoy){ this->fecha_hoy = fecha_hoy; }

// Métodos Adicionales
void Administrador::addObject(Anfitrion* anfitrion)
{
    this->anfitriones[this->indice] = anfitrion;
    this->indice++;
}

Anfitrion* Administrador::searchObject(const char id[])
{
    for(unsigned short i = 0; i < 2000; i++)
    {
        if(this->anfitriones[i] == nullptr){ return nullptr; }
        unsigned short j = 0;
        for(j = 0; j < 16; j++)
        {
            if(this->anfitriones[i]->getId()[j] != id[j]){ break; }
        }
        if(j == 16){ return this->anfitriones[i]; }
    }
    return nullptr;
}
