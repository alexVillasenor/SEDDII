#include "menudisponibilidad.h"
#include "ui_menudisponibilidad.h"

MenuDisponibilidad::MenuDisponibilidad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuDisponibilidad)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{6}")));
    ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]{6}")));
    ui->lineEdit_3->setValidator(new QRegExpValidator(QRegExp("[0-9]{6}")));
    ui->comboBox_Carrera->clear();
    ui->comboBox_Materias->clear();
    ui->comboBox_Profesor->clear();
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->dateTimeEdit->setCalendarPopup(true);
    ui->dateTimeEdit->setDate(QDate::currentDate());
    ui->dateTimeEdit->setTime(QTime::currentTime());
    loadIndex();
    setCarreras();
    setMaterias(1);
    setProfesores();
    ifstream f("Dispersa.txt");
    if(!f.is_open()){
        genera("Dispersa.txt");
    }
    else{
        int myInt;
        ifstream t(".tamano");
        t.read((char*)&myInt,sizeof(myInt));
        FILAS=myInt;
        t.read((char*)&myInt,sizeof(myInt));
        COLUMNAS=myInt;
        t.close();
        f.close();
    }
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
            if(type==1)
                ui->comboBox_Profesor->addItem(p.getCode()+" - "+p.getNombre());
            else if(type==4 && p.getCode()==code){
                ui->comboBox_Profesor->addItem(p.getCode()+" - "+p.getNombre());
            }
            flag=false;
        }
        file.close();
        if(flag){
            QMessageBox::information(this, tr("::Error::"), tr("::No hay profesores registrados::"));
        }
    }
}

