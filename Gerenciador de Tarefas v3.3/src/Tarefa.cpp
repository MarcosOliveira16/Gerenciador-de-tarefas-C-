#include "Tarefa.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Tarefa::Tarefa()
{
    titulo = "";
    descricao = "";
    caracteristica = "";
    tipo = 0;
}

Tarefa::Tarefa(int tipo)
{
    switch(tipo){
        case 1:
            caracteristica = "Educacao";
            break;
        case 2:
            caracteristica = "Lazer";
            break;
        case 3:
            caracteristica = "Esporte";
            break;
    }
}

Tarefa::Tarefa(string titulo, string descricao, string caracteristica, Data data){
    this->titulo = titulo;
    this->descricao = descricao;
    this->caracteristica = caracteristica;
    this->data = data;
}

string Tarefa::getTitulo(){
    return titulo;
}

string Tarefa::getDescricao(){
    return descricao;
}

string Tarefa::getCarac(){
    return caracteristica;
}

int Tarefa::getTipo(){
    return tipo;
}

Data Tarefa::getData(){
    return data;
}

void Tarefa::setTitulo(string t){
    titulo = t;
}

void Tarefa::setDescricao(string d){
    descricao = d;
}

void Tarefa::setCarac(string c){
    caracteristica = c;
}

void Tarefa::setTipo(int t){
    tipo = t;
}

void Tarefa::setData(Data d){
    data = d;
}

string Tarefa::retornaTipo(int t){
    switch(t){
        case 1:
            return "Educação";
        case 2:
            return "Lazer";
        case 3:
            return "Esporte";
        case 4:
            return "Comemorativa";
    }
}

void Tarefa::Exibe(){
    cout << "------------------------------------------\n" << endl;
    cout << "Titulo: ";
    cout << titulo << endl;
    cout << "Característica: ";
    cout << caracteristica << endl;
    cout << "Descricao: ";
    cout << descricao << endl;
    cout << "Data limite do evento: ";
    cout << setfill('0') << setw(2) << data.getDia() << "/" << setfill('0')
    << setw(2) << data.getMes() << "/" << data.getAno() << endl;
}

void Tarefa::lerAtributos(ifstream &obj){
    string separa;
    int d, m, a;

    getline(obj, separa);
    obj >> tipo;
    obj.ignore();
    getline(obj, titulo);
    getline(obj, caracteristica);
    getline(obj, descricao);
    obj >> d;
    obj.ignore();
    obj >> m;
    obj.ignore();
    obj >> a;
    obj.ignore();

    data.setDia(d);
    data.setMes(m);
    data.setAno(a);
}
