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
#include <exception>
#include <string>


class HuffmanException : public std::exception {
    private:
        std::string msg;
    public:
        explicit HuffmanException(const char* message) : msg(message) {}
        explicit HuffmanException(const std::string& message) : msg(message) {}
        virtual ~HuffmanException() throw () {}
        virtual const char* what() const throw () {
            return msg.c_str();
            }

    };

class TDA_Huffman {
    private:
        NodoHuffman* anchor;

        void copyAll(const TDA_Huffman&);
        bool isValidPos(NodoHuffman*);
        void swapData(NodoHuffman*, NodoHuffman*);
        void quickSort(NodoHuffman *leftEdge, NodoHuffman* rightEdge);

    public:
        TDA_Huffman();
        TDA_Huffman(const TDA_Huffman&);
        ~TDA_Huffman();

        int getSize();
        bool isEmpty();

        void insertData(NodoHuffman*, const NodoHuffman&);

        void deleteData(NodoHuffman*);

        NodoHuffman* getFirstPos();
        NodoHuffman* getLastPos();
        NodoHuffman* getPrevPos(NodoHuffman*);
        NodoHuffman* getNextPos(NodoHuffman*);

        NodoHuffman* findData(const Data &);
        Data retriveData(NodoHuffman* p);


        void shellSort();
        void quickSort();

        std::string toString();

        void deleteAll();

        TDA_Huffman& operator = (const TDA_Huffman&);

    };
#endif // TDA_HUFFMAN_H
