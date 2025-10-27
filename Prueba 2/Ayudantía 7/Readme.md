# 🔗 Ayudantía 6: Heapsort

## 📝 Ejercicio 1: MaxHeap

### 🎯 Descripción
Dado un arreglo de enteros, la tarea es ordenarlo utilizando el algoritmo Heapsort (Max Heap), mostrando el paso a paso.

### 💡 Ejemplo
```
📥 Input: [47, 46, 21, 44, 30, 10, 24, 7, 42, 34]

📤 Output: 

H1: 47, 46, 21, 44, 30, 10, 24
H2: 47, 46, 21, 44, 30, 10, 21, 7, 42, 34
H3: 47, 46, 24, 44, 34, 10, 21, 7, 42, 30

1. [30, 46, 24, 44, 34, 10, 21, 7, 42| 47]
 H1: [46, 30, 24, 44, 34, 10, 21, 7, 42| 47]
 H2: [46, 44, 24, 30, 34, 10, 21, 7, 42| 47]
 H3: [46, 44, 24, 42, 34, 10, 21, 7, 30| 47]
2. [30, 44, 24, 42, 34, 10, 21, 7| 46, 47]
 H1: [44, 30, 24, 42, 34, 10, 21, 7| 46, 47]
 .
 .
 .
X. [7, 10, 21, 24, 30, 34, 42, 44, 46, 47]
```

---

## 📝 Ejercicio 2: MinHeap

### 🎯 Descripción
Dado un arreglo de enteros, la tarea es ordenarlo utilizando el algoritmo Heapsort (Min Heap), mostrando el paso a paso.

### 💡 Ejemplo
```
📥 Input: [12, 4, 19, 8, 5, 21, 7]

📤 Output: 

H1: 12, 4
H2: 4, 12, 19, 8
.
.

1. [19, 5, 7, 12, 8, 21| 4]
 H1: [5, 19, 7, 12, 8, 21| 4]
 .
 .
 .
X. [21, 19, 12, 8, 7, 5, 4]
```