//
// Created by mauri on 23/10/2023.
//
#pragma once
#include"Pieza.h"
#include"Lista.h"

class Tienda {
private:
    Lista <Pieza,-1>*ptrP;
public:
    Tienda();
    Tienda(Lista<Pieza,-1>&);
    virtual~Tienda();

    Lista<Pieza,-1>* getLista();

    void ingresarPiezasTienda(Pieza*);
    void mostrarPiezas();
    void mostrarPiezaEspecifica(string);
    void clearTienda();
};

