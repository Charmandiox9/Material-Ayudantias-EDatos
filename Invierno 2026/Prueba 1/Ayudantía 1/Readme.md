# Ayudantía 1: Punteros, POO y Herencia

## Ejercicio 1: Punteros Básicos — Estructura Dinámica

### Descripción

Implementa una estructura `Alumno` con los siguientes campos:

- `nombre` — un `char*` con el nombre del alumno
- `edad` — un `int` con la edad
- `promedio` — un `double` con el promedio

Debes crear funciones que manipulen esta estructura usando **punteros**:

1. `crearAlumno(const char* nombre, int edad, double promedio)` — crea un alumno dinámicamente (incluyendo copia del nombre con `new[]`)
2. `mostrarAlumno(Alumno* alumno)` — imprime los datos del alumno
3. `eliminarAlumno(Alumno* alumno)` — libera la memoria correctamente

**Restricciones:**

- Solo librerías `<iostream>` y `<cstring>`
- No usar `string`, `unique_ptr` ni otros gestores
- Validar que el puntero no sea `nullptr` antes de usarlo
- Liberar TODA la memoria asignada dinámicamente

### Ejemplo

```
main:
  Alumno* a1 = crearAlumno("Ana", 20, 8.5);
  Alumno* a2 = crearAlumno("Carlos", 22, 7.3);

  mostrarAlumno(a1);
  mostrarAlumno(a2);

  eliminarAlumno(a1);
  eliminarAlumno(a2);

Output:
  Nombre: Ana, Edad: 20, Promedio: 8.50
  Nombre: Carlos, Edad: 22, Promedio: 7.30
```

---

## Ejercicio 2: Jerarquía de Figuras con Herencia

### Descripción

Implementa una jerarquía de clases de figuras geométricas usando herencia:

- Clase base abstracta `Figura` con métodos:
  - `double area() const = 0`
  - `double perimeter() const = 0`
  - `virtual void printInfo() const` — imprime nombre y propiedades

- Clase `Rectangulo` (hereda de Figura):
  - Atributos: `double ancho`, `double alto`
  - Constructor con validación (ancho y alto > 0)

- Clase `Circulo` (hereda de Figura):
  - Atributo: `double radio`
  - Constructor con validación (radio > 0)

- Clase `Triangulo` (hereda de Figura):
  - Atributos: `double lado1`, `lado2`, `lado3`
  - Constructor con validación (debe formar triángulo válido: suma de dos lados > tercer lado)

**Restricciones:**

- Solo librerías `<iostream>` y `<iomanip>`
- Usar punteros base `Figura*` para manejar polimorfismo
- No usar `vector` ni contenedores

### Ejemplo

```
main:
  Figura* f1 = new Rectangulo(5.0, 3.0);
  Figura* f2 = new Circulo(7.0);
  Figura* f3 = new Triangulo(3.0, 4.0, 5.0);

  for (auto* f : {f1, f2, f3}) {
      f->printInfo();
      delete f;
  }

Output:
  Rectangulo: 5.00 x 3.00 | Area: 15.00 | Perimetro: 16.00
  Circulo: r=7.00 | Area: 153.94 | Perimetro: 43.98
  Triangulo: 3.00 x 4.00 x 5.00 | Area: 6.00 | Perimetro: 12.00
```

---

**Volver al [README del curso](../../Readme.md)**
