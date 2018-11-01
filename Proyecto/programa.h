#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <QString>
#include "indicesecundario.h"

class Programa
{
private:
    char nombre[40];
    Programa *next;
    IndiceSecundario *first;

public:
    Programa();
    QString getNombre() const;
    void setNombre(const QString &value);
    Programa *getNext() const;
    void setNext(Programa *value);
    IndiceSecundario *getFirst() const;
    void setFirst(IndiceSecundario *value);

    Programa &operator = (const Programa&p);
};

#endif // PROGRAMA_H
