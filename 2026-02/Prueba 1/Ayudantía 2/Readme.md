# Ayudantía 2: POO Avanzada y Herencia

## Ejercicio 1: Herencia, Polimorfismo y Punteros — Cuentas Bancarias

### Descripción

Implementa una jerarquía de clases para cuentas bancarias usando **herencia, polimorfismo y punteros**.

- Clase base **abstracta** `Cuenta`:
  - Atributos protegidos: `string titular`, `double saldo`
  - Constructor `Cuenta(const string& titular, double saldo)`
  - Destructor virtual
  - `double getSaldo() const` — devuelve el saldo
  - `void depositar(double monto)` — suma `monto` al saldo (valida `monto > 0`)
  - `virtual void retirar(double monto)` — versión por defecto: solo si `monto <= saldo`, lanza `runtime_error` en caso contrario
  - `virtual double calcularInteres() const = 0` — **método puro**, cada cuenta lo define
  - `virtual void mostrar() const` — imprime titular, saldo e interés

- Clase `CuentaCorriente` (hereda de `Cuenta`):
  - Atributo privado: `double topeDescubierto`
  - Constructor adicional que recibe el tope de descubrimiento
  - **Redefine** `retirar()`: permite saldo negativo hasta el tope de descubrimiento
  - `calcularInteres()` devuelve `0.0`

- Clase `CuentaAhorro` (hereda de `Cuenta`):
  - Usa la `retirar()` por defecto de la base (sin descubrimiento)
  - `calcularInteres()` devuelve `0.02 * saldo` (2%)

- Función libre `double saldoTotal(Cuenta** cuentas, int n)`:
  — recibe un **arreglo de punteros** a cuentas y devuelve la suma de todos los saldos, accediendo con punteros y polimorfismo.

**Restricciones:**

- Solo librerías `<iostream>`, `<iomanip>`, `<string>` y `<stdexcept>`
- Usar `override` en los métodos redefinidos
- En `main`, crear un **arreglo dinámico de punteros** `Cuenta**` (con `new[]`) para las cuentas, procesarlas (depósito y `mostrar`), imprimir el saldo total y **liberar toda la memoria** (cada cuenta y el arreglo)
- Procesar las cuentas a través de punteros base `Cuenta*` (polimorfismo)

### Ejemplo

```
main:
  Cuenta** cuentas = new Cuenta*[2];
  int n = 2;
  cuentas[0] = new CuentaCorriente("Ana", 1000.0, 500.0);
  cuentas[1] = new CuentaAhorro("Pedro", 2000.0);

  for (int i = 0; i < n; i++) {
      cuentas[i]->depositar(100.0);
      cuentas[i]->mostrar();
  }

  cout << "Saldo total: " << saldoTotal(cuentas, n) << endl;

  for (int i = 0; i < n; i++) delete cuentas[i];
  delete[] cuentas;

Output:
  Ana: saldo=1100.00, interes=0.00
  Pedro: saldo=2100.00, interes=42.00
  Saldo total: 3200.00
```

---

**Volver al [README del curso](../../Readme.md)**
