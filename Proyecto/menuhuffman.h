#ifndef MENUHUFFMAN_H
#define MENUHUFFMAN_H

#include <QWidget>
#include "login.h"
#include <string>
#include "tda_huffman.h"
#include <bitset>

namespace Ui {
class MenuHuffman;
}

class MenuHuffman : public QWidget
{
    Q_OBJECT

public:
    explicit MenuHuffman(QWidget *parent = 0);
    ~MenuHuffman();

    QString getCadena() const;
    void setCadena(const QString &value);

    QString getCode() const;
    void setCode(const QString &value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MenuHuffman *ui;
    QString cadena;
    QString code;
};

#endif // MENUHUFFMAN_H
