#ifndef PERIODO_H
#define PERIODO_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <QDate>

class Periodo
{
private:
    char codigo[10];
    char nombre[50];
    QDate fechaInicio;
    QDate fechaFin;
    char status;
public:
    Periodo();

    QString getCodigo() const;
    void setCodigo(QString value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QDate getFechaInicio() const;
    void setFechaInicio(const QDate &value);
    QDate getFechaFin() const;
    void setFechaFin(const QDate &value);
    char getStatus() const;
    void setStatus(char value);

    QString toQString();
};

#endif // PERIODO_H
