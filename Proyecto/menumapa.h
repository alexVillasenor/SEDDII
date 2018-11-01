#ifndef MENUMAPA_H
#define MENUMAPA_H

#include <QWidget>
#include "login.h"
#include <fstream>
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QIntValidator>
#include <QRegExpValidator>
#include <regex>
#include "mapa.h"
#include <string>
#include "list.h"
#include "stack.h"
#include "Queue.h"

namespace Ui {
class MenuMapa;
}

class MenuMapa : public QWidget
{
    Q_OBJECT

public:
    explicit MenuMapa(QWidget *parent = 0);
    ~MenuMapa();

    Mapa getM() const;
    void setM(const Mapa &value);
    bool recorrido();
    void showRuta(Stack<ParEdificios>&pila, Edificio&destino);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_tabWidget_3_currentChanged(int index);

    void on_pushButton_16_clicked();

    void on_pushButton_mostarEdificios_clicked();

private:
    Ui::MenuMapa *ui;
    Mapa m;

};

#endif // MENUMAPA_H
