#include "menumapa.h"
#include "ui_menumapa.h"

using namespace std;

MenuMapa::MenuMapa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuMapa)
{
    ui->setupUi(this);
    if(ui->stackedWidget_3->currentIndex()==0){
        ui->pushButton_16->setText("Menu Mapa");
        ui->stackedWidget_3->setCurrentIndex(1);
    }
    else{
        ui->pushButton_16->setText("Menu Edificos");
        ui->stackedWidget_3->setCurrentIndex(0);
    }
    ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,2}")));
    ifstream f("Mapa.txt");
    if(!f.is_open()){
        ui->pushButton_6->setDisabled(true);
        ui->pushButton_10->setDisabled(true);

    }
    else{
        f.read((char*)&m,sizeof(m));
        f.close();
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_10->setEnabled(true);

    }
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();
    ui->comboBox_4->clear();
    for(int i(0);i<m.getSize();i++){
        if(m.getEdificio(i).getStatus()=='V'){
            ui->comboBox->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_2->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_3->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_4->addItem(m.getEdificio(i).getNombre());
        }
    }
}

MenuMapa::~MenuMapa()
{
    delete ui;
}

bool MenuMapa::recorrido(){
    List<Edificio> lista_visitados;
    Stack<Edificio> pila;

    Edificio actual;
    Edificio origen;

    origen=m.getEdificio(0);

    pila.push(origen);
    int c(0);

    while(!pila.isEmpty()){
        actual=pila.pop();

        Node<Edificio> *aux;
        aux=lista_visitados.getFirstPos();
        bool flag(false);
        while(aux!=nullptr){
            Edificio ed;
            ed=lista_visitados.retriveData(aux);
            if(actual==ed){
                flag=true;
            }
            aux=lista_visitados.getNextPos(aux);
        }
        if(!flag){
            c++;
            lista_visitados.insertData(lista_visitados.getLastPos(),actual);

            for(int i(actual.getPos());i<m.getSize();i++){
                Edificio e,b;
                Camino c;
                c=m.getCamino(actual,m.getEdificio(i));

                if(c.getStatus()=='V'){
                    e=m.getEdificio(i);
                    Node<Edificio> *aux2;
                    aux2=lista_visitados.getFirstPos();
                    b=lista_visitados.retriveData(aux2);
                    bool flag2(false);
                    while(aux2!=nullptr){
                        if(e==b){
                            flag2=true;
                        }
                        aux2=lista_visitados.getNextPos(aux2);
                    }
                    if(!flag2){
                        pila.push(e);
                    }

                }

            }
        }
    }

    if(c==m.getSize()){
        return true;
    }
    else{
        return false;
    }
}


Mapa MenuMapa::getM() const
{
    return m;
}

void MenuMapa::setM(const Mapa &value)
{
    m = value;
}

/*Regresar*/
void MenuMapa::on_pushButton_clicked()
{
    MenuSU *SU = new MenuSU();
    this->hide();
    SU->show();
    this->close();

}

/*Crear*/
void MenuMapa::on_pushButton_2_clicked()
{
    if (ui->lineEdit_2->text().toInt()<13 && ui->lineEdit_2->text().toInt()>1){
        for(int i(0);i<ui->lineEdit_2->text().toInt();i++){
            remove("Mapa.txt");
            NuevoEdificio *nuevoEdificio = new NuevoEdificio();
            nuevoEdificio->setSize(i);
            this->hide();
            nuevoEdificio->show();
            this->close();

        }

    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::El mapa debe tener mas de 1 edificio y menos de 12::"));
    }
}

/*Mostrar*/
void MenuMapa::on_pushButton_3_clicked()
{
    ifstream f("Mapa.txt");
    if(!f.is_open()){
        ui->textBrowser->setText("::Mapa Inexistente::");
    }
    else{
        f.read((char*)&m,sizeof(m));
        f.close();
        ui->textBrowser->clear();
        ui->textBrowser->append(m.toQstring());
    }
}

/*Buscar*/
void MenuMapa::on_pushButton_4_clicked()
{
    ui->textBrowser_2->clear();

    int cod(ui->lineEdit->text().toInt());
    int pos;
    bool flag(true);
    for(int i(0);i<m.getSize();i++){
        if(cod==m.getEdificio(i).getCodigo()){
            ui->textBrowser_2->append(m.getEdificio(i).toQstring());
            pos=i;
            flag=false;
        }
    }
    if(flag){
        ui->textBrowser_2->setText("::Código Incorrecto::");
    }
    else{
        ui->textBrowser_2->append("Caminos: ");
        Edificio a;
        Edificio b;
        a=m.getEdificio(pos);
        for(int i(0);i<m.getSize();i++){
            b.setPos(i);
            if(m.getCamino(a,b).getStatus()=='V'){
                ui->textBrowser_2->append(a.getNombre()+"->"+m.getEdificio(i).getNombre());
            }
        }
    }

    ui->lineEdit->clear();
}

