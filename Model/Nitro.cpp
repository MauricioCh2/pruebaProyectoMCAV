//
// Created by eolic on 22/10/2023.
//

#include "Nitro.h"

Nitro::Nitro() {
    nombre="";
}
Nitro::Nitro(string nombre, float velocidad) :  Vehiculo() {
    this-> nombre = nombre;
    this->velocidad = velocidad;
}

Nitro::~Nitro() {}

const string Nitro::getNombre2() const {
    return nombre;
}

void Nitro::setNombre2(const string nombre) {
    this->nombre = nombre;
}

void Nitro::setVelocidad2(const float velocidad) {
    this->velocidad=velocidad;
}

const float Nitro::getVelocidad2() const {
    return velocidad;
}

void Nitro::mejorarVelocidad() {
    float valorNitro = 1.2;
    float velocidadActual = this->getVelocidad2();
    float nuevaVelocidad = velocidadActual * valorNitro;
    this->setVelocidad2(nuevaVelocidad);
}
ostream &operator<<(ostream &os, const Nitro *nitro) {
    os <<  " nombre: " << nitro->getNombre2() << "Velocidad mejorada: " << nitro->getVelocidad2();
    return os;
}

