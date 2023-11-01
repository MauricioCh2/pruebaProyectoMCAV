//
// Created by eolic on 31/10/2023.
//

#pragma once
#include"../Model/Utilities.h"
#include"../Model/VehiculoBase.h"
#include"../Model/Juego.h"

class MenuPiezas {
private:
    Juego* _juego;
public:

    bool elegirPieza(string&, Vehiculo&); //Este busca piezas y recive vehiculo para poder verificar que no tenga ya esta pieza
    bool elegirPiezaDeVehiculo(string&, Vehiculo&);  //Este busca e imprime las piezas del vehiculo que resive
};

