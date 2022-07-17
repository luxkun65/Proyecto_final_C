#include "Persona.h"
#include<iostream>
#include<cstdlib>
using namespace::std;

Persona::Persona()
{
    nombre = apellido = password = correo = identidad = "-";
    numID = 0;
    identidad = " ";
    activo = "activa";

}

Persona::~Persona()
{
    //dtor
}


///sets///

void Persona::setNumID(){
    cout<<"Ingrese el numero de ID: ";
    cin>>numID;
    //srand(time(NULL));
    //numID = 1 + rand() % 100;
}


void Persona::setNombre(){
     getline(cin, nombre);//////////////////////linux////////////////////////
    fflush(stdin);
    cout<<"Ingrese el nombre de usuario: ";
    getline(cin, nombre);
}


void Persona::setApellido(){
    fflush(stdin);
    cout<<"Ingrese el apellido de usuario: ";
    getline(cin, apellido);
}


void Persona::setPassword(){
    fflush(stdin);
    cout<<"Ingrese la contrasena: ";
    getline(cin, password);
}


void Persona::setCorreo(){
    fflush(stdin);
    cout<<"Ingrese correo electronico: ";
    getline(cin, correo);
}


void Persona::setIdentidad(){
    fflush(stdin);
    cout<<"Usted es: "<<identidad;
}


void Persona::setActivo(bool act){
    if(act){
        activo = "activa";
    }else{
        activo = "inactiva";
    }
}




///gets///

string Persona::toString(){
    return to_string(numID) + ";" + nombre + ";" + apellido + ";" + password + ";" + correo + ";" + identidad+ ";" +activo;
}


int Persona::getNumID(){
    return numID;
}


string Persona::getNombre(){
    return nombre;
}


string Persona::getApellido(){
    return apellido;
}


string Persona::getPassword(){
    return password;
}


string Persona::getCorreo(){
    return correo;
}


string Persona::getIdentidad(){
return identidad;
}


string Persona::getActivo(){


    return activo;
}
