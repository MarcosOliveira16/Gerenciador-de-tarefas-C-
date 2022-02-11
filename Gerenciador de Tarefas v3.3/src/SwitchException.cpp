#include "SwitchException.h"

SwitchException::SwitchException(int t)
{
    tipo = t;
}

SwitchException::~SwitchException()
{
    //dtor
}

std::string SwitchException::getMessenge(){
    return "\n - Erro! \'" + std::to_string(tipo) + "\' Não é uma opção válida, por favor verifique as opções disponíveis e digite novamente.\n";

}
