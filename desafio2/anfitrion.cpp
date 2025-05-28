#include "anfitrion.h"
#include <iostream>

#include "idManager.h"

// Constructor
Anfitrion::Anfitrion() : antiguedad(0), puntuacion(0)
{
    id = new char[16]();   //el parentesis inicializa a \0
    alojamientos = new Alojamiento[50]();
}

// Constructor de copia
Anfitrion::Anfitrion(const Anfitrion &otro)
{
    id = new char[16];
    alojamientos = new Alojamiento[50];

    unsigned short i = 0;
    for(i = 0; i < 16; i++){ id[i] = otro.id[i]; }
    antiguedad = otro.antiguedad;
    puntuacion = otro.puntuacion;
    for(i = 0; i < 50; i++){ alojamientos[i] = otro.alojamientos[i]; }
}

// Destructor
Anfitrion::~Anfitrion()
{
    delete[] id;
    delete[] alojamientos;  // sobreacargado por c++
}

// Sobreacarga de Operadores
Anfitrion& Anfitrion::operator=(const Anfitrion& otro) {
    // evitar a = a;
    if(this == &otro){ return *this; }

    // liberar los apuntadores dinámicos
    delete[] id;
    delete[] alojamientos;  // sobreacargado por c++

    id = new char[16];
    alojamientos = new Alojamiento[50];

    unsigned short i = 0;
    for(i = 0; i < 16; i++){ id[i] = otro.id[i]; }
    antiguedad = otro.antiguedad;
    puntuacion = otro.puntuacion;
    for(i = 0; i < 50; i++){ alojamientos[i] = otro.alojamientos[i]; }

    return *this;
}

// Getters
const char* Anfitrion::getId() const { return id; }
unsigned short Anfitrion::getAntiguedad() const { return antiguedad; }
unsigned short Anfitrion::getPuntuacion() const { return puntuacion; }
Alojamiento* Anfitrion::getAlojamientos() { return alojamientos; }

// Setters
void Anfitrion::setId(const char id[])
{
    unsigned short i = 0;
    for(i = 0; i < 16; i++)
    {
        if(id[i] == '\0'){ break; }    //frena al llegar a caracter nulo
        this->id[i] = id[i];
    }
    for(i; i < 16; i++){ this->id[i] = '\0'; }
}
void Anfitrion::setAntiguedad(unsigned short antiguedad){ this->antiguedad = antiguedad; }
void Anfitrion::setPuntuacion(unsigned short puntuacion){ this->puntuacion = puntuacion; }
void Anfitrion::setAlojamientos(const Alojamiento alojamientos[])    // necesario un alojamento 0 al final si son menos de 50
{
    unsigned short i = 0;
    for(i = 0; i < 50; i++)
    {
        if(alojamientos[i].getId() == 0){ break; }
        this->alojamientos[i] = alojamientos[i];
    }
    for(i; i < 50; i++){ this->alojamientos[i] = Alojamiento(); }
}

// Métodos adicionales
short Anfitrion::anularReserva(unsigned int fecha)  // fecha hoy
{
    // muestra por consola al usuario todas las reservas de este anfitrion (llamar a consultarReservas con fechas min y max)
    unsigned int fecha_i = fecha;
    unsigned int fecha_f = fecha + 00010000;
    unsigned short max = 0;
    if(this->consultarReservas(fecha_i, fecha_f, max) != 0){ return -1; }
    unsigned short n = 0;
    do{
        // recibir numero de reserva (cnt)
        n = 2;      //dummy
        // cin no funciona correctamente (creashea porque le da la gana)
        //std::cout << "\nIngrese el numero de la reserva a anular: ";
        //std::cin >> n; // Lee el número ingresado por el usuario
    } while(n > max);

    unsigned int fecha_aux = 00000000;
    unsigned short cnt = 0;
    unsigned short i = 0;
    unsigned short j = 0;
    for(i = 0; i < 50; i++)
    {
        if(this->alojamientos[i].getId() == 0){ break; }
        for(j = 0; j < 365; j++)
        {
            if(this->alojamientos[i].getReservas()[j] != nullptr)
            {
                fecha_aux = this->alojamientos[i].getReservas()[j]->getFechaInicio();
                if((fecha_aux > fecha_i) && (fecha_aux < fecha_f))
                {
                    cnt++;
                    if(cnt == n){ break; }
                }
            }
        }
        if(cnt == n){ break; }
    }

    this->alojamientos[i].getReservas()[j]->resetReserva();
    this->alojamientos[i].getReservas()[j] = nullptr;
    return 0;
}

