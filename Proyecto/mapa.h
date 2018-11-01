#ifndef MAPA_H
#define MAPA_H
#include "edificio.h"
#include "camino.h"
#include "paredificios.h"

class Mapa
{
private:
    int size;
    Edificio edificios[12];
    Camino caminos[12][12];
public:
    Mapa();
    void setEdificio(Edificio &e);        
    Edificio &getEdificio(const int pos);
    void setCamino(Edificio &a, Edificio &b, const int &d);
    Camino getCamino(Edificio a, Edificio b);
    void deleteEdificio(Edificio e);

    bool deleteCamino(Edificio a, Edificio b);

    QString toQstring();

    int getSize() const;
    void setSize(int value);
};

#endif // MAPA_H
