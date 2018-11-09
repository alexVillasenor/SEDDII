#ifndef MENUOFERTA_H
#define MENUOFERTA_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <QDate>
#include "login.h"
#include "oferta.h"

namespace Ui {
class MenuOferta;
}

class MenuOferta : public QWidget
{
    Q_OBJECT

public:
    explicit MenuOferta(QWidget *parent = 0);
    ~MenuOferta();
    void cargarPeriodos();
    void cargarGrupos();
    void setProfesores();
    void setAsignatura();
    bool buscar(const QString &arg1);

    int getType() const;
    void setType(int value);

    QString getCode() const;
    void setCode(const QString &value);

private slots:
    void on_pushButton_clicked();

    void on_comboBox_Periodo_activated(const QString &arg1);

    void on_comboBox_Profesor_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MenuOferta *ui;
    int type;
    QString code;
};

#endif // MENUOFERTA_H
