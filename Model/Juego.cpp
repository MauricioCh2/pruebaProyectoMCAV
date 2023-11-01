//
// Created by mauri on 24/10/2023.
//

#include "Juego.h"

//Juego::Juego(bool op) {
//    if(op){
//        //llamar a metodo de creacion de jugador que se encuentra aqui
//    }
//}
Juego::Juego(Jugador* j){
    _tienda = new Tienda();
     _jugador = j;
     _infoJug = "infoJugador.txt";
     _listaVehiculo = "lisVehiculos.txt";
     _listaVehiculoDefecto = "lisVehiculosDefecto.txt" ;
     _listaPieza = "lisPiezaVehiculo.txt";
     _listaPiezaTienda = "lisPiezaTienda";
}

Jugador *Juego::recuperarJugador() {
    //recupera jugador
    Lista<Jugador,-1> tempL;
    ifstream rec ("infoJugador.txt");
    tempL = *_archJug.cargarDatos(rec);
    Jugador* jug = tempL.getFirst()->getInfo();

    //recupera vehiculo
    //Lista<Vehiculo,-1>  listaV;
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

//--------------------------------------------------------------------------------------------------------BORRAR-----------
 //pieza ("nombre", "ID", precio, float )
//    Pieza* piezaQ1 = new Motor("interno","M1", 1700, 25);
//    Pieza* piezaQ2 = new Motor("alto rendimiento","M2", 2300, 50);
//    Pieza* piezaQ3 = new Llantas(" AA alta traccion","Ll1", 220, 80);
//    Pieza* piezaQ4 = new Llantas(" B traccion normal","Ll2", 1100, 45);
//    Pieza* piezaQ5 = new Llantas(" C traccion baja","Ll3", 600, -10);
//    Pieza* piezaQ6 = new Nitro(" Basico","N1", 1000, 30);
//    Pieza* piezaQ7 = new Nitro(" intermedio","N2", 1500, 20);
//    Pieza* piezaQ8 = new Nitro(" Altro rendimiento","N3", 2000, 30);
//    Lista<Pieza, -1>* lisPQ = new Lista<Pieza, -1>;
//    lisPQ->insertEnd(piezaQ1);
//    lisPQ->insertEnd(piezaQ2);
//    lisPQ->insertEnd(piezaQ3);
//    lisPQ->insertEnd(piezaQ4);
//    lisPQ->insertEnd(piezaQ5);
//    lisPQ->insertEnd(piezaQ6);
//    lisPQ->insertEnd(piezaQ7);
//    lisPQ->insertEnd(piezaQ8);


    //ofstream piezas ("lisPiezaVehiculo.txt");
    //archP.guardarDatos(listaP,piezas);
    //jug->setListaPieza(&listaP);

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
        return true;
    }
    return false;
}
