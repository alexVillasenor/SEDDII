#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class NodeException : public std::exception {
private:
    std::string msg;
public:
    explicit NodeException(const char* message) : msg(message) {}
    explicit NodeException(const std::string& message) : msg(message) {}
    virtual ~NodeException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

template<class T>
class Node {
private:
    T data;
    Node<T>* prev;
    Node<T>* next;

public:
    Node();
    Node(const T&);

    T getData();
    Node<T>* getPrev();
    Node<T>* getNext();


    void setData(const T&);
    void setPrev(Node<T>*);
    void setNext(Node<T>*);

    Node<T> &operator = (const Node<T>& n);

};

template<class T>
Node<T>::Node() : prev(nullptr), next(nullptr) {}

template<class T>
Node<T>::Node(const T& e) : data(e),prev(nullptr), next(nullptr) {}
template<class T>
T Node<T>::getData() {
    return data;
}

template<class T>
Node<T>* Node<T>::getNext() {
    return next;
}

template<class T>
Node<T>* Node<T>::getPrev() {
    return prev;
}

template<class T>
void Node<T>::setData(const T& e) {
    data=e;
}

template<class T>
void Node<T>::setNext(Node<T>* p) {
    next=p;
}

template<class T>
Node<T> &Node<T>::operator =(const Node<T> &n)
{
    data=n.data;
    prev=n.prev;
    next=n.next;
    return *this;
}

template<class T>
void Node<T>::setPrev(Node<T>* p) {
    prev=p;
}
#endif // NODE_H_INCLUDED
