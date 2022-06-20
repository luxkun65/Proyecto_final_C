#include "Administrador.h"
#include"Persona.h"
#include<iostream>
using namespace::std;

Administrador::Administrador()
{

}

Administrador::~Administrador()
{
    //dtor
}




string Administrador::toCSV(){
return to_string(numID) + ";" + nom_usuario + ";" +
           password + ";" + correo + ";" + to_string(activo);
}
