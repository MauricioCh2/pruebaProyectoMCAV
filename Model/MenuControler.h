//
// Created by mauri on 23/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_MENUCONTROLER_H
#define PRUEBAPROYECTOMCAV_MENUCONTROLER_H

#include "Menu.h"
#include "Archivos.h"
#include "Juego.h"
#include "VehiculoBase.h"
class MenuControler {
private:
    Menu* _menu;
    Juego* _juego;

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
    bool elegirVehiculo(Vehiculo&);
    bool elegirPieza(string&);
    bool elegirPieza(Pieza&);

    bool quitarTodas();
    bool quitarTodasEspe();
    bool quitarUnaEspe();
    bool modifiarVehiculo();

};


#endif //PRUEBAPROYECTOMCAV_MENUCONTROLER_H
