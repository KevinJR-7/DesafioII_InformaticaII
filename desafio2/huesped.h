#ifndef HUESPED_H
#define HUESPED_H

#include "reserva.h"

class Huesped {
private:
    char* id;                // cc o passport number (en emiratos 15char)
    unsigned short antiguedad; // tiempo en meses en la app
    unsigned short puntuacion;  // puntuacion entre 0 y 50 (pasar a 0 y 5.0)
    Reserva* reservas; // arreglo con códigos de reservas

public:
    Huesped();
    Huesped(const Huesped &otro);
    ~Huesped();

    // Sobrecarga de operadores
    Huesped& operator=(const Huesped& otro);

    // Getters
    const char* getId() const;
    unsigned short getAntiguedad() const;
    unsigned short getPuntuacion() const;
    const Reserva* getReservas() const;

    // Setters
    void setId(const char id[]);
    void setAntiguedad(unsigned short meses);
    void setPuntuacion(unsigned short puntuacion);
    void setReservas(const Reserva reservas[]);

    // Métodos adicionales
    bool reservar();
    bool anularReserva(unsigned short codigo);
};

#endif // HUESPED_H
