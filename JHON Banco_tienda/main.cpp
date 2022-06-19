#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<bits/stdc++.h>
#include"Persona.h"
#include"Administrador.h"
#include"Trabajador.h"
#include"Cliente.h"
#include"Articulo.h"
#include"Prestamo.h"
#include"PQRS.h"
using namespace::std;

///general///
void login();
void sign_up();
vector<Prestamo> vecPrestamos;
vector<PQRS> vecPQRS;
///Cliente///
void menuCli(Cliente&);
void compra(Cliente&);
void verCarritoCompras(vector<Articulo>&, Cliente&);
void menuFruver(vector<Articulo>&);
void menuAgranel(vector<Articulo>&);
void menuEnlatados(vector<Articulo>&);
void menuLacteos(vector<Articulo>&);
void menuCarnes(vector<Articulo>&);
void ingresoProducto(string, string, double, vector<Articulo>&);
void modificarCliente(Cliente&);
void recargaCuenta(Cliente&);
void pagarDeuda(Cliente&);
void borrarCuenta(Cliente&);
void pedirPrestamo(Cliente&);
void generaPQRS(Cliente&);
///Prototipo
void protoTrabajador();
void revisaPrestamos();
void actualizaDeuda(double);
void revisaPQRS();



////////la otra parte del codigo//////


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
    string numID, username, password, correo, membresia, saldo, descuento, deuda, activo;
    fflush(stdin);
    cout<<"ingrese su nombre de usuario: ";
    getline(cin,logUsername);
    fflush(stdin);
    cout<<"ingrese su password: ";
    getline(cin,logPassword);

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
            getline(token,deuda,';');
            getline(token,activo,';');

            if(((logUsername.compare(username) == 0))&&(logPassword.compare(password)==0)&&(activo=="1")){
                existe = true;
                Cliente cli(registro);
                menuCli(cli);
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
    Cliente cli;
    ofstream clienteArch("archivoCliente.csv", ios::app);
    if(!clienteArch){
        cout<<"Error al crear el archivo 'archivoCliente.csv'"<<endl;
    }else{
        cli.setNumID();
        cli.setNombre();
        cli.setApellido();
        cli.setPassword();
        cli.setCorreo();

        clienteArch<<cli.toCSV()<<endl;
        clienteArch.close();

        cout<<"\n\nUsuario creado exitosamente\n\n";
        cout<<"Su informacion de usuario: "<<endl;
        cout<<cli.toString();
        system("pause");
    }
}












