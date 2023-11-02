//
// Created by eolic on 22/10/2023.
//

#include "Nitro.h"
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

string Nitro::mostrarDecoraciones()   {
    stringstream s;
    s <<"\t-Nitro: " << getNombre() << "\n\tID: " << getId() <<"\tPrecio: " <<getPrecio() << "\tMejora en Velocidad: " << getVelocidad()<< " Estado: ";
    this->getEstado() ? s<< YELLOW"Usado" << RESET: s << "Disponible"; //condicion ? exprecion1 : condicion2 (es otra forma de usar if)
    s << endl;
    return s.str();
}

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