short Anfitrion::consultarReservas(unsigned int fecha_i, unsigned int fecha_f, unsigned short& max) const     // rectificar que las fechas están dentro de 12meses
{
    unsigned int fecha_aux = 00000000;
    unsigned short cnt = 0;

    if(this->alojamientos[0].getId() == 0){ return -1; }
    for(unsigned short i = 0; i < 50; i++)
    {
        if(this->alojamientos[i].getId() == 0){ break; }
        for(unsigned short j = 0; j < 365; j++)
        {
            if(this->alojamientos[i].getReservas()[j] != nullptr)
            {
                fecha_aux = this->alojamientos[i].getReservas()[j]->getFechaInicio();
                if((fecha_aux > fecha_i) && (fecha_aux < fecha_f))
                {
                    cnt++;
                    //mostrarReserva(this->alojamientos[i].getReservas()[j])
                    unsigned short code = this->alojamientos[i].getReservas()[j]->getCodigo();
                    std::cout << cnt << ". Reserva encontrada el " << fecha_aux << " con codigo: " << code << std::endl;    //dummy
                    // si queda tiempo, implementar un organizador en orden de fechas de los indices para imprimir en orden
                }
            }
        }
    }
    if(cnt == 0){ return -2; }
    else{ max = cnt; return 0; }
}
short Anfitrion::consultarReservas(unsigned int fecha_i, unsigned int fecha_f) const     // rectificar que las fechas están dentro de 12meses
{
    unsigned int fecha_aux = 00000000;
    unsigned short cnt = 0;

    if(this->alojamientos[0].getId() == 0){ return -1; }
    for(unsigned short i = 0; i < 50; i++)
    {
        if(this->alojamientos[i].getId() == 0){ break; }
        for(unsigned short j = 0; j < 365; j++)
        {
            if(this->alojamientos[i].getReservas()[j] != nullptr)
            {
                fecha_aux = this->alojamientos[i].getReservas()[j]->getFechaInicio();
                if((fecha_aux > fecha_i) && (fecha_aux < fecha_f))
                {
                    cnt++;
                    //mostrarReserva(this->alojamientos[i].getReservas()[j])
                    unsigned short code = this->alojamientos[i].getReservas()[j]->getCodigo();
                    std::cout << cnt << ". Reserva encontrada el " << fecha_aux << " con codigo: " << code << std::endl;    //dummy
                    // si queda tiempo, implementar un organizador en orden de fechas de los indices para imprimir en orden
                }
            }
        }
    }
    if(cnt == 0){ return -2; }
    else{ return 0; }
}

// por probar
short Anfitrion::actualizarHistorico(Anfitrion* const anfitriones[], unsigned int &fecha_actual, unsigned int fecha_nueva) const
{
    // compara que fecha nueva para ver si es mayor que fecha actual
    if(fecha_nueva < fecha_actual){ return -1; }
    fecha_actual = fecha_nueva;

    unsigned int fecha_i_aux = 0;
    unsigned short num_noches_aux = 0;
    unsigned int fecha_f_aux = 0;
    unsigned int cnt = 0;

    if(anfitriones[0]->getId() == 0){ return -2; }
    for(unsigned short i = 0; i < 2000; i++)
    {
        if(anfitriones[i]->getId() == 0){ break; }
        for(unsigned short j = 0; j < 50; j++)
        {
            if(anfitriones[i]->getAlojamientos()[j].getId() == 0){ break; }
            for(unsigned short k = 0; k < 365; k++)
            {
                fecha_i_aux = anfitriones[i]->getAlojamientos()[j].getReservas()[k]->getFechaInicio();
                num_noches_aux = anfitriones[i]->getAlojamientos()[j].getReservas()[k]->getNumNoches();
                fecha_f_aux = fechaFinal(fecha_i_aux, num_noches_aux);
                if(fecha_f_aux < fecha_actual)
                {
                    cnt++;
                    // escribe en el final del archivo
                    // escribirHistorico(anfitriones[i]->getAlojamientos()[j].getReservas()[j])
                    anfitriones[i]->getAlojamientos()[j].getReservas()[j]->resetReserva();
                    anfitriones[i]->getAlojamientos()[j].getReservas()[j] = nullptr;
                }
            }
        }
    }
    if(cnt == 0){ return -3; }
    else{ return 0; }
}
