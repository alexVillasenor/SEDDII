#include "edificio.h"

int Edificio::getCodigo() const
{
    return codigo;
}

void Edificio::setCodigo(int value)
{
    codigo = value;
}

QString Edificio::getNombre() const
{
    QString aux(nombre);
    return aux;
}

void Edificio::setNombre(const QString &value)
{
    strcpy(nombre,value.toStdString().c_str());
}

char Edificio::getStatus() const
{
    return status;
}

void Edificio::setStatus(char value)
{
    status = value;
}

int Edificio::getPos() const
{
    return pos;
}

void Edificio::setPos(int value)
{
    pos = value;
}

QString Edificio::toQstring()
{
    QString regresar;
    regresar+="Código: ";
    regresar+=QString::number(codigo);
    regresar+="\n";
    regresar+="Estado: ";
    regresar+=status;
    regresar+="\n";
    regresar+="Nombre: ";
    regresar+=nombre;
    regresar+="\n";
    return regresar;
}

Edificio &Edificio::operator =(const Edificio &e)
{
    codigo=e.getCodigo();
    status=e.getStatus();
    setNombre(e.getNombre());
    pos=e.getPos();

    return *this;

}

bool Edificio::operator ==(const Edificio &e)
{
    return getNombre()==e.getNombre();

}

bool Edificio::operator !=(const Edificio &e)
{
    return getNombre()!=e.getNombre();
}

bool Edificio::operator <(const Edificio &e)
{
    return getNombre()<e.getNombre();
}

bool Edificio::operator <=(const Edificio &e)
{
    return getNombre()<=e.getNombre();
}

bool Edificio::operator >(const Edificio &e)
{
    return getNombre()>e.getNombre();
}

bool Edificio::operator >=(const Edificio &e)
{
    return getNombre()>=e.getNombre();
}

Edificio::Edificio()
{
    status='V';
}
