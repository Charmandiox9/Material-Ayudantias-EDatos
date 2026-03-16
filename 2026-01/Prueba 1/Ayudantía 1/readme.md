# Ayudantía 1 — Punteros, Referencias y Direcciones de Memoria en C++

**Asignatura:** Estructuras de Datos  
**Sección:** 1 de 13  
**Duración:** 1 hora 30 minutos  
**Nivel:** Segundo año de Ingeniería

---

## Contenidos de la Sesión

- Direcciones de memoria y el operador `&`
- Punteros: declaración, asignación y desreferenciación
- Aritmética de punteros
- Referencias vs Punteros
- Paso por valor, por referencia y por puntero
- Punteros a punteros (doble puntero)

---

## Repaso Teórico

### ¿Qué es una dirección de memoria?

Toda variable en C++ ocupa un espacio en memoria. Ese espacio tiene una **dirección** (normalmente expresada en hexadecimal). El operador `&` permite obtener dicha dirección.

```cpp
int x = 42;
cout << &x;  // Imprime algo como: 0x7ffee4b2a9ac
```

### ¿Qué es un puntero?

Un puntero es una variable que **almacena una dirección de memoria**.

```
int x = 42;       Memoria:
int* p = &x;      ┌──────────────┬─────────┐
                  │ Dirección    │  Valor  │
                  ├──────────────┼─────────┤
                  │ 0x1000  (x)  │   42    │
                  │ 0x1008  (p)  │ 0x1000  │
                  └──────────────┴─────────┘
```

- `p` almacena la dirección de `x`
- `*p` (desreferenciar) accede al valor en esa dirección → `42`

### ¿Qué es una referencia?

Una referencia es un **alias** de una variable existente. No puede ser reasignada ni puede ser `null`.

```cpp
int x = 10;
int& ref = x;   // ref ES x
ref = 20;       // x ahora vale 20
```

---

## Ejercicio 1 — Swap con punteros y con referencias (30 min)

### Enunciado

Implementa **dos versiones** de una función que intercambie los valores de dos enteros:

1. `swapPunteros(int* a, int* b)` — usando punteros
2. `swapReferencias(int& a, int& b)` — usando referencias

Además, muestra en pantalla las direcciones de memoria de las variables antes y después del intercambio para verificar que son las mismas variables (no copias).

### Entrada

Dos enteros `x` e `y` ingresados por el usuario.

### Salida esperada

```
=== Swap con Punteros ===
Antes:  x = 5  (dir: 0x7ffd...)   y = 10  (dir: 0x7ffd...)
Despues: x = 10  y = 5
Direcciones: x sigue en 0x7ffd...  y sigue en 0x7ffd...

=== Swap con Referencias ===
Antes:  a = 3  (dir: 0x7ffd...)   b = 7  (dir: 0x7ffd...)
Despues: a = 7  b = 3
```

### Conceptos clave

| Concepto | Sintaxis | Descripción |
|---|---|---|
| Obtener dirección | `&var` | Dirección de `var` |
| Declarar puntero | `int* p` | `p` guarda una dirección a `int` |
| Desreferenciar | `*p` | Valor en la dirección que guarda `p` |
| Referencia | `int& r = var` | `r` es otro nombre para `var` |

> **Pista:** Para intercambiar via punteros, necesitas una variable temporal y trabajar con `*a` y `*b`.

---

## Ejercicio 2 — Aritmética de Punteros y Recorrido de Arreglo (25 min)

### Enunciado

Dado un arreglo de enteros, implementa las siguientes funciones **sin usar índices** (`arr[i]`), sino usando **aritmética de punteros**:

1. `imprimirArreglo(int* arr, int n)` — imprime todos los elementos
2. `buscarMaximo(int* arr, int n)` — retorna el valor máximo

### Diagrama de memoria

```
arr = 0x2000

  0x2000  0x2004  0x2008  0x200C  0x2010
  ┌───────┬───────┬───────┬───────┬───────┐
  │   3   │   9   │   1   │   7   │   4   │
  └───────┴───────┴───────┴───────┴───────┘
  arr+0   arr+1   arr+2   arr+3   arr+4
  *arr   *(arr+1) *(arr+2) *(arr+3) *(arr+4)
```

### Entrada

```
n = 5
arreglo = {3, 9, 1, 7, 4}
```

### Salida esperada

```
Elementos: 3 9 1 7 4
Maximo: 9
Direccion del maximo: 0x2004
```

### Conceptos clave

- `arr + i` apunta al elemento en la posición `i`
- `*(arr + i)` es equivalente a `arr[i]`
- Cada `int` ocupa 4 bytes, por lo que sumar 1 al puntero avanza 4 bytes

> **Pista:** Comienza con `int* ptr = arr` y avanza con `ptr++` en un ciclo.

---

## Ejercicio 3 — Doble Puntero y Modificación desde Función (35 min)

### Enunciado

Implementa una función `crearArreglo(int** arr, int n)` que:

1. Reserve memoria dinámica para un arreglo de `n` enteros
2. Llene el arreglo con los valores `1, 2, 3, ..., n`
3. Modifique el puntero del llamador para que apunte al nuevo arreglo

Luego implementa `liberarArreglo(int** arr)` que libere la memoria y ponga el puntero en `nullptr`.

### ¿Por qué doble puntero?

```
main():                    crearArreglo():
┌──────────┐               ┌──────────────┐
│ ptr=null │ ← dirección   │ *arr = nueva │
│ &ptr=0xA │──────────────▶│  memoria     │
└──────────┘               └──────────────┘
     │
     ▼ (después de llamar)
 [1][2][3][4][5]
```

Si pasaras sólo `int* arr`, modificarías una copia del puntero, no el puntero original.

### Entrada

```
n = 5
```

### Salida esperada

```
Arreglo creado en: 0x...
Contenido: 1 2 3 4 5
Memoria liberada. ptr = 0 (nullptr)
```

### Conceptos clave

| Sintaxis | Significado |
|---|---|
| `int** pp` | Puntero a puntero a entero |
| `*pp` | El puntero interno (tipo `int*`) |
| `**pp` | El valor al que apunta el puntero interno |
| `new int[n]` | Reserva memoria dinámica |
| `delete[] arr` | Libera arreglo dinámico |

> **Pista:** Dentro de `crearArreglo`, usa `*arr = new int[n]` para asignar la nueva memoria al puntero original.

---

## Resumen de Operadores

| Operador | Nombre | Ejemplo | Resultado |
|---|---|---|---|
| `&` | Dirección de | `&x` | Dirección de `x` |
| `*` | Desreferenciar | `*p` | Valor en la dir. de `p` |
| `->` | Acceso via puntero | `p->campo` | Igual que `(*p).campo` |
| `new` | Memoria dinámica | `new int` | Dirección del `int` nuevo |
| `delete` | Liberar memoria | `delete p` | Libera lo apuntado por `p` |