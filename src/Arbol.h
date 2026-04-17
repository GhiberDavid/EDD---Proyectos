#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"

class Arbol {
private:
    Nodo* raiz;
    
    void mostrarArbolRec(Nodo* nodo, int nivel);
    
public:
    Arbol();
    ~Arbol();
    
    void construirDesdeInput();
    void mostrarArbol();
};

#endif