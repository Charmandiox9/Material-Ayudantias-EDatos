## 10. Grafos

## Índice
- [10. Grafos](#10-grafos)
- [Índice](#índice)
  - [Terminología](#terminología)
  - [Tipos de Grafos](#tipos-de-grafos)
    - [No dirigido](#no-dirigido)
    - [Dirigido (Dígrafo)](#dirigido-dígrafo)
    - [Ponderado](#ponderado)
    - [Conexo vs No Conexo](#conexo-vs-no-conexo)
  - [Formas de Representación](#formas-de-representación)
    - [Matriz de Adyacencia](#matriz-de-adyacencia)
    - [Lista de Adyacencia](#lista-de-adyacencia)
  - [¿Cuándo usar cada representación?](#cuándo-usar-cada-representación)
  - [Resumen visual de tipos](#resumen-visual-de-tipos)

---

Un **grafo** es una estructura compuesta por **vértices** (nodos) conectados
por **aristas** (edges). A diferencia de los árboles, no tienen una jerarquía
fija ni necesariamente una raíz.

---

### Terminología
```mermaid
graph TD
    A((A)) -->|arista| B((B))
    A --> C((C))
    B --> D((D))
    C --> D
    D --> E((E))
```

| Término | Descripción |
|---|---|
| **Vértice** | Nodo del grafo (A, B, C...) |
| **Arista** | Conexión entre dos vértices |
| **Grado** | Cantidad de aristas que tiene un vértice |
| **Camino** | Secuencia de vértices conectados por aristas |
| **Ciclo** | Camino que empieza y termina en el mismo vértice |
| **Peso** | Valor asociado a una arista (distancia, costo, etc.) |

---

### Tipos de Grafos

#### No dirigido
Las aristas **no tienen dirección** — la conexión es bidireccional.
```mermaid
graph LR
    A((A)) --- B((B))
    A --- C((C))
    B --- D((D))
    C --- D
```
> Si existe arista A → B, también existe B → A.

---

#### Dirigido (Dígrafo)
Las aristas **tienen dirección** — solo se puede ir en un sentido.
```mermaid
graph LR
    A((A)) --> B((B))
    A --> C((C))
    B --> D((D))
    C --> D
    D --> A
```
> La arista A → B no implica que exista B → A.

---

#### Ponderado
Las aristas tienen un **peso o costo** asociado.
```mermaid
graph LR
    A((A)) -->|4| B((B))
    A -->|2| C((C))
    B -->|5| D((D))
    C -->|1| D
    D -->|3| E((E))
```
> Usado en problemas de camino mínimo (Dijkstra, Bellman-Ford).

---

#### Conexo vs No Conexo

**Conexo:** existe un camino entre **cualquier par** de vértices.
```mermaid
graph LR
    A((A)) --- B((B))
    B --- C((C))
    C --- D((D))
    D --- A
```

**No conexo:** hay vértices o grupos **aislados** sin camino entre sí.
```mermaid
graph LR
    A((A)) --- B((B))
    C((C)) --- D((D))
```
> A y B no tienen camino hacia C y D.

---

### Formas de Representación

Dado el siguiente grafo de ejemplo:
```mermaid
graph LR
    1((1)) --- 2((2))
    1 --- 3((3))
    2 --- 4((4))
    3 --- 4
    4 --- 5((5))
```

#### Matriz de Adyacencia
Matriz `n×n` donde `M[i][j] = 1` si existe arista entre `i` y `j`.
```
   1  2  3  4  5
1 [0, 1, 1, 0, 0]
2 [1, 0, 0, 1, 0]
3 [1, 0, 0, 1, 0]
4 [0, 1, 1, 0, 1]
5 [0, 0, 0, 1, 0]
```

✅ Consultar si existe arista → O(1)
❌ Espacio → O(n²) — costoso en grafos grandes y dispersos
```cpp
int matriz[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {0, 0, 0, 1, 0}
};
```

---

#### Lista de Adyacencia
Cada vértice guarda una lista de sus vecinos directos.
```
1 → [2, 3]
2 → [1, 4]
3 → [1, 4]
4 → [2, 3, 5]
5 → [4]
```

✅ Espacio → O(n + e) donde `e` = cantidad de aristas
✅ Más eficiente para grafos dispersos
❌ Consultar si existe arista → O(grado del vértice)
```cpp
vector<vector<int>> lista = {
    {},        // índice 0 vacío
    {2, 3},    // vértice 1
    {1, 4},    // vértice 2
    {1, 4},    // vértice 3
    {2, 3, 5}, // vértice 4
    {4}        // vértice 5
};
```

---

### ¿Cuándo usar cada representación?

| | Matriz de Adyacencia | Lista de Adyacencia |
|---|---|---|
| Grafo denso (muchas aristas) | ✅ | ❌ |
| Grafo disperso (pocas aristas) | ❌ | ✅ |
| Consultar arista u-v | O(1) | O(grado) |
| Recorrer vecinos de un vértice | O(n) | O(grado) |
| Espacio | O(n²) | O(n + e) |
| Implementar Dijkstra/BFS/DFS | Funciona | Preferido |

---

### Resumen visual de tipos
```mermaid
graph TD
    G[Grafo] --> ND[No dirigido]
    G --> D[Dirigido]
    ND --> NDP[Ponderado]
    ND --> NDNP[No ponderado]
    D --> DP[Ponderado]
    D --> DNP[No ponderado]
    D --> DAG[DAG - sin ciclos]
```