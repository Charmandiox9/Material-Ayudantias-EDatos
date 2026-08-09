# Ayudantía 7 (P2): Heapsort

## Ejercicio 1: Construcción de heapsort paso a paso

### Descripción

Dado el siguiente vector, utilizar **heapsort** para ordenar los números de menor a mayor mostrando el paso a paso, se pide lo siguiente.

1. El vector resultante
2. Intercambio en cada paso

### Ejercicio

```
Vector: [4, 10, 3, 5, 1, 8, 9, 2 , 7, 6, 11, 0]
```

```
Solucion:

Paso 1: Hacer el heapify (max-heap) al vector.

1.- [4, 10, 3, 5, 1, 8, 9, 2, 7, 6, 11, 0]
2.- [4, 10, 3, 5, 11, 8, 9, 2, 7, 6, 1, 0]
3.- [4, 10, 3, 7, 11, 8, 9, 2, 5, 6, 1, 0]
4.- [4, 10, 9, 7, 11, 8, 3, 2, 5, 6, 1, 0]
5.- [4, 11, 9, 7, 10, 8, 3, 2, 5, 6, 1, 0]
6.- [11, 4, 9, 7, 10, 8, 3, 2, 5, 6, 1, 0]
7.- [11, 10, 9, 7, 4, 8, 3, 2, 5, 6, 1, 0]
8.- [11, 10, 9, 7, 6, 8, 3, 2, 5, 4, 1, 0]


* Intercambios:
1. [0, 10, 9, 7, 6, 3, 8, 2, 4, 1, 5 | 11]
1.1.- [10, 0, 9, 7, 6, 3, 8, 2, 4, 1, 5 | 11]
1.2.- [10, 7, 9, 0, 6, 3, 8, 2, 4, 1, 5 | 11]
1.3.- [10, 7, 9, 4, 6, 3, 8, 2, 0, 1, 5 | 11]
2. [5, 7, 9, 4, 6, 3, 8, 2, 0, 1 | 10, 11]
2.1.- [9, 7, 5, 4, 6, 3, 8, 2, 0, 1 | 10, 11]
2.2.- [9, 7, 8, 4, 6, 3, 5, 2, 0, 1 | 10, 11]
.
.
.

Final: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

```

---

**Volver al [README del curso](../../Readme.md)**
