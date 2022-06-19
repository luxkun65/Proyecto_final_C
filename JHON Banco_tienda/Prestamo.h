#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Cliente.h"
#include<iostream>
using namespace std;

class Prestamo: public Cliente
{
    public:
        Prestamo();
        virtual ~Prestamo();
        void setPrestamo(double);
        Prestamo(Cliente, double);

        double getPrestamo();
        string toString();

    protected:

    private:
        double prestamo;
};

#endif // PRESTAMO_H
