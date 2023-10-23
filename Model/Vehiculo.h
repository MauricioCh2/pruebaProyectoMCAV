//
// Created by eolic on 22/10/2023.
//

#pragma once

#include <ostream>
#include"Item.h"
#include"Tienda.h"

class Vehiculo :public Item{
protected:
    string id;
    string nombre;
    float precio;
    float traccion;
    float velocidad;
    float potencia;
    //Lista<Tienda>*ptrD;
public:
    Vehiculo();
    Vehiculo(const string, const string, float,float,float,float);
    virtual ~Vehiculo();

    const string getId1() const;
    const string getNombre1() const;
    float getPrecio1() const;
    float getTraccion1() const;
    float getVelocidad1() const;
    float getPotencia1() const;

    void setId1(const string id);
    void setNombre1(const string nombre);
    void setPrecio1(float precio);
    void setTraccion1(float traccion);
    void setVelocidad1(float velocidad);
    void setPotencia1(float potencia);

    void agregarDecoraciones(Tienda*);
    void mostrarDecoraciones();
    void quitarDecoraciones();
    void incrementoDecremento();

    friend ostream &operator<<(ostream &os, const Vehiculo *vehiculo);
};



