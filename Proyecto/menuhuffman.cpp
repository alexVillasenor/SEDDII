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
    bool flag;
    ifstream f("Diccionario de datos.txt");
    if(!f.is_open()){
        flag = true;
    }
    else{
        flag = false;
        f.close();
    }
    if(!flag){
        ui->textBrowser->setText("::Archivo ya ha sido comprimido::");
        return;
    }
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
        QString qstr=cadena.c_str();
        ui->textBrowser->append(qstr);

        ui->textBrowser->append("2.- ");

        TDA_Huffman lista,arbol;
        for(int i(0);i<cadena.length();i++){
            Data d,d1;
            string str;
            str=cadena[i];
            d1.setCaracter(str);
            NodoHuffman* nodo=lista.findData(d1);
            if(nodo==nullptr){
                d.setCaracter(str);
                int frec(0);
                for(int j(i);j<cadena.length();j++){
                    string str2;
                    str2=cadena[j];
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

        QString newCadena, cadenaFragmentada;
        string cadenaEncriptada;
        for(int i(0);i<cadena.length();i++){
            DicDatosHuffman auxDic;
            string str;
            str+=cadena[i];
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
            cadenaFragmentada+=binToDec(auxStr);
            cadenaEncriptada+=binToDec(auxStr);
            cadenaFragmentada+=" ";
        }
        ui->textBrowser->append("7.-");
        ui->textBrowser->append(cadenaFragmentada);

        ui->textBrowser->append("8.-");
        qstr=cadenaEncriptada.c_str();
        ui->textBrowser->append(qstr);

        ofstream f("Profesores.txt");
        int i(0);
        unsigned char c;
        while(i<cadenaEncriptada.length()){
            c=cadenaEncriptada[i];
            f.write((char*)&c,sizeof(c));
            i++;
        }
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


/*Descomprimir*/
void MenuHuffman::on_pushButton_2_clicked()
{
    List<DicDatosHuffman> dicDatos;
    int total(0);
    string cadenaFinal,cadenaTraducida;
    ui->textBrowser->clear();
    bool flag;
    ifstream f("Diccionario de datos.txt");
    if(!f.is_open()){
        flag = true;
    }
    else{
        flag = false;
        f.close();
    }

    FILE *file;
    char *buffer;
    unsigned long fileLen;

    //Open file
    file = fopen("Profesores.txt", "rb");
    if (!file)
    {
        ui->textBrowser->setText("::No se pudo abrir archivo profesores::");
        return;
    }

    //Get file length
    fseek(file, 0, SEEK_END);
    fileLen=ftell(file);
    fseek(file, 0, SEEK_SET);

    //Allocate memory
    buffer=(char *)malloc(fileLen+1);
    memset(buffer, '\0', fileLen + 1);
    if (!buffer)
    {
        fclose(file);
        return;
    }

    //Read file contents into buffer
    fread(buffer, fileLen, 1, file);
    fclose(file);

    if(flag){
        ui->textBrowser->append("::No hay archivo comprimido::");
    }
    else{
        //cargarMemoria
        ifstream file("Profesores.txt");
        if(!file.is_open()){
            ui->textBrowser->append("::Error al abrir el archivo::");
        }

        else{
            cadena.clear();
            cadena=buffer;
            file.close();
            ui->textBrowser->append("1.- ");
            QString qstr=cadena.c_str();
            ui->textBrowser->append(qstr);

            //cargarDiccDatos
            ifstream f("Diccionario de datos.txt");
            if(!f.is_open()){
                ui->textBrowser->append("::Error al abrir archivo::");
            }
            else{
                dicDatos.deleteAll();
                string str;
                getline(f,str);
                stringstream ss;
                ss<<str;
                ss>>total;
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
                ui->textBrowser->append("2.- "+QString::number(total)+" Caracteres");
                ui->textBrowser->append("3.- ");
                QString qstr=dicDatos.toString().c_str();
                ui->textBrowser->append(qstr);

                //desencriptar

                cadenaTraducida.clear();
                for(int i(0);i<cadena.length();i++){
                    int a =  int((unsigned char)cadena[i]);
                    qDebug()<<cadena[i]<<a;
                    cadenaTraducida+=decToBin(a);
                }
                ui->textBrowser->append("4.- ");
                qstr=cadenaTraducida.c_str();
                ui->textBrowser->append(qstr);

                //traducir

                cadenaFinal.clear();
                int cont(0);
                for(int i(0);i<cadenaTraducida.length();i++){
                    DicDatosHuffman auxDic;
                    str+=cadenaTraducida[i];
                    auxDic.setCodigo(str);
                    Node<DicDatosHuffman>* nodo = dicDatos.findData2(auxDic);
                    if(nodo!=nullptr){
                        cadenaFinal+=nodo->getData().getCaracter().c_str();
                        str.clear();
                        cont++;
                    }
                    if(cont==total){
                        break;
                    }
                }
                ui->textBrowser->append("5.-");
                qstr=cadenaFinal.c_str();
                ui->textBrowser->append(qstr);
                ofstream f("Profesores.txt");
                int i(0);
                char c;
                while(i<cadenaFinal.length()){
                    c=cadenaFinal[i];
                    f.write((char*)&c,sizeof(c));
                    i++;
                }
                f.close();
                remove("Diccionario de datos.txt");
            }
        }
    }
}

string MenuHuffman::decToBin(int &n)
{
    string result,temp;
    while(n>0){
        if((n%2)==0){
            temp+="0";
        }
        else{
            temp+="1";
        }
        n=n/2;
    }
    if((temp.length()%8)!=0){
        do{
            temp+="0";
        }while((temp.length()%8)!=0);
    }
    for(int i(temp.length()-1);i>=0;i--){
        result+=temp[i];
    }
    return result;
}

int MenuHuffman::binToDec(const string binary)
{
    int len,dec=0,i,exp;

    len = binary.length();
    exp = len-1;

    for(i=0;i<len;i++,exp--)
        dec += binary[i]=='1'?pow(2,exp):0;
    return dec;
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

string MenuHuffman::getCadena() const
{
    return cadena;
}

void MenuHuffman::setCadena(const string &value)
{
    cadena = value;
}

QString MenuHuffman::getCode() const
{
    return code;
}

void MenuHuffman::setCode(const QString &value)
{
    code = value;
}