/*Eliminar Edificio*/
void MenuMapa::on_pushButton_5_clicked()
{
    ui->textBrowser_3->clear();

    int cod(ui->lineEdit_3->text().toInt());
    bool flag(true);
    for(int i(0);i<m.getSize();i++){
        if(cod==m.getEdificio(i).getCodigo()){
            Edificio e;
            e=m.getEdificio(i);
            m.deleteEdificio(m.getEdificio(i));

            bool f(true);///recorrido
            flag=false;
            if(f){
                ui->textBrowser_3->append(e.toQstring());
                ui->textBrowser_3->append("::Edificio Eliminado::");
                ofstream f("Mapa.txt",ios::out);
                f.write((char*)&m,sizeof(m));
                f.close();
            }
            else{
                QMessageBox::information(this, tr("::Error::"), tr("::Todos los edificios deben tener al menos un camino que lo conecte al mapa::"));
            }
        }
    }
    if(flag){
        ui->textBrowser_3->setText("::Código Incorrecto::");
    }



    ui->lineEdit_3->clear();
}

/*Nuevo edificio*/
void MenuMapa::on_pushButton_6_clicked()
{
    NuevoEdificio *nE = new NuevoEdificio();
    nE->setSize(0);
    this->hide();
    nE->show();
    this->close();

}

/*Agregar enlace*/
void MenuMapa::on_pushButton_10_clicked()
{
    NuevoEnlace *nuevoEnlace = new NuevoEnlace();
    this->hide();
    nuevoEnlace->show();
    this->close();

}

/*Eliminar camino*/
void MenuMapa::on_pushButton_7_clicked()
{
    Edificio a;
    Edificio b;
    ui->textBrowser_4->clear();

    a.setNombre(ui->comboBox->currentText());
    b.setNombre(ui->comboBox_2->currentText());

    bool flag = m.deleteCamino(a,b);

    if(flag){
        bool f(true);///recorrido

        if(f){
            ofstream f("Mapa.txt",ios::out);
            f.write((char*)&m,sizeof(m));
            f.close();
            ui->textBrowser_4->setText("::Camino Eliminado::");
        }
        else{
            QMessageBox::information(this, tr("::Error::"), tr("::Todos los edificios deben tener al menos un camino que lo conecte al mapa::"));
        }
    }
    else{
        ui->textBrowser_4->setText("::No existe el camino::");

    }
}

/*Cambio en tabs*/
void MenuMapa::on_tabWidget_currentChanged(int index)
{
    ifstream f("Mapa.txt");
    if(!f.is_open()){
        ui->pushButton_6->setDisabled(true);
        ui->pushButton_10->setDisabled(true);

    }
    else{
        f.read((char*)&m,sizeof(m));
        f.close();
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_10->setEnabled(true);

    }
    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    ui->textBrowser_3->clear();
    ui->textBrowser_4->clear();
    ui->textBrowser_5->clear();
    ui->textBrowser_6->clear();
    ui->textBrowser_9->clear();


    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();
    ui->comboBox_4->clear();
    for(int i(0);i<m.getSize();i++){
        if(m.getEdificio(i).getStatus()=='V'){
            ui->comboBox->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_2->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_3->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_4->addItem(m.getEdificio(i).getNombre());
        }
    }
}

/*Modificar Edificio*/
void MenuMapa::on_pushButton_8_clicked()
{
    ui->textBrowser_5->clear();

    int cod(ui->lineEdit_4->text().toInt());
    bool flag(true);
    for(int i(0);i<m.getSize();i++){
        if(cod==m.getEdificio(i).getCodigo()){
            Edificio e;
            e=m.getEdificio(i);
            if(!ui->lineEdit_5->text().isEmpty()){
                e.setNombre(ui->lineEdit_5->text());
                m.getEdificio(e.getPos()).setNombre(e.getNombre());
                ui->textBrowser_5->setText("::Nombre Modificado::");
                ui->textBrowser_5->append(m.getEdificio(i).toQstring());
                ofstream f("Mapa.txt",ios::out);
                f.write((char*)&m,sizeof(m));
                f.close();
                flag=false;
            }
            else{
                ui->textBrowser_5->setText("::Llene los campos correctamente::");
                flag=false;
            }
        }
    }
    if(flag){
        ui->textBrowser_5->setText("::Código Incorrecto::");
    }

    ui->lineEdit_5->clear();
}

