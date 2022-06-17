#include "Persona.h"

Persona::Persona()
{
    nombre = apellido = password = correo = nom_usuario = "-";
    numID = 0;
}

Persona::~Persona()
{
    //dtor
}


///sets///

void Persona::setNumID(){
    srand(time(NULL));
    numID = 1+rand() % 999;
}
void Persona::setNombre(){
    fflush(stdin);
    cout<<"Ingrese su nombre: ";
    getline(cin, nombre);
}
void Persona::setApellido(){
    fflush(stdin);
    cout<<"Ingrese su apellido: ";
    getline(cin, apellido);
}
void Persona::setPassword(){
    fflush(stdin);
    cout<<"Ingrese un password: ";
    getline(cin, password);
}
void Persona::setCorreo(){
    fflush(stdin);
    cout<<"Ingrese correo electronico: ";
    getline(cin, correo);
}
void Persona::setNombreUsuario(){
    nom_usuario = nombre + "_" + apellido;
}
///gets///


string Persona::toCSV(){
    return to_string(numID) + ";" + nom_usuario + ";" + password + ";" + correo + ";";
}
string Persona::toString(){
    return "ID: " + to_string(numID) + "\n" +
           "Nombre de usuario: " + nombre + "_" + apellido + "\n" +
           "Correo: " + correo + "\n" +
           "Password: " + password + "\n";
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


