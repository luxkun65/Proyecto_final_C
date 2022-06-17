#include "Trabajador.h"
#include"Persona.h"
#include<iostream>
using namespace::std;

Trabajador::Trabajador()
{
    identidad = "trabajador";
    salario = 0;
}

Trabajador::~Trabajador()
{
    //dtor
}


void Trabajador::setSalario(){
salario = 1000000*2;
}

double Trabajador::getSalario(){
return salario;
}
