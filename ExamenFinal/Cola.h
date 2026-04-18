#ifndef COLA_H
#define COLA_H

#include "Nodo.h"

struct NodoCola {
    Nodo* nodoArbol;
    NodoCola* siguiente;
    
    NodoCola(Nodo* nodo) : nodoArbol(nodo), siguiente(nullptr) {}
};

class Cola {
private:
    NodoCola* frente;
    NodoCola* final;
    
public:
    Cola() : frente(nullptr), final(nullptr) {}
    
    ~Cola() {
        while (!vacia()) {
            pop();
        }
    }
    
    void push(Nodo* nodo) {
        NodoCola* nuevo = new NodoCola(nodo);
        if (final == nullptr) {
            frente = final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
    }
    
    void pop() {
        if (frente == nullptr) return;
        NodoCola* temp = frente;
        frente = frente->siguiente;
        if (frente == nullptr) final = nullptr;
        delete temp;
    }
    
    Nodo* front() {
        return (frente != nullptr) ? frente->nodoArbol : nullptr;
    }
    
    bool vacia() {
        return frente == nullptr;
    }
};

#endif