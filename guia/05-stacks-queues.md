## 5. Stacks & Queues

## Índice
- [5. Stacks \& Queues](#5-stacks--queues)
- [Índice](#índice)
  - [Stack (Pila)](#stack-pila)
  - [Queue (Cola)](#queue-cola)
  - [Complejidad de operaciones](#complejidad-de-operaciones)
  - [Comparación](#comparación)
  - [¿Cuándo usar cada una?](#cuándo-usar-cada-una)

---

Ambas son estructuras **lineales y restringidas**: solo permiten insertar
y eliminar elementos por posiciones específicas. Su diferencia está en
el orden de salida.

---

### Stack (Pila)

Funciona bajo el principio **LIFO** — *Last In, First Out*.
El último en entrar es el primero en salir.
```
push(10) push(20) push(30)
                   ┌────┐ ← top
                   │ 30 │
                   ├────┤
                   │ 20 │
                   ├────┤
                   │ 10 │
                   └────┘
pop() → devuelve 30
```
```cpp
#include <stack>

stack<int> s;

s.push(10);     // insertar
s.push(20);
s.push(30);

s.top();        // ver el tope → 30 (sin eliminar)
s.pop();        // eliminar el tope → quita 30
s.empty();      // verificar si está vacía → false
s.size();       // cantidad de elementos → 2
```

---

### Queue (Cola)

Funciona bajo el principio **FIFO** — *First In, First Out*.
El primero en entrar es el primero en salir.
```
enqueue(10) enqueue(20) enqueue(30)

front                         back
  │                            │
  ▼                            ▼
┌────┬────┬────┐
│ 10 │ 20 │ 30 │
└────┴────┴────┘

dequeue() → devuelve 10
```
```cpp
#include <queue>

queue<int> q;

q.push(10);     // insertar por el back
q.push(20);
q.push(30);

q.front();      // ver el primero → 10 (sin eliminar)
q.back();       // ver el último → 30 (sin eliminar)
q.pop();        // eliminar el frente → quita 10
q.empty();      // verificar si está vacía → false
q.size();       // cantidad de elementos → 2
```

---

### Complejidad de operaciones

| Operación | Stack | Queue |
|---|---|---|
| Insertar (`push`) | O(1) | O(1) |
| Eliminar (`pop`) | O(1) | O(1) |
| Ver siguiente (`top`/`front`) | O(1) | O(1) |
| Buscar un elemento | O(n) | O(n) |
| Espacio | O(n) | O(n) |

> Todas las operaciones principales son O(1) porque solo se opera
> sobre un extremo fijo — no hay recorrido.

---

### Comparación

| | Stack | Queue |
|---|---|---|
| Principio | LIFO | FIFO |
| Inserción | Solo por el tope | Solo por el back |
| Eliminación | Solo por el tope | Solo por el front |
| Acceso directo | Solo al tope | Solo al front |
| Analogía | Pila de platos | Fila del supermercado |

---

### ¿Cuándo usar cada una?

| Estructura | Úsala cuando... |
|---|---|
| **Stack** | Necesitas deshacer operaciones (undo), evaluar expresiones matemáticas, recorrer estructuras recursivas (DFS), gestionar el call stack |
| **Queue** | Necesitas procesar tareas en orden de llegada (BFS), sistemas de turnos, buffers de datos, colas de impresión |