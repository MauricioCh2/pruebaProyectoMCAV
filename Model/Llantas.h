//
// Created by eolic on 22/10/2023.
//

#pragma once

#include <ostream>
#include"Vehiculo.h"

class Llantas:public Vehiculo {
private:
    string nombre;
public:
    Llantas();
    Llantas(const string, float);
    virtual ~Llantas();

    const string getNombre2() const;
    const float getTraccion2()const;

    void setTraccion2(const float traccion);
    void setNombre2(const string nombre);

    void mejorarTraccion();

    friend ostream &operator<<(ostream &os, const Llantas *llantas);
};


