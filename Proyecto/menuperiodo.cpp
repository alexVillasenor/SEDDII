#include "menuperiodo.h"
#include "ui_menuperiodo.h"

using namespace std;

MenuPeriodo::MenuPeriodo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPeriodo)
{
    ui->setupUi(this);
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit_2->setCalendarPopup(true);
    ui->dateEdit_3->setCalendarPopup(true);
    ui->dateEdit_4->setCalendarPopup(true);
    QDate today(QDate::currentDate());
    ui->dateEdit->setDate(today);
    ui->dateEdit_2->setDate(today);
    ui->dateEdit_3->setDate(today);
    ui->dateEdit_4->setDate(today);
}

MenuPeriodo::~MenuPeriodo()
{
    delete ui;
}


bool isEmptyPeriodo(string name){
    ifstream f(name+".txt");
    if(!f.is_open()){
        return true;
    }
    else{
        f.seekg(0,f.end);
        long int p=f.tellg();
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

QString getLastCodePeriodo(string name){
    QString code;
    if(isEmptyPeriodo(name)){
        return code="400";
    }
    else{
        Periodo p;
        ifstream file(name+".txt");
        if(!file.is_open()){
            return code="400";
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
void MenuPeriodo::on_pushButton_7_clicked()
{
    QDate myDate;
    QString auxStr;
    Periodo p;
    if(!ui->lineEdit_5->text().isEmpty() and (ui->dateEdit->date()<ui->dateEdit_2->date()))
    {
        auxStr=getLastCodePeriodo("Periodos");
        p.setCodigo(auxStr);
        myDate = ui->dateEdit->date();
        p.setFechaInicio(myDate);
        myDate = ui->dateEdit_2->date();
        p.setFechaFin(myDate);
        auxStr=ui->lineEdit_5->text();
        p.setNombre(auxStr);
        p.setStatus('1');

        ofstream write("Periodos.txt",ios::app);
        write.write((char*)&p,sizeof(p));
        write.close();

        QMessageBox::information(this, tr("::Exito::"), tr("::Periodo Creado::"));
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llena todos los campos correctamente::"));
    }
    ui->lineEdit_5->clear();
}

/*Mostrar*/
void MenuPeriodo::on_pushButton_2_clicked()
{
    bool flag(true);
    Periodo p;

    ifstream file("Periodos.txt");
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
void MenuPeriodo::on_pushButton_3_clicked()
{
    bool flag(true);
    Periodo p;

    QString code(ui->lineEdit->text());

    ifstream file("Periodos.txt");
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
    ui->lineEdit->clear();
}

/*Eliminar*////Validar si tiene gurpos no eliminar periodo
void MenuPeriodo::on_pushButton_4_clicked()
{
    bool flag(true);
    Periodo p;

    QString code(ui->lineEdit_2->text());

    fstream file("Periodos.txt");
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
            bool f(true);
            Grupo g;
            ifstream r("Grupos.txt");
            if(!r.is_open()){
                ui->textBrowser_3->setText("::Error al abrir el archivo::");
            }

            else{
                ui->textBrowser_3->setText("");
                while(!r.eof()){
                    r.read((char*)&g,sizeof(g));
                    if(r.eof()){
                        break;
                    }
                    if(g.getNombrePeriodo()==p.getNombre()){
                        ui->textBrowser_3->append("::Periodo con grupos::");
                        f=false;
                    }
                }
                r.close();
            }


            if(p.getCodigo()==code && p.getStatus()=='1' && f){
            ui->textBrowser_3->append(p.toQString());
            ui->textBrowser_3->append("::Periodo Eliminado::");
            flag=false;
        }
        else{
            temp.write((char*)&p,sizeof(p));
        }
    }
    file.close();
    temp.close();
    remove("Periodos.txt");
    rename("temp.txt","Periodos.txt");
    if(flag){
        ui->textBrowser_3->setText("::Codigo Incorrecto::");
    }
}
ui->lineEdit_2->clear();
}

/*Desactivar*/
void MenuPeriodo::on_pushButton_5_clicked()
{
    bool flag(true);
    Periodo p;

    QString code(ui->lineEdit_3->text());

    fstream file("Periodos.txt");
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
                ui->textBrowser_4->append("::Periodo Desactivado::");
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
            ui->textBrowser_4->setText("::Codigo Incorrecto::");
        }
    }
    ui->lineEdit_3->clear();
}

/*Activar*/
void MenuPeriodo::on_pushButton_6_clicked()
{
    bool flag(true);
    Periodo p;

    QString code(ui->lineEdit_4->text());

    fstream file("Periodos.txt");
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

            if(p.getCodigo()==code && p.getStatus()=='0'){
                ui->textBrowser_5->append(p.toQString());
                ui->textBrowser_5->append("::Periodo Activado::");
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
            ui->textBrowser_5->setText("::Codigo Incorrecto::");
        }
    }
    ui->lineEdit_4->clear();
}

/*regresar*/
void MenuPeriodo::on_pushButton_clicked()
{
    MenuSU *SU = new MenuSU();
    this->hide();
    SU->show();
    this->close();

}

/*Modificar*/
void MenuPeriodo::on_pushButton_8_clicked()
{
    bool flag(true);
    Periodo p;
    QDate myDate;

    QString code(ui->lineEdit_6->text());

    fstream file("Periodos.txt");
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

            if(p.getCodigo()==code && p.getStatus()=='1'){
                ui->textBrowser_6->append(p.toQString());
                if(!ui->lineEdit_7->text().isEmpty()){
                    p.setNombre(ui->lineEdit_7->text());
                    ui->textBrowser_6->append("::Nombre Modificado::");
                }
                if(ui->dateEdit_3->date()<ui->dateEdit_4->date()){
                    myDate=ui->dateEdit_3->date();
                    p.setFechaInicio(myDate);
                    myDate=ui->dateEdit_4->date();
                    p.setFechaFin(myDate);
                    ui->textBrowser_6->append("::Fechas Modificadas::");

                }
                long int direccion(file.tellp());
                direccion-=sizeof(p);
                file.seekp(direccion,ios::beg);
                file.write((char*)&p,sizeof(p));
                flag=false;
                ui->textBrowser_6->append(p.toQString());

            }
        }
        file.close();
        if(flag){
            ui->textBrowser_6->setText("::Codigo Incorrecto::");
        }
    }
    ui->lineEdit_7->clear();
    ui->lineEdit_6->clear();
}
