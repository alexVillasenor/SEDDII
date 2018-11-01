#include "periodo.h"

QString Periodo::getCodigo() const
{
    QString aux(codigo);
    return aux;
}

void Periodo::setCodigo(QString value)
{
    strcpy(codigo,value.toStdString().c_str());
}

QString Periodo::getNombre() const
{
    QString aux(nombre);
    return aux;
}

void Periodo::setNombre(const QString &value)
{
    strcpy(nombre,value.toStdString().c_str());
}

QDate Periodo::getFechaInicio() const
{
    return fechaInicio;
}

void Periodo::setFechaInicio(const QDate &value)
{
    fechaInicio = value;
}

QDate Periodo::getFechaFin() const
{
    return fechaFin;
}

void Periodo::setFechaFin(const QDate &value)
{
    fechaFin = value;
}

char Periodo::getStatus() const
{
    return status;
}

void Periodo::setStatus(char value)
{
    status = value;
}

QString Periodo::toQString()
{
    QString regresar,aux;
    aux=codigo;
    regresar += "\nCodigo:          " + aux;
    aux=nombre;
    regresar += "\nNombre:          " + aux;
    regresar += "\nFecha de inicio: " + fechaInicio.toString("dd-MMM-yyyy");
    regresar += "\nFecha de fin:    " + fechaFin.toString("dd-MMM-yyyy");
    return regresar;
}

Periodo::Periodo()
{

}
