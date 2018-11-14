#include "tda_huffman.h"

NodoHuffman *TDA_Huffman::getInicio() const
{
    return inicio;
}

void TDA_Huffman::setInicio(NodoHuffman *value)
{
    inicio = value;
}

TDA_Huffman::TDA_Huffman()
{

}

int TDA_Huffman::getSize()
{
    NodoHuffman* aux=inicio;
    int cont(0);
    while (aux!=nullptr) {
        cont++;
        aux=aux->getNext();
    }
    return cont;
}

bool TDA_Huffman::isEmpty()
{
    return inicio==nullptr;
}

/////terminar
void TDA_Huffman::insert(NodoHuffman *nodo)
{
    NodoHuffman* aux=getLastPos();

    if(aux==nullptr){

    }
    else{

    }
}

NodoHuffman *TDA_Huffman::getLastPos()
{
    if(isEmpty()){
        return nullptr;
    }

    NodoHuffman* aux=inicio;

    while(aux->getNext() != nullptr) {
        aux=aux->getNext();
        }
    return aux;
}

QString TDA_Huffman::toQString()
{
    QString result;
    NodoHuffman* aux=inicio;

    while(aux != nullptr) {
        result+="["+aux->getCaracter()+"]";
        if(aux->getNext()==nullptr)
            result+="->";
        aux=aux->getNext();
        }
}
