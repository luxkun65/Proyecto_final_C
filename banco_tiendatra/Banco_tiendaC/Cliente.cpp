#include "Cliente.h"
#include"Persona.h"

Cliente::Cliente()
{
    saldo = 0.0;
    gasto = 0.0;
    membresia = "Basico";
    descuento = 0;
}

Cliente::Cliente(long id, string u_name, string pass, string corr, string mem, double sal, int des){
    numID = id;
    nom_usuario = u_name;
    password = pass;
    correo = corr;
    membresia = mem;
    saldo = sal;
    descuento = des;
}
Cliente::~Cliente()
{
    //dtor
}

void Cliente::setDescuento(int des){
    descuento = des;
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
string Cliente::getMembresia(){
    return membresia;
}
int Cliente::getDescuento(){
    return descuento;
}
string Cliente::toString(){
    return Persona::toString() +
           "Saldo: " + to_string(saldo) + "\n" +
           "Membresia: " + membresia + "\n" +
           "Descuento: " + to_string(descuento) + "% \n";
}

string Cliente::toCSV(){
    return Persona::toCSV() + membresia + ";" + to_string(saldo) + ";" + to_string(descuento);
}
