//
// Created by eolic on 22/10/2023.
//

#include "Motor.h"

Motor::Motor() {
    _nombre = "";
    _potencia = 0;
}
Motor::Motor(Item* v) {
    this->ptrItem = v;
    //this->cont= this->ptrItem->getContador()+1;
}
Motor::Motor(string nombre , string ident , double precio , float potencia) {
    //this->ptrItem = v;
    //this->cont= this->ptrItem->getContador()+1;
    this->_nombre = nombre;
    this->_id = ident;
    this->_precio = precio;
    this->_potencia = potencia;
    this->utilizada = false;

}
Motor::~Motor() {}
//Item-----------------------------------------------
double Motor::costo() {
    return costo() + this->_precio;
}

void Motor::agregarDecoraciones(Item *) {

}

string Motor::mostrarDecoraciones()   {
    stringstream s;
    s <<"\t-Motor: " << getNombre() << "\n\tID: " << getId() <<"\tPrecio: " <<getPrecio() << "\tMejora en potencia: " << getPotencia()<< " Estado: ";
    this->getEstado() ? s<< YELLOW"Usado" << RESET: s << "Disponible"; //condicion ? exprecion1 : condicion2 (es otra forma de usar if)
    s<< endl;
    return s.str();
}

//void Motor::incrementoDecremento(bool) {
//
//}

int Motor::getContador() {
    return 0;
}

bool Motor::operator==(const string& id) const {
    return this->_id == id;
}

bool Motor::operator!=(const string& id) const {
    return (this->_id != id);
}

Item *Motor::cargaDatos(Json::Value objeto) {

    string ident = objeto["ID"].asString();
    string nombre = objeto["Nombre"].asString();
    double precio = objeto["Precio"].asDouble();
    float potencia = objeto["Potencia"].asFloat();
    bool estado = objeto["Estado"].asBool();
    return new Motor(nombre, ident, precio, potencia);
}

Json::Value Motor::salvaDatos(Item &veh) {
    Json::Value event;
    event["Tipo"] = "Motor";
    event["ID"] = veh.getId();
    event["Nombre"] = veh.getNombre();
    event["Precio"] = veh.getPrecio();
    event["Potencia"] = veh.getPotencia();

    return event;
}



ostream &operator<<(ostream &os, const Motor &motor) {
    os << " nombre: " << motor.getNombre() << "Potencia mejorada: "<<motor.getPotencia();
    return os;
}





