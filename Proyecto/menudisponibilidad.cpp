#include "menudisponibilidad.h"
#include "ui_menudisponibilidad.h"

MenuDisponibilidad::MenuDisponibilidad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuDisponibilidad)
{
    ui->setupUi(this);
}

MenuDisponibilidad::~MenuDisponibilidad()
{
    delete ui;
}

/*Regresar*/
void MenuDisponibilidad::on_pushButton_clicked()
{
    MenuSU *SU = new MenuSU();
    this->hide();
    SU->show();
    this->close();
    delete this;
}
