//
// Created by eolic on 22/10/2023.
//

#include "Llantas.h"

Llantas::Llantas() {
    nombre = "";
    traccion = 0.0;
}
Llantas::Llantas(const string nombre, float traccion) :Vehiculo(){
    this->nombre = nombre;
    this->traccion = traccion;
}
Llantas::~Llantas() {}

const string Llantas::getNombre2() const {
    return nombre;
}

void Llantas::setNombre2(const string nombre) {
    Llantas::nombre = nombre;
}

const float Llantas::getTraccion2() const {
    return traccion;
}

void Llantas::setTraccion2(const float traccion)  {
    this->traccion = traccion;
}
void Llantas::mejorarTraccion() {
    float factor = 1.3;
    float traccionActual = this->getTraccion2();
    float nuevaTraccion = traccionActual * factor;
    this->setTraccion2(nuevaTraccion);
}

ostream &operator<<(ostream &os, const Llantas *llantas) {
    os << " nombre: " << llantas->nombre <<"Traccion mejorada: "<< llantas->getTraccion2();
    return os;
}


