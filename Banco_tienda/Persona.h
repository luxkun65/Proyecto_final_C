#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
using namespace::std;

class Persona
{
    public:
        Persona();
        virtual ~Persona();

        long numID;
        string nombre, apellido, password, correo, identidad;

        void setNumID();
        void setNombre();
        void setApellido();
        void setPassword();
        void setCorreo();
        void setIdentidad();
        string toString();

        long getNumID();
        string getNombre();
        string getApellido();
        string getPassword();
        string getCorreo();
        string getIdentidad();


    protected:

    private:
};

#endif // PERSONA_H
