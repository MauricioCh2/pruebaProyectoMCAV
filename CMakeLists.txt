cmake_minimum_required(VERSION 3.26)
project(pruebaProyectoMCAV)

set(CMAKE_CXX_STANDARD 17)

add_executable(pruebaProyectoMCAV main.cpp

        Model/dist/json/json.h
        Model/dist/jsoncpp.cpp
        Model/Archivos.h
        Model/Exceptions.cpp
        Model/Exceptions.h
        Model/Lista.h
        Model/Nodo.h
        Model/Utilities.cpp
        Model/Utilities.h
        Model/Item.cpp
        Model/Item.h
        Model/Tienda.cpp
        Model/Tienda.h
        Model/Motor.cpp
        Model/Motor.h
        Model/Llantas.cpp
        Model/Llantas.h
        Model/Nitro.cpp
        Model/Nitro.h


        Model/Jugador.cpp
        Model/Jugador.h
        Model/Menu.cpp
        Model/Menu.h
        Model/MenuControler.cpp
        Model/MenuControler.h
        Model/Juego.cpp
        Model/Juego.h
        Model/VehiculoBase.cpp
        Model/VehiculoBase.h
        Model/Pieza.cpp
        Model/Pieza.h

        View/MenuJugador.cpp
        View/MenuJugador.h
        View/MenuPrincipal.cpp
        View/MenuPrincipal.h
        View/MenuTienda.cpp
        View/MenuTienda.h
        View/MenuPiezas.cpp
        View/MenuPiezas.h
        View/MenuVehiculoB.cpp
        View/MenuVehiculoB.h

        Controler/ControlPrincipal.cpp
        Controler/ControlPrincipal.h
        Controler/ControlJugador.cpp
        Controler/ControlJugador.h
        Controler/ControlVehiculo.cpp
        Controler/ControlVehiculo.h
        Controler/ControlVehiculo.h
        Controler/ControlTienda.cpp
        Controler/ControlTienda.h
        Controler/ControlTienda.h
        Controler/ControlItems.cpp
        Controler/ControlItems.h


)
