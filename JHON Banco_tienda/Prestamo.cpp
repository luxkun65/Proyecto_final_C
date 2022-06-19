#include "Prestamo.h"
#include "Cliente.h"

Prestamo::Prestamo()
{
    prestamo = 0;
}

Prestamo::~Prestamo()
{
    //dtor
}
Prestamo::Prestamo(Cliente cli, double pres){
    nom_usuario = cli.getNombreUsuario();
    numID = cli.getNumID();
    correo = cli.getCorreo();
    membresia = cli.getMembresia();
    saldo = cli.getSaldo();
    deuda = cli.getDeuda();
    prestamo = pres;
}


void Prestamo::setPrestamo(double pres){
    prestamo = pres;
}

double Prestamo::getPrestamo(){
    return prestamo;
}

string Prestamo::toString(){
    return "Usuario: " + nom_usuario + " #" + to_string(numID) + "\n" +
            "Correo: " + correo + "  Membresia: " + membresia + "\n" +
            "Saldo: " + to_string(saldo) + "  Deuda: " + to_string(deuda) + "\n" +
            "Pide un prestamo de: " + to_string(prestamo) + "\n";
}
