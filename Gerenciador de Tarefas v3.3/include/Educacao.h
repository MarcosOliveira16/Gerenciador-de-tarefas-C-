#ifndef EDUCACAO_H
#define EDUCACAO_H

#include "Tarefa.h"
#include "vector"
#include <string>
#include <fstream>

namespace TaTipos{

class Educacao  :   public Tarefa
{
    public:
        Educacao();
        Educacao(int tipo);
        Educacao(std::string titulo, std::string caracteristica,
        std::string disciplina, std::string prof, std::string periodo, std::string descricao, Data data);

        // getters
        std::string getProf();
        std::string getPeriodo();
        std::string getDisciplina();

        // setters
        void setProf(std::string pf);
        void setPeriodo(std::string p);
        void setDisciplina(std::string d);

        void Exibe();
        void lerAtributos(std::ifstream &obj);

    private:
        std::string prof, disciplina, periodo;

};

}

#endif // EDUCACAO_H
