//
// Created by eolic on 22/10/2023.
//

#pragma once

#include <math.h>
#include"Pieza.h"


class Motor :public Pieza {
private:

public:
    Motor(string nombre = " ", string ident = " ", double precio = 0.0, float potencia = 0.0 );
    virtual~Motor();

    virtual const string &getId() const ;
    virtual void setId(const string &id);
    virtual const string &getNombre() const ;
    virtual void setNombre(const string &nombre);
    virtual double getPrecio() const;
    virtual void setPrecio(double precio) ;
    virtual float getPotencia()const;
    virtual void setPotencia(float potencia);
    //Vehiculo----------------------------------------
    virtual string mostrarDecoraciones()  ;
    //Operadores--------------------------------------
    friend ostream &operator<<(ostream &os, const Item &vehiculo);
    virtual bool operator==(const string& id) const;
    virtual bool operator!=(const string& id) const;
    //Archivos-------------------------------------=--
    virtual Item* cargaDatos(Json::Value objeto) ;
    virtual Json::Value salvaDatos(Item& veh) ;
};


