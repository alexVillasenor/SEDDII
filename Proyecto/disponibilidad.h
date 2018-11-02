#ifndef DISPONIBILIDAD_H
#define DISPONIBILIDAD_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <QDate>

class Disponibilidad
{
private:
    char clave[10];
    QDate fecha;
    QTime hora;
public:
    Disponibilidad();
    QString getClave() const;
    void setClave(const QString &value);
    QDate getFecha() const;
    void setFecha(const QDate &value);
    QTime getHora() const;
    void setHora(const QTime &value);
    QString toQstring();
};

#endif // DISPONIBILIDAD_H
