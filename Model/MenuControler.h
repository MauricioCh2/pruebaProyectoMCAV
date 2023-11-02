//
// Created by mauri on 23/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_MENUCONTROLER_H
#define PRUEBAPROYECTOMCAV_MENUCONTROLER_H

#include"Tienda.h"
#include "Menu.h"
#include "Archivos.h"
#include "Juego.h"
#include "VehiculoBase.h"
class MenuControler {
private:
    Menu* _menu;
    Juego* _juego;
    Tienda* _tienda;
public:
    void inicio();
    bool llamarMenus();

    bool opMenuJugador();
    bool opsubMenuModificacion();
    bool opTienda();
    bool developMode();

    //cosas que creo que van separadas para el mvc
    Jugador* crearJugador();
    Vehiculo* crearVehiculo();
    Vehiculo* elegirVehiculo();
    bool elegirPieza(string&, Vehiculo&); //Este busca piezas y recive vehiculo para poder verificar que no tenga ya esta pieza
    bool elegirPiezaDeVehiculo(string&, Vehiculo&);  //Este busca e imprime las piezas del vehiculo que resive


    bool quitarTodasEspe();
    bool quitarUnaEspe();
    bool modifiarVehiculo();
//Tienda
    Pieza* ingresarPieza();
    bool elegirPiezaTienda(string&);
    bool eliminarPiezasTienda();
    bool usarTienda();
};


#endif //PRUEBAPROYECTOMCAV_MENUCONTROLER_H
