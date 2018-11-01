#include "nuevoenlace.h"
#include "ui_nuevoenlace.h"

using namespace std;

NuevoEnlace::NuevoEnlace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NuevoEnlace)
{
    ui->setupUi(this);
    ui->pushButton_2->setDisabled(true);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));

    ifstream fa("Mapa.txt");
    if(!fa.is_open()){

    }
    else{
        fa.read((char*)&m,sizeof(m));
        fa.close();
    }

    ui->comboBox->clear();
    ui->comboBox_2->clear();
    for(int i(0);i<m.getSize();i++){
        if(m.getEdificio(i).getStatus()=='V'){
            ui->comboBox->addItem(m.getEdificio(i).getNombre());
            ui->comboBox_2->addItem(m.getEdificio(i).getNombre());
        }
    }
}

bool NuevoEnlace::recorrido(){
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

NuevoEnlace::~NuevoEnlace()
{
    delete ui;
}

/*Agregar*/
void NuevoEnlace::on_pushButton_clicked()
{

    if(!ui->lineEdit->text().isEmpty()){
        Edificio a;
        Edificio b;
        int d(ui->lineEdit->text().toInt());

        a.setNombre(ui->comboBox->currentText());
        b.setNombre(ui->comboBox_2->currentText());

        for(int i(0);i<m.getSize();i++){
            if(a.getNombre()==m.getEdificio(i).getNombre()){
                a.setPos(m.getEdificio(i).getPos());
            }
            if(b.getNombre()==m.getEdificio(i).getNombre()){
                b.setPos(m.getEdificio(i).getPos());
            }
        }
        m.setCamino(a,b,d);

        ofstream f("Mapa.txt",ios::out);
        f.write((char*)&m,sizeof(m));
        f.close();

        QMessageBox::information(this, tr("::Exito::"), tr("::Camino Creado::"));

    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llena todos los campos correctamente::"));

    }
    ui->lineEdit->clear();



    bool f(true);///recorrido
        if(f){
            ui->pushButton_2->setEnabled(true);
        }
        else{
            QMessageBox::information(this, tr("::Error::"), tr("::Todos los edificios deben tener al menos un camino que lo conecte al mapa::"));
        }
}

/*Terminar*/
void NuevoEnlace::on_pushButton_2_clicked()
{
    MenuMapa *menuMapa = new MenuMapa();
    this->hide();
    menuMapa->show();
    this->close();
    delete this;
}

bool NuevoEnlace::getFlag() const
{
    return flag;
}

void NuevoEnlace::setFlag(bool value)
{
    flag = value;
}
