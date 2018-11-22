#include "tda_huffman.h"


bool TDA_Huffman::isValidPos(NodoHuffman* p) {
    NodoHuffman* aux(anchor);

    while(aux != nullptr){
        if(aux == p){
            return true;
        }
        aux=aux->getNext();
    }
    return false;
}


void TDA_Huffman::swapData(NodoHuffman* a, NodoHuffman* b) {
    Data aux(a->getData());

    a->setData(b->getData());
    b->setData(aux);
}


int TDA_Huffman::getSize() {
    NodoHuffman* aux(anchor);
    int cont(0);
    while (aux!=nullptr) {
        cont++;
        aux=aux->getNext();
    }
    return cont;
}

List<DicDatosHuffman> TDA_Huffman::getDicc() const
{
    return dicc;
}

void TDA_Huffman::setDicc(const List<DicDatosHuffman> &value)
{
    dicc = value;
}

void TDA_Huffman::copyAll(const TDA_Huffman& l) {
    NodoHuffman *aux(l.anchor), *lastInserted(nullptr), *newNode;

    while(aux != nullptr){
        ///inflacion de software
        ///insertData(getLastPos(),aux->getData())
        newNode = new NodoHuffman();
        newNode->setData(aux->getData());
        if (newNode==nullptr){
            throw HuffmanException("Memoria no disponible, creando nuevo nodo durante copia de la TDA_Huffmana");
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


TDA_Huffman::TDA_Huffman() :anchor(nullptr) {}


TDA_Huffman::~TDA_Huffman(){
    deleteAllTDA();
    deleteAllTree();
}


TDA_Huffman::TDA_Huffman(const TDA_Huffman& l):anchor(nullptr) {
    copyAll(l);
}


bool TDA_Huffman::isEmpty() {
    return anchor == nullptr;
}


void TDA_Huffman::insertData(NodoHuffman* p, const Data& e) {
    if(p != nullptr and !isValidPos(p)) {
        throw HuffmanException("Posicion invalida, tratando de insertar");
    }
    NodoHuffman* aux=new NodoHuffman();
    aux->setData(e);

    if(aux == nullptr) {
        throw HuffmanException("Memoria no disponible para crear nuevo nodo, tratando de insertar");
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

void TDA_Huffman::insertData(NodoHuffman* p, NodoHuffman* e) {
    if(p != nullptr and !isValidPos(p)) {
        throw HuffmanException("Posicion invalida, tratando de insertar");
    }
    NodoHuffman* aux=new NodoHuffman();
    aux=e;

    if(aux == nullptr) {
        throw HuffmanException("Memoria no disponible para crear nuevo nodo, tratando de insertar");
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

void TDA_Huffman::insertData(NodoHuffman *p)
{
    NodoHuffman* aux=new NodoHuffman();

    if(aux == nullptr) {
        throw HuffmanException("Memoria no disponible para crear nuevo nodo, tratando de insertar");
    }
    aux=getFirstPos();

    if(aux == nullptr) {
        anchor=p;
        return;
    }

    if(p->getData() < aux->getData()){
        p->setNext(aux);
        aux->setPrev(p);
        anchor=p;
        return;
    }

    while(aux!=nullptr){
        if(p->getData() < aux->getData()){
            p->setNext(aux);
            p->setPrev(aux->getPrev());
            aux->getPrev()->setNext(p);
            aux->setPrev(p);
            return;
        }
        aux=aux->getNext();
    }

    if(aux==nullptr){
        p->setPrev(getLastPos());
        getLastPos()->setNext(p);
    }
}


void TDA_Huffman::deleteData(NodoHuffman* p) {
    if(!isValidPos(p)) {
        throw HuffmanException("Posicion invlaida, tratando de eliminar");
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


NodoHuffman* TDA_Huffman::getFirstPos() {
    return anchor;
}


NodoHuffman* TDA_Huffman::getLastPos() {
    if(isEmpty()) {
        return nullptr;
    }

    NodoHuffman* aux(anchor);

    while(aux->getNext() != nullptr) {
        aux=aux->getNext();
    }
    return aux;
}


NodoHuffman* TDA_Huffman::getPrevPos(NodoHuffman* p) {
    if(!isValidPos(p)){
        return nullptr;
    }
    return p->getPrev();
}


NodoHuffman* TDA_Huffman::getNextPos(NodoHuffman* p) {
    if(!isValidPos(p)){
        return nullptr;
    }
    return p->getNext();
}


NodoHuffman* TDA_Huffman::findData(const Data &e) {
    NodoHuffman* aux=anchor;

    while(aux!=nullptr and aux->getData().getCaracter()!= e.getCaracter()){
        aux=aux->getNext();
    }
    return aux;
}

void TDA_Huffman::findNodo(NodoHuffman* r, std::string path)
{
    if(!r){
        return;
    }
    if(r->getData().getCaracter() != "") {
        DicDatosHuffman d;
        d.setCaracter(r->getData().getCaracter());
        d.setCodigo(path);
        dicc.insertData(dicc.getLastPos(),d);
    }

    findNodo(r->getLeft(),path+"0");
    findNodo(r->getRight(),path+"1");

}


void TDA_Huffman::shellSort() {
    int last(getSize());
    float fact(3.0 / 4.0);
    int dif(last * fact);
    NodoHuffman* lim;
    NodoHuffman* i;
    NodoHuffman* idif;
    NodoHuffman* auxgrl;
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
            NodoHuffman* aux(i->getNext());
            idif=i;
            cont=0;
            while(cont!=dif and idif->getNext()!=nullptr) {
                idif=idif->getNext();
                cont++;
            }
            if(i->getData()>idif->getData()) {
                swapData(i,idif);
            }
            i=aux;
            c2++;
        }
        dif*=fact;
    }
}

void TDA_Huffman::quickSort() {
    quickSort(getFirstPos(),getLastPos());
}

void TDA_Huffman::quickSort(NodoHuffman* leftEdge,NodoHuffman* rightEdge) {
    if(leftEdge>=rightEdge) { ///Criterio de paro
        return;
    }

    NodoHuffman* i=leftEdge;
    NodoHuffman* j=rightEdge;
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


Data TDA_Huffman::retriveData(NodoHuffman* p) {
    if(!isValidPos(p)){
        throw HuffmanException("Posicion invalida, haciendo retrieve");
    }
    return p->getData();
}

void TDA_Huffman::makeDataDir()
{
    string r;
    r.clear();
    dicc.deleteAll();
    findNodo(getFirstPos(),r);
}

bool TDA_Huffman::makeTree()
{
    if(isEmpty()){
        return false;
    }
    while(getSize()>1){
        NodoHuffman* a=getFirstPos();
        NodoHuffman* b=a->getNext();
        NodoHuffman* nuevo=new NodoHuffman();
        nuevo->setLeft(a);
        nuevo->setRight(b);
        Data d;
        d.setFrec(a->getData().getFrec()+b->getData().getFrec());
        anchor=b->getNext();
        nuevo->setData(d);
        insertData(nuevo);
        a->setPrev(nullptr);
        a->setNext(nullptr);
        b->setPrev(nullptr);
        b->setNext(nullptr);
    }
    return true;
}

std::string TDA_Huffman::toString() {
    std::string result;
    NodoHuffman* aux=anchor;

    while(aux != nullptr){
        result+= aux->getData().toString();
        if(aux->getNext()!=nullptr){
            result+="->";
        }
        aux=aux->getNext();
    }
    return result;
}

string TDA_Huffman::treeToString()
{
    string result;
    result=(parsePreOrder(getFirstPos()));
    return result;
}

string TDA_Huffman::parsePreOrder(NodoHuffman *r)
{
    if(r == nullptr) {
        return "";
    }

    std::string result;

    result += r->getData().toString();
    result += ", ";
    result += parsePreOrder(r->getLeft());
    result += parsePreOrder(r->getRight());

    return result;
}


void TDA_Huffman::deleteAllTDA() {
    NodoHuffman* aux;

    while(anchor!=nullptr){
        aux=anchor;
        anchor=anchor->getNext();
        delete aux;
    }
}

void TDA_Huffman::deleteAllTree()
{
    deleteAllTree(getFirstPos());
}

void TDA_Huffman::deleteAllTree(NodoHuffman *r)
{
    if(r==nullptr) {
        return;
    }

    deleteAllTree(r->getLeft());
    deleteAllTree(r->getRight());

    delete r;
    r == nullptr;
}


TDA_Huffman& TDA_Huffman::operator=(const TDA_Huffman& l) {
    deleteAllTDA();

    copyAll(l);

    return *this;
}
