#ifndef SWITCHEXCEPTION_H
#define SWITCHEXCEPTION_H

#include <exception>
#include <string>

class SwitchException   :  public std::exception
{
    public:
        SwitchException(int t);
        virtual ~SwitchException();

        std::string getMessenge();

    protected:

    private:
        int tipo;
};

#endif // SWITCHEXCEPTION_H
