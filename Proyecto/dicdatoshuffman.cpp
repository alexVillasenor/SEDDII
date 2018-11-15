#include "dicdatoshuffman.h"

std::string DicDatosHuffman::getCaracter() const
{
    return caracter;
}

void DicDatosHuffman::setCaracter(const std::string &value)
{
    caracter = value;
}

std::string DicDatosHuffman::getCodigo() const
{
    return codigo;
}

void DicDatosHuffman::setCodigo(const std::string &value)
{
    codigo = value;
}

std::string DicDatosHuffman::toString()
{
    std::string result;
    result+="[";
    if(caracter=="\n"){
        result+="endl";
    }
    else{
        result+=caracter;
    }
    result+="   ";
    result+=codigo;
    result+="]";
    return result;
}

DicDatosHuffman::DicDatosHuffman()
{

}
