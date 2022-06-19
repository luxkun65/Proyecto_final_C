#ifndef CLIENTE_H
#define CLIENTE_H
#include<sstream>
#include"Persona.h"


class Cliente:public Persona
{
    public:
        Cliente();
        virtual ~Cliente();

        void setSaldo(double);
        void setMembresia(string);
        void setGasto(double);
        void setDeuda(double);
        void setDescuento(int);
        Cliente(string);

        double getGasto();
        double getSaldo();
        double getDeuda();
        int getDescuento();
        string getMembresia();
        string toString();
        string toCSV();

    protected:
        double saldo;
        double gasto;
        double deuda;
        int descuento;
        string membresia;
    private:
};

#endif // CLIENTE_H
