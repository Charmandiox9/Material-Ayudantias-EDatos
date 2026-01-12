# 🔗 Ayudantía 9: Árboles AVL

## 📝 Ejercicio 1: Secuencia Ascendente

### 🎯 Descripción
Construya un Árbol AVL insertando elementos en orden ascendente.
Este caso es crítico porque genera desbalances consecutivos hacia la derecha (RR).
Muestre cada rotación necesaria y el factor de equilibrio de cada nodo después de cada inserción.

### 💡 Ejemplo
```
📥 Input: [5, 10, 15, 20, 25, 30, 35]
```

---

## 📝 Ejercicio 2: Secuencia Descendente

### 🎯 Descripción
Inserte los elementos en orden descendente en un Árbol AVL.
Este escenario genera desbalances consecutivos hacia la izquierda (LL).
Identifique todos los puntos donde se requiere rotación y muestre el árbol resultante después de cada rebalanceo.

### 💡 Ejemplo
```
📥 Input: [80, 70, 60, 50, 40, 30, 20]
```

---

## 📝 Ejercicio 3: Patrón Zigzag

### 🎯 Descripción
Construya un Árbol AVL con una secuencia que alterna entre valores grandes y pequeños.
Este patrón genera múltiples rotaciones dobles (LR y RL).
Dibuje el árbol después de cada inserción crítica y especifique el tipo de rotación aplicada.

### 💡 Ejemplo
```
📥 Input: [50, 25, 75, 10, 60, 90, 5, 70]
```

---

## 📝 Ejercicio 4: Eliminación con Rebalanceo en Cascada

### 🎯 Descripción
Construya un Árbol AVL con los elementos dados y luego elimine nodos específicos.
La eliminación puede causar rebalanceos en cascada (múltiples rotaciones en diferentes niveles).
Muestre el árbol después de cada eliminación y todas las rotaciones necesarias.

### 💡 Ejemplo
```
📥 Input: [50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 35, 55, 65, 77, 85]
Números a eliminar: [10, 30, 60]
```

---

## 📝 Ejercicio 5: Rango de Eliminación

### 🎯 Descripción
Construya un Árbol AVL con los elementos dados.
Luego, elimine todos los nodos cuyo valor esté dentro de un rango específico [a, b].
Muestre el árbol después de cada eliminación y los rebalanceos en cascada.

### 💡 Ejemplo
```
📥 Input: [50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 90]
Eliminar rango: [35, 65]
```

---

## 📝 Ejercicio 6: Desafío Extra (Operaciones Mixtas)

### 🎯 Descripción
Realice una secuencia compleja de operaciones: inserciones y eliminaciones.
Mantenga el árbol balanceado en todo momento y registre cada rotación realizada.
Al final, calcule la altura del árbol y verifique que cumple la propiedad AVL.

### 💡 Ejemplo
```
📥 Operaciones:
1. Insertar: [45, 25, 65, 15, 35, 55, 75, 10, 30, 50, 60, 70, 80]
2. Eliminar: [15, 65]
3. Insertar: [5, 20, 40]
4. Eliminar: [25, 75]
5. Insertar: [85, 12]

✅ Resultado:
- Total de rotaciones: ___
- Altura final: ___
- Factor de equilibrio de la raíz: ___
```


---

---

## 🔧 Herramientas de Apoyo

### Visualizador Interactivo de Árboles AVL
Para verificar paso a paso las inserciones, eliminaciones y rotaciones, pueden utilizar:

**🔗 AVL Tree Visualization**  
https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

Esta herramienta permite:
- Insertar y eliminar nodos uno por uno
- Visualizar las rotaciones en tiempo real
- Verificar los factores de equilibrio de cada nodo
- Comparar sus resultados con la solución correcta