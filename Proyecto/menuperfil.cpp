#include "menuperfil.h"
#include "ui_menuperfil.h"

using namespace std;

bool isEmptyP(string name){
    ifstream file(name+".txt");
    if(!file.is_open()){
        file.close();
        return true;
    }
    else{
        file.seekg(0,file.end);
        long int p = file.tellg();

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

QString getLastCodeP(string name){
    QString code;
    if(isEmptyP(name)){
        return code="1";
    }
    else{
        ifstream file(name+".txt");
        if(!file.is_open()){
            return code="1";
        }
        else{
            Perfil u;
            while (!file.eof()) {
                int a,b;

                char code[10];
                char name[30];
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

                u.setCodPerfil(qString);

                file.read((char*)&b,sizeof(int));
                file.read((char*)&name,b);
                name[b]='\0';
                auxStr=name;
                qString = QString::fromStdString(auxStr);

                u.setNombre(qString);

                file.read((char*)&status,1);
                u.setStatus(status);

            }
            file.close();
            int n(u.getCodPerfil().toInt()+1);
            QString aux(QString::number(n));
            return aux;
        }
        }

    }


MenuPerfil::MenuPerfil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPerfil)
{
    ui->setupUi(this);
}

MenuPerfil::~MenuPerfil()
{
    delete ui;
}

/*Agregar*/
void MenuPerfil::on_pushButton_8_clicked()
{
    QString nombre = ui->lineEdit_6->text();

    Perfil myPerfil;

    myPerfil.setCodPerfil(getLastCodeP("Perfiles"));
    myPerfil.setNombre(nombre);

    int b(strlen(myPerfil.getNombre().toStdString().c_str()));
    int a(strlen(myPerfil.getCodPerfil().toStdString().c_str()));

    char code[10];
    char name[30];

    char status;

    strcpy(name,myPerfil.getNombre().toStdString().c_str());
    strcpy(code,myPerfil.getCodPerfil().toStdString().c_str());


    if(!ui->lineEdit_6->text().isEmpty() ){
        ofstream archivo("Perfiles.txt",ios::app);

        archivo.write((char*)&a,sizeof(int));
        archivo.write((char*)&code,a);

        archivo.write((char*)&b,sizeof(int));
        archivo.write((char*)&name,b);

        status='1';
        archivo.write((char*)&status,1);

        archivo.close();
        QMessageBox::information(this, tr("::Éxito::"), tr("::Perfil agregado::\n"));

        ui->lineEdit_6->setText("");                     //Se limpian los espacios de los linEdits

    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llena todos los campos correctamente::"));
    }

}

/*Mostrar*/
void MenuPerfil::on_pushButton_2_clicked()
{
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

/*Limpiar mostrar*/
void MenuPerfil::on_pushButton_7_clicked()
{
    ui->textBrowser->clear();
}

/*Buscar*/
void MenuPerfil::on_pushButton_3_clicked()
{
    QString Qcode = ui->lineEdit->text();
    ui->lineEdit->clear();
    string myCode(Qcode.toStdString());
    bool flag(true);
    ifstream file("Perfiles.txt");
    if(!file.is_open()){
        ui->textBrowser_2->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_2->setText("");
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

            if(u.getStatus()=='1' and myCode==code){
                ui->textBrowser_2->append(u.toQstring());
                ui->textBrowser_2->append("____________________________");
                flag=false;
            }
        }
        file.close();
        if(flag){
            ui->textBrowser_2->setText("::Perfil Incorrecto::");

        }
    }
}

/*Eliminar*/
void MenuPerfil::on_pushButton_4_clicked()
{
    QString Qcode = ui->lineEdit_2->text();
    ui->lineEdit_2->clear();
    string myCode(Qcode.toStdString());
    bool flag(true);
    bool flagu(true);
    ifstream f("Usuarios.txt");
    if(!f.is_open()){
        ui->textBrowser->setText("::Error al abrir el archivo::");
        flagu=false;
    }
    else{
        while (!f.eof()) {
            int a,b,c,d;

            char code[10];
            char name[30];
            char pw[30];
            char codep[10];
            char status;

            string auxStr;
            QString qString;
            User u;

            f.read((char*)&a,sizeof(int));
            if(f.eof()){
                break;
            }

            f.read((char*)&code,a);
            code[a]='\0';
            auxStr=code;
            qString = QString::fromStdString(auxStr);

            u.setCodeUser(qString);

            f.read((char*)&b,sizeof(int));
            f.read((char*)&name,b);
            name[b]='\0';
            auxStr=name;
            qString = QString::fromStdString(auxStr);

            u.setNombre(qString);

            f.read((char*)&c,sizeof(int));
            f.read((char*)&pw,c);
            pw[c]='\0';
            auxStr=pw;
            qString = QString::fromStdString(auxStr);

            u.setPassword(qString);

            f.read((char*)&d,sizeof(int));
            f.read((char*)&codep,d);
            codep[d]='\0';
            auxStr=codep;
            qString = QString::fromStdString(auxStr);

            u.setCodePerfil(qString);

            f.read((char*)&status,1);
            u.setStatus(status);

            if(u.getCodePerfil()==Qcode){
                flagu=false;
            }
        }
        f.close();
    }
    if(flagu){
    ifstream file("Perfiles.txt");
    ofstream archivo("temp.txt");

    if(!file.is_open()){
        ui->textBrowser_2->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_3->setText("");
        while (!file.eof()) {
            int a,b;

            char code[10];
            char name[30];
            char status;

            string auxStr,codeuser;
            QString qString;

            Perfil u;

            file.read((char*)&a,sizeof(int));
            if(file.eof()){
                break;
            }

            file.read((char*)&code,a);
            code[a]='\0';
            codeuser=code;
            qString = QString::fromStdString(codeuser);

            u.setCodPerfil(qString);

            file.read((char*)&b,sizeof(int));
            file.read((char*)&name,b);
            name[b]='\0';
            auxStr=name;
            qString = QString::fromStdString(auxStr);

            u.setNombre(qString);

            file.read((char*)&status,1);

            u.setStatus(status);


            if(codeuser==myCode and u.getStatus()=='1'){
                ui->textBrowser_3->append(u.toQstring());
                ui->textBrowser_3->append("____________________________");
                ui->textBrowser_3->append("::Perfil eliminado::");
                flag=false;
            }

            else{
                archivo.write((char*)&a,sizeof(int));
                archivo.write((char*)&code,a);

                archivo.write((char*)&b,sizeof(int));
                archivo.write((char*)&name,b);

                archivo.write((char*)&status,1);
            }


        }
        file.close();
        archivo.close();

        remove("Perfiles.txt");
        rename("temp.txt","Perfiles.txt");
        if(flag){
            ui->textBrowser_3->setText("::Perfil Incorrecto::");
        }
    }
    }
    else{
        ui->textBrowser_3->setText("::Perfil NO eliminado::\n::Perfil con usuarios::");
    }
}

/*Desactivar*/
void MenuPerfil::on_pushButton_5_clicked()
{
    QString Qcode = ui->lineEdit_3->text();
    ui->lineEdit_3->clear();
    string myCode(Qcode.toStdString());
    bool flag(true);

    ifstream file("Perfiles.txt");
    ofstream archivo("temp.txt");

    if(!file.is_open()){
        ui->textBrowser_4->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_4->setText("");
        while (!file.eof()) {
            int a,b;

            char code[10];
            char name[30];
            char status;

            string auxStr,codeuser;
            QString qString;

            Perfil u;

            file.read((char*)&a,sizeof(int));
            if(file.eof()){
                break;
            }

            file.read((char*)&code,a);
            code[a]='\0';
            codeuser=code;
            qString = QString::fromStdString(codeuser);

            u.setCodPerfil(qString);

            file.read((char*)&b,sizeof(int));
            file.read((char*)&name,b);
            name[b]='\0';
            auxStr=name;
            qString = QString::fromStdString(auxStr);

            u.setNombre(qString);

            file.read((char*)&status,1);

            u.setStatus(status);


            if(codeuser==myCode and u.getStatus()=='1'){
                ui->textBrowser_4->append(u.toQstring());
                ui->textBrowser_4->append("____________________________");
                ui->textBrowser_4->append("::Perfil Desactivado::");
                flag=false;
                status='0';
                bool flag2(true);

                ifstream f("Usuarios.txt");
                ofstream t("t.txt");

                if(!f.is_open()){
                    ui->textBrowser_4->setText("::Error al abrir el archivo usuarios::");
                }

                else{
                    while (!f.eof()) {
                        int e,g,h,i;

                        char codeu[10];
                        char nameu[30];
                        char pw[30];
                        char codep[10];
                        char statusu;

                        string auxStru,codeuseru;
                        QString qStringu;

                        User u;

                        f.read((char*)&e,sizeof(int));
                        if(f.eof()){
                            break;
                        }

                        f.read((char*)&codeu,e);
                        codeu[e]='\0';
                        codeuseru=codeu;
                        qStringu = QString::fromStdString(codeuseru);

                        u.setCodeUser(qString);

                        f.read((char*)&g,sizeof(int));
                        f.read((char*)&nameu,g);
                        nameu[g]='\0';
                        auxStru=nameu;
                        qStringu = QString::fromStdString(auxStru);

                        u.setNombre(qStringu);

                        f.read((char*)&h,sizeof(int));
                        f.read((char*)&pw,h);
                        pw[h]='\0';
                        auxStru=pw;
                        qString = QString::fromStdString(auxStru);

                        u.setPassword(qStringu);

                        f.read((char*)&i,sizeof(int));
                        f.read((char*)&codep,i);
                        codep[i]='\0';
                        auxStru=codep;
                        qStringu = QString::fromStdString(auxStru);
                        u.setCodePerfil(qStringu);

                        f.read((char*)&statusu,1);

                        u.setStatus(statusu);


                        if(codep==myCode and u.getStatus()=='1'){
                            ui->textBrowser_4->append(u.toQstring());
                            ui->textBrowser_4->append("____________________________");
                            ui->textBrowser_4->append("::Usuario Desactivado::");
                            flag2=false;
                            statusu='0';
                        }
                        t.write((char*)&e,sizeof(int));
                        t.write((char*)&codeu,e);

                        t.write((char*)&g,sizeof(int));
                        t.write((char*)&nameu,g);

                        t.write((char*)&h,sizeof(int));
                        t.write((char*)&pw,h);

                        t.write((char*)&i,sizeof(int));
                        t.write((char*)&codep,i);

                        t.write((char*)&statusu,1);
                    }
                    f.close();
                    t.close();

                    remove("Usuarios.txt");
                    rename("t.txt","Usuarios.txt");
                    if(flag2){
                        ui->textBrowser_4->setText("::Perfil Sin Usuarios Activos::");
                    }
                }
            }
            archivo.write((char*)&a,sizeof(int));
            archivo.write((char*)&code,a);

            archivo.write((char*)&b,sizeof(int));
            archivo.write((char*)&name,b);

            archivo.write((char*)&status,1);
        }
        file.close();
        archivo.close();

        remove("Perfiles.txt");
        rename("temp.txt","Perfiles.txt");
        if(flag){
            ui->textBrowser_4->setText("::Perfil Incorrecto::");
        }
    }
}

/*Activar*/
void MenuPerfil::on_pushButton_6_clicked()
{
    QString Qcode = ui->lineEdit_4->text();
    ui->lineEdit_4->clear();
    string myCode(Qcode.toStdString());
    bool flag(true);

    ifstream file("Perfiles.txt");
    ofstream archivo("temp.txt");

    if(!file.is_open()){
        ui->textBrowser_5->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser_5->setText("");
        while (!file.eof()) {
            int a,b;

            char code[10];
            char name[30];
            char status;

            string auxStr,codeuser;
            QString qString;

            Perfil u;

            file.read((char*)&a,sizeof(int));
            if(file.eof()){
                break;
            }

            file.read((char*)&code,a);
            code[a]='\0';
            codeuser=code;
            qString = QString::fromStdString(codeuser);

            u.setCodPerfil(qString);

            file.read((char*)&b,sizeof(int));
            file.read((char*)&name,b);
            name[b]='\0';
            auxStr=name;
            qString = QString::fromStdString(auxStr);

            u.setNombre(qString);

            file.read((char*)&status,1);

            u.setStatus(status);


            if(codeuser==myCode and u.getStatus()=='0'){
                ui->textBrowser_5->append(u.toQstring());
                ui->textBrowser_5->append("____________________________");
                ui->textBrowser_5->append("::Perfil Activado::");
                flag=false;
                status='1';
                bool flag2(true);

                ifstream f("Usuarios.txt");
                ofstream t("t.txt");

                if(!f.is_open()){
                    ui->textBrowser_5->setText("::Error al abrir el archivo usuarios::");
                }

                else{
                    while (!f.eof()) {
                        int e,g,h,i;

                        char codeu[10];
                        char nameu[30];
                        char pw[30];
                        char codep[10];
                        char statusu;

                        string auxStru,codeuseru;
                        QString qStringu;

                        User u;

                        f.read((char*)&e,sizeof(int));
                        if(f.eof()){
                            break;
                        }

                        f.read((char*)&codeu,e);
                        codeu[e]='\0';
                        codeuseru=codeu;
                        qStringu = QString::fromStdString(codeuseru);

                        u.setCodeUser(qString);

                        f.read((char*)&g,sizeof(int));
                        f.read((char*)&nameu,g);
                        nameu[g]='\0';
                        auxStru=nameu;
                        qStringu = QString::fromStdString(auxStru);

                        u.setNombre(qStringu);

                        f.read((char*)&h,sizeof(int));
                        f.read((char*)&pw,h);
                        pw[h]='\0';
                        auxStru=pw;
                        qString = QString::fromStdString(auxStru);

                        u.setPassword(qStringu);

                        f.read((char*)&i,sizeof(int));
                        f.read((char*)&codep,i);
                        codep[i]='\0';
                        auxStru=codep;
                        qStringu = QString::fromStdString(auxStru);
                        u.setCodePerfil(qStringu);

                        f.read((char*)&statusu,1);

                        u.setStatus(statusu);


                        if(codep==myCode and u.getStatus()=='0'){
                            ui->textBrowser_5->append(u.toQstring());
                            ui->textBrowser_5->append("____________________________");
                            ui->textBrowser_5->append("::Usuario Activado::");
                            flag2=false;
                            statusu='1';
                        }
                        t.write((char*)&e,sizeof(int));
                        t.write((char*)&codeu,e);

                        t.write((char*)&g,sizeof(int));
                        t.write((char*)&nameu,g);

                        t.write((char*)&h,sizeof(int));
                        t.write((char*)&pw,h);

                        t.write((char*)&i,sizeof(int));
                        t.write((char*)&codep,i);

                        t.write((char*)&statusu,1);
                    }
                    f.close();
                    t.close();

                    remove("Usuarios.txt");
                    rename("t.txt","Usuarios.txt");
                    if(flag2){
                        ui->textBrowser_5->setText("::Perfil Sin Usuarios Desactivados::");
                    }
                }
            }
            archivo.write((char*)&a,sizeof(int));
            archivo.write((char*)&code,a);

            archivo.write((char*)&b,sizeof(int));
            archivo.write((char*)&name,b);

            archivo.write((char*)&status,1);
        }
        file.close();
        archivo.close();

        remove("Perfiles.txt");
        rename("temp.txt","Perfiles.txt");
        if(flag){
            ui->textBrowser_5->setText("::Perfil Incorrecto::");
        }
    }
}

/*Modificar*/
void MenuPerfil::on_pushButton_9_clicked()
{
    QString Qcode = ui->lineEdit_5->text();
    ui->lineEdit_5->clear();
    string myCode(Qcode.toStdString());
    bool flag(true),f(true);
    bool aux1(!ui->lineEdit_7->text().isEmpty());

    ui->textBrowser_6->setText("");

    ifstream file("Perfiles.txt");
    ofstream archivo("temp.txt");

    if(!file.is_open()){
        ui->textBrowser_6->setText("::Error al abrir el archivo::");
    }

    else{
        while (!file.eof()) {
            int a,b;

            char code[10];
            char name[30];
            char status;

            string auxStr,codeuser;
            QString qString;

            Perfil u;

            file.read((char*)&a,sizeof(int));
            if(file.eof()){
                break;
            }

            file.read((char*)&code,a);
            code[a]='\0';
            codeuser=code;
            qString = QString::fromStdString(codeuser);

            u.setCodPerfil(qString);

            file.read((char*)&b,sizeof(int));
            file.read((char*)&name,b);
            name[b]='\0';
            auxStr=name;
            qString = QString::fromStdString(auxStr);

            u.setNombre(qString);

            file.read((char*)&status,1);

            u.setStatus(status);

            Perfil p;

            if(codeuser==myCode and u.getStatus()=='1'){
                f=false;
            }

            if(codeuser==myCode and u.getStatus()=='1' and aux1){
                ui->textBrowser_6->append("____________________________");
                ui->textBrowser_6->append("::Nombre Modificado::");
                QString nombre = ui->lineEdit_7->text();
                p.setNombre(nombre);
                b=strlen(p.getNombre().toStdString().c_str());
                strcpy(name,p.getNombre().toStdString().c_str());
                flag=false;
            }

            archivo.write((char*)&a,sizeof(int));
            archivo.write((char*)&code,a);

            archivo.write((char*)&b,sizeof(int));
            archivo.write((char*)&name,b);

            archivo.write((char*)&status,1);

        }
        file.close();
        archivo.close();

        remove("Perfiles.txt");
        rename("temp.txt","Perfiles.txt");
        if(f){
            ui->textBrowser_6->setText("::Perfil Incorrecto::");
        }
        if(flag and !f){
            ui->textBrowser_6->setText("::Ingrese los datos a modificar::");
        }
    }
}

/*Regresar*/
void MenuPerfil::on_pushButton_clicked()
{
    MenuSU *SU = new MenuSU();
    this->hide();
    SU->show();
    this->close();
}
