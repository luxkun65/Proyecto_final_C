#ifndef CLIENTE_H
#define CLIENTE_H
#include<iostream>
using namespace std;

class Cliente
{
    public:
        long numID;
        string usuario, password, correo;
        double saldo;
        int membresia;

        Cliente();
        virtual ~Cliente();

        void setNumID();
        void setUsuario();
        void setPassword();
        void setCorreo();
        void setSaldo(double);
        void setMembresia();
        void setMembresia(int);
        void setGasto(double);
        string toString();

        long getNumID();
        string getUsuario();
        string getPassword();
        string getCorreo();
        double getSaldo();
        string getMembresia();

    protected:

    private:
};

#endif // CLIENTE_H
