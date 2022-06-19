#include "Cliente.h"
#include"Persona.h"
#include<iostream>
using namespace::std;

Cliente::Cliente()
{
    saldo = 0.0;
    membresia = 0;
    identidad = "cliente";
}

Cliente::~Cliente()
{
    //dtor
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
