#ifndef RESERVA_H
#define RESERVA_H

class Reserva {
private:
    unsigned int codigo;      // código de la reserva sficiente todos los clientes en todo el ano
    unsigned short alojamiento; // id alojamiento
    char* huesped;           // cc o passport number (en emiratos 15char)
    unsigned short num_noches;  // Duración de la estancia
    unsigned int fecha_i;     // AAAA/MM/DD
    bool pago;                  // true = PSE, false = tarjeta
    unsigned int fecha_pago;   // fecha del pago (0:4 dia, 5:8 mes, 9:20 año)
    unsigned int precio;
    char* comentarios;

public:
    Reserva();
    Reserva(const Reserva &otra);
    ~Reserva();

    // Sobrecarga de operadores
    Reserva& operator=(const Reserva& otro);

    // Getters
    unsigned short getCodigo() const;
    unsigned short getIdAlojamiento() const;
    const char* getIdHuesped() const;
    unsigned short getNumNoches() const;
    unsigned int getFechaInicio() const;
    bool getMetodoPago() const;
    unsigned int getFechaPago() const;
    unsigned int getPrecio() const;
    const char* getComentarios() const;

    // Setters
    void setCodigo(unsigned int codigo);
    void setIdAlojamiento(unsigned short alojamiento);
    void setIdHuesped(const char huesped[]);
    void setNumNoches(unsigned short num_noches);
    void setFechaInicio(unsigned int fecha_i);
    void setMetodoPago(bool pago);              //sobrecargar!!!
    void setFechaPago(unsigned int fecha_pago);
    void setPrecio(unsigned int precio);
    void setComentarios(const char comentarios[]);

    void resetReserva();
};

#endif // RESERVA_H
