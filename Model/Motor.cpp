//
// Created by eolic on 22/10/2023.
//

#include "Motor.h"

Motor::Motor() {
    nombre = "";
    potencia = 0;
}
Motor::Motor(const string nombre, float potencia) :  Vehiculo(){
    this->nombre = nombre;
    this->potencia = potencia;
}
Motor::~Motor() {}

const string Motor::getNombre2() const {
    return nombre;
}

void Motor::setNombre2(const string nombre) {
    this->nombre = nombre;
}

void Motor::mejorarPotencia() {           //Preguntar a que valor se debe hacer la mejora.
    float potenciaActual = this->getPotencia2();
    float nuevaPotencia = pow(potenciaActual, 1.1);  //10%
    this->setPotencia2(nuevaPotencia);
}

void Motor::setPotencia2(const float potencia) {
    this->potencia=potencia;
}

const float Motor::getPotencia2()const {
    return potencia;
}

ostream &operator<<(ostream &os, const Motor *motor) {
    os << " nombre: " << motor->getNombre2() << "Potencia mejorada: "<<motor->getPotencia2();
    return os;
}



