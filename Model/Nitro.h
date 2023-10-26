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
    Nitro();
    //Nitro(string,float);
    Nitro(Item*);
    Nitro(string nombre = " ", string ident = " ", double precio = 0.0, float velociad = 0.0);
    virtual ~Nitro();

//    const string getNombre2() const;
//    const float getVelocidad2()const;
//
//    void setNombre2(const string nombre);
//    void setVelocidad2(const float velocidad);
    //Item--------------------------------------------
    virtual const string &getId() const ;
    virtual void setId(const string &id);
    virtual const string &getNombre() const ;
    virtual void setNombre(const string &nombre);
    virtual double getPrecio() const;
    virtual void setPrecio(double precio) ;
    virtual float getVelocidad() const ;
    virtual void setVelocidad(float velocidad);
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
    void mejorarVelocidad();
    //friend ostream &operator<<(ostream &os, const Nitro &nitro);

};

