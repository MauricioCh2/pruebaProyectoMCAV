//
// Created by mauri on 24/10/2023.
//

#include "VehiculoBase.h"

Vehiculo::Vehiculo(string id, string nombre, double precio, float traccion, float velocidad, float potencia)
        : Item(id, nombre, precio, traccion, velocidad, potencia) {
        _lisPiezas = new Lista<Pieza,-1>;
}


Vehiculo::~Vehiculo() {
     if(_lisPiezas!= nullptr) delete _lisPiezas;
}
Lista<Pieza,-1>* Vehiculo::getListaPiezas(){
    return _lisPiezas;
}

void Vehiculo::quitarTodasLasDecos(){

    for (int i = 0; i < _lisPiezas->counter() ; ++i) {     //Recorre la lista piezas
         (*_lisPiezas)[i].setEstado(false);                //Cambia/Setea el estado de la pieza a falso, lo que indica que ya no esta disponible.
        this->incrementoDecremento(true,(&(*_lisPiezas)[i]));  //Llama al metodo incremento/decremento
        _lisPiezas->deleteEnd();  //Borra la lista iniciando desde el final
    }
    _lisPiezas = new Lista<Pieza,-1>;  //Crea una nueva lista de piezas vacía y la asigna a _lisPiezas
}
bool Vehiculo::validarUso(string p){        //Verifica si la pieza esta siendo usada o no
    if(!_lisPiezas->exist(p)){
        return false;
    }
    return  _lisPiezas->search(p).getEstado();
}
//Item----------------------------------------
double Vehiculo::costo() {    //Este método calcula el precio total del vehiculo, con todas las decoraciones
    double pre = _precio;
    if(!_lisPiezas->emptyList()){
        for (int i = 0; i < _lisPiezas->counter() ; ++i) {
            pre = pre + (*_lisPiezas)[i].getPrecio();
        }
    }

    return pre;
}

void Vehiculo::agregarDecoraciones(Pieza * item) { //Agrega las piezas.
    _lisPiezas->insertFirst(dynamic_cast<Pieza *>(item)); //Usa el operador dynamic_cast para convertir el puntero item al tipo Pieza* e insertarlo a la lista piezas
    dynamic_cast<Pieza *>(item)->setEstado(true); //Setea el estado a verdadero
    this->incrementoDecremento(true, item);
}

string Vehiculo::mostrarDecoraciones()  {  //Devuelve la informacion del vehiculo con sus decoraciones/Piezas (Lista).
    stringstream s;
    s << "-----------------------------------------------------------------------------------------------------------------"<< endl;
    s << "Modelo: " << this->getNombre() << "\nID: " << this->getId() <<"\tPrecio: " <<this->costo() << "\tTraccion: " << this->getTraccion()<< "\tVelocidad: " << this->getVelocidad()<< "\tPotencia: " << this->getPotencia()  << endl;
    s << "Piezas: "<< endl;
    if(!_lisPiezas->emptyList()){
        s << _lisPiezas->toString();
    }
    else{
        s <<"Este vehiculo no cuenta con modificacioes";   //Si la lista esta vacia muestra este mensaje
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

void Vehiculo::quitarDecoraciones(string id) {  //Este metodo elimina las decoraciones/Piezas de un vehiculo
    _lisPiezas->search(id).setEstado(false); //Busca con el "id" y setea el estado a "False",el objeto devuelto es una referencia a la pieza correspondiente.
    incrementoDecremento(false, &_lisPiezas->search(id));  //Actualiza el número de piezas en el vehículo.
    _lisPiezas->deleteEspe(id);  //Elimina la pieza con ese identificador
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
            }

        }
    for(int i=0; i <lisAux->counter(); i++){
        (*lisAux)[i].setEstado(true);
        vehiculo->agregarDecoraciones(&(*lisAux)[i]);
    }
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






