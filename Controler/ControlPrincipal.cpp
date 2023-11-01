//
// Created by eolic on 30/10/2023.
//

#include "ControlPrincipal.h"

ControlPrincipal::ControlPrincipal() {
    _juego = new  Juego();
    mP = new MenuPrincipal();
    mJ = new MenuJugador() ;
    cJ = new ControlJugador();
    cT = new  ControlTienda();
    cI = new ControlItems();
    mT = new MenuTienda();
}
void ControlPrincipal::inicio() {
    bool fin = false;
    print (mP->menuInicio());
    bool op = recivirBool();
    if(op){
        _juego = new Juego(mJ->ingresarJugador());
    }else{
        _juego = new Juego(_juego->recuperarJugador());
    }

    while (!fin) {
        clean();
        llamarMenus();
    }
}


bool ControlPrincipal::llamarMenus() {
    int op = 0;
    bool atras = false;
    print(mP->menuPrincipal());
    op = recivirInt();
    switch (op){
        case 1: //Menu jugador
            while(!atras) {
                clean();
                print(mJ->menuJugador());
                atras = cJ->opMenuJugador();
            }
            break;
        case 2: //Tienda
            while(!atras) {
                clean();
                print(mT->tienda());
                atras = cT->opTienda();
            }
            break;
        case 3: //Develop (No se si lo voy a dejar al final o lo incluimos en tienda y jugador)
            while(!atras) {
                clean();
                print(mT->develop());
                atras = cI->developMode();
            }
            break;
        case 4:
            clean();
            print("Buen dia...");
            //archivos en caso de guardar al final
            delete _juego;
            exit(0);
            return true;
            break;
        default:
            break;
    }
    return false;
}


