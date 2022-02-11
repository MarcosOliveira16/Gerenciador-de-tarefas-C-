#ifndef ESPORTE_H
#define ESPORTE_H

#include "Tarefa.h"
#include <vector>
#include <fstream>

namespace TaTipos{

class Esporte   :   public Tarefa
{
    public:
        Esporte();
        Esporte(int tipo);
        Esporte(std::string titulo, std::string caracteristica, std::string duracao, std::string ambiente, std::string veiculo,
        std::string formato, std::string objetivo, int quantPessoas, std::string descricao, Data data);

        // getters
        std::string getDuracao();
        std::string getAmbiente();
        std::string getVeiculo();
        std::string getFormato();
        std::string getObjetivo();
        int getQuantPessoas();

        // setters
        void setDuracao(std::string d);
        void setAmbiente(std::string am);
        void setVeiculo(std::string v);
        void setFormato(std::string f);
        void setObjetivo(std::string ob);
        void setQuantPessoas(int qp);

        void Exibe();
        void lerAtributos(ifstream &obj);

    private:
        std::string duracao, ambiente, veiculo, formato, objetivo; // formato: individual ou em equipe
        int quantPessoas; //
};

}

#endif // ESPORTE_H
