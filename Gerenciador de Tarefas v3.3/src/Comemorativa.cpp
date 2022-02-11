#include "Comemorativa.h"

namespace TaTipos{

Comemorativa::Comemorativa()
{
    tipo = 4;
}
Comemorativa::Comemorativa(int tipo) : Tarefa(tipo)
{

}

Comemorativa::Comemorativa(std::string titulo, std::string caracteristica, std::string duracao, std::string local,
    std::string endereco, std::string atracao, std::string tipoComemoracao, int quantConvidados, std::string descricao, Data data)
{
    this->titulo = titulo;
    this->caracteristica = caracteristica;
    this->duracao = duracao;
    this->local = local;
    this->endereco = endereco;
    this->atracao = atracao;
    this->tipoComemoracao = tipoComemoracao;
    this->quantConvidados = quantConvidados;
    this->descricao = descricao;
    this->data = data;
}

std::string Comemorativa::getDuracao(){
    return duracao;
}

std::string Comemorativa::getLocal(){
    return local;
}

std::string Comemorativa::getEndereco(){
    return endereco;
}

std::string Comemorativa::getAtracao(){
    return atracao;
}

std::string Comemorativa::getTipoComemoracao(){
    return tipoComemoracao;
}

int Comemorativa::getQuantConvidados(){
    return quantConvidados;
}

// setters
void Comemorativa::setDuracao(std::string d){
    duracao = d;
}

void Comemorativa::setLocal(std::string l){
    local = l;
}

void Comemorativa::setEndereco(std::string en){
    endereco = en;
}

void Comemorativa::setAtracao(std::string a){
    atracao = a;
}

void Comemorativa::setTipoComemoracao(std::string tc){
    tipoComemoracao = tc;
}

void Comemorativa::setQuantConvidados(int qc){
    quantConvidados = qc;
}

// métodos
void Comemorativa::Exibe(){
    Tarefa::Exibe();

    cout << "Duração: ";
    cout << duracao << endl;
    cout << "Local: ";
    cout << local << endl;
    cout << "Endereço: ";
    cout << endereco << endl;
    cout << "Atração: ";
    cout << atracao << endl;
    cout << "Tipo de evento: ";
    cout << tipoComemoracao << endl;
    cout << "Quantidade de convidados: ";
    cout << quantConvidados << endl;
    cout << "\n------------------------------------------\n" << endl;
}

void Comemorativa::lerAtributos(ifstream &obj){
    string separa2;

    Tarefa::lerAtributos(obj);

    getline(obj, duracao);
    getline(obj, local);
    getline(obj, endereco);
    getline(obj, atracao);
    getline(obj, tipoComemoracao);
    obj >> quantConvidados;
    obj.ignore();
    getline(obj, separa2);
}

}
