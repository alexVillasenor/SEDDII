#ifndef MENUUSER_H
#define MENUUSER_H

#include "profesor.h"
#include "user.h"
#include "login.h"
#include "menuprofesor.h"
#include <fstream>

namespace Ui {
class MenuUser;
}

class MenuUser : public QWidget
{
    Q_OBJECT

public:
    explicit MenuUser(QWidget *parent = 0);
    ~MenuUser();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_clicked();

private:
    Ui::MenuUser *ui;
};

#endif // MENUUSER_H
