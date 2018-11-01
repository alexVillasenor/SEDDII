#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <exception>
#include <string>

#include "node.h"

class StackException : public std::exception {
    private:
        std::string msg;
    public:
        explicit StackException(const char* message) : msg(message) {}
        explicit StackException(const std::string& message) : msg(message) {}
        virtual ~StackException() throw () {}
        virtual const char* what() const throw () {
            return msg.c_str();
            }

    };

template <class T>
class Stack {
    private:
        Node<T>* anchor;

        void copyAll(const Stack&);

    public:
        void deleteAll();
        Stack();
        Stack(const Stack&);///constructor copia
        ~Stack();

        bool isEmpty();

        void push(const T&);

        T pop();

        T getTop();

        Stack& operator = (const Stack&);///Compadre
    };

template <class T>
void Stack<T>::copyAll(const Stack<T>& s) {
    Node<T> *aux(s.anchor), *lastInserted(nullptr), *newNode;

    while(aux != nullptr){
        ///inflacion de software
        ///insertData(getLastPos(),aux->getData())
        newNode = new Node<T>(aux->getData());
        if (newNode==nullptr){
            throw StackException("Memoria no disponible, creando nuevo nodo durante copia de la pila");
        }
        if(lastInserted == nullptr){
            anchor=newNode;
        }
        else{
            lastInserted->setNext(newNode);
        }
        lastInserted = newNode;
        aux=aux->getNext();
        }
    }

template<class T>
void Stack<T>::deleteAll(){
    Node<T>* aux;

    while(anchor!=nullptr){
        aux=anchor;
        anchor=anchor->getNext();
        delete aux;
        }
    }
/// ******

template <class T>
Stack<T>::Stack() : anchor(nullptr) {}

template <class T>
Stack<T>::~Stack(){
    deleteAll();
    }

template <class T>
Stack<T>::Stack(const Stack<T>& s) : anchor(nullptr) {
    copyAll(s);
    }

template <class T>
bool Stack<T>::isEmpty() {
    return anchor == nullptr;
    }

template <class T>
void Stack<T>::push(const T& e) {
    Node<T>* aux(new Node<T>(e));
    if(aux==nullptr){
        throw StackException("Memoria no disponible creando nodo, haciendo push");
        }
    aux->setNext(anchor);
    anchor=aux;
    }

template <class T>
T Stack<T>::pop() {
    if(isEmpty()) {
        throw StackException("Insuficiencia de datos, pop");
        }
    T result(anchor->getData());
    Node<T>* aux(anchor);
    anchor=anchor->getNext();
    delete aux;
    return result;
    }

template <class T>
T Stack<T>::getTop() {
    if(isEmpty()) {
        throw StackException("Insuficiencia de datos, getTop");
        }
    return anchor->getData();
    }

template <class T>
Stack<T>& Stack<T>::operator = (const Stack<T>& s) {
    deleteAll();
    copyAll(s);
    return *this;
    }

#endif // STACK_H_INCLUDED
