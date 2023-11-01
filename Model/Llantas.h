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
    Llantas(string nombre = " ", string ident = " ", double precio = 0.0, float traccion = 0.0);
    virtual ~Llantas();
    //Item--------------------------------------------
    virtual const string &getId() const ;
    virtual void setId(const string &id);
    virtual const string &getNombre() const ;
    virtual void setNombre(const string &nombre);
    virtual double getPrecio() const;
    virtual void setPrecio(double precio) ;
    virtual float getTraccion() const ;
    virtual void setTraccion(float traccion) ;

    //Vehiculo----------------------------------------
    virtual string mostrarDecoraciones();
    //Operadores--------------------------------------
    friend ostream &operator<<(ostream &os,  Item &vehiculo);
    virtual bool operator==(const string& id) const;
    virtual bool operator!=(const string& id) const;
    //Archivos----------------------------------------
    virtual Item* cargaDatos(Json::Value objeto) ;
    virtual Json::Value salvaDatos(Item& veh) ;

};


