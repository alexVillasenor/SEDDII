#ifndef MENUGRUPO_H
#define MENUGRUPO_H

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
#include "periodo.h"
#include "grupo.h"

namespace Ui {
class MenuGrupo;
}

class MenuGrupo : public QWidget
{
    Q_OBJECT

public:
    explicit MenuGrupo(QWidget *parent = 0);
    ~MenuGrupo();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MenuGrupo *ui;
};

#endif // MENUGRUPO_H
