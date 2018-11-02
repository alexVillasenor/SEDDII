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
    MenuDisponibilidad *menuDis = new MenuDisponibilidad();
    this->hide();
    menuDis->setType(4);
    menuDis->setCode(code);
    menuDis->setProfesores();
    menuDis->show();
    this->close();
    delete this;
}

/*Salir*/
void ProfesorMenu::on_pushButton_2_clicked()
{    
    LogIn *logIn = new LogIn();
    this->hide();
    logIn->show();
    this->close();
    delete this;
}

QString ProfesorMenu::getCode() const
{
    return code;
}

void ProfesorMenu::setCode(const QString &value)
{
    code = value;
}
