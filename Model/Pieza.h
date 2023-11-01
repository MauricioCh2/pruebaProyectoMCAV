//
// Created by mauri on 25/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_PIEZA_H
#define PRUEBAPROYECTOMCAV_PIEZA_H

#include "Item.h"
class Pieza:public Item {  //Hereda de Item
protected:
    Item* ptrItem;
    bool utilizada;
public:
    Pieza(string id = "0", string nombre = " ", double precio = 0.0, float traccion = 0.0, float velocidad = 0.0, float potencia = 0.0);
    virtual~Pieza();

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
