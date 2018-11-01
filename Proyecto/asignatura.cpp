#include "asignatura.h"

int Asignatura::getCodigo() const
{
    return codigo;
}

void Asignatura::setCodigo(int value)
{
    codigo = value;
}

int Asignatura::getCreditos() const
{
    return creditos;
}

void Asignatura::setCreditos(int value)
{
    creditos = value;
}

QString Asignatura::getNombre() const
{
    QString aux(nombre);
    return aux;
}

void Asignatura::setNombre(const QString &value)
{
    strcpy(nombre,value.toStdString().c_str());
}

QString Asignatura::getPrograma() const
{
    QString aux(programa);
    return aux;
}

void Asignatura::setPrograma(const QString &value)
{

    strcpy(programa,value.toStdString().c_str());
}

char Asignatura::getStatus() const
{
    return status;
}

void Asignatura::setStatus(char value)
{
    status = value;
}

QString Asignatura::toQString()
{
    QString regresar,aux;
    aux=QString::number(codigo);
    regresar += "\nCodigo:   " + aux;
    aux=nombre;
    regresar += "\nNombre:   " + aux;
    aux=programa;
    regresar += "\nPrograma: "+aux;
    aux=QString::number(creditos);
    regresar += "\nCreditos: "+aux;

    return regresar;
}

Asignatura::Asignatura()
{
    status='1';
}
