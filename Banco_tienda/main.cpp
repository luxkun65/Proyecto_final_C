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
//Clientes//
void generarArchivos();
void listadoGeneral();
void buscarXid();
//trabajador//






///trabajador///
void menuTrab();


///Cliente///
void menuCli();







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
//Bucar usuarios por ID//
void buscarXid(){
system("clear");
//system("cls");

ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo"<<endl<<endl;
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
cout<<correo<<" "<<password<<endl;
cout<<identidad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";

}

}
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
//Lista por tipo de usuario//
void listadoGeneral(){
system("clear");
//system("cls");

ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo"<<endl<<endl;
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
cout<<correo<<" "<<password<<endl;
cout<<identidad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";

}
//system("pause");
system("read -p 'Press Enter to continue...' var");
clienteArch.close();
}

}

//revisar PQRS; Eliminar personas;

void menuCli(){cout<<"el cliente existe";}
void menuTrab(){cout<<"el trabajador existe";}


int main()
{
login();
return 0;
}











