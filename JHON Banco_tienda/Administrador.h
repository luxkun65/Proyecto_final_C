#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include"Persona.h"

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
