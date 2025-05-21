#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

class Alojamiento {
private:
    char nombre[100];
    unsigned short id;      // 65,535 es superior a 12,000(max. airbnb en medellín)
    char anfitrion[110];    // nombre más largo + apellido más largo*2 = 107
    char departamento[9];   // antioquia
    char municipio[25];     // San Pedro de los Milagros
    bool tipo;              // true = casa, false = apartamento
    char direccion[100];
    unsigned int precio;    // en airbnb max precio 10millones
    bool amenidades[20];    // amenidades por definir
    bool fechas[365];       // Disponibilidad por noches

public:
    Alojamiento();

    // constructor de copia
    Alojamiento(const Alojamiento &otro);

    // Destructor
    ~Alojamiento();

    // Getters
    const char* getNombre() const;
    int getId() const;
    const char* getAnfitrion() const;
    const char* getDepartamento() const;
    const char* getMunicipio() const;
    bool getTipo() const;
    const char* getDireccion() const;
    float getPrecio() const;
    const bool* getAmenidades() const;
    const bool* getFechas() const;

    // Setters
    void setNombre(const char nombre[]);
    void setId(int id);
    void setAnfitrion(const char anfitrion[]);
    void setDepartamento(const char departamento[]);
    void setMunicipio(const char municipio[]);
    void setTipo(bool tipo);
    void setDireccion(const char direccion[]);
    void setPrecio(float precio);
    void setAmenidades(const bool amenidades[]);
    void setFechas(const bool fechas[]);
};

#endif // ALOJAMIENTO_H