void MenuDisponibilidad::setMaterias(int j)
{
    if(!ui->comboBox_Carrera->currentText().isEmpty()){
        Programa* auxPrograma;
        if(j==1){
            auxPrograma = listainvertida.findPrograma(ui->comboBox_Carrera->currentText());
        }
        else if(j==2){
            auxPrograma = listainvertida.findPrograma(ui->comboBox->currentText());
        }

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
                    if(j==1)
                        ui->comboBox_Materias->addItem(QString::number(a.getCodigo())+" - "+a.getNombre());
                    else if(j==2)
                        ui->comboBox_2->addItem(QString::number(a.getCodigo())+" - "+a.getNombre());
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
        ui->comboBox->addItem(aux->getNombre());
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

void MenuDisponibilidad::genera(string s)
{
    Disponibilidad d;
    int cont(0);
    ofstream file(s,ios::app);
    for(int i(0);i<FILAS;i++){
        file.write((char*)&cont,sizeof(cont));
        for(int j(0);j<COLUMNAS;j++){
            file.write((char*)&d,sizeof(d));
        }
    }
    ofstream t(".tamano");
    cont=FILAS;
    t.write((char*)&cont,sizeof(cont));
    cont=COLUMNAS;
    t.write((char*)&cont,sizeof(cont));
    t.close();
    file.close();
}

long MenuDisponibilidad::dispersion(string clave)
{
    int i(0);
    int direccionBase(0);
    if(FILAS==100){
        while(i<clave.length()){
            direccionBase+=((100*clave[i])+(clave[i+1]%84645));
            i+=2;
        }
    }
    else{///modificar
        while(i<clave.length()){
            direccionBase+=(direccionBase*32)+(clave[i]%2937413);
            i++;
        }
    }
    direccionBase=abs(direccionBase%FILAS);
    return direccionBase;
}

void MenuDisponibilidad::expand(int c,int f,int t)
{
    if(t==1)
        COLUMNAS*=2;
    if(t==2)
        FILAS*=2;
    genera("temp.txt");
    fstream temp("temp.txt");
    ifstream file("Dispersa.txt");
    int pos(0),cont;
    Disponibilidad d;
    if(!file.is_open()){
        QMessageBox::information(this, tr("::Error::"), tr("::No se pudo abrir el archivo::"));
    }
    else{
        while(!file.eof()){
            file.seekg(pos,ios::beg);
            file.read((char*)&cont,sizeof(cont));
            if(cont==0){
                pos=pos+(c*sizeof(d))+sizeof(cont);
            }
            else{
                for(int i(0);i<cont;i++){
                    file.read((char*)&d,sizeof(d));

                    string clave=d.getClaveProf().toStdString()+d.getClaveAsig().toStdString();
                    long int dBase=dispersion(clave);
                    long int aux=dBase,aux2;
                    int cont2;
                    dBase=dBase*((sizeof(d)*COLUMNAS)+sizeof(cont2));
                    temp.seekg(dBase,ios::beg);
                    temp.read((char*)&cont2,sizeof(cont2));
                    if(cont2 == COLUMNAS){
                        QMessageBox::information(this, tr("::Error::"), tr("::No hay espacio para esta llave::"));
                    }
                    else{
                        long int pos = dBase+(cont2*sizeof(d))+sizeof(cont2);
                        aux2=pos;
                        temp.seekp(pos,ios::beg);
                        temp.write((char*)&d,sizeof(d));
                        cont2++;
                        pos=dBase;
                        temp.seekp(pos,ios::beg);
                        temp.write((char*)&cont2,sizeof(cont2));
                    }
                }
                pos=pos+(c*sizeof(d))+sizeof(cont);
            }
        }
        file.close();
        temp.close();
        remove("Dispersa.txt");
        rename("temp.txt","Dispersa.txt");
    }
}

/*Regresar*/
void MenuDisponibilidad::on_pushButton_clicked()
{
    if(type==1){
        MenuSU *SU = new MenuSU();
        this->hide();
        SU->setCode(code);
        SU->show();
        this->close();

    }
    else if(type==4){
        ProfesorMenu *menuProf = new ProfesorMenu();
        this->hide();
        menuProf->setCode(code);
        menuProf->show();
        this->close();

    }
}

/*Agregar*/
void MenuDisponibilidad::on_pushButton_2_clicked()
{
    string clave,auxStr;
    QString llave;
    QDate today=QDate::currentDate();
    QTime now=QTime::currentTime();
    Disponibilidad d;
    int cont;

    auxStr=ui->comboBox_Profesor->currentText().toStdString().substr(0,3);
    llave=auxStr.c_str();
    clave=auxStr;
    d.setClaveProf(llave);
    auxStr=ui->comboBox_Materias->currentText().toStdString().substr(0,3);
    llave=auxStr.c_str();
    clave+=auxStr;
    d.setClaveAsig(llave);

    d.setFecha(today);
    d.setHora(now);
    long int dBase=dispersion(clave);
    long int aux=dBase,aux2;
    QString qStr=clave.c_str();
    qDebug()<<"Clave: "<<qStr;
    qDebug()<<"Direccion Base: "<<dBase;
    if(!buscar(qStr)){
        fstream file("Dispersa.txt");
        dBase=dBase*((sizeof(d)*COLUMNAS)+sizeof(cont));
        file.seekg(dBase,ios::beg);
        file.read((char*)&cont,sizeof(cont));
        if(cont == COLUMNAS){
            QMessageBox::information(this, tr("::Error::"), tr("::No hay espacio para esta llave::"));
        }
        else{
            long int pos = dBase+(cont*sizeof(d))+sizeof(cont);
            aux2=pos;
            file.seekp(pos,ios::beg);
            file.write((char*)&d,sizeof(d));
            cont++;
            pos=dBase;
            file.seekp(pos,ios::beg);
            file.write((char*)&cont,sizeof(cont));
            QMessageBox::information(this, tr("::Exito::"), tr("::Disponibilidad agregada::"));
        }
        file.close();
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llave Existente::"));
    }
}

/*Mostrar*/
void MenuDisponibilidad::on_pushButton_3_clicked()
{
    ui->textBrowser->clear();
    ifstream file("Dispersa.txt");
    int pos(0),cont;
    Disponibilidad d;
    if(!file.is_open()){
        ui->textBrowser->setText("::Error al abrir el archivo::");
    }
    else{
        while(!file.eof()){
            file.seekg(pos,ios::beg);
            file.read((char*)&cont,sizeof(cont));
            if(cont==0){
                pos=pos+(COLUMNAS*sizeof(d))+sizeof(cont);
            }
            else{
                for(int i(0);i<cont;i++){
                    file.read((char*)&d,sizeof(d));
                    if(type==1)
                        ui->textBrowser->append(d.toQstring());
                    else if(type==4 && d.getClaveProf()==code)
                        ui->textBrowser->append(d.toQstring());
                }
                pos=pos+(COLUMNAS*sizeof(d))+sizeof(cont);
            }
        }
        file.close();
    }
}

bool MenuDisponibilidad::buscar(QString clave){
    long int dBase=dispersion(clave.toStdString());

    ifstream file("Dispersa.txt");
    if(!file.is_open()){
        return false;
    }
    else{
        Disponibilidad d;
        int cont;
        long int pos=dBase*((COLUMNAS*sizeof(d))+sizeof(cont));
        file.seekg(pos,ios::beg);
        file.read((char*)&cont,sizeof(cont));
        if(cont==0){
            file.close();
            return false;
        }
        else{
            for(int i(0);i<cont;i++){
                file.read((char*)&d,sizeof(d));
                QString llave=d.getClaveProf();
                llave+=d.getClaveAsig();
                if(type==1 && llave==clave){
                    file.close();
                    return true;
                }
                else if(type==4 && d.getClaveProf()==code && llave==clave){
                    file.close();
                    return true;
                }
                else{
                    file.close();
                    return false;
                }
            }
        }
        file.close();
    }
    file.close();
    return false;
}

/*Buscar*/
void MenuDisponibilidad::on_pushButton_4_clicked()
{
    ui->textBrowser_2->clear();
    if(!ui->lineEdit->text().isEmpty()){
        QString clave=ui->lineEdit->text();
        long int dBase=dispersion(clave.toStdString());

        ifstream file("Dispersa.txt");
        if(!file.is_open()){
            ui->textBrowser_2->setText("::Error al abrir el archivo::");
        }
        else{
            Disponibilidad d;
            int cont;
            long int pos=dBase*((COLUMNAS*sizeof(d))+sizeof(cont));
            file.seekg(pos,ios::beg);
            file.read((char*)&cont,sizeof(cont));
            if(cont==0){
                ui->textBrowser_2->setText("::Clave Erronea::");
            }
            else{
                for(int i(0);i<cont;i++){
                    file.read((char*)&d,sizeof(d));
                    QString llave=d.getClaveProf();
                    llave+=d.getClaveAsig();
                    if(type==1 && llave==clave)
                        ui->textBrowser_2->setText(d.toQstring());
                    else if(type==4 && d.getClaveProf()==code && llave==clave)
                        ui->textBrowser_2->setText(d.toQstring());
                    else
                        ui->textBrowser_2->setText("::Clave Erronea1::");
                }
            }
            file.close();
        }
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llene los campos correctamente::"));
    }

}

bool MenuDisponibilidad::eliminar(QString clave){

    long int dBase=dispersion(clave.toStdString());
    bool flag(false);
    fstream file("Dispersa.txt");
    if(!file.is_open()){
        flag=false;
    }
    else{
        Disponibilidad d;
        int cont;
        long int pos=dBase*((COLUMNAS*sizeof(d))+sizeof(cont));
        file.seekg(pos,ios::beg);
        file.read((char*)&cont,sizeof(cont));
        if(cont==0){
            flag=false;
        }
        else{
            for(int i(1);i<=cont;i++){
                long int pos2 = file.tellg();
                file.read((char*)&d,sizeof(d));
                QString llave=d.getClaveProf();
                llave+=d.getClaveAsig();
                if(type==1 && llave==clave){
                    flag=true;
                }
                else if(type==4 && d.getClaveProf()==code && llave==clave){
                    flag=true;
                }
                else{
                }

                if(flag && i<cont){
                    Disponibilidad d2;
                    long int p3 =file.tellg();
                    file.read((char*)&d2,sizeof(d2));
                    file.seekp(pos2,ios::beg);
                    file.write((char*)&d2,sizeof(d2));
                    file.seekg(p3,ios::beg);
                }
            }
            if(flag){
                cont--;
                file.seekp(pos,ios::beg);
                file.write((char*)&cont,sizeof(cont));
            }
        }
        file.close();
    }
    return flag;
}

/*Eliminar*/
void MenuDisponibilidad::on_pushButton_5_clicked()
{
    ui->textBrowser_3->clear();
    if(!ui->lineEdit_2->text().isEmpty()){
        QString clave=ui->lineEdit_2->text();
        long int dBase=dispersion(clave.toStdString());

        fstream file("Dispersa.txt");
        if(!file.is_open()){
            ui->textBrowser_3->setText("::Error al abrir el archivo::");
        }
        else{
            Disponibilidad d;
            int cont;
            long int pos=dBase*((COLUMNAS*sizeof(d))+sizeof(cont));
            file.seekg(pos,ios::beg);
            file.read((char*)&cont,sizeof(cont));
            if(cont==0){
                ui->textBrowser_3->setText("::Clave Erronea::");
            }
            else{
                for(int i(0);i<cont;i++){
                    file.read((char*)&d,sizeof(d));
                    QString llave=d.getClaveProf();
                    llave+=d.getClaveAsig();
                    if(type==1 && llave==clave){
                        file.close();
                        eliminar(llave);
                        ui->textBrowser_3->append(d.toQstring());
                        ui->textBrowser_3->append("::Eliminado::");
                        break;
                    }
                    else if(type==4 && d.getClaveProf()==code && llave==clave){
                        file.close();
                        eliminar(llave);
                        ui->textBrowser_3->append(d.toQstring());
                        ui->textBrowser_3->append("::Eliminado::");
                        break;
                    }
                }
            }
            file.close();
        }
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llene los campos correctamente::"));
    }
}

/*Modificar*/
void MenuDisponibilidad::on_pushButton_6_clicked()
{
    ui->textBrowser_4->clear();
    qDebug()<<dispersion(ui->lineEdit_4->text().toStdString());
    if(!ui->lineEdit_3->text().isEmpty()){
        QString clave=ui->lineEdit_3->text();
        QDate newDate=ui->dateTimeEdit->date();
        QTime newTime=ui->dateTimeEdit->time();
        string newAsig = ui->comboBox_2->currentText().toStdString().substr(0,3);
        QString auxQstr = newAsig.c_str();
        string newClave;


        long int dBase=dispersion(clave.toStdString());

        fstream file("Dispersa.txt");
        if(!file.is_open()){
            ui->textBrowser_4->setText("::Error al abrir el archivo::");
        }
        else{
            Disponibilidad d;
            int cont;
            long int pos=dBase*((COLUMNAS*sizeof(d))+sizeof(cont));
            file.seekg(pos,ios::beg);
            file.read((char*)&cont,sizeof(cont));
            if(cont==0){
                ui->textBrowser_4->setText("::Clave Erronea::");
            }
            else{
                for(int i(0);i<cont;i++){
                    file.read((char*)&d,sizeof(d));
                    QString llave=d.getClaveProf();
                    llave+=d.getClaveAsig();
                    if(type==1 && llave==clave){
                        ui->textBrowser_4->append(d.toQstring());
                        d.setFecha(newDate);
                        d.setHora(newTime);
                        d.setClaveAsig(auxQstr);
                        newClave=d.getClaveProf().toStdString();
                        newClave+=newAsig;

                        long int newDBase = dispersion(newClave);
                        QString qStr=newClave.c_str();
                        qDebug()<<"Clave: "<<qStr;
                        qDebug()<<"Direccion Base: "<<newDBase;
                        long int aux=newDBase,aux2;
                        if(!buscar(d.getClaveProf()+d.getClaveAsig())){
                            eliminar(llave);
                            newDBase=newDBase*((sizeof(d)*COLUMNAS)+sizeof(cont));
                            file.seekg(newDBase,ios::beg);
                            file.read((char*)&cont,sizeof(cont));
                            if(cont == COLUMNAS){
                                QMessageBox::information(this, tr("::Error::"), tr("::No hay espacio para esta llave::"));
                            }
                            else{
                                long int pos = newDBase+(cont*sizeof(d))+sizeof(cont);
                                aux2=pos;
                                file.seekp(pos,ios::beg);
                                file.write((char*)&d,sizeof(d));
                                cont++;
                                pos=newDBase;
                                file.seekp(pos,ios::beg);
                                file.write((char*)&cont,sizeof(cont));
                                ui->textBrowser_4->append("::Modificado::");
                            }
                        }
                        else{
                            QMessageBox::information(this, tr("::Error::"), tr("::Llave Existente::"));
                        }
                        break;
                    }
                    else if(type==4 && d.getClaveProf()==code && llave==clave){
                        ui->textBrowser_4->append(d.toQstring());
                        d.setFecha(newDate);
                        d.setHora(newTime);
                        d.setClaveAsig(auxQstr);
                        newClave=d.getClaveProf().toStdString();
                        newClave+=newAsig;

                        if(!buscar(d.getClaveProf()+d.getClaveAsig())){
                            eliminar(llave);
                            long int newDBase = dispersion(newClave);
                            long int aux=newDBase,aux2;

                            newDBase=newDBase*((sizeof(d)*COLUMNAS)+sizeof(cont));
                            file.seekg(newDBase,ios::beg);
                            file.read((char*)&cont,sizeof(cont));
                            if(cont == COLUMNAS){
                                QMessageBox::information(this, tr("::Error::"), tr("::No hay espacio para esta llave::"));
                            }
                            else{
                                long int pos = newDBase+(cont*sizeof(d))+sizeof(cont);
                                aux2=pos;
                                file.seekp(pos,ios::beg);
                                file.write((char*)&d,sizeof(d));
                                cont++;
                                pos=newDBase;
                                file.seekp(pos,ios::beg);
                                file.write((char*)&cont,sizeof(cont));
                                ui->textBrowser_4->append("::Modificado::");
                            }
                        }
                        else{
                            QMessageBox::information(this, tr("::Error::"), tr("::Llave Existente::"));
                        }
                        break;
                    }
                }
            }
            file.close();
        }
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llene los campos correctamente::"));
    }
}

/*Expancion filas*/
void MenuDisponibilidad::on_pushButton_7_clicked()
{
    if(FILAS==100)
    {
        expand(COLUMNAS,FILAS,2);
        QMessageBox::information(this, tr("::Exito::"), tr("::Filas duplicadas::"));
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Filas ya han sido duplicadas::"));
    }

}

/*Expancion columnas*/
void MenuDisponibilidad::on_pushButton_8_clicked()
{
    expand(COLUMNAS,FILAS,1);
    QMessageBox::information(this, tr("::Exito::"), tr("::Columnas duplicadas::"));

}

void MenuDisponibilidad::on_comboBox_activated(const QString &arg1)
{
    ui->comboBox_2->clear();
    setMaterias(2);
}

void MenuDisponibilidad::on_comboBox_Carrera_activated(const QString &arg1)
{
    ui->comboBox_Materias->clear();
    setMaterias(1);
}

void MenuDisponibilidad::on_tabWidget_currentChanged(int index)
{
    ui->comboBox_Materias->clear();
    setMaterias(1);
    ui->comboBox_2->clear();
    setMaterias(2);
}

QString MenuDisponibilidad::getCode() const
{
    return code;
}

void MenuDisponibilidad::setCode(const QString &value)
{
    code = value;
}

int MenuDisponibilidad::getType() const
{
    return type;
}

void MenuDisponibilidad::setType(int value)
{
    type = value;
}
