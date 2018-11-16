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
        arbol.makeDataDir();
        dicDatos=arbol.getDicc();
        qAux=dicDatos.toString().c_str();
        ui->textBrowser->append(qAux);

        QString newCadena, cadenaFragmentada, cadenaEncriptada;
        for(int i(0);i<cadena.length();i++){
            DicDatosHuffman auxDic;
            string str;
            str+=cadena.toStdString().c_str()[i];
            auxDic.setCaracter(str);
            newCadena+=dicDatos.findData(auxDic)->getData().getCodigo().c_str();
        }

        ui->textBrowser->append("6.-");
        ui->textBrowser->append(newCadena);

        for(int i(0);i<newCadena.length();i=i+8){
            string auxStr=newCadena.toStdString().substr(i,8);
            if((auxStr.length()%8)!=0){
                do{
                    auxStr+="0";
                }while((auxStr.length()%8)!=0);
            }
            cadenaFragmentada+=auxStr.c_str();
            cadenaFragmentada+=" ";
        }
        ui->textBrowser->append("7.-");
        ui->textBrowser->append(cadenaFragmentada);

        ui->textBrowser->append("8.-");
        for(int i(0);i<newCadena.length();i=i+8){
            string auxStr=newCadena.toStdString().substr(i,8);
            if((auxStr.length()%8)!=0){
                do{
                    auxStr+="0";
                }while((auxStr.length()%8)!=0);
            }
            stringstream ss;
            std::bitset<8> bits;
            ss.clear();
            ss<<auxStr;
            ss >> bits;
            char c = char(bits.to_ulong());
            cadenaEncriptada+=c;
        }

        ui->textBrowser->append(cadenaEncriptada);





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
