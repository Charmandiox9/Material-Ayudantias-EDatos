# 🔗 Ayudantía 4: Doble Linked List Circular

## 📋 Estructura de un Nodo

```cpp
class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        next = this; // se apunta a sí mismo
        prev = this;
    }
};
```

## 📝 Ejercicio 1: Rotación de una Lista Doblemente Enlazada Circular

### 🎯 Descripción
Dada una lista enlazada doble circular y un entero **k**, la tarea es realizar una rotación hacia la derecha de la lista en **k** posiciones.

### 💡 Ejemplo
```
📥 Input:  
Linked List: 10 ⇄ 20 ⇄ 30 ⇄ 40 ⇄ 50  
k = 2  

📤 Output: 40 ⇄ 50 ⇄ 10 ⇄ 20 ⇄ 30
```

### ⚠️ Consideraciones
- ✅ Una **rotación hacia la derecha** significa que cada elemento se mueve k posiciones hacia adelante en la lista.
- ✅ La lista es **circular**, por lo que los últimos elementos deben moverse al inicio sin necesidad de reconstruir la lista.
- ✅ El algoritmo debe **aprovechar la naturaleza circular** de la lista y no usar arreglos auxiliares.

---

## 📝 Ejercicio 2: Invertir una Lista Doblemente Enlazada Circular en grupos

### 🎯 Descripción
Dada una lista enlazada doble circular y un entero **k**, la tarea es invertir cada grupo de **k** nodos en la lista. Si el número de nodos no es multiplo de **k**, entonces los nodos omitidos, al final, deben considerarse como un grupo y deben invertirse.

### 💡 Ejemplo
```
📥 Input:  
Linked List: 1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5 ⇄ 6 
k = 2  

📤 Output: 2 ⇄ 1 ⇄ 4 ⇄ 3 ⇄ 6 ⇄ 5


📥 Input:  
Linked List: 1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5 ⇄ 6 
k = 4  

📤 Output: 4 ⇄ 3 ⇄ 2 ⇄ 1 ⇄ 6 ⇄ 5

```

### ⚠️ Consideraciones
- ✅ Una **rotación hacia la derecha** significa que cada elemento se mueve k posiciones hacia adelante en la lista.
- ✅ La lista es **circular**, por lo que los últimos elementos deben moverse al inicio sin necesidad de reconstruir la lista.
- ✅ El algoritmo debe **aprovechar la naturaleza circular** de la lista y no usar arreglos auxiliares.