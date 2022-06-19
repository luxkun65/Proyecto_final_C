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
string loginID_Nombre, loginpassword;
bool existe = false;
int opc;
string registro;
string numID, nombre, apellido, password, correo, identidad;
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



        if(((loginID_Nombre.compare(numID) == 0)||(loginID_Nombre.compare(nombre) == 0))&&(loginpassword.compare(password)==0)){

            existe = true;
            system("read -p 'Press Enter to continue...' var");
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

        if(((loginID_Nombre.compare(numID) == 0)||(loginID_Nombre.compare(nombre) == 0))&&(loginpassword.compare(password)==0)){
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

        if(((loginID_Nombre.compare(numID) == 0)||(loginID_Nombre.compare(nombre) == 0))&&(loginpassword.compare(password)==0)){
            nombreusuario=nombre ;
            idusuario = numID;
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



//se crea un switch para seguir o salir del programa
do{
system("clear");
//system("cls");

cout<<"Desea salir o logearse nuevamente?"<<endl;
cout<<"1.Logearse"<<endl;
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
cout<<"4.Modificar cliente por ID"<<endl;
cout<<"5.Eliminar cliente por ID"<<endl;
cout<<"0.Salir"<<endl;
cin>>opc;
switch(opc){
case 1: generarArchivos();break;
case 2: listadoGeneral();break;
case 3: buscarXid();break;
case 4: modificarUsuarios();break;
case 5: eliminarUsuarios();break;
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
    default: {  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

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

do{

system("clear");
//system("cls");

int aux = 0;
int cont = 0;
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
    default:{  cout<<"Opcion incorrecta"<<endl;
            //system("pause");
            system("read -p 'Press Enter to continue...' var");}

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
system("clear");
//system("cls");


ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo 'archivoCliente.csv'"<<endl<<endl;
}
else{
vector<string>all_regist_cli;

string buscarID;
bool existe = false;
bool modifico = false;
int opc = 0;
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
cout<<"Datos actuales del cliente a modificar::"<<endl<<endl;
cout<<"Numero de ID == "<<numID<<endl;
cout<<"1.Nombre == "<<nombre<<endl;
cout<<"2.Apellido == "<<apellido<<endl;
cout<<"3.Password == "<<password<<endl;
cout<<"4.Correo electronico == "<<correo<<endl;
cout<<"5.Identidad == "<<identidad<<endl;
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
        getline(cin, identidad);////////////////////linux//////////////
                cout<<"ingrese el nuevo identidad: ";
                getline(cin, identidad);};break;

    }
    all_regist_cli.push_back(numID+";" + nombre + ";" + apellido + ";" + password + ";" + correo + ";" + identidad);

}

else{
all_regist_cli.push_back(registro);
}

}

clienteArch.close();



    if (existe)/*if existe == true*/{
        if(modifico){
            ofstream nuevo("archivoCliente.csv");
            for(int i=0; i<int(all_regist_cli.size()); i++){
                nuevo<<all_regist_cli[i]<<endl;
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








//eliminar usuarios//
void eliminarUsuarios(){
system("clear");
//system("cls");


ifstream clienteArch("archivoCliente.csv", ios::in);
if(!clienteArch){
cout<<"error al abrir el archivo 'archivoCliente.csv'"<<endl<<endl;
}
else{
vector<string>regist_cli_notDelete;


int opc = 0;
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

if(buscarID.compare(numID) == 0 ) existe = true;

else regist_cli_notDelete.push_back(registro);


}

clienteArch.close();



    if (existe)/*if existe == true*/{
        do{

            cout<<"ESTA SEGURO DE ELIMINAR LA CUENTA???  1.[si] 0.[no]"<<endl;
            cin>>opc;

                if(opc == 1){
                    ofstream nuevo("archivoCliente.csv");
                    for(int i=0; i<int(regist_cli_notDelete.size()); i++){
                    nuevo<<regist_cli_notDelete[i]<<endl;
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






int main()
{
login();
return 0;
}











