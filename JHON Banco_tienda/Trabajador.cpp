#include "Trabajador.h"
#include"Persona.h"

Trabajador::Trabajador()
{
    salarioTrab = 0;
}

Trabajador::~Trabajador()
{
    //dtor
}


void Trabajador::setSalarioTrab(){
salarioTrab = 1000000*2;
}

double Trabajador::getSalarioTrab(){
return salarioTrab;
}
