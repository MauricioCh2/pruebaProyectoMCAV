//
// Created by mauri on 22/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_ARCHIVOS_H
#define PRUEBAPROYECTOMCAV_ARCHIVOS_H


#include "Lista.h"
#include <fstream>
#include "VehiculoBase.h"
#include "Motor.h"
#include "Nitro.h"
#include "Llantas.h"
#include "dist/json/json.h"

template<class T, class U>
class Archivos {
private:

public:
    Archivos();
    virtual ~Archivos();
    void guardarDatos(T&, ofstream&);
    Lista<U,-1>* cargarDatos(ifstream&);
    Lista<U,-1>* cargarDatosPieza(ifstream&);
};
template<class T, class U>
Archivos<T,U>::Archivos(){

}
template<class T, class U>
Archivos<T,U>::~Archivos(){

}
template<class T, class U>
void Archivos<T, U>::guardarDatos(T& lis, ofstream& salida) {//Recorre la lista para guardar cada dato de esta
    Json::StreamWriterBuilder builder;
    builder["commentStyle"]= "None";
    builder["identation"]= "    ";
    std::unique_ptr<Json::StreamWriter> writer (builder.newStreamWriter());//construyo un flujo de datos para escritura
    Json:: Value arreglo(Json::arrayValue);
    for (int i = 0; i <lis.counter() ; ++i)
    {
        arreglo.append(((lis[i]).salvaDatos(lis[i])));//llama cada salvar datos
    }
    writer->write(arreglo,&salida );
    salida.close();
}
template<class T, class U>
Lista<U,-1>* Archivos<T, U>::cargarDatos(ifstream& entrada) { //carga cualquier tipo de objeto y lista
    U* temp = new U();
    Lista<U,-1>* lis =  new Lista<U,-1>;
    Json::Value objetos;
    Json::Reader reader;
    reader.parse(entrada, objetos);
        for (int i = 0; i < objetos.size(); ++i) {
            Json::Value objetoActual = objetos[i];
            if(!entrada.bad()) {
                if (temp->cargaDatos(objetos[i]) != NULL) {
                    temp = temp->cargaDatos(objetos[i]);
                    lis->insertEnd(temp);
                }
            }
        }
    entrada.close();
    return lis;

}

template<class T, class U>
Lista<U,-1>* Archivos<T, U>::cargarDatosPieza(ifstream& entrada) {
    //U* temp = new U();
    Lista<U,-1>* lis =  new Lista<U,-1>;
    Json::Value objetos;
    Json::Reader reader;
    reader.parse(entrada, objetos);

    for (int i = 0; i < objetos.size(); ++i) {
        Json::Value objetoActual = objetos[i];
        string tipoPieza = objetoActual["Tipo"].asString(); // Supongamos que tienes una clave "tipo" que indica el tipo de pieza.
        Pieza* nuevaPieza = nullptr;
        Motor* nuevaMotor = new Motor (" ");
        Nitro* nuevaNitro = new Nitro (" ");
        Llantas* nuevaLLanta = new Llantas (" ");

        //Al ser una lista polimorfica dividimos el metodo en varios constructoresy no uno generico para que sea posible usarlo
        if (tipoPieza == "Motor") {
            nuevaMotor = dynamic_cast<Motor *>(nuevaMotor->cargaDatos(objetoActual));
            lis->insertEnd(nuevaMotor);
        } else if (tipoPieza == "Nitro") {
            nuevaNitro = dynamic_cast<Nitro *>(nuevaNitro->cargaDatos(objetoActual));
            lis->insertEnd(nuevaNitro);
        } else if (tipoPieza == "Llanta") {
            nuevaLLanta = dynamic_cast<Llantas *>(nuevaLLanta->cargaDatos(objetoActual));
            lis->insertEnd(nuevaLLanta);
        }

    }
    entrada.close();
    return lis;

}



#endif //PRUEBAPROYECTOMCAV_ARCHIVOS_H
