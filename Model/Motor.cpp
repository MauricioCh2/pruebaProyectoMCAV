//
// Created by eolic on 22/10/2023.
//

#include "Motor.h"

Motor::Motor() {
    _nombre = "";
    _potencia = 0;
}
//Motor::Motor(const string nombre, float potencia) :  Item(){
//    this->_nombre = nombre;
//    this->_potencia = potencia;
//}
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
//ITEM----------------------------------------
const string &Motor::getId() const {
    return Pieza::getId();
}

void Motor::setId(const string &id) {
    Pieza::setId(id);
}

const string &Motor::getNombre() const {
    return Pieza::getNombre();
}

void Motor::setNombre(const string &nombre) {
    Pieza::setNombre(nombre);
}

double Motor::getPrecio() const {
    return Pieza::getPrecio();
}

void Motor::setPrecio(double precio) {
    Pieza::setPrecio(precio);
}

void Motor::setPotencia(float potencia) {
    Pieza::setPotencia(potencia);
}
float Motor::getPotencia()const {
    return _potencia;
}
//Item-----------------------------------------------
double Motor::costo() {
    return this->ptrItem->costo() + this->_precio;
}

void Motor::agregarDecoraciones(Item *) {

}

string Motor::mostrarDecoraciones()  const {
    stringstream s;
    s <<"\t-Motor: " << getNombre() << "\n\tID: " << getId() <<"\tPrecio: " <<getPrecio() << "\tMejora en potencia: " << getVelocidad()<< " Estado: ";
    this->getEstado() ? s<< YELLOW"Usado" << RESET: s << "Disponible"; //condicion ? exprecion1 : condicion2 (es otra forma de usar if)
    s<< endl;



    return s.str();
}

void Motor::incrementoDecremento() {

}

int Motor::getContador() {
    return 0;
}

//ostream &operator<<(ostream &os, const Item &Item){
//    os << "\tMotor: " << Item.getNombre() << "\nID: " << Item.getId() <<"\tPrecio: " <<Item.getPrecio() << "\tMejora en potencia: " << Item.getPotencia()<< endl;
//    os << "Piezas: "<< endl;
//    return os;
//}
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
    //hay que ver lo de la lista
    return new Motor(ident, nombre, precio);
}

Json::Value Motor::salvaDatos(Item &veh) {
    Json::Value event;
    event["ID"] = veh.getId();
    event["Nombre"] = veh.getNombre();
    event["Precio"] = veh.getPrecio();

    return event;
}

void Motor::mejorarPotencia() {

}

//const string Motor::getNombre2() const {
//    return nombre;
//}
//
//void Motor::setNombre2(const string nombre) {
//    this->nombre = nombre;
//}
//
//void Motor::mejorarPotencia() {           //Preguntar a que valor se debe hacer la mejora.
//    float potenciaActual = this->getPotencia2();
//    float nuevaPotencia = pow(potenciaActual, 1.1);  //10%
//    this->setPotencia2(nuevaPotencia);
//}
//
//void Motor::setPotencia2(const float potencia) {
//    this->potencia=potencia;
//}
//
//const float Motor::getPotencia2()const {
//    return potencia;
//}




ostream &operator<<(ostream &os, const Motor &motor) {
    os << " nombre: " << motor.getNombre() << "Potencia mejorada: "<<motor.getPotencia();
    return os;
}





