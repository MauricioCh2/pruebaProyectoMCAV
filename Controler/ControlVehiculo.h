//
// Created by eolic on 25/10/2023.
//

#pragma once
#include"../Model/Utilities.h"
#include"../Model/Juego.h"
#include"../View/MenuVehiculoB.h"

class ControlVehiculo {
private:
    Juego* _juego;
    MenuVehiculo* mV;
public:
    bool opsubMenuModificacion();
};

