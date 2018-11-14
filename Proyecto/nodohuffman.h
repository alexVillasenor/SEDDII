#ifndef NODOHUFFMAN_H
#define NODOHUFFMAN_H


class NodoHuffman
{
private:
    NodoHuffman* prev;
    NodoHuffman* next;
    NodoHuffman* left;
    NodoHuffman* right;

public:
    NodoHuffman();
    NodoHuffman *getPrev() const;
    void setPrev(NodoHuffman *value);
    NodoHuffman *getNext() const;
    void setNext(NodoHuffman *value);
    NodoHuffman *getLeft() const;
    void setLeft(NodoHuffman *value);
    NodoHuffman *getRight() const;
    void setRight(NodoHuffman *value);
};

#endif // NODOHUFFMAN_H
