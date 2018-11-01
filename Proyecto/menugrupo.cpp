#include "menugrupo.h"
#include "ui_menugrupo.h"

using namespace std;

MenuGrupo::MenuGrupo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuGrupo)
{
    ui->setupUi(this);
    ui->comboBox->clear();
    ui->comboBox_2->clear();

    bool flag(true);
    ifstream file("Periodos.txt");
    if(!file.is_open()){
        ui->textBrowser->setText("::Error al abrir el archivo::");
    }

    else{
        Periodo p;
        while (!file.eof()) {

            file.read((char*)&p,sizeof(p));
            if(file.eof()){
                break;
            }

            if(p.getStatus()=='1'){
                ui->comboBox->addItem(p.getNombre());
                ui->comboBox_2->addItem(p.getNombre());
                flag=false;
            }
        }
        file.close();
        if(flag){
            ui->comboBox->addItem("::No hay perfiles::");
            ui->comboBox_2->addItem("::No hay perfiles::");
        }
    }
}

MenuGrupo::~MenuGrupo()
{
    delete ui;
}

bool isEmptyGrupo(string name){
    ifstream f(name+".txt");
    if(!f.is_open()){
        return true;
    }
    else{
        f.seekg(0,f.end);
        long int p = f.tellg();
        if(p==0){
            f.close();
            return true;
        }
        else{
            f.close();
            return false;
        }
    }
}

QString getLastCodeGrupo(string name){
    QString code;
    if(isEmptyGrupo(name)){
        return code="1";
    }
    else{
        Grupo p;
        ifstream file(name+".txt");
        if(!file.is_open()){
            return code="1";
        }
        else{
            file.seekg(0,file.end);
            long int direccion(file.tellg());
            direccion-=sizeof(p);
            file.seekg(direccion,file.beg);
            file.read((char*)&p,sizeof(p));
            file.close();
        }
        int n(p.getCodigo().toInt()+1);
        QString aux(QString::number(n));
        return aux;
    }


}


/*Agregar*/
void MenuGrupo::on_pushButton_2_clicked()
{
    QString auxStr;
    Grupo p;
    if(!ui->lineEdit->text().isEmpty() && ui->comboBox_2->currentText()!="::No hay perfiles::")
    {
        auxStr=getLastCodeGrupo("Grupos");
        p.setCodigo(auxStr);

        auxStr=ui->lineEdit->text();
        p.setNombre(auxStr);
        auxStr=ui->comboBox_2->currentText();
        p.setNombrePeriodo(auxStr);
        p.setStatus('1');

        ofstream w("Grupos.txt",ios::app);
        w.write((char*)&p,sizeof(p));
        w.close();

        QMessageBox::information(this, tr("::Exito::"), tr("::Grupo Creado::"));
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llena todos los campos correctamente::"));
    }
    ui->lineEdit->clear();
}

/*Mostrar*/
void MenuGrupo::on_pushButton_3_clicked()
{
    bool flag(true);
    Grupo p;

    ifstream file("Grupos.txt");
    if(!file.is_open()){
        ui->textBrowser->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser->setText("");
        while (!file.eof()) {
            file.read((char*)&p,sizeof(p));

            if(file.eof()){
                break;
            }

            if(p.getStatus()=='1'){
                ui->textBrowser->append(p.toQString());
                ui->textBrowser->append("____________________________");
                flag=false;
            }
        }
        file.close();
        if(flag){
            ui->textBrowser->setText("::Archivo Vacio::");
        }
    }
}

/*Buscar*/
void MenuGrupo::on_pushButton_4_clicked()
{
    bool flag(true);
    Grupo p;

    QString code(ui->lineEdit_2->text());

    ifstream file("Grupos.txt");
    if(!file.is_open()){
        ui->textBrowser_2->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_2->setText("");
        while(!file.eof()){
            file.read((char*)&p,sizeof(p));
            if(file.eof()){
                break;
            }
            if(p.getCodigo()==code && p.getStatus()=='1'){
                ui->textBrowser_2->append(p.toQString());
                ui->textBrowser_2->append("____________________________");
                flag=false;
            }
        }
        file.close();
        if(flag){
            ui->textBrowser_2->setText("::Codigo Incorrecto::");
        }
    }
    ui->lineEdit_2->clear();
}

