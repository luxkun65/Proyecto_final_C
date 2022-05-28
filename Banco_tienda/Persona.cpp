#include "Persona.h"
#include<iostream>
using namespace::std;

Persona::Persona()
{
    nombre = apellido = password = correo = identidad = "-";
    numID = 0;

}

Persona::~Persona()
{
    //dtor
}


///sets///

void Persona::setNumID(){
    cout<<"Ingrese el numero de ID: ";
    cin>>numID;
}

void Persona::setNombre(){
    fflush(stdin);
    cout<<"Ingrese el nombre de usuario: ";
    getline(cin, nombre);
}

void Persona::setApellido(){
    fflush(stdin);
    cout<<"Ingrese el nombre de usuario: ";
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


///gets///


string Persona::toString(){
    return "ID: " + to_string(numID) + "\n" +
           "Usuario: " + nombre + " " + apellido + "\n" +
           "Password: " + password + "\n" +
           "Correo: " + correo + "\n";
}

long Persona::getNumID(){
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


