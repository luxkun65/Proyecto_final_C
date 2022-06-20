#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include"Persona.h"
#include <sstream>

class Administrador:public Persona
{
    public:
        Administrador();
        virtual ~Administrador();

        string toCSV();

    protected:
    private:
};

#endif // ADMINISTRADOR_H
