//
// Created by eolic on 22/10/2023.
//

#pragma once

#include <math.h>
#include"Vehiculo.h"


class Motor :public Vehiculo {
private:
    string nombre;
public:
    Motor();
    Motor(const string, float);
    virtual~Motor();

    const string getNombre2() const;
    const float getPotencia2() const;

    void setNombre2(const string nombre);
    void setPotencia2(const float);

    void mejorarPotencia();

    friend ostream &operator<<(ostream &os, const Motor *motor);
};


