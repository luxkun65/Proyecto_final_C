#ifndef CLIENTE_H
#define CLIENTE_H
#include"Persona.h"


class Cliente:public Persona
{
    public:
        Cliente();
        virtual ~Cliente();

        void setSaldo(double);
        void setMembresia(string);
        void setGasto(double);
        void setDescuento(int);
        Cliente(long, string, string, string, string, double, int);

        double getGasto();
        double getSaldo();
        int getDescuento();
        string getMembresia();
        string toString();
        string toCSV();


    protected:
        double saldo;
        double gasto;
        int descuento;
        string membresia;

    private:
};

#endif // CLIENTE_H
