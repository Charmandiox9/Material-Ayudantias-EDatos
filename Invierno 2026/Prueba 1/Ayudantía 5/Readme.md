# Ayudantía 5: Stacks y Queues

## Ejercicio 1: Validar Expresiones con Paréntesis Anidados

### Descripción

Implementa una función que valide si una expresión matemática tiene los paréntesis,
corchetes y llaves **balanceados y correctamente anidados**. La función debe usar
una pila de la librería estándar (`std::stack`).

La función debe recibir una cadena de caracteres (usando `char*`) y devolver `true`
si está balanceada, `false` en caso contrario.

**Restricciones:**

- Usar `std::stack<char>` de la librería `<stack>`
- Librerías permitidas: `<iostream>`, `<stack>`
- Complejidad temporal: O(n)
- Complejidad espacial: O(n)

### Ejemplo

```
Input:  "(3 + [4 * {2 - 1}])"
Output: true

Input:  "([)]"
Output: false

Input:  "{[()]"
Output: false
```

---

## Ejercicio 2: Two Stacks — Implementar Queue

### Descripción

Implementa una **cola (Queue)** usando **dos pilas** de la librería estándar (`std::stack`).
La cola debe soportar:

- `enqueue(val)` — agregar al final
- `dequeue()` — quitar del frente
- `peek()` — ver el primer elemento sin quitarlo
- `isEmpty()` — verificar si está vacía

**Restricciones:**

- Debes implementar `Queue` usando dos `std::stack<int>` como miembros internos
- No usar `std::queue`, ni `std::vector`
- Librerías permitidas: `<iostream>`, `<stack>`, `<stdexcept>`

### Ejemplo

```
operaciones:
  q.enqueue(1); q.enqueue(2); q.enqueue(3);
  q.peek();    // 1
  q.dequeue(); // quita 1
  q.dequeue(); // quita 2
  q.peek();    // 3

Output:
  Peek: 1
  Dequeued: 1
  Dequeued: 2
  Peek: 3
```

---

**Volver al [README del curso](../../Readme.md)**
