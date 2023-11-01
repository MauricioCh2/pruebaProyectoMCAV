//
// Created by eolic on 22/10/2023.
//
#pragma once

#include <ostream>
#include"Pieza.h"

class Nitro:public Pieza {
private:
    string nombre;
public:
    Nitro(string nombre = " ", string ident = " ", double precio = 0.0, float velociad = 0.0);
    virtual ~Nitro();

    //Vehiculo----------------------------------------
    virtual string mostrarDecoraciones()  ;
    //Operadores--------------------------------------
    friend ostream &operator<<(ostream &os, const Item &vehiculo);
    virtual bool operator==(const string& id) const;
    virtual bool operator!=(const string& id) const;
    //Archivos-------------------------------------=--
    virtual Item* cargaDatos(Json::Value objeto);
    virtual Json::Value salvaDatos(Item& veh);
};

