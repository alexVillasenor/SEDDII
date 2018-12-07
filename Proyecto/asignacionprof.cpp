#include "asignacionprof.h"
#include "ui_asignacionprof.h"

AsignacionProf::AsignacionProf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AsignacionProf)
{
    ui->setupUi(this);
    setComboOferta();
    setComboProfesores();
}

AsignacionProf::~AsignacionProf()
{
    delete ui;
}

void AsignacionProf::setComboOferta()
{
    bool flag(true);
    Oferta p;
    ui->comboBox->clear();
    ui->textBrowser->clear();
    ifstream file("Oferta.txt");
    if(!file.is_open()){
        QMessageBox::information(this, tr("::Error::"), tr("::No se pudo abrir archivo grupos:"));
    }

    else{
        while (!file.eof()) {
            file.read((char*)&p,sizeof(p));

            if(file.eof()){
                break;
            }

            if("NULL"==p.getCodProfesor()){
                ui->comboBox->addItem(p.getLlave());
                flag=false;
            }

        }
        file.close();
        if(flag){
            ui->textBrowser->setText("::No hay oferta registrada::");
        }
    }
}

void AsignacionProf::setComboProfesores()
{
    QString cAsig=ui->comboBox->currentText().toStdString().substr(0,3).c_str();
    ui->comboBox_2->clear();
    ifstream file("Dispersa.txt");
    int pos(0),cont;
    Disponibilidad d;
    if(!file.is_open()){
        QMessageBox::information(this, tr("::Error::"), tr("::Error al abrir archivo::"));
    }
    else{
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
                    if(cAsig==d.getClaveAsig()){
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
                                if(d.getClaveProf()==p.getCode()){
                                    ui->comboBox_2->addItem(p.getCode()+" "+p.getNombre());
                                    flag=false;
                                }
                            }
                            file.close();
                            if(flag){
                                QMessageBox::information(this, tr("::Error::"), tr("::Sin profesores disponibles::"));
                            }
                        }
                    }
                }
                pos=pos+(COLUMNAS*sizeof(d))+sizeof(cont);
            }
        }
        file.close();
    }
}

/*Asignar*/
void AsignacionProf::on_pushButton_clicked()
{
    bool flag(true);

    QString cProf = ui->comboBox_2->currentText() ;
    QString code = ui->comboBox->currentText();

    Oferta p;

    fstream file("Oferta.txt");
    ofstream t("temp.txt");
    if(!file.is_open()){
        ui->textBrowser->setText("::Error al abrir el archivo::");
    }

    else{
        while(!file.eof()){
            file.read((char*)&p,sizeof(p));
            if(file.eof()){
                break;
            }

            if(p.getLlave()==code and !ui->comboBox_2->currentText().isEmpty()){
                flag=false;
                p.setCodProfesor(cProf);
                t.write((char*)&p,sizeof(p));
                ui->textBrowser->append(p.toQstring());
                ui->textBrowser->append("::Profesor Asignado::");
            }
            else{
                t.write((char*)&p,sizeof(p));
            }
        }
        t.close();
        file.close();
        remove("oferta.txt");
        rename("temp.txt","Oferta.txt");
        if(flag){
            ui->textBrowser->setText("::Profesor erroneo::");
        }
    }
    setComboOferta();
    setComboProfesores();
}

/*Regresar*/
void AsignacionProf::on_pushButton_2_clicked()
{
    MenuOferta *mOf = new MenuOferta;
    this->hide();
    mOf->setType(type);
    mOf->setPermisos();
    mOf->show();
    this->close();
}

void AsignacionProf::on_comboBox_activated(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->pushButton->hide();
        ui->pushButton_2->show();
    }
    setComboProfesores();
    bool flag(true);
    Oferta p;
    QString c=ui->comboBox->currentText();
    ui->textBrowser->clear();
    ifstream file("Oferta.txt");
    if(!file.is_open()){
        QMessageBox::information(this, tr("::Error::"), tr("::No se pudo abrir archivo grupos:"));
    }

    else{
        while (!file.eof()) {
            file.read((char*)&p,sizeof(p));

            if(file.eof()){
                break;
            }

            if(c==p.getLlave()){
                ui->textBrowser->setText(p.toQstring());
                flag=false;
            }

        }
        file.close();
        if(flag){
            ui->textBrowser->setText("::No hay oferta registrada::");
        }
    }
}

int AsignacionProf::getType() const
{
    return type;
}

void AsignacionProf::setType(int value)
{
    type = value;
}
