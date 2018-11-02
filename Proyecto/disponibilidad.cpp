#include "disponibilidad.h"

QString Disponibilidad::getClave() const
{
    QString aux=clave;
    return aux;
}

void Disponibilidad::setClave(const QString &value)
{
    strcpy(clave,value.toStdString().c_str());
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

QString Disponibilidad::toQstring()
{
    QString aux;
    aux+="Clave: ";
    aux+=getClave();
    aux+="\nFecha: ";
    aux+=getFecha().toString();
    aux+="\nHora: ";
    aux+=getHora().toString();
    aux+="\n________________________________\n";
    return aux;
}

Disponibilidad::Disponibilidad()
{

}
