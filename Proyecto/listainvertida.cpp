#include "listainvertida.h"

Programa *ListaInvertida::getInicioProgramas() const
{
    return inicioProgramas;
}

void ListaInvertida::setInicioProgramas(Programa *value)
{
    inicioProgramas = value;
}

IndiceSecundario *ListaInvertida::getInicioIndiceSecundario() const
{
    return inicioIndiceSecundario;
}

void ListaInvertida::setInicioIndiceSecundario(IndiceSecundario *value)
{
    inicioIndiceSecundario = value;
}

void ListaInvertida::agregar(const Asignatura &a)
{
    IndiceSecundario i;
    i.setCodigo(a.getCodigo());
    addIndiceSecundario(i);

    Programa* prog=findPrograma(a.getPrograma());
    if(prog==nullptr){
        addPrograma(a.getPrograma());
        prog=findPrograma(a.getPrograma());
        prog->setFirst(getLastIndiceSecundario());

    }
    else{
        IndiceSecundario* auxIndice;
        auxIndice=prog->getFirst();
        if(auxIndice==nullptr){
            prog->setFirst(getLastIndiceSecundario());
        }
        else{
            while(auxIndice->getNextPrograma()!=nullptr){
                auxIndice=auxIndice->getNextPrograma();
            }
            auxIndice->setNextPrograma(getLastIndiceSecundario());
        }

    }
}

void ListaInvertida::addPrograma(const QString &nombre)
{
    Programa* nuevo = new Programa;
    nuevo->setNombre(nombre);

    if(isEmpty()){
        inicioProgramas=nuevo;
    }
    else{
        Programa* aux;
        aux=getLastPrograma();
        aux->setNext(nuevo);
    }
}

Programa *ListaInvertida::getLastPrograma()
{
    if(isEmpty()){
        qDebug()<<"::No hay Programas::";
    }

    Programa *aux=inicioProgramas;
    while(aux->getNext()!=nullptr){
        aux=aux->getNext();
    }
    return aux;
}

void ListaInvertida::addIndiceSecundario(const IndiceSecundario i)
{
    IndiceSecundario* nuevo = new IndiceSecundario(i);

    if(isEmptyIndiceSec()){
        inicioIndiceSecundario=nuevo;
    }
    else{
        IndiceSecundario* aux;
        aux=getLastIndiceSecundario();
        aux->setNext(nuevo);
    }
}

IndiceSecundario *ListaInvertida::getLastIndiceSecundario()
{
    if(isEmptyIndiceSec()){
        qDebug()<<"::No hay indices secundarios::";
    }

    IndiceSecundario *aux=inicioIndiceSecundario;
    while(aux->getNext()!=nullptr){
        aux=aux->getNext();
    }
    return aux;

}

IndiceSecundario *ListaInvertida::getIndiceSecundario(const long &pos)
{
    if(isEmptyIndiceSec()){
        qDebug()<<"::No hay indices secundarios::";
        return nullptr;
    }
    if(pos==-1){
        return nullptr;
    }

    IndiceSecundario *aux=inicioIndiceSecundario;
    long int c=0;

    while(aux!=nullptr){
        if(c==pos){
            return aux;
        }
        c++;
        aux=aux->getNext();
    }

}

long ListaInvertida::getPos(const IndiceSecundario *i)
{
    long int c=0;

    IndiceSecundario* aux=inicioIndiceSecundario;
    while(aux!=nullptr){
        if(aux==i){
            return c;
        }
        c++;
        aux=aux->getNext();
    }

    if(aux==nullptr)
        c=-1;

    return c;
}

IndiceSecundario *ListaInvertida::findIndiceSecundario(const QString &codigo)
{
    IndiceSecundario* aux;
    aux=inicioIndiceSecundario;
    while(aux!=nullptr){
        if(QString::number(aux->getCodigo())==codigo){
            return aux;
        }
        aux=aux->getNext();
    }
    return aux;
}

void ListaInvertida::deleteIndiceSec(const QString &codigo)
{
    Programa* est=getInicioProgramas();
    IndiceSecundario* auxDel=findIndiceSecundario(codigo);

    while(est!=nullptr){
        IndiceSecundario*aux=est->getFirst();
        if(est->getFirst()==auxDel){
            est->setFirst(aux->getNextPrograma());
            break;
        }
        else{
            while(aux!=nullptr){
                if(aux->getNextPrograma()==auxDel){
                    aux->setNextPrograma(auxDel->getNextPrograma());
                    break;
                }
                aux=aux->getNextPrograma();
            }
        }
        est=est->getNext();
    }

    if(inicioIndiceSecundario==auxDel){
        inicioIndiceSecundario=auxDel->getNext();
    }

    else{
        IndiceSecundario* aux=inicioIndiceSecundario;
        while(aux!=nullptr){
            if(aux->getNext()==auxDel){
                aux->setNext(auxDel->getNext());
                break;
            }
            aux=aux->getNext();
        }
    }

    delete auxDel;
}

Programa* ListaInvertida::findPrograma(const QString &nombre)
{
    Programa* aux;
    aux=inicioProgramas;
    while(aux!=nullptr){
        if(aux->getNombre()==nombre){
            return aux;
        }
        aux=aux->getNext();
    }
    return aux;
}


ListaInvertida::ListaInvertida()
{
    inicioIndiceSecundario=nullptr;
    inicioProgramas=nullptr;
}

void ListaInvertida::deleteAll()
{
    IndiceSecundario *auxInd,*iDel;
    Programa *auxPro,*pDel;

    auxInd=inicioIndiceSecundario;
    auxPro=inicioProgramas;
    while(auxInd!=nullptr){
        iDel=auxInd;
        auxInd=auxInd->getNext();
        delete iDel;
    }
    while(auxPro!=nullptr){
        pDel=auxPro;
        auxPro=auxPro->getNext();
        delete pDel;
    }
    inicioIndiceSecundario=nullptr;
    inicioProgramas=nullptr;
}

bool ListaInvertida::isEmpty()
{
    return inicioProgramas==nullptr;
}

bool ListaInvertida::isEmptyIndiceSec()
{
    return inicioIndiceSecundario==nullptr;

}