///Acciones
//Pedir un prestamo
void pedirPrestamo(Cliente &cli){
    double presta;
    system("cls");
    cout<<"Puedes pedir prestamos a nuestra entidad bancaria si eres un cliente con membresia Intermedio o superior"<<endl;
    if(cli.getMembresia() == "Basico"){
        cout<<"Tu membresia es de tipo Basico, no puedes pedir prestamos a nuestra entidad"<<endl;
        cout<<"Contacta con uno de nuestros administradores para cambiar tu membresia"<<endl;
        system("pause");
        return;
    }
    cout<<"Recuerda que si tu prestamo es aceptado depende de nuestros empleados y administradores"<<endl;
    cout<<"Ingresa la cantidad que deseas prestar de nuestra entidad, presiona 0 para salir"<<endl;
    cout<<"Prestamo: ";
    cin>>presta;
    if(presta == 0)return;
    Prestamo pre(cli, presta);
    vecPrestamos.push_back(pre);
    cout<<"......."<<endl;
    cout<<"Gracias por preferirnos, pronto recibira su respuesta"<<endl;
    system("pause");
}
//Realizar un PQRS
void generaPQRS(Cliente &cli){
    string mensaje;
    system("cls");
    cout<<"Puedes depositar toda Pregunta, Queja, Reclamo o Sugerencia aqui, con gusto te atenderemos."<<endl;
    cout<<"Ingresa tu mensaje o presiona 0 para salir"<<endl;
    cout<<"Mensaje: ";
    fflush(stdin);
    getline(cin, mensaje);
    if(mensaje == "0")return;
    PQRS pqrs(cli, mensaje);
    vecPQRS.push_back(pqrs);
    cout<<"......."<<endl;
    cout<<"Mensaje entregado"<<endl;
    system("pause");
}
//Modificar cuenta cliente
void modificarCliente(Cliente &cli){
    ifstream clienteArch("archivoCliente.csv", ios::in);
    string logUsername;
    long id;
    string registro;
    string numID, username, password, correo, membresia, saldo, descuento, deuda, activo;
    logUsername = cli.getNombreUsuario();
    id = cli.getNumID();

    //se comprueba si el archivo cliente esta creado
    if(!clienteArch){
        cout<<"error al abrir el archivo"<<endl<<endl;
        }
    //se busca y compara el username y el id de cliente
    else{
        vector<string> all_clientes;
        while(getline(clienteArch, registro)){
            stringstream token(registro);
            getline(token,numID,';');
            getline(token,username,';');
            getline(token,password,';');
            getline(token,correo,';');
            getline(token,membresia,';');
            getline(token,saldo,';');
            getline(token,descuento,';');
            getline(token,deuda,';');
            getline(token,activo,';');

            if(((logUsername.compare(username) == 0))&&(to_string(id).compare(numID)==0)){
                all_clientes.push_back(numID + ";" + username + ";"
                                       + password + ";" + correo + ";" + membresia
                                       + ";" + to_string(cli.getSaldo()) + ";" + descuento
                                       + ";" + to_string(cli.getDeuda()) + ";" +
                                       to_string(cli.getActivo()));
            }else{
                all_clientes.push_back(registro);
            }
        }
    clienteArch.close();
    ofstream nuevo("archivoCliente.csv");
    if(!nuevo){
        cout<<"Ha ocurrido un error al actualizar el cliente"<<endl;
    }else{
        for(int i = 0; i<int(all_clientes.size()); i++){
            nuevo<<all_clientes[i]<<endl;
            }
            nuevo.close();
        }
    }

}
//Recargar saldo de la cuenta
void recargaCuenta(Cliente &cli){
    system("cls");
    double recarga;
    cout<<"Bienvenido "+ cli.getNombreUsuario() + "!"<<endl;
    cout<<"El saldo actual de tu cuenta es de: " + to_string(cli.getSaldo())<<endl;
    cout<<"Ingrese la cantidad de dinero a recargar o presiona 0 para salir "<<endl;
    cout<<"Recarga: ";
    cin>>recarga;
    if(recarga == 0)return;
    cli.setSaldo(recarga);
    modificarCliente(cli);
    cout<<"Recarga exitosa"<<endl;
    system("pause");
}
//Pagar deuda del cliente
void pagarDeuda(Cliente &cli){
    system("cls");
    if(cli.getDeuda() == 0){
        cout<<"No tienes deudas pendientes"<<endl;
        system("pause");
        return;
    }
    double pago;
    double resto;
    cout<<"Bienvenido "+ cli.getNombreUsuario() + "!"<<endl;
    cout<<"El saldo actual de tu cuenta es de: " + to_string(cli.getSaldo())<<endl;
    cout<<"La deuda actual de tu cuenta es de: " + to_string(cli.getDeuda())<<endl;
    cout<<"Ingrese la cantidad de dinero a pagar o presiona 0 para salir "<<endl;
    cout<<"Cancela: ";
    cin>>pago;
    if(pago == 0)return;
    if(pago > cli.getSaldo()){
        cout<<"La cantidad a pagar sobrepasa su cartera, salga e intentelo nuevamente"<<endl;
        system("pause");
        return;
    }
    cli.setGasto(pago);
    resto = cli.getDeuda() - pago;
    if(resto < 0){
        cli.setSaldo(resto*-1);
        cli.setDeuda(0);
    }
    else cli.setDeuda(resto);
    modificarCliente(cli);
    cout<<"Pago exitoso"<<endl;
    system("pause");
}
//Eliminar la cuenta del cliente
void borrarCuenta(Cliente &cli){
    system("cls");
    int opc;
    do{
        cout<<"Esta usted seguro de esta decision? \n No podra logearse de nuevo con esta cuenta"<<endl;
        cout<<"[1-Si]    [0-No]\n";
        cin>>opc;
        switch(opc){
            case 1:cli.setActivo(false);modificarCliente(cli);break;
            case 0:break;
            default: cout<<"Opcion incorrecta."<<endl;
        }
    }while((opc != 0 )&&(opc != 1));
    system("pause");
}













