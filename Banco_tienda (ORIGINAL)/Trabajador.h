#ifndef TRABAJADOR_H
#define TRABAJADOR_H
#include "Administrador.h"
#include<iostream>
using namespace::std;


class Trabajador:public Administrador
{
    public:
        Trabajador();
        virtual ~Trabajador();


        void setSalario();

        double getSalario();


    protected:

    private:
};

#endif // TRABAJADOR_H
