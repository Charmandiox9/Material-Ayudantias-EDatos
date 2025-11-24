# 🔗 Ayudantía: Grafos y Representaciones

## 📝 Ejercicio 1: Teoría de Grafos

### 🎯 Descripción
Dado el siguiente grafo dirigido, responda:

1. ¿Cuántos vértices y aristas tiene el grafo?
2. ¿Cuál es el grado de entrada y salida de cada vértice?
3. ¿Existe algún ciclo en el grafo? Si es así, indique uno.
4. Realice un recorrido **BFS** (Breadth-First Search) desde el vértice 0
5. Realice un recorrido **DFS** (Depth-First Search) desde el vértice 0

### 💡 Ejemplo
```
Grafo dirigido:

    0 -----> 1 -----> 2
    |        |        |
    v        v        v
    3 -----> 4 <----- 5
    
Aristas:
0 -> 1
0 -> 3
1 -> 2
1 -> 4
2 -> 5
3 -> 4
5 -> 4
```

---

## 📝 Ejercicio 2: Análisis de Representaciones de Grafos

### 🎯 Descripción
Una red social quiere optimizar su sistema de almacenamiento de conexiones entre usuarios. Actualmente utilizan una **matriz de adyacencia** para representar las amistades, pero están considerando cambiar a una **lista de adyacencia**.

Se te proporciona información de 6 usuarios y sus conexiones. Debes:

1. **Analizar la matriz de adyacencia** proporcionada y determinar:
   - ¿Cuántas amistades tiene cada usuario?
   - ¿Cuál es el usuario más popular (más conexiones)?
   - ¿Cuál es el usuario menos popular?
   - ¿Cuánta memoria ocupa la matriz? (cada elemento ocupa 4 bytes)

2. **Convertir a lista de adyacencia** y calcular:
   - ¿Cuánta memoria ocuparía la lista? (cada puntero ocupa 8 bytes, cada entero 4 bytes)

3. **Operaciones sobre el grafo:**
   - ¿Cuántos amigos en común tienen los usuarios 0 y 3?
   - ¿Existe un camino de amistad entre el usuario 0 y el usuario 5? (amigos de amigos)
   - Si el usuario 1 quiere enviar un mensaje al usuario 5 a través de amigos, ¿cuál es la cadena más corta?

### 💡 Ejemplo

**Contexto:** Red social con 6 usuarios (numerados del 0 al 5)

**Matriz de Adyacencia:**
```
      0  1  2  3  4  5
0 [   0  1  1  0  1  0  ]
1 [   1  0  1  1  0  0  ]
2 [   1  1  0  0  1  1  ]
3 [   0  1  0  0  1  1  ]
4 [   1  0  1  1  0  1  ]
5 [   0  0  1  1  1  0  ]
```

**Visualización del Grafo:**

![Grafo](https://imgur.com/a/Pe19tjk)

**Información adicional:**
- Grafo **no dirigido** (amistad es bidireccional)
- Si `matriz[i][j] = 1`, entonces el usuario `i` y el usuario `j` son amigos
- La diagonal principal siempre es 0 (un usuario no es amigo de sí mismo)

---

## 📝 Ejercicio 3: Implementación de Conversiones

### 🎯 Descripción
Implementar dos funciones que conviertan entre las dos representaciones de grafos:

1. **`matrizToLista()`**: Convertir matriz de adyacencia a lista de adyacencia
2. **`listaToMatriz()`**: Convertir lista de adyacencia a matriz de adyacencia

Ambas funciones deben funcionar para grafos no dirigidos.

### 💡 Ejemplos de Uso

**Ejemplo 1: Conversión Matriz → Lista**
```cpp
📥 Input: 
matriz = [
    [0, 1, 1, 0],
    [1, 0, 0, 1],
    [1, 0, 0, 1],
    [0, 1, 1, 0]
]

📤 Output (lista):
[
    [1, 2],      // Vértice 0 conectado a 1 y 2
    [0, 3],      // Vértice 1 conectado a 0 y 3
    [0, 3],      // Vértice 2 conectado a 0 y 3
    [1, 2]       // Vértice 3 conectado a 1 y 2
]
```

**Ejemplo 2: Conversión Lista → Matriz**
```cpp
📥 Input: 
lista = [
    [1, 2],
    [0, 2],
    [0, 1, 3],
    [2]
]
n = 4

📤 Output (matriz):
[
    [0, 1, 1, 0],
    [1, 0, 1, 0],
    [1, 1, 0, 1],
    [0, 0, 1, 0]
]
```

**Restricciones:**
- `1 <= n <= 1000` (número de vértices)
- Grafo no dirigido (matriz simétrica)
- `matriz[i][j] ∈ {0, 1}`
- No hay aristas múltiples ni lazos (auto-conexiones)

**Hints:**
- Para `matrizToLista()`: Recorrer la matriz y agregar vecinos
- Para `listaToMatriz()`: Crear matriz de ceros y llenar con unos donde hay aristas
