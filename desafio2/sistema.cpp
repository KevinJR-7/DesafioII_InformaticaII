#include "sistema.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>    // Para std::numeric_limits
#include <algorithm> // Para std::transform
#include <stdexcept> // Para std::invalid_argument, std::out_of_range

// --- Definiciones de Variables Globales ---
Huesped g_huespedes[MAX_HUESPEDES];
unsigned int g_numHuespedes = 0;

Anfitrion g_anfitriones[MAX_ANFITRIONES];
unsigned int g_numAnfitriones = 0;

Alojamiento g_alojamientos[MAX_ALOJAMIENTOS];
unsigned int g_numAlojamientos = 0;

Reserva g_reservasVigentes[MAX_RESERVAS];
unsigned int g_numReservasVigentes = 0;

Reserva g_reservasHistoricas[MAX_RESERVAS];
unsigned int g_numReservasHistoricas = 0;


// --- Definición de nombres de archivo ---
const char* HUESPEDES_FILE_PATH = "Data/huespedes.txt";
const char* ANFITRIONES_FILE_PATH = "Data/anfitriones.txt";
const char* ALOJAMIENTOS_FILE_PATH = "Data/alojamientos.txt";
const char* RESERVAS_VIGENTES_FILE_PATH = "Data/reservas_vigentes.txt";
const char* RESERVAS_HISTORICAS_FILE_PATH = "Data/reservas_historicas.txt";


