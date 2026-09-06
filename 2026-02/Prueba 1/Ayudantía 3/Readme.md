# Ayudantía 3: Listas Enlazadas Simples y Circulares

Se usará la siguiente estructura de nodo en ambos ejercicios:

```cpp
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
```

---

## Ejercicio 1: Lista Simple — Mover la Última al Frente

### Descripción

Dada una **lista enlazada simple**, implementa la función que toma el **último nodo** y lo mueve al **frente** de la lista, reordenando los punteros. El resto de los nodos mantiene su orden relativo.

```
1 -> 2 -> 3 -> 4   =>   4 -> 1 -> 2 -> 3
7                     =>   7          (no cambia)
vacia                 =>   vacia      (no cambia)
```

Implementa:

```cpp
Node* moverUltimaAlFrente(Node* head);
```

**Restricciones:**

- Solo librerías `<iostream>`
- Debe devolver el nuevo `head` (el nodo que estaba al final)
- Manejar los casos borde: lista vacía y lista de un solo nodo
- No se permite copiar valores entre nodos, solo reencadenar punteros
- Complejidad temporal: O(n)

### Ejemplo

```
main:
  // 1 -> 2 -> 3 -> 4
  Node* head = new Node(1);
  ... (construir la lista) ...

  head = moverUltimaAlFrente(head);
  imprimir(head);   // 4 -> 1 -> 2 -> 3

Output:
  4 -> 1 -> 2 -> 3
```

---

## Ejercicio 2: Lista Simple Circular — Problema de Joséfo

### Descripción

`n` personas están de pie en un **círculo** numeradas de `1` a `n` (representado por una **lista enlazada simple circular**). Se van eliminando cada `k`-ésima persona (contando en el sentido de las manecillas del reloj) hasta que queda una sola. Devuelve el número de la persona que sobrevive.

En `main` se construye la lista circular (con un helper `crearListaCircular(int n)` que devuelve el `head`) y se pasa como parámetro a la función.

Implementa:

```cpp
int josephus(Node* head, int k);
```

**Restricciones:**

- `head` es el primer nodo de una lista **circular** ya construida (el `next` del último nodo apunta al primero)
- En cada eliminación, liberar la memoria del nodo con `delete`
- Al final debe quedar un solo nodo en la lista; devolver su `data` y liberarlo
- Validar `head != nullptr` y `k > 0` (lanzar `std::invalid_argument` en caso contrario)
- Complejidad temporal: O(n · k)

### Ejemplo

```
main:
  Node* lista1 = crearListaCircular(7);
  std::cout << josephus(lista1, 3) << std::endl;  // 4

  Node* lista2 = crearListaCircular(5);
  std::cout << josephus(lista2, 2) << std::endl;  // 3

Output:
  4
  3
```

### Pista

Con `n = 7, k = 3` las eliminaciones van en este orden: `3, 6, 2, 7, 5, 1` → sobrevive el `4`.
En cada paso: avanza `k - 1` nodos desde la posición actual, elimina al nodo siguiente, y continúa desde ahí.

---

**Volver al [README del curso](../../Readme.md)**
