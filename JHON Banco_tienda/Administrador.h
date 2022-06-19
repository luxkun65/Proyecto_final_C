#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include"Persona.h"
#include <sstream>

class Administrador:public Persona
{
    public:
        Administrador();
        virtual ~Administrador();

        virtual void setSalario();

        virtual double getSalario();

        string toCSV();

    protected:
        double salario;
    private:
};

#endif // ADMINISTRADOR_H
