#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include"Persona.h"

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
