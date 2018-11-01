#ifndef MENUPERIODO_H
#define MENUPERIODO_H

#include <QWidget>
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


namespace Ui {
class MenuPeriodo;
}

class MenuPeriodo : public QWidget
{
    Q_OBJECT

public:
    explicit MenuPeriodo(QWidget *parent = 0);
    ~MenuPeriodo();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MenuPeriodo *ui;
};

#endif // MENUPERIODO_H
