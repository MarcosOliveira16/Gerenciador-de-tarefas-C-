#include "Gerenciador.h"

int ordena = 0;

Gerenciador::Gerenciador()
{
    //ctor
}

//      FUNÇÕES AUXILIARES  (5)    //

int Gerenciador::Buscar(string t, TiposTf tipo) {
    int i;

    for (i = 0; i < TarefaSize(tipo); i++) {
        if (t == TipoVector(tipo)[i]->getTitulo()) {
            return i;
        }
    }
    return -1;
}

bool Gerenciador::VerString(string s){
    int cont = 0;

    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i]) == 0 && isdigit(s[i]) == 0){
            cont++;
        }
    }

    if(s.size() == cont){
        return false;
    }

    return true;
}

void Gerenciador::DetalheTarefa(int indice, TiposTf tipo){
    TipoVector(tipo)[indice]->Exibe();
}

int Gerenciador::TarefaSize(TiposTf tipo){
    if(tipo == EDUCACAO){
        return Educacao.size();
    }else if(tipo == LAZER){
        return Lazer.size();
    }else if(tipo == ESPORTE){
        return Esporte.size();
    }else if(tipo == COMEMORATIVA){
        return Comemorativa.size();
    }
}

vector<Tarefa*>& Gerenciador::TipoVector(TiposTf tipo){
    if(tipo == EDUCACAO){
        return Educacao;
    }else if(tipo == LAZER){
        return Lazer;
    }else if(tipo == ESPORTE){
        return Esporte;
    }else if(tipo == COMEMORATIVA){
        return Comemorativa;
    }
}

//      FUNÇÕES PRINCIPAIS  (9)     //

