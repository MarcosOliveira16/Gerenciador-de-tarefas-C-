#ifndef TAREFA_H
#define TAREFA_H

#include <iostream>
#include <string>

#include "Data.h"
#include <vector>
#include <fstream>

using namespace std;

class Tarefa
{
    public:
        Tarefa();
        Tarefa(int tipo);
        Tarefa(string titulo, string descricao, string caracteristica, Data data);

        // getters
        string getTitulo();
        string getDescricao();
        string getCarac();
        int getTipo();
        Data getData();

        // setters
        void setTitulo(string t);
        void setDescricao(string d);
        void setCarac(string c);
        void setTipo(int t);
        void setData(Data d);

        // métodos
        static string retornaTipo(int t);
        virtual void Exibe() = 0;
        virtual void lerAtributos(ifstream &obj) = 0;


    protected:
        string titulo, descricao, caracteristica;
        Data data;
        int tipo;
};

#endif // TAREFA_H
