#include "user.h"
using namespace std;

QString User::getCodeUser() const
{
    return codeUser;
}

void User::setCodeUser(const QString &value)
{
    codeUser = value;
}

QString User::getNombre() const
{
    return nombre;
}

void User::setNombre(const QString &value)
{
    nombre = value;
}

QString User::getPassword() const
{
    return password;
}

void User::setPassword(const QString &value)
{
    password = value;
}

QString User::getCodePerfil() const
{
    return codePerfil;
}

void User::setCodePerfil(const QString &value)
{
    codePerfil = value;
}

QString User::toQstring()
{
    QString regresar;
    regresar += "\nCodigo:    " + codeUser;
    regresar += "\nNombre:   " + nombre;
    regresar += "\nContraseña:    " + password;
    if(codePerfil=="1"){
        regresar += "\nPerfil: Administrador";
    }
    else if(codePerfil=="2"){
        regresar += "\nPerfil: Coordinador Academico";
    }
    else if(codePerfil=="3"){
        regresar += "\nPerfil: Asistente Academico";
    }
    else if(codePerfil=="4"){
        regresar += "\nPerfil: Profesor";
    }
    return regresar;
}


char User::getStatus() const
{
    return status;
}

void User::setStatus(char value)
{
    status = value;
}

User::User()
{

}
