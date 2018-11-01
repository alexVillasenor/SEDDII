#include "programa.h"

QString Programa::getNombre() const
{
    QString aux(nombre);
    return aux;
}

void Programa::setNombre(const QString &value)
{
    strcpy(nombre,value.toStdString().c_str());
}

Programa *Programa::getNext() const
{
    return next;
}

void Programa::setNext(Programa *value)
{
    next = value;
}

IndiceSecundario *Programa::getFirst() const
{
    return first;
}

void Programa::setFirst(IndiceSecundario *value)
{
    first = value;
}

Programa &Programa::operator =(const Programa &p)
{
    next=p.next;
    first=p.first;
    strcpy(nombre,p.getNombre().toStdString().c_str());

    return *this;
}

Programa::Programa()
{
    next=nullptr;
    first=nullptr;
}
