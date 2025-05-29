#include "sistema.h"
#include <iostream>
#include <fstream>
#include <sstream>


Huesped g_huespedes[MAX_HUESPEDES];
unsigned int g_numHuespedes = 0;

std::string g_huespedes_codigos_reservas_str[MAX_HUESPEDES];

Anfitrion g_anfitriones[MAX_ANFITRIONES];
unsigned int g_numAnfitriones = 0;

Alojamiento g_alojamientos[MAX_ALOJAMIENTOS];
unsigned int g_numAlojamientos = 0;

Reserva g_reservasVigentes[MAX_RESERVAS];
unsigned int g_numReservasVigentes = 0;

Reserva g_reservasHistoricas[MAX_RESERVAS];
unsigned int g_numReservasHistoricas = 0;

const char* HUESPEDES_FILE_PATH = "Data/Huespedes.txt";
const char* ANFITRIONES_FILE_PATH = "Data/Anfitriones.txt";
const char* ALOJAMIENTOS_FILE_PATH = "Data/Alojamientos.txt";
const char* RESERVAS_VIGENTES_FILE_PATH = "Data/Reservas_Actuales.txt";
const char* RESERVAS_HISTORICAS_FILE_PATH = "Data/Reservas_Historicas.txt";


unsigned int leerEntradaInt(const char* mensaje) {
    unsigned int valor;
    while (true) {
        std::cout << mensaje;
        std::cin >> valor;
        return valor; 
    }

}


float leerEntradaFloat(const char* mensaje) {
    float valor;
    while (true) {
        std::cout << mensaje;
        std::cin >> valor;
        return valor;
    }
    
}


void leerEntradaTexto(const char* mensaje, char* bufferDestino, int bufferSize, bool permitirVacio) {
    if (bufferSize <= 0) return;
    while (true) {
        std::cout << mensaje;
        std::cin.getline(bufferDestino, bufferSize);

        if (std::cin.good()) {
            if (!permitirVacio && bufferDestino[0] == '\0') {
                std::cout << "La entrada no puede estar vacía. Intente de nuevo." << std::endl;
                
            } else {
                return;
            }
        } else {             std::cout << "Error de entrada o línea demasiado larga. Intente de nuevo." << std::endl;
            std::cin.clear();
            
        }
    }
}



unsigned int leerEntradaFecha(const char* mensaje) {
    unsigned int valor;
    long long valor_largo; 
    std::string temp_str;

    while (true) {
        std::cout << mensaje << " (YYYYMMDD): ";
        std::cin >> temp_str; 
        
        bool soloDigitos = true;
        if (temp_str.length() == 8) {
            for (char const &c : temp_str) {
                if (!std::isdigit(c)) {
                    soloDigitos = false;
                    break;
                }
            }
            if (soloDigitos) {
                try {
                    valor = std::stoul(temp_str); 
                    return valor;
                } catch (const std::out_of_range& oor) {
                    std::cout << "Fecha fuera de rango. Intente de nuevo." << std::endl;
                } catch (const std::invalid_argument& ia) {
                    std::cout << "Formato de fecha inválido. Intente de nuevo." << std::endl;
                } catch (...) {
                    std::cout << "Error desconocido al procesar la fecha. Intente de nuevo." << std::endl;
                    
                }
            }
        }
        
        std::cout << "Formato incorrecto. Debe ser YYYYMMDD (8 dígitos). Intente de nuevo." << std::endl;
        if (std::cin.fail()) {
            std::cin.clear();
        }
    }
}


