//
// Created by eolic on 25/10/2023.
//

#include "ControlVehiculo.h"


bool ControlVehiculo::opsubMenuModificacion() {
    int op = 0;
    op = recivirInt();
    switch (op) {
        case 1://Quitar todas las piezas de todos los  vehiculos
            _juego->quitarTodas();
            print("Listo todos elementos han sido desemsamblados");
            //enter();
            break;
        case 2://Quitar todas las piezas de un vehiculo en especifico
            if(mV->quitarTodasEspe()){
                print (YELLOW"vehiculo desemsamblado correctamente");
            }
            else{
                print(RED"Fallo en eliminar");
            }
            break;
        case 3://Quitar una las piezas de un vehiculo en especifico
            //hay que poner ifs y cosas para avisar si ya no hay decoradores que borrar
            if(mV->quitarUnaEspe()){
                print (YELLOW"mejora eliminada correctamente");
            }
            else{
                print(RED"Fallo en eliminar");
            }
            //enter();
            break;
        case 4: //Modificar el vehiculo
            //hay que poner ifs y cosas para avisar si ya no hay decoradores que borrar
            if(mV->modifiarVehiculo()){
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
