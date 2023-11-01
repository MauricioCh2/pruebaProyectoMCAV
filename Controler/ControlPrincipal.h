//
// Created by eolic on 30/10/2023.
//

#pragma once
#include"ControlTienda.h"
#include"ControlJugador.h"
#include"ControlItems.h"
#include"../Model/Juego.h"
#include"../View/MenuPrincipal.h"
#include"../View/MenuTienda.h"
#include"../View/MenuJugador.h"


class ControlPrincipal {
private:
    Juego*_juego;
    MenuPrincipal* mP;
    MenuJugador* mJ;
    ControlJugador*  cJ;
    ControlTienda* cT;
    ControlItems* cI;
    MenuTienda*mT;
public:
    ControlPrincipal();
    void inicio();
    bool llamarMenus();
};

