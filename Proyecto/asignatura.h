#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <QDate>


class Asignatura
{
private:
    int codigo;
    int creditos;
    char nombre[40];
    char programa[40];
    char status;
    char grado[15];

public:
    Asignatura();
    int getCodigo() const;
    void setCodigo(int value);
    int getCreditos() const;
    void setCreditos(int value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getPrograma() const;
    void setPrograma(const QString &value);
    char getStatus() const;
    void setStatus(char value);

    QString toQString();
    QString getGrado() const;
    void setGrado(const QString &value);
};

#endif // ASIGNATURA_H
