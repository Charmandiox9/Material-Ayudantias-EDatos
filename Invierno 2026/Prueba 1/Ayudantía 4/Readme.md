# Ayudantía 4: Listas Enlazadas Dobles y Circulares

## Ejercicio 1: Rotar Lista Doblemente Enlazada k Posiciones

### Descripción

Dada una lista **doblemente enlazada**, rota los nodos `k` posiciones hacia la derecha. Es decir, el último nodo pasa al frente, el penúltimo pasa al segundo lugar, etc.

Implementa la función:

```cpp
NodeDLL* rotateRight(NodeDLL* head, int k);
```

**Restricciones:**

- Debes mantener correctamente los punteros `prev` y `next`
- Si `k == 0` o la lista tiene 0 o 1 nodo, devolver la lista sin cambios
- Si `k > n`, usar `k % n` para evitar rotaciones innecesarias
- Complejidad temporal: O(n)

### Ejemplo

```
Input: 1 <-> 2 <-> 3 <-> 4 <-> 5,  k = 2
Output: 4 <-> 5 <-> 1 <-> 2 <-> 3

Input: 1 <-> 2 <-> 3,  k = 5
Output: 2 <-> 3 <-> 1  (k % 3 = 2 rotaciones)
```

---

## Ejercicio 2: Lista Circular — Eliminar cada k-ésimo nodo (Josephus)

### Descripción

Implementa el problema de **Josephus** usando una lista circular: `head` representa las personas que están en el círculo y se elimina cada `k`-ésima persona hasta quedar una. Devuelve el número de la persona que sobrevive.

Implementa:

```cpp
int josephus(NodeDLL* head, int k);
```

**Restricciones:**

- Debes usar una **lista circular** (no una implementación con arreglo)
- Cada vez que se elimina un nodo, debes liberar su memoria (`delete`)
- Al final, la lista debe quedar con un solo nodo (el sobreviviente)

### Ejemplo

```
Input: n = 7, k = 3
Output: 4

Explicacion:
  Círculo inicial: [1, 2, 3, 4, 5, 6, 7]
  Eliminaciones: 3, 6, 2, 7, 5, 1  -> Sobrevive: 4
```

---

**Volver al [README del curso](../../Readme.md)**
