#ifndef CAMINO_H
#define CAMINO_H
#include <QString>

class Camino
{
private:
    char status;
    int distancia;
public:
    Camino();
    char getStatus() const;
    void setStatus(char value);
    int getDistancia() const;
    void setDistancia(int value);

    QString toQstring();
    Camino &operator = (const Camino&c);

};

#endif // CAMINO_H
