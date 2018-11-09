#include "menuoferta.h"
#include "ui_menuoferta.h"

MenuOferta::MenuOferta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuOferta)
{
    ui->setupUi(this);
    cargarPeriodos();
    cargarGrupos(ui->comboBox_Periodo->currentText());
}

MenuOferta::~MenuOferta()
{
    delete ui;
}

void MenuOferta::cargarPeriodos()
{
    bool flag(true);
    Periodo p;
    ui->comboBox_Periodo->clear();
    ifstream file("Periodos.txt");
    if(!file.is_open()){
        QMessageBox::information(this, tr("::Error::"), tr("::No se pudo abrir archivo Periodos:"));
    }

    else{
        while (!file.eof()) {
            file.read((char*)&p,sizeof(p));

            if(file.eof()){
                break;
            }

            if(p.getStatus()=='1'){
                ui->comboBox_Periodo->addItem(p.getNombre());
                flag=false;
            }
        }
        file.close();
        if(flag){
            QMessageBox::information(this, tr("::Error::"), tr("::No hay periodos registrados:"));
        }
    }
}

void MenuOferta::cargarGrupos(QString periodo)
{
    bool flag(true);
    Grupo p;
    ui->comboBox_Grupo->clear();
    ifstream file("Grupos.txt");
    if(!file.is_open()){
        QMessageBox::information(this, tr("::Error::"), tr("::No se pudo abrir archivo grupos:"));
    }

    else{
        while (!file.eof()) {
            file.read((char*)&p,sizeof(p));

            if(file.eof()){
                break;
            }

            if(p.getStatus()=='1' && periodo==p.getNombrePeriodo()){
                ui->comboBox_Grupo->addItem(p.getNombre());
                flag=false;
            }
        }
        file.close();
        if(flag){
            QMessageBox::information(this, tr("::Error::"), tr("::No hay grupos registrados:"));
        }
    }
}

/*Regresar*/
void MenuOferta::on_pushButton_clicked()
{
    MenuSU *SU = new MenuSU();
    this->hide();
    SU->setCode(code);
    SU->show();
    this->close();
    delete this;
}

void MenuOferta::on_comboBox_Periodo_activated(const QString &arg1)
{
    cargarGrupos(arg1);
}

QString MenuOferta::getCode() const
{
    return code;
}

void MenuOferta::setCode(const QString &value)
{
    code = value;
}

int MenuOferta::getType() const
{
    return type;
}

void MenuOferta::setType(int value)
{
    type = value;
}
