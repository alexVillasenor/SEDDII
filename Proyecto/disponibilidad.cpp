#include "disponibilidad.h"

QString Disponibilidad::getClaveProf() const
{
    QString aux=claveProf;
    return aux;
}

void Disponibilidad::setClaveProf(const QString &value)
{
    strcpy(claveProf,value.toStdString().c_str());
}

QString Disponibilidad::getClaveAsig() const
{
    QString aux=claveAsig;
    return aux;
}

void Disponibilidad::setClaveAsig(const QString &value)
{
    strcpy(claveAsig,value.toStdString().c_str());
}

QDate Disponibilidad::getFecha() const
{
    return fecha;
}

void Disponibilidad::setFecha(const QDate &value)
{
    fecha = value;
}

QTime Disponibilidad::getHora() const
{
    return hora;
}

void Disponibilidad::setHora(const QTime &value)
{
    hora = value;
}

QString Disponibilidad::toQstring()
{
    QString aux;
    aux+="Clave: ";
    aux+=getClaveProf()+getClaveAsig();
    aux+="\nCodigo Profesor: ";
    aux+=getClaveProf();
    aux+="\nCodigo Asignatura: ";
    aux+=getClaveAsig();
    aux+="\nFecha: ";
    aux+=getFecha().toString();
    aux+="\nHora: ";
    aux+=getHora().toString();
    aux+="\n________________________________\n";
    return aux;
}

Disponibilidad::Disponibilidad()
{
    strcpy(claveAsig,"");
    strcpy(claveProf,"");
    this->fecha= QDate::currentDate();
    this->hora = QTime::currentTime();
}