/*Modificar enlace*/
void MenuMapa::on_pushButton_9_clicked()
{
    Edificio a;
    Edificio b;
    ui->textBrowser_6->clear();

    a.setNombre(ui->comboBox_3->currentText());
    b.setNombre(ui->comboBox_4->currentText());

    for(int i(0);i<m.getSize();i++){
        if(m.getEdificio(i).getNombre()==a.getNombre()){
            a.setPos(i);
        }
        if(m.getEdificio(i).getNombre()==b.getNombre()){
            b.setPos(i);
        }
    }


    if(m.getCamino(a,b).getStatus()=='V'){
        if(!ui->lineEdit_6->text().isEmpty()){
            m.setCamino(a,b,ui->lineEdit_6->text().toInt());

            ofstream f("Mapa.txt",ios::out);
            f.write((char*)&m,sizeof(m));
            f.close();

            ui->textBrowser_6->setText("::Distancia Modificada::");
            ui->textBrowser_6->append(a.getNombre()+"->"+b.getNombre()+":"+ui->lineEdit_6->text());
        }
        else{
            ui->textBrowser_6->setText("::Llene los campos correctamente::");

        }
    }
    else{
        ui->textBrowser_6->setText("::No existe el camino::");

    }
    ui->lineEdit_6->clear();

}

/*Recorrido profundidad*/
void MenuMapa::on_pushButton_12_clicked()
{
    List<Edificio> lista_visitados;
    Stack<Edificio> pila;

    ui->textBrowser_7->clear();

    Edificio actual;
    Edificio origen;
    origen.setNombre(ui->lineEdit_7->text());
    bool exist(false);

    for(int i(0);i<m.getSize();i++){
        if(origen==m.getEdificio(i)){
            exist=true;
            origen=m.getEdificio(i);
        }
    }

    if(exist){
        ui->textBrowser_7->append("::Recorrido en profundidad::");

        pila.push(origen);

        while(!pila.isEmpty()){
            actual=pila.pop();

            Node<Edificio> *aux;
            aux=lista_visitados.getFirstPos();
            bool flag(false);

            while(aux!=nullptr){
                if(actual==lista_visitados.retriveData(aux)){
                    flag=true;
                }
                aux=lista_visitados.getNextPos(aux);
            }

            if(!flag){
                ui->textBrowser_7->append(actual.getNombre()+", ");

                lista_visitados.insertData(lista_visitados.getLastPos(),actual);

                for(int i(0);i<m.getSize();i++){
                    Edificio e;
                    Camino c;
                    c=m.getCamino(actual,m.getEdificio(i));

                    if(c.getStatus()=='V'){
                        e=m.getEdificio(i);

                        Node<Edificio> *aux2;
                        aux2=lista_visitados.getFirstPos();

                        bool flag2(false);
                        while(aux2!=nullptr){
                            if(e==lista_visitados.retriveData(aux2)){
                                flag2=true;
                            }
                            aux2=lista_visitados.getNextPos(aux2);
                        }
                        if(!flag2){
                            pila.push(e);
                        }

                    }

                }
            }

        }
    }
    else{
        ui->textBrowser_7->setText("::No existe el Edificio::");
    }
}

/*Recorrido Anchura*/
void MenuMapa::on_pushButton_11_clicked()
{
    List<Edificio> lista_visitados;
    Queue<Edificio> cola;

    ui->textBrowser_7->clear();

    Edificio actual;
    Edificio origen;
    origen.setNombre(ui->lineEdit_7->text());
    bool exist(false);

    for(int i(0);i<m.getSize();i++){
        if(origen==m.getEdificio(i)){
            exist=true;
            origen=m.getEdificio(i);
        }
    }

    if(exist){
        ui->textBrowser_7->append("::Recorrido en anchura::");
        cola.enqueue(origen);

        while(!cola.isEmpty()){
            actual=cola.dequeue();

            Node<Edificio> *aux;
            aux=lista_visitados.getFirstPos();
            bool flag(false);

            while(aux!=nullptr){
                if(actual==lista_visitados.retriveData(aux)){
                    flag=true;
                }
                aux=lista_visitados.getNextPos(aux);
            }

            if(!flag){
                ui->textBrowser_7->append(actual.getNombre()+", ");

                lista_visitados.insertData(lista_visitados.getLastPos(),actual);

                for(int i(0);i<m.getSize();i++){
                    Edificio e;
                    Camino c;
                    c=m.getCamino(actual,m.getEdificio(i));

                    if(c.getStatus()=='V'){
                        e=m.getEdificio(i);

                        Node<Edificio> *aux2;
                        aux2=lista_visitados.getFirstPos();

                        bool flag2(false);
                        while(aux2!=nullptr){
                            if(e==lista_visitados.retriveData(aux2)){
                                flag2=true;
                            }
                            aux2=lista_visitados.getNextPos(aux2);
                        }
                        if(!flag2){
                            cola.enqueue(e);
                        }

                    }
                }
            }
        }
    }
    else{
        ui->textBrowser_7->setText("::No existe el Edificio::");
    }
}

