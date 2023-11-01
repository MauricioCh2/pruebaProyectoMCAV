//
// Created by eolic on 23/10/2023.
//

#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal() {}

string MenuPrincipal::menuInicio() {
    stringstream s;
    s<< YELLOW"<<<<Need for Speeed>>>"<<RESET<<endl;
    s<< "[0] Continuar (cargara el ultimo jugador utilizado junto con sus vehiculos)"<<endl;
    s<< "[1] Nuevo juego (elimina jugador antiguo)"<<endl;
    return s.str();
}

string MenuPrincipal::menuPrincipal() {
    stringstream s;
    s<< YELLOW"<<<<Menu principal>>>>"<<RESET<<endl;
    s<< "[1] Menu Jugador"<<endl;
    s<< "[2] Tienda"<<endl;
    s<< "[3] Develop Mode"<<endl;
    s<< "[4] Salir" <<endl;
    return s.str();
}