void Gerenciador::CadastraTarefas(TiposTf tipo) {
    int pDesc;
    string AuxData;
    Data data;
    int verifica;
    int t;

    cout << "\n - Você realmente deseja cadastrar uma tarefa? [1]Sim ou [0]Nao: ";

    cin >> verifica;

    if(verifica == 0){
        cout << "\n - Retornando para o menu." << endl;
        getchar();
        return;
    }

    switch(tipo){
        case EDUCACAO:
            TipoVector(tipo).push_back(new TaTipos::Educacao());
            t = 1;
            break;
        case LAZER:
            TipoVector(tipo).push_back(new TaTipos::Lazer());
            t = 2;
            break;
        case ESPORTE:
            TipoVector(tipo).push_back(new TaTipos::Esporte());
            t = 3;
            break;
        case COMEMORATIVA:
            TipoVector(tipo).push_back(new TaTipos::Comemorativa());
            t = 4;
            break;
    }

    cout << "\n* ------ Criando tarefa ------ *\n" << endl;
    cout << "Crie a tarefa #" << TarefaSize(tipo) << ": " << endl;
    cout << "Titulo da tarefa: ";
    cin.ignore();
    string titulo;
    getline(cin, titulo);
    while(VerString(titulo) == false){
        cout << "\n - Sua tarefa está sem título, por favor adicione um título!\n" << endl;
        cout << "Titulo da tarefa: ";
        getline(cin, titulo);
    }
    TipoVector(tipo).back()->setTitulo(titulo);
    TipoVector(tipo).back()->setCarac(Tarefa::retornaTipo(t));
    cout << "Deseja adicionar uma descricao a tarefa criada?" << endl;
    cout << "[1]Sim ou [0]Nao: ";
    cin >> pDesc;
    string descricao;
    TipoVector(tipo).back()->setDescricao(descricao);
    if (pDesc == 1) {
        cin.ignore();
        cout << "Descricao da tarefa: ";
        getline(cin, descricao);
        TipoVector(tipo).back()->setDescricao(descricao);
    }else {
        descricao = "Sem descricao";
        TipoVector(tipo).back()->setDescricao(descricao);
    }
    int dia, mes, ano;
    bool valido = true;
    do{
        cout << "Digite agora a data limite para conclusao da tarefa (dia/mes/ano)." << endl;
        cout << "Dia: ";
        cin >> dia;
        data.setDia(dia);
        cout << "Mes: ";
        cin >> mes;
        data.setMes(mes);
        while(mes > 12 || mes < 1){
            cout << " - Mes invalido, digite novamente!" << endl;
            cout << "Mes: ";
            cin >> mes;
            data.setMes(mes);
        }
        cout << "Ano: ";
        cin >> ano;
        data.setAno(ano);
        TipoVector(tipo).back()->setData(data);
        AuxData = (ano < 1000 ? "0" + to_string(ano) : to_string(ano)) + "/" + (mes < 10 ? "0"
        + to_string(mes) : to_string(mes)) + "/" + (dia < 10 ? "0" + to_string(dia) : to_string(dia));
        if(dia <= data.DiasDoMes(mes) && dia > 0 && data.RetornaData() <= AuxData){
            valido = false;
        }else{
             cout << "\n - A data digitada é inválida, verifique se o dia digitado já não se passou.\n" <<
                    " - Por favor digite uma nova data!\n" << endl;
            continue;
        }
    }while(valido);

    string prof, disciplina, periodo, ambiente, endereco, valor, duracao, formato, objetivo, veiculo;
    string local, tipoComemoracao, atracao;
    int pValor, pVeiculo, quantPessoas;
    cin.ignore();

    switch(tipo){
        case EDUCACAO:
            cout << "Disciplina: ";
            getline(cin, disciplina);
            ((TaTipos::Educacao*)TipoVector(tipo).back())->setDisciplina(disciplina);
            cout << "Professor: ";
            getline(cin, prof);
            ((TaTipos::Educacao*)TipoVector(tipo).back())->setProf(prof);
            cout << "Período: ";
            getline(cin , periodo);
            ((TaTipos::Educacao*)TipoVector(tipo).back())->setPeriodo(periodo);
            break;
        case LAZER:
            cout << "Local: ";
            getline(cin, ambiente);
            ((TaTipos::Lazer*)TipoVector(tipo).back())->setAmbiente(ambiente);
            cout << "Endereco: ";
            getline(cin, endereco);
            ((TaTipos::Lazer*)TipoVector(tipo).back())->setEndereco(endereco);
            cout << "A atividade possui algum gasto(R$)?" << endl;
            cout << "[1]Sim ou [0]Não: ";
            cin >> pValor;
            cin.ignore();
            if(pValor == 1){
                cout << "Tipo de pagamento: ";
                getline(cin, valor);
                ((TaTipos::Lazer*)TipoVector(tipo).back())->setValor(valor);
                }else{
                    valor = "Não é uma atividade paga.";
                    ((TaTipos::Lazer*)TipoVector(tipo).back())->setValor(valor);
                }
            break;
        case ESPORTE:
            cout << "Duração: ";
            getline(cin, duracao);
            ((TaTipos::Esporte*)TipoVector(tipo).back())->setDuracao(duracao);
            cout << "Local: ";
            getline(cin, ambiente);
            ((TaTipos::Esporte*)TipoVector(tipo).back())->setAmbiente(ambiente);
            cout << "O esporte necessita de algum veículo?" << endl;
            cout << "[1]Sim ou [0]Não: ";
            cin >> pVeiculo;
            cin.ignore();
            if(pVeiculo == 1){
                cout << "Veiculo: ";
                getline(cin, veiculo);
                ((TaTipos::Esporte*)TipoVector(tipo).back())->setVeiculo(veiculo);
            }else{
                veiculo = "Não é necessário veículos para praticar esse esporte.";
                ((TaTipos::Esporte*)TipoVector(tipo).back())->setVeiculo(veiculo);
            }
            cout << "Formato (individual ou em equipe): ";
            getline(cin , formato);
            ((TaTipos::Esporte*)TipoVector(tipo).back())->setFormato(formato);
            cout << "Objetivo: ";
            getline(cin , objetivo);
            ((TaTipos::Esporte*)TipoVector(tipo).back())->setObjetivo(objetivo);
            cout << "Quantidade de participantes: ";
            cin >> quantPessoas;
            ((TaTipos::Esporte*)TipoVector(tipo).back())->setQuantPessoas(quantPessoas);
            cin.ignore();
            break;
        case COMEMORATIVA:
            cout << "Duração: ";
            getline(cin, duracao);
            ((TaTipos::Comemorativa*)TipoVector(tipo).back())->setDuracao(duracao);
            cout << "Local: ";
            getline(cin, local);
            ((TaTipos::Comemorativa*)TipoVector(tipo).back())->setLocal(local);
            cout << "Endereço: ";
            getline(cin, endereco);
            ((TaTipos::Comemorativa*)TipoVector(tipo).back())->setEndereco(endereco);
            cout << "Atração: ";
            getline(cin, atracao);
            ((TaTipos::Comemorativa*)TipoVector(tipo).back())->setAtracao(atracao);
            cout << "Tipo de evento: ";
            getline(cin, tipoComemoracao);
            ((TaTipos::Comemorativa*)TipoVector(tipo).back())->setTipoComemoracao(tipoComemoracao);
            cout << "Quantidade de convidados: ";
            cin >> quantPessoas;
            ((TaTipos::Comemorativa*)TipoVector(tipo).back())->setQuantConvidados(quantPessoas);
            cin.ignore();
            break;
    }
    cout << "\n - Tarefa cadastrada com sucesso." << endl;
}

