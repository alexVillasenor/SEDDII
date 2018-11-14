#include "nodohuffman.h"

NodoHuffman *NodoHuffman::getPrev() const
{
    return prev;
}

void NodoHuffman::setPrev(NodoHuffman *value)
{
    prev = value;
}

NodoHuffman *NodoHuffman::getNext() const
{
    return next;
}

void NodoHuffman::setNext(NodoHuffman *value)
{
    next = value;
}

NodoHuffman *NodoHuffman::getLeft() const
{
    return left;
}

void NodoHuffman::setLeft(NodoHuffman *value)
{
    left = value;
}

NodoHuffman *NodoHuffman::getRight() const
{
    return right;
}

void NodoHuffman::setRight(NodoHuffman *value)
{
    right = value;
}

char NodoHuffman::getCaracter() const
{
    return caracter;
}

void NodoHuffman::setCaracter(char value)
{
    caracter = value;
}

int NodoHuffman::getFrec() const
{
    return frec;
}

void NodoHuffman::setFrec(int value)
{
    frec = value;
}

NodoHuffman &NodoHuffman::operator =(const NodoHuffman &nodo)
{
    prev=nodo.getPrev();
    next=nodo.getNext();
    left=nodo.getLeft();
    right=nodo.getRight();
    caracter=nodo.getCaracter();
    frec=nodo.getFrec();
    return *this;
}

NodoHuffman::NodoHuffman()
{
    prev=nullptr;
    next=nullptr;
    left=nullptr;
    right=nullptr;
    frec=0;
}

NodoHuffman::NodoHuffman(NodoHuffman *nodo)
{
    prev=nodo->getPrev();
    next=nodo->getNext();
    left=nodo->getLeft();
    right=nodo->getRight();
    caracter=nodo->getCaracter();
    frec=nodo->getFrec();
}
