//
// Created by mauri on 25/10/2023.
//

#include "Pieza.h"
Pieza::Pieza(const string id, const string nombre, double precio, float traccion, float velocidad,float potencia): Item(id, nombre, precio, traccion, velocidad, potencia) {}

Pieza::~Pieza() {
     if(ptrItem != nullptr) delete ptrItem;
}

//Pieza-----------------------------------------------
void Pieza::setEstado(bool est){
    utilizada = est;
}
bool Pieza::getEstado()const{
    return utilizada;
}

