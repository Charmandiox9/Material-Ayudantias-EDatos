# Tutoría 3: Grafos

**Asignatura:** Estructuras de Datos  
**Tema:** Grafos
**Enfoque:** Estás programando el sistema de navegación de un videojuego de mundo abierto.

---

## Objetivos de la Sesión 
1. Comprender la diferencia entre buscar por "cercanía" (BFS) y buscar por "costo" (Dijkstra).

---

## Ejercicio 1: Lógica y Trazado
**Objetivo:** Entender el orden de exploración.

**El Mapa:**
Dibuja el siguiente grafo dirigido en tu cuaderno:
* **Nodos:** Inicio(0), A(1), B(2), C(3), Fin(4).
* **Conexiones:**
    * 0 -> 1
    * 0 -> 2
    * 1 -> 3
    * 2 -> 4
    * 3 -> 4

**Tu Tarea:**
1.  Realiza una **Traza de Escritorio** (paso a paso a mano) de un algoritmo **BFS** (Búsqueda en Anchura) comenzando en el nodo `0`.
2.  Dibuja la **Cola (Queue)** en cada paso: ¿Qué nodos entran y en qué orden salen?
3.  ¿Cuál es la ruta que descubre BFS primero para llegar al `Fin`(4)?

---

## Ejercicio 2: La Fuga (BFS - Ruta más Corta)
**Objetivo:** Encontrar el camino con menos intersecciones (saltos). Ignora el tráfico o distancia.

**Enunciado:**
Implementa la función `rutaEscape` que reciba un grafo (sin pesos) y retorne el vector con la secuencia de nodos para escapar.

**Firma de la función:**
```cpp

// Recibe:
// - n: número de nodos
// - adj: Lista de adyacencia (adj[0] = {1, 2} significa que 0 conecta con 1 y 2)
// Retorna: Vector con el camino (Ej: {0, 2, 4})
vector<int> rutaEscape(int n, vector<vector<int>>& adj, int inicio, int fin) {
    // TODO:
    // 1. Usar queue<int> para BFS.
    // 2. Usar vector<int> padre(n, -1) para recordar de dónde vinimos.
    // 3. Al encontrar 'fin', reconstruir el camino hacia atrás usando 'padre'.
    
    vector<int> ruta;
    return ruta; // Retornar vacío si no hay camino
}
```
