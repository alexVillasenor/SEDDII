#include "menuasignatura.h"
#include "ui_menuasignatura.h"
#include <QTimer>

using namespace std;

MenuAsignatura::MenuAsignatura(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuAsignatura)
{
    loadIndex();

    ui->setupUi(this);

    QTimer* timer=new QTimer;
    timer->start(5000);

    connect(timer,SIGNAL(timeout()),this,SLOT(timerSave()));

}

MenuAsignatura::~MenuAsignatura()
{
    delete ui;
}

bool isEmptyAsignaturas(string name){
    ifstream f(name);
    if(!f.is_open()){
        return true;
    }
    else{
        f.seekg(0,f.end);
        long int dir = f.tellg();
        if(dir==0){
            f.close();
            return true;
        }
        else{
            f.close();
            return false;
        }
    }
    f.close();
    return true;
}

int getLastCodeAsignatura(string name){
    if(isEmptyAsignaturas(name)){
        return 200;
    }
    else{
        ifstream file(name);
        if(!file.is_open()){
            return 200;
        }
        else{
            Asignatura a;
            file.seekg(0,ios::end);
            long int pos=file.tellg();
            pos-=sizeof(a);
            file.seekg(pos);
            file.read((char*)&a,sizeof(a));
            file.close();
            int c(a.getCodigo()+1);
            return c;
        }
    }
}

void MenuAsignatura::saveListaInvertida()
{
    remove("TDA_Programa.txt");
    ofstream programas("TDA_Programa.txt",ios::app);
    Programa* auxProgr;
    auxProgr = listainvertida.getInicioProgramas();

    while(auxProgr!=nullptr){
        programas<<auxProgr->getNombre().toStdString()<<"|";
        programas<<listainvertida.getPos(auxProgr->getFirst())<<"\n";

        auxProgr=auxProgr->getNext();
    }
    programas.close();

    remove("TDA_Indice_secundario.txt");
    ofstream indSec("TDA_Indice_secundario.txt",ios::app);
    IndiceSecundario* auxindSec;
    auxindSec = listainvertida.getInicioIndiceSecundario();

    while(auxindSec!=nullptr){
        indSec<<auxindSec->getCodigo()<<"|";

        indSec<<listainvertida.getPos(auxindSec->getNextPrograma())<<"\n";

        auxindSec=auxindSec->getNext();
    }
    indSec.close();
    }

void MenuAsignatura::autoSave(){
    ofstream file("Indices.txt",ios::out);
    Indice i;
    Node<Indice> *aux;
    aux = listaIndices.getFirstPos();

    while(aux!=nullptr){
        i=listaIndices.retriveData(aux);
        file.write((char*)&i,sizeof(i));
        aux=listaIndices.getNextPos(aux);
    }
    file.close();

    fstream f("Asignaturas.txt");
    Asignatura a;
    long int dir;
    while(!stack.isEmpty()){
        a=stack.pop();
        dir=stackDireccion.pop();
        f.seekp(dir);
        f.write((char*)&a,sizeof(a));
    }
    f.close();

    saveListaInvertida();
}

