# Ayudantía 3: Listas Enlazadas Simples y Circulares

## Ejercicio 1: Detectar y Eliminar Ciclo en Lista Enlazada

### Descripción

Implementa la función que detecta si una lista enlazada tiene un ciclo usando el **algoritmo de Floyd (tortuga y liebre)**, y si lo encuentra, elimina el ciclo para convertir la lista en una lista simple.

La función debe:

1. Detectar si existe un ciclo
2. Si existe, encontrar el **nodo de inicio del ciclo**
3. Eliminar el ciclo (conectar el último nodo con `nullptr`)

**Restricciones:**

- Complejidad temporal: O(n)
- Complejidad espacial: O(1) — sin usar HashSet ni memoria adicional
- No modificar los datos de los nodos, solo los punteros `next`

### Ejemplo

```
Input (lista con ciclo): 1 -> 2 -> 3 -> 4 -> 5 -> (back to 3)

Output:
  Ciclo detectado en nodo con valor: 3
  Lista despues de eliminar ciclo: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
```

**Volver al [README del curso](../../Readme.md)**
