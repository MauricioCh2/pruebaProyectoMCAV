//
// Created by mauri on 24/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_VEHICULO_H
#define PRUEBAPROYECTOMCAV_VEHICULO_H

#include "Item.h"
#include "Exceptions.h"
//#include "Pieza.h"
#include "Lista.h"
#include "Motor.h"
#include "Llantas.h"
#include "Nitro.h"
class Vehiculo:public Item  {
private:
    Lista<Pieza,-1>* _lisPiezas;
public:
    //VehiculoBase();
    Vehiculo(string id = " ", string nombre = " ", double precio = 0.0, float traccion = 0.0, float velocidad = 0.0, float potencia = 0.0);
    //Item--------------------------------------------
    virtual const string &getId() const ;
    virtual void setId(const string &id);
    virtual const string &getNombre() const;
    virtual void setNombre(const string &nombre);
    virtual double getPrecio() const ;
    virtual void setPrecio(double precio);
    virtual float getTraccion() const;
    virtual void setTraccion(float traccion) ;
    //virtual float getVelocidad() const ;
    //virtual void setVelocidad(float velocidad) ;
    virtual float getPotencia() const ;
    virtual void setPotencia(float potencia) ;
    //Vehiculo-----------------------------------
    virtual Lista<Pieza,-1>* getListaPiezas();
    virtual void quitarTodasLasDecos();
    bool validarUso(string );
    //Item----------------------------------------
    virtual double costo();
    virtual void agregarDecoraciones(Pieza*);
    virtual string mostrarDecoraciones()  ;
    virtual void quitarDecoraciones(string id);
    virtual void incrementoDecremento(bool, Pieza& item);
    virtual void setItem(Item*);
    virtual Item* getItem();
    virtual Item* getSiguiente();
    virtual int getContador();
    //Operadores--------------------------------------
    friend ostream &operator<<(ostream &os, const Item &Item);
    virtual bool operator==(const string& id) const ;
    virtual bool operator!=(const string& id) const;
    //Archivos-------------------------------------=--
    virtual Vehiculo * cargaDatos(Json::Value objeto);
    virtual Json::Value salvaDatos(Item& veh);
};


#endif //PRUEBAPROYECTOMCAV_VEHICULO_H
