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
    QString clave;
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
};

#endif // DISPONIBILIDAD_H
