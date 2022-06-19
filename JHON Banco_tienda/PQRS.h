#ifndef PQRS_H
#define PQRS_H
#include "Cliente.h"
#include<iostream>
using namespace std;

class PQRS: public Cliente
{
    public:
        PQRS();
        virtual ~PQRS();
        PQRS(Cliente, string);
        void setMensaje(string);

        string getMensaje();
        string toString();

    protected:

    private:
        string mensaje;
};

#endif // PQRS_H
