#ifndef TRABAJADOR_H
#define TRABAJADOR_H
#include"Persona.h"
#include<sstream>


class Trabajador:public Persona
{
    public:
        long salario;
        Trabajador();
        virtual ~Trabajador();

         void setSalario();
        double getSalario();
        string toCSV();

    protected:

    private:
};

#endif // TRABAJADOR_H
