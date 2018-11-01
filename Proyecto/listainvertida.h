#ifndef LISTAINVERTIDA_H
#define LISTAINVERTIDA_H
#include <QString>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <fstream>
#include "indicesecundario.h"
#include "programa.h"
#include "asignatura.h"

class ListaInvertida
{
private:
    Programa* inicioProgramas;
    IndiceSecundario* inicioIndiceSecundario;
public:
    ListaInvertida();
    void deleteAll();
    bool isEmpty();
    bool isEmptyIndiceSec();

    Programa *getInicioProgramas() const;
    void setInicioProgramas(Programa *value);
    IndiceSecundario *getInicioIndiceSecundario() const;
    void setInicioIndiceSecundario(IndiceSecundario *value);

    void agregar(const Asignatura&a);

    void addPrograma(const QString &nombre);
    Programa* getLastPrograma();
    Programa *findPrograma(const QString& nombre);

    void addIndiceSecundario(const IndiceSecundario i);
    IndiceSecundario* getLastIndiceSecundario();
    IndiceSecundario* getIndiceSecundario(const long int &pos);
    long int getPos(const IndiceSecundario* i);
    IndiceSecundario *findIndiceSecundario(const QString& codigo);
    void deleteIndiceSec(const QString& codigo);




};

#endif // LISTAINVERTIDA_H
