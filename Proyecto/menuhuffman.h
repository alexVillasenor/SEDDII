#ifndef MENUHUFFMAN_H
#define MENUHUFFMAN_H

#include <QWidget>
#include "login.h"
#include <string>
#include "tda_huffman.h"
#include <bitset>
#include "node.h" /// Es un nodo doblemente ligado


namespace Ui {
class MenuHuffman;
}

class MenuHuffman : public QWidget
{
    Q_OBJECT

public:
    explicit MenuHuffman(QWidget *parent = 0);
    ~MenuHuffman();

    std::string decToBin(int &n);
    int binToDec(const std::string binary);

    QString getCode() const;
    void setCode(const QString &value);

    std::string getCadena() const;
    void setCadena(const std::string &value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MenuHuffman *ui;
    std::string cadena;
    QString code;
};

#endif // MENUHUFFMAN_H
