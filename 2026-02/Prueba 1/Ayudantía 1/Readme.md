# Ayudantía 1: Punteros, Aritmética de Punteros, POO Base y STL

## Ejercicio 1: Aritmética de Punteros — Arreglo Dinámico (POO)

### Descripción

Implementa una clase `ArregloEnteros` que gestione un arreglo dinámico de enteros. Toda la manipulación interna del arreglo debe hacerse con **aritmética de punteros** (`*(ptr + i)`), nunca con el operador `[]`.

La clase debe tener:

- Atributos privados: `int* data` (puntero al arreglo) y `int tamano`
- Constructor `ArregloEnteros(int n)` — reserva memoria con `new int[n]` y valida que `n > 0`
- Método `int get(int i) const` — devuelve el elemento en la posición `i`, lanzando `std::out_of_range` si el índice es inválido
- Método `void set(int i, int valor)` — asigna `valor` en la posición `i`, con la misma validación
- Método `int sumar() const` — suma de todos los elementos
- Método `double promedio() const` — promedio de los elementos
- Método `int maximo() const` e `int minimo() const` — valor mayor y menor
- Método `void duplicar()` — aumenta el tamaño del arreglo al doble, conservando los valores (reservar un arreglo nuevo, copiar con aritmética de punteros y liberar el antiguo)
- Método `void imprimir() const` — imprime el contenido en el formato `[v1 v2 ... vn]`
- Destructor que libera la memoria

**Restricciones:**

- Solo librerías `<iostream>` y `<stdexcept>`
- No usar `std::vector` ni ningún contenedor de STL en la implementación
- No usar el operador `[]` para acceder a `data` en ninguna parte de la clase
- Validar tamaños e índices con excepciones

### Ejemplo

```
main:
  ArregloEnteros a(5);
  a.set(0, 10); a.set(1, 20); a.set(2, 30); a.set(3, 40); a.set(4, 50);

  a.imprimir();        // [10 20 30 40 50]
  std::cout << "Suma: " << a.sumar() << std::endl;        // 150
  std::cout << "Prom: " << a.promedio() << std::endl;     // 30
  std::cout << "Max: " << a.maximo() << std::endl;        // 50
  std::cout << "Min: " << a.minimo() << std::endl;        // 10

  a.duplicar();  // tamano pasa de 5 a 10
  a.set(7, 99);
  a.imprimir();

Output:
  [10 20 30 40 50]
  Suma: 150
  Prom: 30
  Max: 50
  Min: 10
  [10 20 30 40 50 0 0 99 0 0]
```

---

## Ejercicio 2: STL — Procesamiento de Calificaciones

### Descripción

Usando **STL** (`std::vector` y `std::string`) resuelve el siguiente problema de procesamiento de notas de una asignatura.

Define la estructura:

```cpp
struct Estudiante {
    std::string nombre;
    int nota;  // 0 a 100
};
```

Implementa las siguientes funciones:

1. `std::string estudianteMaximaNota(const std::vector<Estudiante>& lista)`
   — devuelve el nombre del estudiante con la nota más alta (si hay empate, el primero que aparezca).

2. `double promedioGeneral(const std::vector<Estudiante>& lista)`
   — devuelve el promedio de las notas del grupo. Usa un acumulador con un bucle `for` y al final divide entre la cantidad de estudiantes. Devuelve `0.0` si la lista está vacía.

3. `std::vector<std::string> aprobados(const std::vector<Estudiante>& lista, int notaMinima)`
   — devuelve los nombres de los estudiantes con nota >= `notaMinima`, **ordenados por nota descendente**. El ordenamiento debe implementarse a mano con **bubble sort**, sin usar `std::sort` ni `<algorithm>`.

4. `bool existe(const std::vector<Estudiante>& lista, const std::string& nombre)`
   — indica si existe un estudiante con ese nombre (búsqueda lineal).

**Restricciones:**

- Solo librerías `<iostream>`, `<vector>` y `<string>`
- No usar la librería `<algorithm>` (`std::sort`, `std::max_element`, `std::any_of`, etc.)
- No modificar los vectores recibidos por referencia const

### Ejemplo

```
main:
  std::vector<Estudiante> lista = {
      {"Ana", 85}, {"Pedro", 45}, {"Maria", 92},
      {"Luis", 70}, {"Carmen", 45}
  };

  std::cout << std::boolalpha;
  std::cout << estudianteMaximaNota(lista) << std::endl;    // Maria
  std::cout << promedioGeneral(lista) << std::endl;         // 67.4
  std::vector<std::string> apro = aprobados(lista, 60);
  // apro = {"Maria", "Ana", "Luis"}
  std::cout << existe(lista, "Carmen") << std::endl;        // true
  std::cout << existe(lista, "Jorge") << std::endl;         // false

Output:
  Maria
  67.4
  true
  false
```

---

**Volver al [README del curso](../../Readme.md)**
