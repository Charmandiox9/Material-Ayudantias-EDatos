## 2. Clases, Objetos y Herencia

## Índice
- [2. Clases, Objetos y Herencia](#2-clases-objetos-y-herencia)
- [Índice](#índice)
  - [¿Qué es una clase?](#qué-es-una-clase)
  - [Modificadores de acceso](#modificadores-de-acceso)
  - [Herencia simple](#herencia-simple)
  - [`virtual` y `override`](#virtual-y-override)
  - [Herencia múltiple (solo C++)](#herencia-múltiple-solo-c)

---

### ¿Qué es una clase?
Una **clase** es una plantilla que define atributos (datos) y métodos (comportamiento).
Un **objeto** es una instancia concreta de esa clase.
```cpp
class Animal {
public:
    string nombre;
    int edad;

    void hablar() {
        cout << nombre << " hace un sonido" << endl;
    }
};

// Instanciar un objeto
Animal a;        // en el stack
a.nombre = "Rex";
a.hablar();

Animal* b = new Animal();  // en el heap (requiere delete)
b->nombre = "Luna";
b->hablar();
delete b;
```

> En Java los objetos **siempre** van en el heap (`new Animal()`).  
> En C++ puedes crearlos en el stack o en el heap, tú decides.

---

### Modificadores de acceso

| Modificador | Acceso desde la misma clase | Subclase | Cualquier clase |
|---|---|---|---|
| `public`    | ✅ | ✅ | ✅ |
| `protected` | ✅ | ✅ | ❌ |
| `private`   | ✅ | ❌ | ❌ |

> En Java existe además `package-private` (sin modificador). En C++ no hay equivalente directo.

---

### Herencia simple
```cpp
class Perro : public Animal {   // C++
    void hablar() override {
        cout << nombre << " dice: Guau!" << endl;
    }
};
```
```java
class Perro extends Animal {    // Java
    void hablar() {
        System.out.println(nombre + " dice: Guau!");
    }
}
```

**Diferencias clave:**

| | C++ | Java |
|---|---|---|
| Sintaxis | `: public Animal` | `extends Animal` |
| Especificar `override` | Opcional pero recomendado | No existe (se hace solo) |
| Métodos virtuales | Hay que declarar con `virtual` | Todos son virtuales por defecto |

---

### `virtual` y `override`

En C++, para que el polimorfismo funcione correctamente, el método en la clase base **debe** declararse `virtual`:
```cpp
class Animal {
public:
    virtual void hablar() {          // permite sobreescritura real
        cout << "..." << endl;
    }
    virtual ~Animal() {}             // destructor virtual: siempre en clases base
};

class Perro : public Animal {
public:
    void hablar() override {         // override avisa al compilador si hay error
        cout << "Guau!" << endl;
    }
};

Animal* a = new Perro();
a->hablar();   // ✅ imprime "Guau!" (polimorfismo)
```

> Sin `virtual`, `a->hablar()` llamaría al método de `Animal`, no de `Perro`.  
> En Java esto no ocurre: todos los métodos son virtuales por defecto.

---

### Herencia múltiple (solo C++)

C++ permite heredar de más de una clase. Java **no lo permite** (solo permite múltiples interfaces).
```cpp
class Volador {
public:
    virtual void volar() { cout << "Volando..." << endl; }
};

class Nadador {
public:
    virtual void nadar() { cout << "Nadando..." << endl; }
};

class Pato : public Volador, public Nadador {
    // hereda volar() y nadar()
};
```

⚠️ Si dos clases base tienen un método con el mismo nombre, el compilador lanza ambigüedad y hay que resolverla explícitamente:
```cpp
class Pato : public Volador, public Nadador {
public:
    void accion() {
        Volador::volar();   // indicar explícitamente cuál usar
    }
};
```