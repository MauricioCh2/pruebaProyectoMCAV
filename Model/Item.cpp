//
// Created by mauri on 23/10/2023.
//

#include "Item.h"

Item::Item() {}

Item::Item(string id, string nombre, double precio, float traccion, float velocidad, float potencia) {
_id = id;
_nombre = nombre;
_precio = precio;
_traccion = traccion;
_velocidad = velocidad;
_potencia = potencia;
}
ostream &operator<<(ostream &os,  Item &item){
    //os << "Id: " << item.getId() << "Nombre: " << item.getNombre() << "Costo" << item.getPrecio();
    os << item.mostrarDecoraciones();
    //os << "Velocidad pruebaaaa: "<< item.getVelocidad()<<endl;
    return os;
}

float Item::getVelocidad()  {
    return _velocidad;
}
void Item::setVelocidad(float velocidad) {
    _velocidad = velocidad;
}