//Ingreso de productos
void ingresoProducto(string nom, string cal, double precio, vector<Articulo> &car){
    int cant;
    cout<<"Ingrese cantidad a comprar: ";
    cin>>cant;
    Articulo art(nom, cal, cant, precio);
    car.push_back(art);
}
//Ver carrito de compras
void verCarritoCompras(vector<Articulo> &car, Cliente &cli){
    int opc;
    long cantTotal = 0;
    double costoSubTotal = 0;
    double costoTotal = 0;
    system("cls");
    if(car.size() < 1){
        cout<<"No hay elementos en el carrito"<<endl;
        system("pause");
        return;
    }else{
        for(int i = 0; i<car.size(); i++){
            cout<<car[i].toString()<<endl;
            cantTotal += car[i].getCantidad();
            costoSubTotal += car[i].getTotal();
        }
        costoTotal = costoSubTotal - (costoSubTotal/100 * cli.getDescuento());
    }
    cout<<"La cantidad total de productos es de: "<<cantTotal<<endl;
    cout<<"Costo subtotal del carrito: "<<costoSubTotal<<endl;
    cout<<"Descuento: "<<cli.getDescuento()<<"%"<<endl;
    cout<<"Costo total: "<<costoTotal<<endl;
    cout<<"Saldo: "<<cli.getSaldo()<<endl;
    if(costoTotal > cli.getSaldo()){
        cout<<"Parece ser que tu saldo no es suficiente para comprar todos tus productos"<<endl;
    }else{
        do{
            cout<<"Desea realizar compra? \n[1-Si]   [0-No]\n";
            cin>>opc;
            switch(opc){
                case 1:cli.setGasto(costoTotal); modificarCliente(cli);break;
                case 0:break;
                default: cout<<"Opcion incorrecta, vuelve a intentarlo"<<endl;
            }
        }while((opc != 0)&&(opc != 1));
    }
    system("pause");
}
//Visitar Fruver
void menuFruver(vector<Articulo> &car){
    int opc;
    do{
        system("cls");
        cout<<"Fruver te presenta: \n"<<
            "0. Salir de Fruver\n"<<
            "1. Manzanas, calidad: buena, unidad: $800 \n"<<
            "2. Peras, calidad: buena, unidad: $700 \n"<<
            "3. Pinas, calidad: buena, unidad: $1000 \n"<<
            "4. Cebolla larga, calidad: muy buena, lb: $1200 \n"<<
            "5. Cebolla huevo, calidad: excelente, lb: $1500 \n"<<
            "6. Yuca, calidad: excelente, lb: $1000 \n"<<
            "7. Platano verde, calidad: buena, lb: $1500 \n" <<
            "8. Platano maduro, calidad: buena, lb: $1500 \n" <<
            "9. Maiz dulce, calidad: muy buena, bandeja: $3500 \n" <<
            "10. Maiz blanco, calidad: muy buena, bandeja: $3000 \n";
        cout<<"Ingrese seleccion: ";
        cin>>opc;
        switch(opc){
            case 1: ingresoProducto("Manzana", "Buena", 800, car);break;
            case 2: ingresoProducto("Pera", "Buena", 700, car);break;
            case 3: ingresoProducto("Pina", "Buena", 1000, car);break;
            case 4: ingresoProducto("Cebolla larga", "Muy buena", 1200,car);break;
            case 5: ingresoProducto("Cebolla huevo", "Excelente", 1500,car);break;
            case 6: ingresoProducto("Yuca", "Excelente", 1000,car);break;
            case 7: ingresoProducto("Platano verde", "Buena", 1500,car);break;
            case 8: ingresoProducto("Platano maduro", "Buena", 1500,car);break;
            case 9: ingresoProducto("Maiz dulce", "Muy buena", 3500,car);break;
            case 10: ingresoProducto("Maiz blanco", "Muy buena", 3000,car);break;
            case 0: break;
        }
    }while(opc != 0);
}
//Visitar Agranel
void menuAgranel(vector<Articulo> &car){
    int opc;
    do{
        system("cls");
        cout<<"Agranel te presenta: \n"<<
            "0. Salir de Agranel\n"<<
            "1. Arroz, calidad: buena, lb: $1000 \n"<<
            "2. Lentejas, calidad: buena, lb: $1200 \n"<<
            "3. Arvejas, calidad: buena, lb: $1000 \n"<<
            "4. Frijoles larga, calidad: muy buena, lb: $1500 \n"<<
            "5. Habichuela , calidad: excelente, lb: $1500 \n";
        cout<<"Ingrese seleccion: ";
        cin>>opc;
        switch(opc){
            case 1: ingresoProducto("Arroz", "Buena", 1000, car);break;
            case 2: ingresoProducto("Lentejas", "Buena", 1200, car);break;
            case 3: ingresoProducto("Arvejas", "Buena", 1000, car);break;
            case 4: ingresoProducto("Frijoles", "Muy buena", 1500,car);break;
            case 5: ingresoProducto("Habichuela", "Excelente", 1500,car);break;
            case 0: break;
        }
    }while(opc != 0);
}
//visitar Enlatados
void menuEnlatados(vector<Articulo> &car){
    int opc;
    do{
        system("cls");
        cout<<"Enlatados te presenta: \n"<<
            "0. Salir de Enlatados\n"<<
            "1. Atun, calidad: excelente, unidad: $3800 \n"<<
            "2. Sardinas, calidad: muy buena, unidad: $3700 \n"<<
            "3. Comida_Perros, calidad: buena, unidad: $2500 \n"<<
            "4. Comida_Gatos, calidad: muy buena, unidad: $2300 \n";
        cout<<"Ingrese seleccion: ";
        cin>>opc;
        switch(opc){
            case 1: ingresoProducto("Atun", "Excelente", 3800, car);break;
            case 2: ingresoProducto("Sardinas", "Muy buena", 3700, car);break;
            case 3: ingresoProducto("Comida_Perros", "Buena", 2500, car);break;
            case 4: ingresoProducto("Comida_Gatos", "Muy buena", 2300,car);break;
            case 0: break;
        }
    }while(opc != 0);
}
//Visitar Lacteos
void menuLacteos(vector<Articulo> &car){
    int opc;
    do{
        system("cls");
        cout<<"Lacteos te presenta: \n"<<
            "0. Salir de Lacteos\n"<<
            "1. Leche entera, calidad: buena, unidad: $4800 \n"<<
            "2. Leche deslactosada, calidad: buena, unidad: $4700 \n"<<
            "3. Leche en polvo, calidad: buena, unidad: $4000 \n"<<
            "4. Leche condensada, calidad: muy buena, unidad: $2500 \n"<<
            "5. Queso uajada, calidad: excelente, lb: $3500 \n"<<
            "6. Queso campesino, calidad: excelente, lb: $5000 \n";
        cout<<"Ingrese seleccion: ";
        cin>>opc;
        switch(opc){
            case 1: ingresoProducto("Leche entera", "Buena", 4800, car);break;
            case 2: ingresoProducto("Leche deslactosada", "Buena", 4700, car);break;
            case 3: ingresoProducto("Leche en polvo", "Buena", 4000, car);break;
            case 4: ingresoProducto("Leche condensada", "Muy buena", 2500,car);break;
            case 5: ingresoProducto("Queso cuajada", "Excelente", 3500,car);break;
            case 6: ingresoProducto("Queso campesino", "Excelente", 5000,car);break;
            case 0: break;
        }
    }while(opc != 0);
}
//Visitar Carnes
void menuCarnes(vector<Articulo> &car){
    int opc;
    do{
        system("cls");
        cout<<"Carnes te presenta: \n"<<
            "0. Salir de Carnes\n"<<
            "1. Brazo de cerdo, calidad: buena, lb: $8000 \n"<<
            "2. Pierna de cerdo, calidad: buena, lb: $7000 \n"<<
            "3. Costilla de res, calidad: buena, lb: $7000 \n"<<
            "4. Costilla de cerdo larga, calidad: muy buena, lb: $9000 \n"<<
            "5. Tocineta, calidad: excelente, lb: $10000 \n"<<
            "6. Chorizo, calidad: excelente, lb: $8000 \n"<<
            "7. Punta de anca, calidad: buena, lb: $15000 \n" <<
            "8. Lomo, calidad: buena, lb: $12000 \n";
        cout<<"Ingrese seleccion: ";
        cin>>opc;
        switch(opc){
            case 1: ingresoProducto("Brazo de cerdo", "Buena", 8000, car);break;
            case 2: ingresoProducto("Pierna de cerdo", "Buena", 7000, car);break;
            case 3: ingresoProducto("Costilla de res", "Buena", 7000, car);break;
            case 4: ingresoProducto("Costilla de cerdo larga", "Muy buena", 9000,car);break;
            case 5: ingresoProducto("Tocineta", "Excelente", 10000,car);break;
            case 6: ingresoProducto("Chorizo", "Excelente", 8000,car);break;
            case 7: ingresoProducto("Punta de anca", "Buena", 15000,car);break;
            case 8: ingresoProducto("Lomo", "Buena", 12000,car);break;
            case 0: break;
        }
    }while(opc != 0);
}
//Compra de productos
void compra(Cliente &cli){
    vector<Articulo> carrito;
    int opc;
    do{
        system("cls");
        cout<<cli.getNombreUsuario()<<"  #"<<cli.getNumID()<<endl;
        cout<<"Saldo: " + to_string(cli.getSaldo())<<"    Deuda: " + to_string(cli.getDeuda())<<endl;
        cout<<"Por cada una de tus compras, recibe un descuento del "<<cli.getDescuento()<<"% \n";
        cout<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"1. Ver carrito de compras"<<endl;
        cout<<"2. Comprar fruver"<<endl;
        cout<<"3. Comprar agranel"<<endl;
        cout<<"4. Comprar enlatados"<<endl;
        cout<<"5. Comprar lacteos"<<endl;
        cout<<"6. Comprar carnes"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese su seleccion: ";
        cin>>opc;
        switch(opc){
            case 1: verCarritoCompras(carrito, cli);break;
            case 2: menuFruver(carrito);break;
            case 3: menuAgranel(carrito);break;
            case 4: menuEnlatados(carrito);break;
            case 5: menuLacteos(carrito);break;
            case 6: menuCarnes(carrito);break;
            case 0: break;
            default: cout<<"Opcion incorrecta"<<endl; system("pause");
        }

    }while(opc != 0);
}

