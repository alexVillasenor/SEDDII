#include "menuhuffman.h"
#include "ui_menuhuffman.h"

MenuHuffman::MenuHuffman(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuHuffman)
{
    ui->setupUi(this);
}

MenuHuffman::~MenuHuffman()
{
    delete ui;
}

/*Comprimir*/
void MenuHuffman::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    cadena.clear();
    ifstream file("Profesores.txt");
    if(!file.is_open()){
        ui->textBrowser->setText("::Error al abrir el archivo::");
    }

    else{
        ui->textBrowser->append("1.- ");
        while (!file.eof()) {
            char aux;
            file.read((char*)&aux,sizeof(aux));
            if(file.eof()){
                break;
            }
            cadena+=aux;
        }
        file.close();
        ui->textBrowser->append(cadena);

        ui->textBrowser->append("2.- ");

        TDA_Huffman lista,arbol;
        for(int i(0);i<cadena.length();i++){
            Data d,d1;
            string str;
            str=cadena.toStdString()[i];
            d1.setCaracter(str);
            NodoHuffman* nodo=lista.findData(d1);
            if(nodo==nullptr){
                d.setCaracter(str);
                int frec(0);
                for(int j(i);j<cadena.length();j++){
                    string str2;
                    str2=cadena.toStdString()[j];
                    if(str==str2){
                        frec++;
                    }
                }
                d.setFrec(frec);
                lista.insertData(lista.getLastPos(),d);
            }
        }
        QString qAux=lista.toString().c_str();
        ui->textBrowser->append(qAux);

        ui->textBrowser->append("3.- ");
        lista.shellSort();

        qAux=lista.toString().c_str();
        ui->textBrowser->append(qAux);

        ui->textBrowser->append("4.- ");
        arbol=lista;
        arbol.makeTree();

        qAux=arbol.treeToString().c_str();
        ui->textBrowser->append(qAux);

        ui->textBrowser->append("5.- ");
        List<DicDatosHuffman> dicDatos;
//        NodoHuffman* aux = lista.getFirstPos();
//        while(aux!=nullptr){
//            DicDatosHuffman d;
//            arbol.setDir("");
//            d.setCodigo(arbol.findNodo(arbol.getFirstPos(),aux->getData()));
//            d.setCaracter(aux->getData().getCaracter());
//            dicDatos.insertData(dicDatos.getLastPos(),d);
//            aux=aux->getNext();
//        }
        arbol.makeDataDir();
        dicDatos=arbol.getDicc();
        qAux=dicDatos.toString().c_str();
        ui->textBrowser->append(qAux);







    }
}

/*Descomprimir*/
void MenuHuffman::on_pushButton_2_clicked()
{

}

QString MenuHuffman::getCadena() const
{
    return cadena;
}

void MenuHuffman::setCadena(const QString &value)
{
    cadena = value;
}

/*Regresar*/
void MenuHuffman::on_pushButton_3_clicked()
{
    MenuSU *SU = new MenuSU();
    this->hide();
    SU->setCode(code);
    SU->show();
    this->close();
}

QString MenuHuffman::getCode() const
{
    return code;
}

void MenuHuffman::setCode(const QString &value)
{
    code = value;
}
