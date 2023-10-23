//
// Created by mauri on 22/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_EXCEPTIONS_H
#define PRUEBAPROYECTOMCAV_EXCEPTIONS_H


class Exceptions {
private:
    char motivo;
public:
    Exceptions(char m);
    const char* what()const throw();
};



#endif //PRUEBAPROYECTOMCAV_EXCEPTIONS_H
