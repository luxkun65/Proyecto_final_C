#include "Administrador.h"
#include"Persona.h"

Administrador::Administrador()
{
    salarioAdmin = 0;
}

Administrador::~Administrador()
{
    //dtor
}


void Administrador::setSalarioAdmin(){
salarioAdmin = 1000000*5;
}


double Administrador::getSalarioAdmin(){
return salarioAdmin;
}
