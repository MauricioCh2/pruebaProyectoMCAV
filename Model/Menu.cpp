//
// Created by mauri on 23/10/2023.
//

#include "Menu.h"

Menu::Menu() {}

string Menu::menuInicio() {
    stringstream s;
    s<< YELLOW"<<<<Need for Speeed>>>"<<RESET<<endl;
    s<< "[0] Continuar (cargara el ultimo jugador utilizado junto con sus vehiculos)"<<endl;
    s<< "[1] Nuevo juego (elimina jugador antiguo)"<<endl;
    return s.str();
}

string Menu::menuPrincipal() {
    stringstream s;
    s<< YELLOW"<<<<Menu principal>>>>"<<RESET<<endl;
    s<< "[1] Menu Jugador"<<endl;
    s<< "[2] Tienda"<<endl;
    s<< "[3] Develop Mode"<<endl;
    s<< "[4] Salir" <<endl;
    return s.str();
}
//Jugador---------------------------------------------
string Menu::menuJugador() {
    stringstream s;
    s<< YELLOW"<<<<Menu jugador>>>>"<<RESET<<endl;
    s<< "[1] Info del Jugador"<<endl;
    s<< "[2] Mis vehiculos"<<endl;
    s<< "[3] Mis piezas (compradas anteriormente)"<<endl;
    s<< "[4] Modificar vehiculo"<<endl;
    s<< "[5] Atras" <<endl;
    return s.str();
}

string Menu::subMenuModVehiculos() {
    stringstream s;
    s<< YELLOW"<<<<Modificacion de vehiculos>>>>"<<RESET<<endl;
    s<< "[1] Quitar TODAS las piezas de TODOS los vehiculo"<<endl;
    s<< "[2] Quitar TODAS las piezas de un vehiculo en especifico"<<endl;
    s<< "[3] Quitar una pieza de un vehiculo en especifico"<<endl;
    s<< "[4] Modificar vehiculo (Agregar decoraciones)"<<endl;
    s<< "[5] Atras" <<endl;
    return s.str();
}


string Menu::tienda() {
    stringstream s;
    s<< YELLOW"<<<<Tienda>>>>"<<RESET<<endl;
    s<< "[1] Catalogo vehiculos"<<endl;
    s<< "[2] Catalogo de piezas"<<endl;
    s<< "[3] Atras" <<endl;
    return s.str();
}

string Menu::develop() {
    stringstream s;
    s<< RED"<<<<Develop mode>>>>"<<RESET<<endl;
    s<< "[1] Ingresar nuevos items"<<endl;
    s<< "[2] Eliminar items de la tienda"<<endl;
    s<< "[3] Mostrar todos los items"<<endl;
    s<< "[4] Atras" <<endl;
    return s.str();
}
