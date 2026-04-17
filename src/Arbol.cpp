#include "Arbol.h"
#include "Cola.h"
#include <iostream>
#include <limits>

using namespace std;

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
}

void Arbol::construirDesdeInput() {
    int n, valor;
    
    cout << "=== CONSTRUCCION DEL ARBOL BINARIO POR NIVELES ===\n";
    cout << "Ingrese la cantidad de nodos: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "El arbol debe tener al menos un nodo.\n";
        return;
    }
    
    // Aqui se un arreglo dinámico temporal (solo para entrada)
    
    cout << "Ingrese los " << n << " valores separados por espacio: ";
    
    cin >> valor;
    raiz = new Nodo(valor);
    
    // Cola para llevar el control de los nodos padres
    Cola cola;
    cola.push(raiz);
    
    int contador = 1;
    while (contador < n && !cola.vacia()) {
        Nodo* actual = cola.front();
        cola.pop();
        
        // Asignando hijo izquierdo
        if (contador < n) {
            cin >> valor;
            actual->izquierdo = new Nodo(valor);
            cola.push(actual->izquierdo);
            contador++;
        }
        
        // Asignando hijo derecho
        if (contador < n) {
            cin >> valor;
            actual->derecho = new Nodo(valor);
            cola.push(actual->derecho);
            contador++;
        }
    }
    
    cout << "\nArbol construido correctamente por niveles.\n";
}

void Arbol::mostrarArbol() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio.\n";
        return;
    }
    
    cout << "\n=== ESTRUCTURA DEL ARBOL ===\n";
    mostrarArbolRec(raiz, 0);
}

void Arbol::mostrarArbolRec(Nodo* nodo, int nivel) {
    if (nodo == nullptr) return;
    
    // Se muestra con indentación según el nivel
    for (int i = 0; i < nivel; i++) {
        cout << "  ";
    }
    cout << "├─ " << nodo->valor << endl;
    
    mostrarArbolRec(nodo->izquierdo, nivel + 1);
    mostrarArbolRec(nodo->derecho, nivel + 1);
}