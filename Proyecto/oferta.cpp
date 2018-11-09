#include "oferta.h"

QString Oferta::getCodProfesor() const
{
    QString aux=codProfesor;
    return aux;
}

void Oferta::setCodProfesor(const QString &value)
{
    strcpy(codProfesor,value.toStdString().c_str());
}

QString Oferta::getCodPeriodo() const
{
    QString aux=codPeriodo;
    return aux;
}

void Oferta::setCodPeriodo(const QString &value)
{
    strcpy(codPeriodo,value.toStdString().c_str());
}

QString Oferta::getCodGrupo() const
{
    QString aux=codGrupo;
    return aux;
}

void Oferta::setCodGrupo(const QString &value)
{
    strcpy(codGrupo,value.toStdString().c_str());
}

QString Oferta::getCodAsignatura() const
{
    QString aux=codAsignatura;
    return aux;
}

void Oferta::setCodAsignatura(const QString &value)
{
    strcpy(codAsignatura,value.toStdString().c_str());
}

Oferta::Oferta()
{
    this->codAsignatura,nullptr;
    this->codGrupo,nullptr;
    this->codPeriodo,nullptr;
    this->codProfesor,nullptr;
}
