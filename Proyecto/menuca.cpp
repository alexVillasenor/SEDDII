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
    bool flagProf;
    ifstream f("Diccionario de datos.txt");
    if(!f.is_open()){
        flagProf = true;
    }
    else{
        flagProf = false;
        f.close();
    }
    if(flagProf){
        MenuProfesor *menuProfesor = new MenuProfesor();
        hide();
        menuProfesor->setPerfil("2");
        menuProfesor->setPermisos();
        menuProfesor->show();
        this->close();
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Profesores Encriptados::"));
    }

}

/*Salir*/
void MenuCA::on_pushButton_2_clicked()
{
    LogIn *logIn = new LogIn();
    this->hide();
    logIn->show();
    this->close();

}

/*Asignaturas*/
void MenuCA::on_pushButton_3_clicked()
{
    MenuAsignatura *mAsign = new MenuAsignatura();
    hide();
    mAsign->setPerfil("2");
    mAsign->setPermisos();
    mAsign->show();
    this->close();
}

/*Disponibilidad*/
void MenuCA::on_pushButton_4_clicked()
{
    bool flagProf;
    ifstream f("Diccionario de datos.txt");
    if(!f.is_open()){
        flagProf = true;
    }
    else{
        flagProf = false;
        f.close();
    }
    if(flagProf){
        MenuDisponibilidad *menuDis = new MenuDisponibilidad();
        this->hide();
        menuDis->setType(2);
        menuDis->setCode(code);
        menuDis->setProfesores();
        menuDis->show();
        this->close();
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Profesores Encriptados::"));
    }
}

/*Oferta*/
void MenuCA::on_pushButton_5_clicked()
{
    bool flagProf;
    ifstream f("Diccionario de datos.txt");
    if(!f.is_open()){
        flagProf = true;
    }
    else{
        flagProf = false;
        f.close();
    }
    if(flagProf){
        MenuOferta *menuOferta = new MenuOferta();
        this->hide();
        menuOferta->setType(2);
        menuOferta->setCode(code);
        menuOferta->show();
        this->close();
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Profesores Encriptados::"));
    }
}

QString MenuCA::getCode() const
{
    return code;
}

void MenuCA::setCode(const QString &value)
{
    code = value;
}
