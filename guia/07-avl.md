## 7. Árbol AVL

## Índice
- [7. Árbol AVL](#7-árbol-avl)
- [Índice](#índice)
  - [Factor de Balance (FB)](#factor-de-balance-fb)
  - [Rotaciones](#rotaciones)
    - [Rotación LL — desbalance hacia la izquierda](#rotación-ll--desbalance-hacia-la-izquierda)
    - [Rotación RR — desbalance hacia la derecha](#rotación-rr--desbalance-hacia-la-derecha)
    - [Rotación LR — izquierda luego derecha](#rotación-lr--izquierda-luego-derecha)
    - [Rotación RL — derecha luego izquierda](#rotación-rl--derecha-luego-izquierda)
  - [Inserción con rebalanceo](#inserción-con-rebalanceo)
  - [Resumen de casos](#resumen-de-casos)

---

Un **AVL** es un BST que se **autobalancea** tras cada inserción o
eliminación. Garantiza que las operaciones siempre sean O(log n),
evitando el peor caso del BST normal.

---

### Factor de Balance (FB)

El FB de un nodo se calcula como:
```
FB = altura(subárbol izquierdo) - altura(subárbol derecho)
```

- FB válido: `-1`, `0` o `+1`
- Si FB cae fuera de ese rango → el árbol se **desbalancea** → hay que rotar
```
        4  ← FB = 0 (altura izq = altura der = 1)
       / \
      2   6   ← FB = 0
     / \
    1   3     ← FB = 0
```
```cpp
struct Nodo {
    int dato;
    int altura;
    Nodo* izq;
    Nodo* der;
    Nodo(int val) : dato(val), altura(1), izq(nullptr), der(nullptr) {}
};

int altura(Nodo* n) {
    return n ? n->altura : 0;
}

int factorBalance(Nodo* n) {
    return n ? altura(n->izq) - altura(n->der) : 0;
}
```

---

### Rotaciones

Cuando el árbol se desbalancea se corrige con rotaciones.
Hay 4 casos:

#### Rotación LL — desbalance hacia la izquierda
Ocurre cuando FB > 1 y la inserción fue en el **hijo izquierdo izquierdo**.
```
    z (FB=+2)          y
   /          →       / \
  y (FB=+1)          x   z
 /
x
```
```cpp
Nodo* rotarDerecha(Nodo* z) {
    Nodo* y = z->izq;
    Nodo* T = y->der;
    y->der = z;
    z->izq = T;
    z->altura = max(altura(z->izq), altura(z->der)) + 1;
    y->altura = max(altura(y->izq), altura(y->der)) + 1;
    return y;
}
```

#### Rotación RR — desbalance hacia la derecha
Ocurre cuando FB < -1 y la inserción fue en el **hijo derecho derecho**.
```
x (FB=-2)               y
 \           →          / \
  y (FB=-1)            x   z
   \
    z
```
```cpp
Nodo* rotarIzquierda(Nodo* x) {
    Nodo* y = x->der;
    Nodo* T = y->izq;
    y->izq = x;
    x->der = T;
    x->altura = max(altura(x->izq), altura(x->der)) + 1;
    y->altura = max(altura(y->izq), altura(y->der)) + 1;
    return y;
}
```

#### Rotación LR — izquierda luego derecha
Ocurre cuando FB > 1 y la inserción fue en el **hijo izquierdo derecho**.
```
  z (FB=+2)         z            x
 /          →      /     →      / \
y (FB=-1)         x            y   z
 \               /
  x             y
```
```cpp
// Primero rotar izquierda sobre y, luego derecha sobre z
if (fb > 1 && val > raiz->izq->dato) {
    raiz->izq = rotarIzquierda(raiz->izq);
    return rotarDerecha(raiz);
}
```

#### Rotación RL — derecha luego izquierda
Ocurre cuando FB < -1 y la inserción fue en el **hijo derecho izquierdo**.
```
x (FB=-2)      x               y
 \      →       \      →      / \
  z (FB=+1)      y            x   z
 /                \
y                  z
```
```cpp
// Primero rotar derecha sobre z, luego izquierda sobre x
if (fb < -1 && val < raiz->der->dato) {
    raiz->der = rotarDerecha(raiz->der);
    return rotarIzquierda(raiz);
}
```

---

### Inserción con rebalanceo
```cpp
Nodo* insertar(Nodo* raiz, int val) {
    // 1. Inserción BST normal
    if (!raiz) return new Nodo(val);
    if (val < raiz->dato)
        raiz->izq = insertar(raiz->izq, val);
    else if (val > raiz->dato)
        raiz->der = insertar(raiz->der, val);
    else return raiz;   // duplicados no permitidos

    // 2. Actualizar altura
    raiz->altura = max(altura(raiz->izq), altura(raiz->der)) + 1;

    // 3. Calcular FB y aplicar rotación correspondiente
    int fb = factorBalance(raiz);

    if (fb > 1 && val < raiz->izq->dato)        // LL
        return rotarDerecha(raiz);

    if (fb < -1 && val > raiz->der->dato)        // RR
        return rotarIzquierda(raiz);

    if (fb > 1 && val > raiz->izq->dato) {       // LR
        raiz->izq = rotarIzquierda(raiz->izq);
        return rotarDerecha(raiz);
    }

    if (fb < -1 && val < raiz->der->dato) {      // RL
        raiz->der = rotarDerecha(raiz->der);
        return rotarIzquierda(raiz);
    }

    return raiz;
}
```

---

### Resumen de casos

| Caso | Condición | Rotación |
|---|---|---|
| LL | FB > 1 y val < izq | Derecha |
| RR | FB < -1 y val > der | Izquierda |
| LR | FB > 1 y val > izq | Izquierda + Derecha |
| RL | FB < -1 y val < der | Derecha + Izquierda |