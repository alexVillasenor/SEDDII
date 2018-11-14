#include "menuuser.h"
#include "ui_menuuser.h"
#include <fstream>

using namespace std;

bool isEmpty(string name){
    ifstream file(name+".txt");
    if(!file.is_open()){
        file.close();
        return true;
    }
    else{
        file.seekg(0,file.end);
        long int p=file.tellg();
        if(p==0){
            file.close();
            return true;
        }
        else{
            file.close();
            return false;
        }
    }
}

QString getLastCode(string name){
    QString code;
    if(isEmpty(name)){
        return code="300";
    }
    else{
        ifstream file(name+".txt");
        if(!file.is_open()){
            return code="300";
        }
        else{
            User u;
            while (!file.eof()) {
                int a,b,c,d;

                char code[10];
                char name[30];
                char pw[30];
                char codep[10];
                char status;

                string auxStr;
                QString qString;

                file.read((char*)&a,sizeof(int));
                if(file.eof()){
                    break;
                }

                file.read((char*)&code,a);
                code[a]='\0';
                auxStr=code;
                qString = QString::fromStdString(auxStr);

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

            }
            file.close();
            int n(u.getCodeUser().toInt()+1);
            QString aux(QString::number(n));
            return aux;
        }
        }

    }


MenuUser::MenuUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuUser)
{
    ui->setupUi(this);

    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z\\ñ]+\\s?[a-zA-Z\\ñ]+\\s?[a-zA-Z\\ñ]+\\s[a-zA-Z\\ñ]+")));

    ui->comboBox->clear();
    ui->comboBox_2->clear();

    bool flag(true);
    ifstream file("Perfiles.txt");
    if(!file.is_open()){
        ui->textBrowser->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser->setText("");
        while (!file.eof()) {
            int a,b;

            char code[10];
            char name[30];
            char status;

            string auxStr;
            QString qString;
            Perfil u;

            file.read((char*)&a,sizeof(int));
            if(file.eof()){
                break;
            }

            file.read((char*)&code,a);
            code[a]='\0';
            auxStr=code;
            qString = QString::fromStdString(auxStr);

            u.setCodPerfil(qString);

            file.read((char*)&b,sizeof(int));
            file.read((char*)&name,b);
            name[b]='\0';
            auxStr=name;
            qString = QString::fromStdString(auxStr);

            u.setNombre(qString);

            file.read((char*)&status,1);
            u.setStatus(status);

            if(u.getStatus()=='1'){
                ui->comboBox->addItem(u.getNombre());
                ui->comboBox_2->addItem(u.getNombre());
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

MenuUser::~MenuUser()
{
    delete ui;
}

/*Agregar Usuario*/
void MenuUser::on_pushButton_3_clicked()
{
    QString tipo = ui->comboBox->currentText();
    QString nombre = ui->lineEdit->text();
    QString contrasenia = ui->lineEdit_2->text();

    User myUser;

    if(tipo.toStdString()=="Administrador"){
        myUser.setCodePerfil("1");
    }
    else if(tipo.toStdString()=="Coordinador Academico"){
        myUser.setCodePerfil("2");
    }
    else if(tipo.toStdString()=="Asistente Academico"){
        myUser.setCodePerfil("3");
    }
    else if(tipo.toStdString()=="Profesor"){
        myUser.setCodePerfil("4");
    }
    if(tipo.toStdString()==""){
        myUser.setCodePerfil("0");
    }


    myUser.setCodeUser(getLastCode("Usuarios"));
    myUser.setNombre(nombre);
    myUser.setPassword(contrasenia);


    int a(strlen(myUser.getCodeUser().toStdString().c_str()));
    int b(strlen(myUser.getNombre().toStdString().c_str()));
    int c(strlen(myUser.getPassword().toStdString().c_str()));
    int d(strlen(myUser.getCodePerfil().toStdString().c_str()));

    char code[10];
    char name[30];
    char pw[30];
    char codep[10];
    char status;

    strcpy(code,myUser.getCodeUser().toStdString().c_str());
    strcpy(name,myUser.getNombre().toStdString().c_str());
    strcpy(pw,myUser.getPassword().toStdString().c_str());
    strcpy(codep,myUser.getCodePerfil().toStdString().c_str());


    if(!ui->lineEdit->text().isEmpty() and !ui->lineEdit_2->text().isEmpty() and myUser.getCodePerfil()!='0'){
        ofstream archivo("Usuarios.txt",ios::app);

        archivo.write((char*)&a,sizeof(int));
        archivo.write((char*)&code,a);

        archivo.write((char*)&b,sizeof(int));
        archivo.write((char*)&name,b);

        archivo.write((char*)&c,sizeof(int));
        archivo.write((char*)&pw,c);

        archivo.write((char*)&d,sizeof(int));
        archivo.write((char*)&codep,d);

        status='1';
        archivo.write((char*)&status,1);

        archivo.close();

        ui->lineEdit->setText("");                     //Se limpian los espacios de los linEdits
        ui->lineEdit_2->setText("");
        if(myUser.getCodePerfil()=="4"){
            MenuProfesor *menuProfesor = new MenuProfesor();
            hide();
            menuProfesor->setPerfil("4");
            menuProfesor->setPermisos();
            menuProfesor->setCode(myUser.getCodeUser());
            menuProfesor->setNombre(myUser.getNombre());
            menuProfesor->show();
            this->close();
        }

    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llena todos los campos correctamente::"));
    }


}

/*Mostrar Usuarios*/
void MenuUser::on_pushButton_2_clicked()
{
    bool flag(true);
    ifstream file("Usuarios.txt");
    if(!file.is_open()){
        ui->textBrowser->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser->setText("");
        while (!file.eof()) {
            int a,b,c,d;

            char code[10];
            char name[30];
            char pw[30];
            char codep[10];
            char status;

            string auxStr;
            QString qString;
            User u;

            file.read((char*)&a,sizeof(int));
            if(file.eof()){
                break;
            }

            file.read((char*)&code,a);
            code[a]='\0';
            auxStr=code;
            qString = QString::fromStdString(auxStr);

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

            if(u.getStatus()=='1'){
                ui->textBrowser->append(u.toQstring());
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
void MenuUser::on_pushButton_4_clicked()
{
    QString Qcode = ui->lineEdit_3->text();
    ui->lineEdit_3->clear();
    string myCode(Qcode.toStdString());
    bool flag(true);

    ifstream file("Usuarios.txt");
    if(!file.is_open()){
        ui->textBrowser_2->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_2->setText("");
        while (!file.eof()) {
            int a,b,c,d;

            char code[10];
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


            if(codeuser==myCode and u.getStatus()=='1'){
                ui->textBrowser_2->append(u.toQstring());
                ui->textBrowser_2->append("____________________________");
                flag=false;
            }
        }
        file.close();
        if(flag){
            ui->textBrowser_2->setText("::Usuario Incorrecto::");
        }
    }
}

/*Limpiar pantalla mostrar*/
void MenuUser::on_pushButton_6_clicked()
{
    ui->textBrowser->setText("");
}

/*Eliminar*/
void MenuUser::on_pushButton_5_clicked()
{
    QString Qcode = ui->lineEdit_4->text();
    ui->lineEdit_4->clear();
    string myCode(Qcode.toStdString());
    bool flag(true);

    ifstream file("Usuarios.txt");
    ofstream archivo("temp.txt");

    if(!file.is_open()){
        ui->textBrowser_3->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_3->setText("");
        while (!file.eof()) {
            int a,b,c,d;

            char code[10];
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


            if(codeuser==myCode and u.getStatus()=='1'){
                if(u.getCodePerfil()=="4"){
                    bool flag;

                    ifstream read("Profesores.txt");
                    ofstream write("Temp2.txt",ios::app);
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

                            if(p.getCode()==Qcode){
                                flag=true;
                                ui->textBrowser_3->append(p.toQString());
                                ui->textBrowser_3->append("____________________________");
                                ui->textBrowser_3->append("::Profesor Eliminado::");
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
                        rename("Temp2.txt","Profesores.txt");
                    }
                }
                ui->textBrowser_3->append(u.toQstring());
                ui->textBrowser_3->append("____________________________");
                ui->textBrowser_3->append("::Usuario eliminado::");
                flag=false;
            }

            else{
                archivo.write((char*)&a,sizeof(int));
                archivo.write((char*)&code,a);

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
        rename("temp.txt","Usuarios.txt");
        if(flag){
            ui->textBrowser_3->setText("::Usuario Incorrecto::");
        }
    }
}

/*Desactivar*/
void MenuUser::on_pushButton_7_clicked()
{
    QString Qcode = ui->lineEdit_5->text();
    ui->lineEdit_5->clear();
    string myCode(Qcode.toStdString());
    bool flag(true);

    ifstream file("Usuarios.txt");
    ofstream archivo("temp.txt");

    if(!file.is_open()){
        ui->textBrowser_4->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_4->setText("");
        while (!file.eof()) {
            int a,b,c,d;

            char code[10];
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


            if(codeuser==myCode and u.getStatus()=='1'){
                ui->textBrowser_4->append(u.toQstring());
                ui->textBrowser_4->append("____________________________");
                ui->textBrowser_4->append("::Usuario Desactivado::");
                flag=false;
                status='0';
            }
            archivo.write((char*)&a,sizeof(int));
            archivo.write((char*)&code,a);

            archivo.write((char*)&b,sizeof(int));
            archivo.write((char*)&name,b);

            archivo.write((char*)&c,sizeof(int));
            archivo.write((char*)&pw,c);

            archivo.write((char*)&d,sizeof(int));
            archivo.write((char*)&codep,d);

            archivo.write((char*)&status,1);
        }
        file.close();
        archivo.close();

        remove("Usuarios.txt");
        rename("temp.txt","Usuarios.txt");
        if(flag){
            ui->textBrowser_4->setText("::Usuario Incorrecto::");
        }
    }
}

/*Activar*/
void MenuUser::on_pushButton_8_clicked()
{
    QString Qcode = ui->lineEdit_6->text();
    ui->lineEdit_6->clear();
    string myCode(Qcode.toStdString());
    bool flag(true);

    ifstream file("Usuarios.txt");
    ofstream archivo("temp.txt");

    if(!file.is_open()){
        ui->textBrowser_5->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_5->setText("");
        while (!file.eof()) {
            int a,b,c,d;

            char code[10];
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


            if(codeuser==myCode and u.getStatus()=='0'){
                ui->textBrowser_5->append(u.toQstring());
                ui->textBrowser_5->append("____________________________");
                ui->textBrowser_5->append("::Usuario Activado::");
                flag=false;
                status='1';
            }

            archivo.write((char*)&a,sizeof(int));
            archivo.write((char*)&code,a);

            archivo.write((char*)&b,sizeof(int));
            archivo.write((char*)&name,b);

            archivo.write((char*)&c,sizeof(int));
            archivo.write((char*)&pw,c);

            archivo.write((char*)&d,sizeof(int));
            archivo.write((char*)&codep,d);

            archivo.write((char*)&status,1);

        }
        file.close();
        archivo.close();

        remove("Usuarios.txt");
        rename("temp.txt","Usuarios.txt");
        if(flag){
            ui->textBrowser_5->setText("::Usuario Incorrecto::");
        }
    }
}

bool deleteProfesor(QString code){
    bool flag;

    ifstream read("Profesores.txt");
    ofstream write("t.txt",ios::app);
    if(!read.is_open()){

    }

    else{
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

            }
            else{
                write<<p;
            }
        }
        read.close();
        write.close();

        remove("Profesores.txt");
        rename("t.txt","Profesores.txt");
    }

}

/*Editar*/
void MenuUser::on_pushButton_9_clicked()
{
    QString Qcode = ui->lineEdit_8->text();
    ui->lineEdit_8->clear();
    string myCode(Qcode.toStdString());
    bool flag(true),f(true);
    bool aux1(!ui->lineEdit_9->text().isEmpty());
    bool aux2(!ui->lineEdit_10->text().isEmpty());
    bool aux3(!ui->comboBox_2->currentText().isEmpty());

    ui->textBrowser_6->setText("");

    ifstream file("Usuarios.txt");
    ofstream archivo("temp.txt");

    if(!file.is_open()){
        ui->textBrowser_6->setText("::Error al abrir el archivo::");
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
            QString qString,aux;

            User u;

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

            User myUser;

            if(codeuser==myCode and u.getStatus()=='1'){
                f=false;
            }

            if(codeuser==myCode and u.getStatus()=='1' and aux1){
                ui->textBrowser_6->append("____________________________");
                ui->textBrowser_6->append("::Nombre Modificado::");
                QString nombre = ui->lineEdit_9->text();
                myUser.setNombre(nombre);
                b=strlen(myUser.getNombre().toStdString().c_str());
                strcpy(name,myUser.getNombre().toStdString().c_str());
                flag=false;
            }

            if(codeuser==myCode and u.getStatus()=='1' and aux2){
                ui->textBrowser_6->append("____________________________");
                ui->textBrowser_6->append("::Contraseña Modificado::");
                QString contrasenia = ui->lineEdit_10->text();
                myUser.setPassword(contrasenia);
                c=strlen(myUser.getPassword().toStdString().c_str());
                strcpy(pw,myUser.getPassword().toStdString().c_str());
                flag=false;
            }
            if(codeuser==myCode and u.getStatus()=='1' and aux3){
                ui->textBrowser_6->append("____________________________");
                ui->textBrowser_6->append("::Perfil Modificado::");
                QString tipo = ui->comboBox_2->currentText();
                if(tipo.toStdString()=="Administrador"){
                    myUser.setCodePerfil("1");
                    if(u.getCodePerfil()=="4")
                        deleteProfesor(u.getCodeUser());
                }
                else if(tipo.toStdString()=="Coordinador Academico"){
                    myUser.setCodePerfil("2");
                    if(u.getCodePerfil()=="4")
                        deleteProfesor(u.getCodeUser());
                }
                else if(tipo.toStdString()=="Asistente Academico"){
                    myUser.setCodePerfil("3");
                    if(u.getCodePerfil()=="4")
                        deleteProfesor(u.getCodeUser());
                }
                else if(tipo.toStdString()=="Profesor"){
                    myUser.setCodePerfil("4");
                    MenuProfesor *menuProfesor = new MenuProfesor();
                    hide();
                    menuProfesor->setPerfil("4");
                    menuProfesor->setPermisos();
                    menuProfesor->setCode(u.getCodeUser());
                    menuProfesor->setNombre(u.getNombre());
                    menuProfesor->show();
                    this->close();

                }
                d=strlen(myUser.getCodePerfil().toStdString().c_str());
                strcpy(codep,myUser.getCodePerfil().toStdString().c_str());
                flag=false;
            }


            archivo.write((char*)&a,sizeof(int));
            archivo.write((char*)&code,a);

            archivo.write((char*)&b,sizeof(int));
            archivo.write((char*)&name,b);

            archivo.write((char*)&c,sizeof(int));
            archivo.write((char*)&pw,c);

            archivo.write((char*)&d,sizeof(int));
            archivo.write((char*)&codep,d);

            archivo.write((char*)&status,1);

        }
        if(f){
            ui->textBrowser_6->setText("::Usuario Incorrecto::");
        }
        if(flag and !f){
            ui->textBrowser_6->setText("::Ingrese los datos a modificar::");
        }
    }
    file.close();
    archivo.close();

    remove("Usuarios.txt");
    rename("temp.txt","Usuarios.txt");
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
}

/*Regresar*/
void MenuUser::on_pushButton_clicked()
{
    MenuSU *SU = new MenuSU();
    this->hide();
    SU->show();
    this->close();

}
