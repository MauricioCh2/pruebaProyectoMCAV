//
// Created by mauri on 22/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_UTILITIES_H
#define PRUEBAPROYECTOMCAV_UTILITIES_H

//Archivo con métodos, bibliotecas y funciones generales y visuales, para el proyecto.

#include <iostream>
#include <sstream>
#include "Exceptions.h"

#include <regex>
#include <string>

using namespace std;

//Colores
#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"

//Imprimir--------------------------------------------
template<class T>
void print(T t) {
    cout << t << "\x1B[37m" << endl;
}
//Recivir---------------------------------------------
string recivirString();
string recivirStringN();//acepta unicamente strings numericos
int recivirInt();
bool recivirBool();
double recivirDouble();
float recivirFloat();
string recivirGetLine();

//Validar---------------------------------------------
bool yesOrNo();
template<class T>
string validrExistID(T& lis){
    string id = " ";
    bool fin = false;
    while (!fin) {
        try{
            id = recivirStringN();
            if(lis.exist(id)) {
                throw new Exceptions('e');
            }
            fin = true;
            return id;
        }catch (Exceptions* e){
            print(e->what());
        }

    }
    return " ";
}
//Otros-----------------------------------------------
void enter();
void clean();
void clear();
void ignoreCin();



#endif //PRUEBAPROYECTOMCAV_UTILITIES_H
