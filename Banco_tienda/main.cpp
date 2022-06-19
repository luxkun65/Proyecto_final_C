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


///Cliente///
void menuCli();
//funciones del menu cliente//
//en creacion
//preguntar canidad de deinero en cuenta; generar PQRS; generar peticionde agregar $$ a cuenta
void generalPQRS();




///GENERAL///
void login(){


system("clear");
//system("cls");

ifstream clienteArch("archivoCliente.csv", ios::in);
ifstream trabajadorArch("archivoTrabajador.csv", ios::in);
ifstream administradorArch("archivoAdminstrador.csv", ios::in);

//se pide la informacion para logearse
string loginID, loginpassword,loginNombre;
bool existe = false;
int opc;
string registro;
string numID, nombre, apellido, password, correo, identidad;
cout<<"ingrese su numero de ID(si no recuerda escriba un 0): ";
cin>>loginID;
cout<<"ingrese su nombre(si no recuerda escriba un 0)): ";
cin>>loginNombre;
cout<<"ingrese su password: ";
cin>>loginpassword;



//se comprueba si el archivo cliente esta creado
if(!clienteArch){
    cout<<"error al abrir el archivo"<<endl<<endl;
    }
//se busca y compara el numero de id y la password de cliente
else{

    while(getline(clienteArch, registro)){

        stringstream token(registro);
        getline(token,numID,';');
        getline(token,nombre,';');
        getline(token,apellido,';');
        getline(token,password,';');
        getline(token,correo,';');
        getline(token,identidad,';');

        if(((loginID.compare(numID) == 0)||(loginNombre.compare(nombre) == 0))&&(loginpassword.compare(password)==0)){
            existe = true;
            menuCli();
            break;
        }
    }
clienteArch.close();
}



//se comprueba si el archivo trabajador esta creado
if(!trabajadorArch){
    cout<<"error al abrir el archivo"<<endl<<endl;
    }
//se busca y compara el numero de id y la password de trabajador
else{

    while(getline(trabajadorArch, registro)){

        stringstream token(registro);
        getline(token,numID,';');
        getline(token,nombre,';');
        getline(token,apellido,';');
        getline(token,password,';');
        getline(token,correo,';');
        getline(token,identidad,';');

        if((loginID.compare(numID) == 0)&&(loginpassword.compare(password)==0)){
            existe = true;
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
//se busca y compara el numero de id y la password de administrador
else{

    while(getline(administradorArch, registro)){

        stringstream token(registro);
        getline(token,numID,';');
        getline(token,nombre,';');
        getline(token,apellido,';');
        getline(token,password,';');
        getline(token,correo,';');
        getline(token,identidad,';');

        if((loginID.compare(numID) == 0)&&(loginpassword.compare(password)==0)){
            existe = true;
            menuAdmin();
            break;
        }
    }
administradorArch.close();
if (!existe){cout<<"\nEl usuario "<<loginID<<" y/o la password "<<" no coinciden\n\n";}
//system("pause");
system("read -p 'Press Enter to continue...' var");
}



//se crea un switch para seguir o salir del programa
do{
system("clear");
//system("cls");

cout<<"Desea salir o logearse nuevamente?"<<endl;
cout<<"1.Loginearse"<<endl;
cout<<"0.Salir"<<endl;
cin>>opc;
switch(opc){
    case 1: login();break;
    case 0: break;
    default:cout<<"\nOpcion incorrecta\n\n";
        }
    }while(opc !=0);
}



///Acceso de Admin///
//menu//
void menuAdmin(){

int opc;

do{
system("clear");
//system("cls");
cout<<"Menu de opciones"<<endl;
cout<<"1.Crear nuevas personas"<<endl;
cout<<"2.Listado general"<<endl;
cout<<"3.Buscar por ID"<<endl;
cout<<"0.Salir"<<endl;
cin>>opc;
switch(opc){
case 1: generarArchivos();break;
case 2: listadoGeneral();break;
case 3: buscarXid();break;
case 0: break;
default: cout<<"Opcion incorrecta"<<endl;
}

system("clear");
//system("cls");
}while(opc !=0 );


}
//Generador de usuarios//
void generarArchivos(){

int opc;

do{

system("clear");
//system("cls");

int aux = 0;
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

Cliente cli;

    ofstream clienteArch("archivoCliente.csv", ios::app);
    if(!clienteArch){
    cout<<"Error al crear el archivo 'archivoCliente.csv'"<<endl;
    }
    else{

    cli.setNumID();
    cli.setNombre();
    cli.setApellido();
    cli.setPassword();
    cli.setCorreo();
    cli.setIdentidad();

    clienteArch<<cli.toString()<<endl;

    clienteArch.close();

    cout<<"\n\nse ingreso correctamente el cliente\n\n";
        }

        //system("pause");
        system("read -p 'Press Enter to continue...' var");

        }


 if(aux==2){
Trabajador trab;

    ofstream trabajadorArch("archivoTrabajador.csv", ios::app);
    if(!trabajadorArch){
    cout<<"Error al crear el archivo 'archivoTrabajador.csv'"<<endl;
    }
    else{

    trab.setNumID();
    trab.setNombre();
    trab.setApellido();
    trab.setPassword();
    trab.setCorreo();
    trab.setIdentidad();

    trabajadorArch<<trab.toString()<<endl;

    trabajadorArch.close();

    cout<<"\n\nse ingreso correctamente el trabajador\n\n";
        }

        //system("pause");
        system("read -p 'Press Enter to continue...' var");

    }


if(aux==3){
Administrador admin;

    ofstream administradorArch("archivoAdminstrador.csv", ios::app);
    if(!administradorArch){
    cout<<"Error al crear el archivo 'archivoAdminstrador.csv'"<<endl;
    }
    else{

    admin.setNumID();
    admin.setNombre();
    admin.setApellido();
    admin.setPassword();
    admin.setCorreo();
    admin.setIdentidad();

    administradorArch<<admin.toString()<<endl;

    administradorArch.close();

    cout<<"\n\nse ingreso correctamente el administrado\n\n";
        }
        //system("pause");
        system("read -p 'Press Enter to continue...' var");

    }

}while(opc != 0 );


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
void menuCli(){}
//Generador de PQRS//
void generalPQRS(){


}
//agregar $$ a la cuenta//










void menuTrab(){cout<<"el trabajador existe";}


int main()
{
login();
return 0;
}











