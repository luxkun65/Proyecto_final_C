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


        virtual void setSalario();

        virtual double getSalario();

    protected:
        double salario;
    private:
};

#endif // ADMINISTRADOR_H
