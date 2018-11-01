#include "grupo.h"

QString Grupo::getCodigo() const
{
    QString aux(codigo);
    return aux;
}

void Grupo::setCodigo(QString value)
{
    strcpy(codigo,value.toStdString().c_str());
}

QString Grupo::getNombre() const
{
    QString aux(nombre);
    return aux;
}

void Grupo::setNombre(const QString &value)
{
    strcpy(nombre,value.toStdString().c_str());
}

char Grupo::getStatus() const
{
    return status;
}

void Grupo::setStatus(char value)
{
    status = value;
}

QString Grupo::getNombrePeriodo() const
{
    QString aux(nombrePeriodo);
    return aux;
}

void Grupo::setNombrePeriodo(const QString &value)
{
    strcpy(nombrePeriodo,value.toStdString().c_str());
}

QString Grupo::toQString()
{
    QString regresar,aux;
    aux=codigo;
    regresar += "\nCodigo:  " + aux;
    aux=nombre;
    regresar += "\nNombre:  " + aux;
    aux=nombrePeriodo;
    regresar += "\nPeriodo: "+aux;
    return regresar;
}

Grupo::Grupo()
{

}
