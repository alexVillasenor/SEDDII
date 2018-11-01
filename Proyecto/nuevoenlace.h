#ifndef NUEVOENLACE_H
#define NUEVOENLACE_H

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

namespace Ui {
class NuevoEnlace;
}

class NuevoEnlace : public QWidget
{
    Q_OBJECT

public:
    explicit NuevoEnlace(QWidget *parent = 0);
    ~NuevoEnlace();

    bool getFlag() const;
    void setFlag(bool value);
    bool recorrido();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::NuevoEnlace *ui;
    Mapa m;
    bool flag;
};

#endif // NUEVOENLACE_H