void Gerenciador::EditarTarefas(TiposTf tipo) {
    string titulo, AuxData;
    Data data;
    int i, pDesc;

    if(TipoVector(tipo).size() > 0){
        cout << "\n Digite o titulo da tarefa que deseja editar: ";
        getline(cin, titulo);

        i = Buscar(titulo, tipo);

        if(i < 0) {
            cout << "\n - Tarefa nao encontrada!" << endl;
            return;
        }

        int verifica;

        cout << "\n - Você realmente deseja editar está tarefa? " << endl;

        DetalheTarefa(i, tipo);

        cout << "[1]Sim ou [0]Nao: ";
        cin >> verifica;

        if(verifica == 1){
            if(tipo == TipoVector(tipo)[i]->getTipo()){
                cin.ignore();
                cout << "Titulo da tarefa: ";
                string titulo;
                getline(cin, titulo);
                while(VerString(titulo) == false){
                    cout << "\n - Sua tarefa está sem título, por favor adicione um título!\n" << endl;
                    cout << "Titulo da tarefa: ";
                    getline(cin, titulo);
                }
                TipoVector(tipo)[i]->setTitulo(titulo);
                cout << "Deseja adicionar uma descricao a tarefa criada?" << endl;
                cout << "[1]Sim ou [0]Nao: ";
                cin >> pDesc;
                string descricao;
                TipoVector(tipo)[i]->setDescricao(descricao);
                if (pDesc == 1) {
                    cin.ignore();
                    cout << "Descricao da tarefa: ";
                    getline(cin, descricao);
                    TipoVector(tipo)[i]->setDescricao(descricao);
                }
                else {
                    descricao = "Sem descricao";
                    TipoVector(tipo)[i]->setDescricao(descricao);
                }
                int dia, mes, ano;
                bool valido = true;
                do{
                    cout << "Digite agora a data limite para conclusao da tarefa (dia/mes/ano)." << endl;
                    cout << "Dia: ";
                    cin >> dia;
                    data.setDia(dia);
                    cout << "Mes: ";
                    cin >> mes;
                    data.setMes(mes);
                    while(mes > 12 || mes < 1){
                        cout << " - Mes invalido, digite novamente!" << endl;
                        cout << "Mes: ";
                        cin >> mes;
                        data.setMes(mes);
                    }
                    cout << "Ano: ";
                    cin >> ano;
                    data.setAno(ano);
                    TipoVector(tipo)[i]->setData(data);
                    AuxData = (ano < 1000 ? "0" + to_string(ano) : to_string(ano)) + "/" + (mes < 10 ? "0"
                    + to_string(mes) : to_string(mes)) + "/" + (dia < 10 ? "0" + to_string(dia) : to_string(dia));
                    if(dia <= data.DiasDoMes(mes) && dia > 0 && data.RetornaData() <= AuxData){
                        valido = false;
                    }else{
                        cout << "\n - A data digitada é inválida, verifique se o dia digitado já não se passou.\n" <<
                        " - Por favor digite uma nova data!\n\n" << endl;
                        continue;
                    }
                }while(valido);

                string prof, disciplina, periodo, ambiente, endereco, valor, duracao, formato, objetivo, veiculo;
                string local, atracao, tipoComemoracao;
                int pValor, pVeiculo, quantPessoas;
                cin.ignore();

                switch(TipoVector(tipo)[i]->getTipo()){
                    case 1:
                        cout << "Disciplina: ";
                        getline(cin, disciplina);
                        ((TaTipos::Educacao*)TipoVector(tipo)[i])->setDisciplina(disciplina);
                        cout << "Professor: ";
                        getline(cin, prof);
                        ((TaTipos::Educacao*)TipoVector(tipo)[i])->setProf(prof);
                        cout << "Período: ";
                        getline(cin , periodo);
                        ((TaTipos::Educacao*)TipoVector(tipo)[i])->setPeriodo(periodo);
                        cout << "\n - Tarefa editada com sucesso." << endl;
                        break;
                    case 2:
                        cout << "Local: ";
                        getline(cin, ambiente);
                        ((TaTipos::Lazer*)TipoVector(tipo)[i])->setAmbiente(ambiente);
                        cout << "Endereco: ";
                        getline(cin, endereco);
                        ((TaTipos::Lazer*)TipoVector(tipo)[i])->setEndereco(endereco);
                        cout << "A atividade possui algum gasto(R$)?" << endl;
                        cout << "[1]Sim ou [0]Não: ";
                        cin >> pValor;
                        cin.ignore();
                        if(pValor == 1){
                            cout << "Tipo de pagamento: ";
                            getline(cin, valor);
                            ((TaTipos::Lazer*)TipoVector(tipo)[i])->setValor(valor);
                            }else{
                                valor = "Não é uma atividade paga.";
                                ((TaTipos::Lazer*)TipoVector(tipo)[i])->setValor(valor);
                            }
                            cout << "\n - Tarefa editada com sucesso." << endl;
                        break;
                    case 3:
                        cout << "Duração: ";
                        getline(cin, duracao);
                        ((TaTipos::Esporte*)TipoVector(tipo)[i])->setDuracao(duracao);
                        cout << "Local: ";
                        getline(cin, ambiente);
                        ((TaTipos::Esporte*)TipoVector(tipo)[i])->setAmbiente(ambiente);
                        cout << "O esporte necessita de algum veículo?" << endl;
                        cout << "[1]Sim ou [0]Não: ";
                        cin >> pVeiculo;
                        cin.ignore();
                        if(pVeiculo == 1){
                            cout << "Veiculo: ";
                            getline(cin, veiculo);
                            ((TaTipos::Esporte*)TipoVector(tipo)[i])->setVeiculo(veiculo);
                        }else{
                            veiculo = "Não é necessário veículos para praticar esse esporte.";
                        }
                        cout << "Formato (individual ou em equipe): ";
                        getline(cin , formato);
                        ((TaTipos::Esporte*)TipoVector(tipo)[i])->setFormato(formato);
                        cout << "Objetivo: ";
                        getline(cin , objetivo);
                        ((TaTipos::Esporte*)TipoVector(tipo)[i])->setObjetivo(objetivo);
                        cout << "Quantidade de participantes: ";
                        cin >> quantPessoas;
                        ((TaTipos::Esporte*)TipoVector(tipo)[i])->setQuantPessoas(quantPessoas);
                        cin.ignore();
                        cout << "\n - Tarefa editada com sucesso." << endl;
                        break;
                    case 4:
                        cout << "Duração: ";
                        getline(cin, duracao);
                        ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->setDuracao(duracao);
                        cout << "Local: ";
                        getline(cin, local);
                        ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->setLocal(local);
                        cout << "Endereço: ";
                        getline(cin, endereco);
                        ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->setEndereco(endereco);
                        cout << "Atração: ";
                        getline(cin, atracao);
                        ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->setAtracao(atracao);
                        cout << "Tipo de evento: ";
                        getline(cin, tipoComemoracao);
                        ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->setTipoComemoracao(tipoComemoracao);
                        cout << "Quantidade de convidados: ";
                        cin >> quantPessoas;
                        ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->setQuantConvidados(quantPessoas);
                        cin.ignore();
                        break;
                }
            }else{
                cout << "\n - Ainda não foram criadas tarefas do tipo " << TipoVector(tipo)[i]->retornaTipo(tipo) << endl;
            }
        }else{
            cin.ignore();
            cout << "\n - Retornando ao menu." << endl;
        }
    }else{
        cout << "\n - Ainda não foram cadastradas tarefas desse tipo." << endl;
    }
}

