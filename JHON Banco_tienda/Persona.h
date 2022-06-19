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
        virtual string toCSV();
        virtual string toString();

        void setNumID();
        void setNombre();
        void setApellido();
        void setPassword();
        void setNombreUsuario();
        void setCorreo();
        void setActivo();
        void setActivo(bool);

        long getNumID();
        string getNombre();
        string getApellido();
        string getPassword();
        string getNombreUsuario();
        string getCorreo();
        bool getActivo();


    protected:

    long numID;
    string nombre, apellido, password, correo, nom_usuario;
    bool activo;

    private:
};

#endif // PERSONA_H
