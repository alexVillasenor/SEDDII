#ifndef MENUPROFESOR_H
#define MENUPROFESOR_H

#include <QWidget>
#include "profesor.h"
#include "login.h"
#include "menuuser.h"
#include <fstream>
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QIntValidator>
#include <QRegExpValidator>
#include <regex>

namespace Ui {
class MenuProfesor;
}

class MenuProfesor : public QWidget
{
    Q_OBJECT
    QString perfil;
    QString code;
    QString nombre;

public:
    explicit MenuProfesor(QWidget *parent = 0);
    ~MenuProfesor();

    QString getPerfil() const;
    void setPerfil(const QString &value);
    void setPermisos();

    QString getCode() const;
    void setCode(const QString &value);

    QString getNombre() const;
    void setNombre(const QString &value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MenuProfesor *ui;
};

#endif // MENUPROFESOR_H
