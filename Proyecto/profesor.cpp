#include "profesor.h"

using namespace std;

QString Profesor::getNombre() const
{
    return nombre;
}

void Profesor::setNombre(const QString &value)
{
    nombre = value;
}

QString Profesor::getCorreo() const
{
    return correo;
}

void Profesor::setCorreo(const QString &value)
{
    correo = value;
}

QString Profesor::getTelefono() const
{
    return telefono;
}

void Profesor::setTelefono(const QString &value)
{
    telefono = value;
}

QString Profesor::getCode() const
{
    return code;
}

void Profesor::setCode(const QString &value)
{
    code = value;
}

ostream& operator << (ostream& os, Profesor& p)
{
    os<<p.getCode().toStdString()<<","
      <<p.getNombre().toStdString()<<","
      <<p.getCorreo().toStdString()<<","
      <<p.getTelefono().toStdString()<<"\n";
    return os;
}

QString Profesor::toQString()
{
    QString regresar;
    regresar += "\nCodigo:    " + getCode();
    regresar += "\nNombre:   " + getNombre();
    regresar += "\nCorreo:    " + getCorreo();
    regresar += "\nTelefono: " + getTelefono();
    return regresar;
}

Profesor::Profesor()
{

}
