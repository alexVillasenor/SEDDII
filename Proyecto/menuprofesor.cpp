#include "menuprofesor.h"
#include "ui_menuprofesor.h"

using namespace std;

QString MenuProfesor::getPerfil() const
{
    return perfil;
}

void MenuProfesor::setPerfil(const QString &value)
{
    perfil = value;
}

void MenuProfesor::setPermisos()
{
    if(perfil=="1"){
        ui->tab->setDisabled(true);
    }
    else if(perfil=="2"){
        ui->tab->setDisabled(true);
        ui->tab_4->setDisabled(true);
        ui->tab_5->setDisabled(true);
    }
    else if(perfil=="3"){

    }
    else if(perfil=="4"){
        ui->tab_2->setDisabled(true);
        ui->tab_3->setDisabled(true);
        ui->tab_4->setDisabled(true);
        ui->tab_5->setDisabled(true);
        ui->pushButton_2->setDisabled(true);
    }
}

bool validaCorreo(string email){
    regex reg("\\b[a-zA-Z0-9]+@[a-zA-Z0-9]+\\.[a-zA-Z]{2,3}\\.[a-zA-Z]{2,3}\\b");
    regex reg2("\\b[a-zA-Z0-9]+@[a-zA-Z0-9]+\\.[a-zA-Z]{2,3}\\b");
    if(regex_match(email, reg)or regex_match(email,reg2))
      return true;
    else
      return false;
}

QString MenuProfesor::getCode() const
{
    return code;
}

void MenuProfesor::setCode(const QString &value)
{
    code = value;
}

QString MenuProfesor::getNombre() const
{
    return nombre;
}

void MenuProfesor::setNombre(const QString &value)
{
    nombre = value;
}

MenuProfesor::MenuProfesor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuProfesor)
{
    ui->setupUi(this);

    ui->lineEdit_3->setValidator(new QRegExpValidator(QRegExp("\\b[a-zA-Z0-9]+@[a-zA-Z0-9]+\\.[a-zA-Z]{2,3}\\.[a-zA-Z]{2,3}\\b")));

    ui->lineEdit_4->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,10}")));

    ui->lineEdit_5->setValidator(new QRegExpValidator(QRegExp("[0-9]{9}")));
    ui->lineEdit_7->setValidator(new QRegExpValidator(QRegExp("[0-9]{9}")));
    ui->lineEdit_6->setValidator(new QRegExpValidator(QRegExp("[0-9]{9}")));

    ui->lineEdit_9->setValidator(new QRegExpValidator(QRegExp("\\b[a-zA-Z0-9]+@[a-zA-Z0-9]+\\.[a-zA-Z]{2,3}\\.[a-zA-Z]{2,3}\\b")));
    ui->lineEdit_10->setValidator(new QRegExpValidator(QRegExp("[0-9]{10}")));
}

MenuProfesor::~MenuProfesor()
{
    delete ui;
}

/*Agregar profesores*/
void MenuProfesor::on_pushButton_clicked()
{
    QString auxStr;       //Se toman los valores dentro de los lineEdit
    QString correo = ui->lineEdit_3->text();
    QString telefono= ui->lineEdit_4->text();

    Profesor myProfe;

    myProfe.setCode(code);                           //Se ingresan los valores dentro de un objeto profesor
    myProfe.setNombre(nombre);
    myProfe.setCorreo(correo);
    myProfe.setTelefono(telefono);

    if(validaCorreo(myProfe.getCorreo().toStdString()) and !ui->lineEdit_3->text().isEmpty() and !ui->lineEdit_4->text().isEmpty()){
        ofstream file("Profesores.txt",ios::app);
        file<<myProfe;
        file.close();
                //Se limpian los espacios de los linEdits
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        QMessageBox::information(this, tr("::Éxito::"), tr("::Profesor agregado::"));

        MenuUser *menuUser = new MenuUser();
        this->hide();
        menuUser->show();
        this->close();

    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llena todos los campos correctamente::"));
    }
}

/*Regresar de menu de profesores*/
void MenuProfesor::on_pushButton_2_clicked()
{
    if(perfil=="2"){
        MenuCA *CA = new MenuCA();
        this->hide();
        CA->show();
        this->close();
    }
    else if(perfil=="1"){
        MenuSU *SU = new MenuSU();
        this->hide();
        SU->show();
        this->close();
    }
}

/*Mostrar Profesores*/
void MenuProfesor::on_pushButton_3_clicked()
{
    bool flag(true);
    ifstream file("Profesores.txt");
    if(!file.is_open()){
        ui->textBrowser->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser->setText("");
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

            ui->textBrowser->append(p.toQString());
            ui->textBrowser->append("____________________________");
            flag=false;
        }
        file.close();
        if(flag){
            ui->textBrowser->setText("::No hay profesores registrados");
        }
    }
}

/*Limpiar pantalla de mostrar profesores*/
void MenuProfesor::on_pushButton_4_clicked()
{
    ui->textBrowser->setText("");
}

/*Buscar profesores*/
void MenuProfesor::on_pushButton_5_clicked()
{
    QString code;
    bool flag;
    code=ui->lineEdit_5->text();        

    ifstream file("Profesores.txt");
    if(!file.is_open()){
        ui->textBrowser_2->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_2->setText("");
        flag=false;
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

            if(p.getCode()==code){
                ui->textBrowser_2->append(p.toQString());
                ui->textBrowser_2->append("____________________________");
                flag=true;
            }
        }
        file.close();
        if(!flag){
            ui->textBrowser_2->setText("::Profesor no encontrado::");
        }
    }


}

