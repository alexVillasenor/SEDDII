#include "menuoferta.h"
#include "ui_menuoferta.h"

MenuOferta::MenuOferta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuOferta)
{
    ui->setupUi(this);
    ui->comboBox_Grupo->clear();
    ui->comboBox_Periodo->clear();
    ui->comboBox_Profesor->clear();
    ui->comboBox_Asignatura->clear();
    setProfesores();
    cargarPeriodos();
    setAsignatura();
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

void MenuOferta::setProfesores()
{
    bool flag(true);
    ifstream file("Profesores.txt");
    if(!file.is_open()){
        QMessageBox::information(this, tr("::Error::"), tr("::Error al abrir archivo profesores::"));
    }

    else{
        while (!file.eof()) {
            string auxStr;
            QString qString;
            Profesor p;
            getline(file,auxStr,',');

            if(file.eof()){
                break;
            }
            qString = QString::fromStdString(auxStr);
            p.setCode(qString);
            getline(file,auxStr,',');
            qString = QString::fromStdString(auxStr);
            p.setNombre(qString);
            getline(file,auxStr,',');
            qString = QString::fromStdString(auxStr);
            p.setCorreo(qString);
            getline(file,auxStr,'\n');
            qString = QString::fromStdString(auxStr);
            p.setTelefono(qString);
            ui->comboBox_Profesor->addItem(p.getCode()+" - "+p.getNombre());
            flag=false;
        }
        file.close();
        if(flag){
            QMessageBox::information(this, tr("::Error::"), tr("::No hay profesores registrados::"));
        }
    }
}

void MenuOferta::setAsignatura(){
    ifstream file("Dispersa.txt");
    int pos(0),cont;
    Disponibilidad d;
    if(!file.is_open()){
        QMessageBox::information(this, tr("::Error::"), tr("::Error al abrir archivo::"));
    }
    else{
        ui->comboBox_Asignatura->clear();
        int myInt,FILAS,COLUMNAS;
        ifstream t(".tamano");
        t.read((char*)&myInt,sizeof(myInt));
        FILAS=myInt;
        t.read((char*)&myInt,sizeof(myInt));
        COLUMNAS=myInt;
        t.close();

        while(!file.eof()){
            file.seekg(pos,ios::beg);
            file.read((char*)&cont,sizeof(cont));
            if(cont==0){
                pos=pos+(COLUMNAS*sizeof(d))+sizeof(cont);
            }
            else{
                for(int i(0);i<cont;i++){
                    file.read((char*)&d,sizeof(d));
                    QString llave = ui->comboBox_Profesor->currentText().toStdString().substr(0,3).c_str();
                    if(llave==d.getClaveProf())

                        ui->comboBox_Asignatura->addItem(d.getClaveAsig());
                }
                pos=pos+(COLUMNAS*sizeof(d))+sizeof(cont);
            }
        }
        file.close();
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

void MenuOferta::on_comboBox_Profesor_activated(const QString &arg1)
{
    setAsignatura();
}

/*Agregar*/
void MenuOferta::on_pushButton_2_clicked()
{

}