void MenuAsignatura::loadIndex()
{
    listaIndices.deleteAll();
    stack.deleteAll();
    stackDireccion.deleteAll();
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

void MenuAsignatura::printIndiceSec()
{
    Programa* auxPrograma = listainvertida.getInicioProgramas();
    IndiceSecundario* auxIndSec = listainvertida.getInicioIndiceSecundario();

    qDebug()<<":::::::Programas::::::: ";
    while(auxPrograma!=nullptr){
        qDebug()<<"Programa: "<< auxPrograma->getNombre();
        qDebug()<<"Direccion Programa: "<< auxPrograma;
        qDebug()<<"Direccion Primer Indice: "<< auxPrograma->getFirst();
        qDebug()<<"Direccion sieguiente Programa: "<< auxPrograma->getNext();
        qDebug()<<"--------------------------------------------------------------------------------";
        auxPrograma=auxPrograma->getNext();
    }
    auxPrograma = listainvertida.getInicioProgramas();

    qDebug()<<":::::::Indices Secundarios::::::: ";
    while(auxIndSec!=nullptr){

        qDebug()<< auxIndSec<<"\t"<< QString::number(auxIndSec->getCodigo())<<"\t"<<auxIndSec->getNext()<<"\t"<< auxIndSec->getNextPrograma();
        auxIndSec=auxIndSec->getNext();
    }

}

void MenuAsignatura::timerSave()
{
    autoSave();
}

/*Regresar*/
void MenuAsignatura::on_pushButton_clicked()
{
    autoSave();
    MenuSU *SU = new MenuSU();
    this->hide();
    SU->show();
    this->close();

}

/*Crear*/
void MenuAsignatura::on_pushButton_2_clicked()
{
    int codigo = getLastCodeAsignatura("Asignaturas.txt");
    QString nombre = ui->lineEdit->text();
    QString programa = ui->lineEdit_2->text();
    QString cred = ui->lineEdit_3->text();
    int creditos = cred.toInt();
    QString grado = ui->comboBox->currentText();

    qDebug()<<grado;
    Asignatura a;
    a.setCodigo(codigo);
    a.setCreditos(creditos);
    a.setNombre(nombre);
    a.setPrograma(programa);
    a.setGrado(grado);

    qDebug()<<"asigatura:"<<a.toQString();

    if(!ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() && !ui->lineEdit_3->text().isEmpty()){
        long int dir;

        ofstream asigFile("Asignaturas.txt",ios::app);

        asigFile.seekp(0,asigFile.end);
        dir=asigFile.tellp();
        asigFile.write((char*)&a,sizeof(a));
        asigFile.close();

        Indice i;
        i.setCodigo(codigo);
        i.setDireccion(dir);

        listaIndices.insertData(listaIndices.getLastPos(),i);

        listainvertida.agregar(a);
        printIndiceSec();
        autoSave();
        QMessageBox::information(this, tr("::Exito::"), tr("::Asignatura creada correctamente::"));
    }

    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llena todos los campos correctamente::"));
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

/*Mostrar*/
void MenuAsignatura::on_pushButton_3_clicked()
{
    Asignatura a;
    stringstream ss;
    Node<Indice> *aux;
    long int dir;
    loadIndex();
    aux=listaIndices.getFirstPos();

    if(listaIndices.isEmpty()){
        ui->textBrowser->setText("::No hay asignaturas registradas::");
    }
    else{
        ifstream file("Asignaturas.txt");
        if(!file.is_open()){
            ui->textBrowser->setText("::Error al abrir el archivo::");
        }
        else{
            ui->textBrowser->setText("");

            while(aux != nullptr){
                dir = listaIndices.retriveData(aux).getDireccion();

                if(!file.eof()){
                    file.seekg(dir);
                    file.read((char*)&a,sizeof(a));
                    if(a.getStatus() == '1'){
                        ui->textBrowser->append(a.toQString());
                        ui->textBrowser->append("___________________________");
                    }
                }
                aux=aux->getNext();
            }
            file.close();
            printIndiceSec();
        }
    }
}

/*Buscar*/
void MenuAsignatura::on_pushButton_4_clicked()
{
    Asignatura a;
    QString code=ui->lineEdit_4->text();
    ui->lineEdit_4->clear();
    Indice i;
    Node<Indice> *aux;
    loadIndex();
    i.setCodigo(code.toInt());
    long int dir;

    if(listaIndices.isEmpty()){
        ui->textBrowser_2->setText("::No hay asignaturas registradas::");
    }
    else{
        ifstream file("Asignaturas.txt");
        if(!file.is_open()){
            ui->textBrowser_2->setText("::Error al abrir el archivo::");
        }
        else{
            ui->textBrowser_2->setText("");
            aux=listaIndices.findData(i);
            if(aux!=nullptr){
                dir = listaIndices.retriveData(aux).getDireccion();
                file.seekg(dir);
                file.read((char*)&a,sizeof(a));

                if(a.getStatus() == '1' and a.getCodigo() == code.toInt()){
                    ui->textBrowser_2->append(a.toQString());
                    ui->textBrowser_2->append("___________________________");

                }
                else{
                    ui->textBrowser_2->setText("::Codigo incorrecto::");
                }
            }
            else{
                ui->textBrowser_2->setText("::Codigo incorrecto::");
            }
            file.close();
        }
    }
}

/*Eliminar*/
void MenuAsignatura::on_pushButton_5_clicked()
{
    Asignatura a;
    bool flag(true);
    QString code=ui->lineEdit_5->text();
    ui->lineEdit_5->clear();
    Indice i,i2;

    loadIndex();
    i.setCodigo(code.toInt());

    if(listaIndices.isEmpty()){
        ui->textBrowser_3->setText("::No hay asignaturas registradas::");
    }
    else{
        ifstream file("Asignaturas.txt");
        ofstream temp("temp.txt",ios::app);
        ofstream temp2("temp2.txt",ios::app);

        if(!file.is_open()){
            ui->textBrowser_3->setText("::Error al abrir el archivo::");
        }
        else{
            ui->textBrowser_3->setText("");

            while(!file.eof()){
                file.read((char*)&a,sizeof(a));

                if(file.eof()){
                    break;
                }

                if(a.getStatus() == '1' and a.getCodigo() == code.toInt()){
                    ui->textBrowser_3->append(a.toQString());
                    listainvertida.deleteIndiceSec(code);
                    saveListaInvertida();
                    ui->textBrowser_3->append("::Asignatura Eliminada::");
                    flag=false;
                }
                else
                {
                    i2.setCodigo(a.getCodigo());
                    i2.setDireccion(temp.tellp());
                    temp.write((char*)&a,sizeof(a));
                    temp2.write((char*)&i2,sizeof(i2));
                }

            }
            if(flag){
                ui->textBrowser_3->setText("::codigo incorrecto::");

            }
            temp.close();
            temp2.close();
            file.close();
            remove("Asignaturas.txt");
            rename("temp.txt","Asignaturas.txt");
            remove("Indices.txt");
            rename("temp2.txt","Indices.txt");
        }
    }
    loadIndex();

}

/*Desactivar*/
void MenuAsignatura::on_pushButton_6_clicked()
{
    Asignatura a;
    QString code=ui->lineEdit_6->text();
    ui->lineEdit_6->clear();
    Indice i;
    Node<Indice> *aux;

    loadIndex();

    i.setCodigo(code.toInt());
    long int dir;

    if(listaIndices.isEmpty()){
        ui->textBrowser_4->setText("::No hay asignaturas registradas::");
    }
    else{
        fstream file("Asignaturas.txt");
        if(!file.is_open()){
            ui->textBrowser_4->setText("::Error al abrir el archivo::");
        }
        else{
            ui->textBrowser_4->setText("");
            aux=listaIndices.findData(i);
            if(aux!=nullptr){
                dir = listaIndices.retriveData(aux).getDireccion();
                file.seekg(dir,file.beg);
                file.read((char*)&a,sizeof(a));

                if(a.getStatus() == '1' and a.getCodigo() == code.toInt()){
                    a.setStatus('0');
                    ui->textBrowser_4->append(a.toQString());
                    ui->textBrowser_4->append("::Asignatura Desactivada::");

                    stack.push(a);
                    stackDireccion.push(dir);
                }
                else{
                    ui->textBrowser_4->setText("::Codigo incorrecto::");
                }
            }
            else{
                ui->textBrowser_4->setText("::Codigo incorrecto::");
            }

            file.close();

        }
    }
}

/*Activar*/
void MenuAsignatura::on_pushButton_7_clicked()
{
    Asignatura a;
    QString code=ui->lineEdit_7->text();
    ui->lineEdit_7->clear();
    Indice i;
    Node<Indice> *aux;
    loadIndex();
    i.setCodigo(code.toInt());
    long int dir;

    if(listaIndices.isEmpty()){
        ui->textBrowser_5->setText("::No hay asignaturas registradas::");
    }
    else{
        fstream file("Asignaturas.txt");
        if(!file.is_open()){
            ui->textBrowser_5->setText("::Error al abrir el archivo::");
        }
        else{
            ui->textBrowser_5->setText("");
            aux=listaIndices.findData(i);
            if(aux!=nullptr){
                dir = listaIndices.retriveData(aux).getDireccion();
                file.seekg(dir,file.beg);
                file.read((char*)&a,sizeof(a));

                if(a.getStatus() == '0' and a.getCodigo() == code.toInt()){
                    a.setStatus('1');
                    ui->textBrowser_5->append(a.toQString());
                    ui->textBrowser_5->append("::Asignatura Activada::");
                    stack.push(a);
                    stackDireccion.push(dir);
                }
                else{
                    ui->textBrowser_5->setText("::Codigo incorrecto::");
                }
            }
            else{
                ui->textBrowser_5->setText("::Codigo incorrecto::");
            }

            file.close();

        }
    }
}

/*Modificar*/
void MenuAsignatura::on_pushButton_8_clicked()
{
    Asignatura a;
    QString code=ui->lineEdit_8->text();
    ui->lineEdit_8->clear();

    QString nombre =ui->lineEdit_9->text();
    QString programa =ui->lineEdit_10->text();
    QString creditos =ui->lineEdit_11->text();
    QString grado = ui->comboBox_2->currentText();



    Indice i;
    Node<Indice> *aux;
    loadIndex();
    i.setCodigo(code.toInt());
    long int dir;

    if(listaIndices.isEmpty()){
        ui->textBrowser_4->setText("::No hay asignaturas registradas::");
    }
    else{
        fstream file("Asignaturas.txt");
        if(!file.is_open()){
            ui->textBrowser_6->setText("::Error al abrir el archivo::");
        }
        else{
            ui->textBrowser_6->setText("");
            aux=listaIndices.findData(i);
            if(aux!=nullptr){
                dir = listaIndices.retriveData(aux).getDireccion();
                file.seekg(dir,file.beg);
                file.read((char*)&a,sizeof(a));

                if(a.getStatus() == '1' and a.getCodigo() == code.toInt()){
                    if(!ui->lineEdit_9->text().isEmpty()){
                        a.setNombre(nombre);
                    }
                    if(!ui->lineEdit_10->text().isEmpty()){
                        a.setPrograma(programa);
                    }
                    if(!ui->lineEdit_11->text().isEmpty()){
                        a.setCreditos(creditos.toInt());
                    }
                    a.setGrado(grado);
                    ui->textBrowser_6->append(a.toQString());
                    ui->textBrowser_6->append("::Asignatura Modificada::");

                    stack.push(a);
                    stackDireccion.push(dir);

                    listainvertida.deleteIndiceSec(code);
                    listainvertida.agregar(a);
                }
                else{
                    ui->textBrowser_6->setText("::Codigo incorrecto::");
                }
            }
            else{
                ui->textBrowser_6->setText("::Codigo incorrecto::");
            }

            file.close();

        }
    }
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
}

/*Cambio de tab*/
void MenuAsignatura::on_tabWidget_currentChanged(int index)
{
    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    ui->textBrowser_3->clear();
    ui->textBrowser_4->clear();
    ui->textBrowser_5->clear();
    ui->textBrowser_6->clear();
    ui->textBrowser_7->clear();
    //autoSave();
}

/*Ordenar*/
void MenuAsignatura::on_pushButton_9_clicked()
{
    List<Indice> lista;
    lista=listaIndices;

    lista.shellSort();

    Asignatura a;
    Node<Indice> *aux;
    aux=lista.getFirstPos();
    long int dir;

    if(lista.isEmpty()){
        ui->textBrowser_7->setText("::No hay asignaturas registradas::");
    }
    else{
        ifstream file("Asignaturas.txt");
        if(!file.is_open()){
            ui->textBrowser_7->setText("::Error al abrir el archivo::");
        }
        else{
            ui->textBrowser_7->setText("");

            while(aux != nullptr){
                dir = lista.retriveData(aux).getDireccion();
                file.seekg(dir,file.beg);
                file.read((char*)&a,sizeof(a));

                if(a.getStatus() == '1'){
                    ui->textBrowser_7->append(a.toQString());
                    ui->textBrowser_7->append("___________________________");
                }

                aux=lista.getNextPos(aux);
            }
            file.close();

        }
    }
    lista.deleteAll();
}

/*Buscar Programa*/
void MenuAsignatura::on_pushButton_10_clicked()
{
    loadIndex();
    if(!ui->lineEdit_12->text().isEmpty()){
        Programa* auxPrograma = listainvertida.findPrograma(ui->lineEdit_12->text());

        if(auxPrograma!=nullptr){
            IndiceSecundario* auxIndSec = auxPrograma->getFirst();
            ui->textBrowser_8->clear();
            ui->textBrowser_8->append(":::::::Programa::::::: ");
            ui->textBrowser_8->append(auxPrograma->getNombre());
            ui->textBrowser_8->append("----------------------------------");

            auxPrograma = listainvertida.getInicioProgramas();

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
                    ui->textBrowser_8->append(a.toQString());
                    ui->textBrowser_8->append("------------------------------");
                }
                auxIndSec=auxIndSec->getNextPrograma();
            }
        }
        else
            ui->textBrowser_8->setText("::Programa Incorrecto::");
    }
    else{
        ui->textBrowser_8->setText("::Capture un programa::");

    }
}

void MenuAsignatura::on_pushButton_11_clicked()
{
    autoSave();
}
