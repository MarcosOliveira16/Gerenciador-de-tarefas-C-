#ifndef DATA_H
#define DATA_H

#include <string>
#include <chrono>

class Data
{
    public:
        Data();

        static int DiasDoMes(int mes);
        static std::string RetornaData();

        // setteres
        void setDia(int d);
        void setMes(int m);
        void setAno(int a);
        // getteres
        int getDia();
        int getMes();
        int getAno();

    protected:

    private:
        int dia, mes, ano;
};

#endif // DATA_H
