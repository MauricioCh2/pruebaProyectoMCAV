//
// Created by mauri on 23/10/2023.
//

#include "MenuControler.h"

void MenuControler::inicio() {
    bool fin = false;
    print (_menu->menuInicio());
    bool op = recivirBool();
    if(op){
    _juego = new Juego(crearJugador());
    }else{
        _juego = new Juego(_juego->recuperarJugador());
    }

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
            print(_tienda->mostrarPiezas());
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
    Pieza* pAux = nullptr;
    switch (op) {
        case 1:
            pAux = ingresarPieza();
            _juego->ingresarListaTienda(pAux);
            enter();
            break;
        case 2://Eliminar items de la tienda
            if(eliminarPiezasTienda()){
                print("Se elimino correctamente");
            }else{
                print(RED"No se pudo eliminar.");
            }

            enter();
            break;
        case 3://Mostrar los items de la tienda
            print("Piezas disponibles: ");
            print(_juego->mostrarPiezasTienda());
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
                print(YELLOW"<><>TIENDA<><>");
                atras = !usarTienda();
            }
            break;
        case 3:
            while(!atras) {
                clean();
                print(_menu->develop());
                atras =developMode();
            }
            break;
        case 4:
            clean();
            print("Buen dia...");
            _juego->guardarAlSalir();
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
    ofstream guar ("infoJugador.txt");
    ofstream carVe ("lisVehiculos.txt");
    ifstream carVeD ("lisVehiculosDefecto.txt");
    Archivos<Lista<Jugador,-1>,Jugador>  arch;
    Archivos<Lista<Vehiculo, -1>, Vehiculo> archVe;

    //Crea el nuevo jugador----------------------------
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
        listaV = archVe.cargarDatos(carVeD);
        JugTemp->setListaVehiculos(listaV);
        archVe.guardarDatos(*listaV, carVe);
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

    Lista<Pieza,-1>* listaP = new Lista<Pieza,-1>;
    ifstream fpieza ("lisPiezaVehiculo.txt");
    Archivos<Lista<Pieza,-1>, Pieza> archP;
    listaP = archP.cargarDatosPieza(fpieza);
    JugTemp->setListaPieza(listaP);

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
print("Ingrece el id de la pieza a seleccionar: ");
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
        print("Ingrece el id de la pieza a seleccionar: ");
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
        //borrar------------------
        //cout<<_juego->getListaVehiculoJugadcor().toString();
        //borrar------------------
        return true;
    }
    return false;
}

//
Pieza *MenuControler::ingresarPieza() {
    string id = " ";
    string nombre = " ";
    double precio = 0.0;
    float traccion = 0.0;
    float velocidad = 0.0;
    float potencia = 0.0;
    int tipo = 0;

    Pieza* ptrP = nullptr;
   // Lista<Pieza,-1>*  listaI = new  Lista<Pieza,-1>;

    cout << "-=-=-=-=- Ingrese datos de los items (TIENDA)-=-=-=-=-" << endl << endl;
    print("Ingrese el id: ");
    id = recivirStringN();
    print("Ingrese el nombre: ");
    nombre = recivirGetLine();
    print("Elija el tipo de pieza: ");
    print("1. Nitro ");
    print("2. Motor ");
    print("3. Llantas ");
    tipo = recivirInt();

    print("Ingrese el precio que tendra: ");
    precio = recivirDouble();

    // Crear el objeto pieza según el tipo elegido
    switch (tipo) {
        case 1:
            print("Ingrese el valor de la velocidad: ");
            velocidad = recivirFloat();
            ptrP = new Nitro(nombre,id, precio, velocidad);
            break;
        case 2:
            print("Ingrese el valor de la potencia: ");
            potencia = recivirFloat();

            ptrP = new Motor( nombre,id, precio,  potencia);
            break;
        case 3:
            print("Ingrese el valor de la traccion: ");
            traccion = recivirFloat();
            ptrP = new Llantas(nombre,id, precio, traccion);
            break;
        default:
            cout << "Tipo inválido \n";
            break;

    }

    //listaI->insertFirst(ptrP);
    //ooooh
    return ptrP;
}

string MenuControler::mostrarPiezasTienda() {
    return _juego->mostrarPiezasTienda();
}

bool MenuControler::eliminarPiezasTienda() {
    string idPieza = " ";
    bool verificarPieza = elegirPiezaTienda(idPieza);
    if(verificarPieza){
        _juego->eliminarPiezasTienda(idPieza);
        return true;
    }
    return false;
}

bool MenuControler::elegirPiezaTienda(string& id) {
    string idPieza = " ";
    bool verificacion = false;
    while(!verificacion){
        print(YELLOW"\nQue pieza deseas elegir?(si escribes ' salir vas al menu anterior)");
        print(_juego->mostrarPiezasTienda());
        print("Ingrece el id de la pieza a seleccionar: ");
        idPieza = recivirString();
        if(idPieza == "salir") {
            return false;
        }
        try{
            if(_juego->getListaTiendaPiezas()->exist(idPieza)){
                verificacion = true;
                id = idPieza;
                return true;
            }
            else
                throw new Exceptions('P');
        }
        catch(Exceptions* e){
            clean();
            print(e->what());
        }
    }
    return false;
}

bool MenuControler::usarTienda() {
        Pieza*ptrP= nullptr;
        string id = " ";
        bool op = false;
        bool verPieza = false;
        bool seguridad = false;
        if(_juego->getListaTiendaPiezas()->emptyList()){
            return false;
        }else{
            print(_juego->getTienda()->mostrarPiezas());
            print("Quiere comprar algo y/n");
            op = yesOrNo();
            if(op){
                print("Seleccione que pieza: ");
                verPieza = elegirPiezaTienda(id);
                if(verPieza){
                    ptrP = &_juego->getListaTiendaPiezas()->search(id);
                    if(_juego->getDineroJugador() >= ptrP->getPrecio()){
                        print("Estas seguro que quieres comprar esta pieza?(y/n)");
                        seguridad= yesOrNo();
                        if(seguridad){
                            //aqui va el metodo bool de tienda comprar
                            //void incluirle al jugador el Objeto
                            _juego->agregarPiezaTienda(ptrP);
                            //void rebajarle al jugador el dinero
                            _juego->rebajoDeDinero(ptrP->getPrecio());
                            print(YELLOW"Pieza comprada exitosamente!");
                            enter();
                            return false;
                        }else{
                            return false;
                        }
                    }else{
                        enter();
                        print(RED"No tienes dinero suficiente :(");
                        return false;
                    }
                }
            }else{
                return true;
            }
        }

        return false;
}
