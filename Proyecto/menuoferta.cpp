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
    cargarGrupos();
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
                ui->comboBox_Periodo->addItem(p.getCodigo()+" - "+p.getNombre());
                flag=false;
            }
        }
        file.close();
        if(flag){
            QMessageBox::information(this, tr("::Error::"), tr("::No hay periodos registrados:"));
        }
    }
}

void MenuOferta::cargarGrupos()
{
    QString periodo=ui->comboBox_Periodo->currentText().toStdString().substr(6,5).c_str();
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
                ui->comboBox_Grupo->addItem(p.getCodigo()+" - "+p.getNombre());
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
        ui->comboBox_Profesor->clear();
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
                        ui->comboBox_Asignatura->addItem(d.getClaveAsig()+" - ");
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
    cargarGrupos();
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
bool MenuOferta::buscar(const QString &arg1)
{
    bool flag(true);
    Oferta p;
    ifstream file("Oferta.txt");
    if(!file.is_open()){
        return false;
    }
    else{
        while (!file.eof()) {
            file.read((char*)&p,sizeof(p));
            if(file.eof()){break;}
            if(arg1==p.getLlave()){
                flag=false;
                return true;
            }
        }
        file.close();
        if(flag){
            return false;
        }
    }
    return false;
}


/*Agregar*/
void MenuOferta::on_pushButton_2_clicked()
{

        QString cProf = ui->comboBox_Profesor->currentText().toStdString().substr(0,3).c_str();
        QString cAsig = ui->comboBox_Asignatura->currentText().toStdString().substr(0,3).c_str();
        QString cPer = ui->comboBox_Periodo->currentText().toStdString().substr(0,3).c_str();
        QString cGrp = ui->comboBox_Grupo->currentText().toStdString().substr(0,3).c_str();
        Oferta o;

        if(!cProf.isEmpty() and !cAsig.isEmpty() and !cPer.isEmpty() and !cGrp.isEmpty()){
        o.setCodAsignatura(cAsig);
        o.setCodProfesor(cProf);
        o.setCodPeriodo(cPer);
        o.setCodGrupo(cGrp);


        if(!buscar(o.getLlave())){
            ofstream file ("Oferta.txt",ios::app);
            file.write((char*)&o,sizeof(o));
            file.close();
            QMessageBox::information(this, tr("::Exito::"), tr("::Oferta Registrada::"));
        }

        else{
            QMessageBox::information(this, tr("::Error::"), tr("::Oferta existente::"));
        }
    }
        else{
            QMessageBox::information(this, tr("::Error::"), tr("::Llene los campos correctamente::"));
        }

}

/*Mostrar*/
void MenuOferta::on_pushButton_3_clicked()
{
    bool flag(true);
    Oferta p;
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

            ui->textBrowser->append(p.toQstring());
            ui->textBrowser->append("____________________________");
            flag=false;

        }
        file.close();
        if(flag){
            ui->textBrowser->setText("::No hay oferta registrada::");
        }
    }
}

void MenuOferta::on_tabWidget_currentChanged(int index)
{
    setProfesores();
    cargarPeriodos();
    setAsignatura();
    cargarGrupos();
}

/*Buscar*/
void MenuOferta::on_pushButton_4_clicked()
{
    if(!ui->lineEdit->text().isEmpty())
    {
        bool flag(true);
        Oferta p;
        ui->textBrowser_2->clear();
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

                if(ui->lineEdit->text()==p.getLlave()){
                    ui->textBrowser_2->setText(p.toQstring());
                    flag=false;
                }

            }
            file.close();
            if(flag){
                ui->textBrowser_2->setText("::No hay oferta registrada::");
            }
        }
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llene los campos correctamente::"));
    }
}

/*Eliminar*/
void MenuOferta::on_pushButton_5_clicked()
{
    bool flag(true);
    Oferta p;

    QString code(ui->lineEdit_2->text());

    fstream file("Oferta.txt");
    ofstream temp("temp.txt");
    if(!file.is_open()){
        ui->textBrowser_3->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_3->setText("");
        while(!file.eof()){
            file.read((char*)&p,sizeof(p));
            if(file.eof()){
                break;
            }

            if(p.getLlave()==code ){
                ui->textBrowser_3->append(p.toQstring());
                ui->textBrowser_3->append("::Oferta Eliminada::");
                flag=false;
            }
            else{
                temp.write((char*)&p,sizeof(p));
            }
        }
        file.close();
        temp.close();
        remove("Oferta.txt");
        rename("temp.txt","Oferta.txt");
        if(flag){
            ui->textBrowser_3->setText("::Codigo Incorrecto::");
        }
    }
}

/*Modificar*/
void MenuOferta::on_pushButton_6_clicked()
{
    bool flag(true);

    QString cProf = ui->comboBox_Profesor->currentText().toStdString().substr(0,3).c_str();
    QString cAsig = ui->comboBox_Asignatura->currentText().toStdString().substr(0,3).c_str();
    QString cPer = ui->comboBox_Periodo->currentText().toStdString().substr(0,3).c_str();
    QString cGrp = ui->comboBox_Grupo->currentText().toStdString().substr(0,3).c_str();
    QString code(ui->lineEdit_3->text());

    Oferta p;

    fstream file("Oferta.txt");
    if(!file.is_open()){
        ui->textBrowser_4->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_3->setText("");
        while(!file.eof()){
            file.read((char*)&p,sizeof(p));
            if(file.eof()){
                break;
            }

            if(p.getLlave()==code){
                ui->textBrowser_3->append(p.toQstring());
                if(!ui->comboBox_Asignatura_2->currentText().isEmpty()){
                    p.setCodAsignatura(cAsig);
                    ui->textBrowser_4->append("::Asignatura Modificado::");
                }
                if(!ui->comboBox_Grupo_2->currentText().isEmpty()){
                    p.setCodGrupo(cGrp);
                    ui->textBrowser_4->append("::Grupo Modificado::");
                }
                if(!ui->comboBox_Periodo_2->currentText().isEmpty()){
                    p.setCodPeriodo(cPer);
                    ui->textBrowser_4->append("::Periodo Modificado::");
                }
                if(!ui->comboBox_Profesor_2->currentText().isEmpty()){
                    p.setCodProfesor(cProf);
                    ui->textBrowser_4->append("::Profesor Modificado::");
                }

                long int direccion(file.tellp());
                direccion-=sizeof(p);
                file.seekp(direccion,ios::beg);
                file.write((char*)&p,sizeof(p));
                flag=false;
                ui->textBrowser_4->append(p.toQstring());

            }
        }
        file.close();
        if(flag){
            ui->textBrowser_4->setText("::Codigo Incorrecto::");
        }
    }
}
