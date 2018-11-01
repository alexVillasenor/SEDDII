#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include "menuprofesor.h"
#include "menuperfil.h"
#include "menuuser.h"
#include "menusu.h"
#include "menuca.h"
#include "menuperiodo.h"
#include "menugrupo.h"
#include "menuasignatura.h"
#include "menudisponibilidad.h"
#include "profesormenu.h"
#include "menumapa.h"
#include <QList>
#include <QLineEdit>
#include "list.h"
#include "listainvertida.h"
#include "stack.h"
#include "nuevoedificio.h"
#include "nuevoenlace.h"


namespace Ui {
class LogIn;
}

class LogIn : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = 0);
    ~LogIn();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LogIn *ui;
};

#endif // LOGIN_H
