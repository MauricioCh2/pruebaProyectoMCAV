//
// Created by mauri on 25/10/2023.
//

#include "Pieza.h"
Pieza::Pieza(const string id, const string nombre, double precio, float traccion, float velocidad,float potencia): Item(id, nombre, precio, traccion, velocidad, potencia) {}
//ITEM-----------------------------------------------
const string &Pieza::getId() const {
    return _id;
}

void Pieza::setId(const string &id) {
    _id = id;
}

const string &Pieza::getNombre() const {
    return _nombre;
}

void Pieza::setNombre(const string &nombre) {
    _nombre = nombre;
}

double Pieza::getPrecio() const {
    return _precio;
}

void Pieza::setPrecio(double precio) {
    _precio = precio;
}

float Pieza::getTraccion() const {
    return _traccion;
}

void Pieza::setTraccion(float traccion) {
    _traccion = traccion;
}

//float Pieza::getVelocidad() const {
//    return _velocidad;
//}

//void Pieza::setVelocidad(float velocidad) {
//    _velocidad = velocidad;
//}

float Pieza::getPotencia() const {
    return _potencia;
}

void Pieza::setPotencia(float potencia) {
    _potencia = potencia;
}

//Item---------------------------------------------------
void Pieza::quitarDecoraciones(string id) {
//    Item* ppio;
//    Item* aux;
//    aux = ptrItem;
//
//    int cont = ptrItem->getContador();
//    if(ptrItem==NULL) {
//
//    }else{
//        ppio = ptrItem;
//        if(ppio->getId() == id){//elimina el primero
//            //aux = ppio;
//            ppio = ptrItem->getItem();
//            delete aux;
//            //return ppio;
//        }else{//elimina otro en caso de no ser el primero
//
//        }
//    }
}

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

