#include"Persona.h"
#include"Administrador.h"
#include"Trabajador.h"
#include"Cliente.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace::std;

///general///
void login();
void salida();
void registro();

///administrador///
void menuAdmin();
//funciones de menu administrador//
void generarArchivos();

//busca si el cliente ya esta creado
int getFrecuenciaCliente(string);
int getFrecuenciaTrabajador(string);
int getFrecuenciaAdministrador(string);
//generar un listado general de usuarios//
void listadoGeneral();
//mostrar los usuarios buscados X ID//
void buscarXid();
//modificacion de datos//
void modificarUsuarios();
//eliminacion de usuarios//
void eliminarUsuarios();
//cambiar actividad de los usuarios//
void cambiarActividad();
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





string userName;
string userID;
string userIdentity;



///GENERAL///
void login(){


system("clear");
//system("cls");

ifstream clienteArch("archivoCliente.csv", ios::in);
ifstream trabajadorArch("archivoTrabajador.csv", ios::in);
ifstream administradorArch("archivoAdminstrador.csv", ios::in);

//se pide la informacion para logearse
string loginID_Nombre, loginpassword;
bool existe = false;
string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;
cout<<"ingrese su numero de ID o Nombre de usuario: ";
cin>>loginID_Nombre;
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
getline(token,actividad,';');



        if(((loginID_Nombre.compare(numID) == 0)||(loginID_Nombre.compare(nombre) == 0)) &&(loginpassword.compare(password)==0)&& (actividad.compare("activa")==0)){
            userName=nombre ;
            userID = numID;
            userIdentity=identidad;
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
getline(token,actividad,';');


        if(((loginID_Nombre.compare(numID) == 0)||(loginID_Nombre.compare(nombre) == 0)) &&(loginpassword.compare(password)==0)&&(actividad.compare("activa")==0)){
            userName=nombre ;
            userID = numID;
            userIdentity=identidad;
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
    getline(token,actividad,';');

        if(((loginID_Nombre.compare(numID) == 0)||(loginID_Nombre.compare(nombre) == 0)) &&(loginpassword.compare(password)==0)&& (actividad.compare("activa")==0)){
            userName=nombre ;
            userID = numID;
            userIdentity=identidad;
            existe = true;
            menuAdmin();
            break;
        }
    }
administradorArch.close();
if (!existe){cout<<"\nEl usuario "<<loginID_Nombre<<" y/o la password "<<" no coinciden\n\n";}
//system("pause");
system("read -p 'Press Enter to continue...' var");
}

salida();

}

void salida(){

int opc;
//se crea un switch para seguir o salir del programa

system("clear");
//system("cls");
cout<<"Desea salir o logearse nuevamente?"<<endl;
cout<<"1.Logearse"<<endl;
cout<<"0.Salir"<<endl;
cin>>opc;
switch(opc){
    case 1: login();break;
    case 0: break;
    default:{cout<<"\nOpcion incorrecta\n\n";
            //system("pause");
            system("read -p 'Press Enter to continue...' var");
            salida();}
        }

}



///Acceso de Admin///
//menu//
void menuAdmin(){

int opc;

do{
system("clear");
//system("cls");
cout<<"Bienvenido "<<userName<<endl;
cout<<"Menu de opciones"<<endl;
cout<<"1.Crear nuevas personas"<<endl;
cout<<"2.Listado general"<<endl;
cout<<"3.Buscar por ID"<<endl;
cout<<"4.Modificar usuario"<<endl;
cout<<"5.Eliminar usuario"<<endl;
cout<<"6.Eliminar todos los datos de un usuario"<<endl;
cout<<"mi cuenta (construccion)"<<endl;
cout<<"0.Salir"<<endl;
cin>>opc;
switch(opc){
case 1: generarArchivos();break;
case 2: listadoGeneral();break;
case 3: buscarXid();break;
case 4: modificarUsuarios();break;
case 5: cambiarActividad();break;
case 6: eliminarUsuarios();break;
case 0: break;
default: {  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}
}

system("clear");
//system("cls");
}while(opc !=0 );


}



