#ifndef GRUPO_H
#define GRUPO_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <sstream>

class Grupo
{
private:
    char grado[15];
    char codigo[10];
    char nombre[50];
    char status;
    char nombrePeriodo[50];
public:
    Grupo();
    QString getCodigo() const;
    void setCodigo(QString value);
    QString getNombre() const;
    void setNombre(const QString &value);
    char getStatus() const;
    void setStatus(char value);
    QString getNombrePeriodo() const;
    void setNombrePeriodo(const QString &value);

    QString toQString();
    QString getGrado() const;
    void setGrado(const QString &value);
};

#endif // GRUPO_H
