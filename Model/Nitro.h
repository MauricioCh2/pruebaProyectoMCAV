//
// Created by eolic on 22/10/2023.
//
#pragma once

#include <ostream>
#include"Vehiculo.h"

class Nitro:public Vehiculo {
private:
    string nombre;
public:
    Nitro();
    Nitro(string,float);
    virtual ~Nitro();

    const string getNombre2() const;
    const float getVelocidad2()const;

    void setNombre2(const string nombre);
    void setVelocidad2(const float velocidad);

    void mejorarVelocidad();
    friend ostream &operator<<(ostream &os, const Nitro &nitro);

};