//Generador de usuarios//
void generarArchivos(){

int opc;
int aux = 0;


do{


//administrador sub menu
if(userIdentity.compare("administrador")==0){


system("clear");
//system("cls");


opc = 0;
cout<<"Escoja el tipo de persona a crear"<<endl;
cout<<"1.Cliente"<<endl;
cout<<"2.Trabajador"<<endl;
cout<<"3.Administrador"<<endl;
cout<<"0.Atras"<<endl;
cin>>opc;

switch(opc){
    case 1:aux=1;break;
    case 2:aux=2;break;
    case 3:aux=3;break;
    case 0:aux=0;break;
    default: {  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

    }

}




//trabajador sub menu
if(userIdentity.compare("trabajador")==0){

system("clear");
//system("cls");


opc = 0;
cout<<"Crear un Usuario"<<endl;
cout<<"1.Crear nuevo Cliente"<<endl;
cout<<"0.Atras"<<endl;
cin>>opc;

switch(opc){
    case 1:aux=1;break;
    case 0:aux=0;break;
    default: {  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

    }

}




system("clear");
//system("cls");



//Cliente
if(aux==1){

Cliente cli;

    ofstream clienteArch("archivoCliente.csv", ios::app);
    if(!clienteArch){
    cout<<"Error al crear el archivo 'archivoCliente.csv'"<<endl;
    }
    else{

    cli.setNumID();
    if(getFrecuenciaCliente(to_string(cli.getNumID()))==0){
        cli.setNombre();
        cli.setApellido();
        cli.setPassword();
        cli.setCorreo();
        cli.setIdentidad();
        cli.setActivo(true);

        clienteArch<<cli.toString()<<endl;

        clienteArch.close();

        cout<<"\n\nse ingreso correctamente el cliente\n\n";
        }

        else{
        cout<<"El cliente con numero de ID "<<cli.getNumID()<<" ya existe\n\n";
        clienteArch.close();
        }


}
//system("pause");
system("read -p 'Press Enter to continue...' var");

}



//trabajador
 if(aux==2){
Trabajador trab;

    ofstream trabajadorArch("archivoTrabajador.csv", ios::app);
    if(!trabajadorArch){
    cout<<"Error al crear el archivo 'archivoTrabajador.csv'"<<endl;
    }
    else{

    trab.setNumID();
    if(getFrecuenciaTrabajador(to_string(trab.getNumID())) == 0){
    trab.setNombre();
    trab.setApellido();
    trab.setPassword();
    trab.setCorreo();
    trab.setIdentidad();
    trab.setActivo(true);

    trabajadorArch<<trab.toString()<<endl;

    trabajadorArch.close();

    cout<<"\n\nse ingreso correctamente el trabajador\n\n";
        }
        else{
        cout<<"El Trabajador con numero de ID "<<trab.getNumID()<<" ya existe\n\n";
        trabajadorArch.close();
        }

//system("pause");
system("read -p 'Press Enter to continue...' var");

    }
}



//administrador
if(aux==3){
Administrador admin;

    ofstream administradorArch("archivoAdminstrador.csv", ios::app);
    if(!administradorArch){
    cout<<"Error al crear el archivo 'archivoAdminstrador.csv'"<<endl;
    }
    else{

    admin.setNumID();
    if(getFrecuenciaAdministrador(to_string(admin.getNumID())) == 0){
    admin.setNombre();
    admin.setApellido();
    admin.setPassword();
    admin.setCorreo();
    admin.setIdentidad();
    admin.setActivo(true);

    administradorArch<<admin.toString()<<endl;

    administradorArch.close();

    cout<<"\n\nse ingreso correctamente el administrado\n\n";
        }
        else{
        cout<<"El Adminnistrador con numero de ID "<<admin.getNumID()<<" ya existe\n\n";
        administradorArch.close();
        }
//system("pause");
system("read -p 'Press Enter to continue...' var");

    }
}


}while(opc != 0 );

}





//busca la cantidad de codigos iguales//

int getFrecuenciaCliente(string num_id_buscar){

int cont = 0;
ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo 'archivoCliente.csv'"<<endl<<endl;
}
else{

string registro;
string numID;

while(getline(clienteArch, registro)){

stringstream token(registro);
getline(token,numID,';');

if(num_id_buscar.compare(numID) == 0 ) cont++;

    }

clienteArch.close();

    }
return cont;
}


int getFrecuenciaTrabajador(string num_id_buscar){

int cont = 0;

ifstream trabajadorArch("archivoTrabajador.csv", ios::in);
if(!trabajadorArch){
cout<<"error al abrir el archivo 'archivoTrabajador.csv'"<<endl<<endl;
}
else{

string registro;
string numID;

while(getline(trabajadorArch, registro)){

stringstream token(registro);
getline(token,numID,';');


if(num_id_buscar.compare(numID) == 0 ) cont++;


}

trabajadorArch.close();

}

return cont;
}


int getFrecuenciaAdministrador(string num_id_buscar){

int cont = 0;

ifstream administradorArch("archivoAdminstrador.csv", ios::in);
if(!administradorArch){
cout<<"error al abrir el archivo 'archivoAdminstrador.csv'"<<endl<<endl;
}
else{

string registro;
string numID;

while(getline(administradorArch, registro)){

stringstream token(registro);
getline(token,numID,';');


if(num_id_buscar.compare(numID) == 0 )cont++;
}

administradorArch.close();

}
return cont;

}





//Lista por tipo de usuario//
void listadoGeneral(){

int opc;
int aux = 0;
int cont = 0;
opc = 0;

do{

if(userIdentity.compare("administrador")==0){

aux = 0;
cont = 0;
opc = 0;

system("clear");
//system("cls");

cout<<"Escoja el tipo de persona a buscar"<<endl;
cout<<"1.Cliente"<<endl;
cout<<"2.Trabajador"<<endl;
cout<<"3.Administrador"<<endl;
cout<<"0.Atras"<<endl;
cin>>opc;

switch(opc){
    case 1:aux=1;break;
    case 2:aux=2;break;
    case 3:aux=3;break;
    case 0:aux=0;break;
    default:{  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

    }

}

if(userIdentity.compare("trabajador")==0){

system("clear");
//system("cls");

aux = 0;
cont = 0;
opc = 0;

cout<<"Listado de los usuarios del programa"<<endl;
cout<<"1.Mostrar listado de clientes"<<endl;
cout<<"0.Atras"<<endl;
cin>>opc;

switch(opc){
    case 1:aux=1;break;
    case 0:aux=0;break;
    default:{  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

    }

}

system("clear");
//system("cls");



//cliente
if(aux==1){

ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo 'archivoCliente.csv'"<<endl<<endl;
}
else{

string registro;
string numID, nombre, apellido, password, correo, identidad, actividad;

cout<<"\n\n////////////////////////////////////\n\n";

while(getline(clienteArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');
getline(token,actividad,';');



cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<actividad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
cont++;
}
cout<<"Hay un total de "<<cont<<" Clientes"<<endl;
//system("pause");
system("read -p 'Press Enter to continue...' var");
clienteArch.close();
}

}



//trabajador
if(aux==2){

ifstream trabajadorArch("archivoTrabajador.csv", ios::in);
if(!trabajadorArch){
cout<<"error al abrir el archivo 'archivoTrabajador.csv'"<<endl<<endl;
}
else{

string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;

cout<<"\n\n////////////////////////////////////\n\n";

while(getline(trabajadorArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');
getline(token,actividad,';');

cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<actividad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
cont++;
}
cout<<"Hay un total de "<<cont<<" Trabajadores"<<endl;
//system("pause");
system("read -p 'Press Enter to continue...' var");
trabajadorArch.close();
}

}



//administrador
if(aux==3){

ifstream administradorArch("archivoAdminstrador.csv", ios::in);
if(!administradorArch){
cout<<"error al abrir el archivo 'archivoAdminstrador.csv'"<<endl<<endl;
}
else{

string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;

cout<<"\n\n////////////////////////////////////\n\n";

while(getline(administradorArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');
getline(token,actividad,';');


cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<actividad<<endl;
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
system("clear");
//system("cls");
int opc;
int aux = 0;

do{

//sub menu administrador
if(userIdentity.compare("administrador")==0){

system("clear");
//system("cls");

aux = 0;
opc = 0;
cout<<"Escoja el tipo de persona a buscar"<<endl;
cout<<"1.Cliente"<<endl;
cout<<"2.Trabajador"<<endl;
cout<<"3.Administrador"<<endl;
cout<<"4.Busqueda general"<<endl;
cout<<"0.Atras"<<endl;
cin>>opc;

switch(opc){
    case 1:aux=1;break;
    case 2:aux=2;break;
    case 3:aux=3;break;
    case 4:aux=4;break;
    case 0:aux=0;break;
    default:{  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

    }


}


//sub mennu trabajador
if(userIdentity.compare("trabajador")==0){

system("clear");
//system("cls");

aux = 0;
opc = 0;
cout<<"Busqueda de Usuarios por ID"<<endl;
cout<<"1.Buscar cliente"<<endl;
cout<<"0.Atras"<<endl;
cin>>opc;

switch(opc){
    case 1:aux=1;break;
    case 0:aux=0;break;
    default:{  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

    }


}

system("clear");
//system("cls");



//cliente
if(aux==1){
ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo 'archivoCliente.csv'"<<endl<<endl;
}
else{
string buscarID;
bool existe = false;
string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;
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
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<actividad<<endl;
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



//trabajador
if(aux==2){
ifstream trabajadorArch("archivoTrabajador.csv", ios::in);
if(!trabajadorArch){
cout<<"error al abrir el archivo 'archivoTrabajador.csv'"<<endl<<endl;
}
else{
string buscarID;
bool existe = false;
string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;
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
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<actividad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
    }
}
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



//Administrador
if(aux==3){
ifstream administradorArch("archivoAdminstrador.csv", ios::in);
if(!administradorArch){
cout<<"error al abrir el archivo 'archivoAdminstrador.csv'"<<endl<<endl;
}
else{
string buscarID;
bool existe = false;
string registro;
string numID, nombre, apellido, password, correo, identidad, actividad;
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
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<actividad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
}
}
//system("pause");
system("read -p 'Press Enter to continue...' var");
administradorArch.close();

if (!existe){
cout<<"No existe el administrador "<<buscarID<<endl;
//system("pause");
system("read -p 'Press Enter to continue...' var");
    }
}
}



//todos
if(aux==4){
bool existe = false;
string buscarID;
string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;
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
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<actividad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
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
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<actividad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
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
getline(token,actividad,';');
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<numID<<endl;
cout<<nombre<<" "<<apellido<<endl;
cout<<correo<<endl;
cout<<identidad<<endl;
cout<<actividad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";
    }
}

administradorArch.close();

if (!existe){
cout<<"No existe el Administrador "<<buscarID<<endl;
            }
        }

//system("pause");
system("read -p 'Press Enter to continue...' var");

    }

}while(opc != 0);

}





//Modificador de usuarios//
void modificarUsuarios(){


int opc;
int aux = 0;

do{


//sub menu administrado
if(userIdentity.compare("administrador")==0){

system("clear");
//system("cls");

aux = 0;
opc = 0;
cout<<"Escoja el tipo de persona a buscar"<<endl;
cout<<"1.Cliente"<<endl;
cout<<"2.Trabajador"<<endl;
cout<<"3.Administrador"<<endl;
cout<<"0.Atras"<<endl;
cin>>opc;

switch(opc){
    case 1:aux=1;break;
    case 2:aux=2;break;
    case 3:aux=3;break;
    case 0:aux=0;break;
    default:{  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

    }
}


//sub menu trabajador
if(userIdentity.compare("trabajador")==0){

system("clear");
//system("cls");

aux = 0;
opc = 0;
cout<<"Escoja el tipo de persona a buscar"<<endl;
cout<<"1.Cliente"<<endl;
cout<<"0.Atras"<<endl;
cin>>opc;

switch(opc){
    case 1:aux=1;break;
    case 0:aux=0;break;
    default:{  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

    }
}



system("clear");
//system("cls");



//cliente
if(aux == 1){

ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo 'archivoCliente.csv'"<<endl<<endl;
}
else{
vector<string>all_regist;

string buscarID;
bool existe = false;
bool modifico = false;
int opc = 0;
string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;
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
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<"Datos actuales del cliente a modificar::"<<endl<<endl;
cout<<"Numero de ID == "<<numID<<endl;
cout<<"1.Nombre == "<<nombre<<endl;
cout<<"2.Apellido == "<<apellido<<endl;
cout<<"3.Password == "<<password<<endl;
cout<<"4.Correo electronico == "<<correo<<endl;
cout<<"5.actividad == "<<actividad<<endl;
cout<<"0.Ninguno"<<endl;
cout<<"\n\n////////////////////////////////////\n\n";

    do{
        cout<<"Seleccione el campo a modificar: ";
        cin>>opc;


    }while(opc < 0 || opc > 5);

    fflush(stdin);
    switch(opc){

        case 1:{modifico = true;
        getline(cin, nombre);///////////////////Linux////////
                cout<<"ingrese el nuevo nombre: ";
                getline(cin, nombre);};break;

        case 2: {modifico = true;
        getline(cin, apellido);////////////////linux//////////////
                cout<<"ingrese el nuevo apellido: ";
                getline(cin, apellido);};break;

        case 3: {modifico = true;
        getline(cin, password);////////////////////linux//////////////
                cout<<"ingrese la nueva password: ";
                getline(cin, password);};break;

        case 4: {modifico = true;
        getline(cin, correo);//////////////////////////linux//////////////////
                cout<<"ingrese el nuevo correo: ";
                getline(cin, correo);};break;

        case 5: {modifico = true;
        bool aux=0;
        cout<<"ingres 1.[activo] 0.[inactivo]: ";
        cin>>aux;
        if(aux) actividad = "activa";
        else actividad = "inactiva";
                };break;


    }
    all_regist.push_back(numID+";" + nombre + ";" + apellido + ";" + password + ";" + correo + ";" + identidad +";" + actividad);

}

else{
all_regist.push_back(registro);
}

}

clienteArch.close();



    if (existe)/*if existe == true*/{
        if(modifico){
            ofstream nuevo("archivoCliente.csv");
            for(int i=0; i<int(all_regist.size()); i++){
                nuevo<<all_regist[i]<<endl;
            }

            nuevo.close();
            cout<<"\n\nSe modifico el cliente\n\n";

        }

    }
    else{
    cout<<"el cliente "<<buscarID<<" no esxiste en el archivo\n\n";
        }

    }

//system("pause");
system("read -p 'Press Enter to continue...' var");
}



//trabajador
if(aux == 2){

ifstream tabajadorArch("archivoTrabajador.csv", ios::in);
if(!tabajadorArch){
cout<<"error al abrir el archivo 'archivoTrabajador.csv'"<<endl<<endl;
}
else{
vector<string>all_regist;

string buscarID;
bool existe = false;
bool modifico = false;
int opc = 0;
string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;
cout<<"ingrese numero de ID a buscar: ";
cin>>buscarID;
cout<<"\n\n////////////////////////////////////\n\n";

while(getline(tabajadorArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<"Datos actuales del trabajador a modificar::"<<endl<<endl;
cout<<"Numero de ID == "<<numID<<endl;
cout<<"1.Nombre == "<<nombre<<endl;
cout<<"2.Apellido == "<<apellido<<endl;
cout<<"3.Password == "<<password<<endl;
cout<<"4.Correo electronico == "<<correo<<endl;
cout<<"5.actividad == "<<actividad<<endl;
cout<<"0.Ninguno"<<endl;
cout<<"\n\n////////////////////////////////////\n\n";

    do{
        cout<<"Seleccione el campo a modificar: ";
        cin>>opc;


    }while(opc < 0 || opc > 5);

    fflush(stdin);
    switch(opc){

        case 1:{modifico = true;
        getline(cin, nombre);///////////////////Linux////////
                cout<<"ingrese el nuevo nombre: ";
                getline(cin, nombre);};break;

        case 2: {modifico = true;
        getline(cin, apellido);////////////////linux//////////////
                cout<<"ingrese el nuevo apellido: ";
                getline(cin, apellido);};break;

        case 3: {modifico = true;
        getline(cin, password);////////////////////linux//////////////
                cout<<"ingrese la nueva password: ";
                getline(cin, password);};break;

        case 4: {modifico = true;
        getline(cin, correo);//////////////////////////linux//////////////////
                cout<<"ingrese el nuevo correo: ";
                getline(cin, correo);};break;

        case 5: {modifico = true;
        bool aux=0;
        cout<<"ingres 1.[activo] 0.[inactivo]: ";
        cin>>aux;
        if(aux) actividad = "activa";
        else actividad = "inactiva";
                };break;


    }
    all_regist.push_back(numID+";" + nombre + ";" + apellido + ";" + password + ";" + correo + ";" + identidad +";" + actividad);

}

else{
all_regist.push_back(registro);
}

}

tabajadorArch.close();



    if (existe)/*if existe == true*/{
        if(modifico){
            ofstream nuevo("archivoTrabajador.csv");
            for(int i=0; i<int(all_regist.size()); i++){
                nuevo<<all_regist[i]<<endl;
            }

            nuevo.close();
            cout<<"\n\nSe modifico el trabajador\n\n";

        }

    }
    else{
    cout<<"el trabajador "<<buscarID<<" no esxiste en el archivo\n\n";
        }

    }

//system("pause");
system("read -p 'Press Enter to continue...' var");

}



//administrador
if(aux == 3){


ifstream administradorArch("archivoAdminstrador.csv", ios::in);
if(!administradorArch){
cout<<"error al abrir el archivo 'archivoAdminstrador.csv'"<<endl<<endl;
}
else{
vector<string>all_regist;

string buscarID;
bool existe = false;
bool modifico = false;
int opc = 0;
string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;
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
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<"Datos actuales del Administrador a modificar::"<<endl<<endl;
cout<<"Numero de ID == "<<numID<<endl;
cout<<"1.Nombre == "<<nombre<<endl;
cout<<"2.Apellido == "<<apellido<<endl;
cout<<"3.Password == "<<password<<endl;
cout<<"4.Correo electronico == "<<correo<<endl;
cout<<"5.actividad == "<<actividad<<endl;
cout<<"0.Ninguno"<<endl;
cout<<"\n\n////////////////////////////////////\n\n";

    do{
        cout<<"Seleccione el campo a modificar: ";
        cin>>opc;


    }while(opc < 0 || opc > 5);

    fflush(stdin);
    switch(opc){

        case 1:{modifico = true;
        getline(cin, nombre);///////////////////Linux////////
                cout<<"ingrese el nuevo nombre: ";
                getline(cin, nombre);};break;

        case 2: {modifico = true;
        getline(cin, apellido);////////////////linux//////////////
                cout<<"ingrese el nuevo apellido: ";
                getline(cin, apellido);};break;

        case 3: {modifico = true;
        getline(cin, password);////////////////////linux//////////////
                cout<<"ingrese la nueva password: ";
                getline(cin, password);};break;

        case 4: {modifico = true;
        getline(cin, correo);//////////////////////////linux//////////////////
                cout<<"ingrese el nuevo correo: ";
                getline(cin, correo);};break;

        case 5: {modifico = true;
        bool aux=0;
        cout<<"ingres 1.[activo] 0.[inactivo]: ";
        cin>>aux;
        if(aux) actividad = "activa";
        else actividad = "inactiva";
                };break;


    }
    all_regist.push_back(numID+";" + nombre + ";" + apellido + ";" + password + ";" + correo + ";" + identidad +";" + actividad);

}

else{
all_regist.push_back(registro);
}

}

administradorArch.close();



    if (existe)/*if existe == true*/{
        if(modifico){
            ofstream nuevo("archivoAdminstrador.csv");
            for(int i=0; i<int(all_regist.size()); i++){
                nuevo<<all_regist[i]<<endl;
            }

            nuevo.close();
            cout<<"\n\nSe modifico el cliente\n\n";

        }

    }
    else{
    cout<<"el cliente "<<buscarID<<" no esxiste en el archivo\n\n";
        }

    }

//system("pause");
system("read -p 'Press Enter to continue...' var");

}

}while(opc != 0);
}





//eliminar usuarios//
void eliminarUsuarios(){

int opc;

do{

system("clear");
//system("cls");

int aux = 0;

//sub menu administrador
if(userIdentity.compare("administrador")==0){

opc = 0;
cout<<"Escoja el tipo de persona a buscar"<<endl;
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
    default:{  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

    }


}



system("clear");
//system("cls");



//cliente
if(aux==1){

ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo 'archivoCliente.csv'"<<endl<<endl;
}
else{
vector<string>regist_notDelete;


int opc = 0;
string buscarID;
bool existe = false;
string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;
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
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){

existe = true;
cout<<"Datos actuales del Cliente::"<<endl<<endl;
cout<<"Numero de ID == "<<numID<<endl;
cout<<"Nombre == "<<nombre<<endl;
cout<<"Apellido == "<<apellido<<endl;
cout<<"Password == "<<password<<endl;
cout<<"Correo electronico == "<<correo<<endl;
cout<<"Identidad == "<<identidad<<endl;
cout<<"actividad == "<<actividad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";

}

else regist_notDelete.push_back(registro);


}

clienteArch.close();



    if (existe)/*if existe == true*/{
        do{

            cout<<"ESTA SEGURO DE ELIMINAR LA CUENTA???  1.[si] 0.[no]"<<endl;
            cin>>opc;

                if(opc == 1){
                    ofstream nuevo("archivoCliente.csv");
                    for(int i=0; i<int(regist_notDelete.size()); i++){
                    nuevo<<regist_notDelete[i]<<endl;
                    }
                 nuevo.close();
                cout<<"\n\nSe Elimino el cliente\n\n";
                }

                else break;



    }while(opc < 0 || opc > 1);




    }
    else{
    cout<<"el cliente "<<buscarID<<" no esxiste en el archivo\n\n";
        }

    }

//system("pause");
system("read -p 'Press Enter to continue...' var");

}



//trabajador
if(aux==2){

ifstream trabajadorArch("archivoTrabajador.csv", ios::in);
if(!trabajadorArch){
cout<<"error al abrir el archivo 'archivoTrabajador.csv'"<<endl<<endl;
}
else{
vector<string>regist_notDelete;


int opc = 0;
string buscarID;
bool existe = false;
string registro;
string numID, nombre, apellido, password, correo, identidad, actividad;
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
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){

existe = true;
cout<<"Datos actuales del Trabajador::"<<endl<<endl;
cout<<"Numero de ID == "<<numID<<endl;
cout<<"Nombre == "<<nombre<<endl;
cout<<"Apellido == "<<apellido<<endl;
cout<<"Password == "<<password<<endl;
cout<<"Correo electronico == "<<correo<<endl;
cout<<"Identidad == "<<identidad<<endl;
cout<<"actividad == "<<actividad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";

}

else regist_notDelete.push_back(registro);


}

trabajadorArch.close();



    if (existe)/*if existe == true*/{
        do{

            cout<<"ESTA SEGURO DE ELIMINAR LA CUENTA???  1.[si] 0.[no]"<<endl;
            cin>>opc;

                if(opc == 1){
                    ofstream nuevo("archivoTrabajador.csv");
                    for(int i=0; i<int(regist_notDelete.size()); i++){
                    nuevo<<regist_notDelete[i]<<endl;
                    }
                 nuevo.close();
                cout<<"\n\nSe Elimino el trabajador\n\n";
                }

                else break;



    }while(opc < 0 || opc > 1);




    }
    else{
    cout<<"el trabajador "<<buscarID<<" no esxiste en el archivo\n\n";
        }

    }

//system("pause");
system("read -p 'Press Enter to continue...' var");

}



//administrador
if(aux==3){

ifstream administradorArch("archivoAdminstrador.csv", ios::in);
if(!administradorArch){
cout<<"error al abrir el archivo 'archivoAdminstrador.csv'"<<endl<<endl;
}
else{
vector<string>regist_notDelete;


int opc = 0;
string buscarID;
bool existe = false;
string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;
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
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){

existe = true;
cout<<"Datos actuales del Administrador::"<<endl<<endl;
cout<<"Numero de ID == "<<numID<<endl;
cout<<"Nombre == "<<nombre<<endl;
cout<<"Apellido == "<<apellido<<endl;
cout<<"Password == "<<password<<endl;
cout<<"Correo electronico == "<<correo<<endl;
cout<<"Identidad == "<<identidad<<endl;
cout<<"actividad == "<<actividad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";

}

else regist_notDelete.push_back(registro);


}

administradorArch.close();



    if (existe)/*if existe == true*/{
        do{

            cout<<"ESTA SEGURO DE ELIMINAR LA CUENTA???  1.[si] 0.[no]"<<endl;
            cin>>opc;

                if(opc == 1){
                    ofstream nuevo("archivoAdminstrador.csv");
                    for(int i=0; i<int(regist_notDelete.size()); i++){
                    nuevo<<regist_notDelete[i]<<endl;
                    }
                 nuevo.close();
                cout<<"\n\nSe Elimino el administrador\n\n";
                }

                else break;



    }while(opc < 0 || opc > 1);




    }
    else{
    cout<<"el administrador "<<buscarID<<" no esxiste en el archivo\n\n";
        }

    }

