# Examen Final - Estructuras Dinámicas de Datos

Programa que construye un árbol binario por niveles (llenado completo de arriba abajo y de izquierda a derecha), calcula la suma de cada camino desde la raíz hasta cada hoja, obtiene el promedio de todas esas sumas, y muestra el camino cuya suma es más cercana a dicho promedio.


## Compilación

Desde la raíz del proyecto:

En el bash:
g++ ExamenFinal/main.cpp ExamenFinal/Arbol.cpp -o Arbol/examen_final

## Ejecución:
./Arbol/examen_final

Al ejecutar el programa, saldrá lo siguiente: 

=== MENU PRINCIPAL ===
1. Construir arbol binario
2. Mostrar estructura del arbol
3. Calcular y mostrar resultados
4. Salir

Paso a paso:

Opción 1 - Construir el árbol

        Ingrese la cantidad de nodos

        Ingrese cada valor cuando se solicite (se muestra la posición y relación padre-hijo)

Opción 2 - Ver la estructura jerárquica del árbol

Opción 3 - Calcular y mostrar:

        Todos los caminos desde la raíz hasta cada hoja

        La suma de cada camino

        El promedio de todas las sumas

        El camino más cercano al promedio

    Opción 4 - Salir del programa

## Características técnicas

Sin vectores: Todas las estructuras dinámicas (cola, lista de caminos) están implementadas manualmente con listas enlazadas.

Construcción por niveles: El árbol se llena completamente de izquierda a derecha, como un heap.

Recorrido recursivo: Se utiliza DFS (profundidad) para explorar todos los caminos.

Memoria dinámica: Cada nodo se asigna con new y se libera correctamente.

## Requisitos

Compilador C++ (g++ recomendado)

Sistema Linux/Unix o WSL en Windows