bool ComparaData(Tarefa* t1, Tarefa* t2){
    if(t1->getData().getAno() == t2->getData().getAno()){
        if(t1->getData().getMes() == t2->getData().getMes()){
            if(t1->getData().getDia() < t2->getData().getDia()){
                ordena++;
                return true;
            }
        }else if(t1->getData().getMes() < t2->getData().getMes()){
            ordena++;
            return true;
        }
    }else if(t1->getData().getAno() < t2->getData().getAno()){
        ordena++;
        return true;
    }

    return false;
}

#include <algorithm>

void Gerenciador::OrdenaTarefas(TiposTf tipo) {
    int i;

    if(TarefaSize(tipo) == 0){
        cout << "\n - Ainda não foi cadastrada nenhuma tarefa para que seja possível ordenar." << endl;
    }else if(TarefaSize(tipo) > 1){
        ordena = 0;
        sort(TipoVector(tipo).begin(), TipoVector(tipo).end(), ComparaData);
        if(ordena >= 1){
            cout << "\n - Ordenado." << endl;
        }else{
            cout << "\n - A lista já está ordenada." << endl;
        }
    }
}

void Gerenciador::ExibeTarefas(TiposTf tipo){
    int i = 0;

    if(TipoVector(tipo).empty()){
        cout << "\n - Ainda não foram cadastradas tarefas." << endl;
        return;
    }

    for(i = 0; i < TarefaSize(tipo); i++){
        TipoVector(tipo)[i]->Exibe();
    }
}

