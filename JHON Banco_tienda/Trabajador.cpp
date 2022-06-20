#include "Trabajador.h"
#include"Persona.h"
#include "Cliente.h"
#include<iostream>
using namespace::std;

Trabajador::Trabajador()
{

}

Trabajador::~Trabajador()
{
    //dtor
}



string Trabajador::toCSV(){
    return to_string(numID) + ";" + nom_usuario + ";" +
           password + ";" + correo + ";" + to_string(activo);
}
