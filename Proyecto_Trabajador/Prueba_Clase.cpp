#include <iostream>
using namespace::std;
#include "Clase_Trabajador.h"
Clase_Trabajador objeto1;

int main (){
    objeto1.setVerPQR();
    objeto1.setConsultaCartera();
    objeto1.setAceptaPrestamo();
    objeto1.setNiegaPrestamo();
    objeto1.setGuia();
    objeto1.setConsultaSaldo();
    objeto1.setAceptaPQR();

    cout<<objeto1.getVerPQR()<<endl;
    cout<<objeto1.getConsultaCartera()<<endl;
    cout<<objeto1.getAceptaPrestamo()<<endl;
    cout<<objeto1.getNiegaPrestamo()<<endl;
    cout<<objeto1.getGuia()<<endl;
    cout<<objeto1.getConsultaSaldo()<<endl;
    cout<<objeto1.getAceptaPQR()<<endl;


return 0;
}
