#ifndef PERFIL_H
#define PERFIL_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <sstream>

class Perfil
{
private:
    QString codPerfil;
    QString nombre;
    char status;


public:
    Perfil();

    QString getCodPerfil() const;
    void setCodPerfil(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    char getStatus() const;
    void setStatus(const char &value);

    QString toQstring();

};

#endif // PERFIL_H
