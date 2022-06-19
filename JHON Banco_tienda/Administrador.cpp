#include "Administrador.h"
#include"Persona.h"
#include<iostream>
using namespace::std;

Administrador::Administrador()
{

    salario = 0;
}

Administrador::~Administrador()
{
    //dtor
}


void Administrador::setSalario(){
salario = 1000000*5;
}


double Administrador::getSalario(){
return salario;
}


string Administrador::toCSV(){
return to_string(numID) + ";" + nom_usuario + ";" +
           password + ";" + correo + ";" + to_string(activo);
}
