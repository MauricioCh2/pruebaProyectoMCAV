//
// Created by eolic on 23/10/2023.
//

#include "MenuVehiculoB.h"

MenuVehiculo::MenuVehiculo() {
    _juego = new Juego();
    mP = new MenuPiezas();
}

string MenuVehiculo::subMenuModVehiculos() {
    stringstream s;
    s<< YELLOW"<Menu Jugador<<Modificacion de vehiculos>>>"<<RESET<<endl;
    s<< "[1] Quitar TODAS las piezas de TODOS los vehiculo"<<endl;
    s<< "[2] Quitar TODAS las piezas de un vehiculo en especifico"<<endl;
    s<< "[3] Quitar una pieza de un vehiculo en especifico"<<endl;
    s<< "[4] Modificar vehiculo (Agregar decoraciones)"<<endl;
    s<< "[5] Atras" <<endl;
    return s.str();
}

bool MenuVehiculo::elegirVehiculo(Vehiculo& veh) {
    string idCar;
    bool verificacion = false;
    while(!verificacion) {
        print(YELLOW"\nSeleccione el vehiculo(si escribe 'salir' ira al menu anterior)");
        print(_juego->imprimirVehiculosJugador());
        print("\nIngrese el id del vehiculo a elegir: ");
        idCar = recivirString();
        if(idCar == "salir"){
            return false;
        }
        try {
            veh= *_juego->buscarVehiculoJugador(idCar);
            verificacion = true;
        }
        catch (Exceptions e) {
            clean();
            print(e.what());

        }
    }

    return true;
}
bool MenuVehiculo::quitarTodasEspe() {
    Vehiculo vehiculo;
    bool verVehiculo = false;
    verVehiculo = elegirVehiculo(vehiculo);
    if(verVehiculo){
        _juego->quitarTodasEspe(&vehiculo);
        return true;
    }
    return false;
}

bool MenuVehiculo::quitarUnaEspe() {
    Vehiculo vehiculo;
    string pieza;
    bool verVehiculo = false;
    bool verPieza = false;
    verVehiculo = elegirVehiculo(vehiculo);
    verPieza = mP->elegirPiezaDeVehiculo(pieza,vehiculo);
    if (verVehiculo&&verPieza){
        _juego->quitarUnaEspe(&vehiculo,pieza);
        return true;
    }
    return false;
}

bool MenuVehiculo::modifiarVehiculo() {
    Vehiculo vehiculo;
    string pieza;
    bool verVehiculo = false;
    bool verPieza = false;
    verVehiculo = elegirVehiculo(vehiculo);
    verPieza = mP->elegirPieza(pieza, vehiculo);
    if (verVehiculo&&verPieza){
        _juego->getListaPiezasDeVehiculo(&vehiculo);
        _juego->modificarVehiculo(&vehiculo,pieza);
        //borrar------------------
        cout<<_juego->getListaVehiculoJugadcor().toString();
        //borrar------------------
        return true;
    }
    return false;
}

Vehiculo *MenuVehiculo::ingresarVehiculo() {
    string id = " ";
    string nom = " ";
    double precio = 0.0;
    float traccion = 0.0;
    float velocidad = 0.0;
    float potencia = 0.0;
    //Lista<Vehiculo,-1> temp;
    //ofstream guar ("lisVehiculo.txt");
    Vehiculo* tempV = NULL;
    //Archivos<Lista<Vehiculo,-1>,Vehiculo>  arch;
    print("Ingrese el id: ");
    id = recivirStringN();
    //id = validrExistID(_juego->getListaVehiculoJugadcor());
    print("Ingrese el nombre: ");
    nom = recivirGetLine();
    print("Ingrese el valor del vehiculo: ");
    precio = recivirDouble();
    print("Ingrese el valor de la traccion: ");
    traccion = recivirFloat();
    print("Ingrese el valor de la velocidad: ");
    velocidad = recivirFloat();
    print("Ingrese el valor de la potencia: ");
    potencia = recivirFloat();
    tempV = new Vehiculo(id, nom, precio, traccion, velocidad, potencia);
    //temp.insertFirst(tempV);
    return tempV;

}

