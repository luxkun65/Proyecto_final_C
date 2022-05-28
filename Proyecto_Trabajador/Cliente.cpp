#include "Cliente.h"

Cliente::Cliente()
{
    usuario = password = correo = "-";
    saldo = 0.0;
    membresia = 0;
    numID = 0;
}

void Cliente::setNumID(){
    cout<<"Ingrese el numero de ID: ";
    cin>>numID;
}

void Cliente::setUsuario(){
    fflush(stdin);
    cout<<"Ingrese el nombre de usuario: ";
    getline(cin, usuario);
}
void Cliente::setPassword(){
    fflush(stdin);
    cout<<"Ingrese la contrasena: ";
    getline(cin, password);
}
void Cliente::setCorreo(){
    fflush(stdin);
    cout<<"Ingrese correo electronico: ";
    getline(cin, correo);
}
void Cliente::setSaldo(double sal){
    saldo += sal;
}
void Cliente::setGasto(double gasto){
    saldo -= gasto;
}

void Cliente::setMembresia(){
    membresia = 1;
}
void Cliente::setMembresia(int mem){
    membresia = mem;
}
string Cliente::toString(){
    return "ID: " + to_string(numID) + "\n" +
           "Usuario: " + usuario + "\n" +
           "Password: " + password + "\n" +
           "Correo: " + correo + "\n" +
           "Membresia: " + getMembresia() + "\n" +
           "Saldo: " + to_string(saldo);
}

long Cliente::getNumID(){
    return numID;
}
string Cliente::getUsuario(){
    return usuario;
}
string Cliente::getPassword(){
    return password;
}
string Cliente::getCorreo(){
    return correo;
}
double Cliente::getSaldo(){
    return saldo;
}
string Cliente::getMembresia(){
    switch(membresia){
        case 1: return "basico"; break;
        case 2: return "medio"; break;
        case 3: return "premium"; break;
        default: return "basico";
    }
}

Cliente::~Cliente()
{
    //dtor
}

int main(){
    Cliente cli;
    cli.setNumID();
    cli.setUsuario();
    cli.setCorreo();
    cli.setPassword();
    cli.setSaldo(5000);
    cli.setMembresia(3);
    cout<<cli.toString();
    return 0;
}
