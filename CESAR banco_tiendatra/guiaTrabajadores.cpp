#include <iostream>
using namespace::std;

//declaracion de funcion guia
void guiaTrabajadores();

//declaracion de funciones mensajes
void trabajador1();
void trabajador2();
void trabajador3();

//implementacion funcion guia
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

//implementacion funciones mensaje

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

guiaTrabajadores();

return 0;
}
