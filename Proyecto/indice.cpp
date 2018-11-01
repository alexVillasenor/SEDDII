#include "indice.h"

int Indice::getCodigo() const
{
    return codigo;
}

void Indice::setCodigo(int value)
{
    codigo = value;
}

long Indice::getDireccion() const
{
    return direccion;
}

void Indice::setDireccion(long value)
{
    direccion = value;
}

Indice &Indice::operator =(const Indice &i)
{
    codigo=i.codigo;
    direccion=i.direccion;
    return *this;
}

bool Indice::operator ==(const Indice &i)
{
    return codigo == i.codigo;
}

bool Indice::operator !=(const Indice &i)
{
    return codigo != i.codigo;
}

bool Indice::operator <=(const Indice &i)
{
    return codigo <= i.codigo;
}

bool Indice::operator <(const Indice &i)
{
    return codigo < i.codigo;
}

bool Indice::operator >=(const Indice &i)
{
    return codigo >= i.codigo;
}

bool Indice::operator >(const Indice &i)
{
    return codigo > i.codigo;
}

Indice::Indice()
{

}
