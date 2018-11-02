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
    ifstream f("Dispersa.txt");
    if(!f.is_open()){
        genera();
    }
    else{
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

void MenuDisponibilidad::genera()
{
    Disponibilidad d;
    int cont(0);
    ofstream file("Dispersa.txt",ios::app);
    for(int i(0);i<FILAS;i++){
        file.write((char*)&cont,sizeof(cont));
        for(int j(0);j<COLUMNAS;j++){
            file.write((char*)&d,sizeof(d));
        }
    }
    file.close();
}

long MenuDisponibilidad::dispersion(string clave)
{
    int i(0);
    int direccionBase(0);
    while(i<clave.length()){
        direccionBase+=((FILAS*clave[i])+(clave[i+1]%84645));
        i+=2;
    }
    direccionBase=direccionBase%FILAS;
    return direccionBase;
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
        delete this;
    }
    else if(type==4){
        ProfesorMenu *menuProf = new ProfesorMenu();
        this->hide();
        menuProf->setCode(code);
        menuProf->show();
        this->close();
        delete this;
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

    qDebug()<<llave;
    qDebug()<<today;
    qDebug()<<now;
    qDebug()<<dBase;

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
                        ui->textBrowser_2->append(d.toQstring());
                    else if(type==4 && d.getClaveProf()==code && llave==clave)
                        ui->textBrowser_2->append(d.toQstring());
                    else
                        ui->textBrowser_2->setText("::Clave Erronea::");
                }
            }
            file.close();
        }
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llene los campos correctamente::"));
    }

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
                        cont--;
                        file.seekp(pos,ios::beg);
                        file.write((char*)&cont,sizeof(cont));
                        ui->textBrowser_3->append(d.toQstring());
                        ui->textBrowser_3->append("::Eliminado::");
                        break;
                    }
                    else if(type==4 && d.getClaveProf()==code && llave==clave){
                        cont--;
                        file.seekp(pos,ios::beg);
                        file.write((char*)&cont,sizeof(cont));
                        ui->textBrowser_3->append(d.toQstring());
                        ui->textBrowser_3->append("::Eliminado::");
                        break;
                    }
                    else
                        ui->textBrowser_3->setText("::Clave Erronea::");
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

}

void MenuDisponibilidad::on_comboBox_Carrera_activated(const QString &arg1)
{
    ui->comboBox_Materias->clear();
    setMaterias();
}

void MenuDisponibilidad::on_tabWidget_currentChanged(int index)
{

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
