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
    return "\n - Erro! \'" + std::to_string(tipo) + "\' N�o � uma op��o v�lida, por favor verifique as op��es dispon�veis e digite novamente.\n";

}
