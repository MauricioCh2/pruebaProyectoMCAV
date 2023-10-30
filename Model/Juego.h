//
// Created by mauri on 24/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_JUEGO_H
#define PRUEBAPROYECTOMCAV_JUEGO_H

#include "Jugador.h"
#include "Archivos.h"
class Juego {
private:
Jugador* _jugador;
Archivos<Lista<Jugador, -1>, Jugador> _archJug;
string _infoJug;
string _listaVehiculo;
string _listaVehiculoDefecto;
string _listaPieza;
string _listaPiezaTienda;

public:
    Juego(Jugador*);
    Jugador* recuperarJugador();
    //Jugador-----------------------------------------
    string imprimirInfoJugador();
    string imprimirVehiculosJugador();
    string imprimirPiezasJugador();
    Lista<Vehiculo, -1>& getListaVehiculoJugadcor();
    Lista<Pieza, -1>& getListaPiezasJugador();
    bool validarUso();
    //Lista piezas vehiculos-------------------------
    Lista<Pieza, -1>& getListaPiezasDeVehiculo(Vehiculo* );
    string imprimirListaPiezasVehiculo( Vehiculo*);

    //Submenu modificacion----------------------------
    void quitarTodas();
    void quitarTodasEspe(Vehiculo*);//Quita todas las piezas de un vehiculo especifico
    void quitarUnaEspe(Vehiculo*,string);//
    void modificarVehiculo(Vehiculo*, string);

    //Utiles------------------------------------------
    Pieza* buscarPiezaJugador(string);
    Vehiculo* buscarVehiculoJugador(string);
};


#endif //PRUEBAPROYECTOMCAV_JUEGO_H
