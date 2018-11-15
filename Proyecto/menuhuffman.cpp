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
            string auxStr;
            getline(file,auxStr);
            if(file.eof()){
                break;
            }
            auxStr+="\n";
            cadena+=auxStr.c_str();
        }
        file.close();
        ui->textBrowser->append(cadena);

        ui->textBrowser->append("2.- ");

        TDA_Huffman arbol;
        for(int i(0);i<cadena.length();i++){
            Data d,d1;
            d1.setCaracter(cadena.toStdString()[i]);
            NodoHuffman* nodo=arbol.findData(d1);
            if(nodo==nullptr){
                d.setCaracter(cadena.toStdString()[i]);
                int frec(0);
                for(int j(i);j<cadena.length();j++){
                    if(d.getCaracter()==cadena[j]){
                        frec++;
                    }
                }
                d.setFrec(frec);
                arbol.insertData(arbol.getLastPos(),d);
            }
        }
        QString qAux=arbol.toString().c_str();
        ui->textBrowser->append(qAux);

        ui->textBrowser->append("3.- ");
        arbol.shellSort();

        qAux=arbol.toString().c_str();
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
