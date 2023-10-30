//
// Created by mauri on 23/10/2023.
//

#include "MenuControler.h"

void MenuControler::inicio() {
    bool fin = false;
    print (_menu->menuInicio());
    bool op = recivirBool();
    if(op){
    _juego = new Juego( crearJugador());
    }else{
        _juego = new Juego(_juego->recuperarJugador());
    }

    //aqui va a ir cargar
    //arch = new Archivos(_tienda);
    //arch->cargar();
    while (!fin) {
        clean();
        llamarMenus();
    }
}



bool MenuControler::opMenuJugador() {
    bool atras = false;
    int op = 0;
    op = recivirInt();
    switch (op) {
        case 1://Info del jugador
            print(_juego->imprimirInfoJugador());
            enter();
            break;
        case 2://Mis vehiculos
            print(ORANGE"<<MIS VEHICULOS>>");
            print(_juego->imprimirVehiculosJugador());
            enter();
            break;
        case 3://Mis piezas
            print(ORANGE"<<MIS PIEZAS>>");
            print(_juego->imprimirPiezasJugador());
            enter();
            break;
        case 4://ModificarVehiculos
            while (!atras) {//Este while permite ir al menu anterior  y no volver al principal
                print(_menu->subMenuModVehiculos());
                atras = opsubMenuModificacion();
                enter();
            }
            break;
        case 5://Atras
            clean();
            return true;
            break;
        default:
            clean();
            print(RED"Esa opcion no existe");
            enter();
            break;

        }
    return false;
}

bool MenuControler::opsubMenuModificacion() {
    int op = 0;
    op = recivirInt();
    switch (op) {
        case 1://Quitar todas las piezas de todos los  vehiculos
            _juego->quitarTodas();
            print("Listo todos elementos han sido desemsamblados");
            //enter();
            break;
        case 2://Quitar todas las piezas de un vehiculo en especifico
            if(quitarTodasEspe()){
                print (YELLOW"vehiculo desemsamblado correctamente");
            }
            else{
                print(RED"Fallo en eliminar");
            }
            break;
        case 3://Quitar una las piezas de un vehiculo en especifico
            //hay que poner ifs y cosas para avisar si ya no hay decoradores que borrar
            if(quitarUnaEspe()){
                print (YELLOW"mejora eliminada correctamente");
            }
            else{
                print(RED"Fallo en eliminar");
            }
            //enter();
            break;
        case 4: //Modificar el vehiculo
            //hay que poner ifs y cosas para avisar si ya no hay decoradores que borrar
            if(modifiarVehiculo()){
                print (YELLOW"mejora agregada correctamente");
            }
            else{
                print(RED"Fallo en la mejora");
            }
            //enter();
            break;
        case 5://Atras
            clean();
            return true;
            break;
        default:
            clean();
            print(RED"Esa opcion no existe");
            enter();
            break;

    }
    return false;
}

bool MenuControler::opTienda() {

    int op = 0;
    op = recivirInt();
    switch (op) {
        case 1://Catalogo vehiculos
            print(RED"opcion en desarrollo");
            enter();
            break;
        case 2://Catalogo piezas
            print(RED"opcion en desarrollo");
            enter();
            break;
        case 3://Atras
            clean();
            return true;
            break;
        default:
            clean();
            print(RED"Esa opcion no existe");
            enter();
            break;

    }
    return false;
}

bool MenuControler::developMode() {
    int op = 0;
    op = recivirInt();
    switch (op) {
        case 1://Ingresar nuevos items
            print(RED"opcion en desarrollo");
            enter();
            break;
        case 2://Eliminar items de la tienda
            print(RED"opcion en desarrollo");
            enter();
            break;
        case 3://Mostrar todos los items //tienda y jugador
            print(RED"opcion en desarrollo");
            enter();
            break;
        case 4://Atras
            clean();
            return true;
            break;
        default:
            clean();
            print(RED"Esa opcion no existe");
            enter();
            break;

    }
    return false;
}

bool MenuControler::llamarMenus() {
    int op = 0;
    bool atras = false;
    print(_menu->menuPrincipal());
    op = recivirInt();
    switch (op){
        case 1: //Menu jugador
            while(!atras) {
                clean();
                print(_menu->menuJugador());
                atras = opMenuJugador();
            }
            break;
        case 2: //Tienda
            while(!atras) {
                clean();
                print(_menu->tienda());
                atras = opTienda();
            }
            break;
        case 3: //Develop (No se si lo voy a dejar al final o lo incluimos en tienda y jugador)
            while(!atras) {
                clean();
                print(_menu->develop());
                atras =developMode();
            }
            break;
        case 4:
            clean();
            print("Buen dia...");
            //archivos en caso de guardar al final
            delete _juego;
            exit(0);
            return true;
            break;
        default:
            break;
    }
    return false;
}

