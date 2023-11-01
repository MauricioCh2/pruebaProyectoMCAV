//
// Created by eolic on 21/10/2023.
//
#pragma once
#include<iostream>
#include<sstream>
#include "VehiculoBase.h"
#include "Lista.h"
#include "Archivos.h"
#include "dist/json/json.h"
#include "Motor.h"
#include "Nitro.h"
#include "Llantas.h"

using namespace std;

class Jugador {
private:
    string _id;
    string _nombre;
    double _dinero;
    Lista<Vehiculo,-1>* _lisVehiculo;
    Lista<Pieza, -1>* _lisPiezas;
    Archivos<Lista<Vehiculo,-1>, Vehiculo> _archV;
public:
    Jugador();
    Jugador(const string id, const string nombre, double dinero);
    virtual ~Jugador();

    const string getId() const;
    const string getNombre() const;
    double getDinero() const;
    Lista<Vehiculo,-1>* getListaVehiculo();
    Lista<Pieza,-1>* getListaPieza();

    void setListaVehiculos(Lista<Vehiculo,-1>*);
    void setListaPieza (Lista<Pieza,-1>*);
    void setId(const string id);
    void setNombre(const string nombre);
    void setDinero(double dinero);

    void agregarVehiculos(Vehiculo* );
    void mostrarVehiculos() const;
//TIENDA
    void agregarPiezaTienda(Pieza*);
    void rebajoDeDinero(double);

    friend ostream &operator<<(ostream &os,  Jugador &jugador);
    bool operator==(const string& id) const;
    bool operator!=(const string& id) const;

    //Archivos
    Jugador* cargaDatos(Json::Value objeto);
    Json::Value salvaDatos(Jugador& jug);
    void cargarLista();
};


