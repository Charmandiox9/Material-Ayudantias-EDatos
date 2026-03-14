## 1. Punteros, Referencias y Direcciones de Memoria

## Índice
- [1. Punteros, Referencias y Direcciones de Memoria](#1-punteros-referencias-y-direcciones-de-memoria)
- [Índice](#índice)
  - [¿Qué es la memoria?](#qué-es-la-memoria)
  - [Puntero](#puntero)
  - [Referencia](#referencia)
  - [Diferencias clave](#diferencias-clave)

---

### ¿Qué es la memoria?
La memoria RAM puede pensarse como una tabla: cada fila tiene una **dirección única** (ej: `0x1000`) y un **valor almacenado**. Cuando declaras una variable, el sistema te asigna una de esas filas.
```
Dirección   | Variable | Valor
------------|----------|------------------
0x1000      | x        | 42
0x1004      | y        | 99
0x1008      | ptr      | 0x1000  ← dirección de x
```

---

### Puntero
Variable que **guarda una dirección** de memoria. Puede cambiar a qué apunta y puede ser `nullptr`.
```cpp
int x = 42;
int* ptr = &x;  // ptr guarda la dirección de x
*ptr = 10;      // modifica x a través del puntero
ptr = &y;       // reasignable
```

- `&x` → obtiene la dirección de `x`
- `*ptr` → accede al valor en esa dirección (desreferencia)

---

### Referencia
**Alias permanente** de otra variable. No ocupa celda propia, no puede ser `nullptr` y debe inicializarse al declararse.
```cpp
int x = 42;
int& ref = x;   // ref ES x, mismo espacio de memoria
ref = 10;       // x también cambia a 10
// ref = y;     // ❌ no se puede reasignar
```

---

### Diferencias clave

| | Puntero `int*` | Referencia `int&` |
|---|---|---|
| Puede ser `nullptr` | ✅ | ❌ |
| Se puede reasignar | ✅ | ❌ |
| Requiere `*` para acceder al valor | ✅ | ❌ |
| Debe inicializarse | ❌ | ✅ |