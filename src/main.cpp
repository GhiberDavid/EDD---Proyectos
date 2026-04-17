#include <iostream>
#include "Arbol.h"

using namespace std;

int main() {
    cout << "=== PROYECTO: CAMINO MAS CERCANO AL PROMEDIO ===\n\n";
    
    Arbol arbol;
    arbol.construirDesdeInput();
    arbol.mostrarArbol();
    
    return 0;
}