///ACCESO CLIENTE///
//menu//
void menuCli(Cliente &client){
    int opc;
    do{
        system("cls");
        cout<<"Bienvenido " + client.getNombreUsuario() + "!\n";
        cout<<"Ingrese a continuacion lo que desea hacer hoy: "<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"1. Comprar."<<endl;
        cout<<"2. Pedir un prestamo."<<endl;
        cout<<"3. Realizar una peticion, queja, reclamo o sugerencia."<<endl;
        cout<<"4. Recargar cuenta."<<endl;
        cout<<"5. Pagar deuda."<<endl;
        cout<<"6. Eliminar cuenta"<<endl;
        cout<<"0. Cerrar sesion."<<endl;
        cout<<"Opcion: ";
        cin>>opc;
        switch(opc){
            case 1:compra(client);break;
            case 2:pedirPrestamo(client);break;
            case 3: generaPQRS(client);break;
            case 4: recargaCuenta(client);break;
            case 5: pagarDeuda(client);break;
            case 6: borrarCuenta(client);break;
            case 0: break;
            default: cout<<"Opcion incorrecta"<<endl; system("pause");
        }
    }while(opc != 0);
}

///PROTOTIPO TRABAJADOR
void actualizaDeuda(double pres){
    ifstream clienteArch("archivoCliente.csv", ios::in);
    string logUsername;
    long id;
    string registro;
    double new_saldo = vecPrestamos[0].getSaldo() + pres;
    double new_deuda = vecPrestamos[0].getDeuda() + pres;
    string numID, username, password, correo, membresia, saldo, descuento, deuda, activo;
    logUsername = vecPrestamos[0].getNombreUsuario();
    id = vecPrestamos[0].getNumID();

    //se comprueba si el archivo cliente esta creado
    if(!clienteArch){
        cout<<"error al abrir el archivo"<<endl<<endl;
        }
    //se busca y compara el username y el id de cliente
    else{
        vector<string> all_clientes;
        while(getline(clienteArch, registro)){
            stringstream token(registro);
            getline(token,numID,';');
            getline(token,username,';');
            getline(token,password,';');
            getline(token,correo,';');
            getline(token,membresia,';');
            getline(token,saldo,';');
            getline(token,descuento,';');
            getline(token,deuda,';');
            getline(token,activo,';');

            if(((logUsername.compare(username) == 0))&&(to_string(id).compare(numID)==0)&&activo=="1"){
                all_clientes.push_back(numID + ";" + username + ";"
                                       + password + ";" + correo + ";" + membresia
                                       + ";" + to_string(new_saldo) + ";" + descuento
                                       + ";" + to_string(new_deuda) + ";" + activo);
            }else{
                all_clientes.push_back(registro);
            }
        }
    clienteArch.close();
    ofstream nuevo("archivoCliente.csv");
    if(!nuevo){
        cout<<"Ha ocurrido un error al actualizar el cliente"<<endl;
    }else{
        for(int i = 0; i<int(all_clientes.size()); i++){
            nuevo<<all_clientes[i]<<endl;
            }
            nuevo.close();
        }
    }

}


