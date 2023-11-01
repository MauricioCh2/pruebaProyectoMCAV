//
// Created by eolic on 22/10/2023.
//

#include "Llantas.h"

Llantas::Llantas(string nombre , string ident , double precio, float traccion) {
    this->_nombre = nombre;
    this->_id = ident;
    this->_precio = precio;
    this->_traccion = traccion;
    this->utilizada = false;
}
Llantas::~Llantas() {}

//Item-----------------------------------------------
string Llantas::mostrarDecoraciones()   {
    stringstream s;
    s <<"\t-Llantas: " << getNombre() << "\n\tID: " << getId() <<"\tPrecio: " <<getPrecio() << "\tMejora en traccion: " << getTraccion()<< " Estado: ";
    this->getEstado() ? s<< YELLOW"Usado" << RESET: s << "Disponible"; //condicion ? exprecion1 : condicion2 (es otra forma de usar if)
    s << endl;
    return s.str();
}

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
    return new Llantas(nombre, ident, precio, traccion);
}

Json::Value Llantas::salvaDatos(Item &veh) {
    Json::Value event;
    event["Tipo"] = "Llanta";
    event["ID"] = veh.getId();
    event["Nombre"] = veh.getNombre();
    event["Precio"] = veh.getPrecio();
    event["Traccion"] = veh.getTraccion();
    return event;
}

ostream &operator<<(ostream &os, const Llantas &llantas) {
    os << " nombre: " << llantas.getNombre() <<"Traccion mejorada: "<< llantas.getTraccion();
    return os;
}


