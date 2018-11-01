#ifndef INDICE_H
#define INDICE_H


class Indice
{
private:
    int codigo;
    long int direccion;
public:
    Indice();
    int getCodigo() const;
    void setCodigo(int value);
    long getDireccion() const;
    void setDireccion(long value);

    Indice& operator = (const Indice&);


    bool operator ==(const Indice&);
    bool operator !=(const Indice&);
    bool operator <=(const Indice&);
    bool operator <(const Indice&);
    bool operator >=(const Indice&);
    bool operator >(const Indice&);
};

#endif // INDICE_H
