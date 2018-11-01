#ifndef INDICESECUNDARIO_H
#define INDICESECUNDARIO_H


class IndiceSecundario
{
private:
    int codigo;
    IndiceSecundario* next;
    IndiceSecundario* nextPrograma;
public:
    IndiceSecundario();
    IndiceSecundario(const IndiceSecundario &i);
    IndiceSecundario *getNext() const;
    void setNext(IndiceSecundario *value);
    IndiceSecundario *getNextPrograma() const;
    void setNextPrograma(IndiceSecundario *value);
    int getCodigo() const;
    void setCodigo(int value);

    IndiceSecundario &operator = (const IndiceSecundario&i);

};

#endif // INDICESECUNDARIO_H
