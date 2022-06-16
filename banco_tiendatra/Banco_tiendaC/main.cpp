#include"Persona.h"
#include"Administrador.h"
#include"Trabajador.h"
#include"Cliente.h"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace::std;

///general///
void login();
void sign_up();

///administrador///
void menuAdmin();
//funciones de menu administrador//
void generarArchivos();
void listadoGeneral();
void buscarXid();
//en curso//
//eliminacion de usuarios; lectura, busqueda y eliminacion de PQRS; (aceptar peticion)agregar o quitar $$ a cuenta cliente//
void listaPQRS();
void buscarPQRS();

///trabajador///
void menuTrab();
//funciones de menu trabajador//
void PQRs();
void inactivaCuentaCliente();
void inactivaCuenta();
void guiaTrabajadores();
//funciones del menu guia para trabajadores
void trabajador1();
void trabajador2();
void trabajador3();


///Cliente///
void menuCli(string, string, string, string, string, string, string);
//funciones del menu cliente//
//en creacion
//preguntar canidad de deinero en cuenta; generar PQRS; generar peticionde agregar $$ a cuenta
void generalPQRS();

///GENERAL///
//Login de usuarios
void login(){
    //system("clear");
    system("cls");

    ifstream clienteArch("archivoCliente.csv", ios::in);
    ifstream trabajadorArch("archivoTrabajador.csv", ios::in);
    ifstream administradorArch("archivoAdminstrador.csv", ios::in);

    //se pide la informacion para logearse
    string logPassword,logUsername;
    bool existe = false;
    string registro;
    string numID, username, password, correo, membresia, saldo, descuento;
    cout<<"ingrese su nombre de usuario: ";
    cin>>logUsername;
    cout<<"ingrese su password: ";
    cin>>logPassword;

    //se comprueba si el archivo cliente esta creado
    if(!clienteArch){
        cout<<"error al abrir el archivo"<<endl<<endl;
        }
    //se busca y compara el username y la password de cliente
    else{
        while(getline(clienteArch, registro)){
            stringstream token(registro);
            getline(token,numID,';');
            getline(token,username,';');
            getline(token,password,';');
            getline(token,correo,';');
            getline(token,membresia,';');
            getline(token,saldo,';');
            getline(token,descuento,';');

            if(((logUsername.compare(username) == 0))&&(logPassword.compare(password)==0)){
                existe = true;
                menuCli(numID, username, password, correo, membresia, saldo, descuento);
                break;
            }
        }
    clienteArch.close();
    }

    //se comprueba si el archivo trabajador esta creado
    if(!trabajadorArch){
        cout<<"error al abrir el archivo"<<endl<<endl;
        }
    //se busca y compara el username y la password de trabajador
    else{

        while(getline(trabajadorArch, registro)){

            stringstream token(registro);
            getline(token,numID,';');
            getline(token,username,';');
            getline(token,password,';');
            getline(token,correo,';');

            if((logUsername.compare(username) == 0)&&(logPassword.compare(password)==0)){
                existe = true;
                cout<<endl;
                menuTrab();
                break;
            }
        }
    trabajadorArch.close();
    }

    //se comprueba si el archivo administrador esta creado
    if(!administradorArch){
        cout<<"error al abrir el archivo"<<endl<<endl;
        }
    //se busca y compara el username y la password de administrador
    else{

        while(getline(administradorArch, registro)){

            stringstream token(registro);
            getline(token,numID,';');
            getline(token,username,';');
            getline(token,password,';');
            getline(token,correo,';');

            if((logUsername.compare(username) == 0)&&(logPassword.compare(password)==0)){
                existe = true;
                break;
            }
        }
    administradorArch.close();
    if (!existe){cout<<"\nEl usuario y/o la password "<<" no coinciden\n\n";}
    system("pause");
    //system("read -p 'Press Enter to continue...' var");
    }
}

