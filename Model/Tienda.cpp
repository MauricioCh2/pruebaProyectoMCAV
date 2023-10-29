//
// Created by mauri on 23/10/2023.
//

#include "Tienda.h"

Tienda::Tienda() {

}

Tienda::Tienda(Lista<Pieza, -1> &) {

}

Tienda::~Tienda() {

}

Lista<Pieza, -1> *Tienda::getLista() {
    return ptrP;
}


void Tienda::ingresarPiezasTienda(Pieza * pP) {
    ptrP->insertEnd(pP);
}

void Tienda::mostrarPiezas() {
    ptrP->toString();
}

void Tienda::mostrarPiezaEspecifica(string id) {
    // Crear una variable temporal para guardar la pieza encontrada
    Pieza* temp = nullptr;
    // Buscar la pieza en la lista usando el método search
    bool encontrado = &ptrP->search<string>(id);
    // Si se encontró la pieza, mostrar su información usando el operador <<
    if (encontrado) {
        cout << "La pieza con el id " << id << " es: " << endl;
        cout << *temp << endl;
    }
        // Si no se encontró, mostrar un mensaje de error
    else {
        cout << "No se encontró ninguna pieza con el id " << id << endl;
    }
}