#include "nodohuffman.h"

using namespace std;

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
    string result;
    result+="[";
    if(caracter=='\n'){
        result+="endl";
    }
    else{
        result+=caracter;
    }
    result+=" ";
    result+=to_string(frec);
    result+="]";
    return result;
}

bool Data::operator ==(const Data &d)
{
    return (frec==d.frec) and (caracter==d.caracter);
}

bool Data::operator !=(const Data &d)
{
    return (frec!=d.frec) or (caracter!=d.caracter);
}

bool Data::operator <=(const Data &d)
{
    if(frec<d.frec){
        return true;
    }
    if(frec==d.frec){
        return caracter<=d.caracter;
    }
    return false;
}

bool Data::operator <(const Data &d)
{
    if(frec<d.frec){
        return true;
    }
    if(frec==d.frec){
        return caracter<d.caracter;
    }
    return false;
}

bool Data::operator >=(const Data &d)
{
    if(frec>d.frec){
        return true;
    }
    if(frec==d.frec){
        return caracter>=d.caracter;
    }
    return false;
}

bool Data::operator >(const Data &d)
{
    if(frec>d.frec){
        return true;
    }
    if(frec==d.frec){
        return caracter>d.caracter;
    }
    return false;
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
