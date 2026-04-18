#ifndef LISTA_CAMINOS_H
#define LISTA_CAMINOS_H

#include <iostream>

// Nodo para almacenar un camino completo
struct NodoCamino {
    int* valores;        // Arreglo dinámico con los valores del camino
    int longitud;        // Cuántos nodos tiene este camino
    int suma;            // Suma de los valores del camino
    NodoCamino* siguiente;
    
    NodoCamino(int* vals, int len, int sum) : longitud(len), suma(sum), siguiente(nullptr) {
        valores = new int[len];
        for (int i = 0; i < len; i++) {
            valores[i] = vals[i];
        }
    }
    
    ~NodoCamino() {
        delete[] valores;
    }
};

// Lista enlazada para manejar todos los caminos
class ListaCaminos {
private:
    NodoCamino* cabeza;
    NodoCamino* cola;
    int cantidad;
    
public:
    ListaCaminos() : cabeza(nullptr), cola(nullptr), cantidad(0) {}
    
    ~ListaCaminos() {
        while (cabeza != nullptr) {
            NodoCamino* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
    
    void agregar(int* valores, int longitud, int suma) {
        NodoCamino* nuevo = new NodoCamino(valores, longitud, suma);
        if (cabeza == nullptr) {
            cabeza = cola = nuevo;
        } else {
            cola->siguiente = nuevo;
            cola = nuevo;
        }
        cantidad++;
    }
    
    NodoCamino* getCabeza() { return cabeza; }
    
    int getCantidad() { return cantidad; }
    
    void mostrarTodos() {
        NodoCamino* actual = cabeza;
        int numCamino = 1;
        while (actual != nullptr) {
            std::cout << "Camino " << numCamino++ << " (suma=" << actual->suma << "): ";
            for (int i = 0; i < actual->longitud; i++) {
                std::cout << actual->valores[i];
                if (i < actual->longitud - 1) std::cout << " -> ";
            }
            std::cout << std::endl;
            actual = actual->siguiente;
        }
    }
    
    // Calculando el promedio de todas las sumas
    double calcularPromedio() {
        if (cantidad == 0) return 0;
        
        int sumaTotal = 0;
        NodoCamino* actual = cabeza;
        while (actual != nullptr) {
            sumaTotal += actual->suma;
            actual = actual->siguiente;
        }
        return (double)sumaTotal / cantidad;
    }
    
    // Encontrandoel camino con suma más cercana a un valor dado
    NodoCamino* encontrarMasCercano(double objetivo) {
        if (cabeza == nullptr) return nullptr;
        
        NodoCamino* mejor = cabeza;
        double menorDiferencia = abs(mejor->suma - objetivo);
        
        NodoCamino* actual = cabeza->siguiente;
        while (actual != nullptr) {
            double diferencia = abs(actual->suma - objetivo);
            if (diferencia < menorDiferencia) {
                menorDiferencia = diferencia;
                mejor = actual;
            }
            actual = actual->siguiente;
        }
        return mejor;
    }
};

#endif