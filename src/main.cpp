#include "dialogos.h"
#include "calculos.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<Contacto> contactos{};
    int opcion{};
    bool bucle{true};
    while (bucle)
    {

        pintarMenu(opcion);
        switch (opcion)
        {
        case constantesNumericas::opcionUnoInt:
        {

            if (contactos.empty())
            {
                std::cout << "No hay contactos. \n";
                break;
            }
            std::cout << literales::tituloContactosSV << "\n";
            verContactos(&contactos);
            break;
        }
        case constantesNumericas::opcionDosInt:
        {
            // Añadir contactos
            std::cout << literales::tituloAñadirSV << "\n";

            Contacto contactoNuevo{};
            pedirDatosContacto(contactoNuevo);
            if (contactoNuevo.nombreContacto != "" && contactoNuevo.numero != 0)
                añadir(&contactoNuevo, contactos);
            break;
        }
        case constantesNumericas::opcionTresInt:
        {
            if (contactos.empty())
            {
                std::cout << "No hay contactos. \n";
                break;
            }
            std::cout << literales::tituloModificarSV << "\n";
            // Modificar un contacto
            int numeroTelefono{};
            std::string nombreContacto{};

            pedirDatosContacto(numeroTelefono, nombreContacto);

            std::string_view nombreContactoSV{nombreContacto};
            Contacto* contacto {buscar(contactos, &nombreContactoSV, &numeroTelefono)};
            if (contacto){
            std::cout << "Contacto encontrado! \n";
            Contacto contactoNuevo {};
            pedirDatosContacto(contactoNuevo);
            modificar(contacto);
            }
            break;
        }
        case constantesNumericas::opcionCuatroInt:
        {
            if (contactos.empty())
            {
                std::cout << "No hay contactos. \n";
                break;
            }
            std::cout << literales::tituloBuscarSV << "\n";
            int numeroTelefono{};
            std::string nombreContacto{};

            pedirDatosContacto(numeroTelefono, nombreContacto);

            std::string_view nombreContactoSV{nombreContacto};
            Contacto *contactoEncontrado{buscar(contactos, &nombreContactoSV, &numeroTelefono)};
            if (contactoEncontrado)
            {
                std::cout << "Contacto encontrado! \n";

                std::cout << "Nombre del contacto: " << contactoEncontrado->nombreContacto << "\n";
                std::cout << "Numero del contacto: " << contactoEncontrado->numero << "\n";
            }
            break;
        }
        case constantesNumericas::opcionCincoInt:
            bucle = false;
            break;
        default:
            std::cout << literales::errorInputSV;
            break;
        }
    }

    std::cout << literales::despedidaSV << "\n";
    return 0;
}
