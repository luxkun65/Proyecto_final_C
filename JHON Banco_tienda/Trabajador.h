#ifndef TRABAJADOR_H
#define TRABAJADOR_H
#include"Persona.h"
#include<sstream>
#include "Administrador.h"


class Trabajador:public Administrador
{
    public:
        Trabajador();
        virtual ~Trabajador();

        string toCSV();

    protected:

    private:
};

#endif // TRABAJADOR_H
