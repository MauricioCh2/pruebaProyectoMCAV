//
// Created by eolic on 31/10/2023.
//

#include "ControlJugador.h"

bool ControlJugador::opMenuJugador() {
    bool atras = false;
    int op = 0;
    op = recivirInt();
    switch (op) {
        case 1://Info del jugador
            print(_juego->imprimirInfoJugador());
            enter();
            break;
        case 2://Mis vehiculos
            print(ORANGE"<<MIS VEHICULOS>>");
            print(_juego->imprimirVehiculosJugador());
            enter();
            break;
        case 3://Mis piezas
            print(ORANGE"<<MIS PIEZAS>>");
            print(_juego->imprimirPiezasJugador());
            enter();
            break;
        case 4://ModificarVehiculos
            while (!atras) {//Este while permite ir al menu anterior  y no volver al principal
                print(mV->subMenuModVehiculos());
                atras = cV->opsubMenuModificacion();
                enter();
            }
            break;
        case 5://Atras
            clean();
            return true;
            break;
        default:
            clean();
            print(RED"Esa opcion no existe");
            enter();
            break;

    }
    return false;
}
