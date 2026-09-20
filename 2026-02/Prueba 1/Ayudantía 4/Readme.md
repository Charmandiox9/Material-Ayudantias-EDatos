# Ayudantía 4: Listas Doblemente Enlazadas

Se usará la siguiente estructura de nodo en ambos ejercicios:

```cpp
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};
```

---

## Ejercicio 1: Lista Doble — Invertir la Lista

### Descripción

Dada una **lista enlazada doble** (lineal), implementa la función que **invierte** el orden de los nodos reencadenando los punteros `prev` y `next`. Al final, el nodo que estaba al final pasa a ser el `head` y viceversa.

```
null <-> 1 <-> 2 <-> 3 <-> null
   se convierte en
null <-> 3 <-> 2 <-> 1 <-> null
```

Implementa:

```cpp
Node* invertir(Node* head);
```

**Restricciones:**

- Solo librerías `<iostream>`
- Debe devolver el nuevo `head` (el nodo que estaba al final)
- En cada nodo se intercambian sus punteros `prev` y `next`
- Manejar los casos borde: lista vacía y lista de un solo nodo
- Complejidad temporal: O(n), recorriendo la lista una sola vez

### Ejemplo

```
main:
  // 1 <-> 2 <-> 3
  Node* head = new Node(1);
  ... (construir la lista doble) ...

  head = invertir(head);
  imprimir(head);   // 3 -> 2 -> 1

Output:
  3 -> 2 -> 1
```

---

## Ejercicio 2: Lista Doble Circular — Eliminar Todos los Nodos con un Valor

### Descripción

Dada una **lista enlazada doble circular** (cada nodo apunta al siguiente y al anterior, y el último conecta con el primero en ambas direcciones), implementa la función que **elimina todos los nodos** cuyo `data` sea igual a un valor dado.

Implementa:

```cpp
Node* eliminarValor(Node* head, int valor);
```

La función debe devolver el nuevo `head` de la lista resultante.

**Casos a considerar (lógica importante):**

- Lista vacía (`head == nullptr`) → devolver `nullptr`
- Todos los nodos tienen el valor → devolver `nullptr`
- El `head` tiene el valor → el nuevo `head` es el siguiente nodo que no se elimina
- Queda un solo nodo → debe seguir siendo un círculo válido (`next` y `prev` apuntando a sí mismo)

**Restricciones:**

- Solo librería `<iostream>`
- En cada eliminación, liberar la memoria del nodo con `delete`
- Mantener los punteros `prev` y `next` consistentes en todo momento
- Lista vacía (`head == nullptr`) → devolver `nullptr` sin lanzar error

### Ejemplo

```
main:
  // 1 <-> 2 <-> 3 <-> 2 <-> 4  (circular)
  int vals1[] = {1, 2, 3, 2, 4};
  Node* head = crearListaDobleCircular(vals1, 5);
  head = eliminarValor(head, 2);
  imprimir(head);   // 1 <-> 3 <-> 4  (circular)

  int vals2[] = {5, 5, 5};
  Node* head2 = crearListaDobleCircular(vals2, 3);
  head2 = eliminarValor(head2, 5);
  // head2 == nullptr

Output:
  1 -> 3 -> 4 (circular)
  (lista vacia)
```

### Pista

En una lista circular no hay un "final" natural, así que conviene trabajar con el **predecesor** del nodo a eliminar: `prev->next = nodo->next` y `nodo->next->prev = prev`, y recién después hacer `delete nodo`.

---

**Volver al [README del curso](../../Readme.md)**
