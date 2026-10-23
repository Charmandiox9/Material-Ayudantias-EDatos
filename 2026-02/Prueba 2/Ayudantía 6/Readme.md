# Ayudantía 6: Recorridos en Árboles Binarios

Un **árbol binario** es una estructura recursiva: cada nodo tiene a lo sumo dos hijos, llamados **izquierdo** y **derecho**. Los tres recorridos en profundidad (*depth-first*) más importantes difieren solo en **cuándo se visita la raíz** respecto a sus subárboles:

| Recorrido | Orden de visita |
|-----------|-----------------|
| **Pre-order**  | raíz → izquierdo → derecho |
| **In-order**   | izquierdo → raíz → derecho |
| **Post-order** | izquierdo → derecho → raíz |

En los ejercicios de código se usará la siguiente estructura de nodo:

```cpp
struct Nodo {
    int data;
    Nodo* izquierda;
    Nodo* derecha;
    Nodo(int x, Nodo* izq = nullptr, Nodo* der = nullptr)
        : data(x), izquierda(izq), derecha(der) {}
};
```

---

## Ejercicio 1: Recorridos a mano (sin código)

### Descripción

Dado el siguiente árbol binario de 15 nodos, escribe a mano los tres recorridos en profundidad: **pre-order**, **in-order** y **post-order**.

```
                          1
                        /   \
                       2      3
                      / \      \
                     4    5      6
                    / \  / \    / \
                   7  8  9  10  11  12
                       /       \
                      13        14
                                  \
                                   15
```

Para quitar toda ambigüedad, estas son las aristas del árbol (`nodo → (hijo izquierdo, hijo derecho)`):

| Nodo | Izquierdo | Derecho |
|------|-----------|---------|
| 1    | 2         | 3       |
| 2    | 4         | 5       |
| 3    | —         | 6       |
| 4    | 7         | 8       |
| 5    | 9         | 10      |
| 6    | 11        | 12      |
| 9    | 13        | —       |
| 12   | —         | 14      |
| 14   | —         | 15      |

(Los demás nodos son hojas, sin hijos.)

**Entregable:** la secuencia de los 15 valores de cada recorrido, separados por espacios. Por ejemplo:

```
Pre-order:  1 _ _ _ _ _ _ _ _ _ _ _ _ _
In-order:   _ _ _ _ _ _ _ _ _ _ _ _ _ _
Post-order: _ _ _ _ _ _ _ _ _ _ _ _ _ _
```

---

## Ejercicio 2: Recorrido in-order con recursión

### Descripción

Implementa una función que devuelva el **recorrido in-order** (izquierdo → raíz → derecho) de un árbol binario, usando **recursión**.

```cpp
vector<int> inOrden(Nodo* raiz);
```

La función devuelve un `vector<int>` con los valores en el orden in-order. Si `raiz` es `nullptr` (subárbol vacío), devuelve un vector vacío.

**Restricciones:**

- Librerías permitidas: `<iostream>` y `<vector>`
- Debe ser **recursiva**
- Complejidad temporal: O(n), visitando cada nodo una vez

### Ejemplo

Si construyes el mismo árbol del Ejercicio 1, la salida debe ser:

```
7 4 8 2 13 9 5 10 1 3 11 6 12 14 15
```

### Pista

El in-order recursivo sigue directamente el orden **izquierdo → raíz → derecho**: primero recursa en el subárbol izquierdo, luego agrega `raiz->data`, y al final recursa en el subárbol derecho.

---

## Ejercicio 3: Recorrido in-order sin recursión (iterativo)

### Descripción

Implementa **el mismo recorrido in-order** pero de forma **iterativa**, es decir, **sin recursión**, usando una **pila explícita** para simular la llamada recursiva.

```cpp
vector<int> inOrdenIterativo(Nodo* raiz);
```

**Restricciones:**

- Librerías permitidas: `<iostream>`, `<vector>` y `<stack>`
- Debe ser **iterativa** (no usar recursión)
- Usar `std::stack` para guardar el camino mientras desciendes
- Mismo resultado que el Ejercicio 2

### Ejemplo

Con el árbol del Ejercicio 1, la salida (idéntica al Ejercicio 2) debe ser:

```
7 4 8 2 13 9 5 10 1 3 11 6 12 14 15
```

### Pista

La idea: desciende todo lo posible por la rama **izquierda**, guardando cada nodo en la pila. Cuando no queda rama izquierda, **saca** el nodo de la pila (ese es el siguiente a visitar en in-order), agrégalo al resultado y pasa a su subárbol **derecho**. Repite hasta que no queden nodos por visitar ni nodos en la pila.

---

**Volver al [README del curso](../../Readme.md)**