void revisaPrestamos(){

    int cantidad;
    cantidad = vecPrestamos.size();
    system("cls");
    if(cantidad < 1){
        cout<<"No hay peticiones actualmente"<<endl;
        system("pause");
        return;
    }
    for(int i = 0; i<cantidad; i++){
        int opc;
        system("cls");
        cout<<"Estas son las peticiones al dia de hoy"<<endl;
        cout<<"Peticion #"<<i+1<<"/"<<cantidad<<endl;
        cout<<vecPrestamos[0].toString()<<endl;
        double pres = vecPrestamos[0].getPrestamo();
        do{
            cout<<"Desea aceptar este prestamo?"<<endl;
            cout<<"1. Aceptar"<<endl;
            cout<<"2. Rechazar"<<endl;
            cout<<"0. Salir"<<endl;
            cout<<"Decision: ";
            cin>>opc;
            switch(opc){
                case 1: actualizaDeuda(pres);vecPrestamos.erase(vecPrestamos.begin());break;
                case 2: vecPrestamos.erase(vecPrestamos.begin());break;
                case 0: return;
                default: cout<<"Opcion Incorrecta"<<endl;system("pause");
            }
        }while(opc < 0 && opc > 2);
    }
}
void revisaPQRS(){
    int cantidad;
    cantidad = vecPQRS.size();
    system("cls");
    if(cantidad < 1){
        cout<<"No hay PQRS actualmente"<<endl;
        system("pause");
        return;
    }
    for(int i = 0; i<cantidad; i++){
        int opc;
        system("cls");
        cout<<"Estas son las PQRS al dia de hoy"<<endl;
        cout<<"PQRS #"<<i+1<<"/"<<cantidad<<endl;
        cout<<vecPQRS[0].toString()<<endl;
        do{
            cout<<"Que desea hacer con este PQRS?"<<endl;
            cout<<"1. Eliminar"<<endl;
            cout<<"0. Salir"<<endl;
            cout<<"Decision: ";
            cin>>opc;
            switch(opc){
                case 1: vecPQRS.erase(vecPQRS.begin());break;
                case 0: return;
                default: cout<<"Opcion Incorrecta"<<endl;system("pause");
            }
        }while(opc < 0 && opc > 1);
    }
}

