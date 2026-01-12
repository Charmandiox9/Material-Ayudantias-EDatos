# 🔗 Ayudantía: Grafos y Representaciones

## 📝 Ejercicio 1: Teoría de Grafos

### ✅ Respuestas:

**1. Vértices y aristas:**
- **Vértices:** 6 (numerados del 0 al 5)
- **Aristas:** 7 aristas dirigidas

**3. Ciclos:**
Sí, existe al menos un ciclo:
- **Ciclo 1:** 0 → 1 → 4 (no es ciclo, 4 no tiene salida)
- **No hay ciclos** en este grafo porque el vértice 4 es un sumidero (no tiene aristas salientes)

**4. Recorrido BFS desde vértice 0:**
```
Orden de visita: 0 → 1 → 3 → 2 → 4 → 5

Explicación:
- Nivel 0: [0]
- Nivel 1: [1, 3] (vecinos de 0)
- Nivel 2: [2, 4] (vecinos de 1 y 3)
- Nivel 3: [5] (vecino de 2)
```

**5. Recorrido DFS desde vértice 0:**
```
Orden de visita: 0 → 1 → 2 → 5 → 4 → 3

Explicación (siguiendo siempre el primer vecino disponible):
0 → 1 (primer vecino de 0)
1 → 2 (primer vecino de 1)
2 → 5 (primer vecino de 2)
5 → 4 (primer vecino de 5)
Retroceso a 1 → 4 (ya visitado)
Retroceso a 0 → 3 (segundo vecino de 0)
3 → 4 (ya visitado)
```

---

## 📝 Ejercicio 2: Análisis de Representaciones de Grafos

### ✅ Respuestas:

**Parte 1: Análisis de la Matriz**

**Cantidad de amistades por usuario:**
- **Usuario 0:** 3 amigos [1, 2, 4]
- **Usuario 1:** 3 amigos [0, 2, 3]
- **Usuario 2:** 4 amigos [0, 1, 4, 5]
- **Usuario 3:** 3 amigos [1, 4, 5]
- **Usuario 4:** 4 amigos [0, 2, 3, 5]
- **Usuario 5:** 3 amigos [2, 3, 4]

**Usuario más popular:** Usuario 2 y Usuario 4 (empate con 4 amigos cada uno)

**Usuario menos popular:** Usuarios 0, 1, 3, y 5 (empate con 3 amigos cada uno)

**Memoria de la matriz:**
```
Memoria = n × n × tamaño_de_int
Memoria = 6 × 6 × 4 bytes = 144 bytes
```

**Parte 2: Lista de Adyacencia**

**Lista de Adyacencia:**
```
0: [1, 2, 4]
1: [0, 2, 3]
2: [0, 1, 4, 5]
3: [1, 4, 5]
4: [0, 2, 3, 5]
5: [2, 3, 4]
```

**Cálculo de memoria de la lista:**
```
Componentes:
- 6 vectores (punteros): 6 × 8 bytes = 48 bytes
- Total de conexiones almacenadas: 3 + 3 + 4 + 3 + 4 + 3 = 20 enteros
- Enteros: 20 × 4 bytes = 80 bytes

Total: 48 + 80 = 128 bytes
```

**Comparación:**
- Matriz: 144 bytes
- Lista: 128 bytes
- **Ahorro: 16 bytes (11.1%)**

**Conclusión:** Para este grafo, la lista de adyacencia es más eficiente. La diferencia sería más significativa en grafos más grandes y dispersos.

**Parte 3: Operaciones sobre el grafo**

**1. Amigos en común entre usuarios 0 y 3:**

Amigos de 0: [1, 2, 4]
Amigos de 3: [1, 4, 5]

**Amigos en común: [1, 4]** (2 amigos en común)

**2. ¿Existe camino entre usuario 0 y usuario 5?**

**Sí, existen varios caminos:**
- 0 → 2 → 5 (longitud 2)
- 0 → 4 → 5 (longitud 2)
- 0 → 1 → 3 → 5 (longitud 3)
- 0 → 2 → 4 → 5 (longitud 3)

**3. Cadena más corta de 1 a 5:**

**Camino más corto: 1 → 2 → 5** (longitud 2)

Explicación usando BFS desde 1:
```
Nivel 0: [1]
Nivel 1: [0, 2, 3] (vecinos de 1)
Nivel 2: [4, 5] (nuevos vecinos desde nivel 1)
         - Desde 2: llegamos a 5 ✓
```

Caminos alternativos de igual longitud:
- 1 → 3 → 5 (longitud 2)

---

## 📝 Ejercicio 3: Implementación Completa de Conversión y Operaciones

```cpp
#include <iostream>
#include <vector>
using namespace std;

// ================= CONVERSIONES =================

vector<vector<int>> matrizToLista(vector<vector<int>>& matriz) {
    int n = matriz.size();
    vector<vector<int>> lista(n);
    
    // Recorrer cada celda de la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Si existe una arista, agregar a la lista
            if (matriz[i][j] == 1) {
                lista[i].push_back(j);
            }
        }
    }
    
    return lista;
}

vector<vector<int>> listaToMatriz(vector<vector<int>>& lista, int n) {
    // Crear matriz de n×n llena de ceros
    vector<vector<int>> matriz(n, vector<int>(n, 0));
    
    // Llenar la matriz según las conexiones de la lista
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < lista[i].size(); j++) {
            int vecino = lista[i][j];
            matriz[i][vecino] = 1;
        }
    }
    
    return matriz;
}
```