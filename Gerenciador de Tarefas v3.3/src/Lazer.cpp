#include "Lazer.h"

namespace TaTipos{

Lazer::Lazer(){
    tipo = 2;
}

Lazer::Lazer(int tipo) : Tarefa(tipo)
{
   // caracteristica = "Lazer";
}

Lazer::Lazer(std::string titulo, std::string caracteristica, std::string ambiente, std::string endereco, std::string valor, std::string descricao, Data data){
    this->titulo = titulo;
    this->caracteristica = caracteristica;
    this->ambiente = ambiente;
    this->endereco = endereco;
    this->valor = valor;
    this->descricao = descricao;
    this->data = data;
}

std::string Lazer::getAmbiente(){
    return ambiente;
}

std::string Lazer::getEndereco(){
    return endereco;
}

std::string Lazer::getValor(){
    return valor;
}

void Lazer::setAmbiente(std::string am){
    ambiente = am;
}

void Lazer::setEndereco(std::string en){
    endereco = en;
}

void Lazer::setValor(std::string v){
    valor = v;
}

void Lazer::Exibe(){
    Tarefa::Exibe();

    cout << "Local: ";
    cout << ambiente << endl;
    cout << "Endereco: ";
    cout << endereco << endl;
    cout << "Tipo de pagamento: ";
    cout << valor << endl;
    cout << "\n------------------------------------------\n" << endl;
}

void Lazer::lerAtributos(ifstream &obj){
    string separa2;

    Tarefa::lerAtributos(obj);

    getline(obj, ambiente);
    getline(obj, endereco);
    getline(obj, valor);
    getline(obj, separa2);
}

}