//system("pause");
system("read -p 'Press Enter to continue...' var");

}


}while(opc != 0);




}






//cambiar actividad de usuarios//
void cambiarActividad(){



int opc;

do{

system("clear");
//system("cls");

int aux = 0;


//sub menu Administrador
if(userIdentity.compare("administrador")==0){
aux = 0;
opc = 0;
cout<<"Desactivar o activar usuario por ID"<<endl;
cout<<"1.Cliente"<<endl;
cout<<"2.Trabajador"<<endl;
cout<<"3.Administrador"<<endl;
cout<<"0.Atras"<<endl;
cin>>opc;

switch(opc){
    case 1:aux=1;break;
    case 2:aux=2;break;
    case 3:aux=3;break;
    case 0:aux=0;break;
    default:{  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

    }

}



//sub menu trabajador
if(userIdentity.compare("trabajador")==0){
aux = 0;
opc = 0;
cout<<"Desactivar o activar usuario por ID"<<endl;
cout<<"1.Cliente"<<endl;
cout<<"0.Atras"<<endl;
cin>>opc;

switch(opc){
    case 1:aux=1;break;
    case 0:aux=0;break;
    default:{  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

    }

}



system("clear");
//system("cls");



//cliente
if(aux == 1){

ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo 'archivoCliente.csv'"<<endl<<endl;
}
else{
vector<string>all_regist;

string buscarID;
bool existe = false;
bool modifico = false;
int opc = 0;
string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;
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
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<"Datos actuales del cliente::"<<endl<<endl;
cout<<"Numero de ID == "<<numID<<endl;
cout<<"Nombre == "<<nombre<<endl;
cout<<"Apellido == "<<apellido<<endl;
cout<<"Password == "<<password<<endl;
cout<<"Correo electronico == "<<correo<<endl;
cout<<"actividad == "<<actividad<<endl;
cout<<"\n\n////////////////////////////////////\n\n";

    do{
        cout<<"DESEA CAMBIAR LA ACTIVIDAD DE LA CUENTA???\n\n";
        opc=1;

    }while(opc < 0 || opc > 1);

    fflush(stdin);
    switch(opc){

        case 1: {modifico = true;
        bool aux=0;
        cout<<"ingrese 1.[si] 0.[no]: ";
        cin>>aux;
        if(aux && actividad=="activa") actividad = "inactiva";
        else actividad = "activa";
                };break;


    }
    all_regist.push_back(numID+";" + nombre + ";" + apellido + ";" + password + ";" + correo + ";" + identidad +";" + actividad);

}

else{
all_regist.push_back(registro);
}

}

clienteArch.close();



    if (existe)/*if existe == true*/{
        if(modifico){
            ofstream nuevo("archivoCliente.csv");
            for(int i=0; i<int(all_regist.size()); i++){
                nuevo<<all_regist[i]<<endl;
            }

            nuevo.close();
            cout<<"\n\nSe modifico el cliente\n\n";

        }

    }
    else{
    cout<<"el cliente "<<buscarID<<" no esxiste en el archivo\n\n";
        }

    }

//system("pause");
system("read -p 'Press Enter to continue...' var");
}



//trabajador
if(aux == 2){

ifstream tabajadorArch("archivoTrabajador.csv", ios::in);
if(!tabajadorArch){
cout<<"error al abrir el archivo 'archivoTrabajador.csv'"<<endl<<endl;
}
else{
vector<string>all_regist;

string buscarID;
bool existe = false;
bool modifico = false;
int opc = 0;
string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;
cout<<"ingrese numero de ID a buscar: ";
cin>>buscarID;
cout<<"\n\n////////////////////////////////////\n\n";

while(getline(tabajadorArch, registro)){

stringstream token(registro);
getline(token,numID,';');
getline(token,nombre,';');
getline(token,apellido,';');
getline(token,password,';');
getline(token,correo,';');
getline(token,identidad,';');
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<"Datos actuales del trabajador a modificar::"<<endl<<endl;
cout<<"Numero de ID == "<<numID<<endl;
cout<<"1.Nombre == "<<nombre<<endl;
cout<<"2.Apellido == "<<apellido<<endl;
cout<<"3.Password == "<<password<<endl;
cout<<"4.Correo electronico == "<<correo<<endl;
cout<<"5.actividad == "<<actividad<<endl;
cout<<"0.Ninguno"<<endl;
cout<<"\n\n////////////////////////////////////\n\n";

    do{
        cout<<"Seleccione el campo a modificar: ";
        cin>>opc;


    }while(opc < 0 || opc > 5);

    fflush(stdin);
    switch(opc){

        case 1:{modifico = true;
        getline(cin, nombre);///////////////////Linux////////
                cout<<"ingrese el nuevo nombre: ";
                getline(cin, nombre);};break;

        case 2: {modifico = true;
        getline(cin, apellido);////////////////linux//////////////
                cout<<"ingrese el nuevo apellido: ";
                getline(cin, apellido);};break;

        case 3: {modifico = true;
        getline(cin, password);////////////////////linux//////////////
                cout<<"ingrese la nueva password: ";
                getline(cin, password);};break;

        case 4: {modifico = true;
        getline(cin, correo);//////////////////////////linux//////////////////
                cout<<"ingrese el nuevo correo: ";
                getline(cin, correo);};break;

        case 5: {modifico = true;
        bool aux=0;
        cout<<"ingres 1.[activo] 0.[inactivo]: ";
        cin>>aux;
        if(aux && actividad=="activa") actividad = "inactiva";
        else actividad = "activa";
                };break;


    }
    all_regist.push_back(numID+";" + nombre + ";" + apellido + ";" + password + ";" + correo + ";" + identidad +";" + actividad);

}

else{
all_regist.push_back(registro);
}

}

tabajadorArch.close();



    if (existe)/*if existe == true*/{
        if(modifico){
            ofstream nuevo("archivoTrabajador.csv");
            for(int i=0; i<int(all_regist.size()); i++){
                nuevo<<all_regist[i]<<endl;
            }

            nuevo.close();
            cout<<"\n\nSe modifico el trabajador\n\n";

        }

    }
    else{
    cout<<"el trabajador "<<buscarID<<" no esxiste en el archivo\n\n";
        }

    }

//system("pause");
system("read -p 'Press Enter to continue...' var");

}



