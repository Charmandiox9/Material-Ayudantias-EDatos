# 🔗 Ayudantía 6:

## 📝 Opción 1: Repaso Listas Enlazadas
### 🎯 Descripción
Dadas dos listas ordenadas en orden creciente, cree y devuelva una nueva lista que represente la intersección de las dos listas. La nueva lista debe hacerse con su propia memoria, las listas originales no deben cambiarse.

### 💡 Ejemplo
```
📥 Input:  
Lista 1: 1->2->3->4->6
Lista 2: 2->4->6->8

📤 Output: 2->4->6
```

---


## 📝 Opción 2: Resolución Ejercicio 4 Prueba (Stacks)

### 🎯 Descripción
Dadas dos secuencias de valores numéricos almacenadas en arreglos `pushed` y `popped` de tamaño **n**, determina si es posible obtener la secuencia `popped` aplicando operaciones **Push** (inserción) y **Pop** (eliminación) sobre una pila vacía, utilizando los valores del arreglo `pushed` en orden.

Implementa la función:
```cpp
bool canBeObtainable(int* pushed, int* popped, int size)
```

**Restricciones:**
- Complejidad temporal: O(n)
- Complejidad espacial: O(n)
- Usar clase `Node`
- Solo librería `<iostream>`

### 💡 Ejemplo
```
📥 Input:  
pushed = [1, 2, 3, 4, 5]
popped = [4, 5, 3, 2, 1]

📤 Output: true
```

---

## 📝 Opción 3: Materia nueva

### 🎯 Descripción
Dada una lista enlazada, y dos índices **m** y **n**, y un entero **k** que define los subgrupos que hay que rotar, rota la sublista desde la posición **m** hasta la **n** (inclusive) **k** posiciones hacia la derecha dentro de la lista original, sin usar espacio adicional significativo y reocrriendo la lista solo una vez.

### 💡 Ejemplo
Dado el siguiente arbol, hacer los recorridos NLR, LNR, LRN y BFS

```
       F
     /  \
    B     G
   / \     \
  A   D     I
     / \   /
    C   E H
```


---

```
class Node {
public:
int value;
Node* next;
Node() { next = nullptr; }
};
```