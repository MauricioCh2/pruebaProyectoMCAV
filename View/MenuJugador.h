//
// Created by eolic on 23/10/2023.
//

#pragma once

#include "../Model/Jugador.h"

class MenuJugador {
public:
    static Jugador* ptrJ;
    /*static int menuJ();*/
    static string menuJugador();
    static Jugador* ingresarJugador();
    static void mostrarJugadores();
};

