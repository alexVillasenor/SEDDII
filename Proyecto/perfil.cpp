#include "perfil.h"

QString Perfil::getCodPerfil() const
{
    return codPerfil;
}

void Perfil::setCodPerfil(const QString &value)
{
    codPerfil = value;
}

QString Perfil::getNombre() const
{
    return nombre;
}

void Perfil::setNombre(const QString &value)
{
    nombre = value;
}

char Perfil::getStatus() const
{
    return status;
}

void Perfil::setStatus(const char &value)
{
    status = value;
}

QString Perfil::toQstring()
{
    QString regresar;
    regresar += "\nCodigo:    " + codPerfil;
    regresar += "\nNombre:   " + nombre;
    return regresar;
}

Perfil::Perfil()
{

}
