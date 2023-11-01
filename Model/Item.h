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
    virtual~Item();
    //GetterSetters-----------------------------------
    virtual const string &getId() const;
    virtual void setId(const string &id);
    virtual const string &getNombre() const;
    virtual void setNombre(const string &nombre);
    virtual const double getPrecio() const;
    virtual void setPrecio(const double precio);
    virtual const float getTraccion()const;
    virtual void setTraccion(const float traccion);
    virtual float const getVelocidad()const;
    virtual void setVelocidad(const float velocidad);
    virtual float const getPotencia()const;
    virtual void setPotencia(const float potencia);

    // Metodos virtuales puros que heredan sus hijos e implementaran--------------------------
    virtual double costo()=0;
    virtual string mostrarDecoraciones()  =0;
    //Operadores--------------------------------------
    friend ostream &operator<<(ostream &os,  Item &vehiculo);
    virtual bool operator==(const string& id) const = 0;
    virtual bool operator!=(const string& id) const = 0;
    //Archivos----------------------------------------
    virtual Item* cargaDatos(Json::Value objeto) = 0;
    virtual Json::Value salvaDatos(Item& veh) = 0;
};


#endif