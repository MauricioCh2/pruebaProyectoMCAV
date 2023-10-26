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
}

Jugador *Juego::recuperarJugador() {
    Lista<Jugador,-1> tempL;
    ifstream rec ("lisJugador.txt");
    _archJug.cargarDatos(tempL, rec );
    Jugador* jug = tempL.getFirst()->getInfo();

    ifstream carVe ("lisVehiculos.txt");
    Lista<Vehiculo,-1>*  listaV = new  Lista<Vehiculo,-1>;
    Archivos<Lista<Vehiculo, -1>, Vehiculo> archVe;

//--------------------------------------------------------------------------------------------------------BORRAR-----------
    Vehiculo* quemado1 = new Vehiculo("V1", "Ferrari 458 Italia Coupe", 15000, 21, 250, 562);
    Vehiculo* quemado2 = new Vehiculo("V2", "Tesla Model X", 17000, 22, 180, 670 );
    Vehiculo* quemado3 = new Vehiculo("V3", "Maserati MC12 Stradale", 17000, 18, 255, 450 );
    Lista<Vehiculo, -1>* lisQ = new Lista<Vehiculo, -1>;
    lisQ->insertFirst(quemado1);
    lisQ->insertFirst(quemado2);
    lisQ->insertFirst(quemado3);
    ofstream carVeD ("lisVehiculosD.txt");
    Archivos<Lista<Vehiculo, -1>,Vehiculo> arch;
    //arch.guardarDatos(*lisQ,carVeD );
    jug->setListaVehiculos(lisQ);
//--------------------------------------------------------------------------------------------------------BORRAR-----------
    Pieza* piezaQ1 = new Motor("M1","interno", 1700, 25);
    Pieza* piezaQ2 = new Motor("M1","alto rendimiento", 2300, 50);
    Pieza* piezaQ3 = new Llantas("Ll1"," AA alta traccion", 80, 220);
    Pieza* piezaQ4 = new Motor("M1","Motor interno", 1700, 25);
    Pieza* piezaQ5 = new Motor("M1","Motor interno", 1700, 25);
    Pieza* piezaQ6 = new Motor("M1","Motor interno", 1700, 25);
    Pieza* piezaQ7 = new Motor("M1","Motor interno", 1700, 25);
    Pieza* piezaQ8 = new Nitro("M1"," Altro rendimiento", 2000, 30);
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


    //archVe.cargarVehiculos((*listaV),carVe);

    //jug->setLista(listaV);
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
//Sub menu modificacion---------------------------------------------------
void Juego::quitarTodas() {

}

void Juego::quitarTodasEspe(Vehiculo *) {

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
