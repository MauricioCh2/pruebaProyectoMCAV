//
// Created by mauri on 23/10/2023.
//

#include "Tienda.h"


Tienda::Tienda() {
    ptrP = new Lista<Pieza,-1>;

    ifstream fpieza ("lisPiezaTienda.txt");
    Archivos<Lista<Pieza,-1>, Pieza> archP;
    ptrP = archP.cargarDatosPieza(fpieza);
}



Tienda::~Tienda() {
     if(ptrP!=NULL) delete ptrP;
}

Lista<Pieza, -1> *Tienda::getLista() {
    return ptrP;
}


void Tienda::ingresarPiezasTienda(Pieza * pP) {   //Ingresa una pieza a la lista, por medio de una llamada al método insertarAlFinaal de la lista.
    ptrP->insertEnd(pP);
}

string Tienda::mostrarPiezas() {   //Muestra la lista de piezas, por medio de una llamada al toString de la lista
  return ptrP->toString();

}

void Tienda::eliminarPiezas(string id) {  //Elimina las piezas, según el id, por medio de una llamada al método eliminarEspecifico de la lista
    ptrP->deleteEspe(id);
}




