#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <QString>
#include <iostream>

class Edificio
{
private:
    int codigo;
    char nombre[10];
    char status;
    int pos;
public:
    Edificio();
    int getCodigo() const;
    void setCodigo(int value);
    QString getNombre() const;
    void setNombre(const QString &value);
    char getStatus() const;
    void setStatus(char value);
    int getPos() const;
    void setPos(int value);

    QString toQstring();

    Edificio &operator = (const Edificio&e);
    bool operator == (const Edificio &e);
    bool operator != (const Edificio &e);
    bool operator < (const Edificio &e);
    bool operator <= (const Edificio &e);
    bool operator > (const Edificio &e);
    bool operator >= (const Edificio &e);



};

#endif // EDIFICIO_H
