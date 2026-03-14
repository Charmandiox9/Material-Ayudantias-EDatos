## 13. Matrices Poco Pobladas (Sparse Matrix)

---

## Índice
- [13. Matrices Poco Pobladas (Sparse Matrix)](#13-matrices-poco-pobladas-sparse-matrix)
- [Índice](#índice)
  - [¿Qué es una matriz poco poblada?](#qué-es-una-matriz-poco-poblada)
  - [Comparación con matriz densa](#comparación-con-matriz-densa)
  - [Representaciones](#representaciones)
    - [COO — Coordinate Format](#coo--coordinate-format)
    - [CSR — Compressed Sparse Row](#csr--compressed-sparse-row)
    - [Lista de Listas](#lista-de-listas)
  - [Operaciones básicas](#operaciones-básicas)
    - [Suma de dos matrices sparse (COO)](#suma-de-dos-matrices-sparse-coo)
    - [Transponer una matriz sparse (Lista de Listas)](#transponer-una-matriz-sparse-lista-de-listas)
  - [¿Cuándo usar cada representación?](#cuándo-usar-cada-representación)

---

### ¿Qué es una matriz poco poblada?

Una **sparse matrix** es una matriz donde la **mayoría de sus elementos
son cero**. Almacenarla completa desperdicia memoria innecesariamente.
```
Matriz densa 5×5:        Matriz sparse 5×5:

1  2  3  4  5            0  0  3  0  0
6  7  8  9 10            0  0  0  0  0
11 12 13 14 15           0  7  0  0  0
16 17 18 19 20           0  0  0  0  0
21 22 23 24 25           0  0  0  9  0

25 elementos             25 elementos almacenados
todos con valor          pero solo 3 son ≠ 0
```

> Regla general: si más del **70% de los elementos son cero**,
> conviene usar una representación sparse.

---

### Comparación con matriz densa

| | Matriz Densa | Sparse Matrix |
|---|---|---|
| Almacenamiento | O(n²) | O(k) donde k = elementos ≠ 0 |
| Acceso a elemento | O(1) | O(k) o O(log k) según representación |
| Útil cuando | Pocos ceros | Mayoría de elementos son cero |
| Ejemplo de uso | Transformaciones 3D | Grafos, sistemas de ecuaciones |

---

### Representaciones

Matriz de ejemplo para los tres casos:
```
0  0  3  0  0
0  0  0  0  0
0  7  0  0  0
0  0  0  0  0
0  0  0  9  0

Solo 3 elementos ≠ 0:
(0,2) = 3
(2,1) = 7
(4,3) = 9
```

---

#### COO — Coordinate Format

Guarda tres arreglos paralelos: **fila**, **columna** y **valor**
de cada elemento no nulo.
```
fila:    [0, 2, 4]
columna: [2, 1, 3]
valor:   [3, 7, 9]
```
```cpp
struct MatrizCOO {
    vector<int> fila;
    vector<int> col;
    vector<int> val;

    void insertar(int f, int c, int v) {
        fila.push_back(f);
        col.push_back(c);
        val.push_back(v);
    }

    void imprimir() {
        for (int i = 0; i < val.size(); i++)
            cout << "(" << fila[i] << "," << col[i] << ")"
                 << " = " << val[i] << "\n";
    }
};

MatrizCOO m;
m.insertar(0, 2, 3);
m.insertar(2, 1, 7);
m.insertar(4, 3, 9);
```

✅ Simple de construir e iterar  
❌ Acceso a un elemento específico → O(k)  
❌ No eficiente para operaciones por fila

---

#### CSR — Compressed Sparse Row

Comprime la información por filas. Usa tres arreglos:
- `val` → valores no nulos en orden de fila
- `col` → columna de cada valor
- `ptr` → índice en `val` donde empieza cada fila
```
val: [3, 7, 9]
col: [2, 1, 3]
ptr: [0, 1, 1, 2, 2, 3]
      ↑  ↑  ↑  ↑  ↑  ↑
     f0 f1 f2 f3 f4  fin
```

> `ptr[i]` indica dónde empieza la fila `i` en `val`.
> Si `ptr[i] == ptr[i+1]`, la fila `i` no tiene elementos no nulos.
```cpp
struct MatrizCSR {
    int filas;
    vector<int> val;
    vector<int> col;
    vector<int> ptr;

    MatrizCSR(int f) : filas(f), ptr(f + 1, 0) {}

    // Recorrer una fila específica → O(elementos en esa fila)
    void recorrerFila(int f) {
        for (int i = ptr[f]; i < ptr[f + 1]; i++)
            cout << "col " << col[i] << " = " << val[i] << "\n";
    }
};
```

✅ Recorrer fila por fila → muy eficiente  
✅ Ideal para multiplicación de matrices  
❌ Construcción más compleja  
❌ Insertar nuevos elementos → costoso

---

#### Lista de Listas

Cada fila es un `map<columna, valor>`. Solo existen las entradas
con valores no nulos.
```
fila 0: {2: 3}
fila 1: {}
fila 2: {1: 7}
fila 3: {}
fila 4: {3: 9}
```
```cpp
struct MatrizLOL {
    int filas;
    vector<map<int,int>> datos;

    MatrizLOL(int f) : filas(f), datos(f) {}

    // Insertar → O(log k)
    void insertar(int f, int c, int v) {
        datos[f][c] = v;
    }

    // Acceder → O(log k)
    int obtener(int f, int c) {
        if (datos[f].count(c))
            return datos[f][c];
        return 0;
    }

    // Recorrer todos los no nulos
    void imprimir() {
        for (int f = 0; f < filas; f++)
            for (auto [c, v] : datos[f])
                cout << "(" << f << "," << c << ") = " << v << "\n";
    }
};

MatrizLOL m(5);
m.insertar(0, 2, 3);
m.insertar(2, 1, 7);
m.insertar(4, 3, 9);
cout << m.obtener(2, 1);   // 7
cout << m.obtener(0, 0);   // 0
```

✅ Fácil de construir y modificar  
✅ Acceso directo a cualquier elemento → O(log k)  
✅ Inserción dinámica sin reconstruir  
❌ Mayor overhead de memoria que COO y CSR

---

### Operaciones básicas

#### Suma de dos matrices sparse (COO)
```cpp
MatrizLOL sumar(MatrizLOL& a, MatrizLOL& b) {
    MatrizLOL resultado(a.filas);
    for (int f = 0; f < a.filas; f++) {
        for (auto [c, v] : a.datos[f])
            resultado.insertar(f, c, v);
        for (auto [c, v] : b.datos[f])
            resultado.insertar(f, c, resultado.obtener(f, c) + v);
    }
    return resultado;
}
```

#### Transponer una matriz sparse (Lista de Listas)
```cpp
MatrizLOL transponer(MatrizLOL& m, int cols) {
    MatrizLOL resultado(cols);
    for (int f = 0; f < m.filas; f++)
        for (auto [c, v] : m.datos[f])
            resultado.insertar(c, f, v);   // intercambiar fila y columna
    return resultado;
}
```

---

### ¿Cuándo usar cada representación?

| Representación | Úsala cuando... |
|---|---|
| **COO** | Solo necesitas construir e iterar todos los elementos una vez |
| **CSR** | Necesitas operaciones eficientes por fila (multiplicación, sistemas lineales) |
| **Lista de Listas** | Necesitas insertar/modificar elementos dinámicamente |