#include <iostream>

#include "huesped.h"

// Constructor por defecto
Huesped::Huesped() : antiguedad(0), puntuacion(0)
{
    id = new char[16]();   //el parentesis inicializa a \0
    reservas = new Reserva[365]();
}

// Constructor de copia
Huesped::Huesped(const Huesped &otro)
{
    id = new char[16];
    reservas = new Reserva[365];

    unsigned short i = 0;
    for(i = 0; i < 16; i++){ id[i] = otro.id[i]; }
    antiguedad = otro.antiguedad;
    puntuacion = otro.puntuacion;
    for(i = 0; i < 365; i++){ reservas[i] = otro.reservas[i]; }
}

// Destructor
Huesped::~Huesped()
{
    delete[] id;
    delete[] reservas;
}

// Sobreacarga de Operadores
Huesped& Huesped::operator=(const Huesped& otro) {
    // evitar a = a;
    if(this == &otro){ return *this; }

    // liberar los apuntadores dinámicos
    delete[] id;
    delete[] reservas;

    id = new char[16];
    reservas = new Reserva[365];

    unsigned short i = 0;
    for(i = 0; i < 16; i++){ id[i] = otro.id[i]; }
    antiguedad = otro.antiguedad;
    puntuacion = otro.puntuacion;
    for(i = 0; i < 365; i++){ reservas[i] = otro.reservas[i]; }

    return *this;
}

// Getters
const char* Huesped::getId() const { return id; }
unsigned short Huesped::getAntiguedad() const { return antiguedad; }
unsigned short Huesped::getPuntuacion() const { return puntuacion; }
Reserva* Huesped::getReservas() { return reservas; }

// Setters
void Huesped::setId(const char id[])
{
    unsigned short i = 0;
    for(i = 0; i < 16; i++)
    {
        if(id[i] == '\0'){ break; }    //frena al llegar a caracter nulo
        this->id[i] = id[i];
    }
    for(i; i < 16; i++){ this->id[i] = '\0'; }
}
void Huesped::setAntiguedad(unsigned short antiguedad){ this->antiguedad = antiguedad; }
void Huesped::setPuntuacion(unsigned short puntuacion){ this->puntuacion = puntuacion; }
void Huesped::setReservas(const Reserva reservas[])     // asegurar tamaño del arreglo desde fuera!!
{
    unsigned short i = 0;
    for(i = 0; i < 365; i++)
    {
        //if(reservas[i].getCodigo() == 0){ break; }
        this->reservas[i] = reservas[i];
    }
    //for(i; i < 365; i++){ this->reservas[i] = Reserva(); }
}

// Métodos adicionales
short Huesped::reservar(Alojamiento& alojamiento, unsigned short codigo,
    unsigned short num_noches, unsigned int fecha_i, unsigned int fecha_pago)   // fecha pago = fecha hoy
{
    // Pide datos basicos para la reserva (fecha inicio, numero de días, municipio)
    // Muestra alojamientos que cumplan (itera comparando condiciones) y opción de aplicar filtros
        // si aplica filtros, muestra nuevas opciones (iterando again)
    // ingresa la opción el usuario
    // se rectifica disponibilidad (de huesped y alojameinto)
                /*   Hasta aquí, hacer afuera   */
    bool pago;
    char* comentarios = new char[1001];
    // recibe si tarjeta o que
    pago = true;    // dummy
    // recibe comentarios
    // std::cout << "Ingrese su comentario (máx. 1000 caracteres): ";    // dummy
    // std::cin.getline(comentarios, 1001);    // dummy
    // dummy
    const char* temp = "Me gustaría confirmar una reservación para [fecha y hora] en su establecimiento. Agradecería que la mesa esté ubicada en un área tranquila, preferiblemente con buena iluminación y lejos de la cocina o la entrada principal, si es posible. También quisiera saber si ofrecen opciones en el menú para personas con restricciones alimentarias, ya que uno de los asistentes tiene alergias específicas. Agradecería cualquier recomendación que puedan hacer al respecto. Además, si cuentan con opciones de estacionamiento cercanas, agradecería detalles sobre disponibilidad y tarifas. Espero su confirmación y quedo atento a cualquier información adicional que puedan proporcionar. ¡Gracias!";   // dummy
    for (size_t i = 0; i < 1000 && temp[i] != '\0'; i++) {   // dummy
        comentarios[i] = temp[i];
    }
    comentarios[1000] = '\0';   // dummy
    // dummy
    unsigned short i = 0;
    for(i = 0; i < 365; i++)
    {
        if(this->getReservas()[i].getCodigo() == 0){ break; }
    }
    if(i == 365){ return -1;}   // no tiene días libres para reservar
    unsigned short j = 0;
    for(j = 0; j < 365; j++)
    {
        if(alojamiento.getReservas()[j] == nullptr){ break; }
    }
    if(j == 365){ return -2;}   // no tiene días libres para reservar

    this->getReservas()[i].setCodigo(001100);     // dummy (el código se debe generar)
    this->getReservas()[i].setComentarios(comentarios);     delete[] comentarios;
    this->getReservas()[i].setFechaInicio(fecha_i);
    this->getReservas()[i].setFechaPago(fecha_pago);
    this->getReservas()[i].setIdAlojamiento(alojamiento.getId());
    this->getReservas()[i].setIdHuesped(this->getId());
    this->getReservas()[i].setMetodoPago(pago);
    this->getReservas()[i].setNumNoches(num_noches);
    this->getReservas()[i].setPrecio((alojamiento.getPrecio())*num_noches);
    alojamiento.getReservas()[j] = &(this->getReservas()[i]);

    return 0;
}