/*Eliminar profesores*/
void MenuProfesor::on_pushButton_6_clicked()
{
    QString code;
    bool flag;
    code=ui->lineEdit_6->text();

    ifstream read("Profesores.txt");
    ofstream write("Temp.txt",ios::app);
    if(!read.is_open()){
        ui->textBrowser_3->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_3->setText("");
        flag=false;
        while (!read.eof()) {
            string auxStr;
            QString qString;
            Profesor p;
            getline(read,auxStr,',');
            if(read.eof()){
                break;
            }
            qString = QString::fromStdString(auxStr);
            p.setCode(qString);
            getline(read,auxStr,',');
            qString = QString::fromStdString(auxStr);
            p.setNombre(qString);
            getline(read,auxStr,',');
            qString = QString::fromStdString(auxStr);
            p.setCorreo(qString);
            getline(read,auxStr,'\n');
            qString = QString::fromStdString(auxStr);
            p.setTelefono(qString);

            if(p.getCode()==code){

                ifstream file("Usuarios.txt");
                ofstream archivo("temp2.txt");

                if(!file.is_open()){
                    ui->textBrowser_3->setText("::Error al abrir el archivo::");
                }

                else{
                    ui->textBrowser_3->setText("");
                    while (!file.eof()) {
                        int a,b,c,d;

                        char codeu[10];
                        char name[30];
                        char pw[30];
                        char codep[10];
                        char status;

                        string auxStr,codeuser;
                        QString qString;

                        User u;

                        file.read((char*)&a,sizeof(int));
                        if(file.eof()){
                            break;
                        }

                        file.read((char*)&codeu,a);
                        codeu[a]='\0';
                        codeuser=codeu;
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


                        if(QString::fromStdString(codeuser)==code && u.getStatus()=='1'){
                            ui->textBrowser_3->append(u.toQstring());
                            ui->textBrowser_3->append("____________________________");
                            ui->textBrowser_3->append("::Usuario eliminado::");
                            flag=true;
                            ui->textBrowser_3->append(p.toQString());
                            ui->textBrowser_3->append("____________________________");
                            ui->textBrowser_3->append("::Profesor Eliminado::");
                        }

                        else{
                            archivo.write((char*)&a,sizeof(int));
                            archivo.write((char*)&codeu,a);

                            archivo.write((char*)&b,sizeof(int));
                            archivo.write((char*)&name,b);

                            archivo.write((char*)&c,sizeof(int));
                            archivo.write((char*)&pw,c);

                            archivo.write((char*)&d,sizeof(int));
                            archivo.write((char*)&codep,d);

                            archivo.write((char*)&status,1);
                        }


                    }
                    file.close();
                    archivo.close();

                    remove("Usuarios.txt");
                    rename("temp2.txt","Usuarios.txt");
                    if(!flag){
                        ui->textBrowser_3->setText("::Usuario no encontrado::");
                        write<<p;
                    }
                }
            }
            else{
                write<<p;
            }
        }
        read.close();
        write.close();
        if(!flag){
            ui->textBrowser_3->setText("::Profesor no encontrado::");
        }
        remove("Profesores.txt");
        rename("Temp.txt","Profesores.txt");
    }
}

/*Modificar profesores*/
void MenuProfesor::on_pushButton_7_clicked()
{
    QString code,nombre,correo,telefono;
    bool flag(true),f(true);
    code=ui->lineEdit_7->text();
    correo=ui->lineEdit_9->text();
    telefono=ui->lineEdit_10->text();

    bool aux2(!ui->lineEdit_9->text().isEmpty());
    bool aux3(!ui->lineEdit_10->text().isEmpty());

    Profesor myProfe;

    myProfe.setCode(code);                           //Se ingresan los valores dentro de un objeto profesor
    myProfe.setNombre(nombre);
    myProfe.setCorreo(correo);
    myProfe.setTelefono(telefono);
    ifstream read("Profesores.txt");
    ofstream write("Temp.txt",ios::app);

    if(!read.is_open()){
        ui->textBrowser_4->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_4->setText("");
        while (!read.eof()) {
            string auxStr;
            QString qString;
            Profesor p;
            getline(read,auxStr,',');
            if(read.eof()){
                break;
            }
            qString = QString::fromStdString(auxStr);
            p.setCode(qString);
            getline(read,auxStr,',');
            qString = QString::fromStdString(auxStr);
            p.setNombre(qString);
            getline(read,auxStr,',');
            qString = QString::fromStdString(auxStr);
            p.setCorreo(qString);
            getline(read,auxStr,'\n');
            qString = QString::fromStdString(auxStr);
            p.setTelefono(qString);

            if(p.getCode()==code)
                f=false;


            if(p.getCode()==code and aux2 and validaCorreo(myProfe.getCorreo().toStdString())){
                ui->textBrowser_4->append("____________________________");
                ui->textBrowser_4->append("::Correo Modificado::");
                flag=false;
                p.setCorreo(myProfe.getCorreo());
            }
            if(p.getCode()==code and aux3){
                ui->textBrowser_4->append("____________________________");
                ui->textBrowser_4->append("::Telefono Modificado::");
                flag=false;
                p.setTelefono(myProfe.getTelefono());
            }
            write<<p;

        }
        if(flag){
            ui->textBrowser_4->setText("::Profesor no encontrado::");
        }
        if(flag and !f){
            ui->textBrowser_4->setText("::Datos Incorrectos::");
        }

    }
    read.close();
    write.close();
    remove("Profesores.txt");
    rename("Temp.txt","Profesores.txt");
}
