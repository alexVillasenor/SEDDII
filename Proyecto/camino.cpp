#include "camino.h"

char Camino::getStatus() const
{
    return status;
}

void Camino::setStatus(char value)
{
    status = value;
}

int Camino::getDistancia() const
{
    return distancia;
}

void Camino::setDistancia(int value)
{
    distancia = value;
}

QString Camino::toQstring()
{
    QString regresar;
    regresar+=status+"\n";
    regresar+=QString::number(distancia);
    return regresar;
}

Camino &Camino::operator =(const Camino &c)
{
    status=c.getStatus();
    distancia=c.getDistancia();

    return *this;

}

Camino::Camino()
{
    distancia=-1;
    status='F';
}