void Gerenciador::ApagarTarefas(TiposTf tipo){
    int verfifica;

    if(TarefaSize(tipo) > 0 ){
        cout << "\n - Indique o índice da tarefa que você deseja apagar: ";
        int apagar;
        cin >> apagar;
        if(apagar <= TarefaSize(tipo)){
            DetalheTarefa(apagar - 1, tipo);
            cout << " - Você realmente desejar apagar essa tarefa? ";
            cout << "[1]Sim ou [0]Não: ";
            cin >> verfifica;
            if(verfifica == 1){
                delete TipoVector(tipo)[apagar - 1];
                TipoVector(tipo).erase(TipoVector(tipo).begin() + (apagar - 1));
                cout << "\n - Tarefa apagada com sucesso." << endl;
                getchar();
            }else{
                cout << "\n - Retornando ao menu." << endl;
                getchar();
                return;
            }
        }else{
            cout << "\n - A tarefa digitada não existe." << endl;
            getchar();
            return;
        }
    }else{
        cout << "\n - Ainda não existe nenhuma tarefa." << endl;
        return;
    }
}

void Gerenciador::ApagarTudo(TiposTf tipo){
    if(TipoVector(tipo).empty()){
        cout << "\n - A lista de tarefas já está vazia." << endl;
        return;
    }

    int verifica;

    cout << "\n - Você realmente deseja apagar todas as tarefas? [1]Sim ou [0]Não: ";

    cin >> verifica;

    if(verifica == 0){
        getchar();
        cout << "\n - Retornando ao menu." << endl;
        return;
    }

    cout << "\n - Você acionou o comando de apagar todas as tarefas." << endl;
    for(int i = 0; i < TarefaSize(tipo); i++){
        delete TipoVector(tipo)[i];
    }
    getchar();
    TipoVector(tipo).clear();
    cout << "\n - Apagado com sucesso!" << endl;
}

