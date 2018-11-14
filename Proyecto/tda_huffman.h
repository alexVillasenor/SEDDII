#ifndef TDA_HUFFMAN_H
#define TDA_HUFFMAN_H
#include "nodohuffman.h"
#include <QWidget>
#include "login.h"
#include <fstream>
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QIntValidator>
#include <QRegExpValidator>
#include <regex>

class TDA_Huffman
{
private:
    NodoHuffman* inicio;
public:
    TDA_Huffman();
    ~TDA_Huffman();

    int getSize();
    bool isEmpty();

    void insert(NodoHuffman* nodo );

    NodoHuffman* getLastPos();

    void deleteAll();

    QString toQString();


    NodoHuffman *getInicio() const;
    void setInicio(NodoHuffman *value);
};

#endif // TDA_HUFFMAN_H
