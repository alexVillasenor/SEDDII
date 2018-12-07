#include "menuoferta.h"
#include "ui_menuoferta.h"

MenuOferta::MenuOferta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuOferta)
{
    ui->setupUi(this);
    loadIndex();
    cargarPeriodos();
    cargarCarreras();
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

void MenuOferta::setPermisos()
{
    if(type==4 or type == 3){
        ui->tab->setDisabled(true);
        ui->tab_4->setDisabled(true);
        ui->tab_5->setDisabled(true);
    }
}

void MenuOferta::cargarGrupos()
{
    QString periodo=ui->comboBox_Periodo->currentText().toStdString().substr(6,5).c_str();
    QString grado=ui->comboBox_Grupo->currentText();
    bool flag(true);
    Grupo p;
    ui->comboBox->clear();
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

            if(p.getStatus()=='1' && periodo==p.getNombrePeriodo() && grado == p.getGrado()){
                ui->comboBox->addItem(p.getCodigo()+" - "+p.getNombre());
                flag=false;
            }
        }
        file.close();
        if(flag){
            QMessageBox::information(this, tr("::Error::"), tr("::No hay grupos registrados:"));
        }
    }
}

void MenuOferta::cargarCarreras()
{
    loadIndex();
    ui->comboBox_Asignatura->clear();
    Programa* aux=listainvertida.getInicioProgramas();
    while(aux!=nullptr){
        ui->comboBox_Asignatura->addItem(aux->getNombre());
        aux=aux->getNext();
    }
}

