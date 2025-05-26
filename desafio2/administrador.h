#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "anfitrion.h"

class Administrador{
private:
    Anfitrion** anfitriones;    // en airbnb hay aprox 2000 anfitriones
    //Huesped** huespedes;      //
    unsigned short indice;      // indice en proximo anfitrión vacío
    unsigned int fecha_hoy;

public:
    Administrador();
    Administrador(const Administrador &otro);
    ~Administrador();

    // Getters
    const Anfitrion* const* getAnfitriones() const;
    unsigned short getIndice() const;
    unsigned int getFechaHoy() const;
    //const Huesped* const* getHuespedes() const;

    // Setters
    void setAnfitriones(Anfitrion* const anfitriones[]);
    void setIndice(unsigned short indice);
    void setFechaHoy(unsigned int fecha_hoy);
    //void setHuespedes(Huesped* const huespedes[]);

    // Métodos adicionales
    void addObject(Anfitrion* anfitrion);
    //void addObject(unsigned short indice, Huesped* anfitrion);
    Anfitrion* searchObject(const char id[]);    //busca un admin por su id

};

#endif // ADMINISTRADOR_H
