#ifndef PROFESOR_H
#define PROFESOR_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <sstream>


class Profesor
{
private:
    QString code;
    QString nombre;
    QString correo;
    QString telefono;
public:
    Profesor();


    QString getNombre() const;
    void setNombre(const QString &value);
    QString getCorreo() const;
    void setCorreo(const QString &value);
    QString getTelefono() const;
    void setTelefono(const QString &value);
    QString getCode() const;
    void setCode(const QString &value);

    friend std::ostream &operator << (std::ostream&os, Profesor& p);

    QString toQString();
};

#endif // PROFESOR_H
