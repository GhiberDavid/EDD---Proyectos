#ifndef NODO_H
#define NODO_H

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    
    Nodo(int val) : valor(val), izquierdo(nullptr), derecho(nullptr) {}
};

#endif