#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"
#include "ListaCaminos.h"

class Arbol {
private:
    Nodo* raiz;
    ListaCaminos* listaCaminos;  // Almacena todos los caminos encontrados
    
    void mostrarArbolRec(Nodo* nodo, int nivel);
    void recorrerYGuardarCaminos(Nodo* nodo, int* caminoActual, int profundidad);
    
public:
    Arbol();
    ~Arbol();
    
    void construirDesdeInput();
    void mostrarArbol();
    void calcularCaminosYSumas();
    void mostrarResultados();
};

#endif