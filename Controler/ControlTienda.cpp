//
// Created by eolic on 31/10/2023.
//

#include "ControlTienda.h"


bool ControlTienda::opTienda() {

    int op = 0;
    op = recivirInt();
    switch (op) {
        case 1://Catalogo vehiculos
            print(RED"opcion en desarrollo");
            enter();
            break;
        case 2://Catalogo piezas
            print(RED"opcion en desarrollo");
            enter();
            break;
        case 3://Atras
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