//
// Created by eolic on 31/10/2023.
//

#include "MenuPiezas.h"


bool MenuPiezas::elegirPieza(string& pieza, Vehiculo& veh) {
    string idPieza;
    bool verificacion = false;
    while(!verificacion) {
        print(YELLOW"\nQue pieza deseas elegir?(si escribe 'salir' ira al menu anterior)");
        print(_juego->imprimirPiezasJugador());
        idPieza = recivirString();
        if(idPieza == "salir"){
            return false;
        }
        try {

            if(_juego->getListaPiezasJugador().exist(idPieza)) {
                if(!veh.validarUso(idPieza)){
                    verificacion = true;
                    pieza = idPieza;
                    return true;
                }else {print(RED"ERROR: esa pieza se encuentra en uso, ingrese una existente o escriba 'salir");}

            }else {print(RED"ERROR: esa pieza no existe, ingrese una existente o escriba 'salir");}
        }
        catch (Exceptions e) {
            clean();
            print(e.what());

        }
    }

    return true;
}

bool MenuPiezas::elegirPiezaDeVehiculo(string& pieza, Vehiculo& veh) {
    string idPieza;
    bool verificacion = false;
    while(!verificacion) {
        if(_juego->getListaPiezasDeVehiculo(&veh).emptyList()){
            print(RED"Este vehiculo no posee piezas");
            return false;
        }
        print(YELLOW"\nQue pieza deseas elegir?(si escribe 'salir' ira al menu anterior)");
        print(_juego->imprimirListaPiezasVehiculo(&veh));
        idPieza = recivirString();
        if(idPieza == "salir"){
            return false;
        }
        try {


            if(_juego->getListaPiezasDeVehiculo(&veh).exist(idPieza)) {
//if(!veh.validarUso(idPieza)){
                verificacion = true;
                pieza = idPieza;
                return true;
//}else {print(RED"ERROR: esa pieza se encuentra en uso, ingrese una existente o escriba 'salir");}

            }else {print(RED"ERROR: esa pieza no existe, ingrese una existente o escriba 'salir");}
        }
        catch (Exceptions e) {
            clean();
            print(e.what());

        }
    }

    return false;
}
