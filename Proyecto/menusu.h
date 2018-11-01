#ifndef MENUSU_H
#define MENUSU_H

#include <QWidget>

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include "menuprofesor.h"
#include "menuperfil.h"
#include "menuuser.h"
#include "login.h"
#include <QList>
#include <QLineEdit>

namespace Ui {
class MenuSU;
}

class MenuSU : public QWidget
{
    Q_OBJECT
    QString perfil;

public:
    explicit MenuSU(QWidget *parent = 0);
    ~MenuSU();

    QString getPerfil() const;
    void setPerfil(const QString &value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MenuSU *ui;
};

#endif // MENUSU_H