void leerEntradaMetodoPago(const char* mensaje, char* bufferDestino, int bufferSize) {
    std::string entrada_str;
    while (true) {
        std::cout << mensaje << " (PSE/TCredito): ";
        std::cin >> entrada_str;

        if (entrada_str == "PSE" || entrada_str== "TCREDITO") {
            std::string valorCanonica = (entrada_str == "PSE") ? "PSE" : "TCredito";
            
            
            unsigned int i = 0;
            
            while (i < bufferSize - 1 && valorCanonica[i] != '\0') {
                bufferDestino[i] = valorCanonica[i];
                i++;
            }
            bufferDestino[i] = '\0'; 

            return;
        }
        std::cout << "Método de pago inválido. Ingrese PSE o TCredito." << std::endl;
        if (std::cin.fail()) { 
            std::cin.clear();
        }
    }
}
Reserva* encontrarReservaPorCodigo(unsigned int codigoReserva) {
    for (unsigned int i = 0; i < g_numReservasVigentes; ++i) {
        if (g_reservasVigentes[i].getCodigo() == codigoReserva) {
            return &g_reservasVigentes[i];
        }
    }
    for (unsigned int i = 0; i < g_numReservasHistoricas; ++i) {
        if (g_reservasHistoricas[i].getCodigo() == codigoReserva) {
            return &g_reservasHistoricas[i];
        }
    }
    return nullptr;
}

