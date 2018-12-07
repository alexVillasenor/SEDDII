#include "menuasistente.h"
#include "ui_menuasistente.h"

MenuAsistente::MenuAsistente(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuAsistente)
{
    ui->setupUi(this);
}

MenuAsistente::~MenuAsistente()
{
    delete ui;
}

/*Oferta*/
void MenuAsistente::on_pushButton_clicked()
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
        menuOferta->setType(3);
        menuOferta->setPermisos();
        menuOferta->setCode(code);
        menuOferta->show();
        this->close();
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Profesores Encriptados::"));
    }
}

/*Disponibilidad*/
void MenuAsistente::on_pushButton_2_clicked()
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
        menuDis->setType(3);
        menuDis->setCode(code);
        menuDis->setPermisos();
        menuDis->setProfesores();
        menuDis->show();
        this->close();
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Profesores Encriptados::"));
    }
}

/*Salir*/
void MenuAsistente::on_pushButton_3_clicked()
{
    LogIn *logIn = new LogIn();
    this->hide();
    logIn->show();
    this->close();
}

QString MenuAsistente::getCode() const
{
    return code;
}

void MenuAsistente::setCode(const QString &value)
{
    code = value;
}

