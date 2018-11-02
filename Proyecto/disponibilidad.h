#ifndef DISPONIBILIDAD_H
#define DISPONIBILIDAD_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <QDate>
#include "login.h"

class Disponibilidad
{
private:
    char claveProf[10];
    char claveAsig[10];
    QDate fecha;
    QTime hora;
public:
    Disponibilidad();
    QString getClaveProf() const;
    void setClaveProf(const QString &value);
    QString getClaveAsig() const;
    void setClaveAsig(const QString &value);
    QDate getFecha() const;
    void setFecha(const QDate &value);
    QTime getHora() const;
    void setHora(const QTime &value);
    QString toQstring();
};

#endif // DISPONIBILIDAD_H
