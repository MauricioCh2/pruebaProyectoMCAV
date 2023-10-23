//
// Created by eolic on 21/10/2023.
//

#include "Jugador.h"


Jugador::Jugador() {
    id = "";
    nombre = "";
    dinero = 0.0;

}
Jugador::Jugador(const string id, const string nombre, float dinero) : id(id), nombre(nombre), dinero(dinero)/*ptrV(ptrV)*/ {}

Jugador::~Jugador() {
//if(ptrV!=NULL)
//delete ptrV;
}

const string Jugador::getId() const {
    return id;
}

void Jugador::setId(const string id) {
    this->id = id;
}

const string Jugador::getNombre() const {
    return nombre;
}

void Jugador::setNombre(const string nombre) {
    this->nombre = nombre;
}

float Jugador::getDinero() const {
    return dinero;
}

void Jugador::setDinero(float dinero) {
    this->dinero = dinero;
}

ostream &operator<<(ostream &os, const Jugador *jugador) {
    os << "id: " << jugador->id << " nombre: " << jugador->nombre << " dinero: " << jugador->dinero;
    return os;
}

void Jugador::agregarVehiculos(Vehiculo* veh) {
    ptrV->insertEnd(veh);
}

void Jugador::mostrarVehiculos() const {

    cout << "Jugador: " << nombre << endl;
    for (int i = 0; i < ptrV->counter(); i++) {
        Vehiculo* v;
        try {
            Nodo<Vehiculo>* nodo = ptrV->searchInPos(i);
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

Lista<Vehiculo, 10> *Jugador::getLista() {
    return ptrV;
}

void Jugador::setLista(Lista<Vehiculo, 10> *pV) {
    ptrV = pV;
}


