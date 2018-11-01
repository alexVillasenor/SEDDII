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

void MenuDisponibilidad::setProfesores()
{

}

void MenuDisponibilidad::setCarreras()
{

}

void MenuDisponibilidad::setMaterias()
{

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

/*Agregar*/
void MenuDisponibilidad::on_pushButton_2_clicked()
{

}

void MenuDisponibilidad::on_comboBox_Carrera_activated(const QString &arg1)
{
    ui->comboBox_Materias->addItem(arg1);
}
