#include "paredificios.h"

Edificio ParEdificios::getOrigen() const
{
    return origen;
}

void ParEdificios::setOrigen(const Edificio &value)
{
    origen = value;
}

Edificio ParEdificios::getDestino() const
{
    return destino;
}

void ParEdificios::setDestino(const Edificio &value)
{
    destino = value;
}

ParEdificios::ParEdificios()
{

}
