#include "Educacao.h"

#include <iomanip>

namespace TaTipos{

Educacao::Educacao(){
    tipo = 1;
}

Educacao::Educacao(int tipo) : Tarefa(tipo)
{
   // caracteristica = "Educacao";
}

Educacao::Educacao(std::string titulo, std::string caracteristica, std::string disciplina, std::string prof, std::string periodo, std::string descricao, Data data){
    this->titulo = titulo;
    this->caracteristica = caracteristica;
    this->disciplina = disciplina;
    this->prof = prof;
    this->periodo = periodo;
    this->descricao = descricao;
    this->data = data;
}

std::string Educacao::getProf(){
    return prof;
}

std::string Educacao::getPeriodo(){
    return periodo;
}

std::string Educacao::getDisciplina(){
    return disciplina;
}

void Educacao::setProf(std::string pf){
    prof = pf;
}

void Educacao::setPeriodo(std::string p){
    periodo = p;
}

void Educacao::setDisciplina(std::string d){
    disciplina = d;
}

void Educacao::Exibe(){
    Tarefa::Exibe();

    cout << "Disciplina: ";
    cout << disciplina << endl;
    cout << "Professor: ";
    cout << prof << endl;
    cout << "Período: ";
    cout << periodo << endl;
    cout << "\n------------------------------------------\n" << endl;
}

void Educacao::lerAtributos(ifstream &obj){
    string separa2;

    Tarefa::lerAtributos(obj);

    getline(obj, disciplina);
    getline(obj, prof);
    getline(obj, periodo);
    getline(obj, separa2);
}

}
