//
// Created by eolic on 22/10/2023.
//

#include "Nitro.h"

Nitro::Nitro() {
    nombre="";
}
//Nitro::Nitro(string nombre, float velocidad) :  Item() {
//    this-> nombre = nombre;
//    this->velocidad = velocidad;
//}
Nitro::Nitro(Item* v) {
    this->ptrItem = v;
    //this->cont= this->ptrItem->getContador()+1;
}
Nitro::Nitro(string nombre , string ident , double precio, float velocidad ) {
    //this->ptrItem = v;
    //this->cont= this->ptrItem->getContador()+1;
    this->_nombre = nombre;
    this->_id = ident;
    this->_precio = precio;
    this->_velocidad = velocidad;
    this->utilizada = false;

}
Nitro::~Nitro() {}
//ITEM----------------------------------------
const string &Nitro::getId() const {
    return Pieza::getId();
}

void Nitro::setId(const string &id) {
    Pieza::setId(id);
}

const string &Nitro::getNombre() const {
    return Pieza::getNombre();
}

void Nitro::setNombre(const string &nombre) {
    Pieza::setNombre(nombre);
}

double Nitro::getPrecio() const {
    return Pieza::getPrecio();
}

void Nitro::setPrecio(double precio) {
    Pieza::setPrecio(precio);
}
//float Nitro::getVelocidad() const {
//    return _velocidad;
//}
//void Nitro::setVelocidad(float velocidad) {
//    Pieza::setVelocidad(velocidad);
//}

double Nitro::costo() {
    return this->ptrItem->costo() + this->_precio;
}

void Nitro::agregarDecoraciones(Item *) {

}

string Nitro::mostrarDecoraciones()   {
    stringstream s;
    //s << this->ptrItem->mostrarDecoraciones() << endl;
    s <<"\t-Nitro: " << getNombre() << "\n\tID: " << getId() <<"\tPrecio: " <<getPrecio() << "\tMejora en Velocidad: " << getVelocidad()<< " Estado: ";
    this->getEstado() ? s<< YELLOW"Usado" << RESET: s << "Disponible"; //condicion ? exprecion1 : condicion2 (es otra forma de usar if)
    s << endl;
    return s.str();
}

//void Nitro::incrementoDecremento(bool) {
//
//}

int Nitro::getContador() {
    return 0;
}

//ostream &operator<<(ostream &os, const Item &Item){
//    os << "\t-Nitro: " << Item.getNombre() << "\nID: " << Item.getId() <<"\tPrecio: " <<Item.getPrecio() << "\tMejora en Velocidad: " << Item.getVelocidad()<< endl;
//
//    return os;
//}
bool Nitro::operator==(const string& id) const {
    return this->_id == id;
}

bool Nitro::operator!=(const string& id) const {
    return (this->_id != id);
}

Item *Nitro::cargaDatos(Json::Value objeto) {
    string ident = objeto["ID"].asString();
    string nombre = objeto["Nombre"].asString();
    double precio = objeto["Precio"].asDouble();
    float velocidad = objeto["Velocidad"].asFloat();
    bool estado = objeto["Estado"].asBool();
    return new Nitro( nombre, ident, precio, velocidad);
}

Json::Value Nitro::salvaDatos(Item &veh) {
    Json::Value event;
    event["Tipo"] = "Nitro";
    event["ID"] = veh.getId();
    event["Nombre"] = veh.getNombre();
    event["Precio"] = veh.getPrecio();
    event["Velocidad"] = veh.getVelocidad();

    return event;
}

void Nitro::mejorarVelocidad() {

}
//const string Nitro::getNombre2() const {
//    return nombre;
//}
//
//void Nitro::setNombre2(const string nombre) {
//    this->nombre = nombre;
//}
//
//void Nitro::setVelocidad2(const float velocidad) {
//    this->velocidad=velocidad;
//}
//
//const float Nitro::getVelocidad2() const {
//    return velocidad;
//}
//
//void Nitro::mejorarVelocidad() {
//    float valorNitro = 1.2;
//    float velocidadActual = this->getVelocidad2();
//    float nuevaVelocidad = velocidadActual * valorNitro;
//    this->setVelocidad2(nuevaVelocidad);
//}
//ostream &operator<<(ostream &os, const Nitro *nitro) {
//    os <<  " nombre: " << nitro->_nombre << "Velocidad mejorada: " << nitro->getVelocidad2();
//    return os;
//}