//Sign_Up/Registro de usuarios
void sign_up(){
    //system("clear");
    system("cls");
    Trabajador trab;
    ofstream trabajadorArch("archivoTrabajador.csv", ios::app);
    if(!trabajadorArch){
        cout<<"Error al crear el archivo 'archivoCliente.csv'"<<endl;
    }else{
        trab.setNumID();
        trab.setNombre();
        trab.setApellido();
        trab.setPassword();
        trab.setCorreo();

        trabajadorArch<<trab.toCSV()<<endl;
        trabajadorArch.close();

        cout<<"\n\nUsuario creado exitosamente\n\n";
    }
}

///Acceso de Admin///
//menu//
void menuAdmin(){

int opc;

do{
system("clear");
//system("cls");8
cout<<"Menu de opciones"<<endl;
cout<<"1.Crear nuevas personas"<<endl;
cout<<"2.Listado general"<<endl;
cout<<"3.Buscar por ID"<<endl;
cout<<"0.Salir"<<endl;
cin>>opc;
switch(opc){
case 1: sign_up();break;
case 2: listadoGeneral();break;
case 3: buscarXid();break;
case 0: break;
default: cout<<"Opcion incorrecta"<<endl;
}

system("clear");
//system("cls");
}while(opc !=0 );


}

//Lista por tipo de usuario//
void listadoGeneral(){

int opc;

do{

system("clear");
//system("cls");

int aux = 0;
int cont = 0;
opc = 0;
cout<<"Escoja el tipo de persona a crear"<<endl;
cout<<"1.Cliente"<<endl;
cout<<"2.Trabajador"<<endl;
cout<<"3.Administrador"<<endl;
cout<<"0.Salir"<<endl;
cin>>opc;

switch(opc){
    case 1:aux=1;break;
    case 2:aux=2;break;
    case 3:aux=3;break;
    case 0:aux=0;break;
    default: cout<<"Opcion incorrecta"<<endl;

    }

system("clear");
//system("cls");



if(aux==1){

ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo 'archivoCliente.csv'"<<endl<<endl;
}
else{

string registro;
string numID, nombre, apellido, password, correo, identidad;

cout<<"\n\n////////////////////////////////////\n\n";

while(getline(clienteArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');


cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
cont++;
}
cout<<"Hay un total de "<<cont<<" Clientes"<<endl;
//system("pause");
system("read -p 'Press Enter to continue...' var");
clienteArch.close();
}

}


if(aux==2){

ifstream trabajadorArch("archivoTrabajador.csv", ios::in);
if(!trabajadorArch){
cout<<"error al abrir el archivo 'archivoTrabajador.csv'"<<endl<<endl;
}
else{

string registro;
string numID, nombre, apellido, password, correo, identidad;

cout<<"\n\n////////////////////////////////////\n\n";

while(getline(trabajadorArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');


cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
cont++;
}
cout<<"Hay un total de "<<cont<<" Trabajadores"<<endl;
//system("pause");
system("read -p 'Press Enter to continue...' var");
trabajadorArch.close();
}

}


if(aux==3){

ifstream administradorArch("archivoAdminstrador.csv", ios::in);
if(!administradorArch){
cout<<"error al abrir el archivo 'archivoAdminstrador.csv'"<<endl<<endl;
}
else{

string registro;
string numID, nombre, apellido, password, correo, identidad;

cout<<"\n\n////////////////////////////////////\n\n";

while(getline(administradorArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');


cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
cont++;
}
//system("pause");
cout<<"Hay un total de "<<cont<<" Administradores"<<endl;
system("read -p 'Press Enter to continue...' var");
administradorArch.close();
}

}


}while(opc!=0);
}
//Bucar usuarios por ID//
void buscarXid(){
int opc;

do{

system("clear");
//system("cls");

int aux = 0;
int cont;
cont=0;
opc = 0;
cout<<"Escoja el tipo de persona a buscar"<<endl;
cout<<"1.Cliente"<<endl;
cout<<"2.Trabajador"<<endl;
cout<<"3.Administrador"<<endl;
cout<<"4.Busqueda general"<<endl;
cout<<"0.Salir"<<endl;
cin>>opc;

switch(opc){
    case 1:aux=1;break;
    case 2:aux=2;break;
    case 3:aux=3;break;
    case 4:aux=4;break;
    case 0:aux=0;break;
    default: cout<<"Opcion incorrecta"<<endl;

    }

system("clear");
//system("cls");



if(aux==1){
ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo 'archivoCliente.csv'"<<endl<<endl;
}
else{
string buscarID;
bool existe = false;
string registro;
string numID, nombre, apellido, password, correo, identidad;
cout<<"ingrese numero de ID a buscar: ";
cin>>buscarID;
cout<<"\n\n////////////////////////////////////\n\n";

while(getline(clienteArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
cont++;
}

}
cout<<"Hay un total de "<<cont<<" Clientes con ID "<<buscarID<<endl;
//system("pause");
system("read -p 'Press Enter to continue...' var");
clienteArch.close();

if (!existe){
cout<<"el cliente "<<buscarID<<" no esxiste\n";
//system("pause");
system("read -p 'Press Enter to continue...' var");
    }
}
}


if(aux==2){
ifstream trabajadorArch("archivoTrabajador.csv", ios::in);
if(!trabajadorArch){
cout<<"error al abrir el archivo 'archivoTrabajador.csv'"<<endl<<endl;
}
else{
string buscarID;
bool existe = false;
string registro;
string numID, nombre, apellido, password, correo, identidad;
cout<<"ingrese numero de ID a buscar: ";
cin>>buscarID;
cout<<"\n\n////////////////////////////////////\n\n";

while(getline(trabajadorArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
cont++;
    }
}
cout<<"Hay un total de "<<cont<<" Trabajadores con ID "<<buscarID<<endl;
//system("pause");
system("read -p 'Press Enter to continue...' var");
trabajadorArch.close();

if (!existe){
cout<<"el trabajador "<<buscarID<<" no esxiste\n";
//system("pause");
system("read -p 'Press Enter to continue...' var");
    }
}
}


if(aux==3){
ifstream administradorArch("archivoAdminstrador.csv", ios::in);
if(!administradorArch){
cout<<"error al abrir el archivo 'archivoAdminstrador.csv'"<<endl<<endl;
}
else{
string buscarID;
bool existe = false;
string registro;
string numID, nombre, apellido, password, correo, identidad;
cout<<"ingrese numero de ID a buscar: ";
cin>>buscarID;
cout<<"\n\n////////////////////////////////////\n\n";

while(getline(administradorArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
cont++;
}
}
cout<<"Hay un total de "<<cont<<" Administradores con ID "<<buscarID<<endl;
//system("pause");
system("read -p 'Press Enter to continue...' var");
administradorArch.close();

if (!existe){
cout<<"el Administrador "<<buscarID<<" no esxiste\n";
//system("pause");
system("read -p 'Press Enter to continue...' var");
    }
}
}


if(aux==4){
bool existe = false;
string buscarID;
string registro;
string numID, nombre, apellido, password, correo, identidad;
cout<<"ingrese numero de ID a buscar: ";
cin>>buscarID;
cout<<"\n\n////////////////////////////////////\n\n";



ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo 'archivoCliente.csv'"<<endl<<endl;
}
else{
existe = false;

while(getline(clienteArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
cont++;
    }
}
clienteArch.close();

if (!existe){
cout<<"No existe el cliente "<<buscarID<<endl;
    }
}

//////////////////////////////////////////

ifstream trabajadorArch("archivoTrabajador.csv", ios::in);
if(!trabajadorArch){
cout<<"error al abrir el archivo 'archivoTrabajador.csv'"<<endl<<endl;
}
else{
existe = false;

while(getline(trabajadorArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
cont++;
}
}
trabajadorArch.close();

if (!existe){
cout<<"No existe el trabajador "<<buscarID<<endl;
    }
}


///////////////////////////

ifstream administradorArch("archivoAdminstrador.csv", ios::in);
if(!administradorArch){
cout<<"error al abrir el archivo 'archivoAdminstrador.csv'"<<endl<<endl;
}
else{
existe = false;

while(getline(administradorArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
cont++;
    }
}
cout<<"Hay un total de "<<cont<<" usurarios con ID "<<buscarID<<endl;
//system("pause");
system("read -p 'Press Enter to continue...' var");
administradorArch.close();

if (!existe){
cout<<"No existe el Administrador "<<buscarID<<endl;
//system("pause");
system("read -p 'Press Enter to continue...' var");
            }
        }
    }


}while(opc != 0);

}
//lista de PQRS con contador//
void listaPQRS(){}
//buscar PQRS con contador//
void buscarPQRS(){}
//Agregar $$ a cuenta de cliente//
//restar $$ a cuenta de cliente//

