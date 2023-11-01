//
// Created by mauri on 25/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_PIEZA_H
#define PRUEBAPROYECTOMCAV_PIEZA_H

#include "Item.h"
class Pieza:public Item {
protected:
    Item* ptrItem;
    bool utilizada;
public:
    Pieza(string id = "0", string nombre = " ", double precio = 0.0, float traccion = 0.0, float velocidad = 0.0, float potencia = 0.0);
    virtual const string &getId() const ;
    virtual void setId(const string &id);
    virtual const string &getNombre() const;
    virtual void setNombre(const string &nombre);
    virtual double getPrecio() const;
    virtual void setPrecio(double precio) ;
    virtual float getTraccion() const ;
    virtual void setTraccion(float traccion) ;
    //virtual float getVelocidad() const ;
//    virtual void setVelocidad(float velocidad) ;
    virtual float getPotencia() const;
    virtual void setPotencia(float potencia);

    //Vehiculo----------------------------------------
    virtual string mostrarDecoraciones()=0;
    //Pieza-------------------------------------------
    virtual void setEstado(bool);
    virtual bool getEstado()const;
    //Operadores--------------------------------------
    friend ostream &operator<<(ostream &os, const Item &vehiculo);
    virtual bool operator==(const string& id) const = 0;
    virtual bool operator!=(const string& id) const = 0;
    //Archivos----------------------------------------
    virtual Item* cargaDatos(Json::Value objeto) = 0;
    virtual Json::Value salvaDatos(Item& veh) = 0;
};


#endif //PRUEBAPROYECTOMCAV_PIEZA_H
