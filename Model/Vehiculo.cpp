//
// Created by eolic on 22/10/2023.
//

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    id = "";
    nombre = "";
    precio = 0;
    traccion = 0;
    velocidad = 0;
    potencia = 0;
}

Vehiculo::Vehiculo(const string id, const string nombre, float precio, float traccion, float velocidad,float potencia): id(id), nombre(nombre), precio(precio), traccion(traccion), velocidad(velocidad),potencia(potencia) {}
Vehiculo::~Vehiculo() {}

const string Vehiculo::getId1() const {
    return id;
}

void Vehiculo::setId1(const string id) {
    this->id = id;
}

const string Vehiculo::getNombre1() const {
    return nombre;
}

void Vehiculo::setNombre1(const string nombre) {
    this->nombre = nombre;
}

float Vehiculo::getPrecio1() const {
    return precio;
}

void Vehiculo::setPrecio1(float precio) {
    this->precio = precio;
}

float Vehiculo::getTraccion1() const {
    return traccion;
}

void Vehiculo::setTraccion1(float traccion) {
    this->traccion = traccion;
}

float Vehiculo::getVelocidad1() const {
    return velocidad;
}

void Vehiculo::setVelocidad1(float velocidad) {
    this->velocidad = velocidad;
}

float Vehiculo::getPotencia1() const{
    return potencia;
}

void Vehiculo::setPotencia1(float potencia) {
    this->potencia = potencia;
}

void Vehiculo::agregarDecoraciones(Tienda*decoracion) {
    //  if (decoracion->getEstado() == "disponible") {
    //ptrD->insertEnd(decoracion);
    // decoracion->setEstado("asignado");
    //   incrementoDecremento();
    //  }
}

void Vehiculo::mostrarDecoraciones() {
    // int cont = 0;

    cout << "Vehiculo: " << nombre <<" Id: " << id << endl;
    cout << "Traccion: " << traccion << endl;
    cout << "Velocidad: " << velocidad << endl;
    cout << "Potencia: " << potencia<< endl;

    /* for (int i = 0; i <  ptrD->counter(); i++) {
         Tienda* decoracion;
         try {
             // Buscar el nodo en la posición i
             Nodo<Tienda>* nodo = ptrD->searchInPos(i);
             // Obtener la información del nodo
             decoracion = nodo->getInfo();
         }
         catch (Exeptions* e) {
             // Manejar la excepción si no se encuentra el nodo
             print(e->what());
             return;
         }
           // Mostrar el nombre y los valores del artefacto
     cout << "Decoracion: " << decoracion->getNombre() << endl;
     cout << "Traccion: " << decoracion->getTraccion() << endl;
     cout << "Velocidad: " << decoracion->getVelocidad() << endl;
     cout << "Potencia: " << decoracion->getPotencia() << endl;

     // Incrementar el contador de decoraciones
     cont++;
   }

   // Si el contador es cero, mostrar un mensaje indicando que el vehículo no tiene decoraciones
   if (cont == 0) {
     cout << "Este vehiculo no tiene decoraciones" << endl;
   }
 */
}

void Vehiculo::quitarDecoraciones() {

    /* for (int i = 0; i < listD->counter(); i++) {
         Tienda* decoracion;
         try {
             Nodo<Tienda>* nodo = listD->searchInPos(i);
             decoracion = nodo->getInfo();
         }
         catch (Exeptions* e) {
             // Manejar la excepción si no se encuentra el nodo
             print(e->what());
             return;
         }

         // Comparar el artefacto que se quiere quitar con el artefacto actual
      **NOTA SE DEBE DE HACER UNA CLASE ARTEFACTO PADRE DE LAS DECORACIONES
           if (artefacto == decoracion) {
             // Eliminar el artefacto de la lista
             listD->deleteInPos(int);
             // Cambiar el estado del artefacto a "disponible"
             decoracion->setEstado("disponible");

             // Llamar al método incrementoDecremento para actualizar las características del vehículo
             incrementoDecremento();

             // Terminar el bucle
             break;
         }
     }*/
}

void Vehiculo::incrementoDecremento() {
    // float traccionN,velocidadN,potenciaN;
    //traccionN = traccion;
    //velocidadN = velocidad;
    //potenciaN = potencia;

    // for (int i = 0; i < ptrD->counter(); i++) {
    //  Tienda* decoracion;
    //  try {
    //     Nodo<Tienda>* nodo = searchInPos(i);

    //  decoracion = nodo->getInfo();
    //   }
    //  catch (Exeptions* e) {
    // Manejar la excepción si no se encuentra el nodo
    //     print(e->what());
    //      return;
    //   }


    //  traccionN += decoracion->getTraccion();
    // velocidadN += decoracion->getVelocidad();
    //potenciaN += decoracion->getPotencia();
    //  }
}

ostream &operator<<(ostream &os, const Vehiculo *vehiculo) {
    os <<  " id: " << vehiculo->id << " nombre: " << vehiculo->nombre << " precio: "
       << vehiculo->precio << " traccion: " << vehiculo->traccion << " velocidad: " << vehiculo->velocidad << " potencia: "
       << vehiculo->potencia;
    return os;
}