/*Eliminar*/
void MenuGrupo::on_pushButton_6_clicked()
{
    bool flag(true);
    Grupo p;

    QString code(ui->lineEdit_5->text());

    fstream file("Grupos.txt");
    ofstream temp("temp.txt");
    if(!file.is_open()){
        ui->textBrowser_4->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_4->setText("");
        while(!file.eof()){
            file.read((char*)&p,sizeof(p));
            if(file.eof()){
                break;
            }

            if(p.getCodigo()==code && p.getStatus()=='1'){
                ui->textBrowser_4->append(p.toQString());
                ui->textBrowser_4->append("::Grupo Eliminado::");
                flag=false;
            }
            else{
                temp.write((char*)&p,sizeof(p));
            }
        }
        file.close();
        temp.close();
        remove("Grupos.txt");
        rename("temp.txt","Grupos.txt");
        if(flag){
            ui->textBrowser_4->setText("::Codigo Incorrecto::");
        }
    }
    ui->lineEdit_5->clear();
}

/*Desactivar*/
void MenuGrupo::on_pushButton_7_clicked()
{
    bool flag(true);
    Grupo p;

    QString code(ui->lineEdit_6->text());

    fstream file("Grupos.txt");
    if(!file.is_open()){
        ui->textBrowser_5->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_5->setText("");
        while(!file.eof()){
            file.read((char*)&p,sizeof(p));
            if(file.eof()){
                break;
            }

            if(p.getCodigo()==code && p.getStatus()=='1'){
                ui->textBrowser_5->append(p.toQString());
                ui->textBrowser_5->append("::Grupo Desactivado::");
                p.setStatus('0');
                long int direccion(file.tellp());
                direccion-=sizeof(p);
                file.seekp(direccion,ios::beg);
                file.write((char*)&p,sizeof(p));
                flag=false;
            }
        }
        file.close();
        if(flag){
            ui->textBrowser_5->setText("::Codigo Incorrecto::");
        }
    }
    ui->lineEdit_6->clear();
}

/*Activar*/
void MenuGrupo::on_pushButton_8_clicked()
{
    bool flag(true);
    Grupo p;

    QString code(ui->lineEdit_7->text());

    fstream file("Grupos.txt");
    if(!file.is_open()){
        ui->textBrowser_6->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_6->setText("");
        while(!file.eof()){
            file.read((char*)&p,sizeof(p));
            if(file.eof()){
                break;
            }

            if(p.getCodigo()==code && p.getStatus()=='0'){
                ui->textBrowser_6->append(p.toQString());
                ui->textBrowser_6->append("::Grupo Activado::");
                p.setStatus('1');
                long int direccion(file.tellp());
                direccion-=sizeof(p);
                file.seekp(direccion,ios::beg);
                file.write((char*)&p,sizeof(p));
                flag=false;
            }
        }
        file.close();
        if(flag){
            ui->textBrowser_6->setText("::Codigo Incorrecto::");
        }
    }
    ui->lineEdit_7->clear();
}

/*Regresar*/
void MenuGrupo::on_pushButton_clicked()
{
    MenuSU *SU = new MenuSU();
    this->hide();
    SU->show();
    this->close();
    delete this;
}

/*Modificar*/
void MenuGrupo::on_pushButton_5_clicked()
{
    bool flag(true);
    Grupo p;


    QString code(ui->lineEdit_3->text());

    fstream file("Grupos.txt");
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

            if(p.getCodigo()==code && p.getStatus()=='1'){
                ui->textBrowser_3->append(p.toQString());
                if(!ui->lineEdit_4->text().isEmpty()){
                    p.setNombre(ui->lineEdit_4->text());
                    ui->textBrowser_3->append("::Nombre Modificado::");
                }
                QString auxStr(ui->comboBox->currentText());
                p.setNombrePeriodo(auxStr);
                ui->textBrowser_3->append("::Periodo Modificado::");
                long int direccion(file.tellp());
                direccion-=sizeof(p);
                file.seekp(direccion,ios::beg);
                file.write((char*)&p,sizeof(p));
                flag=false;
                ui->textBrowser_3->append(p.toQString());

            }
        }
        file.close();
        if(flag){
            ui->textBrowser_3->setText("::Codigo Incorrecto::");
        }
    }
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}
