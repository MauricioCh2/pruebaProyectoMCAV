//
// Created by mauri on 22/10/2023.
//

#ifndef PRUEBAPROYECTOMCAV_LISTA_H
#define PRUEBAPROYECTOMCAV_LISTA_H


#include "Nodo.h"
#include "Exceptions.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
//#include "dist/json/json.h"
template <class T, int tam>
class Lista {
private:
    Nodo<T>* _first;
    Nodo<T>* _end;
    int _cont;

public:
    Lista();
    void insertFirst(T*);
    void insertEnd(T*);
    virtual bool deleteEnd();
    virtual bool emptyList();
    virtual int counter();
    virtual Nodo<T>* searchInPos(int); //Te da el elemento en la posicion n
    template <class U>
    bool search(U, T&); //Retorna el elemento em base a una identificacion o algo especial dpendiendo de su tipo
    virtual bool deleteInPos(int);
    virtual string toString();
    Nodo<T>* getFirst();
    Nodo<T>* getEnd();
    T& operator [](int n);
    ~Lista();
};


template<class T, int tam>
T &Lista<T, tam>::operator[](int pos) {
    Nodo<T>* actual = _first;

    int cont = 0;
    if(pos > counter()){
        throw (new Exceptions('L'));
    }
    while (actual!= nullptr){
        if (cont == pos){
            return *actual->getInfo();
        }
        actual = actual->getNext();
        cont++;
    }
    throw (new Exceptions('L'));

}


template<class T, int tam>
Lista<T, tam>::Lista() {
    _first = nullptr;
    _end = nullptr;
    _cont = 0;
}

template<class T, int tam>
void Lista<T, tam>::insertFirst(T* t) {
    try{
        if(counter() < tam || tam == -1){

            if(_first== nullptr && _end== nullptr){
                _first = new Nodo<T> (t, nullptr, _first);
                _end = _first;
            }else{
                _first = new Nodo<T> (t, nullptr, _first); // lo dejo asi para que en la lista circular pueda poner el ultimo
                _first->getNext()->setPrev(_first); //ya esta siendo end
            }
            this->_cont++;
        }
        else {
            throw (Exceptions ('c'));
        }
    }
    catch (Exceptions* e){
        print(e->what());
    }
}

template<class T, int tam>
void Lista<T, tam>::insertEnd (T* t) {
    try{
        if(counter() < tam || tam == -1){
            if(_first == nullptr && _end == nullptr){
                _first = new Nodo<T> (t, nullptr, _first);
                _end =_first;
            }else{
                Nodo<T>* temp = _end;
                temp->setNext(new Nodo<T>(t, temp, nullptr));
                _end = temp->getNext();
            }
            this->_cont++;
        }

        else {
            throw (Exceptions ('c'));
        }

    }
    catch (Exceptions* e){
        print(e->what());
    }
}
template<class T, int tam>
bool Lista<T, tam>::deleteEnd() {
    Nodo<T>* actual = _first;
    if(_end == nullptr){
        return false;
    }
    else{
        while(_end->getPrev()!=nullptr){
            actual= _end;
            delete actual;
            _end = _end->getPrev();
        }
        if(_end->getPrev()==nullptr){
            delete _end;
            _end= nullptr;
        }
    }
    return true;
}


template<class T, int tam>
bool Lista<T, tam>::emptyList() {
    if(_first == nullptr){
        return true;
    }
    return false;
}

template<class T, int tam>
int Lista<T, tam>::counter() {
    return _cont;
}

template<class T, int tam>
Nodo<T> *Lista<T, tam>::searchInPos(int pos) {
    Nodo<T>* actual = _first;
    int cont = 0;
    try{
        if(pos > counter()){
            throw (new Exceptions('L'));
            enter();
        }
        while (actual!= nullptr){
            if (cont == pos){
                return actual;
            }
            actual = actual->getNext();
            cont++;
        }
        throw (new Exceptions('L'));
    }catch(Exceptions* e){
        print(e->what());
    }
    return nullptr;
}

template<class T, int tam>
template<class U>
bool Lista<T, tam>::search(U ident, T& temp) {
    Nodo<T> actual1 = *_first;
    Nodo<T> actual2 = *_end;
    while (actual1.getNext() != nullptr && actual2.getPrev() != nullptr) {
        if (*(actual1.getInfo()) == ident) {
            temp = *actual1.getInfo();
            return true;
        }
        if (*(actual2.getInfo()) == ident) {
            temp = *actual2.getInfo();
            return true;
        }
        actual1 = *actual1.getNext();
        actual2 = *actual2.getPrev();
    }
    throw (Exceptions('L'));
}

template<class T, int tam>
bool Lista<T, tam>::deleteInPos(int pos ) {
    return false;
}

template<class T, int tam>
string Lista<T, tam>::toString() {
    stringstream s;
    Nodo<T>* actual = _first;
    while (actual != nullptr){
        s << *actual<< endl;
        actual = actual->getNext();
    }
    return s.str();
}

template <class T, int tam>
Nodo<T> *Lista<T, tam>::getFirst() {
    return _first;
}
template<class T, int tam>
Nodo<T> *Lista<T, tam>::getEnd() {
    return _end;
}

template <class T, int tam>
Lista<T, tam>::~Lista() {
    if (!this->emptyList())
        this->deleteEnd();

}


#endif //PRUEBAPROYECTOMCAV_LISTA_H
