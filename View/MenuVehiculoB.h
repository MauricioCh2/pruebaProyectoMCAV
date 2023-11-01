//
// Created by eolic on 23/10/2023.
//

#pragma once
#include"MenuPiezas.h"
#include "../Model/Jugador.h"
#include "../Model/Juego.h"

class MenuVehiculo {
private:
    Juego*_juego;
    MenuPiezas* mP;
public:
    MenuVehiculo();
    Vehiculo*ingresarVehiculo();
    string subMenuModVehiculos();
    bool elegirVehiculo(Vehiculo&);
    bool quitarTodasEspe();
    bool quitarUnaEspe();
    bool modifiarVehiculo();
};

