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

        ofstream f("Profesores2.txt");
        f<<cadenaEncriptada.toStdString();
        f.close();

        f.open("Diccionario de datos.txt");
        f<<arbol.getFirstPos()->getData().getFrec()<<endl;
        Node<DicDatosHuffman>* aux=dicDatos.getFirstPos();
        while(aux!=nullptr){
            f<<aux->getData().getCaracter()<<"~"<<aux->getData().getCodigo()<<"~";
            aux=aux->getNext();
        }
        f.close();
    }
}

char* chartobin ( unsigned char c )
{
    static char bin[CHAR_BIT + 1] = { 0 };
    int i;

    for ( i = CHAR_BIT - 1; i >= 0; i-- )
    {
        bin[i] = (c % 2) + '0';
        c /= 2;
    }

    return bin;
}

/*Descomprimir*/
void MenuHuffman::on_pushButton_2_clicked()
{
    ui->textBrowser->clear();
    List<DicDatosHuffman> dicDatos;
    int maxSize;
    ifstream f("Diccionario de datos.txt");
    if(!f.is_open()){
        cout<<"::Error al abrir archivo::"<<endl;
    }
    else{
        string str;
        getline(f,str);
        stringstream ss;
        ss<<str;
        ss>>maxSize;
        while(!f.eof()){
            DicDatosHuffman d;
            getline(f,str,'~');
            if(f.eof()){break;}
            d.setCaracter(str);
            getline(f,str,'~');
            d.setCodigo(str);

            dicDatos.insertData(dicDatos.getLastPos(),d);
        }
        f.close();

        f.open("Profesores2.txt");
        cadena.clear();
        while (!f.eof()) {
            char aux;
            f.read((char*)&aux,sizeof(aux));
            if(f.eof()){
                break;
            }
            cadena+=aux;
        }
        f.close();
        ui->textBrowser->append("1.-");
        ui->textBrowser->append(cadena);
        str.clear();
        for(int i(0);i<cadena.length();i++){
            unsigned char a=cadena.toStdString().c_str()[i];
            str+=chartobin(a);
        }
        QString cadenaBinaria=str.c_str();
        ui->textBrowser->append("2.-");
        ui->textBrowser->append(cadenaBinaria);



    }


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
