#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <exception>
#include <string>
#include "node.h" ///doblemente ligado

using namespace std;

class QueueException : public std::exception {
    private:
        std::string msg;
    public:
        explicit QueueException(const char* message) : msg(message) {}
        explicit QueueException(const std::string& message) : msg(message) {}
        virtual ~QueueException() throw () {}
        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

template<class T>
class Queue {
    private:
        Node<T>* header;

        void copyAll(const Queue<T>&);

        void deleteAll();

    public:
        Queue();
        Queue(const Queue&);
        ~Queue();

        bool isEmpty();

        void enqueue(const T&);

        T dequeue();

        T getFront();

        //string toString();

        Queue<T>& operator =(const Queue<T>&);///operador de asignacion
    };

template <class T>
void Queue<T>::copyAll(const Queue<T>& q) {
    Node<T> *aux(q.header->getNext()), *newNode;

    while(aux!=q.header){
        ///inflacion de software
        ///insertData(getLastPos(),aux->getData())
        newNode = new Node<T>(aux->getData());
        if (newNode==nullptr){
            throw QueueException("Memoria no disponible, creando nuevo nodo durante copia de la cola");
        }
        newNode->setPrev(header->getPrev());
        newNode->setnext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
        }
    }

template <class T>
void Queue<T>::deleteAll() {

    Node<T> *aux;

    while(header->getNext()!=header){
        aux = header->getNext();

        header->setNext(aux->getNext());
        delete aux;
        }
    }

///**************

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q) {
    deleteAll();

    copyAll(q);

    return *this;
    }

template <class T>
T Queue<T>::getFront() {
    if(isEmpty()){
        throw QueueException("Insuficiencia de datos, dequeue");
    }
    return header->getNext()->getData();
    }

template <class T>
T Queue<T>::dequeue() {
    if(isEmpty()){
        throw QueueException("Insuficiencia de datos, dequeue");
    }

    Node<T>* aux(header->getNext());

    T result(aux->getData());

    aux->getPrev()->setNext(aux->getNext());
    aux->getNext()->setPrev(aux->getPrev());
    delete aux;

    return result;
    }
template <class T>
void Queue<T>::enqueue(const T& e) {
    Node<T>* aux;

    try{
    if((aux = new Node<T>(e))==nullptr){
        throw QueueException("Memoria no disponible creando nuevo nodo, enqueue");
        }
    }catch(NodeException ex){
        throw QueueException ("Excepcion de nod, durante la inicializacion, enqueue");
    }

    aux->setPrev(header->getPrev());
    aux->setNext(header);

    header->getPrev()->setNext(aux);
    header->setPrev(aux);
    }

template <class T>
bool Queue<T>::isEmpty() {
    return header->getNext()==header;
    }

/*
template <class T>
string Queue<T>::toString()
{
    string result;
    while(!isEmpty()){
        result+=getFront();
    }
    return result;
}
*/


template <class T>
Queue<T>::~Queue(){
    deleteAll();

    delete header;
    }

template <class T>
Queue<T>::Queue() {
    header =new(Node<T>);

    if(header==nullptr){
        throw QueueException("Memoria no disponible, incializando cola");
    }

    header->setPrev(header);
    header->setNext(header);
}




#endif // QUEUE_H_INCLUDED


