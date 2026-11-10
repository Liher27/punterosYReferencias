#ifndef CALCULOS_HEADER
#define CALCULOS_HEADER
#include "contacto.h"
#include <vector>

Contacto *buscar(std::vector<Contacto> &contactos, const std::string_view *nombreContacto, const int *numeroContacto);
void añadir(const Contacto *contacto, std::vector<Contacto> &contactos);
void modificar(Contacto *contacto);

#endif
