//
// Created by eolic on 31/10/2023.
//

#include "ControlItems.h"


bool ControlItems::developMode() {
    int op = 0;
    op = recivirInt();
    switch (op) {
        case 1://Ingresar nuevos items
            print(RED"opcion en desarrollo");
            enter();
            break;
        case 2://Eliminar items de la tienda
            print(RED"opcion en desarrollo");
            enter();
            break;
        case 3://Mostrar todos los items //tienda y jugador
            print(RED"opcion en desarrollo");
            enter();
            break;
        case 4://Atras
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