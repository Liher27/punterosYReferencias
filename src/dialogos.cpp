#include "dialogos.h"
#include "calculos.h"
#include <iostream>
#include <limits>

bool clearFailedExtraction();
void ignoreLine();

void pintarMenu(int &operacion)
{
    while (true)
    {
        if (clearFailedExtraction())
        {
            continue;
        }
        std::cout << "\n"
                  << literales::tituloAppSV << "\n";

        std::cout << literales::opcionUnoSV << "\n";
        std::cout << literales::opcionDosSV << "\n";
        std::cout << literales::opcionTresSV << "\n";
        std::cout << literales::opcionCuatroSV << "\n";
        std::cout << literales::opcionCincoSV << "\n";

        std::cin >> operacion;

        if (operacion == 1 || operacion == 2 || operacion == 3 || operacion == 4 || operacion == 5)
        {
            break;
        }
        else
        {
            std::cout << literales::errorInputSV << "\n";
        }
    }
}

void verContactos(std::vector<Contacto> *contactos)
{

    for (const Contacto &contacto : *contactos)
    {
        std::cout << "Nombre: " << contacto.nombreContacto << "\n";
        std::cout << "Número: " << contacto.numero << "\n";
    }
}

void pedirDatosContacto(Contacto &contacto)
{
    std::cout << "Nombre que deseas ponerle al contacto?: \n";
    std::cin >> contacto.nombreContacto;
    if (clearFailedExtraction())
    {
        std::cout << literales::errorInputSV << "\n";
        return;
    }
    std::cout << "Numero que deseas ponerle al contacto? \n";
    std::cin >> contacto.numero;
    if (clearFailedExtraction())
    {
        std::cout << literales::errorInputSV << "\n";
        return;
    }
}

void pedirDatosContacto(int &numeroTelefono, std::string &nombreContacto)
{
    std::cout << "Nombre del contacto que deseas buscar? \n";
    std::cin >> nombreContacto;
    if (clearFailedExtraction())
    {
        std::cout << literales::errorInputSV << "\n";
        return;
    }
    std::cout << "Numero del contacto que deseas buscar? \n";
    std::cin >> numeroTelefono;
    if (clearFailedExtraction())
    {
        std::cout << literales::errorInputSV << "\n";
        return;
    }
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            std::exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }

    return false;
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
