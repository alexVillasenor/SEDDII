#ifndef NUEVOEDIFICIO_H
#define NUEVOEDIFICIO_H

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
class NuevoEdificio;
}

class NuevoEdificio : public QWidget
{
    Q_OBJECT

public:
    explicit NuevoEdificio(QWidget *parent = 0);
    ~NuevoEdificio();

    Mapa getM() const;
    void setM(const Mapa &value);
    int getLastCodeEdificio(std::string name);

    int getSize() const;
    void setSize(int value);

    int getFinal() const;
    void setFinal(int value);

    bool getFlag() const;
    void setFlag(bool value);

private slots:
    void on_pushButton_clicked();

private:
    Ui::NuevoEdificio *ui;
    Mapa m;
    int size;
    int final;
    bool flag;
};

#endif // NUEVOEDIFICIO_H
