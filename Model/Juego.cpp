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
    Lista<Vehiculo,-1>  listaV;
    ifstream carVe ("lisVehiculos.txt");
    Archivos<Lista<Vehiculo, -1>, Vehiculo> archVe;
    if(!carVe.fail()) {
        jug->setListaVehiculos(archVe.cargarDatos(carVe));
    }

//--------------------------------------------------------------------------------------------------------BORRAR-----------
// pieza ("nombre", "ID", precio, float )
    Pieza* piezaQ1 = new Motor("interno","M1", 1700, 25);
    Pieza* piezaQ2 = new Motor("alto rendimiento","M2", 2300, 50);
    Pieza* piezaQ3 = new Llantas(" AA alta traccion","Ll1", 80, 220);
    Pieza* piezaQ4 = new Motor("M1","Motor interno", 1700, 25);
    Pieza* piezaQ5 = new Motor("M1","Motor interno", 1700, 25);
    Pieza* piezaQ6 = new Motor("M1","Motor interno", 1700, 25);
    Pieza* piezaQ7 = new Motor("M1","Motor interno", 1700, 25);
    Pieza* piezaQ8 = new Nitro(" Altro rendimiento","N1", 2000, 30);
    Lista<Pieza, -1>* lisPQ = new Lista<Pieza, -1>;
    lisPQ->insertFirst(piezaQ1);
    lisPQ->insertFirst(piezaQ2);
    lisPQ->insertFirst(piezaQ3);
//    lisPQ->insertFirst(piezaQ4);
//    lisPQ->insertFirst(piezaQ5);
//    lisPQ->insertFirst(piezaQ6);
//    lisPQ->insertFirst(piezaQ7);
    lisPQ->insertFirst(piezaQ8);
    ofstream piezas ("lisPiezas.txt");
    Archivos<Lista<Pieza, -1>,Pieza> archPiezas;
    archPiezas.guardarDatos(*lisPQ,piezas);

    jug->setListaPieza(lisPQ);

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

void Juego::quitarTodasEspe(Vehiculo * vehiculo) {
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
