#ifndef USER_H
#define USER_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <fstream>
class User
{
private:
    static int count;
    QString codeUser;
    QString nombre;
    QString password;
    QString codePerfil;
    char status;

public:
    User();

    QString getCodeUser() const;
    void setCodeUser(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getPassword() const;
    void setPassword(const QString &value);
    QString getCodePerfil() const;
    void setCodePerfil(const QString &value);

    QString toQstring();

    char getStatus() const;
    void setStatus(char value);
};

#endif // USER_H
