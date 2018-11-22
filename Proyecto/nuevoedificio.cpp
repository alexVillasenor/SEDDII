#include "nuevoedificio.h"
#include "ui_nuevoedificio.h"

using namespace std;

NuevoEdificio::NuevoEdificio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NuevoEdificio)
{
    ui->setupUi(this);
}

bool isEmptyMapa(string name){
    ifstream f(name);
    if(!f.is_open()){
        return true;
    }
    else{
        f.seekg(0,f.end);
        long int p=f.tellg();
        if(p==0){
            f.close();
            return true;
        }
        else{
            f.close();
            return false;
        }
    }
}

int NuevoEdificio::getLastCodeEdificio(string name){

    if(isEmptyMapa(name)){
        return 1;
    }
    else{
        ifstream file(name);
        if(!file.is_open()){
            return 1;
        }
        else{
            file.read((char*)&m,sizeof(m));
            file.close();
            int last;
            for(int i=0;i<m.getSize();i++){
                last=i;
            }
            return m.getEdificio(last).getCodigo()+1;
        }
    }
}

NuevoEdificio::~NuevoEdificio()
{
    delete ui;
}

void NuevoEdificio::on_pushButton_clicked()
{
    if(!ui->lineEdit->text().isEmpty()){
        Edificio e;
        QString nombre = ui->lineEdit->text();
        e.setCodigo(getLastCodeEdificio("Mapa.txt"));
        qDebug()<<QString::number(e.getCodigo());
        e.setNombre(nombre);
        m.setEdificio(e);

        ofstream f("Mapa.txt",ios::out);
        f.write((char*)&m,sizeof(m));
        f.close();


        if(size==0){
            NuevoEnlace *nuevoEnlace = new NuevoEnlace();
            this->hide();
            nuevoEnlace->show();
        }

        this->close();

    }
    else{
        QMessageBox::information(this, tr("::Error::"), tr("::Llena todos los campos correctamente::"));
    }

}

bool NuevoEdificio::getFlag() const
{
    return flag;
}

void NuevoEdificio::setFlag(bool value)
{
    flag = value;
}

int NuevoEdificio::getFinal() const
{
    return final;
}

void NuevoEdificio::setFinal(int value)
{
    final = value;
}

int NuevoEdificio::getSize() const
{
    return size;
}

void NuevoEdificio::setSize(int value)
{
    size = value;
}

Mapa NuevoEdificio::getM() const
{
    return m;
}

void NuevoEdificio::setM(const Mapa &value)
{
    m = value;
}
