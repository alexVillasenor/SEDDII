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
    char codProfesor[50];
    char codPeriodo[50];
    char codGrupo[50];
    char codAsignatura[50];
public:
    Oferta();
    QString getLlave();
    QString getCodProfesor() const;
    void setCodProfesor(const QString &value);
    QString getCodPeriodo() const;
    void setCodPeriodo(const QString &value);
    QString getCodGrupo() const;
    void setCodGrupo(const QString &value);
    QString getCodAsignatura() const;
    void setCodAsignatura(const QString &value);
    QString toQstring();
};

#endif // OFERTA_H
