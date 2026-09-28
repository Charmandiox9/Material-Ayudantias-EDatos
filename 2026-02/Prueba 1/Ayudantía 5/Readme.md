# Ayudantía 5: Pilas y Colas

## Ejercicio 1: Pila — Validar paréntesis balanceados

### Descripción

Usa una **pila** (la `std::stack` de la biblioteca estándar) para determinar si una expresión tiene sus paréntesis **balanceados**. Una expresión está balanceada si:

- Cada paréntesis de apertura (`(`, `[`, `{`) tiene un paréntesis de cierre (`)`, `]`, `}`) que lo cierra.
- Están correctamente **anidados**: el último que se abre es el primero que se cierra.
- No sobran paréntesis de apertura ni de cierre.

Implementa:

```cpp
bool parentesisBalanceados(const string& expr);
```

**Restricciones:**

- Librerías permitidas: `<iostream>`, `<string>` y `<stack>`
- Usar `std::stack` (de `<stack>`), no implementar la pila por cuenta propia
- Manejar el caso de cadena vacía (devolver `true`)
- Complejidad temporal: O(n), recorriendo la expresión una sola vez

### Ejemplo

```
main:
  cout << parentesisBalanceados("(a+b)*(c-d)") << endl;  // 1
  cout << parentesisBalanceados("((a+b)")       << endl;  // 0
  cout << parentesisBalanceados("a(b[c]d)e")    << endl;  // 1
  cout << parentesisBalanceados("(a+b]")        << endl;  // 0
  cout << parentesisBalanceados("")             << endl;  // 1

Output:
  1
  0
  1
  0
  1
```

### Pista

Recorre la expresión carácter a carácter. Cuando aparezca un paréntesis de apertura, haz `push` en la pila. Cuando aparezca uno de cierre, mira el tope con `top`, quítalo con `pop` y verifica que sea el mismo tipo de paréntesis. Al terminar, la pila debe quedar vacía (`empty`). Los caracteres que no son paréntesis se ignoran.

---

## Ejercicio 2: Cola — Primer carácter no repetido

### Descripción

Usa una **cola** (la `std::queue` de la biblioteca estándar) para encontrar el **primer carácter** de un texto que aparece **una sola vez**, considerando el orden en que aparecen los caracteres. Si no existe tal carácter, devuelve `'0'`.

La clave: la cola sirve para recordar el **orden de llegada** de los caracteres, mientras un arreglo de frecuencias indica cuántas veces aparece cada uno.

Implementa:

```cpp
char primerNoRepetido(const string& s);
```

**Restricciones:**

- Librerías permitidas: `<iostream>`, `<string>` y `<queue>`
- Usar `std::queue` (de `<queue>`), no implementar la cola por cuenta propia
- Considerar solo letras minúsculas (`a`–`z`)
- Complejidad temporal: O(n)

### Ejemplo

```
main:
  cout << primerNoRepetido("holaamigo") << endl;  // h
  cout << primerNoRepetido("aabbc")     << endl;  // c
  cout << primerNoRepetido("aabb")      << endl;  // 0

Output:
  h
  c
  0
```

### Pista

Recorre el texto una sola vez: actualiza la frecuencia de cada letra y, al mismo tiempo, agrégala a la cola con `push` (para guardar el orden de llegada). Después, recorre la cola de frente a fondo con `front`/`pop`: el primer carácter cuya frecuencia sea `1` es la respuesta. Si la cola se agota sin encontrar uno, devuelve `'0'`.

---

**Volver al [README del curso](../../Readme.md)**