unsigned int leerEntradaInt(const char* mensaje) {
    unsigned int valor;
    while (true) {
        std::cout << mensaje;
        std::cin >> valor;
        if (std::cin.good()) { 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            return valor;
        } else {
            std::cout << "Entrada inválida. Ingrese un número entero. Intente de nuevo." << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    }
}

float leerEntradaFloat(const char* mensaje) {
    float valor;
    while (true) {
        std::cout << mensaje;
        std::cin >> valor;
        if (std::cin.good()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        } else {
            std::cout << "Entrada inválida. Ingrese un número (ej: 3.14). Intente de nuevo." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
        }
    }
}


bool leerEntradaBool(const char* mensaje, const char* opcionVerdadera, const char* opcionFalsa) {
    std::string entrada_str;
    std::string strVerdadera(opcionVerdadera);
    std::string strFalsa(opcionFalsa);
    std::transform(strVerdadera.begin(), strVerdadera.end(), strVerdadera.begin(), ::tolower);
    std::transform(strFalsa.begin(), strFalsa.end(), strFalsa.begin(), ::tolower);

    while (true) {
        std::cout << mensaje << " (" << opcionVerdadera << "/" << opcionFalsa << "): ";
        std::cin >> entrada_str; 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        std::transform(entrada_str.begin(), entrada_str.end(), entrada_str.begin(), ::tolower);

        if (entrada_str == strVerdadera) return true;
        if (entrada_str == strFalsa) return false;
        
        std::cout << "Entrada inválida. Ingrese '" << opcionVerdadera << "' o '" << opcionFalsa << "'." << std::endl;
        
        if (std::cin.fail()) {
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
                    valor = std::stoul(temp_str); // Convertir string a unsigned int
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el resto de la línea
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }
}


void leerEntradaMetodoPago(const char* mensaje, char* bufferDestino, int bufferSize) {
    std::string entrada_str;
    while (true) {
        std::cout << mensaje << " (PSE/TCredito): ";
        std::cin >> entrada_str; 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        std::string temp_upper = entrada_str;
        std::transform(temp_upper.begin(), temp_upper.end(), temp_upper.begin(), ::toupper);

        if (temp_upper == "PSE" || temp_upper == "TCREDITO") {
            std::string valorCanonica = (temp_upper == "PSE") ? "PSE" : "TCredito";
            
            
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

// ... (includes y definiciones de variables globales como en la respuesta anterior) ...

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

    // --- 1. Cargar Huéspedes ---
    // Formato esperado: id|antiguedad_meses|puntuacion|lista_codigos_reservas_str
    archivo.open(HUESPEDES_FILE_PATH); // Asegúrate que HUESPEDES_FILE_PATH esté definido
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
                
                // Hace falta un setter en Huesped que acepte una cadena de códigos de reservas
                if (camposLeidos >= 3) { // Ajusta si todos los campos son obligatorios
                    g_huespedes[g_numHuespedes++] = tempHuesped;
                } else {
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

    // --- 2. Cargar Anfitriones ---
    // Formato esperado: id|antiguedad_meses|puntuacion|lista_codigos_alojamientos_str
    archivo.open(ANFITRIONES_FILE_PATH); // Asegúrate que ANFITRIONES_FILE_PATH esté definido
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


                
                // Hace falta un setter en Anfitrion que acepte una cadena de códigos de alojamientos
                
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

    // --- 3. Cargar Alojamientos ---
    // Formato: id|nombre|id_anfitrion_str|dpto|municipio|tipo_str|direccion|precio|amenidades_str|lista_reservas_asociadas_str
    archivo.open(ALOJAMIENTOS_FILE_PATH); // Asegúrate que ALOJAMIENTOS_FILE_PATH esté definido
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
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { // tipo_str
                    bool tipo_bool = false; // Default a apartamento
                    std::string tipo_str_lower = campo;
                    std::transform(tipo_str_lower.begin(), tipo_str_lower.end(), tipo_str_lower.begin(), ::tolower);
                    if (tipo_str_lower == "casa") tipo_bool = true;
                    else if (tipo_str_lower == "apartamento") tipo_bool = false;
                    // else { std::cerr << "Advertencia: Tipo de alojamiento desconocido '" << campo << "' en línea: " << linea << std::endl; }
                    tempAlojamiento.setTipo(tipo_bool);
                    camposLeidos++;
                }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempAlojamiento.setDireccion(campo.c_str()); camposLeidos++; }
                if (std::getline(ss_linea, campo, DELIMITER_PRINCIPAL)) { tempAlojamiento.setPrecio(std::stoul(campo)); camposLeidos++; }
                
                //Hace falta un setter en Alojamiento que acepte una cadena de amenidades
                // Hace falta un setter en Alojamiento que acepte una cadena de reservas asociadas
                
                if (camposLeidos >= 9) { // Ajusta
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

    // --- 4. Cargar Reservas (Vigentes e Históricas) ---
    auto cargarArchivoReservas = [&](const char* nombreArchivoFS, Reserva* arrayReservas, int& contadorReservas, int maxReservasFS, const std::string& tipoReservaStr) {
        std::ifstream archivoFS(nombreArchivoFS);
        if (archivoFS.is_open()) {
            std::string lineaFS, campoFS;
            while (contadorReservas < maxReservasFS && std::getline(archivoFS, lineaFS)) {
                
                if (lineaFS.empty() || lineaFS[0] == '#') continue;
                std::istringstream ss_linea_res(lineaFS);
                Reserva tempReserva;
                int camposLeidos = 0;
                try {
                    // Formato: codigo_r|codigo_a|doc_h|fecha_e|duracion|metodo_p_str|fecha_p|monto|anotaciones
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setCodigo(std::stoul(campoFS)); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setIdAlojamiento(static_cast<unsigned short>(std::stoul(campoFS))); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setIdHuesped(campoFS.c_str()); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setFechaInicio(std::stoul(campoFS)); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setNumNoches(static_cast<unsigned short>(std::stoul(campoFS))); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { // metodo_p_str
                        bool pago_bool = false; // Default a tarjeta (false)
                        std::string metodo_p_str_upper = campoFS;
                        std::transform(metodo_p_str_upper.begin(), metodo_p_str_upper.end(), metodo_p_str_upper.begin(), ::toupper);
                        if (metodo_p_str_upper == "PSE") pago_bool = true;
                        else if (metodo_p_str_upper == "TCREDITO" || metodo_p_str_upper == "TARJETA") pago_bool = false; // Asumiendo TCredito es tarjeta
                        // else { std::cerr << "Advertencia: Método de pago desconocido '" << campoFS << "' en línea: " << lineaFS << std::endl; }
                        tempReserva.setMetodoPago(pago_bool);
                        camposLeidos++;
                    }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setFechaPago(std::stoul(campoFS)); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS, DELIMITER_PRINCIPAL)) { tempReserva.setPrecio(std::stoul(campoFS)); camposLeidos++; }
                    if (std::getline(ss_linea_res, campoFS)) { tempReserva.setComentarios(campoFS.c_str()); camposLeidos++; }

                    if (camposLeidos >= 8) { // Ajusta
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


    
}
