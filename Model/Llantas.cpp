//
// Created by eolic on 22/10/2023.
//

#include "Llantas.h"

//Llantas::Llantas() {
//    nombre = "";
//    traccion = 0.0;
//}
Llantas::Llantas(Item* v) {
    this->ptrItem = v;
    //this->cont= this->ptrItem->getContador()+1;
}
Llantas::Llantas(string nombre , string ident , double precio, float traccion) {
    //this->ptrItem = v;
    //this->cont= this->ptrItem->getContador()+1;
    this->_nombre = nombre;
    this->_id = ident;
    this->_precio = precio;
    this->_traccion = traccion;
    this->utilizada = false;
}
Llantas::~Llantas() {}
//ITEM----------------------------------------
const string &Llantas::getId() const {
    return Pieza::getId();
}

void Llantas::setId(const string &id) {
    Pieza::setId(id);
}

const string &Llantas::getNombre() const {
    return Pieza::getNombre();
}

void Llantas::setNombre(const string &nombre) {
    Pieza::setNombre(nombre);
}

double Llantas::getPrecio() const {
    return Pieza::getPrecio();
}

void Llantas::setPrecio(double precio) {
    Pieza::setPrecio(precio);
}

void Llantas::setTraccion(float traccion) {
    Pieza::setVelocidad(traccion);
}
float Llantas::getTraccion()const {
    return _traccion;
}
//Item-----------------------------------------------
double Llantas::costo() {
    return this->ptrItem->costo() + this->_precio;
}

void Llantas::agregarDecoraciones(Item *) {

}

string Llantas::mostrarDecoraciones()   {
    stringstream s;
    s <<"\t-Llantas: " << getNombre() << "\n\tID: " << getId() <<"\tPrecio: " <<getPrecio() << "\tMejora en traccion: " << getTraccion()<< " Estado: ";
    this->getEstado() ? s<< YELLOW"Usado" << RESET: s << "Disponible"; //condicion ? exprecion1 : condicion2 (es otra forma de usar if)
    s << endl;
    return s.str();
}




//void Llantas::incrementoDecremento(bool incremento) {
//
//}

int Llantas::getContador() {
    return 0;
}
//ostream &operator<<(ostream &os, const Item &Item){
//    os << "\tLlantas: " << Item.getNombre() << "\nID: " << Item.getId() <<"\tPrecio: " <<Item.getPrecio() << "\tMejora en traccion: " << Item.getTraccion()<< endl;
//    os << "Piezas: "<< endl;
//    return os;
//}
bool Llantas::operator==(const string& id) const {
    return this->_id == id;
}

bool Llantas::operator!=(const string& id) const {
    return (this->_id != id);
}

Item *Llantas::cargaDatos(Json::Value objeto) {
    string ident = objeto["ID"].asString();
    string nombre = objeto["Nombre"].asString();
    double precio = objeto["Precio"].asDouble();
    float traccion = objeto["Traccion"].asFloat();
    bool estado = objeto["Estado"].asBool();
    //hay que ver lo de la lista
    return new Llantas(ident, nombre, precio, traccion);
}

Json::Value Llantas::salvaDatos(Item &veh) {
    Json::Value event;
    event["ID"] = veh.getId();
    event["Nombre"] = veh.getNombre();
    event["Precio"] = veh.getPrecio();
    event["Traccion"] = veh.getTraccion();
    return event;
}
//Llantas::Llantas(const string nombre, float traccion) :Item(){
//    this->nombre = nombre;
//    this->traccion = traccion;
//}
//Llantas::~Llantas() {}
//
//const string Llantas::getNombre2() const {
//    return nombre;
//}
//
//void Llantas::setNombre2(const string nombre) {
//    Llantas::nombre = nombre;
//}
//
//const float Llantas::getTraccion2() const {
//    return traccion;
//}
//
//void Llantas::setTraccion2(const float traccion)  {
//    this->traccion = traccion;
//}
void Llantas::mejorarTraccion() {
//    float factor = 1.3;
//    float traccionActual = this->getTraccion2();
//    float nuevaTraccion = traccionActual * factor;
//    this->setTraccion2(nuevaTraccion);
}

ostream &operator<<(ostream &os, const Llantas &llantas) {
    os << " nombre: " << llantas.getNombre() <<"Traccion mejorada: "<< llantas.getTraccion();
    return os;
}


