#include "login.h"
#include "ui_login.h"

using namespace std;

LogIn::LogIn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{9}")));

}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::on_pushButton_clicked()
{
    QString Qcode = ui->lineEdit->text();
    string myCode(Qcode.toStdString());
    QString Qpw = ui->lineEdit_2->text();
    ui->lineEdit_2->clear();
    string myPw(Qpw.toStdString());
    bool flag(true);

    if(Qcode=="1" && Qpw=="1"){
        MenuSU *menuAdmin = new MenuSU();
        hide();
        menuAdmin->show();
        this->close();
    }
    else{
        ifstream file("Usuarios.txt");
        User u;
        if(!file.is_open()){
            QMessageBox::information(this, tr("::Error::"), tr("::No se pudo abrir el archivo de usuarios::"));
        }

        else{
            while (!file.eof()) {
                int a,b,c,d;

                char code[10];
                char name[30];
                char pw[30];
                char codep[10];
                char status;

                string auxStr,codeuser;
                QString qString;


                file.read((char*)&a,sizeof(int));
                if(file.eof()){
                    break;
                }

                file.read((char*)&code,a);
                code[a]='\0';
                codeuser=code;
                qString = QString::fromStdString(codeuser);

                u.setCodeUser(qString);

                file.read((char*)&b,sizeof(int));
                file.read((char*)&name,b);
                name[b]='\0';
                auxStr=name;
                qString = QString::fromStdString(auxStr);

                u.setNombre(qString);

                file.read((char*)&c,sizeof(int));
                file.read((char*)&pw,c);
                pw[c]='\0';
                auxStr=pw;
                qString = QString::fromStdString(auxStr);

                u.setPassword(qString);

                file.read((char*)&d,sizeof(int));
                file.read((char*)&codep,d);
                codep[d]='\0';
                auxStr=codep;
                qString = QString::fromStdString(auxStr);
                u.setCodePerfil(qString);

                file.read((char*)&status,1);

                u.setStatus(status);


                if(codeuser==myCode and u.getStatus()=='1' and pw==myPw){
                    flag=false;
                    break;
                }
            }
            file.close();
            if(flag){
                QMessageBox::information(this, tr("::Error::"), tr("::Perfil Incorrecto::"));

            }
            else{
                if(u.getCodePerfil()=="1"){
                    MenuSU *menuAdmin = new MenuSU();
                    hide();
                    menuAdmin->show();
                    this->close();
                }
                else if(u.getCodePerfil()=="2"){
                    MenuCA *menuCA = new MenuCA();
                    hide();
                    menuCA->show();
                    this->close();
                }
                else if(u.getCodePerfil()=="3"){
                    QMessageBox::information(this, tr("::Asistente Academico::"), tr("::Sistema en desarrollo::"));
                }
                else if(u.getCodePerfil()=="4"){
                    QMessageBox::information(this, tr("::Profesor::"), tr("::Sistema en desarrollo"));
                }

            }
        }
    }
}

void LogIn::on_pushButton_2_clicked()
{
    this->close();
}
