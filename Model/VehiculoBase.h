//
// Created by mauri on 24/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_VEHICULO_H
#define PRUEBAPROYECTOMCAV_VEHICULO_H

#include "Item.h"
#include "Exceptions.h"
#include "Archivos.h"
#include "Lista.h"
#include "Motor.h"
#include "Llantas.h"
#include "Nitro.h"
class Vehiculo:public Item  {      //Hija de la clase Item, forma parte del patron decorador
private:
    Lista<Pieza,-1>* _lisPiezas;
public:
    Vehiculo(string id = " ", string nombre = " ", double precio = 0.0, float traccion = 0.0, float velocidad = 0.0, float potencia = 0.0);
    virtual~Vehiculo();
    //Vehiculo-----------------------------------
    virtual Lista<Pieza,-1>* getListaPiezas();
    virtual void quitarTodasLasDecos(); //Elimina todas las piezas decorativas que tiene un vehiculo, y crea vacia nuevamente una lista de piezas.
    bool validarUso(string );
    //Item----------------------------------------
    virtual double costo();
    virtual void agregarDecoraciones(Pieza*);
    virtual void agregarDecoracionesSinIncremento(Pieza*);
    virtual string mostrarDecoraciones();
    virtual void quitarDecoraciones(string id);
    virtual void incrementoDecremento(bool, Pieza* item);
    //Operadores--------------------------------------
    friend ostream &operator<<(ostream &os, const Item &Item);
    virtual bool operator==(const string& id) const ;
    virtual bool operator!=(const string& id) const;
    //Archivos-------------------------------------=--
    virtual Vehiculo * cargaDatos(Json::Value objeto);
    virtual Json::Value salvaDatos(Item& veh);
};


#endif //PRUEBAPROYECTOMCAV_VEHICULO_H
