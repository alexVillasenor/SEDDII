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
    void cargarGrupos(QString periodo);
    void setProfesores();
    void setAsignatura();

    int getType() const;
    void setType(int value);

    QString getCode() const;
    void setCode(const QString &value);

private slots:
    void on_pushButton_clicked();

    void on_comboBox_Periodo_activated(const QString &arg1);

    void on_comboBox_Profesor_activated(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::MenuOferta *ui;
    int type;
    QString code;
};

#endif // MENUOFERTA_H
