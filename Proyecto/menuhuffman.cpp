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