void Gerenciador::SalvarListaDeTarefas(TiposTf tipo)
{
    string nomeDaLista;
    ofstream output;

    int verifica;

    if(TipoVector(tipo).empty()){
        cout << "\n - Não há nenhuma tarefa cadastrada para que seja possivel salvá-la em uma lista." << endl;
    }else{
        cout << endl;
        for(int i = 0; i < TarefaSize(tipo); i++){
            TipoVector(tipo)[i]->Exibe();
        }

        cout << "\n - Você realmente deseja salvar em um arquivo as tarefas existentes? [1]Sim ou [0]Não: ";
        cin >> verifica;

        if(verifica == 1){
            cin.ignore();
            cout << "\n - Qual nome você deseja atribuir a sua lista? ";
            getline(cin, nomeDaLista);
            nomeDaLista += ".txt";
            output.open(nomeDaLista, ios::app);
            if(!output.is_open()){
                cout << "\n - Error ao abrir arquivo." << endl;
                return;
            }
            int i;
            int tamanho = TarefaSize(tipo);
            string separa1;

            separa1 = "====================================================";

            for(i = 0; i < tamanho; i++){
                output << separa1 << endl;
                output << "Titulo: ";
                output << TipoVector(tipo)[i]->getTitulo() << endl;
                output << "Característica: ";
                output << TipoVector(tipo)[i]->getCarac() << endl;
                output << "Descricao: ";
                output << TipoVector(tipo)[i]->getDescricao() << endl;
                output << "Dia/Mes/Ano: ";
                output << setfill('0') << setw(2) << TipoVector(tipo)[i]->getData().getDia() << "/" << setfill('0') << setw(2)<< TipoVector(tipo)[i]->getData().getMes()
                << "/" << TipoVector(tipo)[i]->getData().getAno() << endl;

                switch(tipo){
                    case EDUCACAO:
                        output << "Disciplina: ";
                        output << ((TaTipos::Educacao*)TipoVector(tipo)[i])->getDisciplina() << endl;
                        output << "Professor: ";
                        output << ((TaTipos::Educacao*)TipoVector(tipo)[i])->getProf() << endl;
                        output << "Período: ";
                        output << ((TaTipos::Educacao*)TipoVector(tipo)[i])->getPeriodo() << endl;
                        output << separa1 << endl;

                        break;
                    case LAZER:
                        output << "Local: ";
                        output << ((TaTipos::Lazer*)TipoVector(tipo)[i])->getAmbiente() << endl;
                        output << "Endereco: ";
                        output << ((TaTipos::Lazer*)TipoVector(tipo)[i])->getEndereco() << endl;
                        output << "Tipo de pagamento: ";
                        output << ((TaTipos::Lazer*)TipoVector(tipo)[i])->getValor() << endl;
                        output << separa1 << endl;

                        break;
                    case ESPORTE:
                        output << "Duração: ";
                        output << ((TaTipos::Esporte*)TipoVector(tipo)[i])->getDuracao() << endl;
                        output << "Local: ";
                        output << ((TaTipos::Esporte*)TipoVector(tipo)[i])->getAmbiente() << endl;
                        output << "Veiculo: ";
                        output << ((TaTipos::Esporte*)TipoVector(tipo)[i])->getVeiculo() << endl;
                        output << "Formato (individual ou em equipe): ";
                        output << ((TaTipos::Esporte*)TipoVector(tipo)[i])->getFormato() << endl;
                        output << "Objetivo: ";
                        output << ((TaTipos::Esporte*)TipoVector(tipo)[i])->getObjetivo() << endl;
                        output << "Quantidade de participantes: ";
                        output << ((TaTipos::Esporte*)TipoVector(tipo)[i])->getQuantPessoas() << endl;
                        output << separa1 << endl;

                        break;
                    case COMEMORATIVA:
                        output << "Duração: ";
                        output << ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->getDuracao() << endl;
                        output << "Local: ";
                        output << ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->getLocal() << endl;
                        output << "Endereço: ";
                        output << ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->getEndereco() << endl;
                        output << "Atração: ";
                        output << ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->getAtracao() << endl;
                        output << "Tipo de evento: ";
                        output << ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->getTipoComemoracao() << endl;
                        output << "Quantidade de convidados: ";
                        output << ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->getQuantConvidados() << endl;
                        output << separa1 << endl;

                        break;
                }
            }

            cout << "\n - Lista salva com sucesso." << endl;
            output.close();
        }else{
            cout << "\n - Retornando ao menu." << endl;
            getchar();
        }
    }
}

