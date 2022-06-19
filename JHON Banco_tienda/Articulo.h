#ifndef ARTICULO_H
#define ARTICULO_H
#include<iostream>
using namespace std;

class Articulo
{
    public:
        Articulo();
        virtual ~Articulo();

        void setNombre(string);
        void setCantidad(int);
        void setPrecio(double);
        void setTotal();
        void setCalidad(string);
        Articulo(string, string, int, double);

        string getNombre();
        string getCalidad();
        int getCantidad();
        double getPrecio();
        double getTotal();
        string toString();

    protected:
        string nombre;
        string calidad;
        int cantidad;
        double precio;
        double total;

    private:
};

#endif // ARTICULO_H
