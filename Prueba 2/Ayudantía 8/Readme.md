# 🔗 Ayudantía 8: Árboles AVL

## 📝 Ejercicio 1: Rotaciones Simples (LL y RR)

### 🎯 Descripción
Dado un conjunto de números, construya un Árbol AVL insertando los elementos uno por uno.
Observe los casos donde el árbol se desbalancea y se requiere una rotación simple (LL o RR) para equilibrarlo.

### 💡 Ejemplo
```
📥 Input: [30, 20, 10]
```

---

## 📝 Ejercicio 2: Rotaciones Dobles (LR y RL)

### 🎯 Descripción
Inserte los elementos en el orden dado y observe los casos donde se requiere una rotación doble (LR o RL).
Muestre los pasos y el árbol antes y después de la rotación.

### 💡 Ejemplo
```
📥 Input: [50, 30, 40]
```

---

## 📝 Ejercicio 3: Construcción de Árbol AVL Completo

### 🎯 Descripción
Dado un arreglo de enteros, construya un Árbol Binario de Búsqueda Balanceado (AVL) insertando los elementos uno por uno.
Después de cada inserción, calcule los factores de equilibrio y aplique las rotaciones necesarias.

### 💡 Ejemplo
```
📥 Input: [10, 20, 30, 25, 5, 35, 40, 15, 38]
```

---

## 📝 Ejercicio 4: Inserciones y Eliminaciones

### 🎯 Descripción
Construya un Árbol AVL insertando y luego eliminando elementos.
Después de cada operación, muestre el árbol y los reequilibrios que ocurran.

### 💡 Ejemplo
```
📥 Input: [10, 20, 30, 25, 5, 35, 40, 15, 38]
Números a eliminar: [10, 35, 20]
```

---

## 📝 Ejercicio 5: Desafío (Mixto)

### 🎯 Descripción
Inserte los números y realice las rotaciones necesarias para mantener el árbol AVL balanceado.
Después, elimine algunos nodos y reequilibre el árbol.
Dibuje el resultado final y anote las rotaciones realizadas.

### 💡 Ejemplo
```
📥 Input: [50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45]
Eliminar: [20, 35, 70]

✅ Árbol final balanceado:
         40
        /  \
      25    60
     / \    / \
   10  30  50  80
```