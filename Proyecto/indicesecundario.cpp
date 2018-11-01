#include "indicesecundario.h"

IndiceSecundario *IndiceSecundario::getNext() const
{
    return next;
}

void IndiceSecundario::setNext(IndiceSecundario *value)
{
    next = value;
}

IndiceSecundario *IndiceSecundario::getNextPrograma() const
{
    return nextPrograma;
}

void IndiceSecundario::setNextPrograma(IndiceSecundario *value)
{
    nextPrograma = value;
}

int IndiceSecundario::getCodigo() const
{
    return codigo;
}

void IndiceSecundario::setCodigo(int value)
{
    codigo = value;
}

IndiceSecundario &IndiceSecundario::operator =(const IndiceSecundario &i)
{
    next=i.next;
    nextPrograma=i.nextPrograma;
    codigo=i.codigo;

    return *this;
}

IndiceSecundario::IndiceSecundario()
{
    codigo=0;
    next=nullptr;
    nextPrograma=nullptr;
}
IndiceSecundario::IndiceSecundario(const IndiceSecundario &i)
{
    codigo=i.getCodigo();
    next=nullptr;
    nextPrograma=nullptr;
}
