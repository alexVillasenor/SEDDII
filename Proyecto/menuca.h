#ifndef MENUCA_H
#define MENUCA_H

#include <QWidget>
#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include "menuprofesor.h"
#include "menuperfil.h"
#include "menuuser.h"
#include <QList>
#include <QLineEdit>

namespace Ui {
class MenuCA;
}

class MenuCA : public QWidget
{
    Q_OBJECT

public:
    explicit MenuCA(QWidget *parent = 0);
    ~MenuCA();

    QString getCode() const;
    void setCode(const QString &value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MenuCA *ui;
    QString code;
};

#endif // MENUCA_H