void protoTrabajador(){
    int opc;
    do{
        system("cls");
        cout<<"Bienvenido empleado, por favor elige una opcion: "<<endl;
        cout<<"1. Revisa y acepta peticiones de Prestamos \n";
        cout<<"2. Revisa PQRS\n";
        cout<<"0. Salir\n";
        cout<<"Eleccion: ";
        cin>>opc;
        switch(opc){
            case 1: revisaPrestamos();break;
            case 2: revisaPQRS();break;
            case 0: break;
            default: cout<<"Opcion incorrecta"<<endl;system("pause");
        }
    }while(opc != 0);
}
///ACCESO GENERAL
void menu(){
    int opc;
    do{
        system("cls");
        cout<<"Bienvenido a BANCO_TIENDA"<<endl;
        cout<<"Ingrese a continuacion la accion a ejecutar: "<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"1. Registrarse."<<endl;
        cout<<"2. Iniciar sesion"<<endl;
        cout<<"3. PROTOTIPO TRABAJADOR"<<endl;
        cout<<"0. Salir de la aplicacion"<<endl;
        cout<<"Opcion: ";
        cin>>opc;
        switch(opc){
            case 1: sign_up();break;
            case 2: login();break;
            case 3: protoTrabajador();break;
            case 0: break;
            default: cout<<"Opcion incorrecta"<<endl; system("pause");
        }
    }while(opc != 0);
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





///Acceso de Admin///
//menu//
void menuAdmin(){

int opc;

do{

system("cls");
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
            system("pause");
            }
}


system("cls");
}while(opc !=0 );


}



