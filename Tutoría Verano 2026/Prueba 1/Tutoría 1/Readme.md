# Tutoría: Listas Enlazadas

**Tema:** Manipulación de Punteros, Inversión y Fusión  
**Duración:** 90 Minutos  
**Objetivo:** Perder el miedo a los punteros y manipular listas sin romper la memoria.

---

## Instrucciones de Inicio

1. Abre el archivo `main.cpp` en tu IDE.
2. Compila y ejecuta para verificar que el entorno funciona.
3. Verás que la salida actual es incorrecta o está vacía. Tu misión es arreglarlo función por función.

---

## Ejercicio 1: El Detective (Debugging)
En el archivo `ejercicio1.cpp` encontrarás la función `eliminarUltimo()`.
Actualmente, esta función provoca un **Segmentation Fault** o deja basura en memoria bajo ciertas condiciones.

**Tu tarea:**
1. Lee el código (¡No lo ejecutes aún!).
2. Encuentra el error lógico: ¿Qué pasa si la lista tiene solo 1 nodo? ¿Qué pasa con el puntero `anterior`?
3. Corrige el código para que maneje los casos borde.

---

## Ejercicio 2: Inversión "In-Place"
**Misión:** Implementar la función `invertirLista(Nodo*& cabeza)`.
**Restricción:** PROHIBIDO crear nodos nuevos (`new`). Debes reutilizar los nodos existentes cambiando la dirección de sus flechas.

**Algoritmo sugerido:**
Necesitas tres punteros auxiliares:
- `prev` (inicialmente `nullptr`)
- `curr` (inicialmente `cabeza`)
- `next` (para no perder el resto de la lista)


---

## Ejercicio 3: Fusión de Listas
**Misión:** Tienes dos listas ordenadas (`L1` y `L2`). Únelas en una sola lista ordenada llamada `ListaFusionada`.
**Restricción:** Complejidad O(N). No uses doble bucle.
