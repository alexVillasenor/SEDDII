#ifndef PAREDIFICIOS_H
#define PAREDIFICIOS_H
#include "edificio.h"

class ParEdificios
{
private:
    Edificio origen;
    Edificio destino;
public:
    ParEdificios();
    Edificio getOrigen() const;
    void setOrigen(const Edificio &value);
    Edificio getDestino() const;
    void setDestino(const Edificio &value);
};

#endif // PAREDIFICIOS_H
