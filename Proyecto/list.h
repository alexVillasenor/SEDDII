#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <exception>
#include <string>

#include "node.h" /// Es un nodo doblemente ligado

class ListException : public std::exception {
private:
    std::string msg;
public:
    explicit ListException(const char* message) : msg(message) {}
    explicit ListException(const std::string& message) : msg(message) {}
    virtual ~ListException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

template <class T>
class List {
private:
    Node<T>* anchor;

    void copyAll(const List<T>&);
    bool isValidPos(Node<T>*);
    void swapData(Node<T>*, Node<T>*);
    void quickSort(Node<T> *leftEdge, Node<T>* rightEdge);

public:
    List();
    List(const List<T>&);
    ~List();

    int getSize();
    bool isEmpty();

    void insertData(Node<T>*, const T&);

    void deleteData(Node<T>*);

    Node<T>* getFirstPos();
    Node<T>* getLastPos();
    Node<T>* getPrevPos(Node<T>*);
    Node<T>* getNextPos(Node<T>*);

    Node<T>* findData(const T&);
    Node<T>* findData2(const T&);

    void shellSort();
    void quickSort();

    T retriveData(Node<T>*);

    std::string toString();

    void deleteAll();

    List<T>& operator = (const List<T>&);

};

template <class T>
bool List<T>::isValidPos(Node<T>* p) {
    Node<T>* aux(anchor);

    while(aux != nullptr){
        if(aux == p){
            return true;
        }
        aux=aux->getNext();
    }
    return false;
}

template <class T>
void List<T>::swapData(Node<T>* a, Node<T>* b) {
    T aux(a->getData());

    a->setData(b->getData());
    b->setData(aux);
}

template <class T>
int List<T>::getSize() {
    Node<T>* aux(anchor);
    int cont(0);
    while (aux!=nullptr) {
        cont++;
        aux=aux->getNext();
    }
    return cont;
}

template <class T>
void List<T>::copyAll(const List<T>& l) {
    Node<T> *aux(l.anchor), *lastInserted(nullptr), *newNode;

    while(aux != nullptr){
        ///inflacion de software
        ///insertData(getLastPos(),aux->getData())
        newNode = new Node<T>(aux->getData());
        if (newNode==nullptr){
            throw ListException("Memoria no disponible, creando nuevo nodo durante copia de la lista");
        }
        if(lastInserted == nullptr){
            anchor=newNode;
        }
        else{
            lastInserted->setNext(newNode);
            newNode->setPrev(lastInserted);
        }
        lastInserted = newNode;
        aux=aux->getNext();
    }
}

template <class T>
List<T>::List() :anchor(nullptr) {}

template <class T>
List<T>::~List(){
    deleteAll();
}

template <class T>
List<T>::List(const List<T>& l):anchor(nullptr) {
    copyAll(l);
}

template <class T>
bool List<T>::isEmpty() {
    return anchor == nullptr;
}

template <class T>
void List<T>::insertData(Node<T>* p, const T& e) {
    if(p != nullptr and !isValidPos(p)) {
        throw ListException("Posicion invalida, tratando de insertar");
    }
    Node<T>* aux(new Node<T>(e));

    if(aux == nullptr) {
        throw ListException("Memoria no disponible para crear nuevo nodo, tratando de insertar");
    }
    if(p==nullptr){/// insertar al principio
        ///aux->setPrev(nullptr);///redundante (no es necesaria)
        aux->setNext(anchor);
        if(anchor!=nullptr){
            anchor->getNext()->setPrev(aux);
        }
        anchor=aux;
    }
    else{            ///Insertar en otra parte
        aux->setPrev(p);
        aux->setNext(p->getNext());
        if(p->getNext()!=nullptr){
            p->getNext()->setPrev(aux);
        }
        p->setNext(aux);
    }
}

template <class T>
void List<T>::deleteData(Node<T>* p) {
    if(!isValidPos(p)) {
        throw ListException("Posicion invlaida, tratando de eliminar");
    }
    if(p->getPrev()!=nullptr){///si existe, el anterior apunta al siguiente
        p->getPrev()->setNext(p->getNext());
    }
    if(p->getNext()!=nullptr){///si existe, el sioguiente apunta al anterior
        p->getNext()->setPrev(p->getPrev());
    }
    if(p==anchor){///si es el primero, recorrer ancla
        anchor=anchor->getNext();
    }
    delete p;///liberar espacio de memoria
}

template <class T>
Node<T>* List<T>::getFirstPos() {
    return anchor;
}

template <class T>
Node<T>* List<T>::getLastPos() {
    if(isEmpty()) {
        return nullptr;
    }

    Node<T>* aux(anchor);

    while(aux->getNext() != nullptr) {
        aux=aux->getNext();
    }
    return aux;
}

template <class T>
Node<T>* List<T>::getPrevPos(Node<T>* p) {
    if(!isValidPos(p)){
        return nullptr;
    }
    return p->getPrev();
}

template <class T>
Node<T>* List<T>::getNextPos(Node<T>* p) {
    if(!isValidPos(p)){
        return nullptr;
    }
    return p->getNext();
}

template <class T>
Node<T>* List<T>::findData(const T& e) {
    Node<T>* aux(anchor);

    while(aux!=nullptr and aux->getData()!=e){
        aux=aux->getNext();
    }
    return aux;
}

template <class T>
Node<T>* List<T>::findData2(const T& e) {
    Node<T>* aux(anchor);

    while(aux!=nullptr and aux->getData()%e){
        aux=aux->getNext();
    }
    return aux;
}

template <class T>
void List<T>::shellSort() {
    int last(getSize());
    float fact(3.0 / 4.0);
    int dif(last * fact);
    Node<T>* lim;
    Node<T>* i;
    Node<T>* idif;
    Node<T>* auxgrl;
    while(dif > 0) {
        i=anchor;
        lim=anchor;
        auxgrl=anchor;
        int cont(0), cic(0),c2(0);
        while(cont!=(last-dif)) {
            lim=lim->getNext();
            cont++;
        }

        while(auxgrl!=lim) {
            auxgrl=auxgrl->getNext();
            cic++;
        }

        while(c2<=cic) {
            Node<T>* aux(i->getNext());
            idif=i;
            cont=0;
            while(cont!=dif and idif->getNext()!=nullptr) {
                idif=idif->getNext();
                cont++;
            }
            if(i->getData()<idif->getData()) {
                swapData(i,idif);
            }
            i=aux;
            c2++;
        }
        dif*=fact;
    }
}

template<class T>
void List<T>::quickSort() {
    quickSort(getFirstPos(),getLastPos());
}

template<class T>
void List<T>::quickSort(Node<T>* leftEdge,Node<T>* rightEdge) {
    if(leftEdge>=rightEdge) { ///Criterio de paro
        return;
    }

    Node<T>* i=leftEdge;
    Node<T>* j=rightEdge;
    ///Separacion de elementos

    while(i<j) {
        while(i<j and i->getData()<=rightEdge->getData()) {
            i=i->getNext();
        }
        while(i<j and j->getData()>=rightEdge->getData()) {
            j=j->getPrev();
        }
        if(i!=j) {
            swapData(i,j);
        }
    }

    if(i!=rightEdge) { /// reubicacion del pivote
        swapData(i,rightEdge);
    }
    ///Divide y venceras
    quickSort(leftEdge,i->getPrev());
    quickSort(i->getNext(),rightEdge);
}

template <class T>
T List<T>::retriveData(Node<T>* p) {
    if(!isValidPos(p)){
        throw ListException("Posicion invalida, haciendo retrieve");
    }
    return p->getData();
}

template <class T>
std::string List<T>::toString() {
    std::string result;
    Node<T>* aux(anchor);

    while(aux != nullptr){
        result+= aux->getData().toString() + "\n";
        aux=aux->getNext();
    }
    return result;
}

template <class T>
void List<T>::deleteAll() {
    Node<T>* aux;

    while(anchor!=nullptr){
        aux=anchor;
        anchor=anchor->getNext();
        delete aux;
    }
}

template <class T>
List<T>& List<T>::operator=(const List<T>& l) {
    deleteAll();

    copyAll(l);

    return *this;
}

#endif // LIST_H_INCLUDED
