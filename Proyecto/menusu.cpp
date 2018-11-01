#include "menusu.h"
#include "ui_menusu.h"

QString MenuSU::getPerfil() const
{
    return perfil;
}

void MenuSU::setPerfil(const QString &value)
{
    perfil = value;
}

MenuSU::MenuSU(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuSU)
{
    ui->setupUi(this);    
}

MenuSU::~MenuSU()
{
    delete ui;
}

/*Usuario*/
void MenuSU::on_pushButton_clicked()
{
    MenuUser *menuUser = new MenuUser();
    hide();
    menuUser->show();
    this->close();
    delete this;
}

/*Perfiles*/
void MenuSU::on_pushButton_2_clicked()
{
    MenuPerfil *menuPerfil = new MenuPerfil();
    hide();
    menuPerfil->show();
    this->close();
    delete this;
}

/*Menu Profesor*/
void MenuSU::on_pushButton_3_clicked()
{
    MenuProfesor *menuProfesor = new MenuProfesor();
    hide();
    menuProfesor->setPerfil("1");
    menuProfesor->setPermisos();
    menuProfesor->show();
    this->close();
    delete this;
}

/*Salir*/
void MenuSU::on_pushButton_4_clicked()
{
    LogIn *logIn = new LogIn();
    this->hide();
    logIn->show();
    this->close();
    delete this;
}

/*Periodo*/
void MenuSU::on_pushButton_5_clicked()
{
    MenuPeriodo *menuPeriodo = new MenuPeriodo();
    this->hide();
    menuPeriodo->show();
    this->close();
    delete this;
}

/*Grupo*/
void MenuSU::on_pushButton_6_clicked()
{
    MenuGrupo *menuGrupo = new MenuGrupo();
    this->hide();
    menuGrupo->show();
    this->close();
    delete this;
}

/*Asignatura*/
void MenuSU::on_pushButton_7_clicked()
{
    MenuAsignatura *menuGrupo = new MenuAsignatura();
    this->hide();
    menuGrupo->show();
    this->close();
    delete this;
}

/*Mapa*/
void MenuSU::on_pushButton_8_clicked()
{
    MenuMapa *menuMapa = new MenuMapa();
    this->hide();
    menuMapa->show();
    this->close();
    delete this;
}

/*Disponibilidad*/
void MenuSU::on_pushButton_9_clicked()
{
    MenuDisponibilidad *menuDis = new MenuDisponibilidad();
    this->hide();
    menuDis->show();
    this->close();
    delete this;
}
