#include "Cliente.h"
#include"Persona.h"

Cliente::Cliente()
{
    saldo = 0.0;
    gasto = 0.0;
    deuda = 0.0;
    membresia = "Basico";
    descuento = 0;
}

Cliente::Cliente(string registro){
    string _numID, _username, _password, _correo, _membresia, _saldo, _descuento, _deuda, _activo;
    stringstream token(registro);
    getline(token,_numID,';');
    getline(token,_username,';');
    getline(token,_password,';');
    getline(token,_correo,';');
    getline(token,_membresia,';');
    getline(token,_saldo,';');
    getline(token,_descuento,';');
    getline(token,_deuda,';');
    getline(token,_activo,';');
    stringstream ss, sd, si, sa, sdeu;
    ss<<_saldo;
    ss>>saldo;
    sd<<_descuento;
    sd>>descuento;
    si<<_numID;
    si>>numID;
    sa<<_activo;
    sa>>activo;
    sdeu<<_deuda;
    sdeu>>deuda;
    nom_usuario = _username;
    correo = _correo;
    password = _password;
    membresia = _membresia;
}
Cliente::~Cliente()
{
    //dtor
}

void Cliente::setDescuento(int des){
    descuento = des;
}
void Cliente::setDeuda(double deu){
    deuda = deu;
}
void Cliente::setSaldo(double sal){
    saldo += sal;
}
void Cliente::setGasto(double gasto){
    saldo -= gasto;
}

void Cliente::setMembresia(string mem){
    membresia = mem;
}

double Cliente::getSaldo(){
    return saldo;
}
double Cliente::getDeuda(){
    return deuda;
}
string Cliente::getMembresia(){
    return membresia;
}
int Cliente::getDescuento(){
    return descuento;
}
string Cliente::toString(){
    return "Nombre de usuario: " + nom_usuario + "\n" +
           "Numero ID: " + to_string(numID) + "\n" +
           "Correo: " + correo + "\n" +
           "Password: " + password + "\n" +
           "Saldo: " + to_string(saldo) + "\n" +
           "Membresia: " + membresia + "\n" +
           "Descuento: " + to_string(descuento) + "% \n" +
           "Deuda: " + to_string(deuda) + "\n" +
           "Activo: " + to_string(activo) + "\n";
}

string Cliente::toCSV(){
    return to_string(numID) + ";" + nom_usuario + ";" +
           password + ";" + correo + ";" + membresia + ";" +
           to_string(saldo) + ";" + to_string(descuento) + ";" +
           to_string(deuda) + ";" + to_string(activo);
}
