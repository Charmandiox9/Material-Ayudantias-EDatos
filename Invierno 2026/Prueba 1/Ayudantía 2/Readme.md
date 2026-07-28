# Ayudantía 2: Aritmética de Punteros, Control de Errores y Sobrecarga de Operadores

## Ejercicio 1: Array Dinámico con Sobrecarga de Operadores

### Descripción

Implementa una clase `ArrayDinamico` que gestione un arreglo unidimensional de enteros usando **punteros dinámicos** (sin `std::vector`). Debes sobrecargar los siguientes operadores:

- `operator[]` — acceso con validación de índices: `arr[i]`
- `operator<<` (stream) — imprime el contenido del arreglo
- `operator=` — asignación con manejo de memoria seguro

**Restricciones:**

- Constructor recibe el tamaño del arreglo
- Destructor debe liberar la memoria (`delete[]`)
- `operator[]` debe lanzar `out_of_range` si el índice es inválido
- Se requiere la Regla de Tres (destructor, constructor copia, operador asignación)

### Ejemplo

```
main:
  ArrayDinamico a(5);
  a[0] = 10; a[1] = 20; a[2] = 30; a[3] = 40; a[4] = 50;

  ArrayDinamico b = a;
  std::cout << b;

  ArrayDinamico c(3);
  c = a;  // asignación
  std::cout << c;

Output:
  [10 20 30 40 50]
  [10 20 30 40 50]
```

---

## Ejercicio 2: Punteros — Invertir y Buscar en Arreglos

### Descripción

Implementa dos funciones usando **únicamente aritmética de punteros** (sin `[]`):

1. **`invertir`**: Invierte un arreglo en su lugar
2. **`buscar`**: Busca un valor en el arreglo y devuelve el índice (o -1 si no se encuentra)

Implementa validación de punteros nulos y tamaños inválidos que lance `invalid_argument`.

La función `invertir` debe recibir:

- `int* arr, int size` — puntero y tamaño del arreglo

La función `buscar` debe recibir:

- `int* arr, int size, int target` — puntero, tamaño y valor a buscar

**Restricciones:**

- Solo usar aritmética de punteros (`*(ptr + i)`), no `arr[i]`
- Validar entradas al inicio
- Complejidad temporal: O(n) para cada función

### Ejemplo

```
main:
  int arr[] = {1, 2, 3, 4, 5};
  invertir(arr, 5);
  buscar(arr, 5, 3);
  buscar(arr, 5, 9);

Output:
  Arreglo invertido: [5 4 3 2 1]
  Elemento 3 encontrado en indice: 2
  Elemento 9 no encontrado: -1
```

---

**Volver al [README del curso](../../Readme.md)**
