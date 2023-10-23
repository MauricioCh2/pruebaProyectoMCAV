//
// Created by eolic on 21/10/2023.
//

#include<iostream>
#include<sstream>
#include "Vehiculo.h"
#include "Lista.h"

using namespace std;


class Jugador {
private:
    string id;
    string nombre;
    float dinero;
    Lista<Vehiculo,10>* ptrV;
public:
    Jugador();
    Jugador(const string id, const string nombre, float dinero);
    virtual ~Jugador();

    const string getId() const;
    const string getNombre() const;
    float getDinero() const;
    Lista<Vehiculo,10>* getLista();

    void setLista(Lista<Vehiculo,10>*);
    void setId(const string id);
    void setNombre(const string nombre);
    void setDinero(float dinero);

    void agregarVehiculos(Vehiculo* );
    void mostrarVehiculos() const;

    friend ostream &operator<<(ostream &os, const Jugador *jugador);
};


