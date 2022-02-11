#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <exception>

#include "Tarefa.h"
#include "Educacao.h"
#include "Lazer.h"
#include "Esporte.h"
#include "Gerenciador.h"
#include "SwitchException.h"

Gerenciador gerenciador;

void Info();
void ExibeMenu();
void ExibeTipo(TiposTf tf);
void MenuTarefa(TiposTf tf);

using namespace std;
using namespace TaTipos;

int main(){
    setlocale(LC_ALL,"Portuguese");

    int tipo;
    TiposTf tf;

    do{
        Info();
        cout << "Digite: ";
        cin >> tipo;

        try{
            if(tipo > 10 || tipo < 1){
                throw SwitchException(tipo);
            }
        }catch(SwitchException e){
            cout << e.getMessenge();
        }

        switch(tipo){

            case 1:
                tf = EDUCACAO;
                ExibeTipo(tf);
                cout << "\n - Digite enter para continuar." << endl;
                getchar();
                getchar();
                system("cls");
                MenuTarefa(tf);
                break;

            case 2:
                tf = LAZER;
                ExibeTipo(tf);
                cout << "\n - Digite enter para continuar." << endl;
                getchar();
                getchar();
                system("cls");
                MenuTarefa(tf);
                break;

            case 3:
                tf = ESPORTE;
                ExibeTipo(tf);
                cout << "\n - Digite enter para continuar." << endl;
                getchar();
                getchar();
                system("cls");
                MenuTarefa(tf);
                break;

            case 4:
                tf = COMEMORATIVA;
                ExibeTipo(tf);
                cout << "\n - Digite enter para continuar." << endl;
                getchar();
                getchar();
                system("cls");
                MenuTarefa(tf);
                break;

            case 5:
                cout << "=============== Educação ================" << endl;
                gerenciador.ExibeTarefas(EDUCACAO);
                cout << "\n=========================================\n" << endl;
                cout << "================= Lazer =================" << endl;
                gerenciador.ExibeTarefas(LAZER);
                cout << "\n=========================================\n" << endl;
                cout << "================ Esportes ===============" << endl;
                gerenciador.ExibeTarefas(ESPORTE);
                cout << "\n=========================================\n" << endl;
                cout << "============= Comemorativa ==============" << endl;
                gerenciador.ExibeTarefas(COMEMORATIVA);
                cout << "\n=========================================\n" << endl;
                cout << "\n - Digite enter para continuar." << endl;
                getchar();
                getchar();
                system("cls");
                break;

            case 6:
                cout << "=============== Educação ================" << endl;
                gerenciador.ApagarTudo(EDUCACAO);
                cout << "\n=========================================\n" << endl;
                cout << "================= Lazer =================" << endl;
                gerenciador.ApagarTudo(LAZER);
                cout << "\n=========================================\n" << endl;
                cout << "================ Esportes ===============" << endl;
                gerenciador.ApagarTudo(ESPORTE);
                cout << "\n=========================================\n" << endl;
                cout << "============= Comemorativa ==============" << endl;
                gerenciador.ApagarTudo(COMEMORATIVA);
                cout << "\n=========================================\n" << endl;
                cout << "\n - Digite enter para continuar." << endl;
                getchar();
                getchar();
                system("cls");
                break;

            case 7:
                cout << "=============== Educação ================" << endl;
                gerenciador.SalvarListaDeTarefas(EDUCACAO);
                cout << "\n=========================================\n" << endl;
                cout << "================= Lazer =================" << endl;
                gerenciador.SalvarListaDeTarefas(LAZER);
                cout << "\n=========================================\n" << endl;
                cout << "================ Esportes ===============" << endl;
                gerenciador.SalvarListaDeTarefas(ESPORTE);
                cout << "\n=========================================\n" << endl;
                cout << "============= Comemorativa ==============" << endl;
                gerenciador.SalvarListaDeTarefas(COMEMORATIVA);
                cout << "\n=========================================\n" << endl;
                cout << "\n - Digite enter para continuar." << endl;
                getchar();
                getchar();
                system("cls");
                break;

            case 8:
                cout << "=============== Educação ================" << endl;
                gerenciador.SalvarImport(EDUCACAO);
                cout << "\n=========================================\n" << endl;
                cout << "================= Lazer =================" << endl;
                gerenciador.SalvarImport(LAZER);
                cout << "\n=========================================\n" << endl;
                cout << "================ Esportes ===============" << endl;
                gerenciador.SalvarImport(ESPORTE);
                cout << "\n=========================================\n" << endl;
                cout << "============= Comemorativa ==============" << endl;
                gerenciador.SalvarImport(COMEMORATIVA);
                cout << "\n=========================================\n" << endl;
                cout << "\n - Digite enter para continuar." << endl;
                getchar();
                getchar();
                system("cls");
                break;

            case 9:
                getchar();
                cout << "=============== Educação ================" << endl;
                gerenciador.ImportarLista(EDUCACAO);
                cout << "\n=========================================\n" << endl;
                cout << "================= Lazer =================" << endl;
                gerenciador.ImportarLista(LAZER);
                cout << "\n=========================================\n" << endl;
                cout << "================ Esportes ===============" << endl;
                gerenciador.ImportarLista(ESPORTE);
                cout << "\n=========================================\n" << endl;
                cout << "============= Comemorativa ==============" << endl;
                gerenciador.ImportarLista(COMEMORATIVA);
                cout << "\n=========================================\n" << endl;
                cout << "\n - Digite enter para continuar." << endl;
                getchar();
                getchar();
                system("cls");
                break;

            case 10:
                cout << "\n - O comando sair foi acionado. Obrigado por usar e volta sempre @.@ ." << endl;
                Sleep(2500);
                system("cls");
                break;

            default:
                cout << "\n - Digite enter para continuar." << endl;
                getchar();
                getchar();
                system("cls");
        }

    }while(tipo != 10);

    return 0;

}

