//
// Created by mauri on 25/10/2023.
//

#include "Pieza.h"
Pieza::Pieza(const string id, const string nombre, double precio, float traccion, float velocidad,float potencia): Item(id, nombre, precio, traccion, velocidad, potencia) {}
//ITEM-----------------------------------------------
const string &Pieza::getId() const {
    return _id;
}

void Pieza::setId(const string &id) {
    _id = id;
}

const string &Pieza::getNombre() const {
    return _nombre;
}

void Pieza::setNombre(const string &nombre) {
    _nombre = nombre;
}

double Pieza::getPrecio() const {
    return _precio;
}

void Pieza::setPrecio(double precio) {
    _precio = precio;
}

float Pieza::getTraccion() const {
    return _traccion;
}

void Pieza::setTraccion(float traccion) {
    _traccion = traccion;
}



float Pieza::getPotencia() const {
    return _potencia;
}

void Pieza::setPotencia(float potencia) {
    _potencia = potencia;
}

//Pieza---------------------------------------------------

void Pieza::setEstado(bool est){
    utilizada = est;
}
bool Pieza::getEstado()const{
    return utilizada;
}

