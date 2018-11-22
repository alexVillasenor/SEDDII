#include "menuca.h"
#include "ui_menuca.h"

using namespace std;

MenuCA::MenuCA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuCA)
{
    ui->setupUi(this);
}

MenuCA::~MenuCA()
{
    delete ui;
}

/*Profesores*/
void MenuCA::on_pushButton_clicked()
{
    MenuProfesor *menuProfesor = new MenuProfesor();
    hide();
    menuProfesor->setPerfil("2");
    menuProfesor->setPermisos();
    menuProfesor->show();
    this->close();
}

/*Salir*/
void MenuCA::on_pushButton_2_clicked()
{
    LogIn *logIn = new LogIn();
    this->hide();
    logIn->show();
    this->close();

}
