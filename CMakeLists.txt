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
)
