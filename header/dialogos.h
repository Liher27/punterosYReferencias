#ifndef HEADER_DIALOGOS
#define HEADER_DIALOGOS
#include "contacto.h"
#include <string_view>
#include <vector>

void pintarMenu(int &operacion);
void verContactos(std::vector<Contacto> *contactos);
void pedirDatosContacto(Contacto &contacto);
void pedirDatosContacto(int& numeroTelefono, std::string& nombreContacto);

namespace constantesNumericas
{
    constexpr int opcionUnoInt{1};
    constexpr int opcionDosInt{2};
    constexpr int opcionTresInt{3};
    constexpr int opcionCuatroInt{4};
    constexpr int opcionCincoInt{5};
}

namespace literales
{
    constexpr std::string_view tituloAppSV{"=== AGENDA DE CONTACTOS ==="};
    constexpr std::string_view tituloContactosSV{"=== CONTACTOS ==="};
    constexpr std::string_view tituloAñadirSV{"=== AÑADIR ==="};
    constexpr std::string_view tituloModificarSV{"=== MODIFICAR ==="};
    constexpr std::string_view tituloBuscarSV{"=== BUSCAR ==="};

    constexpr std::string_view opcionUnoSV{"1. Ver contactos"};
    constexpr std::string_view opcionDosSV{"2. Añadir contacto"};
    constexpr std::string_view opcionTresSV{"3. Modificar contacto"};
    constexpr std::string_view opcionCuatroSV{"4. Buscar contacto"};
    constexpr std::string_view opcionCincoSV{"5. Salir"};

    constexpr std::string_view seleccionarOpcionSV{"Seleccione una opción: "};

    constexpr std::string_view errorInputSV{"Opción no válida."};
    constexpr std::string_view despedidaSV{"Sayonara baby"};
}
#endif
