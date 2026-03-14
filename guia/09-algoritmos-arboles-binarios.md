## 9. Algoritmos en Árboles Binarios

## Índice
- [9. Algoritmos en Árboles Binarios](#9-algoritmos-en-árboles-binarios)
- [Índice](#índice)
  - [Nodo base para todos los ejercicios](#nodo-base-para-todos-los-ejercicios)
  - [1. Reconstruir árbol desde Inorder + Preorder](#1-reconstruir-árbol-desde-inorder--preorder)
  - [2. Reconstruir árbol desde Inorder + Postorder](#2-reconstruir-árbol-desde-inorder--postorder)
  - [3. Encontrar la Altura del Árbol](#3-encontrar-la-altura-del-árbol)
  - [4. Mínimo y Máximo en BST](#4-mínimo-y-máximo-en-bst)
  - [5. Verificar si un BST es Válido](#5-verificar-si-un-bst-es-válido)
  - [6. LCA — Ancestro Común más Cercano](#6-lca--ancestro-común-más-cercano)
  - [Resumen de complejidades](#resumen-de-complejidades)

---

### Nodo base para todos los ejercicios
```cpp
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    Nodo(int val) : dato(val), izq(nullptr), der(nullptr) {}
};
```

---

### 1. Reconstruir árbol desde Inorder + Preorder

**Clave:**
- **Preorder:** el **primer** elemento siempre es la raíz
- **Inorder:** todo lo que está a la **izquierda** de la raíz en inorder
  es el subárbol izquierdo, y lo que está a la **derecha** es el subárbol derecho

**Ejemplo:**
```
Preorder: [4, 2, 1, 3, 6, 5, 7]
Inorder:  [1, 2, 3, 4, 5, 6, 7]

Paso 1: raíz = 4 (primero del preorder)
Paso 2: en inorder, 4 está en índice 3
        → izquierda: [1, 2, 3] → derecha: [5, 6, 7]
Paso 3: siguiente en preorder es 2 → raíz del subárbol izquierdo
        → en inorder [1, 2, 3], el 2 está en el medio
        → izquierda: [1] → derecha: [3]
Paso 4: siguiente es 6 → raíz del subárbol derecho
        → en inorder [5, 6, 7], el 6 está en el medio
        → izquierda: [5] → derecha: [7]

Resultado:
        4
       / \
      2   6
     / \ / \
    1  3 5  7
```
```cpp
Nodo* construirPreIn(vector<int>& pre, vector<int>& in,
                     int preInicio, int inInicio, int inFin) {
    if (preInicio >= pre.size() || inInicio > inFin) return nullptr;

    Nodo* raiz = new Nodo(pre[preInicio]);

    // buscar la raíz en inorder
    int mid = inInicio;
    while (in[mid] != raiz->dato) mid++;

    int tamIzq = mid - inInicio;

    raiz->izq = construirPreIn(pre, in, preInicio + 1,
                                inInicio, mid - 1);
    raiz->der = construirPreIn(pre, in, preInicio + tamIzq + 1,
                                mid + 1, inFin);
    return raiz;
}

// Llamada inicial
Nodo* raiz = construirPreIn(pre, in, 0, 0, in.size() - 1);
```

---

### 2. Reconstruir árbol desde Inorder + Postorder

**Clave:**
- **Postorder:** el **último** elemento siempre es la raíz
- **Inorder:** misma lógica de partición izquierda/derecha

**Ejemplo:**
```
Postorder: [1, 3, 2, 5, 7, 6, 4]
Inorder:   [1, 2, 3, 4, 5, 6, 7]

Paso 1: raíz = 4 (último del postorder)
Paso 2: en inorder, 4 está en índice 3
        → izquierda: [1, 2, 3] → derecha: [5, 6, 7]
Paso 3: siguiente desde el final del postorder es 2
        → raíz del subárbol izquierdo
        → en inorder [1, 2, 3], el 2 divide en [1] y [3]
Paso 4: siguiente es 6 → raíz del subárbol derecho
        → en inorder [5, 6, 7], divide en [5] y [7]

Resultado:
        4
       / \
      2   6
     / \ / \
    1  3 5  7
```
```cpp
Nodo* construirPostIn(vector<int>& post, vector<int>& in,
                      int postFin, int inInicio, int inFin) {
    if (postFin < 0 || inInicio > inFin) return nullptr;

    Nodo* raiz = new Nodo(post[postFin]);

    // buscar la raíz en inorder
    int mid = inInicio;
    while (in[mid] != raiz->dato) mid++;

    int tamIzq = mid - inInicio;

    raiz->izq = construirPostIn(post, in, postFin - (inFin - mid) - 1,
                                 inInicio, mid - 1);
    raiz->der = construirPostIn(post, in, postFin - 1,
                                 mid + 1, inFin);
    return raiz;
}

// Llamada inicial
Nodo* raiz = construirPostIn(post, in, post.size() - 1, 0, in.size() - 1);
```

---

### 3. Encontrar la Altura del Árbol

**Altura** = cantidad de niveles. Un árbol vacío tiene altura 0.
```
        4          altura = 3
       / \
      2   6        altura = 2
     / \
    1   3          altura = 1
```
```cpp
int altura(Nodo* raiz) {
    if (!raiz) return 0;
    int izq = altura(raiz->izq);
    int der = altura(raiz->der);
    return max(izq, der) + 1;
}
// altura(raiz) → 3
```

---

### 4. Mínimo y Máximo en BST

En un BST el **mínimo** siempre está en el extremo izquierdo
y el **máximo** en el extremo derecho.
```
        10
       /  \
      5    15
     / \     \
    3   7     20

mínimo → 3 (ir siempre a la izquierda)
máximo → 20 (ir siempre a la derecha)
```
```cpp
int minimo(Nodo* raiz) {
    if (!raiz) return -1;
    while (raiz->izq) raiz = raiz->izq;
    return raiz->dato;
}

int maximo(Nodo* raiz) {
    if (!raiz) return -1;
    while (raiz->der) raiz = raiz->der;
    return raiz->dato;
}
// minimo(raiz) → 3
// maximo(raiz) → 20
```

---

### 5. Verificar si un BST es Válido

No basta verificar que cada nodo sea mayor que su hijo izquierdo
y menor que su hijo derecho. Hay que propagar un rango válido.

**Contraejemplo que engaña la verificación simple:**
```
        10
       /  \
      5    15
       \
        12   ← 12 > 5 ✅ pero 12 > 10 ❌ viola la propiedad BST
```
```cpp
bool esBST(Nodo* raiz, int minVal = INT_MIN, int maxVal = INT_MAX) {
    if (!raiz) return true;
    if (raiz->dato <= minVal || raiz->dato >= maxVal) return false;
    return esBST(raiz->izq, minVal, raiz->dato) &&
           esBST(raiz->der, raiz->dato, maxVal);
}
// esBST(raiz) → false para el árbol del contraejemplo
```

---

### 6. LCA — Ancestro Común más Cercano

El **LCA** de dos nodos `p` y `q` es el nodo más profundo del árbol
que tiene a ambos como descendientes.
```
        4
       / \
      2   6
     / \ / \
    1  3 5  7

LCA(1, 3) → 2   (2 es el padre directo de ambos)
LCA(1, 6) → 4   (4 es el primer nodo que los contiene a ambos)
LCA(5, 7) → 6
```

**En un BST** se puede aprovechar la propiedad de orden:
- Si ambos `p` y `q` son menores que la raíz → LCA está en la izquierda
- Si ambos son mayores → LCA está en la derecha
- Si se separan → la raíz actual **es** el LCA
```cpp
Nodo* LCA(Nodo* raiz, int p, int q) {
    if (!raiz) return nullptr;

    if (p < raiz->dato && q < raiz->dato)
        return LCA(raiz->izq, p, q);   // ambos a la izquierda

    if (p > raiz->dato && q > raiz->dato)
        return LCA(raiz->der, p, q);   // ambos a la derecha

    return raiz;   // se separan aquí → este es el LCA
}
// LCA(raiz, 1, 3)->dato → 2
// LCA(raiz, 1, 6)->dato → 4
```

---

### Resumen de complejidades

| Algoritmo | Tiempo | Espacio |
|---|---|---|
| Reconstruir desde recorridos | O(n²) | O(n) |
| Altura del árbol | O(n) | O(h) |
| Mínimo / Máximo en BST | O(h) | O(1) |
| Verificar BST válido | O(n) | O(h) |
| LCA en BST | O(h) | O(h) |

> `h` = altura del árbol. En un BST balanceado `h = log n`,
> en el peor caso (árbol degenerado) `h = n`.