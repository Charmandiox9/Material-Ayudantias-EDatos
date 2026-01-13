# Tutoría 2: Stacks y Queues
**Asignatura:** Estructuras de Datos  
**Tema:** Stacks (Pilas) y Queues (Colas)  
**Enfoque:** Lógica de Negocio y Simulación de Procesos

---

## Objetivos de la Sesión
1.  Modelar restricciones físicas y temporales.
2.  Gestionar el flujo de datos entre múltiples estructuras auxiliares.

---

## Ejercicio 1: Ingeniería de Software (El Navegador Web)
**Estructura:** Doble Stack (`stack`)

### Contexto
Estás desarrollando el núcleo del nuevo navegador "Chrome++". Los usuarios reportan que el comportamiento de los botones **Atrás** (`<-`) y **Adelante** (`->`) es inconsistente. Tu tarea es implementar la lógica exacta de navegación.

### Requerimientos Lógicos
Debes implementar una clase `Navegador` que gestione:
1.  **Pagina Actual:** Un string con la URL donde está el usuario.
2.  **Historial Atras:** Una Pila con las páginas visitadas anteriormente.
3.  **Historial Adelante:** Una Pila con las páginas que el usuario "deshizo" al volver atrás.

### Reglas de Negocio (Crítico)
* **Visitar(url):** Al entrar a un sitio nuevo, la página actual pasa al historial *Atras*. **Importante:** El historial *Adelante* debe vaciarse (se pierde el futuro al cambiar la línea temporal).
* **Atras():** La actual pasa a *Adelante*. Se recupera la última de *Atras*.
* **Adelante():** La actual pasa a *Atras*. Se recupera la última de *Adelante*.

---

## Ejercicio 2: Sistemas Operativos (Round Robin CPU)
**Estructura:** Queue (`queue`)

### Contexto
Tienes un procesador (CPU) single-core que debe ejecutar múltiples tareas simultáneamente. Para ser justo, el procesador usa un algoritmo Round Robin: le da a cada tarea un pequeño tiempo de ejecución (Quantum) y si no termina, la manda al final de la fila.

### Requerimientos Lógicos
Implementa una función `simularCPU(cola, quantum` que:
1. Saque la primera tarea de la cola.
2. Simule su ejecución.
   - Si la tarea necesita menos o igual tiempo que el Quantum: La tarea termina y sale del sistema.
   - Si la tarea necesita más tiempo que el Quantum: Se ejecuta por el tiempo del Quantum, se le resta ese tiempo, y vuelve a formarse al final de la cola.
3. Repita hasta que no queden tareas.

**Estructura de Datos sugerida:**
```
struct Tarea {
    string nombre;
    int tiempoRestante; // Ej: 100ms
};
// El Quantum será de 20ms
```

---

## Desafío 3: Logística (El Estacionamiento "Callejón")
Estructura: Stack

### Contexto
Un estacionamiento en el centro de la ciudad es muy estrecho; solo cabe un auto de ancho. Esto lo convierte en una estructura LIFO (Last In, First Out). Tienes una fila de autos: `[FONDO] BMW -> Fiat -> Audi -> Kia [SALIDA]`

El dueño del **Fiat** (que está atrapado en el medio) llega a retirar su auto.

### Requerimientos Lógicos
Implementa la función `retirarAuto(estacionamiento, patente)`:

1. No puedes acceder a los elementos del medio aleatoriamente.
2. Debes sacar los autos que estorban (Kia, Audi) y moverlos a una estructura temporal (La "Calle").
3. Cuando encuentres el Fiat, entrégalo (sácalo del sistema).
4. Crucial: Debes regresar los autos de la "Calle" al estacionamiento de tal forma que mantengan su orden original relativo.

