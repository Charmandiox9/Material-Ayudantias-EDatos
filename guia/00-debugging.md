## Debugging en C++

Guía de errores frecuentes al trabajar con memoria, punteros y
estructuras de datos en C++.

---

## Índice
- [Errores comunes de compilación](#errores-comunes-de-compilación)
- [Segmentation Fault](#segmentation-fault)
- [Memory Leak](#memory-leak)
- [Dangling Pointer](#dangling-pointer)

---

### Errores comunes de compilación

#### `error: use of undeclared identifier`
Usas una variable que no fue declarada en ese scope.
```cpp
// ❌
void foo() {
    cout << x << endl;  // x no existe aquí
}

// ✅
void foo() {
    int x = 10;
    cout << x << endl;
}
```

---

#### `error: no matching function for call`
Llamas una función con parámetros del tipo equivocado.
```cpp
void imprimir(int x) { cout << x; }

// ❌
imprimir("hola");   // string ≠ int

// ✅
imprimir(42);
```

---

#### `error: expected ';' before '}'`
Falta un punto y coma. El compilador lo detecta una línea después
del error real — revisa la línea **anterior** al error indicado.
```cpp
// ❌
int x = 10   // falta ;
int y = 20;

// ✅
int x = 10;
int y = 20;
```

---

#### `error: ISO C++ forbids variable length arrays`
C++ no permite arreglos con tamaño definido en tiempo de ejecución.
Usa `vector` en su lugar.
```cpp
// ❌
int n;
cin >> n;
int arr[n];     // tamaño no conocido en compilación

// ✅
int n;
cin >> n;
vector<int> arr(n);
```

---

#### `error: base class undefined` / `error: does not name a type`
La clase base no fue declarada antes de la clase hija, o falta el
`#include` correspondiente.
```cpp
// ❌
class Perro : public Animal { };  // Animal no fue declarado aún

// ✅
class Animal { };
class Perro : public Animal { };
```

---

### Segmentation Fault

Ocurre cuando el programa intenta **acceder a memoria que no le
pertenece**. Es uno de los errores más frecuentes al trabajar con
punteros.

**Causas más comunes:**

#### 1. Desreferenciar un puntero nulo
```cpp
// ❌
Nodo* nodo = nullptr;
cout << nodo->dato;   // segfault: nodo no apunta a nada

// ✅
if (nodo != nullptr)
    cout << nodo->dato;
```

#### 2. Acceder fuera de los límites de un arreglo
```cpp
// ❌
int arr[5] = {1, 2, 3, 4, 5};
cout << arr[5];   // índice 5 no existe (0..4)

// ✅
for (int i = 0; i < 5; i++)
    cout << arr[i];
```

#### 3. Usar memoria ya liberada
```cpp
// ❌
int* ptr = new int(10);
delete ptr;
cout << *ptr;   // segfault: memoria ya fue liberada

// ✅
delete ptr;
ptr = nullptr;  // siempre nullear después de delete
```

#### 4. Recursión infinita (stack overflow)
```cpp
// ❌
void f(int n) {
    f(n);   // nunca llega al caso base → desborda el stack
}

// ✅
void f(int n) {
    if (n == 0) return;   // caso base obligatorio
    f(n - 1);
}
```

> **Cómo detectarlo:** compila con `-g` y ejecuta con AddressSanitizer:
> ```bash
> g++ -g -fsanitize=address -o programa main.cpp
> ./programa
> ```
> El output indicará exactamente en qué línea ocurrió el acceso inválido.

---

### Memory Leak

Ocurre cuando se reserva memoria con `new` pero **nunca se libera**
con `delete`. El programa no falla inmediatamente, pero consume
memoria creciente hasta agotarla.
```cpp
// ❌ — leak: nunca se libera el nodo
void agregar(int val) {
    Nodo* nuevo = new Nodo(val);
    // ... se pierde la referencia sin hacer delete
}

// ✅ — liberar cuando ya no se necesita
void agregar(int val) {
    Nodo* nuevo = new Nodo(val);
    // usar el nodo...
    delete nuevo;
}
```

#### Leak en listas enlazadas — error frecuente
Al eliminar una lista hay que recorrerla y liberar **cada nodo**:
```cpp
// ❌ — solo borra el head, el resto queda en memoria
delete head;

// ✅ — liberar nodo por nodo
void destruir(Nodo* head) {
    while (head != nullptr) {
        Nodo* temp = head;
        head = head->siguiente;
        delete temp;           // liberar antes de avanzar
    }
}
```

#### Regla general
```
por cada  new  →  debe existir un  delete
por cada  new[] →  debe existir un  delete[]
```

> **Cómo detectarlo:** usa Valgrind para ver exactamente cuántos bytes
> quedaron sin liberar y en qué línea fueron reservados:
> ```bash
> g++ -g -o programa main.cpp
> valgrind --leak-check=full ./programa
> ```

---

### Dangling Pointer

Un **dangling pointer** es un puntero que sigue apuntando a una
dirección de memoria que ya fue liberada o que ya no es válida.
No siempre causa un crash inmediato — a veces lee basura silenciosamente.

#### Caso 1 — puntero a memoria liberada
```cpp
// ❌
int* ptr = new int(42);
delete ptr;
cout << *ptr;   // ptr sigue apuntando ahí, pero es basura

// ✅ — nullear siempre después de delete
delete ptr;
ptr = nullptr;
if (ptr) cout << *ptr;   // nunca entra
```

#### Caso 2 — puntero a variable local fuera de scope
```cpp
// ❌
int* foo() {
    int x = 10;
    return &x;   // x se destruye al salir de foo()
}

int* ptr = foo();
cout << *ptr;    // dangling: x ya no existe

// ✅ — reservar en el heap si necesitas retornar un puntero
int* foo() {
    int* x = new int(10);
    return x;   // existe hasta que se haga delete
}
```

#### Caso 3 — dos punteros al mismo objeto, uno lo libera
```cpp
// ❌
int* a = new int(5);
int* b = a;      // ambos apuntan al mismo objeto
delete a;
cout << *b;      // dangling: b apunta a memoria liberada

// ✅ — nullear ambos
delete a;
a = nullptr;
b = nullptr;
```

---

### Resumen

| Error | Causa | Señal | Solución |
|---|---|---|---|
| **Segfault** | Acceso a memoria inválida | Crash inmediato | Verificar punteros antes de usar |
| **Memory Leak** | `new` sin `delete` | Memoria crece con el tiempo | Liberar cada nodo, usar destructores |
| **Dangling Pointer** | Usar puntero tras `delete` | Comportamiento indefinido | Nullear puntero tras `delete` |

> **Regla de oro:** si usas `new`, siempre pregúntate
> ¿dónde y cuándo hago el `delete`?