#include "profesormenu.h"
#include "ui_profesormenu.h"

ProfesorMenu::ProfesorMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfesorMenu)
{
    ui->setupUi(this);
}

ProfesorMenu::~ProfesorMenu()
{
    delete ui;
}

/*Disponibilidad*/
void ProfesorMenu::on_pushButton_clicked()
{

}

/*Salir*/
void ProfesorMenu::on_pushButton_2_clicked()
{

}
