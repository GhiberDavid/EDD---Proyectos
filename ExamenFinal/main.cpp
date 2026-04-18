#include <iostream>
#include "Arbol.h"

using namespace std;

void mostrarMenu() {
    cout << "\n=== MENU PRINCIPAL ===\n";
    cout << "1. Construir arbol binario\n";
    cout << "2. Mostrar estructura del arbol\n";
    cout << "3. Calcular y mostrar resultados\n";
    cout << "4. Salir\n";
    cout << "Opcion: ";
}

int main() {
    cout << "=== PROYECTO: CAMINO MAS CERCANO AL PROMEDIO ===\n";
    
    Arbol arbol;
    int opcion;
    bool arbolConstruido = false;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                arbol.construirDesdeInput();
                arbolConstruido = true;
                break;
            case 2:
                if (arbolConstruido) {
                    arbol.mostrarArbol();
                } else {
                    cout << "Primero construya el arbol (opcion 1).\n";
                }
                break;
            case 3:
                if (arbolConstruido) {
                    arbol.calcularCaminosYSumas();
                    arbol.mostrarResultados();
                } else {
                    cout << "Primero construya el arbol (opcion 1).\n";
                }
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while(opcion != 4);
    
    return 0;
}