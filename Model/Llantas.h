//
// Created by eolic on 22/10/2023.
//

#pragma once

#include <ostream>
#include "Pieza.h"

class Llantas:public Pieza {
private:
    string nombre;
public:
    Llantas();
    Llantas(Item*);
    Llantas(string nombre = " ", string ident = " ", double precio = 0.0, float traccion = 0.0);
    virtual ~Llantas();
    //Vehiculo----------------------------------------
    virtual double costo();
    virtual void agregarDecoraciones(Item*);
    virtual string mostrarDecoraciones();
    //virtual void incrementoDecremento(bool);
    virtual int getContador();
    //Operadores--------------------------------------
    friend ostream &operator<<(ostream &os,  Item &vehiculo);
    virtual bool operator==(const string& id) const;
    virtual bool operator!=(const string& id) const;
    //Archivos-------------------------------------=--
    virtual Item* cargaDatos(Json::Value objeto) ;
    virtual Json::Value salvaDatos(Item& veh) ;


};


