#ifndef CLIENTE_H
#define CLIENTE_H
#include"Persona.h"
#include<iostream>
using namespace::std;


class Cliente:public Persona
{
    public:
        Cliente();
        virtual ~Cliente();

        double saldo;
        int membresia;

        void setSaldo(double);
        void setMembresia();
        void setMembresia(int);
        void setGasto(double);

        double getSaldo();
        string getMembresia();


    protected:

    private:
};

#endif // CLIENTE_H
