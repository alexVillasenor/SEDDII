#ifndef NODOHUFFMAN_H
#define NODOHUFFMAN_H


class NodoHuffman
{
private:
    NodoHuffman* prev;
    NodoHuffman* next;
    NodoHuffman* left;
    NodoHuffman* right;
    char caracter;
    int frec;

public:
    NodoHuffman();
    NodoHuffman(NodoHuffman* nodo);
    NodoHuffman *getPrev() const;
    void setPrev(NodoHuffman *value);
    NodoHuffman *getNext() const;
    void setNext(NodoHuffman *value);
    NodoHuffman *getLeft() const;
    void setLeft(NodoHuffman *value);
    NodoHuffman *getRight() const;
    void setRight(NodoHuffman *value);
    char getCaracter() const;
    void setCaracter(char value);
    int getFrec() const;
    void setFrec(int value);

    NodoHuffman &operator = (const NodoHuffman &nodo);

};

#endif // NODOHUFFMAN_H