void Gerenciador::SalvarImport(TiposTf tipo)
{
    string nomeDaLista;
    ofstream output;

    int verifica;

    if(TipoVector(tipo).empty()){
        cout << "\n - Não há nenhuma tarefa cadastrada para que seja possivel salvá-la em uma arquivo para exportação." << endl;
    }else{
        cout << endl;
        for(int i = 0; i < TarefaSize(tipo); i++){
            TipoVector(tipo)[i]->Exibe();
        }

        cout << "\n - Você realmente deseja salvar em um arquivo para exportação as tarefas existentes? [1]Sim ou [0]Não: ";
        cin >> verifica;

        if(verifica == 1){
            cin.ignore();
            cout << "\n - Qual nome você deseja atribuir a sua lista? ";
            getline(cin, nomeDaLista);
            nomeDaLista += " import.txt";
            output.open(nomeDaLista, ios::app);
            if(!output.is_open()){
                cout << "\n - Error ao abrir arquivo." << endl;
                return;
            }
            int i;
            int tamanho = TarefaSize(tipo);
            string separa1;

            separa1 = "====================================================";

            for(i = 0; i < tamanho; i++){
                output << separa1 << endl;
                output << TipoVector(tipo)[i]->getTipo() << endl;
                output << TipoVector(tipo)[i]->getTitulo() << endl;
                output << TipoVector(tipo)[i]->getCarac() << endl;
                output << TipoVector(tipo)[i]->getDescricao() << endl;
                output << setfill('0') << setw(2) << TipoVector(tipo)[i]->getData().getDia() << "/" << setfill('0') << setw(2) << TipoVector(tipo)[i]->getData().getMes()
                << "/" << TipoVector(tipo)[i]->getData().getAno() << endl;

                switch(tipo){
                    case 1:
                        output << ((TaTipos::Educacao*)TipoVector(tipo)[i])->getDisciplina() << endl;
                        output << ((TaTipos::Educacao*)TipoVector(tipo)[i])->getProf() << endl;
                        output << ((TaTipos::Educacao*)TipoVector(tipo)[i])->getPeriodo() << endl;
                        output << separa1 << endl;

                        break;
                    case 2:
                        output << ((TaTipos::Lazer*)TipoVector(tipo)[i])->getAmbiente() << endl;
                        output << ((TaTipos::Lazer*)TipoVector(tipo)[i])->getEndereco() << endl;
                        output << ((TaTipos::Lazer*)TipoVector(tipo)[i])->getValor() << endl;
                        output << separa1 << endl;

                        break;
                    case 3:
                        output << ((TaTipos::Esporte*)TipoVector(tipo)[i])->getDuracao() << endl;
                        output << ((TaTipos::Esporte*)TipoVector(tipo)[i])->getAmbiente() << endl;
                        output << ((TaTipos::Esporte*)TipoVector(tipo)[i])->getVeiculo() << endl;
                        output << ((TaTipos::Esporte*)TipoVector(tipo)[i])->getFormato() << endl;
                        output << ((TaTipos::Esporte*)TipoVector(tipo)[i])->getObjetivo() << endl;
                        output << ((TaTipos::Esporte*)TipoVector(tipo)[i])->getQuantPessoas() << endl;
                        output << separa1 << endl;

                        break;
                    case 4:
                        output << ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->getDuracao() << endl;
                        output << ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->getLocal() << endl;
                        output << ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->getEndereco() << endl;
                        output << ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->getAtracao() << endl;
                        output << ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->getTipoComemoracao() << endl;
                        output << ((TaTipos::Comemorativa*)TipoVector(tipo)[i])->getQuantConvidados() << endl;
                        output << separa1 << endl;

                        break;
                }
            }

            cout << "\n - Lista para exportação salva com sucesso." << endl;
            output.close();
        }else{
            cout << "\n - Retornando ao menu." << endl;
            getchar();
        }
    }
}

