#include "disponibilidad.h"

QString Disponibilidad::getClave() const
{
    return clave;
}

void Disponibilidad::setClave(const QString &value)
{
    clave = value;
}

QDate Disponibilidad::getFecha() const
{
    return fecha;
}

void Disponibilidad::setFecha(const QDate &value)
{
    fecha = value;
}

QTime Disponibilidad::getHora() const
{
    return hora;
}

void Disponibilidad::setHora(const QTime &value)
{
    hora = value;
}

Disponibilidad::Disponibilidad()
{

}
