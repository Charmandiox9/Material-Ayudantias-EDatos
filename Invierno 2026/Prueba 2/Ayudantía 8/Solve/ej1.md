# Solución Ejercicio 1: Construcción de heapsort paso a paso

## 📥 Vector original: "[4, 10, 3, 5, 1, 8, 9, 2 , 7, 6, 11, 0]"

Total de elementos: 12
índice de ultimo nodo con hijos: 5

### Paso 1: Construir Heapify (Max-Heap)

Se parte desde el índice 5 y se verifica si cumple la propiedad de max-heap respecto sus hijos.

```
1.- [4, 10, 3, 5, 1, 8, 9, 2, 7, 6, 11, 0] -> No pasa nada, retrocedemos 1 índice
2.- [4, 10, 3, 5, 11, 8, 9, 2, 7, 6, 1, 0] -> Intercambiamos el 1 con el 11 y retrocedemos 1 índice
3.- [4, 10, 3, 7, 11, 8, 9, 2, 5, 6, 1, 0] -> Intercambiamos el 5 con el 7 y retrocedemos 1 índice
4.- [4, 10, 9, 7, 11, 8, 3, 2, 5, 6, 1, 0] -> Intercambiamos el 3 con el 9 y retrocedemos 1 índice
5.- [4, 11, 9, 7, 10, 8, 3, 2, 5, 6, 1, 0] -> Intercambiamos el 10 con el 11 y retrocedemos 1 índice
6.- [11, 4, 9, 7, 10, 8, 3, 2, 5, 6, 1, 0] -> Intercambiamos el 4 con el 11
7.- [11, 10, 9, 7, 4, 8, 3, 2, 5, 6, 1, 0] -> Se intercambia el 4 con su hijo mayor (10)
8.- [11, 10, 9, 7, 6, 8, 3, 2, 5, 4, 1, 0] -> Se intercambia el 4 con el 6
```

### Paso 2: Intercambiar y re hacer

Una vez hecho el heapify, debemos intercambiar el primer elemento de la lista con el último, se descarta el último, y se vuelve a realizar el heapify pero desde el índice 0 hasta el último nodo con hijos.

```
1.- [0, 10, 9, 7, 6, 8, 3, 2, 5, 4, 1 | 11] -> Se intercambia y descarta el 11
1.1- [10, 0, 9, 7, 6, 8, 3, 2, 5, 4, 1 | 11] -> Se intercambia el 0 con su hijo mayor (10)
1.2- [10, 7, 9, 0, 6, 8, 3, 2, 5, 4, 1 | 11] -> Se intercambia el 0 con su hijo mayor (7)
1.3- [10, 7, 9, 5, 6, 8, 3, 2, 0, 4, 1 | 11] -> Se intercambia el 0 con su hijo mayor (5)

2.- [1, 7, 9, 5, 6, 8, 3, 2, 0, 4 | 10, 11] -> Se intercambia y descarta el 10
2.1- [9, 7, 1, 5, 6, 8, 3, 2, 0, 4 | 10, 11] -> Se intercambia el 1 con su hijo mayor (9)
2.2- [9, 7, 8, 5, 6, 1, 3, 2, 0, 4 | 10, 11] -> Se intercambia el 1 con su hijo mayor (8)

3.- [4, 7, 8, 5, 6, 1, 3, 2, 0 | 9, 10, 11] -> Se intercambia y descarta el 9
3.1- [8, 7, 4, 5, 6, 1, 3, 2, 0 | 9, 10, 11] -> Se intercambia el 4 con su hijo mayor (8)

4.- [0, 7, 4, 5, 6, 1, 3, 2 | 8, 9, 10, 11] -> Se intercambia y descarta el 8
4.1- [7, 0, 4, 5, 6, 1, 3, 2 | 8, 9, 10, 11] -> Se intercambia el 0 con su hijo mayor (7)
4.2- [7, 6, 4, 5, 0, 1, 3, 2 | 8, 9, 10, 11] -> Se intercambia el 0 con su hijo mayor (6)

5.- [2, 6, 4, 5, 0, 1, 3 | 7, 8, 9, 10, 11] -> Se intercambia y descarta el 7
5.1- [6, 2, 4, 5, 0, 1, 3 | 7, 8, 9, 10, 11] -> Se intercambia el 2 con su hijo mayor (6)
5.2- [6, 5, 4, 2, 0, 1, 3 | 7, 8, 9, 10, 11] -> Se intercambia el 2 con su hijo mayor (5)

6.- [3, 5, 4, 2, 0, 1 | 6, 7, 8, 9, 10, 11] -> Se intercambia y descarta el 6
6.1- [5, 3, 4, 2, 0, 1 | 6, 7, 8, 9, 10, 11] -> Se intercambia el 3 con su hijo mayor (5)

7.- [1, 3, 4, 2, 0 | 5, 6, 7, 8, 9, 10, 11] -> Se intercambia y descarta el 5
7.1- [4, 3, 1, 2, 0 | 5, 6, 7, 8, 9, 10, 11] -> Se intercambia el 1 con su hijo mayor (4)

8.- [0, 3, 1, 2 | 4, 5, 6, 7, 8, 9, 10, 11] -> Se intercambia y descarta el 4
8.1- [3, 0, 1, 2 | 4, 5, 6, 7, 8, 9, 10, 11] -> Se intercambia el 0 con su hijo mayor (3)
8.2- [3, 2, 1, 0 | 4, 5, 6, 7, 8, 9, 10, 11] -> Se intercambia el 0 con su hijo mayor (2)

9.- [0, 2, 1 | 3, 4, 5, 6, 7, 8, 9, 10, 11] -> Se intercambia y descarta el 3
9.1- [2, 0, 1 | 3, 4, 5, 6, 7, 8, 9, 10, 11] -> Se intercambia el 0 con su hijo mayor (2)

10.- [1, 0 | 2, 3, 4, 5, 6, 7, 8, 9, 10, 11] -> Se intercambia y descarta el 2

11.- [0 | 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11] -> Se intercambia y descarta el 1

12.- [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11] -> Se descarta el 0
```
