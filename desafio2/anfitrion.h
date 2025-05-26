#ifndef ANFITRION_H
#define ANFITRION_H

class Anfitrion {
private:
    char id[15];                // cc o passport number (en emiratos 15char)
    unsigned short antiguedad;  // tiempo como anfitrión en meses
    unsigned short puntuacion;  // puntuacion entre 0 y 50 (pasar a 0 y 5.0)
    unsigned short alojamientos[50]; // arreglo con códigos de alojamientos

public:
    Anfitrion();

    Anfitrion(const Anfitrion &otro);

    ~Anfitrion();

    // Getters
    const char* getId() const;
    unsigned short getAntiguedad() const;
    unsigned short getPuntuacion() const;
    const unsigned short* getAlojamientos() const;

    // Setters
    void setId(const char id[]);
    void setAntiguedad(unsigned short meses);
    void setPuntuacion(unsigned short puntuacion);
    void setAlojamientos(const unsigned short alojamientos[], unsigned short cantidad);

    // Métodos adicionales
    bool anularReserva(unsigned short codigo);
    void consultarReservas(unsigned int fecha_i, unsigned int fecha_f) const; // muestra reservas entre esas fechas
    void actualizarHistorico(unsigned int fecha_i);
};

#endif // ANFITRION_H