void cargarDatos() {

    g_numHuespedes = 0;
    g_numAnfitriones = 0;
    g_numAlojamientos = 0;
    g_numReservasVigentes = 0;
    g_numReservasHistoricas = 0;

    std::ifstream archivo;
    std::string linea;
    std::string campo;
    const char DELIMITER_PRINCIPAL = '|';

    archivo.open(HUESPEDES_FILE_PATH); 
    if (archivo.is_open()) {
        while (g_numHuespedes < MAX_HUESPEDES && std::getline(archivo, linea)) {
            if (linea.empty() || linea[0] == '#') continue;
            std::istringstream ss_linea(linea);
            Huesped tempHuesped;
            unsigned short camposLeidos = 0;
            try {
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempHuesped.setId(campo.c_str()); camposLeidos++; }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempHuesped.setAntiguedad(static_cast<unsigned short>(std::stoul(campo))); camposLeidos++; }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempHuesped.setPuntuacion(static_cast<unsigned short>(std::stoul(campo))); camposLeidos++; } 
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) {
                    std::stringstream ss_reservas(campo);std::string subcampo;
    
                    Reserva reservas[365];  
                    int index = 0;

                    while (std::getline(ss_reservas, subcampo, ';') && index < 365) {
                        unsigned short codigo = static_cast<unsigned short>(std::stoul(subcampo));
                        Reserva r;
                        r.setCodigo(codigo);  
                    reservas[index++] = r;
                   }

                    tempHuesped.setReservas(reservas);  
                    camposLeidos++;}
                if (camposLeidos >= 3) { 
                    g_huespedes[g_numHuespedes++] = tempHuesped;
                } 

                else {
                    std::cerr << "Advertencia: Línea Huesped malformada: " << linea << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << "Error procesando Huesped: " << linea << " - Campo problemático aprox.: '" << campo << "' - Error: " << e.what() << std::endl;
            }
        }
        archivo.close();
        std::cout << g_numHuespedes << " huéspedes cargados." << std::endl;
    } else {
        std::cout << "Advertencia: No se pudo abrir " << HUESPEDES_FILE_PATH << std::endl;
    }

    archivo.open(ANFITRIONES_FILE_PATH); 
    if (archivo.is_open()) {
        while (g_numAnfitriones < MAX_ANFITRIONES && std::getline(archivo, linea)) {

            if (linea.empty() || linea[0] == '#') continue;
            std::istringstream ss_linea(linea);
            Anfitrion tempAnfitrion;
            int camposLeidos = 0;
            try {
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempAnfitrion.setId(campo.c_str()); camposLeidos++; }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempAnfitrion.setAntiguedad(static_cast<unsigned short>(std::stoul(campo))); camposLeidos++; }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempAnfitrion.setPuntuacion(static_cast<unsigned short>(std::stoul(campo))); camposLeidos++; } // Clase usa unsigned short
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) {
                    std::stringstream ss_alojamientos(campo); std::string subcampo;

                    Alojamiento alojamientos[50];  // Puedes ajustar este tamaño si lo deseas
                    int index = 0;

                    while (std::getline(ss_alojamientos, subcampo, ';') && index < 50) {
                        unsigned short idAlojamiento = static_cast<unsigned short>(std::stoul(subcampo));
                        Alojamiento a;
                        a.setId(idAlojamiento);  // Asegúrate que Alojamiento tenga este método
                        alojamientos[index++] = a;
                    }

                    tempAnfitrion.setAlojamientos(alojamientos);  // Pasa el arreglo a la función
                    camposLeidos++;
                }
                if (camposLeidos >= 3) {
                    g_anfitriones[g_numAnfitriones++] = tempAnfitrion;
                } else {
                    std::cerr << "Advertencia: Línea Anfitrion malformada: " << linea << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << "Error procesando Anfitrion: " << linea << " - Campo problemático aprox.: '" << campo << "' - Error: " << e.what() << std::endl;
            }
        }
        archivo.close();
        std::cout << g_numAnfitriones << " anfitriones cargados." << std::endl;
    } else {
        std::cout << "Advertencia: No se pudo abrir " << ANFITRIONES_FILE_PATH << std::endl;
    }


    archivo.open(ALOJAMIENTOS_FILE_PATH); 
    if (archivo.is_open()) {
        while (g_numAlojamientos < MAX_ALOJAMIENTOS && std::getline(archivo, linea)) {

            if (linea.empty() || linea[0] == '#') continue;
            std::istringstream ss_linea(linea);
            Alojamiento tempAlojamiento;
            int camposLeidos = 0;
            try {
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempAlojamiento.setId(static_cast<unsigned short>(std::stoul(campo))); camposLeidos++; }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempAlojamiento.setNombre(campo.c_str()); camposLeidos++; }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempAlojamiento.setAnfitrion(campo.c_str()); camposLeidos++; }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempAlojamiento.setDepartamento(campo.c_str()); camposLeidos++; }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempAlojamiento.setMunicipio(campo.c_str()); camposLeidos++; }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { 
                    bool tipo_bool = false; 
                    
                    if (campo == "casa") tipo_bool = true;
                    else if (campo == "apartamento") tipo_bool = false;
                    tempAlojamiento.setTipo(tipo_bool);
                    camposLeidos++;
                }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempAlojamiento.setDireccion(campo.c_str()); camposLeidos++; }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempAlojamiento.setPrecio(std::stoul(campo)); camposLeidos++; }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { 
                    bool amenidades[6] = {false}; 
                    std::stringstream ss_amenidades(campo);
                    std::string subcampo;
                    int index = 0;

                    while (std::getline(ss_amenidades, subcampo, ';') && index < 10) {
                        if (subcampo == "true") {
                            amenidades[index++] = true;
                        } else if (subcampo == "false") {
                            amenidades[index++] = false;
                        } else {
                            std::cerr << "Advertencia: Amenidad desconocida '" << subcampo << "' en línea: " << linea << std::endl;
                        }
                    }
                    tempAlojamiento.setAmenidades(amenidades);
                    camposLeidos++;
                }
                if (camposLeidos >= 9) { 
                    g_alojamientos[g_numAlojamientos++] = tempAlojamiento;
                } else {
                    std::cerr << "Advertencia: Línea Alojamiento malformada: " << linea << std::endl;
                }
            } catch (const std::exception& e) {
                std::cerr << "Error procesando Alojamiento: " << linea << " - Campo problemático aprox.: '" << campo << "' - Error: " << e.what() << std::endl;
            }
        }
        archivo.close();
        std::cout << g_numAlojamientos << " alojamientos cargados." << std::endl;
    } else {
        std::cout << "Advertencia: No se pudo abrir " << ALOJAMIENTOS_FILE_PATH << std::endl;
    }


    auto cargarArchivoReservas = [&](const char* nombreArchivoFS, Reserva* arrayReservas, unsigned int& contadorReservas, unsigned int maxReservasFS, const std::string& tipoReservaStr) {
        std::ifstream archivoFS(nombreArchivoFS);
        if (archivoFS.is_open()) {
            std::string lineaFS, campoFS;
            while (contadorReservas < maxReservasFS && std::getline(archivoFS, lineaFS)) {
                
                if (lineaFS.empty() || lineaFS[0] == '#') continue;
                std::istringstream ss_linea_res(lineaFS);
                Reserva tempReserva;
                int camposLeidos = 0;
                try {
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setCodigo(std::stoul(campoFS)); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setIdAlojamiento(static_cast<unsigned short>(std::stoul(campoFS))); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setIdHuesped(campoFS.c_str()); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setFechaInicio(std::stoul(campoFS)); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setNumNoches(static_cast<unsigned short>(std::stoul(campoFS))); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { 
                        bool pago_bool = false; 
                        if (campoFS == "PSE") pago_bool = true;
                        else if (campoFS == "TCREDITO" || campoFS == "TARJETA") pago_bool = false; 
                        tempReserva.setMetodoPago(pago_bool);
                        camposLeidos++;
                    }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setFechaPago(std::stoul(campoFS)); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setPrecio(std::stoul(campoFS)); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS)) { tempReserva.setComentarios(campoFS.c_str()); camposLeidos++; }

                    if (camposLeidos >= 8) { 
                        arrayReservas[contadorReservas++] = tempReserva;
                    } else {
                        std::cerr << "Advertencia: Línea Reserva malformada en " << nombreArchivoFS << ": " << lineaFS << std::endl;
                    }
                } catch (const std::exception& e) {
                    std::cerr << "Error procesando Reserva en " << nombreArchivoFS << ": " << lineaFS << " - Campo problemático aprox.: '" << campoFS << "' - Error: " << e.what() << std::endl;
                }
            }
            archivoFS.close();
            std::cout << contadorReservas << " reservas " << tipoReservaStr << " cargadas." << std::endl;
        } else {
            std::cout << "Advertencia: No se pudo abrir " << nombreArchivoFS << std::endl;
        }
    };

    
    cargarArchivoReservas(RESERVAS_VIGENTES_FILE_PATH, g_reservasVigentes, g_numReservasVigentes, MAX_RESERVAS, "vigentes");
    

    cargarArchivoReservas(RESERVAS_HISTORICAS_FILE_PATH, g_reservasHistoricas, g_numReservasHistoricas, MAX_RESERVAS, "históricas");
    

    
}

