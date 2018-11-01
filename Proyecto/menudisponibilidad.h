#ifndef MENUDISPONIBILIDAD_H
#define MENUDISPONIBILIDAD_H

#include <QWidget>
#include "disponibilidad.h"
#include "login.h"

namespace Ui {
class MenuDisponibilidad;
}

class MenuDisponibilidad : public QWidget
{
    Q_OBJECT

public:
    explicit MenuDisponibilidad(QWidget *parent = 0);
    ~MenuDisponibilidad();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MenuDisponibilidad *ui;
};

#endif // MENUDISPONIBILIDAD_H
