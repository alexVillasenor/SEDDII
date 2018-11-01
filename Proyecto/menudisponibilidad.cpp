#include "menudisponibilidad.h"
#include "ui_menudisponibilidad.h"

MenuDisponibilidad::MenuDisponibilidad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuDisponibilidad)
{
    ui->setupUi(this);
    ui->comboBox_Carrera->clear();
    ui->comboBox_Materias->clear();
    ui->comboBox_Profesor->clear();
    loadIndex();
    setCarreras();
    setMaterias();
    setProfesores();
}

MenuDisponibilidad::~MenuDisponibilidad()
{
    delete ui;
}

void MenuDisponibilidad::setProfesores()
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

void MenuDisponibilidad::setMaterias()
{
    if(!ui->comboBox_Carrera->currentText().isEmpty()){
        Programa* auxPrograma = listainvertida.findPrograma(ui->comboBox_Carrera->currentText());

        if(auxPrograma!=nullptr){
            IndiceSecundario* auxIndSec = auxPrograma->getFirst();

            while(auxIndSec!=nullptr){
                Indice i;
                Asignatura a;
                i.setCodigo(auxIndSec->getCodigo());
                long int dir =listaIndices.retriveData(listaIndices.findData(i)).getDireccion();
                ifstream f("Asignaturas.txt");
                f.seekg(dir);
                f.read((char*)&a,sizeof(a));
                f.close();
                if(a.getStatus()=='1'){
                    ui->comboBox_Materias->addItem(QString::number(a.getCodigo())+" - "+a.getNombre());
                }
                auxIndSec=auxIndSec->getNextPrograma();
            }
        }
        else
            QMessageBox::information(this, tr("::Error::"), tr("::Llena todos los campos correctamente::"));
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llena todos los campos correctamente::"));

    }
}

void MenuDisponibilidad::setCarreras()
{
    Programa* aux=listainvertida.getInicioProgramas();
    while(aux!=nullptr){
        ui->comboBox_Carrera->addItem(aux->getNombre());
        aux=aux->getNext();
    }
}

void MenuDisponibilidad::loadIndex()
{
    listaIndices.deleteAll();
    listainvertida.deleteAll();

    ifstream indices("Indices.txt");
    if(!indices.is_open()){

    }
    else{
        Indice i;
        while(!indices.eof()){
            indices.read((char*)&i,sizeof(i));
            if(indices.eof()){
                break;
            }
            listaIndices.insertData(listaIndices.getLastPos(),i);
        }
        indices.close();
    }


    IndiceSecundario iSec;
    string auxStr;
    int myInt;
    stringstream ss;

    ifstream indSec("TDA_Indice_secundario.txt");
    if(!indSec.is_open()){

    }
    else{
        while(!indSec.eof()){
            getline(indSec,auxStr,'|');
            if(indSec.eof()){
                break;
            }
            ss.clear();
            ss<<auxStr;
            ss>>myInt;
            iSec.setCodigo(myInt);
            listainvertida.addIndiceSecundario(iSec);
            getline(indSec,auxStr);
        }
        indSec.close();
    }

    ifstream programas("TDA_Programa.txt");
    if(!programas.is_open()){

    }
    else{
        programas.seekg(0);
        while(!programas.eof()){
            getline(programas,auxStr,'|');
            if(programas.eof()){
                break;
            }
            listainvertida.addPrograma(QString::fromStdString(auxStr));
            Programa* Pro=listainvertida.findPrograma(QString::fromStdString(auxStr));
            getline(programas,auxStr);
            ss.clear();
            ss<<auxStr;
            ss>>myInt;
            Pro->setFirst(listainvertida.getIndiceSecundario(myInt));
        }
        programas.close();
    }

    indSec.open("TDA_Indice_secundario.txt");
    if(!indSec.is_open()){

    }
    else{
        string auxStr;
        int myInt;
        stringstream ss;
        while(!indSec.eof()){
            getline(indSec,auxStr,'|');
            if(indSec.eof()){
                break;
            }
            IndiceSecundario* iS = listainvertida.findIndiceSecundario(QString::fromStdString(auxStr));
            getline(indSec,auxStr);
            ss.clear();
            ss<<auxStr;
            ss>>myInt;
            iS->setNextPrograma(listainvertida.getIndiceSecundario(myInt));
        }
        indSec.close();
    }
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
    QString clave;
    clave=ui->comboBox_Profesor->currentText();
    clave+=ui->comboBox_Materias->currentText();
    QDate today=QDate::currentDate();
    QTime now=QTime::currentTime();

    Disponibilidad d;
    d.setClave(clave);
    d.setFecha(today);
    d.setHora(now);
    qDebug()<<clave;
    qDebug()<<today;
    qDebug()<<now;
}

void MenuDisponibilidad::on_comboBox_Carrera_activated(const QString &arg1)
{
    ui->comboBox_Materias->clear();
    setMaterias();
}
