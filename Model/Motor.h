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

    //Vehiculo----------------------------------------
    virtual string mostrarDecoraciones()  ;
    //Operadores--------------------------------------
    friend ostream &operator<<(ostream &os, const Item &vehiculo);
    virtual bool operator==(const string& id) const;
    virtual bool operator!=(const string& id) const;
    //Archivos----------------------------------------
    virtual Item* cargaDatos(Json::Value objeto) ;
    virtual Json::Value salvaDatos(Item& veh) ;
};


