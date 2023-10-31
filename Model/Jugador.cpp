//
// Created by eolic on 21/10/2023.
//

#include "Jugador.h"


Jugador::Jugador() {
    _id = "";
    _nombre = "";
    _dinero = 0.0;

}
Jugador::Jugador(const string id, const string nombre, double dinero) : _id(id), _nombre(nombre), _dinero(dinero)/*ptrV(ptrV)*/ {
    _lisVehiculo = new Lista<Vehiculo,-1>;
}

Jugador::~Jugador() {
//if(ptrV!=NULL)
//delete ptrV;
}

const string Jugador::getId() const {
    return _id;
}

void Jugador::setId(const string id) {
    this->_id = id;
}

const string Jugador::getNombre() const {
    return _nombre;
}

void Jugador::setNombre(const string nombre) {
    this->_nombre = nombre;
}

double Jugador::getDinero() const {
    return _dinero;
}

void Jugador::setDinero(double dinero) {
    this->_dinero = dinero;
}

ostream &operator<<(ostream &os,  Jugador &jugador) {
    os << ORANGE"Jugador:\n"<<RESET"id: " << jugador._id << "\nnombre: " << jugador._nombre << "\ndinero: " << jugador._dinero;
    os << "\n------------------------------------------------\n";
    return os;
}

void Jugador::agregarVehiculos(Vehiculo* veh) {
    _lisVehiculo->insertEnd(veh);
}

void Jugador::mostrarVehiculos() const {

    cout << "Jugador: " << _nombre << endl;
    for (int i = 0; i < _lisVehiculo->counter(); i++) {
        Vehiculo* v;
        try {
            Nodo<Vehiculo>* nodo = _lisVehiculo->searchInPos(i);
            // Obtener la información del nodo
            v = nodo->getInfo();
        }
        catch (Exceptions* e) {
            // Manejar la excepción si no se encuentra el nodo
            print(e->what());
            return;
        }

        // SIN EL PRECIO
        cout << "Vehiculo: " << v->getNombre() << endl;
        cout << "Traccion: " << v->getTraccion() << endl;
        cout << "Velocidad: " << v->getVelocidad() << endl;
        cout << "Potencia: " << v->getPotencia() << endl;

    }
}

Lista<Vehiculo, -1> *Jugador::getListaVehiculo() {
    return _lisVehiculo;
}
Lista<Pieza, -1> *Jugador::getListaPieza() {
    return _lisPiezas;
}
void Jugador::setListaVehiculos(Lista<Vehiculo, -1> *pV) {
    _lisVehiculo = pV;
}
void Jugador::setListaPieza (Lista<Pieza,-1>* pP) {
    _lisPiezas = pP;
}
bool Jugador::operator==(const string& id) const {
    return this->_id == id;
}

bool Jugador::operator!=(const string& id) const {
    return (this->_id != id);
}
//Archivos
Jugador *Jugador::cargaDatos(Json::Value objeto) {
    string ident = objeto["ID"].asString();
    string nombre = objeto["Nombre"].asString();
    double dinero = objeto["Dinero"].asDouble();
    //hay que ver lo de la lista
    return new Jugador(ident, nombre, dinero);
}

Json::Value Jugador::salvaDatos(Jugador& jug) {
    Json::Value event;
    event["ID"] = jug.getId();
    event["Nombre"] = jug.getNombre();
    event["Dinero"] = jug.getDinero();
    //ver lo de la lista x2
    return event;
}

void Jugador::cargarLista() {
    ifstream vehiculos ("lisVechiculos.txt");
    //_archV.cargarDatos(*_lisVehiculo,vehiculos);
    //this->setLista();
}


