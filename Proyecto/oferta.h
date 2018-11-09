#ifndef OFERTA_H
#define OFERTA_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <QDate>
#include "login.h"

class Oferta
{
private:
    char codProfesor[20];
    char codPeriodo[20];
    char codGrupo[20];
    char codAsignatura[20];
public:
    Oferta();
    QString getCodProfesor() const;
    void setCodProfesor(const QString &value);
    QString getCodPeriodo() const;
    void setCodPeriodo(const QString &value);
    QString getCodGrupo() const;
    void setCodGrupo(const QString &value);
    QString getCodAsignatura() const;
    void setCodAsignatura(const QString &value);
};

#endif // OFERTA_H
