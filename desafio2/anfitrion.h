#ifndef ANFITRION_H
#define ANFITRION_H

#include "alojamiento.h"

class Anfitrion {
private:
    char* id;                // cc o passport number (en emiratos 15char)
    unsigned short antiguedad;  // tiempo como anfitrión en meses
    unsigned short puntuacion;  // puntuacion entre 0 y 50 (pasar a 0 y 5.0)
    Alojamiento* alojamientos;

public:
    Anfitrion();
    Anfitrion(const Anfitrion &otro);
    ~Anfitrion();

    // Sobrecarga de operadores
    Anfitrion& operator=(const Anfitrion& otro);

    // Getters
    const char* getId() const;
    unsigned short getAntiguedad() const;
    unsigned short getPuntuacion() const;
    const Alojamiento* getAlojamientos() const;

    // Setters
    void setId(const char id[]);
    void setAntiguedad(unsigned short meses);
    void setPuntuacion(unsigned short puntuacion);
    void setAlojamientos(const Alojamiento alojamientos[]);

    // Métodos adicionales
    bool anularReserva(Reserva reserva[]);
    bool consultarReservas(unsigned int fecha_i, unsigned int fecha_f) const; // muestra reservas entre esas fechas
    bool actualizarHistorico(unsigned int &fecha) const;  // fecha hoy modificable
};

#endif // ANFITRION_H