short Huesped::anularReserva(Anfitrion* const anfitriones[])
{
    // muestra por consola al usuario todas las reservas de este huesped (iterar reservas)
    unsigned int fecha_aux = 00000000;
    unsigned short cnt = 0;

    for(unsigned short j = 0; j < 365; j++)
    {
        if(this->getReservas()[j].getCodigo() != 0)
        {
            fecha_aux = this->getReservas()[j].getFechaInicio();
            cnt++;
            //mostrarReserva(this->getReservas()[j])
            unsigned short code = this->getReservas()[j].getCodigo();
            std::cout << cnt << ". Reserva encontrada el " << fecha_aux << " con codigo: " << code << std::endl;    //dummy
            // si queda tiempo, implementar un organizador en orden de fechas de los indices para imprimir en orden
        }
    }
    if(cnt == 0){ return -1; }
    unsigned short n = 0;
    do{
        // recibir numero de reserva (n segun cnt)
        n = 1;  //dummy
        // cin no funciona correctamente (creashea porque le da la gana)
        //std::cout << "\nIngrese el numero de la reserva a anular: ";
        //std::cin >> n; // Lee el número ingresado por el usuario
    } while(n > cnt);
    cnt = 0;

    unsigned short j = 0;
    for(j = 0; j < 365; j++)
    {
        if(this->getReservas()[j].getCodigo() != 0)
        {
            cnt++;
            if(cnt == n){ ; break; }
        }
    }
    unsigned short alojamiento = this->getReservas()[j].getIdAlojamiento();
    unsigned short codigo = this->getReservas()[j].getCodigo();
    //Reserva* pedro = &this->getReservas()[j];//getCodigo();

    unsigned short alojamiento_aux = 0;
    unsigned short codigo_aux = 0;

    if(anfitriones[0]->getId() == 0){ return -1; }
    for(unsigned short i = 0; i < 2000; i++)
    {
        if(anfitriones[i]->getId() == 0){ break; }
        for(unsigned short j = 0; j < 50; j++)
        {
            if(anfitriones[i]->getAlojamientos()[j].getId() == 0){ break; }
            alojamiento_aux = anfitriones[i]->getAlojamientos()[j].getId();
            if(alojamiento_aux == alojamiento)
            {
                for(unsigned short k = 0; k < 365; k++)
                {
                    codigo_aux = anfitriones[i]->getAlojamientos()[j].getReservas()[k]->getCodigo();
                    if(codigo_aux == codigo)
                    {
                        //Reserva* juan = anfitriones[i]->getAlojamientos()[j].getReservas()[k];
                        anfitriones[i]->getAlojamientos()[j].getReservas()[k] = nullptr;
                        this->getReservas()[j].resetReserva();
                        //juan = anfitriones[i]->getAlojamientos()[j].getReservas()[k];
                        return 0;
                    }
                }
            }
        }
    }
    return -2;
}
