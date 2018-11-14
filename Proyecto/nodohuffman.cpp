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

NodoHuffman::NodoHuffman()
{
    prev=nullptr;
    next=nullptr;
    left=nullptr;
    right=nullptr;
}