//administrador
if(aux == 3){


ifstream administradorArch("archivoAdminstrador.csv", ios::in);
if(!administradorArch){
cout<<"error al abrir el archivo 'archivoAdminstrador.csv'"<<endl<<endl;
}
else{
vector<string>all_regist;

string buscarID;
bool existe = false;
bool modifico = false;
int opc = 0;
string registro;
string numID, nombre, apellido, password, correo, identidad,actividad;
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
getline(token,actividad,';');

if(buscarID.compare(numID) == 0 ){
existe = true;
cout<<"Datos actuales del Administrador a modificar::"<<endl<<endl;
cout<<"Numero de ID == "<<numID<<endl;
cout<<"1.Nombre == "<<nombre<<endl;
cout<<"2.Apellido == "<<apellido<<endl;
cout<<"3.Password == "<<password<<endl;
cout<<"4.Correo electronico == "<<correo<<endl;
cout<<"5.actividad == "<<actividad<<endl;
cout<<"0.Ninguno"<<endl;
cout<<"\n\n////////////////////////////////////\n\n";

    do{
        cout<<"Seleccione el campo a modificar: ";
        cin>>opc;


    }while(opc < 0 || opc > 5);

    fflush(stdin);
    switch(opc){

        case 1:{modifico = true;
        getline(cin, nombre);///////////////////Linux////////
                cout<<"ingrese el nuevo nombre: ";
                getline(cin, nombre);};break;

        case 2: {modifico = true;
        getline(cin, apellido);////////////////linux//////////////
                cout<<"ingrese el nuevo apellido: ";
                getline(cin, apellido);};break;

        case 3: {modifico = true;
        getline(cin, password);////////////////////linux//////////////
                cout<<"ingrese la nueva password: ";
                getline(cin, password);};break;

        case 4: {modifico = true;
        getline(cin, correo);//////////////////////////linux//////////////////
                cout<<"ingrese el nuevo correo: ";
                getline(cin, correo);};break;

        case 5: {modifico = true;
        bool aux=0;
        cout<<"ingres 1.[activo] 0.[inactivo]: ";
        cin>>aux;
        if(aux && actividad=="activa") actividad = "inactiva";
        else actividad = "activa";
                };break;


    }
    all_regist.push_back(numID+";" + nombre + ";" + apellido + ";" + password + ";" + correo + ";" + identidad +";" + actividad);

}

else{
all_regist.push_back(registro);
}

}

administradorArch.close();



    if (existe)/*if existe == true*/{
        if(modifico){
            ofstream nuevo("archivoAdminstrador.csv");
            for(int i=0; i<int(all_regist.size()); i++){
                nuevo<<all_regist[i]<<endl;
            }

            nuevo.close();
            cout<<"\n\nSe modifico el cliente\n\n";

        }

    }
    else{
    cout<<"el cliente "<<buscarID<<" no esxiste en el archivo\n\n";
        }

    }

