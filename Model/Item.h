//
// Created by mauri on 23/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_ITEM_H
#define PRUEBAPROYECTOMCAV_ITEM_H

#include "Utilities.h"
#include "dist/json/json.h"
class Item {
protected:
    string _id;
    string _nombre;
    double _precio;
    float _traccion;
    float _velocidad;
    float _potencia;
public:
    Item();
    Item(string id = " ", string nombre = " ", double precio = 0.0, float traccion = 0.0, float velocidad = 0.0, float potencia = 0.0);
    //GetterSetters-----------------------------------
    virtual const string &getId() const  = 0;
    virtual void setId(const string &id) = 0;
    virtual const string &getNombre() const  = 0;
    virtual void setNombre(const string &nombre) = 0;
    virtual double getPrecio() const = 0;
    virtual void setPrecio(double precio)  = 0;
    virtual float getTraccion() const  = 0;
    virtual void setTraccion(float traccion)  = 0;
    virtual float getVelocidad() ;
    virtual void setVelocidad(float velocidad) ;
    virtual float getPotencia() const = 0;
    virtual void setPotencia(float potencia) = 0;
    //Item----------------------------------------
    virtual double costo()=0;
    //virtual void agregarDecoraciones(Item*)=0;
    virtual string mostrarDecoraciones()  =0;
    virtual void quitarDecoraciones(string id)=0;
    //virtual void incrementoDecremento(bool)=0;
    //virtual void setItem(Item*)=0;
    //virtual Item* getItem()=0;
    virtual Item* getSiguiente()=0;
    //virtual int getContador()=0;
    //Operadores--------------------------------------
    friend ostream &operator<<(ostream &os,  Item &vehiculo);//en realidad no hace faltra ponerlo aca
    virtual bool operator==(const string& id) const = 0;
    virtual bool operator!=(const string& id) const = 0;
    //Archivos-------------------------------------=--
    virtual Item* cargaDatos(Json::Value objeto) = 0;
    virtual Json::Value salvaDatos(Item& veh) = 0;
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