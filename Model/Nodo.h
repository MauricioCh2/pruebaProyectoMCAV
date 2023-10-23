//
// Created by mauri on 22/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_NODO_H
#define PRUEBAPROYECTOMCAV_NODO_H


#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class Nodo {
private:
    T* _info;
    Nodo<T>* _next;
    Nodo<T>* _previous;
    int _num;
public:
    Nodo(T*, Nodo<T>*,Nodo<T>*);
    Nodo(T*, Nodo<T>*);
    Nodo(T*);
    ~Nodo();
    T *getInfo() const;
    Nodo<T> *getNext() const;
    Nodo<T> *getPrev() const;
    void setInfo(T *info);
    void setNext(Nodo<T> *siguiente);
    void setPrev(Nodo<T> *siguiente);

    int getNum() const;

    string toStringN();
    friend ostream &operator<<(ostream &os, const Nodo &nodo) {
        os << *nodo._info;
        return os;
    }
    bool operator==(const string& id) {
        return *_info == id;
    }

    bool operator==(const Nodo &rhs) const {
        return _info == rhs._info;
    }

    bool operator!=(const Nodo &rhs) const {
        return !(rhs == *this);
    }
    T  operator*(const Nodo &rhs) const {
        return _info;
    }
};

template<class T>
int Nodo<T>::getNum() const {
    return _num;
}


template<class T>
Nodo<T>::Nodo(T * s, Nodo<T> * p, Nodo<T> * n) {
    _info = s;
    _previous = p;
    _next = n;

}

template<class T>
Nodo<T>::Nodo(T * i , Nodo<T>* s) {
    _info = i;
    _next = s;

}

template<class T>
Nodo<T>::Nodo(T * s) {
    _info = s;

}

template<class T>
T *Nodo<T>::getInfo() const {
    return _info;
}

template<class T>
void Nodo<T>::setInfo(T *info) {
    _info = info;
}

template<class T>
Nodo<T> *Nodo<T>::getNext() const {
    return _next;
}

template<class T>
Nodo<T> *Nodo<T>::getPrev() const {
    return _previous;
}

template<class T>
void Nodo<T>::setNext(Nodo<T> *next) {
    _next = next;
}


template<class T>
string Nodo<T>::toStringN() {
    return _info->toString();
}

template<class T>
void Nodo<T>::setPrev(Nodo<T> *prev) {
    _previous = prev;
}

template<class T>
Nodo<T>::~Nodo() {

}


#endif //PRUEBAPROYECTOMCAV_NODO_H
