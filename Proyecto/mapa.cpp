#include "mapa.h"

int Mapa::getSize() const
{
    return size;
}

void Mapa::setSize(int value)
{
    size = value;
}

Mapa::Mapa()
{
    size = 0;
    Camino c;
    c.setDistancia(0);
    for(int i(0);i<12;i++)
        for(int j(0);j<12;j++)
            caminos[i][j]=c;
}

void Mapa::setEdificio(Edificio &e)
{
    e.setPos(size);
    edificios[size]=e;
    size++;
}


Edificio &Mapa::getEdificio(const int pos)
{
    return edificios[pos];
}

void Mapa::setCamino(Edificio &a, Edificio &b, const int &d)
{
    Camino c;
    c.setDistancia(d);
    c.setStatus('V');
    caminos[a.getPos()][b.getPos()]=c;
    caminos[b.getPos()][a.getPos()]=c;
}

Camino Mapa::getCamino(Edificio a, Edificio b)
{
    return caminos[a.getPos()][b.getPos()];
}

void Mapa::deleteEdificio(Edificio e)
{  
    for(int i(0);i<size;i++){
        for(int j(e.getPos());j<size;j++){
            caminos[i][j]=caminos[i][j+1];
        }
    }
    for(int i(e.getPos());i<size;i++){
        for(int j(0);j<size;j++){
            caminos[i][j]=caminos[i+1][j];
        }
    }

    for(int i(e.getPos());i<size;i++){
       edificios[i]=edificios[i+1];
    }
    size--;
}

bool Mapa::deleteCamino(Edificio a, Edificio b)
{
    for(int i(0);i<size;i++){
        if(edificios[i].getNombre()==a.getNombre()){
            a.setPos(i);
        }
        if(edificios[i].getNombre()==b.getNombre()){
            b.setPos(i);
        }
    }
    Camino c;
    c.setDistancia(0);
    if(caminos[a.getPos()][b.getPos()].getStatus()=='V'){
        caminos[a.getPos()][b.getPos()]=c;
        caminos[b.getPos()][a.getPos()]=c;
        return true;
    }
    else{
        return false;
    }
}

QString Mapa::toQstring()
{
    QString edif,camin;

    edif+="\t|";
    for(int i(0);i<size;i++){
        edif+=edificios[i].getStatus();
        edif+="\t|";
    }
    edif+="\n\t|";
    for(int i(0);i<size;i++){
        edif+=edificios[i].getNombre();
        edif+="\t|";
    }
    edif+="\n\n";
    for(int i(0);i<size;i++){
        camin+=edificios[i].getNombre();
        camin+="\t|";
        for(int j(0);j<size;j++){
            camin+=QString::number(caminos[i][j].getDistancia());
            camin+="\t|";
        }
        camin+="\n";
    }

    edif+=camin;
    return edif;
}
