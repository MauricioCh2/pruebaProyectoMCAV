//
// Created by mauri on 23/10/2023.
//

#include "Item.h"

Item::Item() {}

Item::~Item() {}

Item::Item(string id, string nombre, double precio, float traccion, float velocidad, float potencia) {
        _id = id;
        _nombre = nombre;
        _precio = precio;
        _traccion = traccion;
        _velocidad = velocidad;
        _potencia = potencia;
}
ostream &operator<<(ostream &os,  Item &item){
    os << item.mostrarDecoraciones();
    return os;
}

const float Item::getVelocidad()const  {
    return _velocidad;
}
void Item::setVelocidad(const float velocidad) {
    _velocidad = velocidad;
}

const string &Item::getId() const {
    return _id;
}

void Item::setId(const string &id) {
     _id = id;
}

const string &Item::getNombre() const{
    return _nombre;
}

void Item::setNombre(const string &nombre) {
      _nombre = nombre;
}

const double Item::getPrecio() const{
    return _precio;
}

void Item::setPrecio(const double precio) {
    _precio = precio;
}

const float Item::getTraccion()const {
    return _traccion;
}

void Item::setTraccion(const float traccion) {
     _traccion = traccion;
}

const float Item::getPotencia()const {
    return _potencia;
}

void Item::setPotencia(float potencia) {
     _potencia = potencia;
}