void Gerenciador::ImportarLista(TiposTf tipo){
    string buscar;
    ifstream lerLista;
    vector<string> aux;
    Tarefa* tf;
    int contador = 0, add = 0;

    cout << "\n - Digite o nome da lista que você deseja importar: ";
    getline(cin, buscar);
    buscar += ".txt";

    lerLista.open(buscar, ios::in);
    if(!lerLista.is_open()){
        cout << "\n - Error ao importar arquivo." << endl;
        return;
    }

    string linha;

    // exibindo o conteúdo do arquivo de importação
    cout << endl;
    while(getline(lerLista, linha)){
        cout << linha << endl;
        aux.push_back(linha);
        if(linha == "1" || linha == "2" || linha == "3" || linha == "4"){
            contador++;
        }
    }

    lerLista.close();

    int verifica;

    cout << "\n - Você realmente deseja importar esse arquivo? [1]Sim ou [0]Não: ";
    cin >> verifica;
    if(verifica == 1){
        lerLista.open(buscar, ios::in);
        if(!lerLista.is_open()){
            cout << "\n - Error ao importar arquivo." << endl;
            return;
        }
        while(add < contador){
            int i = 1;
            switch(tipo){
                case EDUCACAO:
                    if(aux[i] == "1"){
                        tf = new TaTipos::Educacao();
                        ((TaTipos::Educacao*)tf)->lerAtributos(lerLista);
                        i += 10;
                    }
                    break;
                case LAZER:
                    if(aux[i] == "2"){
                        tf = new TaTipos::Lazer();
                        ((TaTipos::Lazer*)tf)->lerAtributos(lerLista);
                        i += 10;
                    }else{
                        cout << "\n - O arquivo selecionado não é correspondente para a importação." << endl;
                        return;
                    }
                    break;
                case ESPORTE:
                    if(aux[i] == "3"){
                        tf = new TaTipos::Esporte();
                        ((TaTipos::Esporte*)tf)->lerAtributos(lerLista);
                        i += 13;
                    }else{
                        cout << "\n - O arquivo selecionado não é correspondente para a importação." << endl;
                        return;
                    }
                    break;
                case COMEMORATIVA:
                    if(aux[i] == "4"){
                        tf = new TaTipos::Comemorativa();
                        ((TaTipos::Comemorativa*)tf)->lerAtributos(lerLista);
                        i += 13;
                    }else{
                        cout << "\n - O arquivo selecionado não é correspondente para a importação." << endl;
                        return;
                    }
                    break;
            }
            add++;
            TipoVector(tipo).push_back(tf);
        }

        cin.ignore();
        cout << "\n - Lista importada com sucesso." << endl;
        lerLista.close();
    }else{
        cout << "\n - Retornando ao menu." << endl;
        getchar();
    }
}
