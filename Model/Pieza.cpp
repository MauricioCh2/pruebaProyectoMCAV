//
// Created by mauri on 25/10/2023.
//

#include "Pieza.h"
Pieza::Pieza(const string id, const string nombre, double precio, float traccion, float velocidad,float potencia): Item(id, nombre, precio, traccion, velocidad, potencia) {}

Pieza::~Pieza() {
     if(ptrItem != nullptr) delete ptrItem;
}

//ITEM-----------------------------------------------

void Pieza::setItem(Item* v) {
    ptrItem = v;
}

Item* Pieza::getItem() {
    return ptrItem;
}

Item* Pieza::getSiguiente() {
    return ptrItem->getSiguiente();
}
void Pieza::setEstado(bool est){
    utilizada = est;
}
bool Pieza::getEstado()const{
    return utilizada;
}

void Pieza::quitarDecoraciones(string id) {

}