Jugador* MenuControler::crearJugador() {
    string id = " ";
    string nombre = " ";
    double dinero = 0.0;
    bool op = false;
    int can = 0;
    Lista<Jugador,-1> lisJ;
    Lista<Vehiculo,-1>*  listaV = new  Lista<Vehiculo,-1>;

    ofstream guar ("lisJugador.txt");
    ofstream carVe ("lisVehiculos.txt");
    ifstream carVeD ("lisVehiculosD.txt");

    Archivos<Lista<Jugador,-1>,Jugador>  arch;
    Archivos<Lista<Vehiculo, -1>, Vehiculo> archVe;

    Jugador* JugTemp = nullptr;

    print("Ingrese el id: ");
    id = recivirStringN();
    print("Ingrese el nombre: ");
    nombre = recivirGetLine();
    print("Ingrese el dinero que tendra disponible: ");
    dinero = recivirDouble();

    JugTemp = new Jugador(id, nombre, dinero);

    lisJ.insertFirst(JugTemp);
    arch.guardarDatos(lisJ, guar);

    print("Desea utilizar los 3 vehiculos por defecto?(y/n)");
    op = yesOrNo();
    if(op){

        JugTemp->setListaVehiculos(&archVe.cargarVehiculos(carVeD));
    }
   if(!op){
       print("Cuantos vehiculos desea agregar (minimo uno max 5)");
       while (can <1 || can >=5){
           can = recivirInt();
       }
        while (can != 0){
            listaV->insertFirst(crearVehiculo());
            can --;
        }
        JugTemp->setListaVehiculos(listaV);
       archVe.guardarDatos((*listaV), carVe);
   }
    return JugTemp;

}

Vehiculo* MenuControler::crearVehiculo(){
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
    id = validrExistID(_juego->getListaVehiculoJugadcor());
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

bool MenuControler::elegirVehiculo(Vehiculo& veh) {
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
bool MenuControler::elegirPiezaDeVehiculo(string& pieza, Vehiculo& veh) {
string idPieza;
bool verificacion = false;
while(!verificacion) {
    if(_juego->getListaPiezasDeVehiculo(&veh).emptyList()){
        print(RED"Este vehiculo no posee piezas");
        return false;
    }
print(YELLOW"\nQue pieza deseas elegir?(si escribe 'salir' ira al menu anterior)");
print(_juego->imprimirListaPiezasVehiculo(&veh));
idPieza = recivirString();
if(idPieza == "salir"){
return false;
}
try {


if(_juego->getListaPiezasDeVehiculo(&veh).exist(idPieza)) {
//if(!veh.validarUso(idPieza)){
verificacion = true;
pieza = idPieza;
return true;
//}else {print(RED"ERROR: esa pieza se encuentra en uso, ingrese una existente o escriba 'salir");}

}else {print(RED"ERROR: esa pieza no existe, ingrese una existente o escriba 'salir");}
}
catch (Exceptions e) {
clean();
print(e.what());

}
}

return false;
}
bool MenuControler::elegirPieza(string& pieza, Vehiculo& veh) {
    string idPieza;
    bool verificacion = false;
    while(!verificacion) {
        print(YELLOW"\nQue pieza deseas elegir?(si escribe 'salir' ira al menu anterior)");
        print(_juego->imprimirPiezasJugador());
        idPieza = recivirString();
        if(idPieza == "salir"){
            return false;
        }
        try {

            if(_juego->getListaPiezasJugador().exist(idPieza)) {
                if(!veh.validarUso(idPieza)){
                    verificacion = true;
                    pieza = idPieza;
                    return true;
                }else {print(RED"ERROR: esa pieza se encuentra en uso, ingrese una existente o escriba 'salir");}

            }else {print(RED"ERROR: esa pieza no existe, ingrese una existente o escriba 'salir");}
        }
        catch (Exceptions e) {
            clean();
            print(e.what());

        }
    }

    return true;
}


bool MenuControler::quitarTodasEspe() {
    Vehiculo vehiculo;
    bool verVehiculo = false;
    verVehiculo = elegirVehiculo(vehiculo);
    if(verVehiculo){
        _juego->quitarTodasEspe(&vehiculo);
        return true;
    }
    return false;
}

bool MenuControler::quitarUnaEspe() {
    Vehiculo vehiculo;
    string pieza;
    bool verVehiculo = false;
    bool verPieza = false;
    verVehiculo = elegirVehiculo(vehiculo);
    verPieza = elegirPiezaDeVehiculo(pieza,vehiculo);
    if (verVehiculo&&verPieza){
        _juego->quitarUnaEspe(&vehiculo,pieza);
        return true;
    }
    return false;
}

bool MenuControler::modifiarVehiculo() {
    Vehiculo vehiculo;
    string pieza;
    bool verVehiculo = false;
    bool verPieza = false;
    verVehiculo = elegirVehiculo(vehiculo);
    verPieza = elegirPieza(pieza, vehiculo);
    if (verVehiculo&&verPieza){
        _juego->getListaPiezasDeVehiculo(&vehiculo);
        _juego->modificarVehiculo(&vehiculo,pieza);
        return true;
    }
    return false;
}


