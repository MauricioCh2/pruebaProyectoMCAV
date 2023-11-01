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

//float Vehiculo::getVelocidad() const {
//    return _velocidad;
//}

//void Vehiculo::setVelocidad(float velocidad) {
//    _velocidad = velocidad;
//}

float Vehiculo::getPotencia() const {
    return _potencia;
}

void Vehiculo::setPotencia(float potencia) {
    _potencia = potencia;
}

//Vehiculo----------------------------------------------------------
Lista<Pieza,-1>* Vehiculo::getListaPiezas(){
    return _lisPiezas;
}
void Vehiculo::quitarTodasLasDecos(){

    for (int i = 0; i < _lisPiezas->counter() ; ++i) {
         (*_lisPiezas)[i].setEstado(false);
        this->incrementoDecremento(true,(&(*_lisPiezas)[i]));
        //_lisPiezas->deleteEspe((*_lisPiezas)[i].getId());
        _lisPiezas->deleteEnd();
    }
    _lisPiezas = new Lista<Pieza,-1>;
}
bool Vehiculo::validarUso(string p){
    if(!_lisPiezas->exist(p)){
        return false;
    }
    return  _lisPiezas->search(p).getEstado();
}
//Item----------------------------------------
double Vehiculo::costo() {
    double pre = _precio;
    if(!_lisPiezas->emptyList()){
        for (int i = 0; i < _lisPiezas->counter() ; ++i) {
            pre = pre + (*_lisPiezas)[i].getPrecio();
        }
    }

    return pre;
}

void Vehiculo::agregarDecoraciones(Pieza * item) {
    _lisPiezas->insertFirst(dynamic_cast<Pieza *>(item));
    dynamic_cast<Pieza *>(item)->setEstado(true);
    this->incrementoDecremento(true, item);


   //cout<< "Prueba de velocidad: "<< getVelocidad()<<endl;
    //cout<< "Prueba de velocidad: "<< _velocidad<<endl;
    //cout<< "Prueba de velocidad: "<< mostrarDecoraciones()<<endl;
}

string Vehiculo::mostrarDecoraciones()  {
    stringstream s;
    s << "-----------------------------------------------------------------------------------------------------------------"<< endl;
    s << "Modelo: " << this->getNombre() << "\nID: " << this->getId() <<"\tPrecio: " <<this->costo() << "\tTraccion: " << this->getTraccion()<< "\tVelocidad: " << this->getVelocidad()<< "\tPotencia: " << this->getPotencia()  << endl;
    s << "Piezas: "<< endl;
    if(!_lisPiezas->emptyList()){
        s << _lisPiezas->toString();
    }
    else{
        s <<"Este vehiculo no cuenta con modificacioes";
    }
    return s.str();
}

void Vehiculo::incrementoDecremento(bool incremento, Pieza* item) {
    if (incremento) {
        if (typeid(*item).name() == typeid(Motor).name()) {
            this->setPotencia(this->_potencia + item->getPotencia());
        }
        if (typeid(*item).name() == typeid(Nitro).name()) {
            this->setVelocidad(_velocidad + item->getVelocidad());
        }
        if (typeid(*item).name() == typeid(Llantas).name()) {
            _traccion = _traccion + item->getTraccion();
        }
    } else {
        if (typeid(*item).name() == typeid(Motor).name()) {
            this->setPotencia(this->_potencia - item->getPotencia());
        }
        if (typeid(*item).name() == typeid(Nitro).name()) {
            this->setVelocidad(_velocidad - item->getVelocidad());
        }
        if (typeid(*item).name() == typeid(Llantas).name()) {
            _traccion = _traccion - item->getTraccion();
        }
    }
}

void Vehiculo::quitarDecoraciones(string id) {
    _lisPiezas->search(id).setEstado(false);
    incrementoDecremento(false, &_lisPiezas->search(id));
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

    Lista<Pieza,-1>* lisAux = new Lista<Pieza,-1>;

    Vehiculo* vehiculo = nullptr;
    string ident = objeto["ID"].asString();
    string nombre = objeto["Nombre"].asString();
    double precio = objeto["Precio"].asDouble();
    float traccion = objeto["Traccion"].asFloat();
    float velocidad = objeto["Velocidad"].asFloat();
    float potencia = objeto["Potencia"].asFloat();
    vehiculo = new Vehiculo(ident, nombre, precio, traccion, velocidad, potencia);
        Json::Value piezasJson = objeto["Piezas"];


        for (int i = 0; i < piezasJson.size(); ++i) {
            Json::Value objetoActual = piezasJson[i];
            string tipoPieza = objetoActual["Tipo"].asString();
            Motor *nuevaMotor = new Motor(" ");
            Nitro *nuevaNitro = new Nitro(" ");
            Llantas *nuevaLLanta = new Llantas(" ");
            if (tipoPieza == "Motor") {
                nuevaMotor = dynamic_cast<Motor *>(nuevaMotor->cargaDatos(objetoActual));
                lisAux->insertEnd(nuevaMotor);
                //vehiculo->agregarDecoraciones();
            } else if (tipoPieza == "Nitro") {
                nuevaNitro = dynamic_cast<Nitro *>(nuevaNitro->cargaDatos(objetoActual));
                lisAux->insertEnd(nuevaNitro);
            } else if (tipoPieza == "Llanta") {
                nuevaLLanta = dynamic_cast<Llantas *>(nuevaLLanta->cargaDatos(objetoActual));
                lisAux->insertEnd(nuevaLLanta);
            } // Supongamos que tienes un método cargaDatos en la clase Pieza

        }
    for(int i=0; i <lisAux->counter(); i++){
        (*lisAux)[i].setEstado(true);
        vehiculo->agregarDecoraciones(&(*lisAux)[i]);
    }
   // hay que ver lo de la lista
    return vehiculo;

}

Json::Value Vehiculo::salvaDatos(Item &veh) {
    Json::Value event;
    event["ID"] = veh.getId();
    event["Nombre"] = veh.getNombre();
    event["Precio"] = veh.getPrecio();
    event["Traccion"] = veh.getTraccion();
    event["Velocidad"] = veh.getVelocidad();
    event["Potencia"] = veh.getPotencia();

    // agregamos piezas en caso de ser necesario
    if(!getListaPiezas()->emptyList()){
        Json::Value piezasJson(Json::arrayValue);
        for (int i = 0; i < _lisPiezas->counter(); ++i) {
            piezasJson.append((*_lisPiezas)[i].salvaDatos((*_lisPiezas)[i]));
        }
        event["Piezas"] = piezasJson;
    }
    return event;
}





