#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include"Persona.h"
#include<iostream>
using namespace::std;

class Administrador:public Persona
{
    public:
        Administrador();
        virtual ~Administrador();

        double salarioAdmin;

        void setSalarioAdmin();

        double getSalarioAdmin();

    protected:

    private:
};

#endif // ADMINISTRADOR_H
