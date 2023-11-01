//
// Created by mauri on 23/10/2023.
//

#pragma once
#include"Pieza.h"
#include"Lista.h"
#include "Archivos.h"

class Tienda {   //Es una lista de piezas
private:
    Lista <Pieza,-1>*ptrP;
public:
    Tienda();
    virtual~Tienda();

    Lista<Pieza,-1>* getLista();

    void ingresarPiezasTienda(Pieza*);
    string mostrarPiezas();
    void eliminarPiezas(string);
};