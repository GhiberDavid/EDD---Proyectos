#include "Arbol.h"
#include "Cola.h"
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

Arbol::Arbol() {
    raiz = nullptr;
    listaCaminos = nullptr;
}

Arbol::~Arbol() {
    if (listaCaminos != nullptr) {
        delete listaCaminos;
    }
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
        
        if (contador < n) {
            numNodo++;
            cout << "Nodo " << numNodo << " (Hijo izquierdo de " << actual->valor << "): ";
            cin >> valor;
            actual->izquierdo = new Nodo(valor);
            cola.push(actual->izquierdo);
            contador++;
        }
        
        if (contador < n) {
            numNodo++;
            cout << "Nodo " << numNodo << " (Hijo derecho de " << actual->valor << "): ";
            cin >> valor;
            actual->derecho = new Nodo(valor);
            cola.push(actual->derecho);
            contador++;
        }
    }
    
    cout << "\n✅ Arbol construido correctamente por niveles.\n";
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
    
    for (int i = 0; i < nivel; i++) {
        cout << "  ";
    }
    cout << "├─ " << nodo->valor << endl;
    
    mostrarArbolRec(nodo->izquierdo, nivel + 1);
    mostrarArbolRec(nodo->derecho, nivel + 1);
}

void Arbol::calcularCaminosYSumas() {
    if (raiz == nullptr) {
        cout << "El arbol esta vacio. No hay caminos que calcular.\n";
        return;
    }
    
    // Inicializando la lista de caminos
    if (listaCaminos != nullptr) {
        delete listaCaminos;
    }
    listaCaminos = new ListaCaminos();
    
    int caminoActual[100];
    
    // Comenzando el recorrido desde la raíz
    recorrerYGuardarCaminos(raiz, caminoActual, 0);
    
    cout << "\n✅ Se encontraron " << listaCaminos->getCantidad() << " caminos desde la raiz hasta las hojas.\n";
}

void Arbol::recorrerYGuardarCaminos(Nodo* nodo, int* caminoActual, int profundidad) {
    if (nodo == nullptr) return;
    
    // Agregando el valor actual al camino
    caminoActual[profundidad] = nodo->valor;
    
    // Verificando si es una hoja (no tiene hijos)
    bool esHoja = (nodo->izquierdo == nullptr && nodo->derecho == nullptr);
    
    if (esHoja) {
        // Calculando la suma del camino
        int suma = 0;
        for (int i = 0; i <= profundidad; i++) {
            suma += caminoActual[i];
        }
        
        // Guardando el camino (copia de los valores)
        listaCaminos->agregar(caminoActual, profundidad + 1, suma);
    } else {
        // Seguir recorriendo
        recorrerYGuardarCaminos(nodo->izquierdo, caminoActual, profundidad + 1);
        recorrerYGuardarCaminos(nodo->derecho, caminoActual, profundidad + 1);
    }
}

void Arbol::mostrarResultados() {
    if (listaCaminos == nullptr || listaCaminos->getCantidad() == 0) {
        cout << "\nNo hay caminos calculados. Ejecute calcularCaminosYSumas() primero.\n";
        return;
    }
    
    cout << "\n=== RESULTADOS ===\n";
    
    // Mostrando todos los caminos y sus sumas
    cout << "\n--- Caminos encontrados ---\n";
    listaCaminos->mostrarTodos();
    
    // Calculculando y mostrando el promedio
    double promedio = listaCaminos->calcularPromedio();
    cout << "\n--- Promedio de sumas ---\n";
    cout << "Promedio: " << promedio << endl;
    
    // Encontrando y mostrando el camino más cercano al promedio
    NodoCamino* mejor = listaCaminos->encontrarMasCercano(promedio);
    if (mejor != nullptr) {
        cout << "\n--- Camino mas cercano al promedio ---\n";
        cout << "Camino: ";
        for (int i = 0; i < mejor->longitud; i++) {
            cout << mejor->valores[i];
            if (i < mejor->longitud - 1) cout << " -> ";
        }
        cout << "\nSuma: " << mejor->suma << endl;
        cout << "Diferencia con el promedio: " << abs(mejor->suma - promedio) << endl;
    }
}