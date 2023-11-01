//
// Created by mauri on 24/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_JUEGO_H
#define PRUEBAPROYECTOMCAV_JUEGO_H
#include "Tienda.h"
#include "Jugador.h"
#include "Archivos.h"
class Juego {
private:
    Tienda*_tienda;
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
    double getDineroJugador();
    void rebajoDeDinero(double);
    void agregarPiezaTienda(Pieza*);
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


    //Tienda
    void ingresarListaTienda(Pieza*);
    string mostrarPiezasTienda();
    void eliminarPiezasTienda(string);
    Lista<Pieza,-1>*getListaTiendaPiezas();
    Tienda*getTienda();

    bool guardarAlSalir();
};


#endif //PRUEBAPROYECTOMCAV_JUEGO_H