void Info() {
    cout << "\n           * CRIADOR & ADMINISTRADOR DE TAREFAS *          \n";
    cout << "\n* -------------------- Informações -------------------- *\n"
         << "|                                                      |\n"
         << "|      * Escolha a característica da sua tarefa:       |\n"
         << "|         1) - Educação                                |\n"
         << "|         2) - Lazer                                   |\n"
         << "|         3) - Esporte                                 |\n"
         << "|         4) - Comemorativa                            |\n"
         << "|                                                      |\n"
         << "|      * Comando gerais:                               |\n"
         << "|         5) - Exibir todas as tarefas (global)        |\n"
         << "|         6) - Apagar todas as tarefas (global)        |\n"
         << "|         7) - Salvar em arquivos (global)             |\n"
         << "|         8) - Salvar para exportação (global)         |\n"
         << "|         9) - Importações de arquivos (global)        |\n"
         << "|         10) - Encerrar                               |\n"
         << "|                                                      |\n"
         << "* ----------------------------------------------------- *\n"
         << endl;
}

void ExibeMenu() {
    cout << "\n* ----------- Menu ------------ *\n"
         << "|      1 - Cadastrar tarefas   |\n"
         << "|      2 - Editar tarefas      |\n"
         << "|      3 - Ordena tarefas      |\n";
    cout << "|      4 - Exibe tarefas       |\n"
         << "|      5 - Apagar tarefa       |\n"
         << "|      6 - Apagar tudo         |\n"
         << "|      7 - Salvar lista        |\n"
         << "|      8 - Salvar p/exportação |\n"
         << "|      9 - Importar lista      |\n"
         << "|      10 - Tela inicial       |\n"
         << "* ----------------------------- *\n"
         << endl;
}

void ExibeTipo(TiposTf tf){
    if(tf == EDUCACAO){
        cout << "\n - Entrando em \'Educação\'!" << endl;
    }else if(tf == LAZER){
        cout << "\n - Entrando em \'Lazer\'!" << endl;
    }else if(tf == ESPORTE){
        cout << "\n - Entrando em \'Esporte\'!" << endl;
    }else{
        cout << "\n - Entrando em \'Comemorativa\'!" << endl;
    }
}

void MenuTarefa(TiposTf tf){
    int op;

    do{
        ExibeMenu();
        cout << "Digite o comando que deseja: ";
        cin >> op;
        cin.ignore();

        try{
            if(op > 10 || op < 1){
                throw SwitchException(op);
            }
        }catch(SwitchException e){
            cout << e.getMessenge();
        }

        switch(op){
            case 1:
                gerenciador.CadastraTarefas(tf);
                cout << "\n - Digite enter para continuar." << endl;
                break;
            case 2:
                gerenciador.EditarTarefas(tf);
                cout << "\n - Digite enter para continuar." << endl;
                break;
            case 3:
                gerenciador.OrdenaTarefas(tf);
                cout << "\n - Digite enter para continuar." << endl;
                break;
            case 4:
                gerenciador.ExibeTarefas(tf);
                cout << "\n - Digite enter para continuar." << endl;
                break;
            case 5:
                gerenciador.ApagarTarefas(tf);
                cout << "\n - Digite enter para continuar." << endl;
                break;
            case 6 :
                gerenciador.ApagarTudo(tf);
                cout << "\n - Digite enter para continuar." << endl;
                break;
            case 7:
                gerenciador.SalvarListaDeTarefas(tf);
                cout << "\n - Digite enter para continuar." << endl;
                break;
            case 8:
                gerenciador.SalvarImport(tf);
                cout << "\n - Digite enter para continuar." << endl;
                break;
            case 9:
                gerenciador.ImportarLista(tf);
                cout << "\n - Digite enter para continuar." << endl;
                break;
            case 10:
                cout << "\n - Voltando para tela inical.\n\n - Por favor aguarde..." << endl;
                Sleep(3000);
                system("cls");
                return;
            default:
                cout << "\n - Digite enter para continuar." << endl;
                break;
        }
        getchar();
        system("cls");
    }while(op != 10);

}
