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
    //Llantas(const string, float);
    Llantas(Item*);
    Llantas(string nombre = " ", string ident = " ", double precio = 0.0, float traccion = 0.0);
    virtual ~Llantas();

//    const string getNombre2() const;
//    const float getTraccion2()const;
//
//    void setTraccion2(const float traccion);
//    void setNombre2(const string nombre);
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
    virtual double costo();
    virtual void agregarDecoraciones(Item*);
    virtual string mostrarDecoraciones() const ;
    virtual void incrementoDecremento();
    virtual int getContador();
    //Operadores--------------------------------------
    friend ostream &operator<<(ostream &os, const Item &vehiculo);
    virtual bool operator==(const string& id) const;
    virtual bool operator!=(const string& id) const;
    //Archivos-------------------------------------=--
    virtual Item* cargaDatos(Json::Value objeto) ;
    virtual Json::Value salvaDatos(Item& veh) ;

    //Propios-----------------------------------------
    void mejorarTraccion();
    //friend ostream &operator<<(ostream &os, const Llantas *llantas);
};


