//
// Created by eolic on 23/10/2023.
//

#pragma once
#include"../Model/Utilities.h"
#include"../Model/Juego.h"
#include"../View/MenuVehiculoB.h"
#include"ControlVehiculo.h"

class ControlJugador {
private:
  Juego* _juego;
  MenuVehiculo* mV;
  ControlVehiculo* cV;
public:
    bool opMenuJugador();
};