void MenuOferta::setProfesores()
{
    QString cAsig=ui->lineEdit_3->text().toStdString().substr(0,3).c_str();
    ui->comboBox_Profesor_2->clear();
    ifstream file("Dispersa.txt");
    int pos(0),cont;
    Disponibilidad d;
    if(!file.is_open()){
        QMessageBox::information(this, tr("::Error::"), tr("::Error al abrir archivo::"));
    }
    else{
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
                    if(cAsig==d.getClaveAsig()){
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
                                if(d.getClaveProf()==p.getCode()){
                                    ui->comboBox_Profesor_2->addItem(p.getCode()+" "+p.getNombre());
                                    flag=false;
                                }
                            }
                            file.close();
                            if(flag){
                                QMessageBox::information(this, tr("::Error::"), tr("::Sin profesores disponibles::"));
                            }
                        }
                    }
                }
                pos=pos+(COLUMNAS*sizeof(d))+sizeof(cont);
            }
        }
        file.close();
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
                    QString llave;
                    if(llave==d.getClaveProf()){

                    }
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
    if(type==1){
        MenuSU *SU = new MenuSU();
        this->hide();
        SU->setCode(code);
        SU->show();
        this->close();

    }
    else if(type ==2){
        this->hide();
        MenuCA *CA = new MenuCA();
        CA->setCode(code);
        CA->show();
        this->close();
    }
    else if(type == 3){
        this->hide();
        MenuAsistente *AS = new MenuAsistente();
        AS->setCode(code);
        AS->show();
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

bool MenuOferta::buscarGrupo(const QString &arg1, const QString &arg2)
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
            if(arg1==p.getCodGrupo()){
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

void MenuOferta::loadIndex()
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

/*Agregar*/
void MenuOferta::on_pushButton_2_clicked()
{

    QString carrera=ui->comboBox_Asignatura->currentText();
    QString grado=ui->comboBox_Grupo->currentText();
    List<Asignatura> listAsigns;
    bool flag(false);
    QString periodo=ui->comboBox_Periodo->currentText().toStdString().substr(6,5).c_str();
    bool fla(true);
    Programa* auxPrograma = listainvertida.findPrograma(carrera);    
    if(auxPrograma!=nullptr){
        IndiceSecundario* auxIndSec = auxPrograma->getFirst();

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
            if(a.getStatus()=='1' && grado == a.getGrado()){
                listAsigns.insertData(listAsigns.getLastPos(),a);
                fla=false;
            }
            auxIndSec=auxIndSec->getNextPrograma();
        }
        if(fla){
            QMessageBox::information(this, tr("::Error::"), tr("::No hay asignaturas registradas:"));
        }
        else{
            Node<Asignatura>* auxAsig=listAsigns.getFirstPos();
            Oferta o;
            while(auxAsig!=nullptr){
                o.setCodGrupo(ui->comboBox->currentText());
                o.setCodProfesor("NULL");
                o.setCodPeriodo(periodo);
                o.setCodAsignatura(QString::number(auxAsig->getData().getCodigo())+" "+auxAsig->getData().getNombre());
                if(buscar(o.getLlave())){
                    QMessageBox::information(this, tr("::Error::"), tr("::Oferta Existente::"));
                }
                else{
                    ofstream file ("Oferta.txt",ios::app);
                    file.write((char*)&o,sizeof(o));
                    file.close();
                    flag = true;
                }
                auxAsig=auxAsig->getNext();
            }

            if(flag){
                QMessageBox::information(this, tr("::Exito::"), tr("::Oferta Creada::"));
                AsignacionProf *asigProf = new AsignacionProf;
                this->hide();
                asigProf->setType(type);
                asigProf->show();
                this->close();
            }
        }
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::No Existe el programa::"));
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
        QMessageBox::information(this, tr("::Error::"), tr("::No se pudo abrir archivo::"));
    }

    else{
        while (!file.eof()) {
            file.read((char*)&p,sizeof(p));

            if(file.eof()){
                break;
            }
            QString pcode;
            pcode=p.getCodProfesor().toStdString().substr(0,3).c_str();
            if(type==4 and pcode==code){
                ui->textBrowser->append(p.toQstring());
                ui->textBrowser->append("____________________________");
                flag=false;
            }
            else if(type==1 or type==2 or type ==3){
                ui->textBrowser->append(p.toQstring());
                ui->textBrowser->append("____________________________");
                flag=false;
            }
        }
        file.close();
        if(flag){
            ui->textBrowser->setText("::No hay oferta registrada::");
        }
    }
}

void MenuOferta::on_tabWidget_currentChanged(int index)
{
    cargarPeriodos();
    cargarCarreras();
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
                QString pcode;
                pcode=p.getCodProfesor().toStdString().substr(0,3).c_str();
                if(type==4 and pcode==code and ui->lineEdit->text()==p.getLlave()){
                    ui->textBrowser_2->append(p.toQstring());
                    ui->textBrowser_2->append("____________________________");
                    flag=false;
                }
                else if((type==1 or type==2 or type==3) and ui->lineEdit->text()==p.getLlave()){
                    ui->textBrowser_2->append(p.toQstring());
                    ui->textBrowser_2->append("____________________________");
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

    QString cProf = ui->comboBox_Profesor_2->currentText() ;
    QString code(ui->lineEdit_3->text());

    Oferta p;

    fstream file("Oferta.txt");
    ofstream t("temp.txt");
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

            if(p.getLlave()==code and !ui->comboBox_Profesor_2->currentText().isEmpty()){
                p.setCodProfesor(cProf);
                flag=false;
                t.write((char*)&p,sizeof(p));
                ui->textBrowser_4->append(p.toQstring());
                ui->textBrowser_4->append("::Profesor Modificado::");
            }
            else{
                t.write((char*)&p,sizeof(p));
            }
        }
        file.close();
        t.close();
        remove("Oferta.txt");
        rename("temp.txt","Oferta.txt");
        if(flag){
            ui->textBrowser_4->setText("::No hay profesores disponibles::");
        }
    }
}

/*Buscar en modificar*/
void MenuOferta::on_pushButton_7_clicked()
{
    if(!ui->lineEdit_3->text().isEmpty())
    {
        bool flag(true);
        Oferta p;
        ui->textBrowser_4->clear();
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

                if(ui->lineEdit_3->text()==p.getLlave()){
                    ui->textBrowser_4->setText(p.toQstring());
                    setProfesores();
                    flag=false;
                    break;
                }

            }
            file.close();
            if(flag){
                ui->textBrowser_4->setText("::No hay oferta registrada::");
            }
        }
    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llene los campos correctamente::"));
    }
}

void MenuOferta::on_comboBox_Grupo_activated(const QString &arg1)
{
    cargarGrupos();
}
