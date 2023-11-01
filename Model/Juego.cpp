//
// Created by mauri on 24/10/2023.
//

#include "Juego.h"

Juego::Juego(Jugador* j){
    _tienda = new Tienda();
     _jugador = j;
     _infoJug = "infoJugador.txt";
     _listaVehiculo = "lisVehiculos.txt";
     _listaVehiculoDefecto = "lisVehiculosDefecto.txt" ;
     _listaPieza = "lisPiezaVehiculo.txt";
     _listaPiezaTienda = "lisPiezaTienda";
}

Juego::~Juego() {
     if(_tienda != nullptr) delete _tienda;
     if(_jugador != nullptr) delete _jugador;
}


Jugador *Juego::recuperarJugador() {
    //recupera jugador
    Lista<Jugador,-1> tempL;
    ifstream rec ("infoJugador.txt");
    tempL = *_archJug.cargarDatos(rec);
    Jugador* jug = tempL.getFirst()->getInfo();

    //recupera vehiculo
    ifstream carVe ("lisVehiculos.txt");
    Archivos<Lista<Vehiculo, -1>, Vehiculo> archVe;
    if(!carVe.fail()) {
        jug->setListaVehiculos(archVe.cargarDatos(carVe));
    }

    Lista<Pieza,-1>* listaP = new Lista<Pieza,-1>;
    ifstream fpieza ("lisPiezaVehiculo.txt");
    Archivos<Lista<Pieza,-1>, Pieza> archP;
    listaP = archP.cargarDatosPieza(fpieza);
    jug->setListaPieza(listaP);
    return jug;
}

string Juego::imprimirInfoJugador() {
    stringstream s;
    s<<*_jugador;
    return s.str();
}

string Juego::imprimirVehiculosJugador() {
    return _jugador->getListaVehiculo()->toString();
}
string Juego::imprimirPiezasJugador() {
    return _jugador->getListaPieza()->toString();
}
Lista<Vehiculo, -1>& Juego::getListaVehiculoJugadcor(){
    return *_jugador->getListaVehiculo();
}
Lista<Pieza, -1>& Juego::getListaPiezasJugador(){
    return *_jugador->getListaPieza();
}
//Lista piezas vehiculos-------------------------
Lista<Pieza, -1>& Juego::getListaPiezasDeVehiculo(Vehiculo* vehiculo){
    return *vehiculo->getListaPiezas();
}

string Juego::imprimirListaPiezasVehiculo(Vehiculo* vehiculo){
    return getListaPiezasDeVehiculo(vehiculo).toString();
}


//Sub menu modificacion---------------------------------------------------
void Juego::quitarTodas() {
    for (int i = 0; i < getListaVehiculoJugadcor().counter(); ++i) {
        (getListaVehiculoJugadcor())[i].quitarTodasLasDecos();
    }
}

void Juego::quitarTodasEspe(Vehiculo* vehiculo) {
    if(!vehiculo->getListaPiezas()->emptyList()){
        vehiculo->quitarTodasLasDecos();
    }

}

void Juego::quitarUnaEspe(Vehiculo * vehiculo, string pieza) {
    vehiculo->quitarDecoraciones(pieza);
}

void Juego::modificarVehiculo(Vehiculo * vehiculo, string pieza) {
    vehiculo->agregarDecoraciones(buscarPiezaJugador(pieza));
}

//Utilidades---------------------------------------------------------------
Pieza *Juego::buscarPiezaJugador(string id) {
    return &(_jugador->getListaPieza()->search(id));
}

Vehiculo *Juego::buscarVehiculoJugador(string id ) {
    return &_jugador->getListaVehiculo()->search(id);
}

bool Juego::validarUso() {
    _jugador->getListaPieza();
    return false;
}

void Juego::ingresarListaTienda(Pieza* ptrP) {
     _tienda->ingresarPiezasTienda(ptrP);
}

string Juego::mostrarPiezasTienda() {
    return _tienda->mostrarPiezas();
}

void Juego::eliminarPiezasTienda(string id) {
    return _tienda->eliminarPiezas(id);
}

Lista<Pieza, -1> *Juego::getListaTiendaPiezas() {
    return _tienda->getLista();
}

Tienda *Juego::getTienda() {
    return _tienda;
}

double Juego::getDineroJugador() {
    return _jugador->getDinero();
}

void Juego::rebajoDeDinero(double pre) {
        _jugador->rebajoDeDinero(pre);
}

void Juego::agregarPiezaTienda(Pieza* p) {
       _jugador->agregarPiezaTienda(p);
}


bool Juego::guardarAlSalir() {
    ofstream ofVehiculo("lisVehiculos.txt");
    Archivos<Lista<Vehiculo,-1>, Vehiculo> archVehi;
    if(!_jugador->getListaVehiculo()->emptyList()) {
        archVehi.guardarDatos(*_jugador->getListaVehiculo(), ofVehiculo);
    }
    ofstream ofTienda("lisPiezaTienda.txt");
    Archivos<Lista<Pieza,-1>, Pieza> archPieza;
    if(!_tienda->getLista()->emptyList()){
        archPieza.guardarDatos(*_tienda->getLista(),ofTienda);
    }
    return true;
}