/*Mostrar Ruta*/
void MenuMapa::showRuta(Stack<ParEdificios> &pila, Edificio &destino)
{
    Edificio actual=destino;
    while(!pila.isEmpty()){
        ui->textBrowser_8->append(actual.getNombre()+",");
        while(!pila.isEmpty() and pila.getTop().getDestino()!=actual){
            pila.pop();
        }
        if(!pila.isEmpty()){
            actual=pila.getTop().getOrigen();
        }
    }
}

/*Ruta Anchura*/
void MenuMapa::on_pushButton_13_clicked()
{
    List<Edificio> lista_visitados;
    Queue<Edificio> cola;

    ui->textBrowser_8->clear();

    Edificio actual;
    Edificio origen;
    Edificio destino;

    origen.setNombre(ui->lineEdit_8->text());
    destino.setNombre(ui->lineEdit_9->text());

    bool existD(false);
    bool existO(false);
    bool find(true);

    for(int i(0);i<m.getSize();i++){
        if(origen==m.getEdificio(i)){
            existO=true;
            origen=m.getEdificio(i);
        }
        if(destino==m.getEdificio(i)){
            existD=true;
            destino=m.getEdificio(i);
        }
    }

    if(existO && existD){
        ui->textBrowser_8->append("::Primero en anchura::");
        cola.enqueue(origen);
        Stack<ParEdificios> pilaPares;

        while(!cola.isEmpty()){
            actual=cola.dequeue();

            Node<Edificio> *aux;
            aux=lista_visitados.getFirstPos();
            bool flag(false);

            while(aux!=nullptr){
                if(actual==lista_visitados.retriveData(aux)){
                    flag=true;
                }
                aux=lista_visitados.getNextPos(aux);
            }

            if(!flag){
                if(actual==destino)
                {
                    showRuta(pilaPares, destino);
                    find=false;
                    break;
                }
                else{
                    lista_visitados.insertData(lista_visitados.getLastPos(),actual);
                    for(int i(0);i<m.getSize();i++){
                        Edificio e;
                        Camino c;
                        c=m.getCamino(actual,m.getEdificio(i));

                        if(c.getStatus()=='V'){
                            e=m.getEdificio(i);

                            Node<Edificio> *aux2;
                            aux2=lista_visitados.getFirstPos();

                            bool flag2(false);
                            while(aux2!=nullptr){
                                if(e==lista_visitados.retriveData(aux2)){
                                    flag2=true;
                                }
                                aux2=lista_visitados.getNextPos(aux2);
                            }

                            if(!flag2){
                                ParEdificios par;
                                par.setOrigen(actual);
                                par.setDestino(m.getEdificio(i));
                                cola.enqueue(e);
                                pilaPares.push(par);
                            }

                        }
                    }
                }
            }
        }
        if(cola.isEmpty() and find){
            ui->textBrowser_8->setText("::No existe Ruta::");
        }
    }
    else{
        ui->textBrowser_8->setText("::No existe el Edificio::");
    }
}

