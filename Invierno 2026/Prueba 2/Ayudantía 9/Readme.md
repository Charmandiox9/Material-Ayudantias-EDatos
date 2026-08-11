# Ayudantía 9 (P2): Grafos

## Ejercicio 1: Manzanas Podridas — BFS Multi-Fuente

### Descripción

Tienes una matriz de tamaño `n x m` que representa una caja de manzanas. Cada celda puede tener uno de estos valores:

- `0` — celda vacía
- `1` — manzana fresca
- `2` — manzana podrida

Cada minuto, toda manzana fresca **adyacente** (arriba, abajo, izquierda o derecha — no en diagonal) a una podrida, también se pudre.

La matriz se puede pensar como un **grafo implícito**: cada celda es un nodo conectado a sus vecinos. Pudrir las manzanas minuto a minuto equivale a un recorrido **BFS** que parte simultáneamente desde **todas** las manzanas podridas iniciales.

Implementa la función:

```cpp
int rottenApples(vector<vector<int>> mtx);
```

que retorne la cantidad mínima de minutos hasta que ninguna manzana fresca quede en la grilla. Si eso nunca ocurre, retorna `-1`.

**Restricciones:**

- Usar matriz (no listas de adyacencia)
- Librerías permitidas: `<iostream>`, `<queue>`
- Debe resolverse con BFS (no DFS, no fuerza bruta)
- Complejidad temporal: O(N · M)

### Ejemplo

```
grid =
  2 1 1
  1 1 0
  0 1 1

rottenApples(mtx): 4

---

grid =
2 1 1
0 1 1
1 0 2

rottenApples(mtx): -1
```

---

**Volver al [README del curso](../../Readme.md)**
