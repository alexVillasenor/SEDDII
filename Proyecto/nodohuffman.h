#ifndef NODOHUFFMAN_H
#define NODOHUFFMAN_H
#include <exception>
#include <string>
#include <QString>

class NodoHuffmanException : public std::exception {
private:
    std::string msg;
public:
    explicit NodoHuffmanException(const char* message) : msg(message) {}
    explicit NodoHuffmanException(const std::string& message) : msg(message) {}
    virtual ~NodoHuffmanException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }

};


class Data{
private:
    std::string caracter;
    int frec;
public:
    Data();
    int getFrec() const;
    void setFrec(int value);

    std::string toString();

    bool operator ==(const Data& d);
    bool operator !=(const Data& d);
    bool operator <=(const Data& d);
    bool operator <(const Data&d);
    bool operator >=(const Data&d);
    bool operator >(const Data&d);
    std::string getCaracter() const;
    void setCaracter(const std::string &value);
};

class NodoHuffman {
private:
    Data data;
    NodoHuffman* prev;
    NodoHuffman* next;
    NodoHuffman* left;
    NodoHuffman* right;

public:
    NodoHuffman();
    NodoHuffman(const NodoHuffman&);

    NodoHuffman* getPrev();
    NodoHuffman* getNext();


    void setPrev(NodoHuffman*);
    void setNext(NodoHuffman*);

    NodoHuffman &operator = (const NodoHuffman& n);

    Data getData() const;
    void setData(const Data &value);
    NodoHuffman *getLeft() const;
    void setLeft(NodoHuffman *value);
    NodoHuffman *getRight() const;
    void setRight(NodoHuffman *value);
};

#endif // NODOHUFFMAN_H
