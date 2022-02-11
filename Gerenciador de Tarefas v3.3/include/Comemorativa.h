#ifndef COMEMORATIVA_H
#define COMEMORATIVA_H

#include "Tarefa.h"

namespace TaTipos{

class Comemorativa : public Tarefa
{
    public:
        Comemorativa();
        Comemorativa(int tipo);
        Comemorativa(std::string titulo, std::string caracteristica, std::string duracao, std::string local,
        std::string endereco, std::string atracao, std::string tipoComemoracao, int quantConvidados, std::string descricao, Data data);

        // getters
        std::string getDuracao();
        std::string getLocal();
        std::string getEndereco();
        std::string getAtracao();
        std::string getTipoComemoracao();
        int getQuantConvidados();

        // setters
        void setDuracao(std::string d);
        void setLocal(std::string l);
        void setEndereco(std::string en);
        void setAtracao(std::string a);
        void setTipoComemoracao(std::string tc);
        void setQuantConvidados(int qc);

        // métodos
        void Exibe();
        void lerAtributos(ifstream &obj);


    private:
        std::string duracao, local, endereco, atracao, tipoComemoracao;
        int quantConvidados;
};

}
#endif // COMEMORATIVA_H
