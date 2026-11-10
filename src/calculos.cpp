#include "calculos.h"
#include "dialogos.h"
#include <iostream>

Contacto *buscar(std::vector<Contacto> &contactos, const std::string_view *nombreContacto, const int *numeroContacto)
{
    for (Contacto &contacto : contactos)
    {
        if (contacto.nombreContacto == *nombreContacto && contacto.numero == *numeroContacto)
        {
            return &contacto;
        }
    }
    return nullptr;
}

void añadir(const Contacto *contacto, std::vector<Contacto> &contactos)
{
    if (!contacto)
    {
        std::cout << "error: no hay contacto a añadir. \n";
        return;
    }
    std::string_view nombreContacto{(*contacto).nombreContacto};

    if (buscar(contactos, &nombreContacto, &contacto->numero))
    {
        std::cout << "Ya existe ese contacto. \n";
        return;
    }
    contactos.push_back(*contacto);
    std::cout << "Contacto añadido correctamente! \n";
}

void modificar(Contacto * contacto, const Contacto* const contactoNuevo)
{
    if (!contacto)
    {
        std::cout << "No se ha encontrado ese contacto. \n";
        return;
    }
    (*contacto).nombreContacto = (*contactoNuevo).nombreContacto;
    (*contacto).numero = (*contactoNuevo).numero;
}
