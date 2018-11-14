#include "nodohuffman.h"

Data NodoHuffman::getData() const
{
    return data;
}

void NodoHuffman::setData(const Data &value)
{
    data = value;
}

NodoHuffman::NodoHuffman() : prev(nullptr), next(nullptr),left(nullptr), right(nullptr) {}


NodoHuffman::NodoHuffman(const NodoHuffman &e) {
    data=e.data;
    prev=e.prev;
    next=e.next;
    left=e.left;
    right=e.right;
}

NodoHuffman* NodoHuffman::getNext() {
    return next;
    }


NodoHuffman* NodoHuffman::getPrev() {
    return prev;
    }


void NodoHuffman::setNext(NodoHuffman* p) {
    next=p;
}


NodoHuffman &NodoHuffman::operator =(const NodoHuffman &n)
{
    data=n.data;
    prev=n.prev;
    next=n.next;
    left=n.left;
    right=n.right;
    return *this;
}


void NodoHuffman::setPrev(NodoHuffman* p) {
    prev=p;
    }

int Data::getFrec() const
{
    return frec;
}

void Data::setFrec(int value)
{
    frec = value;
}

std::string Data::toString()
{

}

bool Data::operator ==(const Data &)
{

}

bool Data::operator !=(const Data &)
{

}

bool Data::operator <=(const Data &)
{

}

bool Data::operator <(const Data &)
{

}

bool Data::operator >=(const Data &)
{

}

bool Data::operator >(const Data &)
{

}

Data::Data(): frec(0) {}

char Data::getCaracter() const
{
    return caracter;
}

void Data::setCaracter(char value)
{
    caracter = value;
}