//revisar PQRS; Eliminar personas;

///ACCESO CLIENTE///
//menu//
void menuCli(string id, string u_name, string pass, string corr, string mem, string sal, string des){

}
//Generador de PQRS//
void generalPQRS(){


}
//agregar $$ a la cuenta//

///Acceso de menu trabajador///
void menuTrab(){
int opc;
do{
        cout<<"MENU DE TRABAJADORES"<<endl<<endl;
        cout<<"1. Aceptar o denegar PQRs"<<endl;
        cout<<"2. Dar de baja la cuenta de un cliente"<<endl;
        cout<<"3. Dar de baja la cuenta"<<endl;
        cout<<"4. Guia"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opc;

        switch(opc){
        case 1: cout<<"En construccion"<<endl; break;
        case 2: cout<<"En construccion"<<endl; break;
        case 3: cout<<"En construccion"<<endl; break;
        case 4: guiaTrabajadores(); break;
        case 0: break;
        default: cout<<"Opcion incorrecta, por favor digite nuevamente"<<endl;
        }
        cout<<endl;
        system("pause");
        system("cls");


}while(opc != 0);


}
//implementacion de funciones trabajador
void PQRs(){


}

void inactivaCuentaCliente(){


}

void inactivaCuenta(){


}

void guiaTrabajadores(){
      int opc;
    do{
            system("cls");
        cout<<"MENU GUIA PARA TRABAJADORES"<<endl<<endl;
        cout<<"1. Aceptar o denegar PQR"<<endl;
        cout<<"2. Dar de baja a un cliente"<<endl;
        cout<<"3. Dar de baja su cuenta trabajador"<<endl;
        cout<<"0. Regresar al menu guia principal"<<endl<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opc;

        switch(opc){
        case 1: trabajador1(); break;
        case 2: trabajador2(); break;
        case 3: trabajador3(); break;
        case 0: break;
        default: cout<<"Opcion incorrecta, por favor digite nuevamente"<<endl;
        }
        cout<<endl;
        system("pause");

    }while(opc != 0);
}

