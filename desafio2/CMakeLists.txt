cmake_minimum_required(VERSION 3.16)

project(desafio2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(desafio2 main.cpp
    huesped.h huesped.cpp
    anfitrion.h anfitrion.cpp
    alojamiento.h alojamiento.cpp
    reserva.h reserva.cpp
    administrador.h administrador.cpp
    interfaz.h interfaz.cpp
    sistema.h sistema.cpp
    administrador.h administrador.cpp
    idManager.h idManager.cpp)

include(GNUInstallDirs)
install(TARGETS desafio2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