bool sonIdentificadoresIguales(const char* id1, const char* id2) {
    if (!id1 || !id2) { 
        return id1 == id2; 
    }
    int i = 0;
    while (id1[i] != '\0' && id2[i] != '\0') {
        if (id1[i] != id2[i]) {
            return false; 
        }
        i++;
    }
    
    return (id1[i] == '\0' && id2[i] == '\0');
}



Huesped* iniciarSesionHuesped() {
    char idIngresado[4]; 
    leerEntradaTexto("Ingrese su ID de huésped: ", idIngresado, sizeof(idIngresado));

    for (unsigned int i = 0; i < g_numHuespedes; ++i) {
        
        if (sonIdentificadoresIguales(g_huespedes[i].getId(), idIngresado)) { 
            std::cout << "Inicio de sesión exitoso como huésped." << std::endl;
            return &g_huespedes[i]; 
        }
    }
    std::cout << "ID de huésped no encontrado." << std::endl;
    return nullptr; // No se encontró el huésped
}

Anfitrion* iniciarSesionAnfitrion() {
    char idIngresado[21]; 
    leerEntradaTexto("Ingrese su ID de anfitrión: ", idIngresado, sizeof(idIngresado));

    for (unsigned int i = 0; i < g_numAnfitriones; ++i) {
        if (sonIdentificadoresIguales(g_anfitriones[i].getId(), idIngresado)) { 
            std::cout << "Inicio de sesión exitoso como anfitrión." << std::endl;
            return &g_anfitriones[i]; // Devuelve un puntero al anfitrión encontrado
        }
    }
    std::cout << "ID de anfitrión no encontrado." << std::endl;
    return nullptr; // No se encontró el anfitrión
}
