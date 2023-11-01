//
// Created by eolic on 23/10/2023.
//

#include "MenuJugador.h"

Jugador* MenuJugador::ptrJ = new Jugador();

string MenuJugador::menuJugador() {
    stringstream s;
    s<< YELLOW"<<<<Menu jugador>>>>"<<RESET<<endl;
    s<< "[1] Info del Jugador"<<endl;
    s<< "[2] Mis vehiculos"<<endl;
    s<< "[3] Mis piezas (compradas anteriormente)"<<endl;
    s<< "[4] Modificar vehiculo"<<endl;
    s<< "[5] Atras" <<endl;
    return s.str();
}
/*
int MenuJugador::menuJ() {
    int op;
    system("cls");
    cout << endl;
    cout << "    --------------------MENU JUGADOR---------------  " << endl;
    cout << "     -1- Ingresar Jugadores.                 " << endl;
    cout << "     -2- Mostrar Jugadores.                  " << endl;
    cout << "     -3- Salir.                              " << endl;
    cout << "    ---------------------------------------  " << endl;
    cout << "         Digite la opcion: ";
    cin >> op;
    return op;
}*/
Jugador *MenuJugador::ingresarJugador() {
    string id = " ";
    string nom = " ";
    double din = 0.0;
    bool op = false;
    int can = 0;

    Lista<Jugador,-1> lisJ;
    Lista<Vehiculo,-1>*  listaV = new  Lista<Vehiculo,-1>;
    ofstream guar ("infoJugador.txt");
    ofstream carVe ("lisVehiculos.txt");
    ifstream carVeD ("lisVehiculosDefecto.txt");
    Archivos<Lista<Jugador,-1>,Jugador>  arch;
    Archivos<Lista<Vehiculo, -1>, Vehiculo> archVe;

    cout << "-=-=-=-=- Ingrese datos del jugador-=-=-=-=-" << endl << endl;
    print("Ingrese el id: ");
    id = recivirStringN();
    print("Ingrese el nombre: ");
    nom = recivirGetLine();
    print("Ingrese el dinero que tendra disponible: ");
    din = recivirDouble();
    ptrJ = new Jugador(id, nom, din);

    lisJ.insertFirst(ptrJ);
    arch.guardarDatos(lisJ, guar);

    print("Desea utilizar los 3 vehiculos por defecto?(y/n)");
    op = yesOrNo();
    if(op){
        listaV = archVe.cargarDatos(carVeD);
        ptrJ->setListaVehiculos(listaV);
        archVe.guardarDatos(*listaV, carVe);
    }
    if(!op){
        print("Cuantos vehiculos desea agregar (minimo uno max 5)");
        while (can <1 || can >=5){
            can = recivirInt();
        }
        while (can != 0){
          //***********  listaV->insertFirst(crearVehiculo()); //******************
            can --;
        }
        ptrJ->setListaVehiculos(listaV);
        archVe.guardarDatos((*listaV), carVe);
    }
    Pieza* piezaQ1 = new Motor("interno","M1", 1700, 25);
    Pieza* piezaQ2 = new Motor("alto rendimiento","M2", 2300, 50);
    Pieza* piezaQ3 = new Llantas(" AA alta traccion","Ll1", 220, 80);
    Pieza* piezaQ4 = new Llantas(" B traccion normal","Ll2", 1100, 45);
    Pieza* piezaQ5 = new Llantas(" C traccion baja","Ll3", 600, -10);
    Pieza* piezaQ6 = new Nitro(" Basico","N1", 1000, 30);
    Pieza* piezaQ7 = new Nitro(" intermedio","N2", 1500, 20);
    Pieza* piezaQ8 = new Nitro(" Altro rendimiento","N3", 2000, 30);
    Lista<Pieza, -1>* lisPQ = new Lista<Pieza, -1>;
    lisPQ->insertEnd(piezaQ1);
    lisPQ->insertEnd(piezaQ2);
    lisPQ->insertEnd(piezaQ3);
    lisPQ->insertEnd(piezaQ4);
    lisPQ->insertEnd(piezaQ5);
    lisPQ->insertEnd(piezaQ6);
    lisPQ->insertEnd(piezaQ7);
    lisPQ->insertEnd(piezaQ8);
    ofstream piezas ("lisPiezas.txt");
    Archivos<Lista<Pieza, -1>,Pieza> archPiezas;
    archPiezas.guardarDatos(*lisPQ,piezas);

    ptrJ->setListaPieza(lisPQ);
    return ptrJ;
}

void MenuJugador::mostrarJugadores() {
    cout<<ptrJ;
}