//implementacion funciones mensaje de guia

void trabajador1(){
    system("cls");
    cout<<"Para aceptar o denegar un PQR (Peticion, Queja, Recurso) debe iniciar sesion en su cuenta"<<endl;
    cout<<"y se le abrira un menu predeterminado para trabajadores, en este menu debe seleccionar la"<<endl;
    cout<<"opcion 'Aceptar o denegar PQR', alli se mostraran las diferentes PQR enviadas por los clientes"<<endl;
    cout<<"debe leer detenidamente cada una de ellas y de acuerdo a sus bases, usted debera evaluar si es"<<endl;
    cout<<"apropiada o no, si la es debe seleccionar la opcion 'aceptar PQR' O si no lo es 'denegar PQR'"<<endl;

}

void trabajador2(){
    system("cls");
    cout<<"Para dar de baja a un cliente debe de iniciar sesion en su cuenta, se le desplegara"<<endl;
    cout<<"un menu, en dicho menu debe seleccional la opcion 'eliminar un cliente', debe ingresar"<<endl;
    cout<<"el numero de ID de el cliente a eliminar, le pedira la confirmacion de si en verdad desea"<<endl;
    cout<<"dar de baja la cuenta del cliente, debe confirmar y el cliente pasara a estado inactivo."<<endl;

}

void trabajador3(){
    system("cls");
    cout<<"Para dar de baja su cuenta propia, debe de iniciar sesion primero, se le desplegara"<<endl;
    cout<<"un menu, en dicho menu debe seleccionar la opcion 'darse de baja', debe ingresar"<<endl;
    cout<<"se le pedira la confirmacion de si en verdad desea darse de baja,"<<endl;
    cout<<"debe confirmar y posterior a esto su cuenta pasara a estado inactivo."<<endl;

}

int main(){
    //sign_up();
    login();
    return 0;
}
