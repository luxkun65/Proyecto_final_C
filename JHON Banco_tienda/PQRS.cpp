#include "PQRS.h"
#include"Cliente.h"
PQRS::PQRS()
{
    mensaje = "-";
}

PQRS::~PQRS()
{
    //dtor
}
PQRS::PQRS(Cliente cli, string mnsg){
    nom_usuario = cli.getNombreUsuario();
    numID = cli.getNumID();
    correo = cli.getCorreo();
    membresia = cli.getMembresia();
    mensaje = mnsg;
}

void PQRS::setMensaje(string mnsg){
    mensaje = mnsg;
}

string PQRS::getMensaje(){
    return mensaje;
}

string PQRS::toString(){
    return "Usuario: " + nom_usuario + " #" + to_string(numID) + "\n" +
            "Correo: " + correo + "  Membresia: " + membresia + "\n" +
            "Dice: " + mensaje + "\n";
}
