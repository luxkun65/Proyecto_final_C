#ifndef CLASE_TRABAJADOR_H
#define CLASE_TRABAJADOR_H
#include <iostream>
using namespace::std;


class Clase_Trabajador
{
    public:
        string verPQR, consultaCartera, guia;
        long consultaSaldo;
        bool aceptaPQR, aceptaPrestamo, niegaPrestamo;

        Clase_Trabajador() {
        verPQR = consultaCartera = guia = "-";
        consultaSaldo = 0.0;
        aceptaPQR = aceptaPrestamo = niegaPrestamo = false;
        }
        virtual ~Clase_Trabajador() {}
        //declaración de funciones set y get

        void setVerPQR(){
        cout<<"Peticiones, Quejas, Recursos: "<<endl;
        }
        string getVerPQR(){
        return verPQR;
        }
        void setConsultaCartera(){
        cout<<"Cartera del usuario: "<<endl;
        }
        string getConsultaCartera(){
        return consultaCartera;
        }
        void setAceptaPrestamo(){
        cout<<"su prestamo ha sido aceptado"<<endl;
        }
        bool getAceptaPrestamo(){
        return aceptaPrestamo;
        }
        void setNiegaPrestamo(){
        cout<<"Su prestamo ha sido rechazado"<<endl;
        }
        bool getNiegaPrestamo(){
        return niegaPrestamo;
        }
        void setGuia(){
        cout<<"Guia del usuario: "<<endl;
        }
        string getGuia(){
        return guia;
        }
        void setConsultaSaldo(){
        cout<<"su saldo es de: "<<endl;
        }
        long getConsultaSaldo(){
        return consultaSaldo;
        }
        void setAceptaPQR(){
        cout<<"Su PQR ha sido aceptado"<<endl;
        }
        bool getAceptaPQR(){
        return aceptaPQR;
        }

    protected:

    private:
};

#endif // CLASE_TRABAJADOR_H
