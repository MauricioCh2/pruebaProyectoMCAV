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
    virtual~Tienda();

    Lista<Pieza,-1>* getLista();

    void ingresarPiezasTienda(Pieza*);
    string mostrarPiezas();
    void mostrarPiezaEspecifica(string); //***//
    void eliminarPiezas(string);

  //  void comprar(Lista<Pieza, -1>& lista, int numero, double precio);
};