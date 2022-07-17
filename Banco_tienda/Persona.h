#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
using namespace::std;

class Persona
{
    public:
        Persona();
        virtual ~Persona();




        void setNumID();
        void setNombre();
        void setApellido();
        void setPassword();
        void setCorreo();
        void setIdentidad();
        string toString();
        void setActivo(bool);


        int getNumID();
        string getNombre();
        string getApellido();
        string getPassword();
        string getCorreo();
        string getIdentidad();
        string getActivo();


    protected:

    int numID;
    string nombre, apellido, password, correo, identidad, activo;


    private:
};

#endif // PERSONA_H
