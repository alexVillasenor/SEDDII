#ifndef DICDATOSHUFFMAN_H
#define DICDATOSHUFFMAN_H
#include <string>

class DicDatosHuffman
{
private:
    std::string caracter;
    std::string codigo;
public:
    DicDatosHuffman();
    std::string getCaracter() const;
    void setCaracter(const std::string &value);
    std::string getCodigo() const;
    void setCodigo(const std::string &value);
    std::string toString();
};

#endif // DICDATOSHUFFMAN_H
