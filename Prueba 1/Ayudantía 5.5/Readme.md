# 🔗 Ayudantía 5.5: Listas Enlazadas (Tipo prueba)

## 📝 Ejercicio 1: Suma de listas

### 🎯 Descripción
Se te da dos números representados como listas enlazadas, donde cada nodo contiene un solo dígito. Los dígitos están almacenados en orden inverso, de manera que las unidades están en el primer nodo. Escribe un programa para sumar estos dos números y devolver el resultado
como una lista enlazada.

### 💡 Ejemplo
```
📥 Input:  
Lista 1: 2 -> 4 -> 3 (Representa 342)
Lista 2: 5 -> 6 -> 4 (Representa 465)

📤 Output: Resultado: 7 -> 0 -> 8 (Representa 807)
```

---


## 📝 Ejercicio 2: Rotar una Lista Enlazada en rango en subgrupos

### 🎯 Descripción
Dada una lista enlazada, y dos índices **m** y **n**, y un entero **k** que define los subgrupos que hay que rotar, rota la sublista desde la posición **m** hasta la **n** (inclusive) **k** posiciones hacia la derecha dentro de la lista original, sin usar espacio adicional significativo y reocrriendo la lista solo una vez.

### 💡 Ejemplo
```
📥 Input:  
Lista: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> Null
m = 3, n = 6, k = 2

📤 Output:  1 -> 2 -> 5 -> 6 -> 3 -> 4 -> 7 -> 8 -> Null
```