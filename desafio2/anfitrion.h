#ifndef ANFITRION_H
#define ANFITRION_H

#include "alojamiento.h"

class Anfitrion {
private:
    char* id;                // cc o passport number (en emiratos 15char)
    unsigned short antiguedad;  // tiempo como anfitrión en meses
    unsigned short puntuacion;  // puntuacion entre 0 y 50 (pasar a 0 y 5.0)
    Alojamiento* alojamientos;  // basandose en datos no muy precisos, no creo que un propietario supere las 50 propiedades

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
    Alojamiento* getAlojamientos();

    // Setters
    void setId(const char id[]);
    void setAntiguedad(unsigned short meses);
    void setPuntuacion(unsigned short puntuacion);
    void setAlojamientos(const Alojamiento alojamientos[]);

    // Métodos adicionales
    short anularReserva(unsigned int fecha);
    short consultarReservas(unsigned int fecha_i, unsigned int fecha_f) const;
    short consultarReservas(unsigned int fecha_i, unsigned int fecha_f, unsigned short& max) const; // muestra reservas entre esas fechas
    short actualizarHistorico(Anfitrion* const anfitriones[], unsigned int &fecha_actual, unsigned int fecha_nueva) const;  // fecha hoy modificable
};

#endif // ANFITRION_H
