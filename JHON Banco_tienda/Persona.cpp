#include "Persona.h"

Persona::Persona()
{
    nombre = apellido = password = correo = nom_usuario = "-";
    numID = 0;
    activo = true;
}

Persona::~Persona()
{
    //dtor
}


///sets///
void Persona::setNombreUsuario(){
    nom_usuario = nombre + "_" + apellido;
}

void Persona::setNumID(){
    srand(time(NULL));
    numID = 1+rand() % 999;
}
void Persona::setNombre(){
    fflush(stdin);
    cout<<"Ingrese su nombre: ";
    getline(cin,nombre);
}
void Persona::setApellido(){
    fflush(stdin);
    cout<<"Ingrese su apellido: ";
    getline(cin,apellido);
    Persona::setNombreUsuario();
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
void Persona::setActivo(){
    activo = true;
}
void Persona::setActivo(bool act){
    if(act){
        activo = true;
    }else{
        activo = false;
    }
}

///gets///


string Persona::toCSV(){
}
string Persona::toString(){
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

string Persona::getNombreUsuario(){
    return nom_usuario;
}

bool Persona::getActivo(){
    return activo;
}

