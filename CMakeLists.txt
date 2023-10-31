cmake_minimum_required(VERSION 3.26)
project(pruebaProyectoMCAV)

set(CMAKE_CXX_STANDARD 17)

add_executable(pruebaProyectoMCAV main.cpp
        View/Menu.cpp
        View/Menu.h
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
        Model/Motor.h
        Model/Llantas.cpp
        Model/Llantas.h
        Model/Llantas.h
        Model/Nitro.cpp
        Model/Nitro.h
        Model/Nitro.h


        Model/Jugador.cpp
        Model/Jugador.h
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
        Controler/soloParaQueAparezcaCon.cpp
        Controler/soloParaQueAparezcaCon.h
        Controler/soloParaQueAparezcaCon.h
)
