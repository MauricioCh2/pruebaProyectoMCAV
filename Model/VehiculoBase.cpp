//
// Created by mauri on 24/10/2023.
//

#include "VehiculoBase.h"
Vehiculo::Vehiculo(string id, string nombre, double precio, float traccion, float velocidad, float potencia)
        : Item(id, nombre, precio, traccion, velocidad, potencia) {
        _lisPiezas = new Lista<Pieza,-1>;
}

//VehiculoBase::VehiculoBase() {
//    this->cont = 0;
//}
//ITEM---------------------------------------------------------------
const string &Vehiculo::getId() const {
    return _id;
}

void Vehiculo::setId(const string &id) {
    _id = id;
}

const string &Vehiculo::getNombre() const {
    return _nombre;
}

void Vehiculo::setNombre(const string &nombre) {
    _nombre = nombre;
}

double Vehiculo::getPrecio() const {
    return _precio;
}

void Vehiculo::setPrecio(double precio) {
    _precio = precio;
}

float Vehiculo::getTraccion() const {
    return _traccion;
}

void Vehiculo::setTraccion(float traccion) {
    _traccion = traccion;
}

float Vehiculo::getVelocidad() const {
    return _velocidad;
}

void Vehiculo::setVelocidad(float velocidad) {
    _velocidad = velocidad;
}

float Vehiculo::getPotencia() const {
    return _potencia;
}

void Vehiculo::setPotencia(float potencia) {
    _potencia = potencia;
}

//Vehiculo-----------------------------------------------------------
double Vehiculo::costo() {
    return _precio;
}

void Vehiculo::agregarDecoraciones(Item * item) {
    _lisPiezas->insertFirst(dynamic_cast<Pieza *>(item));
}

string Vehiculo::mostrarDecoraciones() const  {
    stringstream s;
    s << "-----------------------------------------------------------------------------------------------------------------"<< endl;
    s << "Modelo: " << this->getNombre() << "\nID: " << this->getId() <<"\tPrecio: " <<this->getPrecio() << "\tTraccion: " << this->getTraccion()<< "\tVelocidad: " << this->getVelocidad()<< "\tPotencia: " << this->getPotencia()  << endl;
    s << "Piezas: "<< endl;
    return s.str();
}

void Vehiculo::incrementoDecremento() {
}
void Vehiculo::quitarDecoraciones(string id) {
    _lisPiezas->deleteEspe(id);

}

void Vehiculo::setItem(Item * v) {
    throw new Exceptions('n');
}

Item *Vehiculo::getItem() {
    throw new Exceptions('n');
    return nullptr;
}

Item *Vehiculo::getSiguiente() {
    throw new Exceptions('n');
    return nullptr;
}

int Vehiculo::getContador() {
    return 0;
}

//ostream &operator<<(ostream &os, const Item &Item){
//    os << "-----------------------------------------------------------------------------------------------------------------"<< endl;
//    os << "\tModelo: " << Item.getNombre() << "\nID: " << Item.getId() <<"\tPrecio: " <<Item.getPrecio() << "\tTraccion: " << Item.getTraccion()<< "\tVelocidad: " << Item.getVelocidad()<< "\tPotencia: " << Item.getPotencia()  << endl;
//    os << "Piezas: "<< endl;
//
//    return os;
//}
bool Vehiculo::operator==(const string& id) const {
    return this->_id == id;
}

bool Vehiculo::operator!=(const string& id) const {
    return (this->_id != id);
}

Vehiculo * Vehiculo::cargaDatos(Json::Value objeto) {
    string ident = objeto["ID"].asString();
    string nombre = objeto["Nombre"].asString();
    double precio = objeto["Precio"].asDouble();
    float traccion = objeto["Traccion"].asFloat();
    float velocidad = objeto["Velocidad"].asFloat();
    float potencia = objeto["Potencia"].asFloat();
    //hay que ver lo de la lista
    return new Vehiculo(ident, nombre, precio, traccion, velocidad, potencia);
}

Json::Value Vehiculo::salvaDatos(Item &veh) {
    Json::Value event;
    event["ID"] = veh.getId();
    event["Nombre"] = veh.getNombre();
    event["Precio"] = veh.getPrecio();
    event["Traccion"] = veh.getTraccion();
    event["Velocidad"] = veh.getVelocidad();
    event["Potencia"] = veh.getPotencia();

    return event;
}





