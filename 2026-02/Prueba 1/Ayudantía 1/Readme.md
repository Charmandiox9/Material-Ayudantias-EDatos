# Ayudantía 1: Punteros, POO y Herencia

## Ejercicio 1: Punteros y Memoria Dinámica — Lista de Empleados

### Descripción

Implementa una estructura `Empleado` con los siguientes campos:

- `nombre` — un `char*` con el nombre del empleado
- `rut` — un `char*` con el RUT (formato: "12345678-9")
- `sueldo` — un `double` con el sueldo mensual

Debes implementar las siguientes funciones que trabajan con **punteros**:

1. `crearEmpleado(const char* nombre, const char* rut, double sueldo)` — crea un empleado dinámicamente (con copias de los strings mediante `new[]`)
2. `crearListaEmpleados(int n)` — crea un arreglo dinámico de `n` punteros a `Empleado`, inicializados en `nullptr`
3. `mostrarEmpleado(Empleado* e)` — imprime los datos del empleado
4. `eliminarEmpleado(Empleado* e)` — libera la memoria del empleado (incluyendo los strings)
5. `eliminarLista(Empleado** lista, int n)` — elimina la memoria de los empleados no nulos y del arreglo de punteros

**Restricciones:**

- Solo librerías `<iostream>` y `<cstring>`
- No usar `std::string`, `std::vector` ni `std::unique_ptr`
- Validar punteros `nullptr` antes de usarlos
- No debe quedar ninguna memoria sin liberar

### Ejemplo

```
main:
  Empleado** lista = crearListaEmpleados(3);
  lista[0] = crearEmpleado("Ana", "12345678-9", 650000.0);
  lista[1] = crearEmpleado("Pedro", "98765432-1", 820000.5);
  lista[2] = nullptr;

  for (int i = 0; i < 3; i++) {
      if (lista[i] != nullptr) mostrarEmpleado(lista[i]);
  }

  eliminarLista(lista, 3);

Output:
  Nombre: Ana, RUT: 12345678-9, Sueldo: 650000.00
  Nombre: Pedro, RUT: 98765432-1, Sueldo: 820000.50
```

---

## Ejercicio 2: Herencia — Cálculo de Sueldos

### Descripción

Implementa una jerarquía de clases para el cálculo de sueldos de una empresa usando **herencia y polimorfismo**:

- Clase base abstracta `Empleado`:
  - Atributos protegidos: `char* nombre`, `int rut`
  - Constructor que recibe nombre y rut (copiando el nombre con `new[]`)
  - Método virtual puro: `double calcularSueldo() const = 0`
  - Método virtual: `virtual void mostrar() const` — imprime nombre, rut y sueldo
  - Destructor virtual

- Clase `EmpleadoJornalero` (hereda de Empleado):
  - Atributos: `double valorDia`, `int diasTrabajados`
  - Sueldo = `valorDia * diasTrabajados`

- Clase `EmpleadoComision` (hereda de Empleado):
  - Atributos: `double sueldoBase`, `double porcentajeComision` (ej: 0.10 = 10%), `double ventas`
  - Sueldo = `sueldoBase + (ventas * porcentajeComision)`

- Clase `EmpleadoGerente` (hereda de Empleado):
  - Atributo: `double sueldoMensual`
  - Sueldo = `sueldoMensual + 100000.0` (bono fijo)

**Restricciones:**

- Solo librerías `<iostream>` y `<iomanip>`
- Procesar los empleados a través de punteros base `Empleado*` (polimorfismo)
- No usar `std::vector` ni contenedores
- Cada clase hija debe reimplementar `mostrar()` mostrando además sus datos propios

### Ejemplo

```
main:
  Empleado** empleados = new Empleado*[3];
  empleados[0] = new EmpleadoJornalero("Juan", 11111111, 30000.0, 25);
  empleados[1] = new EmpleadoComision("Maria", 22222222, 400000.0, 0.10, 2500000.0);
  empleados[2] = new EmpleadoGerente("Luis", 33333333, 1500000.0);

  for (int i = 0; i < 3; i++) {
      empleados[i]->mostrar();
      delete empleados[i];
  }
  delete[] empleados;

Output:
  [Jornalero] Juan (11111111): valorDia=30000.00, dias=25 | Sueldo: 750000.00
  [Comision] Maria (22222222): base=400000.00, comision=10.00%, ventas=2500000.00 | Sueldo: 650000.00
  [Gerente] Luis (33333333): mensual=1500000.00 | Sueldo: 1600000.00
```

---

**Volver al [README del curso](../../Readme.md)**