//Generador de usuarios//
void generarArchivos(){

int opc;

do{


system("cls");

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
            system("pause");
            }

    }


system("cls");



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


        clienteArch<<cli.toString()<<endl;

        clienteArch.close();

        cout<<"\n\nse ingreso correctamente el cliente\n\n";
        }

        else{
        cout<<"El cliente con numero de ID "<<cli.getNumID()<<" ya existe\n\n";
        clienteArch.close();
        }


}
system("pause");


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


    trabajadorArch<<trab.toString()<<endl;

    trabajadorArch.close();

    cout<<"\n\nse ingreso correctamente el trabajador\n\n";
        }
        else{
        cout<<"El Trabajador con numero de ID "<<trab.getNumID()<<" ya existe\n\n";
        trabajadorArch.close();
        }

system("pause");


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

    administradorArch<<admin.toString()<<endl;

    administradorArch.close();

    cout<<"\n\nse ingreso correctamente el administrado\n\n";
        }
        else{
        cout<<"El Adminnistrador con numero de ID "<<admin.getNumID()<<" ya existe\n\n";
        administradorArch.close();
        }
system("pause");


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


system("cls");

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
            system("pause");
          }

    }


system("cls");



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
system("pause");
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
system("pause");
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

cout<<"Hay un total de "<<cont<<" Administradores"<<endl;

system("pause");
administradorArch.close();
}

}


}while(opc!=0);
}





//Bucar usuarios por ID//
void buscarXid(){
int opc;

do{


system("cls");

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
            system("pause");
     }

    }



system("cls");



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
system("pause");

clienteArch.close();

if (!existe){
cout<<"el cliente "<<buscarID<<" no esxiste\n";
system("pause");

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
system("pause");

trabajadorArch.close();

if (!existe){
cout<<"el trabajador "<<buscarID<<" no esxiste\n";
system("pause");

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
system("pause");

administradorArch.close();

if (!existe){
cout<<"No existe el administrador "<<buscarID<<endl;
system("pause");

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

system("pause");


    }




}while(opc != 0);

}





//Modificador de usuarios//
void modificarUsuarios(){

system("cls");


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

                cout<<"ingrese el nuevo nombre: ";
                getline(cin, nombre);};break;

        case 2: {modifico = true;

                cout<<"ingrese el nuevo apellido: ";
                getline(cin, apellido);};break;

        case 3: {modifico = true;

                cout<<"ingrese la nueva password: ";
                getline(cin, password);};break;

        case 4: {modifico = true;

                cout<<"ingrese el nuevo correo: ";
                getline(cin, correo);};break;

        case 5: {modifico = true;

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

system("pause");

}








//eliminar usuarios//
void eliminarUsuarios(){
system("cls");


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

system("pause");

}


int main(){
    menu();
    return 0;
}
