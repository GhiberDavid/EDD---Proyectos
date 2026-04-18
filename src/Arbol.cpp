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
    
    cout << "\n=== CONSTRUCCION DEL ARBOL BINARIO POR NIVELES ===\n";
    cout << "Ingrese la cantidad de nodos: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "El arbol debe tener al menos un nodo.\n";
        return;
    }
    
    cout << "\n--- Ingrese los valores ---\n";
    
    // Leyendo la raíz
    cout << "Nodo 1 (Raiz): ";
    cin >> valor;
    raiz = new Nodo(valor);
    
    Cola cola;
    cola.push(raiz);
    
    int contador = 1;
    int numNodo = 1;
    
    while (contador < n && !cola.vacia()) {
        Nodo* actual = cola.front();
        cola.pop();
        
        // Asignando hijo izquierdo
        if (contador < n) {
            numNodo++;
            cout << "Nodo " << numNodo << " (Hijo izquierdo de nodo " << actual->valor << "): ";
            cin >> valor;
            actual->izquierdo = new Nodo(valor);
            cola.push(actual->izquierdo);
            contador++;
        }
        
        // Asignando hijo derecho
        if (contador < n) {
            numNodo++;
            cout << "Nodo " << numNodo << " (Hijo derecho de nodo " << actual->valor << "): ";
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