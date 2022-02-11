#include "Data.h"
#include <string>

using namespace std;

Data::Data()
{
    dia = 0;
    mes = 0;
    ano = 0;
}

int Data::DiasDoMes(int mes){
    switch(mes){
        case 1:
            return 31;
        case 2:
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }
}

std::string Data::RetornaData(){
    string d;

    chrono::system_clock::time_point data = chrono::system_clock::now();
    time_t tt = chrono::system_clock::to_time_t(data);

    tm utc_tm = *gmtime(&tt);
    tm local_tm = *localtime(&tt);

    int ano = (int)local_tm.tm_year + 1900;
    int mes = (int)local_tm.tm_mon + 1;
    int dia = (int)local_tm.tm_mday;

    d = to_string(ano) + "/" + (mes < 10 ? "0" + to_string(mes) : to_string(mes)) + "/" + (dia < 10 ? "0" + to_string(dia) : to_string(dia));

    return d;
}

void Data::setDia(int d){
    dia = d;
}

void Data::setMes(int m){
    mes = m;
}

void Data::setAno(int a){
    ano = a;
}

int Data::getDia(){
    return dia;
}

int Data::getMes(){
    return mes;
}

int Data::getAno(){
    return ano;
}
