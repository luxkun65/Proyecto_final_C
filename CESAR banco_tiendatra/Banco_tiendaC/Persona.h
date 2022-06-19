#ifndef PERSONA_H
#define PERSONA_H
#include<ctime>
#include<iostream>
#include<cstdlib>
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
        void setNombreUsuario();
        void setCorreo();
        string toCSV();
        string toString();

        long getNumID();
        string getNombre();
        string getApellido();
        string getPassword();
        string getNombreUsuario();
        string getCorreo();


    protected:

    long numID;
    string nombre, apellido, password, correo, nom_usuario;

    private:
};

#endif // PERSONA_H