/*Ruta profundidad*/
void MenuMapa::on_pushButton_14_clicked()
{
    List<Edificio> lista_visitados;
    Stack<Edificio> pila;

    ui->textBrowser_8->clear();

    Edificio actual;
    Edificio origen;
    Edificio destino;

    origen.setNombre(ui->lineEdit_8->text());
    destino.setNombre(ui->lineEdit_9->text());

    bool existD(false);
    bool existO(false);
    bool find(true);

    for(int i(0);i<m.getSize();i++){
        if(origen==m.getEdificio(i)){
            existO=true;
            origen=m.getEdificio(i);
        }
        if(destino==m.getEdificio(i)){
            existD=true;
            destino=m.getEdificio(i);
        }
    }

    if(existO && existD){
        ui->textBrowser_8->append("::Primero en anchura::");
        pila.push(origen);
        Stack<ParEdificios> pilaPares;

        while(!pila.isEmpty()){
            actual=pila.pop();

            Node<Edificio> *aux;
            aux=lista_visitados.getFirstPos();
            bool flag(false);

            while(aux!=nullptr){
                if(actual==lista_visitados.retriveData(aux)){
                    flag=true;
                }
                aux=lista_visitados.getNextPos(aux);
            }

            if(!flag){
                if(actual==destino)
                {
                    showRuta(pilaPares, destino);
                    find=false;
                    break;
                }
                else{
                    lista_visitados.insertData(lista_visitados.getLastPos(),actual);
                    for(int i(0);i<m.getSize();i++){
                        Edificio e;
                        Camino c;
                        c=m.getCamino(actual,m.getEdificio(i));

                        if(c.getStatus()=='V'){
                            e=m.getEdificio(i);

                            Node<Edificio> *aux2;
                            aux2=lista_visitados.getFirstPos();

                            bool flag2(false);
                            while(aux2!=nullptr){
                                if(e==lista_visitados.retriveData(aux2)){
                                    flag2=true;
                                }
                                aux2=lista_visitados.getNextPos(aux2);
                            }

                            if(!flag2){
                                ParEdificios par;
                                par.setOrigen(actual);
                                par.setDestino(m.getEdificio(i));
                                pila.push(e);
                                pilaPares.push(par);
                            }

                        }
                    }
                }
            }
        }
        if(pila.isEmpty() and find){
            ui->textBrowser_8->setText("::No existe Ruta::");
        }
    }
    else{
        ui->textBrowser_8->setText("::No existe el Edificio::");
    }
}

/*Cambio de tabs2*/
void MenuMapa::on_tabWidget_2_currentChanged(int index)
{
    ifstream f("Mapa.txt");
    if(!f.is_open()){
        ui->pushButton_6->setDisabled(true);
        ui->pushButton_10->setDisabled(true);

    }
    else{
        f.read((char*)&m,sizeof(m));
        f.close();
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_10->setEnabled(true);

    }
    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    ui->textBrowser_3->clear();
    ui->textBrowser_4->clear();
    ui->textBrowser_5->clear();
    ui->textBrowser_6->clear();
    ui->textBrowser_9->clear();


    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();
    ui->comboBox_4->clear();
    for(int i(0);i<m.getSize();i++){
        if(m.getEdificio(i).getStatus()=='V'){
            ui->comboBox->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_2->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_3->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_4->addItem(m.getEdificio(i).getNombre());
        }
    }
}

/*Big tab*/
void MenuMapa::on_tabWidget_3_currentChanged(int index)
{
    ifstream f("Mapa.txt");
    if(!f.is_open()){
        ui->pushButton_6->setDisabled(true);
        ui->pushButton_10->setDisabled(true);

    }
    else{
        f.read((char*)&m,sizeof(m));
        f.close();
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_10->setEnabled(true);

    }
    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    ui->textBrowser_3->clear();
    ui->textBrowser_4->clear();
    ui->textBrowser_5->clear();
    ui->textBrowser_6->clear();

    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();
    ui->comboBox_4->clear();
    for(int i(0);i<m.getSize();i++){
        if(m.getEdificio(i).getStatus()=='V'){
            ui->comboBox->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_2->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_3->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_4->addItem(m.getEdificio(i).getNombre());
        }
    }
}


void MenuMapa::on_pushButton_15_clicked()
{
}

/*Cambio de menu*/
void MenuMapa::on_pushButton_16_clicked()
{
    if(ui->stackedWidget_3->currentIndex()==0){
        ui->pushButton_16->setText("Menu Mapa");
        ui->stackedWidget_3->setCurrentIndex(1);
    }
    else{
        ui->pushButton_16->setText("Menu Edificos");
        ui->stackedWidget_3->setCurrentIndex(0);
    }
}

void MenuMapa::on_pushButton_mostarEdificios_clicked()
{
    ui->textBrowser_9->clear();
    ifstream f("Mapa.txt");
    if(!f.is_open()){
        ui->textBrowser_9->setText("::No hay Edifcios::");
    }
    else{
        f.read((char*)&m,sizeof(m));
        f.close();
        ui->textBrowser_9->clear();
        for (int i = 0; i < m.getSize(); ++i) {
            ui->textBrowser_9->append(m.getEdificio(i).toQstring());
        }
    }

}
