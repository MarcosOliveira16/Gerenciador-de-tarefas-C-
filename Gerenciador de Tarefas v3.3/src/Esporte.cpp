#include "Esporte.h"

#include <iomanip>

namespace TaTipos{

Esporte::Esporte(){
    tipo = 3;
}

Esporte::Esporte(int tipo) : Tarefa(tipo)
{
  //  caracteristica = "Esporte";
}

Esporte::Esporte(std::string titulo, std::string caracteristica, std::string duracao, std::string ambiente, std::string veiculo,
std::string formato, std::string objetivo, int quantPessoas, std::string descricao, Data data)
{
    this->titulo = titulo;
    this->caracteristica = caracteristica;
    this->duracao = duracao;
    this->ambiente = ambiente;
    this->veiculo = veiculo;
    this->formato = formato;
    this->objetivo = objetivo;
    this->quantPessoas = quantPessoas;
    this->descricao = descricao;
    this->data = data;
}


std::string Esporte::getDuracao(){
    return duracao;
}

std::string Esporte::getAmbiente(){
    return ambiente;
}

std::string Esporte::getVeiculo(){
    return veiculo;
}

std::string Esporte::getFormato(){
    return formato;
}

std::string Esporte::getObjetivo(){
    return objetivo;
}

int Esporte::getQuantPessoas(){
    return quantPessoas;
}

void Esporte::setDuracao(std::string d){
    duracao = d;
}

void Esporte::setAmbiente(std::string am){
    ambiente = am;
}

void Esporte::setVeiculo(std::string v){
    veiculo = v;
}

void Esporte::setFormato(std::string f){
    formato = f;
}

void Esporte::setObjetivo(std::string ob){
    objetivo = ob;
}

void Esporte::setQuantPessoas(int qp){
    quantPessoas = qp;
}

void Esporte::Exibe(){
    Tarefa::Exibe();

    cout << "Duração: ";
    cout << duracao << endl;
    cout << "Local: ";
    cout << ambiente << endl;
    cout << "Veículo: ";
    cout << veiculo << endl;
    cout << "Formato: ";
    cout << formato << endl;
    cout << "Objetivo: ";
    cout << objetivo << endl;
    cout << "Parcipantes: ";
    cout << quantPessoas << endl;
    cout << "\n------------------------------------------\n" << endl;
}

void Esporte::lerAtributos(ifstream &obj){
    string separa2;

    Tarefa::lerAtributos(obj);

    getline(obj, duracao);
    getline(obj, ambiente);
    getline(obj, veiculo);
    getline(obj, formato);
    getline(obj, objetivo);
    obj >> quantPessoas;
    obj.ignore();
    getline(obj, separa2);
}

}