//system("pause");
system("read -p 'Press Enter to continue...' var");

}

}while(opc != 0);

}
















//lista de PQRS con contador//
void listaPQRS(){

}
//buscar PQRS con contador//
void buscarPQRS(){

}
//Agregar $$ a cuenta de cliente//
//restar $$ a cuenta de cliente//


//revisar PQRS; Eliminar personas;











///ACCESO CLIENTE///
//menu//
void menuCli(){

}
//Generador de PQRS//
void generalPQRS(){

}
//agregar $$ a la cuenta//










void menuTrab(){

int opc;

do{
system("clear");
//system("cls");
cout<<"Bienvenido "<<userName<<endl;
cout<<"Menu de opciones"<<endl;
cout<<"1.Crear nuevas personas"<<endl;
cout<<"2.Listado general"<<endl;
cout<<"3.Buscar por ID"<<endl;
cout<<"4.Modificar usuario"<<endl;
cout<<"5.Eliminar usuario"<<endl;
cout<<"Mi cuenta(construccion)"<<endl;
cout<<"0.Salir"<<endl;
cin>>opc;
switch(opc){
case 1: generarArchivos();break;
case 2: listadoGeneral();break;
case 3: buscarXid();break;
case 4: modificarUsuarios();break;
case 5: cambiarActividad();break;
case 0: break;
default: {  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}
}

system("clear");
//system("cls");
}while(opc !=0 );

}






int main()
{
//generarArchivos();
login();
return 0;
}











