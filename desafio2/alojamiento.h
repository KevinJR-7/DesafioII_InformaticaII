#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

class Alojamiento {
private:
    char* nombre;
    unsigned short id;      // 65,535 es superior a 12,000(max. airbnb en medellín)
    char* anfitrion;     // cc o passport number (en emiratos 15char)\0
    char* departamento;   // antioquia \0
    char* municipio;   // antioquia \0
    bool tipo;              // true = casa, false = apartamento
    char* direccion;
    unsigned int precio;    // en airbnb max precio 10millones
    bool* amenidades;    // amenidades por definir
    bool* fechas;       // Disponibilidad por noches

public:
    Alojamiento();
    Alojamiento(const Alojamiento &otro);
    ~Alojamiento();

    // Getters
    const char* getNombre() const;  // nopuede modificar los atributos de this
    unsigned short getId() const;
    const char* getAnfitrion() const;
    const char* getDepartamento() const;
    const char* getMunicipio() const;
    bool getTipo() const;
    const char* getDireccion() const;
    unsigned int getPrecio() const;
    const bool* getAmenidades() const;
    const bool* getFechas() const;

    // Setters
    void setNombre(const char nombre[]);
    void setId(unsigned short id);
    void setAnfitrion(const char anfitrion[]);
    void setDepartamento(const char departamento[]);
    void setMunicipio(const char municipio[]);
    void setTipo(bool tipo);
    void setDireccion(const char direccion[]);
    void setPrecio(unsigned int precio);
    void setAmenidades(const bool amenidades[]);
    void setFechas(const bool fechas[]);
};

#endif // ALOJAMIENTO_H
