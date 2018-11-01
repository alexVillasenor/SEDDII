#ifndef MENUPERFIL_H
#define MENUPERFIL_H

#include <QWidget>
#include "profesor.h"
#include "perfil.h"
#include "user.h"
#include "login.h"
#include "menuprofesor.h"
#include <fstream>

namespace Ui {
class MenuPerfil;
}

class MenuPerfil : public QWidget
{
    Q_OBJECT

public:
    explicit MenuPerfil(QWidget *parent = 0);
    ~MenuPerfil();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_clicked();

private:
    Ui::MenuPerfil *ui;
};

#endif // MENUPERFIL_H
