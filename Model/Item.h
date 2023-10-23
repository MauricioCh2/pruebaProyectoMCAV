//
// Created by mauri on 23/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_ITEM_H
#define PRUEBAPROYECTOMCAV_ITEM_H

#include "Utilities.h"
class Item {
private:
    string ID;
    string Nombre;
    double precio;
    float traccion;
    float velocidad;
    float potencia;
public:
    Item();

    virtual const string &getId() const  = 0;
    virtual void setId(const string &id) = 0;
    virtual const string &getNombre() const  = 0;
    virtual void setNombre(const string &nombre) = 0;
    virtual double getPrecio() const = 0;
    virtual void setPrecio(double precio)  = 0;
    virtual float getTraccion() const  = 0;
    virtual void setTraccion(float traccion)  = 0;
    virtual float getVelocidad() const  = 0;
    virtual void setVelocidad(float velocidad)  = 0;
    virtual float getPotencia() const = 0;
    virtual void setPotencia(float potencia) = 0;
};


#endif //PRUEBAPROYECTOMCAV_ITEM_H
/*    //Creo que esta igual, solo algunos detallitos
#pragma once

#include<iostream>
#include<sstream>

using namespace std;

class Item {
protected:
    string id;
    string nombre;
    float precio;
    float traccion;
    float velocidad;
    float potencia;
public:
    virtual const string getId() const = 0 ;
    virtual const string getNombre() const  = 0 ;
    virtual float getPrecio() const  = 0 ;
    virtual float getTraccion() const = 0;
    virtual float getVelocidad() const = 0;
    virtual float getPotencia() const = 0;

    virtual void setId(const string) = 0;
    virtual void setNombre(const string) = 0;
    virtual void setPrecio(float) = 0;
    virtual void setTraccion(float) = 0;
    virtual void setVelocidad(float) = 0;
    virtual void setPotencia(float) = 0;
};



*/