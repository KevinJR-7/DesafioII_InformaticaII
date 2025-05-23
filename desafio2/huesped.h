#ifndef HUESPED_H
#define HUESPED_H

class Huesped {
private:
    char id[15];                // cc o passport number (en emiratos 15char)
    unsigned short antiguedad; // tiempo en meses en la app
    unsigned short puntuacion;  // puntuacion entre 0 y 50 (pasar a 0 y 5.0)
    unsigned short reservas[365]; // arreglo con códigos de reservas

public:
    Huesped();
    Huesped(const Huesped &otro);
    ~Huesped();

    // Getters
    const char* getId() const;
    unsigned short getAntiguedad() const;
    unsigned short getPuntuacion() const;
    const unsigned short* getReservas() const;

    // Setters
    void setId(const char id[]);
    void setAntiguedad(unsigned short meses);
    void setPuntuacion(unsigned short puntuacion);
    void setReservas(const unsigned short reservas[], unsigned short cantidad);

    // Métodos adicionales
    bool reservar();
    bool anularReserva(unsigned short codigo);
};

#endif // HUESPED_H
