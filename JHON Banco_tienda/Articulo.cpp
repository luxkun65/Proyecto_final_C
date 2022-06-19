#include "Articulo.h"

Articulo::Articulo()
{
    precio = total = 0.0;
    cantidad = 0;
    nombre = calidad = "-";
}

Articulo::~Articulo()
{
    //dtor
}

void Articulo::setNombre(string nom){
    nombre = nom;
}
void Articulo::setCantidad(int cant){
    cantidad = cant;
}
void Articulo::setPrecio(double pre){
    precio = pre;
}
void Articulo::setTotal(){
    total = precio * cantidad;
}
void Articulo::setCalidad(string cal){
    calidad = cal;
}

string Articulo::getNombre(){
    return nombre;
}
int Articulo::getCantidad(){
    return cantidad;
}
double Articulo::getPrecio(){
    return precio;
}
double Articulo::getTotal(){
    return total;
}
string Articulo::getCalidad(){
    return calidad;
}

Articulo::Articulo(string nom, string cal, int cant, double prec){
    nombre = nom;
    calidad = cal;
    cantidad = cant;
    precio = prec;
    total = cantidad * precio;
}

string Articulo::toString(){
    return "Producto: " + nombre + "\n" +
           "Calidad: " + calidad + "\n" +
           "Precio c/u: " + to_string(precio) + "\n" +
           "Cantidad: " + to_string(cantidad) + "\n" +
           "Total: " + to_string(total) + "\n";
}
