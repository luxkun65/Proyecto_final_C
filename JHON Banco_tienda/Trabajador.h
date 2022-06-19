#ifndef TRABAJADOR_H
#define TRABAJADOR_H
#include"Persona.h"


class Trabajador:public Persona
{
    public:
        Trabajador();
        virtual ~Trabajador();

        double salarioTrab;

        void setSalarioTrab();

        double getSalarioTrab();


    protected:

    private:
};

#endif // TRABAJADOR_H
