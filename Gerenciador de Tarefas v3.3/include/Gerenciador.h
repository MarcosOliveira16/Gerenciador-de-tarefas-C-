#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include "Tarefa.h"
#include "Data.h"
#include "Educacao.h"
#include "Lazer.h"
#include "Esporte.h"
#include "Comemorativa.h"
#include <vector>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
#include <string>
#include <algorithm>

enum TiposTf{
    EDUCACAO = 1, LAZER = 2, ESPORTE = 3, COMEMORATIVA = 4
};

class Gerenciador
{
    public:
        Gerenciador();

        // métodos auxiliares
        int Buscar(string t, TiposTf tipo);
        bool VerString(string s);
        void DetalheTarefa(int indice, TiposTf tipo);
        int TarefaSize(TiposTf tipo);
        vector<Tarefa*>& TipoVector(TiposTf tipo);

        // métodos
        void CadastraTarefas(TiposTf tipo);
        void EditarTarefas(TiposTf tipo);
        void OrdenaTarefas(TiposTf tipo);
        void ExibeTarefas(TiposTf tipo);
        void ApagarTarefas(TiposTf tipo);
        void ApagarTudo(TiposTf tipo);
        void SalvarListaDeTarefas(TiposTf tipo);
        void SalvarImport(TiposTf tipo);
        void ImportarLista(TiposTf tipo);

    private:
        std::vector<Tarefa*> Educacao;
        std::vector<Tarefa*> Lazer;
        std::vector<Tarefa*> Esporte;
        std::vector<Tarefa*> Comemorativa;
};

#endif // GERENCIADOR_H
