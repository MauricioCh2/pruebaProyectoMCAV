//
// Created by eolic on 31/10/2023.
//

#include "MenuTienda.h"

string MenuTienda::develop() {
    stringstream s;
    s<< RED"<<<<Develop mode>>>>"<<RESET<<endl;
    s<< "[1] Ingresar nuevos items"<<endl;
    s<< "[2] Eliminar items de la tienda"<<endl;
    s<< "[3] Mostrar todos los items"<<endl;
    s<< "[4] Atras" <<endl;
    return s.str();
}

string MenuTienda::tienda() {
    stringstream s;
    s<< YELLOW"<<<<Tienda>>>>"<<RESET<<endl;
    s<< "[1] Catalogo vehiculos"<<endl;
    s<< "[2] Catalogo de piezas"<<endl;
    s<< "[3] Atras" <<endl;
    return s.str();
}

Item *MenuTienda::ingresarPieza() {
    string id = " ";
    string nombre = " ";
    double precio = 0.0;
    float traccion = 0.0;
    float velocidad = 0.0;
    float potencia = 0.0;
    int tipo = 0;

    Item* ptrP;
    Lista<Item,-1>*  listaI = new  Lista<Item,-1>;

    cout << "-=-=-=-=- Ingrese datos de los items (TIENDA)-=-=-=-=-" << endl << endl;
    print("Ingrese el id: ");
    id = recivirStringN();
    print("Ingrese el nombre: ");
    nombre = recivirGetLine();
    print("Ingrese el dinero que tendra disponible: ");
    precio = recivirDouble();
    print("Ingrese el valor de la traccion: ");
    traccion = recivirFloat();
    print("Ingrese el valor de la velocidad: ");
    velocidad = recivirFloat();
    print("Ingrese el valor de la potencia: ");
    potencia = recivirFloat();
    print("Elija el tipo de pieza: ");
    print("1. Nitro ");
    print("2. Motor ");
    print("3. Llantas ");

    tipo = recivirInt();

    // Crear el objeto pieza según el tipo elegido
    switch (tipo) {
        case 1:
            ptrP = new Nitro(id, nombre, precio, velocidad);
            break;
        case 2:
            ptrP = new Motor(id, nombre, precio,  potencia);
            break;
        case 3:
            ptrP = new Llantas(id, nombre, precio, traccion);
            break;
        default:
            cout << "Tipo inválido \n";
            break;
    }

    listaI->insertFirst(ptrP);
        return ptrP;
}

