#ifndef LAZER_H
#define LAZER_H

#include "Tarefa.h"
#include <vector>
#include <string>
#include <fstream>

namespace TaTipos{

class Lazer :   public Tarefa
{
    public:
        Lazer();
        Lazer(int tipo);
        Lazer(std::string titulo, std::string caracteristica, std::string ambiente,
              std::string endereco, std::string valor, std::string descricao, Data data);

        // getters
        std::string getAmbiente();
        std::string getEndereco();
        std::string getValor();

        // setters
        void setAmbiente(std::string am);
        void setEndereco(std::string en);
        void setValor(std::string v);

        void Exibe();
        void lerAtributos(ifstream &obj);

    private:
        std::string ambiente, endereco;
        std::string valor;
};

}

#endif // LAZER_H
